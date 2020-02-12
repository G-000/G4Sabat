#include "G4SabatSubmarine.hh"

G4double SubmarineBody::x() const
{
    return width / 2;
}

G4double SubmarineBody::y() const
{
    return height / 2;
}

G4double SubmarineBody::z() const
{
    return length / 2;
}

//SourceTube::SourceTube(SubmarineBody *sub)
//{
//    parent = sub;
//}

//SourceTube::~SourceTube()
//{
//    delete parent;
//}

//G4double SourceTube::x() const
//{
//    return outerR / 2;
//}

//G4double SourceTube::y() const
//{
//    return height / 2;
//}

//G4double SourceTube::z() const
//{
//    return outerR / 2;
//}

//G4double SourceTube::xPos() const
//{
//    return 0;
//}

//G4double SourceTube::yPos() const
//{
//    return -parent->y() - y();
//}

//G4double SourceTube::zPos() const
//{
//    return 0;
//}


G4ThreeVector G4SabatSubmarine::getVolumePos() const
{
    return volumePos;
}

void G4SabatSubmarine::setVolumePos(const G4ThreeVector &value)
{
    volumePos = value;
}

G4SabatSubmarine::G4SabatSubmarine()
{
    qDebug() << "[Constructor]{G4SabatSubmarine}" << "start";
    submarine = new SubmarineBody();
//    detectorTube = new DetectorTube(submarine);
//    sourceTube = new SourceTube(submarine);

    width = submarine->width;
//    height = submarine->height + sourceTube->height;
    length = submarine->length;



//    sourceTubePos = G4ThreeVector(sourceTube->xPos(),
//                                  sourceTube->yPos(), sourceTube->zPos());
//    detectorTubePos = G4ThreeVector(sourceTube->xPos() + 12.*cm, sourceTube->yPos(),
//                                    sourceTube->zPos());
    qDebug() << "[Constructor]{G4SabatSubmarine}" << "done";
}

G4SabatSubmarine::~G4SabatSubmarine()
{
    delete submarine;
}


void G4SabatSubmarine::setVolumePossition(const G4ThreeVector &possition, const G4double seaBottomHeight)
{
    G4double x = possition.x(),
//            y = possition.y() + seaBottomHeight / 2 + height / 2 + sourceTube->height,
            z = possition.z();
//    volumePos = G4ThreeVector(x, y, z);
    qDebug() << "[Submarine]{VolumePosition} set done ";
}

G4double G4SabatSubmarine::x() const
{
    return width / 2;
}

G4double G4SabatSubmarine::y() const
{
    return height / 2;
}

G4double G4SabatSubmarine::z() const
{
    return length / 2;
}


G4LogicalVolume *G4SabatSubmarine::G4SabatSubmarineConstruct(G4LogicalVolume *logicEnv,
                          const G4bool &checkOverlaps)
{
     G4NistManager* nist = G4NistManager::Instance();
     // Submarine main box
     G4Material* submarine_mat = nist->FindOrBuildMaterial("G4_Al");
     G4Box *solidSubmarine =
             new G4Box("Submarine", submarine->x(), submarine->y(), submarine->z());
     G4LogicalVolume *logicSubmarine =
             new G4LogicalVolume(solidSubmarine, submarine_mat, "Submarine");
     logicSubmarine->SetVisAttributes(new G4VisAttributes(submarineColor));
     new G4PVPlacement(0,                       //no rotation
                       volumePos,                    //at position
                       logicSubmarine,             //its logical volume
                       "Submarine",                //its name
                       logicEnv,                //its mother  volume
                       false,                   //no boolean operation
                       0,                       //copy number
                       checkOverlaps);          //overlaps checking
     //Source Tube
     qDebug() << "[Submarine]{G4SabatSubmarineConstruct} submarine create";
//     G4Material* sourceTube_mat = nist->FindOrBuildMaterial("G4_Be");
//     G4Tubs *solidSourceTube =
//             new G4Tubs("SourceTube",
//                        sourceTube->innerR,
//                        sourceTube->outerR,
//                        sourceTube->height,
//                        0.0*deg,
//                        360.0*deg);
//     G4LogicalVolume *logicSourceTube =
//             new G4LogicalVolume(solidSourceTube, sourceTube_mat, "SourceTube");
//     logicSourceTube->SetVisAttributes(new G4VisAttributes(red));
//     G4RotationMatrix* yRot = new G4RotationMatrix; // Rotates X and Z axes only
//     yRot->rotateX(M_PI / 2 *rad);
//     new G4PVPlacement(yRot,                       //no rotation
//                       sourceTubePos,                    //at position
//                       logicSourceTube,             //its logical volume
//                       "Submarine",                //its name
//                       logicSubmarine,                //its mother  volume
//                       false,                   //no boolean operation
//                       0,                       //copy number
//                       checkOverlaps);          //overlaps checking

     qDebug() << "[Submarine]{G4SabatSubmarineConstruct} source Tube create";
     //detector Tube
//     G4Material* detectorTube_mat = nist->FindOrBuildMaterial("G4_A-150_TISSUE");
//     G4VSolid *solidDetectorTube =
//             new G4Tubs("DetectorTube", detectorTube->innerR,
//                       detectorTube->outerR, detectorTube->height, 0.0*deg, 360.0*deg);
//     G4LogicalVolume *logicDetectorTube =
//             new G4LogicalVolume(solidDetectorTube, detectorTube_mat, "DetectorTube");
//     logicDetectorTube->SetVisAttributes(new G4VisAttributes(red));
//     G4RotationMatrix* yRot = new G4RotationMatrix; // Rotates X and Z axes only
//     yRot->rotateY(1.176*rad);
//     new G4PVPlacement(yRot,                       //no rotation
//                       detectorTubePos,                    //at position
//                       logicDetectorTube,             //its logical volume
//                       "Submarine",                //its name
//                       logicSubmarine,                //its mother  volume
//                       false,                   //no boolean operation
//                       0,                       //copy number
//                       checkOverlaps);          //overlaps checking
     //Detector
     G4Material* shape2_mat = nist->FindOrBuildMaterial("G4_BONE_COMPACT_ICRU");
     G4ThreeVector pos2 = G4ThreeVector(0, -1*cm, 7*cm);

     // Trapezoid shape
     G4double shape2_dxa = 12*cm, shape2_dxb = 12*cm;
     G4double shape2_dya = 10*cm, shape2_dyb = 16*cm;
     G4double shape2_dz  = 6*cm;
     G4Trd* solidShape2 =
       new G4Trd("Shape2",                      //its name
                 0.5*shape2_dxa, 0.5*shape2_dxb,
                 0.5*shape2_dya, 0.5*shape2_dyb, 0.5*shape2_dz); //its size

     G4LogicalVolume* logicShape2 =
       new G4LogicalVolume(solidShape2,         //its solid
                           shape2_mat,          //its material
                           "Shape2");           //its name

     new G4PVPlacement(0,                       //no rotation
                       pos2,                    //at position
                       logicShape2,             //its logical volume
                       "Shape2",                //its name
                       logicEnv,                //its mother  volume
                       false,                   //no boolean operation
                       0,                       //copy number
                       checkOverlaps);          //overlaps checking
     return logicShape2;
}


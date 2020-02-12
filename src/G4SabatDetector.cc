#include "G4SabatDetector.hh"

DetectorTube::DetectorTube(G4LogicalVolume *parent)
{
    yRot->rotateX(M_PI/2*rad);
    this->parent = parent;
}

DetectorTube::~DetectorTube()
{
}

G4double DetectorTube::x() const
{
    return outerR3;
}

G4double DetectorTube::y() const
{
    return height;
}

G4double DetectorTube::z() const
{
    return outerR3;
}

G4SabatDetector::G4SabatDetector(G4LogicalVolume *parent, const G4bool &checkOverlaps)
{
    this->parent = parent;
    tube = new DetectorTube(this->parent);
    width = 2*tube->outerR3;
    height = tube->outerR3 + height;
    length = 2*tube->outerR3;
    this->checkOverlaps = checkOverlaps;
    G4Box* parentBox = dynamic_cast<G4Box*>(this->parent->GetSolid());
    G4double yP = -parentBox->GetYHalfLength();
    G4double xP = tube->outerR3;
    tubePos = G4ThreeVector(xP, yP, 0);
}

G4SabatDetector::~G4SabatDetector()
{
    delete tube;
}

void G4SabatDetector::createVolume() const
{
    G4NistManager* nist = G4NistManager::Instance();

    //create tube for detector
    G4Material* tube3_mat = nist->FindOrBuildMaterial(tube->material3);
    G4Tubs *solidTube3 = new G4Tubs("DetectorTube3",
                                    tube->innerR3,
                                    tube->outerR3,
                                    tube->height,
                                    0.*deg,
                                    360.*deg);
    G4LogicalVolume *tube3Volume =
            new G4LogicalVolume(solidTube3, tube3_mat, "DetectorTube3");
    new G4PVPlacement(tube->yRot,
                      tubePos,
                      tube3Volume,
                      "DetectorTube3",
                      parent,
                      false,
                      0,
                      checkOverlaps);
}

#include "G4SabatSeaBottom.hh"
G4double SeaBottom::x() const
{
    return width / 2;
}

G4double SeaBottom::y() const
{
    return height / 2;
}

G4double SeaBottom::z() const
{
    return length / 2;
}

Example::Example(SeaBottom *parent)
{
    this->parent = parent;
}

Example::~Example()
{
    delete parent;
}

G4double Example::x() const
{
    return width / 2;
}

G4double Example::y() const
{
    return height / 2;
}

G4double Example::z() const
{
    return length / 2;
}

G4double Example::xPos() const
{
    return 0;
}

G4double Example::yPos() const
{
    return parent->y() - y();
}

G4double Example::zPos() const
{
    return 0;
}

G4ThreeVector G4SabatSeaBottom::getVolumePossition() const
{
    return volumePossition;
}

G4double G4SabatSeaBottom::getHeight() const
{
    return height;
}

G4SabatSeaBottom::G4SabatSeaBottom()
{
    seaBottom = new SeaBottom();
    example = new Example(seaBottom);

    width = seaBottom->width;
    height = seaBottom->height;
    length = seaBottom ->length;

    examplePossition = G4ThreeVector(example->xPos(),
                                     example->yPos(), example->zPos());
}

G4SabatSeaBottom::~G4SabatSeaBottom()
{
    delete seaBottom;
    delete example;
}

void G4SabatSeaBottom::G4SabatSeaBottomConstruct(G4LogicalVolume *logicEnv, const G4bool &checkOverlaps)
{
    G4NistManager* nist = G4NistManager::Instance();
    // Submarine main box
    G4Material* bottom_mat = nist->FindOrBuildMaterial("G4_Si");
    G4Box *solidBottom =
            new G4Box("Bottom", seaBottom->x(), seaBottom->y(), seaBottom->z());
    G4LogicalVolume *logicBottom =
            new G4LogicalVolume(solidBottom, bottom_mat, "Bottom");
    logicBottom->SetVisAttributes(new G4VisAttributes(yellow));
    new G4PVPlacement(0,                       //no rotation
                      volumePossition,                    //at position
                      logicBottom,             //its logical volume
                      "Bottom",                //its name
                      logicEnv,                //its mother  volume
                      false,                   //no boolean operation
                      0,                       //copy number
                      checkOverlaps);          //overlaps checking
    G4Material* example_mat = nist->FindOrBuildMaterial("G4_Au");
    G4Box *solidExample =
            new G4Box("Example", example->x(), example->y(), example->z());
    G4LogicalVolume *logicExample =
            new G4LogicalVolume(solidExample, example_mat, "Example");
    logicExample->SetVisAttributes(new G4VisAttributes(green));
    new G4PVPlacement(0,                       //no rotation
                      examplePossition,                    //at position
                      logicExample,             //its logical volume
                      "Bottom",                //its name
                      logicBottom,                //its mother  volume
                      false,                   //no boolean operation
                      0,                       //copy number
                      checkOverlaps);          //overlaps checking
}

void G4SabatSeaBottom::setPossition(const G4double &parentWidth,
                                    const G4double &parentHeiht, const G4double &parentLength)
{
    volumePossition = G4ThreeVector(parentWidth / 2 - width / 2,
                                    - parentHeiht / 2 + height / 2,
                                    parentLength / 2 - length / 2 );
}


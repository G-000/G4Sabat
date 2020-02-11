 #include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4Color.hh"
#include "G4VisAttributes.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include <G4VPhysicalVolume.hh>
#include <G4Colour.hh>
#include "G4SabatColours.hh"

struct SeaBottom {
    const G4double width = 400*cm;
    const G4double height = 151.5*cm;
    const G4double length = 400*cm;
    SeaBottom(){};
    ~SeaBottom(){};
    G4double x() const;
    G4double y() const;
    G4double z() const;
};

struct Example {
    const G4double width = 194*cm;
    const G4double height = 50*cm;
    const G4double length = 50*cm;
    SeaBottom *parent;

    Example(SeaBottom *parent);
    ~Example();

    G4double x() const;
    G4double y() const;
    G4double z() const;

    G4double xPos() const;
    G4double yPos() const;
    G4double zPos() const;
};
class G4SabatSeaBottom {

private:
    G4double width;
    G4double height;
    G4double length;

    Example *example;
    SeaBottom * seaBottom;

    G4ThreeVector volumePossition = G4ThreeVector();    //
    G4ThreeVector examplePossition = G4ThreeVector();
    //


public:
    G4SabatSeaBottom();
    ~G4SabatSeaBottom();
    void G4SabatSeaBottomConstruct(G4LogicalVolume *logicEnv, const G4bool &checkOverlaps);

    void setPossition(const G4double &parentWidth,
                      const G4double &parentHeiht, const G4double &parentLength);
    G4ThreeVector getVolumePossition() const;
    G4double getHeight() const;
};

#ifndef G4SABATDETECTOR_H
#define G4SABATDETECTOR_H
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
#include <QDebug>
#include "G4Tubs.hh"

struct DetectorTube {

    const G4String material = "G4_Sb";
    //internal tube from H2O
    const G4double innerR1 = 2*cm;
    const G4double outerR1 = 10*cm;
    const G4double height = 30*cm;
    // Be
    const G4String material2 = "G4_Be";
    const G4double innerR2 = 10*cm;
    const G4double outerR2 = 25*cm;
    //
    const G4String material3 = "G4_Sb";
    const G4double innerR3 = 25*cm;
    const G4double outerR3 = 30*cm;
    // sphere
    G4double phi = 360.0*deg;
    G4double teta = 180.0*deg;
    G4RotationMatrix* yRot = new G4RotationMatrix; // Rotates X and Z axes only
private:
    G4LogicalVolume *parent;

public:
    DetectorTube(G4LogicalVolume *parent);
    ~DetectorTube();

    G4double x() const;
    G4double y() const;
    G4double z() const;
};

class G4SabatDetector{

private:
    G4double width;
    G4double height;
    G4double length;
    G4LogicalVolume *parent;
    DetectorTube *tube;
    G4bool checkOverlaps;
    G4ThreeVector tubePos;
public:
    G4SabatDetector(G4LogicalVolume *parent, const G4bool &checkOverlaps);
    ~G4SabatDetector();

    void createVolume() const;

};

#endif // G4SABATDETECTOR_H

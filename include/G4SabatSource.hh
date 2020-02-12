#ifndef G4SABATSOURCE_H
#define G4SABATSOURCE_H
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

struct SourceTube {
    const G4String material = "G4_Be";
    //internal tube from H2O
    const G4double innerR1 = 10*cm;
    const G4double outerR1 = 20*cm;
    const G4double height1 = 15*cm;
    // Be
    const G4String material2 = "G4_Be";
    const G4double innerR2 = 20*cm;
    const G4double outerR2 = 25*cm;
    const G4double height2 = 15*cm;
    //
    const G4String material3 = "G4_Be";
    const G4double innerR3 = 25*cm;
    const G4double outerR3 = 35*cm;
    const G4double height3 = 15*cm;
    // sphere
    G4double phi = 360.0*deg;
    G4double teta = 180.0*deg;

    SourceTube();
    ~SourceTube();
};

#endif // G4SABATSOURCE_H

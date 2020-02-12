#ifndef SUBMARINE_H
#define SUBMARINE_H
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

struct SubmarineBody {
    const G4double width = 300*cm;
    const G4double height = 200*cm;
    const G4double length = 300*cm;
    SubmarineBody(){qDebug() << "[Constructor]{SubmarineBody}" << "done"; };
    ~SubmarineBody(){};
    G4double x() const;
    G4double y() const;
    G4double z() const;
};


class G4SabatSubmarine {

private:
    const G4Colour  submarineColor = G4Colour(0.0, 0.0, 1.0) ;
    //volume size parametr
    G4double width;
    G4double height;
    G4double length;
    //element list
    SubmarineBody *submarine;

    G4ThreeVector volumePos = G4ThreeVector();    //
    G4ThreeVector sourceTubePos = G4ThreeVector();    //
    G4ThreeVector detectorTubePos = G4ThreeVector();
public:
    G4SabatSubmarine();
    ~G4SabatSubmarine();
    G4LogicalVolume *G4SabatSubmarineConstruct(G4LogicalVolume *logicEnv, const G4bool &checkOverlaps);

    void setVolumePossition(const G4ThreeVector &seaBottomPossition,
                            const G4double seaBottomHeight);

    G4double x() const;
    G4double y() const;
    G4double z() const;
    G4ThreeVector getVolumePos() const;
    void setVolumePos(const G4ThreeVector &value);
};

#endif //SUBMARINE_H

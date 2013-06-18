
#ifndef stave_scratch_TargetSD_h
#define stave_scratch_TargetSD_h 1

#include "G4VSensitiveDetector.hh"
#include "stave_scratch_TargetHit.hh"

class G4Step;
class G4HCofThisEvent;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class stave_scratch_TargetSD : public G4VSensitiveDetector
{
  public:
      stave_scratch_TargetSD(G4String);
     ~stave_scratch_TargetSD();

      void Initialize(G4HCofThisEvent*);
      G4bool ProcessHits(G4Step*, G4TouchableHistory*);
      void EndOfEvent(G4HCofThisEvent*);

  private:
      stave_scratch_TargetHitsCollection* targetCollection;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif


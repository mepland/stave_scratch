 
#ifndef stave_scratch_PrimaryGeneratorAction_h
#define stave_scratch_PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

class stave_scratch_DetectorConstruction;
class G4ParticleGun;
class G4Event;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
class stave_scratch_PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    stave_scratch_PrimaryGeneratorAction(stave_scratch_DetectorConstruction*);    
   ~stave_scratch_PrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event*);

  private:
    G4ParticleGun* particleGun;
    stave_scratch_DetectorConstruction* myDetector;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif



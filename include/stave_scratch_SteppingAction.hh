
#ifndef stave_scratch_SteppingAction_h
#define stave_scratch_SteppingAction_h 1

#include "G4UserSteppingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class stave_scratch_SteppingAction : public G4UserSteppingAction
{
  public:
    stave_scratch_SteppingAction();
   ~stave_scratch_SteppingAction(){};

    void UserSteppingAction(const G4Step*);
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

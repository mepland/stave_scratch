 
#ifndef stave_scratch_EventAction_h
#define stave_scratch_EventAction_h 1

#include "G4UserEventAction.hh"

class G4Event;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class stave_scratch_EventAction : public G4UserEventAction
{
  public:
    stave_scratch_EventAction();
   ~stave_scratch_EventAction();

  public:
    void BeginOfEventAction(const G4Event*);
    void EndOfEventAction(const G4Event*);
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    

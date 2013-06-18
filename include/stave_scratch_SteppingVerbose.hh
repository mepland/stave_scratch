
class stave_scratch_SteppingVerbose;

#ifndef stave_scratch_SteppingVerbose_h
#define stave_scratch_SteppingVerbose_h 1

#include "G4SteppingVerbose.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class stave_scratch_SteppingVerbose : public G4SteppingVerbose 
{
 public:
   
  stave_scratch_SteppingVerbose();
 ~stave_scratch_SteppingVerbose();

  void StepInfo();
  void TrackingStarted();

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

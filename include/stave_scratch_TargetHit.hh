#ifndef stave_scratch_TargetHit_h
#define stave_scratch_TargetHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class stave_scratch_TargetHit : public G4VHit
{
  public:

      stave_scratch_TargetHit();
     ~stave_scratch_TargetHit();
      stave_scratch_TargetHit(const stave_scratch_TargetHit&);
      const stave_scratch_TargetHit& operator=(const stave_scratch_TargetHit&);
      G4int operator==(const stave_scratch_TargetHit&) const;

      inline void* operator new(size_t);
      inline void  operator delete(void*);

      void Draw();
      void Print();

  public:
  
      void SetTrackID  (G4int track)      { trackID = track; };
      void SetChamberNb(G4int chamb)      { chamberNb = chamb; };  
      void SetEdep     (G4double de)      { edep = de; };
      void SetPos      (G4ThreeVector xyz){ pos = xyz; };
      
      G4int GetTrackID()    { return trackID; };
      G4int GetChamberNb()  { return chamberNb; };
      G4double GetEdep()    { return edep; };      
      G4ThreeVector GetPos(){ return pos; };
      
  private:
  
      G4int         trackID;
      G4int         chamberNb;
      G4double      edep;
      G4ThreeVector pos;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

typedef G4THitsCollection<stave_scratch_TargetHit> stave_scratch_TargetHitsCollection;

extern G4Allocator<stave_scratch_TargetHit> stave_scratch_TargetHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

inline void* stave_scratch_TargetHit::operator new(size_t)
{
  void *aHit;
  aHit = (void *) stave_scratch_TargetHitAllocator.MallocSingle();
  return aHit;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

inline void stave_scratch_TargetHit::operator delete(void *aHit)
{
  stave_scratch_TargetHitAllocator.FreeSingle((stave_scratch_TargetHit*) aHit);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

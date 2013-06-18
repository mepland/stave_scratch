#include "stave_scratch_TargetSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

stave_scratch_TargetSD::stave_scratch_TargetSD(G4String name)
:G4VSensitiveDetector(name)
{
  G4String HCname;
  collectionName.insert(HCname="targetCollection");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

stave_scratch_TargetSD::~stave_scratch_TargetSD(){ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void stave_scratch_TargetSD::Initialize(G4HCofThisEvent* HCE)
{
  targetCollection = new stave_scratch_TargetHitsCollection
                          (SensitiveDetectorName,collectionName[0]); 
  static G4int HCID = -1;
  if(HCID<0)
  { HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); }
  HCE->AddHitsCollection( HCID, targetCollection ); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool stave_scratch_TargetSD::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{
  G4double edep = aStep->GetTotalEnergyDeposit();

  if(edep==0.) return false;

  stave_scratch_TargetHit* newHit = new stave_scratch_TargetHit();
  newHit->SetTrackID  (aStep->GetTrack()->GetTrackID());
  newHit->SetChamberNb(aStep->GetPreStepPoint()->GetTouchableHandle() //TODO Chamber is still alive???
                                               ->GetCopyNumber());
  newHit->SetEdep     (edep);
  newHit->SetPos      (aStep->GetPostStepPoint()->GetPosition());
  targetCollection->insert( newHit );
  
  //newHit->Print();
  //newHit->Draw();

  return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void stave_scratch_TargetSD::EndOfEvent(G4HCofThisEvent*)
{
  if (verboseLevel>0) { 
     G4int NbHits = targetCollection->entries();
     G4cout << "\n-------->Hits Collection: in this event they are " << NbHits 
            << " hits in the target: " << G4endl;
     for (G4int i=0;i<NbHits;i++) (*targetCollection)[i]->Print();
    } 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


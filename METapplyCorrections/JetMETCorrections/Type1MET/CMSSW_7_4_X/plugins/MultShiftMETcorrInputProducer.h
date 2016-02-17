#ifndef JetMETCorrections_Type1MET_MultShiftMETcorrInputProducer_h
#define JetMETCorrections_Type1MET_MultShiftMETcorrInputProducer_h
/** \class MultShiftMETcorrInputProducer
 */
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"

#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

#include <TF1.h>
#include <TH1F.h>
#include <string>
#include <vector>
#include <TProfile.h>
#include <TH2F.h>
class MultShiftMETcorrInputProducer : public edm::EDProducer  
{
 public:

  explicit MultShiftMETcorrInputProducer(const edm::ParameterSet&);
  ~MultShiftMETcorrInputProducer();
    
 private:

  void produce(edm::Event&, const edm::EventSetup&);
  static int translateTypeToAbsPdgId( reco::PFCandidate::ParticleType type );

  edm::InputTag pflow_;
  edm::InputTag vertices_;
  std::string moduleLabel_;

  std::vector<edm::ParameterSet> cfgCorrParameters_;

  std::vector<TH1F* > METx_, METy_, METphi_;
  std::vector<double> etaMin_, etaMax_, MEx_, MEy_;
 // std::vector<double> etaMin_, etaMax_;
 // std::vector<int> type_, counts_, varType_, nbins_, counts_, etaNBins_;
  std::vector<int> type_, counts_, varType_;
 //std::vector<int> type_, varType_, nbins_, counts_, etaNBins_;

  std::vector<double> sumPt_;
  std::vector<TF1*> formula_x_;
  std::vector<TF1*> formula_y_;

 //static int translateTypeToAbsPdgId( reco::PFCandidate::ParticleType type );


};

#endif


 


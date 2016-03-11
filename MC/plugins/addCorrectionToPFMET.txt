#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/CorrMETData.h"
#include <memory>

#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
//#include "DataFormats/VertexReco/interface/Jet.h"
#include "DataFormats/TrackReco/interface/TrackBase.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

/// electron conversion veto
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerPath.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
#include "DataFormats/TrackReco/interface/HitPattern.h"
////////////////
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"
/// electron Iso.
#include "DataFormats/RecoCandidate/interface/IsoDepositDirection.h"
#include "DataFormats/RecoCandidate/interface/IsoDeposit.h"
#include "DataFormats/RecoCandidate/interface/IsoDepositVetos.h"
#include "DataFormats/PatCandidates/interface/Isolation.h"
#include "EgammaAnalysis/ElectronTools/interface/ElectronEffectiveArea.h"
////////////////
/// needed for JetID
#include "PhysicsTools/SelectorUtils/interface/PFJetIDSelectionFunctor.h"

#include "TTree.h"
#include "TMath.h"
// system include files
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
// GenJet
#include "DataFormats/JetReco/interface/GenJet.h"
//#include "DataFormats/JetReco/plugins/CorrectedPFMETProducer"
#include <vector>
using namespace std;
using namespace edm;
using namespace pat;
using namespace reco;
//____________________________________________________________________________||
class AddCorrectionsToPFMET : public edm::EDProducer
{

public:

  explicit AddCorrectionsToPFMET(const edm::ParameterSet& cfg)
    : token_(consumes<METCollection>(cfg.getParameter<edm::InputTag>("src")))
  {
  std::vector<edm::InputTag> corrInputTags = cfg.getParameter<std::vector<edm::InputTag> >("srcCorrections");
  for (std::vector<edm::InputTag>::const_iterator inputTag = corrInputTags.begin(); inputTag != corrInputTags.end(); ++inputTag)
      {
	corrTokens_.push_back(consumes<CorrMETData>(*inputTag));
      }

    produces<METCollection>("");
  }

  ~AddCorrectionsToPFMET() { }

private:

  typedef std::vector<pat::MET> METCollection;
//  typedef std::vector<reco::PFMET> METCollection;
  edm::EDGetTokenT<METCollection> token_;
  std::vector<edm::EDGetTokenT<CorrMETData> > corrTokens_;

  void produce(edm::Event& evt, const edm::EventSetup& es) override
  {
    edm::Handle<METCollection> srcMETCollection;
    evt.getByToken(token_, srcMETCollection);

    const pat::MET& srcMET = (*srcMETCollection)[0];
   // const reco::PFMET& srcMET = (*srcMETCollection)[0];

    CorrMETData correction = readAndSumCorrections(evt, es);

    pat::MET outMET = applyCorrection(srcMET, correction);
//    reco::PFMET outMET = applyCorrection(srcMET, correction);
    std::auto_ptr<METCollection> product(new METCollection);
    product->push_back(outMET);
    evt.put(product);
  }

  CorrMETData readAndSumCorrections(edm::Event& evt, const edm::EventSetup& es)
  {
    CorrMETData ret;

    edm::Handle<CorrMETData> corr;
    for (std::vector<edm::EDGetTokenT<CorrMETData> >::const_iterator corrToken = corrTokens_.begin(); corrToken != corrTokens_.end(); ++corrToken)
      {
	evt.getByToken(*corrToken, corr);
	ret += (*corr);
      }

    return ret;
  }
  reco::PFMET applyCorrection(const pat::MET& srcMET, const CorrMETData& correction)
//  pat::MET applyCorrection(const pat::MET& srcMET, const CorrMETData& correction)
  {
    //return pat::MET(srcMET.pfSpecific(), srcMET.sumEt() + correction.sumet, constructP4From(srcMET, correction), srcMET.vertex());
    //cout << "srcMET.sumEt() "<< srcMET.sumEt()  << endl;
   // cout << "srcMET.vertex() "<< srcMET.vertex()  << endl;
    return reco::PFMET(srcMET.pfSpecific(), srcMET.sumEt() + correction.sumet, constructP4From(srcMET, correction), srcMET.vertex());
  }

  reco::Candidate::LorentzVector constructP4From(const pat::MET& met, const CorrMETData& correction)
  //reco::Candidate::LorentzVector constructP4From(const reco::PFMET& met, const CorrMETData& correction)
  {
    double px = met.px() + correction.mex;
    double py = met.py() + correction.mey;
    double pt = sqrt(px*px + py*py);
    cout << "correct mex__"<< correction.mex << "px__" << px <<  "_corrext._mey:::" << correction.mey << "py__ " <<  py  << "___pt" << pt << endl;

    return reco::Candidate::LorentzVector(px, py, 0., pt);
  }
};

//____________________________________________________________________________||

DEFINE_FWK_MODULE(AddCorrectionsToPFMET);

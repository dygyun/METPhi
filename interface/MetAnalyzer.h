#ifndef Demo_MetAnalyzer_Class_h
#define Demo_MetAnalyzer_Class_h

#include <memory>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
// class declaration
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/CorrMETData.h"

#include "TLorentzVector.h" 
#include "TTree.h"
#include "TMath.h"
using namespace std;
class TTree;

class MetAnalyzer : public edm::EDAnalyzer {

   typedef std::vector<pat::MET> METCollection;
   typedef std::vector<pat::Muon> MuonCollection;
   //typedef std::vector<reco::PFMET> METCollection;
   typedef CorrMETData CorrMetdataCollection;

   public:
      explicit MetAnalyzer(const edm::ParameterSet&);
      ~MetAnalyzer();
      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      virtual void beginRun(edm::Run const&, edm::EventSetup const&);
      virtual void endRun(edm::Run const&, edm::EventSetup const&);
      virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
      virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

      void Book();    
      void Reset();    
      edm::InputTag MetTag;
      edm::InputTag MuonTag;
      edm::InputTag MetCorrectTag;
   /////////////////
      edm::InputTag MetegammaHFMinusTag;
      edm::InputTag MetegammaHFPlusTag;
      edm::InputTag MetgammaBarrelTag;
      edm::InputTag MetgammaEndcapMinusTag;
      edm::InputTag MetgammaEndcapPlusTag;
      //edm::InputTag MethTag;
      edm::InputTag MethEtaPlusTag;
      edm::InputTag MethEtaMinusTag;
      edm::InputTag Meth0BarrelTag;
      edm::InputTag Meth0EndcapMinusTag;
      edm::InputTag Meth0EndcapPlusTag;
      edm::InputTag MethHFMinusTag;
      edm::InputTag MethHFPlusTag;
  
      edm::Service<TFileService> metfile;
      TTree* dytree; 
      // ----------member data ---------------------------
     double MET;
     double METphi;
     double METphi_arc;
     double MET_x;
     double MET_y;
     double MET_sumEt;
     double METcorrect;
     double METcorrectphi;
     double METcorrect_x;
     double METcorrect_y;
     double METcorrect_sumEt;
     double Muons;
     double zmass;
     /////////////
     double METegammaHFMinus_x;
     double METegammaHFMinus_y;
     double METegammaHFMinus_phi;
     double METegammaHFPlus_x;
     double METegammaHFPlus_y;
     double METgammaBarrel_x;
     double METgammaBarrel_y;
     double METgammaEndcapMinus_x;
     double METgammaEndcapMinus_y;
     double METgammaEndcapPlus_x;
     double METgammaEndcapPlus_y;
//     double METh_x;
//     double METh_y;
     double METhEtaPlus_x;
     double METhEtaPlus_y;
     double METhEtaMinus_x;
     double METhEtaMinus_y;
     double METh0Barrel_x;
     double METh0Barrel_y;
     double METh0EndcapMinus_x;
     double METh0EndcapMinus_y;
     double METh0EndcapPlus_x;
     double METh0EndcapPlus_y;
     double METhHFMinus_x;
     double METhHFMinus_y;
     double METhHFPlus_x;
     double METhHFPlus_y;
///////////////////////
     int MET_index;

     std::vector<double> met;
};

#endif


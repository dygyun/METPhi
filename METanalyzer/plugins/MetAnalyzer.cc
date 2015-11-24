#include <iostream>
#include "TTree.h"
#include "Demo/MetAnalyzer/interface/MetAnalyzer.h"
// constructors and destructor
using namespace std;
using namespace reco;
MetAnalyzer::MetAnalyzer(const edm::ParameterSet& iConfig)
:
MetTag(       iConfig.getParameter<edm::InputTag>("metTag") ),
MuonTag(      iConfig.getParameter<edm::InputTag>("muonTag") ),
MetCorrectTag(iConfig.getParameter<edm::InputTag>("metCorrectTag") ),
MetegammaHFMinusTag( iConfig.getParameter<edm::InputTag>("egammaHFMinusTag") ),
MetegammaHFPlusTag( iConfig.getParameter<edm::InputTag>("egammaHFPlusTag") ),
MetgammaBarrelTag( iConfig.getParameter<edm::InputTag>("gammaBarrelTag") ),
MetgammaEndcapMinusTag( iConfig.getParameter<edm::InputTag>("gammaEndcapMinusTag") ),
MetgammaEndcapPlusTag( iConfig.getParameter<edm::InputTag>("gammaEndcapPlusTag") ),
MethEtaPlusTag( iConfig.getParameter<edm::InputTag>("hEtaPlusTag") ),
MethEtaMinusTag( iConfig.getParameter<edm::InputTag>("hEtaMinusTag") ),
Meth0BarrelTag( iConfig.getParameter<edm::InputTag>("h0BarrelTag") ),
Meth0EndcapMinusTag( iConfig.getParameter<edm::InputTag>("h0EndcapMinusTag") ),
Meth0EndcapPlusTag( iConfig.getParameter<edm::InputTag>("h0EndcapPlusTag") ),
MethHFMinusTag( iConfig.getParameter<edm::InputTag>("hHFMinusTag") ),
MethHFPlusTag( iConfig.getParameter<edm::InputTag>("hHFPlusTag") )
{
   //now do what ever initialization is needed
}

MetAnalyzer::~MetAnalyzer()
{
   // do anything here that needs to be done at desctruction time
}
// member functions
// ------------ method called for each event  ------------
void
MetAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
//   MET_index=0;
////////////////////////////////////////////////////////////////////////////////////////////
   Handle<METCollection> met;
   iEvent.getByLabel( MetTag, met );
 
   int numMet =0;
   for (METCollection::const_iterator itMet = met->begin() ; itMet != met->end(); itMet++)
   {
       MET         =  (itMet)->pt();     
       METphi      =  (itMet)->phi();     
   //  METphi_arc= (TMath::ATan((itMet)->px()/(itMet)->py()));
       METphi_arc  = (TMath::ATan2((itMet)->py(),(itMet)->px()));
       MET_x       = (itMet)->px();
       MET_y       = (itMet)->py();
       MET_sumEt   = (itMet)->sumEt();
       numMet++;
//       cout << "Met_pt:"<<  (itMet)->pt()  << "met phii___" << (itMet)->phi() << "MET_x________" << (itMet)->px() << "MET_sumEt___"<<  (itMet)->sumEt()  << endl;
//       MET_index++;
   }
////////////////////////////////////////////////////////////////////////////////////////////
   Handle<METCollection> metcorrect;
   iEvent.getByLabel( MetCorrectTag, metcorrect );
 
   for (METCollection::const_iterator itMet_corr = metcorrect->begin() ; itMet_corr != metcorrect->end(); itMet_corr++)
   {
       METcorrect         =  (itMet_corr)->pt();     
       METcorrectphi      =  (itMet_corr)->phi();     
       METcorrectphi_arc  =  (TMath::ATan2((itMet_corr)->py(),(itMet_corr)->px()));
       METcorrect_x       =  (itMet_corr)->px();
       METcorrect_y       =  (itMet_corr)->py();
       METcorrect_sumEt   =  (itMet_corr)->sumEt();
   }                            
   // cout << "numMet " << numMet << endl;
////////////////////////////////////////////////////////////////////////////////////////////
   Handle<CorrMetdataCollection> corr;
   iEvent.getByLabel( MetegammaHFMinusTag, corr );
   METegammaHFMinus_x = MET_x + corr->mex;
   METegammaHFMinus_y = MET_y + corr->mey;
   METegammaHFMinus_phi = (TMath::ATan2(MET_y + corr->mey,MET_x + corr->mex));
   METcorrect_egammaHFMinus_x = METcorrect_x + corr->mex;
   METcorrect_egammaHFMinus_y = METcorrect_y + corr->mey;
   METcorrect_egammaHFMinus_phi = (TMath::ATan2(METcorrect_y + corr->mey,METcorrect_x + corr->mex));
   cout << "mex:" << corr->mex << "--DY mey:____ "  << corr->mey <<"___sumet___" <<  corr->sumet << endl;
   Handle<CorrMetdataCollection> corr1;
   iEvent.getByLabel( MetegammaHFPlusTag, corr1 );
   METegammaHFPlus_x= MET_x + corr1->mex;
   METegammaHFPlus_y= MET_y + corr1->mey;
   METegammaHFPlus_phi = (TMath::ATan2(MET_y + corr1->mey,MET_x + corr1->mex));
   METcorrect_egammaHFPlus_x= METcorrect_x + corr1->mex;
   METcorrect_egammaHFPlus_y= METcorrect_y + corr1->mey;
   METcorrect_egammaHFPlus_phi = (TMath::ATan2(METcorrect_y + corr1->mey,METcorrect_x + corr1->mex));
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr2;
   iEvent.getByLabel( MetgammaBarrelTag, corr2 );
   METgammaBarrel_x= MET_x + corr2->mex;
   METgammaBarrel_y= MET_y + corr2->mey;
   METgammaBarrel_phi= (TMath::ATan2(MET_y + corr2->mey,MET_x + corr2->mex));
   METcorrect_gammaBarrel_x= METcorrect_x + corr2->mex;
   METcorrect_gammaBarrel_y= METcorrect_y+ corr2->mey;
   METcorrect_gammaBarrel_phi= (TMath::ATan2(METcorrect_y + corr2->mey,METcorrect_x + corr2->mex));
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr3;
   iEvent.getByLabel( MetgammaEndcapMinusTag, corr3 );
   METgammaEndcapMinus_x= MET_x + corr3->mex;
   METgammaEndcapMinus_y= MET_y + corr3->mey;
   METgammaEndcapMinus_phi= (TMath::ATan2(MET_y + corr3->mey,MET_x + corr3->mex));
   METcorrect_gammaEndcapMinus_x= METcorrect_x + corr3->mex;
   METcorrect_gammaEndcapMinus_y= METcorrect_y + corr3->mey;
   METcorrect_gammaEndcapMinus_phi= (TMath::ATan2(METcorrect_y + corr3->mey,METcorrect_x + corr3->mex));
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr4;
   iEvent.getByLabel( MetgammaEndcapPlusTag, corr4 );
   METgammaEndcapPlus_x= MET_x + corr4->mex;
   METgammaEndcapPlus_y= MET_y + corr4->mey;
   METgammaEndcapPlus_phi= (TMath::ATan2(MET_y + corr4->mey,MET_x + corr4->mex));
   METcorrect_gammaEndcapPlus_x= METcorrect_x + corr4->mex;
   METcorrect_gammaEndcapPlus_y= METcorrect_y + corr4->mey;
   METcorrect_gammaEndcapPlus_phi= (TMath::ATan2(METcorrect_y + corr4->mey,METcorrect_x + corr4->mex));
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr5;
   iEvent.getByLabel( MethEtaPlusTag, corr5 );
   METhEtaPlus_x= MET_x + corr5->mex;
   METhEtaPlus_y= MET_y + corr5->mey;
   METhEtaPlus_phi= (TMath::ATan2(MET_y + corr5->mey,MET_x + corr5->mex));
   METcorrect_hEtaPlus_x= METcorrect_x + corr5->mex;
   METcorrect_hEtaPlus_y= METcorrect_y + corr5->mey;
   METcorrect_hEtaPlus_phi= (TMath::ATan2(METcorrect_y + corr5->mey,METcorrect_x + corr5->mex));
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr6;
   iEvent.getByLabel( MethEtaMinusTag, corr6 );
   METhEtaMinus_x= MET_x + corr6->mex;
   METhEtaMinus_y= MET_y + corr6->mey;
   METhEtaMinus_phi= (TMath::ATan2(MET_y + corr6->mey,MET_x + corr6->mex));
   METcorrect_hEtaMinus_x= METcorrect_x + corr6->mex;
   METcorrect_hEtaMinus_y= METcorrect_y + corr6->mey;
   METcorrect_hEtaMinus_phi= (TMath::ATan2(METcorrect_y + corr6->mey,METcorrect_x + corr6->mex));
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr7;
   iEvent.getByLabel( Meth0BarrelTag, corr7 );
   METh0Barrel_x= MET_x + corr7->mex;
   METh0Barrel_y= MET_y + corr7->mey;
   METh0Barrel_phi= (TMath::ATan2(MET_y + corr7->mey,MET_x + corr7->mex));
   METcorrect_h0Barrel_x= METcorrect_x + corr7->mex;
   METcorrect_h0Barrel_y= METcorrect_y + corr7->mey;
   METcorrect_h0Barrel_phi= (TMath::ATan2(METcorrect_y + corr7->mey,METcorrect_x + corr7->mex));
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr8;
   iEvent.getByLabel( Meth0EndcapMinusTag, corr8 );
   METcorrect_h0EndcapMinus_x= METcorrect_x + corr8->mex;
   METcorrect_h0EndcapMinus_y= METcorrect_y + corr8->mey;
   METcorrect_h0EndcapMinus_phi= (TMath::ATan2(METcorrect_y + corr8->mey,METcorrect_x + corr8->mex));
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr9;
   iEvent.getByLabel( Meth0EndcapPlusTag, corr9 );
   METh0EndcapPlus_x= MET_x + corr9->mex;
   METh0EndcapPlus_y= MET_y + corr9->mey;
   METh0EndcapPlus_phi= (TMath::ATan2(MET_y + corr9->mey, MET_x + corr9->mex));
   METcorrect_h0EndcapPlus_x= METcorrect_x + corr9->mex;
   METcorrect_h0EndcapPlus_y= METcorrect_y + corr9->mey;
   METcorrect_h0EndcapPlus_phi= (TMath::ATan2(METcorrect_y + corr9->mey, METcorrect_x + corr9->mex));
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr10;
   iEvent.getByLabel( MethHFMinusTag, corr10 );
   METhHFMinus_x= MET_x + corr10->mex;
   METhHFMinus_y= MET_y + corr10->mey;
   METhHFMinus_phi= (TMath::ATan2(MET_y + corr10->mey,MET_x + corr10->mex));
   METcorrect_hHFMinus_x= METcorrect_x + corr10->mex;
   METcorrect_hHFMinus_y= METcorrect_y + corr10->mey;
   METcorrect_hHFMinus_phi= (TMath::ATan2(METcorrect_y + corr10->mey,METcorrect_x + corr10->mex));
////////////////////////////////////////
   Handle<CorrMetdataCollection> corr11;
   iEvent.getByLabel( MethHFPlusTag, corr11 );
   METhHFPlus_x= MET_x + corr11->mex;
   METhHFPlus_y= MET_y + corr11->mey;
   METhHFPlus_phi= (TMath::ATan2(MET_y + corr11->mey,MET_x + corr11->mex));
   METcorrect_hHFPlus_x= METcorrect_x + corr11->mex;
   METcorrect_hHFPlus_y= METcorrect_y + corr11->mey;
   METcorrect_hHFPlus_phi= (TMath::ATan2(METcorrect_y + corr11->mey,METcorrect_x + corr11->mex));
////////////////////////////////////////////////////////////////////
  //Handle<pat::MuonCollection> Muons;
  Handle<MuonCollection> Muons;
  iEvent.getByLabel(MuonTag, Muons);
  //iEvent.getByLabel(MuonLabel_, Muons);
  //iEvent.getByToken(MuonLabel_, Muons);
  //int j = 0;
  //bool isZ;
 // isZ=false;
  //for (const pat::Muon & aPatMuon : *Muons) 
  int n=Muons->size();
 // int k = 0;
 // double pMET = MET->at(k);    
  //auto& pMET = MET->at(k);    
  //if( pMET.pt() >10  )
  //if( Muons->size()>1 && pMET.pt() > 10  ) //muon >2 met cut > 10GeV
 for (METCollection::const_iterator itMet = met->begin() ; itMet != met->end(); itMet++)
  if( Muons->size()>1 &&  (itMet)->pt() > 10  ) //muon >2 met cut > 10GeV
  {
      for (int i=0; i<n-1; ++i)  //ist leading muon
      {
          auto& p1 = Muons->at(i);
          if(!p1.isPFMuon()) continue;
          if(!(p1.isGlobalMuon() || p1.isTrackerMuon()) ) continue;
          if(!(p1.pt()>20 && fabs(p1.eta())<2.4) ) continue;
        
          double pt    = p1.pt() ;
        
          double chIso = p1.pfIsolationR04().sumChargedHadronPt;
          double nhIso = p1.pfIsolationR04().sumNeutralHadronEt;
          double phIso = p1.pfIsolationR04().sumPhotonEt;
          double puIso = p1.pfIsolationR04().sumPUPt;
          //for deltabeta correction
          float relIso1 = ( chIso + std::max( 0.0, nhIso + phIso - 0.5 * puIso) ) / pt;
          if(relIso1>0.20) continue;
          //if(relIso1>0.12) continue;
          TLorentzVector a;
          a.SetPtEtaPhiM(p1.pt(),p1.eta(),p1.phi(),p1.mass());
          //for (const pat::Muon & aPatMuon2 : *Muons) 
          for (int j=i; j<n; ++j) //2nd muon 
          {
              auto& p2 = Muons->at(j);
              if(!p2.isPFMuon()) continue;
              if(!(p2.isGlobalMuon() || p2.isTrackerMuon()) ) continue;
              if(!(p2.pt()>20 && fabs(p2.eta())<2.4) ) continue;
              
              double pt2    = p1.pt() ;
              
              double chIso2 = p2.pfIsolationR04().sumChargedHadronPt;
              double nhIso2 = p2.pfIsolationR04().sumNeutralHadronEt;
              double phIso2 = p2.pfIsolationR04().sumPhotonEt;
              double puIso2 = p2.pfIsolationR04().sumPUPt;
              //for deltabeta correction
              float relIso2 = ( chIso2 + std::max( 0.0, nhIso2 + phIso2 - 0.5 * puIso2) ) / pt2;
              //if(relIso2>0.12) continue;
              if(relIso2>0.20) continue;
            
              TLorentzVector b;
              b.SetPtEtaPhiM(p2.pt(),p2.eta(),p2.phi(),p2.mass());
              zmass = (a+b).M();
              if(fabs(zmass-91.2)<15 && p1.charge()*p2.charge()<0 );
///////  isZ=true;
          } 
       }
    }
////////////////////////////////////////////////////////
      dytree->Fill();
       //dytree->Write();
#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}
// ------------ method called once each job just before starting event loop  ------------
void 
MetAnalyzer::beginJob()
{
      dytree =  metfile->make<TTree> ("met","Met");
      Book();
   //ssbtree = ssbfs->make<TTree>("SSBTree", "Tree for Physics Analyses at CMS");  
}
// ------------ method called once each job just after ending the event loop  ------------
void 
MetAnalyzer::endJob() 
{
}
void 
MetAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
MetAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
MetAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
MetAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
void
MetAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
void 
MetAnalyzer::Book()
{
  dytree->Branch("MET",&MET,"MET/D");
  dytree->Branch("METphi",&METphi,"METphi/D");
  dytree->Branch("METphi_arc",&METphi_arc,"METphi_arc/D");
  dytree->Branch("MET_x",&MET_x,"MET_x/D");
  dytree->Branch("MET_y",&MET_y,"MET_y/D");
  dytree->Branch("MET_sumEt",&MET_sumEt,"MET_sumEt/D");
  dytree->Branch("METcorrect",&METcorrect,"METcorrect/D");
  dytree->Branch("METcorrectphi",&METcorrectphi,"METcorrectphi/D");
  dytree->Branch("METcorrectphi_arc",&METcorrectphi_arc,"METcorrectphi_arc/D");
  dytree->Branch("METcorrect_x",&METcorrect_x,"METcorrect_x/D");
  dytree->Branch("METcorrect_y",&METcorrect_y,"METcorrect_y/D");
  dytree->Branch("METcorrect_sumEt",&METcorrect_sumEt,"METcorrect_sumEt/D");
  dytree->Branch("ZMass",&zmass,"ZMass/D");
///////
  dytree->Branch("METegammaHFMinus_x",&METegammaHFMinus_x,"METegammaHFMinus_x/D");
  dytree->Branch("METegammaHFMinus_y",&METegammaHFMinus_y,"METegammaHFMinus_y/D");
  dytree->Branch("METegammaHFMinus_phi",&METegammaHFMinus_phi,"METegammaHFMinus_phi/D");
  dytree->Branch("METcorrect_egammaHFMinus_x",&METcorrect_egammaHFMinus_x,"METcorrect_egammaHFMinus_x/D");
  dytree->Branch("METcorrect_egammaHFMinus_y",&METcorrect_egammaHFMinus_y,"METcorrect_egammaHFMinus_y/D");
  dytree->Branch("METcorrect_egammaHFMinus_phi",&METcorrect_egammaHFMinus_phi,"METcorrect_egammaHFMinus_phi/D");
  dytree->Branch("METegammaHFPlus_x",&METegammaHFPlus_x,"METegammaHFPlus_x/D");
  dytree->Branch("METegammaHFPlus_y",&METegammaHFPlus_y,"METegammaHFPlus_y/D");
  dytree->Branch("METegammaHFPlus_phi",&METegammaHFPlus_phi,"METegammaHFPlus_phi/D");
  dytree->Branch("METcorrect_egammaHFPlus_x",&METcorrect_egammaHFPlus_x,"METcorrect_egammaHFPlus_x/D");
  dytree->Branch("METcorrect_egammaHFPlus_y",&METcorrect_egammaHFPlus_y,"METcorrect_egammaHFPlus_y/D");
  dytree->Branch("METcorrect_egammaHFPlus_phi",&METcorrect_egammaHFPlus_phi,"METcorrect_egammaHFPlus_phi/D");
  dytree->Branch("METgammaBarrel_x",&METgammaBarrel_x,"METgammaBarrel_x/D");
  dytree->Branch("METgammaBarrel_y",&METgammaBarrel_y,"METgammaBarrel_y/D");
  dytree->Branch("METgammaBarrel_phi",&METgammaBarrel_phi,"METgammaBarrel_phi/D");
  dytree->Branch("METcorrect_gammaBarrel_x",&METcorrect_gammaBarrel_x,"METcorrect_gammaBarrel_x/D");
  dytree->Branch("METcorrect_gammaBarrel_y",&METcorrect_gammaBarrel_y,"METcorrect_gammaBarrel_y/D");
  dytree->Branch("METcorrect_gammaBarrel_phi",&METcorrect_gammaBarrel_phi,"METcorrect_gammaBarrel_phi/D");
  dytree->Branch("METgammaEndcapMinus_x",&METgammaEndcapMinus_x,"METgammaEndcapMinus_x/D");
  dytree->Branch("METgammaEndcapMinus_y",&METgammaEndcapMinus_y,"METgammaEndcapMinus_y/D");
  dytree->Branch("METgammaEndcapMinus_phi",&METgammaEndcapMinus_phi,"METgammaEndcapMinus_phi/D");
  dytree->Branch("METcorrect_gammaEndcapMinus_x",&METcorrect_gammaEndcapMinus_x,"METcorrect_gammaEndcapMinus_x/D");
  dytree->Branch("METcorrect_gammaEndcapMinus_y",&METcorrect_gammaEndcapMinus_y,"METcorrect_gammaEndcapMinus_y/D");
  dytree->Branch("METcorrect_gammaEndcapMinus_phi",&METcorrect_gammaEndcapMinus_phi,"METcorrect_gammaEndcapMinus_phi/D");
  dytree->Branch("METgammaEndcapPlus_x",&METgammaEndcapPlus_x,"METgammaEndcapPlus_x/D");
  dytree->Branch("METgammaEndcapPlus_y",&METgammaEndcapPlus_y,"METgammaEndcapPlus_y/D");
  dytree->Branch("METgammaEndcapPlus_phi",&METgammaEndcapPlus_phi,"METgammaEndcapPlus_phi/D");
  dytree->Branch("METcorrect_gammaEndcapPlus_x",&METcorrect_gammaEndcapPlus_x,"METcorrect_gammaEndcapPlus_x/D");
  dytree->Branch("METcorrect_gammaEndcapPlus_y",&METcorrect_gammaEndcapPlus_y,"METcorrect_gammaEndcapPlus_y/D");
  dytree->Branch("METcorrect_gammaEndcapPlus_phi",&METcorrect_gammaEndcapPlus_phi,"METcorrect_gammaEndcapPlus_phi/D");
  dytree->Branch("METhEtaPlus_x",&METhEtaPlus_x,"METhEtaPlus_x/D");
  dytree->Branch("METhEtaPlus_y",&METhEtaPlus_y,"METhEtaPlus_y/D");
  dytree->Branch("METhEtaPlus_phi",&METhEtaPlus_phi,"METhEtaPlus_phi/D");
  dytree->Branch("METcorrect_hEtaPlus_x",&METcorrect_hEtaPlus_x,"METcorrect_hEtaPlus_x/D");
  dytree->Branch("METcorrect_hEtaPlus_y",&METcorrect_hEtaPlus_y,"METcorrect_hEtaPlus_y/D");
  dytree->Branch("METcorrect_hEtaPlus_phi",&METcorrect_hEtaPlus_phi,"METcorrect_hEtaPlus_phi/D");
  dytree->Branch("METhEtaMinus_x",&METhEtaMinus_x,"METhEtaMinus_x/D");
  dytree->Branch("METhEtaMinus_y",&METhEtaMinus_y,"METhEtaMinus_y/D");
  dytree->Branch("METhEtaMinus_phi",&METhEtaMinus_phi,"METhEtaMinus_phi/D");
  dytree->Branch("METcorrect_hEtaMinus_x",&METcorrect_hEtaMinus_x,"METcorrect_hEtaMinus_x/D");
  dytree->Branch("METcorrect_hEtaMinus_y",&METcorrect_hEtaMinus_y,"METcorrect_hEtaMinus_y/D");
  dytree->Branch("METcorrect_hEtaMinus_phi",&METcorrect_hEtaMinus_phi,"METcorrect_hEtaMinus_phi/D");
  dytree->Branch("METh0Barrel_x",&METh0Barrel_x,"METh0Barrel_x/D");
  dytree->Branch("METh0Barrel_y",&METh0Barrel_y,"METh0Barrel_y/D");
  dytree->Branch("METh0Barrel_phi",&METh0Barrel_phi,"METh0Barrel_phi/D");
  dytree->Branch("METcorrect_h0Barrel_x",&METcorrect_h0Barrel_x,"METcorrect_h0Barrel_x/D");
  dytree->Branch("METcorrect_h0Barrel_y",&METcorrect_h0Barrel_y,"METcorrect_h0Barrel_y/D");
  dytree->Branch("METcorrect_h0Barrel_phi",&METcorrect_h0Barrel_phi,"METcorrect_h0Barrel_phi/D");
  dytree->Branch("METh0EndcapMinus_x",&METh0EndcapMinus_x,"METh0EndcapMinus_x/D");
  dytree->Branch("METh0EndcapMinus_y",&METh0EndcapMinus_y,"METh0EndcapMinus_y/D");
  dytree->Branch("METh0EndcapMinus_phi",&METh0EndcapMinus_phi,"METh0EndcapMinus_phi/D");
  dytree->Branch("METcorrect_h0EndcapMinus_x",&METcorrect_h0EndcapMinus_x,"METcorrect_h0EndcapMinus_x/D");
  dytree->Branch("METcorrect_h0EndcapMinus_y",&METcorrect_h0EndcapMinus_y,"METcorrect_h0EndcapMinus_y/D");
  dytree->Branch("METcorrect_h0EndcapMinus_phi",&METcorrect_h0EndcapMinus_phi,"METcorrect_h0EndcapMinus_phi/D");
  dytree->Branch("METh0EndcapPlus_x",&METh0EndcapPlus_x,"METh0EndcapPlus_x/D");
  dytree->Branch("METh0EndcapPlus_y",&METh0EndcapPlus_y,"METh0EndcapPlus_y/D");
  dytree->Branch("METh0EndcapPlus_phi",&METh0EndcapPlus_phi,"METh0EndcapPlus_phi/D");
  dytree->Branch("METcorrect_h0EndcapPlus_x",&METcorrect_h0EndcapPlus_x,"METcorrect_h0EndcapPlus_x/D");
  dytree->Branch("METcorrect_h0EndcapPlus_y",&METcorrect_h0EndcapPlus_y,"METcorrect_h0EndcapPlus_y/D");
  dytree->Branch("METcorrect_h0EndcapPlus_phi",&METcorrect_h0EndcapPlus_phi,"METcorrect_h0EndcapPlus_phi/D");
  dytree->Branch("METhHFMinus_x",&METhHFMinus_x,"METhHFMinus_x/D");
  dytree->Branch("METhHFMinus_y",&METhHFMinus_y,"METhHFMinus_y/D");
  dytree->Branch("METhHFMinus_phi",&METhHFMinus_phi,"METhHFMinus_phi/D");
  dytree->Branch("METcorrect_hHFMinus_x",&METcorrect_hHFMinus_x,"METcorrect_hHFMinus_x/D");
  dytree->Branch("METcorrect_hHFMinus_y",&METcorrect_hHFMinus_y,"METcorrect_hHFMinus_y/D");
  dytree->Branch("METcorrect_hHFMinus_phi",&METcorrect_hHFMinus_phi,"METcorrect_hHFMinus_phi/D");
  dytree->Branch("METhHFPlus_x",&METhHFPlus_x,"METhHFPlus_x/D");
  dytree->Branch("METhHFPlus_y",&METhHFPlus_y,"METhHFPlus_y/D");
  dytree->Branch("METhHFPlus_phi",&METhHFPlus_phi,"METhHFPlus_phi/D");
  dytree->Branch("METcorrect_hHFPlus_x",&METcorrect_hHFPlus_x,"METcorrect_hHFPlus_x/D");
  dytree->Branch("METcorrect_hHFPlus_y",&METcorrect_hHFPlus_y,"METcorrect_hHFPlus_y/D");
  dytree->Branch("METcorrect_hHFPlus_phi",&METcorrect_hHFPlus_phi,"METcorrect_hHFPlus_phi/D");

}
void
MetAnalyzer::Reset()
{
  MET =-999;
  METphi =-999;
  METphi_arc =-999;
  MET_x=-999;
  MET_y=-999;
  MET_sumEt=-999;
  METcorrect =-999;
  METcorrectphi =-999;
  METcorrectphi_arc =-999;
  METcorrect_x=-999;
  METcorrect_y=-999;
  METcorrect_sumEt=-999;
  METegammaHFMinus_x=-999;
  METegammaHFMinus_y=-999;
  METegammaHFMinus_phi=-999;
  METegammaHFPlus_x=-999;
  METegammaHFPlus_y=-999;
  METegammaHFPlus_phi=-999;
  METgammaBarrel_x=-999;      
  METgammaBarrel_y=-999;
  METgammaBarrel_phi=-999;
  METgammaEndcapMinus_x=-999;
  METgammaEndcapMinus_y=-999;
  METgammaEndcapMinus_phi=-999;
  METgammaEndcapPlus_x=-999;
  METgammaEndcapPlus_y=-999;
  METgammaEndcapPlus_phi=-999;
  METhEtaPlus_x=-999;
  METhEtaPlus_y=-999;
  METhEtaPlus_phi=-999;
  METhEtaMinus_x=-999;
  METhEtaMinus_y=-999;
  METhEtaMinus_phi=-999;
  METh0Barrel_x=-999;
  METh0Barrel_y=-999;
  METh0Barrel_phi=-999;
  METh0EndcapMinus_x=-999;
  METh0EndcapMinus_y=-999;
  METh0EndcapMinus_phi=-999;
  METh0EndcapPlus_x=-999;
  METh0EndcapPlus_y=-999;
  METh0EndcapPlus_phi=-999;
  METhHFMinus_x=-999;
  METhHFMinus_y=-999;
  METhHFMinus_phi=-999;
  METhHFPlus_x=-999;
  METhHFPlus_y=-999;
  METhHFPlus_phi=-999;
///////////
  METcorrect_egammaHFMinus_x=-999;
  METcorrect_egammaHFMinus_y=-999;
  METcorrect_egammaHFMinus_phi=-999;
  METcorrect_egammaHFPlus_x=-999;
  METcorrect_egammaHFPlus_y=-999;
  METcorrect_egammaHFPlus_phi=-999;
  METcorrect_gammaBarrel_x=-999;      
  METcorrect_gammaBarrel_y=-999;
  METcorrect_gammaBarrel_phi=-999;
  METcorrect_gammaEndcapMinus_x=-999;
  METcorrect_gammaEndcapMinus_y=-999;
  METcorrect_gammaEndcapMinus_phi=-999;
  METcorrect_gammaEndcapPlus_x=-999;
  METcorrect_gammaEndcapPlus_y=-999;
  METcorrect_gammaEndcapPlus_phi=-999;
  METcorrect_hEtaPlus_x=-999;
  METcorrect_hEtaPlus_y=-999;
  METcorrect_hEtaPlus_phi=-999;
  METcorrect_hEtaMinus_x=-999;
  METcorrect_hEtaMinus_y=-999;
  METcorrect_hEtaMinus_phi=-999;
  METcorrect_h0Barrel_x=-999;
  METcorrect_h0Barrel_y=-999;
  METcorrect_h0Barrel_phi=-999;
  METcorrect_h0EndcapMinus_x=-999;
  METcorrect_h0EndcapMinus_y=-999;
  METcorrect_h0EndcapMinus_phi=-999;
  METcorrect_h0EndcapPlus_x=-999;
  METcorrect_h0EndcapPlus_y=-999;
  METcorrect_h0EndcapPlus_phi=-999;
  METcorrect_hHFMinus_x=-999;
  METcorrect_hHFMinus_y=-999;
  METcorrect_hHFMinus_phi=-999;
  METcorrect_hHFPlus_x=-999;
  METcorrect_hHFPlus_y=-999;
  METcorrect_hHFPlus_phi=-999;

}

//define this as a plug-in
DEFINE_FWK_MODULE(MetAnalyzer);

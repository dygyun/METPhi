import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'MCRUN2_74_V9A::All'
#from JetMETCorrections.Type1MET.testMultShiftMETcorrInputProducer import * 
process.load('JetMETCorrections.Type1MET.correctionTermsPfMetMult_cff')
process.load('JetMETCorrections.Type1MET.correctedMet_cff')#corrected MET

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.source = cms.Source("PoolSource",
#    fileNames = cms.untracked.vstring('file:/u/user/dygyun/scratch/histo_AOD_TTedm.root')
#    fileNames = cms.untracked.vstring('file:/afs/cern.ch/work/d/dygyun/RelValZMM_13_7_4_1-MCRUN2_74_V9_MINIAODSIM.root')
    fileNames = cms.untracked.vstring('root://eoscms.cern.ch//eos/cms/store/mc/RunIISpring15DR74/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/Asympt50ns_MCRUN2_74_V9A-v2/70000/0AE770D6-0409-E511-BFD8-008CFA051EC0.root')
#   fileNames = cms.untracked.vstring(#'root://eoscms.cern.ch//eos/cms/store/relval/CMSSW_7_4_1/RelValZMM_13/MINIAODSIM/MCRUN2_74_V9_extended-v2/00000/1C2CE936-37F2-E411-85DF-02163E00C8BA.root',
#    fileNames = cms.untracked.vstring('file:/afs/cern.ch/work/d/dygyun/MetStudy/CMSSW_7_4_1/src/JetMETCorrections/Type1MET/test/histo.root')
  #  )
)

process.TFileService = cms.Service("TFileService",
      fileName = cms.string("MetTree.root"),
#      closeFileFast = cms.untracked.bool(True)
 )

process.out = cms.OutputModule("PoolOutputModule",
     #verbose = cms.untracked.bool(True),
#     SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
 #    fileName = cms.untracked.string('Met_mini_DY_M50_Asympt50ns.root'),
     fileName = cms.untracked.string('histo.root'),
     outputCommands = cms.untracked.vstring('keep *') 
)
process.pfMetMultCorr.vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices")
process.pfMetMultCorr.srcPFlow = cms.InputTag("packedPFCandidates")
#process.pfMETMultShiftCorr.vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices")
#process.pfMETMultShiftCorr.srcPFlow = cms.InputTag("packedPFCandidates")
process.pfMetMultCorr.src = cms.InputTag("slimmedMETs")

process.demo = cms.EDAnalyzer('MetAnalyzer',
                   metTag = cms.InputTag("slimmedMETs",""),
                   muonTag = cms.InputTag("slimmedMuons",""),
                   #metTag = cms.InputTag("pfMet",""),
                   metCorrectTag = cms.InputTag("pfMetMultCorr","")
                   egammaHFMinusTag = cms.InputTag("pfMETMultShiftCorr","egammaHFMinus"),
                   egammaHFPlusTag = cms.InputTag("pfMETMultShiftCorr","egammaHFPlus"),
                   gammaBarrelTag = cms.InputTag("pfMETMultShiftCorr","gammaBarrel"),
                   gammaEndcapMinusTag = cms.InputTag("pfMETMultShiftCorr","gammaEndcapMinus"),
                   gammaEndcapPlusTag = cms.InputTag("pfMETMultShiftCorr","gammaEndcapPlus"),
                   hEtaPlusTag = cms.InputTag("pfMETMultShiftCorr","hEtaPlus"),
                   hEtaMinusTag = cms.InputTag("pfMETMultShiftCorr","hEtaMinus"),
                   h0BarrelTag = cms.InputTag("pfMETMultShiftCorr","h0Barrel"),
                   h0EndcapMinusTag = cms.InputTag("pfMETMultShiftCorr","h0EndcapMinus"),
                   h0EndcapPlusTag = cms.InputTag("pfMETMultShiftCorr","h0EndcapPlus"),
                   hHFMinusTag = cms.InputTag("pfMETMultShiftCorr","hHFMinus"),
                   hHFPlusTag = cms.InputTag("pfMETMultShiftCorr","hHFPlus")
)
#process.p = cms.Path(process.run*process.demo)
#process.AOutput  = cms.EndPath(process.out + process.demo)
process.AOutput  = cms.EndPath((process.pfMETMultShiftCorrSequence*
  process.pfMetMultCorr)+ process.demo)



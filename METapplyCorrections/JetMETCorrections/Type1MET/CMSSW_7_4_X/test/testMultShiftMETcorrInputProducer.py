import FWCore.ParameterSet.Config as cms
process = cms.Process("test")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )
#process.options = cms.untracked.PSet(
#SkipEvent = cms.untracked.vstring('ProductNotFound')
#)
process.source = cms.Source(
    'PoolSource',
#for 74X miniAOD data
  fileNames = cms.untracked.vstring('file:/cms/home/dygyun/MetPhi/CMSSW_7_4_15/src/Demo/MetAnalyzer/plugins/127E79F1-8A6F-E511-8ED2-0026189438ED.root')
#for 76X miniAOD MC
#fileNames = cms.untracked.vstring('root://xrootd.unl.edu//store/mc/RunIIFall15MiniAODv2/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PU25nsData2015v1_HCALDebug_76X_mcRun2_asymptotic_v12-v1/00000/16779D78-3EB9-E511-96E2-0025903D0B7A.root')

)
process.TFileService = cms.Service("TFileService", fileName = cms.string("MetTree.root") ,
      closeFileFast = cms.untracked.bool(True))

process.load('Configuration.StandardSequences.Services_cff')
#process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
#process.GlobalTag.globaltag = 'MCRUN2_74_V9A::All'

process.out = cms.OutputModule("PoolOutputModule",
     #verbose = cms.untracked.bool(True),
#     SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
     fileName = cms.untracked.string('histo.root'),
     outputCommands = cms.untracked.vstring('keep *',
    ) 
)
process.load('JetMETCorrections.Type1MET.correctionTermsPfMetMult_cff')
process.load('JetMETCorrections.Type1MET.correctedMet_cff')
#Replacements for mAOD
#process.corrPfMetMult.vertexCollection = cms.InputTag("offlineSlimmedPrimaryVertices")
#process.corrPfMetMult.srcPFlow = cms.InputTag("packedPFCandidates")
#process.pfMetMultCorr.src = cms.InputTag("slimmedMETs")
#
# RUN!
process.run = cms.Path(
#  process.pfMETMultShiftCorrSequence*
#  process.pfMetMultCorr 
  process.pfMETMultShiftCorr*
  process.pfMetMultCorr 
)

process.outpath = cms.EndPath(process.out)
#process.outpath = cms.EndPath(process.out)


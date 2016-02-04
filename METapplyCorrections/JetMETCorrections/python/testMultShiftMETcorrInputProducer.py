import FWCore.ParameterSet.Config as cms
process = cms.Process("test")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )
#process.options = cms.untracked.PSet(
#SkipEvent = cms.untracked.vstring('ProductNotFound')
#)
process.source = cms.Source(
    'PoolSource',
    fileNames = cms.untracked.vstring('file:/cms/home/dygyun/MetPhi/CMSSW_7_4_15/src/Demo/MetAnalyzer/plugins/127E79F1-8A6F-E511-8ED2-0026189438ED.root')
 #fileNames = cms.untracked.vstring('file:/u/user/dygyun/scratch/CMSSW_7_4_7/src/ZtoMuMu/zmumu/plugins/12284DB9-4227-E511-A438-02163E013674.root')

)
process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'MCRUN2_74_V9A::All'
process.load('JetMETCorrections.Type1MET.correctionTermsPfMetMult_cff')

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
#
process.run = cms.Path(
#  process.pfMETMultShiftCorrSequence*
#  process.pfMetMultCorr 
  process.pfMETMultShiftCorr*
  process.pfMetMultCorr 
)

#process.outpath = cms.EndPath(process.out)


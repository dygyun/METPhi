import FWCore.ParameterSet.Config as cms
process = cms.Process("test")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )
#process.options = cms.untracked.PSet(
#SkipEvent = cms.untracked.vstring('ProductNotFound')
#)
process.source = cms.Source(
    'PoolSource',
  fileNames = cms.untracked.vstring('file:/cms/home/dygyun/MetPhi/CMSSW_7_4_15/src/Demo/MetAnalyzer/plugins/127E79F1-8A6F-E511-8ED2-0026189438ED.root')
# fileNames = cms.untracked.vstring('file:/cms/home/dygyun/MET/CMSSW_7_6_3/src/MetTools/MetPhiCorrections/test/16779D78-3EB9-E511-96E2-0025903D0B7A.root')
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


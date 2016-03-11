import FWCore.ParameterSet.Config as cms
process = cms.Process("test")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )
process.source = cms.Source(
    'PoolSource',
   fileNames = cms.untracked.vstring('file:/cms/home/dygyun/MET/CMSSW_7_6_3/src/MetTools/MetPhiCorrections/test/16779D78-3EB9-E511-96E2-0025903D0B7A.root')
##AOD 76XX
# fileNames = cms.untracked.vstring('root://xrootd.unl.edu//store/mc/RunIIFall15DR76/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/AODSIM/PU25nsData2015v1_76X_mcRun2_asymptotic_v12_ext4-v1/00000/004953DC-5AC2-E511-9E31-0025905A60CE.root')
   )

process.TFileService = cms.Service("TFileService", fileName = cms.string("MetTree.root") ,
      closeFileFast = cms.untracked.bool(True))

process.load('Configuration.StandardSequences.Services_cff')
#process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
#process.GlobalTag.globaltag = '76X_mcRun2_asymptotic_v12'

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(False) )
###
process.out = cms.OutputModule("PoolOutputModule",
     fileName = cms.untracked.string('histo_test.root'),
     outputCommands = cms.untracked.vstring('keep *',
    )
)
process.load('JetMETCorrections.Type1MET.correctionTermsPfMetMult_cff')
process.load('JetMETCorrections.Type1MET.correctedMet_cff')
#
# RUN!
#
process.run = cms.Path(
#  process.correctionTermsPfMetMult
#  *process.pfMetTxy
  process.pfMETMultShiftCorr*
  process.pfMetMultCorr 
)

#process.outpath = cms.EndPath(process.out)

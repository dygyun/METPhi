import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
       'file:/cms/home/dygyun/MetPhi/CMSSW_7_4_15/src/Demo/MetAnalyzer/plugins/127E79F1-8A6F-E511-8ED2-0026189438ED.root'
       
    )
)

process.demo = cms.EDAnalyzer('ZMuMuFilter'
)


process.p = cms.Path(process.demo)

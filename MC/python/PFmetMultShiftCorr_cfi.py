import FWCore.ParameterSet.Config as cms
#--------------------------------------------------------------------------------
# parametrization of MET x/y shift vs. sumEt
#from JetMETCorrections.Type1MET.multPhiCorr_741_50nsDY_cfi import multPhiCorr_741_50nsDY as multPhiCorrParams_763_25nsDY
#from JetMETCorrections.Type1MET.multPhiCorr_741_25nsDY_cfi import multPhiCorr_741_25nsDY as multPhiCorrParams_763_25nsDY
from JetMETCorrections.Type1MET.multPhiCorr_763_25nsDY_cfi import multPhiCorr_763_25nsDY as multPhiCorrParams_763_25nsDY
#so far, only one set of parameter
# this is ugly, but a direct copy does not work

#25 ns
#multPhiCorrParams_T0rtTxy_25ns     = cms.VPSet( pset for pset in multPhiCorrParams_Txy_25ns)

pfMETMultShiftCorr= cms.EDProducer("MultShiftMETcorrInputProducer",
   # srcPFlow = cms.InputTag('particleFlow', ''),
   # vertexCollection = cms.InputTag('offlinePrimaryVertices'),
    srcPFlow = cms.InputTag('packedPFCandidates', ''),
    #pflow_ = cms.InputTag('packedPFCandidates',''),
    vertexCollection = cms.InputTag('offlineSlimmedPrimaryVertices'),
    #pflow_ = cms.InputTag('offlineSlimmedPrimaryVertices'),
    parameters = multPhiCorrParams_763_25nsDY
)

#pfMETMultShiftCorrSequence = cms.Sequence( pfMETMultShiftCorr )
pfMETSysShiftCorrSequence = cms.Sequence( pfMETMultShiftCorr )

#from Configuration.StandardSequences.Eras import eras
#eras.run2_common.toModify(pfMEtMultShiftCorr, parameters=multPhiCorrParams_763_25nsDY )
#eras.run2_50ns_specific.toModify(pfMEtMultShiftCorr, parameters=multPhiCorrParams_763_25nsDY )
#eras.run2_25ns_specific.toModify(pfMEtMultShiftCorr, parameters=multPhiCorrParams_763_25nsDY )



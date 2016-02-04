import FWCore.ParameterSet.Config as cms

##____________________________________________________________________________||
from JetMETCorrections.Type1MET.pfMETmultShiftCorrections_cfi import *

##____________________________________________________________________________||
corrPfMetMult = pfMETMultShiftCorr.clone()
#corrPfMetMult = pfMEtMultShiftCorr.clone()


correctionTermsPfMetMult = cms.Sequence(
#    selectedVerticesForMEtCorr *
    corrPfMetMult
   )


##____________________________________________________________________________||
pfMETMultShiftCorrSequence = cms.Sequence(
#    selectedVerticesForMEtCorr *
   #pfMEtMultShiftCorr 
    pfMETMultShiftCorr
    )

##____________________________________________________________________________||

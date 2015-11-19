import FWCore.ParameterSet.Config as cms
multPhiCorr_tmp = cms.VPSet(
    cms.PSet(
      name=cms.string("hEtaPlus"),
      type=cms.int32(1),
      varType=cms.int32(0),
      etaMin=cms.double(0),
      etaMax=cms.double(2.7),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.00343240107744,9.47305550624e-07),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.000570933486213,2.12984439262e-06),
    ),
    cms.PSet(
      name=cms.string("hEtaMinus"),
      type=cms.int32(1),
      varType=cms.int32(0),
      etaMin=cms.double(-2.7),
      etaMax=cms.double(0),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.0114369217386,-6.88376021445e-07),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.00521928520644,1.35999941463e-06),
    ),
    cms.PSet(
      name=cms.string("h0Barrel"),
      type=cms.int32(5),
      varType=cms.int32(0),
      etaMin=cms.double(-1.392),
      etaMax=cms.double(1.392),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.0417282026204,0.000257657419074),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(-0.0198072136162,-0.000488028122615),
    ),
    cms.PSet(
      name=cms.string("h0EndcapPlus"),
      type=cms.int32(5),
      varType=cms.int32(0),
      etaMin=cms.double(1.392),
      etaMax=cms.double(3),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.0260097690731,0.000202525232885),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.0211187951455,3.54146619629e-05),
    ),
    cms.PSet(
      name=cms.string("h0EndcapMinus"),
      type=cms.int32(5),
      varType=cms.int32(0),
      etaMin=cms.double(-3.0),
      etaMax=cms.double(-1.392),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.0187702775077,0.000104782463772),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.0524326499484,-0.000373543525321),
    ),
    cms.PSet(
      name=cms.string("gammaBarrel"),
      type=cms.int32(4),
      varType=cms.int32(0),
      etaMin=cms.double(-1.479),
      etaMax=cms.double(1.479),
      fx=cms.string("x*[0]"),
      px=cms.vdouble(-0.000482601917196),
      fy=cms.string("x*[0]"),
      py=cms.vdouble(-0.00226697900235),
    ),
    cms.PSet(
      name=cms.string("gammaEndcapPlus"),
      type=cms.int32(4),
      varType=cms.int32(0),
      etaMin=cms.double(1.479),
      etaMax=cms.double(3.0),
      fx=cms.string("x*[0]"),
      px=cms.vdouble(-0.0018756372094),
      fy=cms.string("x*[0]"),
      py=cms.vdouble(0.00424948571581),
    ),
    cms.PSet(
      name=cms.string("gammaEndcapMinus"),
      type=cms.int32(4),
      varType=cms.int32(0),
      etaMin=cms.double(-3.0),
      etaMax=cms.double(-1.479),
      fx=cms.string("x*[0]"),
      px=cms.vdouble(-0.00370668294222),
      fy=cms.string("x*[0]"),
      py=cms.vdouble(0.00416035025823),
    ),
    cms.PSet(
      name=cms.string("hHFPlus"),
      type=cms.int32(6),
      varType=cms.int32(0),
      etaMin=cms.double(2.901376),
      etaMax=cms.double(5.2),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(0.00195497823781,-1.40408312529e-05),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.00151983061636,2.8340107275e-07),
    ),
    cms.PSet(
      name=cms.string("hHFMinus"),
      type=cms.int32(6),
      varType=cms.int32(0),
      etaMin=cms.double(-5.2),
      etaMax=cms.double(-2.901376),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(0.0025655956001,4.93454347364e-06),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.000836490530042,-2.16312548374e-05),
    ),
    cms.PSet(
      name=cms.string("egammaHFPlus"),
      type=cms.int32(7),
      varType=cms.int32(0),
      etaMin=cms.double(2.901376),
      etaMax=cms.double(5.2),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.00201079650457,3.51486447259e-05),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(-0.00188873309884,4.78851455274e-06),
    ),
    cms.PSet(
      name=cms.string("egammaHFMinus"),
      type=cms.int32(7),
      varType=cms.int32(0),
      etaMin=cms.double(-5.2),
      etaMax=cms.double(-2.901376),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(0.000273929964891,-2.37775700575e-05),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(-0.00141064244687,8.0776524497e-06),
    ),
)

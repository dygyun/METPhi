import FWCore.ParameterSet.Config as cms
multPhiCorr_763_25nsDY = cms.VPSet(
    cms.PSet(
      name=cms.string("hEtaPlus"),
      type=cms.int32(1),
      varType=cms.int32(0),
      etaMin=cms.double(0),
      etaMax=cms.double(2.7),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.00287210321816,1.35557652667e-06),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.00115647460627,1.36316130611e-07),
    ),
    cms.PSet(
      name=cms.string("hEtaMinus"),
      type=cms.int32(1),
      varType=cms.int32(0),
      etaMin=cms.double(-2.7),
      etaMax=cms.double(0),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.00937208508159,-2.48178204936e-06),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.00168533691491,8.37751201614e-08),
    ),
    cms.PSet(
      name=cms.string("h0Barrel"),
      type=cms.int32(5),
      varType=cms.int32(0),
      etaMin=cms.double(-1.392),
      etaMax=cms.double(1.392),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.00688392584308,-3.19272861969e-05),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(-0.00075751655842,-7.99446316263e-05),
    ),
    cms.PSet(
      name=cms.string("h0EndcapPlus"),
      type=cms.int32(5),
      varType=cms.int32(0),
      etaMin=cms.double(1.392),
      etaMax=cms.double(3),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.00418007979734,0.000182438392521),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.00978141801664,0.0001693334666),
    ),
    cms.PSet(
      name=cms.string("h0EndcapMinus"),
      type=cms.int32(5),
      varType=cms.int32(0),
      etaMin=cms.double(-3.0),
      etaMax=cms.double(-1.392),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(0.00121027953824,0.000244279516767),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.0192513649435,7.70479334882e-05),
    ),
    cms.PSet(
      name=cms.string("gammaBarrel"),
      type=cms.int32(4),
      varType=cms.int32(0),
      etaMin=cms.double(-1.479),
      etaMax=cms.double(1.479),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.00162036770821,4.78746785448e-06),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(-0.00215212820506,9.76928085836e-06),
    ),
    cms.PSet(
      name=cms.string("gammaEndcapPlus"),
      type=cms.int32(4),
      varType=cms.int32(0),
      etaMin=cms.double(1.479),
      etaMax=cms.double(3.0),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.000699441888193,-9.3111183253e-06),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.00302909267786,4.91978276846e-05),
    ),
    cms.PSet(
      name=cms.string("gammaEndcapMinus"),
      type=cms.int32(4),
      varType=cms.int32(0),
      etaMin=cms.double(-3.0),
      etaMax=cms.double(-1.479),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(0.00052828860192,1.2733201313e-05),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(-0.00254665395999,-1.78694427136e-05),
    ),
    cms.PSet(
      name=cms.string("hHFPlus"),
      type=cms.int32(6),
      varType=cms.int32(0),
      etaMin=cms.double(2.901376),
      etaMax=cms.double(5.2),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.00019314984612,-5.10555685808e-06),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(-0.000881566850571,-5.84789306415e-06),
    ),
    cms.PSet(
      name=cms.string("hHFMinus"),
      type=cms.int32(6),
      varType=cms.int32(0),
      etaMin=cms.double(-5.2),
      etaMax=cms.double(-2.901376),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(-0.00113093665001,-3.80784826162e-06),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(-0.000686535279465,-7.30133103822e-06),
    ),
    cms.PSet(
      name=cms.string("egammaHFPlus"),
      type=cms.int32(7),
      varType=cms.int32(0),
      etaMin=cms.double(2.901376),
      etaMax=cms.double(5.2),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(0.000288217564817,2.07384753229e-06),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.000195207663725,1.15593685445e-06),
    ),
    cms.PSet(
      name=cms.string("egammaHFMinus"),
      type=cms.int32(7),
      varType=cms.int32(0),
      etaMin=cms.double(-5.2),
      etaMax=cms.double(-2.901376),
      fx=cms.string("(x*[0])+(sq(x)*[1])"),
      px=cms.vdouble(0.000173675551713,3.06711814585e-06),
      fy=cms.string("(x*[0])+(sq(x)*[1])"),
      py=cms.vdouble(0.000240375931822,2.32439470613e-06),
    ),
)
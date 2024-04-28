/*
 * icuasw_pus_service1.h
 *
 *  Created on: Dec 21, 2016
 *      Author: user
 */


#ifndef PUBLIC__ICUASW_PUS_SERVICE1_H
#define PUBLIC__ICUASW_PUS_SERVICE1_H

#include "public/basic_types.h"

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/cdtchandler.h"
#include "public/cdtmlist.h"

class PUSService1{

public:

  static void TryTCAcceptation( CDTCHandler &tcHandler);

  static void CompleteTCRejection( CDTCHandler &tcHandler);

  static void BuildTM_1_1(CDTCHandler &tcHandler, CDTMList &tmList);

  static void BuildTM_1_2(CDTCHandler &tcHandler, CDTMList &tmList);

  static void BuildTM_1_7(CDTCHandler &tcHandler, CDTMList &tmList);

  static void BuildTM_1_8_TC_3_X_SIDNotValid(CDTCHandler &tcHandler,
		  	  	  	  	  	  	  CDTMList &tmList,
		  	  	  	  	  	  	  uint16_t SID);

  static void BuildTM_1_8_TC_20_X_PIDNotValid(CDTCHandler &tcHandler,
 		  	  	  	  	  	  	  CDTMList &tmList,
 		  	  	  	  	  	  	  uint16_t PID);

  static void BuildTM_1_8_TC_5_X_RIDUnknown(CDTCHandler &tcHandler,
 		  	  	  	  	  	  	  CDTMList &tmList,
 		  	  	  	  	  	  	  uint16_t RID);

  static void BuildTM_1_8_TC_12_X_PMONIDUndefined(CDTCHandler &tcHandler,
 		  	  	  	  	  	  	  CDTMList &tmList,
 		  	  	  	  	  	  	  uint16_t PMONID);

  static void BuildTM_1_8_TC_12_X_PMONIDDefined(CDTCHandler &tcHandler,
 		  	  	  	  	  	  	  CDTMList &tmList,
 		  	  	  	  	  	  	  uint16_t PMONID);

  static void BuildTM_1_8_TC_12_X_PMONIDNotValid(CDTCHandler &tcHandler,
 		  	  	  	  	  	  	  CDTMList &tmList,
 		  	  	  	  	  	  	  uint16_t PMONID);

  static void BuildTM_1_8_TC_19_X_EvActionEnabled(CDTCHandler &tcHandler,
  	  	  	  	  CDTMList &tmList,
  	  	  	  	  uint16_t EvID);

  static void BuildTM_1_8_TC_19_1_MaxEvActions(CDTCHandler &tcHandler,
	  	  	  	  CDTMList &tmList,
	  	  	  	  uint16_t EvID);

  static void BuildTM_1_8_TC_19_1_EvActionRejected(CDTCHandler &tcHandler,
 	  	  	  	  CDTMList &tmList,
 	  	  	  	  uint16_t EvID);

  static void BuildTM_1_8_TC_19_X_EvActionNotDefined(CDTCHandler &tcHandler,
  	  	  	  	  CDTMList &tmList,
  	  	  	  	  uint16_t EvID);

  static void BuildTM_1_8_TC_2_X_DeviceNotValid(CDTCHandler &tcHandler,
  	  	  	  	  CDTMList &tmList,
  	  	  	  	  uint8_t devID);

private:


  static bool_t IsCRCValid( CDTCHandler &tcHandler);

  static bool_t IsAPIDValid( CDTCHandler &tcHandler);
  
  static bool_t IsSourceIDValid( CDTCHandler &tcHandler);



};



#endif


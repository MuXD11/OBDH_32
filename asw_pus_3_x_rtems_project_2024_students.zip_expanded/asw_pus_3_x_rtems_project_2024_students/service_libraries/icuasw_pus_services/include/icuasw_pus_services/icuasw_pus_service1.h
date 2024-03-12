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



private:


  static bool_t IsCRCValid( CDTCHandler &tcHandler);

  static bool_t IsAPIDValid( CDTCHandler &tcHandler);
  
  static bool_t IsSourceIDValid( CDTCHandler &tcHandler);



};



#endif


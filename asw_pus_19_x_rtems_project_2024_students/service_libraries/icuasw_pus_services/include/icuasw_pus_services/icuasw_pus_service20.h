/*
 * icuasw_pus_private_service20.cpp
 *
 *  Created on: Dec 22, 2023
 *      Author: user
 */


#ifndef PUBLIC__ICUASW_PUS_SERVICE20_H
#define PUBLIC__ICUASW_PUS_SERVICE20_H


#include "public/basic_types.h"

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/cdtchandler.h"
#include "public/cdtmlist.h"

class PUSService20{

	//friend class PUSPrioTCExecutor;

public:
  static void ExecTC( CDTCHandler &tcHandler, CDTMList &List);

  static void Exec20_1TC( CDTCHandler &tcHandler, CDTMList &List);
  static void Exec20_3TC( CDTCHandler &tcHandler, CDTMList &List);

};

#endif

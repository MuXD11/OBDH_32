/*
 * icuasw_pus_Service17.h
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */



#ifndef PUBLIC__ICUASW_PUS_SERVICE17_H
#define PUBLIC__ICUASW_PUS_SERVICE17_H

#include "public/basic_types.h"

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/cdtchandler.h"
#include "public/cdtmlist.h"

class PUSService17{

 friend class PUSPrioTCExecutor;
protected:
  static void ExecTC( CDTCHandler &tcHandler, CDTMList &tmList);
  static void BuildTM_17_2(CDTMList &tmList);


};
#endif

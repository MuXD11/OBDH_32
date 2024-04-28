/*
 * icuasw_pus_service9.h
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */


#ifndef PUBLIC__ICUASW_PUS_SERVICE9_H
#define PUBLIC__ICUASW_PUS_SERVICE9_H

#include "public/basic_types.h"

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/cdtchandler.h"
#include "public/cdtmlist.h"

class PUSService9{

 friend class PUSPrioTCExecutor;
protected:

  static void ExecTC(CDTCHandler &tc_handler, CDTMList &tm_list);

public:
  static uint32_t GetCurrentUniTimeY2K();
};
#endif


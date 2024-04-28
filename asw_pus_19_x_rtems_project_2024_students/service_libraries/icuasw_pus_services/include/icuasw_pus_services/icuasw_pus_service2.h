/*
 * icuasw_pus_Service2.h
 *
 *  Created on: Dec 22, 2024
 *      Author: user
 */



#ifndef PUBLIC__ICUASW_PUS_SERVICE2_H
#define PUBLIC__ICUASW_PUS_SERVICE2_H

#include "public/basic_types.h"

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/cdtchandler.h"
#include "public/cdtmlist.h"

class PUSService2{

 friend class PUSPrioTCExecutor;
 friend class PUS_HK_FDIR_TCExecutor;
protected:
  static void ExecTC( CDTCHandler &tcHandler, CDTMList &tmList);

public:
  static void Exec2_1TC( CDTCHandler &tcHandler, CDTMList &tmList);
};
#endif

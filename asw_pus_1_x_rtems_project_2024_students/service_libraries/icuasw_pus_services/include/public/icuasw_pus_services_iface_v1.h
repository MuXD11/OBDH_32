#ifndef PUBLIC__ICUASW_PUS_SERVICES_IFACE_V1_H
#define PUBLIC__ICUASW_PUS_SERVICES_IFACE_V1_H

#include <public/cdtmlist_iface_v1.h>

#include "public/config.h"
#include "public/basic_types.h"
#include "public/serialize.h"
#include "public/cdtchandler_iface_v1.h"
#include "public/cdtmhandler.h"
#include "public/cdeventlist_iface_v1.h"


#define DATAPOOL_PARAMNumber 64
typedef uint16_t sysdatapool_element_t;

class SystemDataPool{

public:

	static sysdatapool_element_t sParamCurrentValue[DATAPOOL_PARAMNumber];

	static void Init();
};


#include "../../../icuasw_pus_services/include/icuasw_pus_services/icuasw_pus_service1.h"
//TODO Add PUS Services 9 and 17 header files
//#include "../../../icuasw_pus_services/include/icuasw_pus_services/icuasw_pus_service9.h"
//#include "../../../icuasw_pus_services/include/icuasw_pus_services/icuasw_pus_service17.h"


class PUSPrioTCExecutor {

public:
	static void ExecTC(CDTCHandler &tc_handler, CDTMList &tm_list,
			CDEventList &eventList);
};


/*PROTECTED REGION END*/



#endif // PUBLIC__CONSOLE_DRV_IFACE_V1_H

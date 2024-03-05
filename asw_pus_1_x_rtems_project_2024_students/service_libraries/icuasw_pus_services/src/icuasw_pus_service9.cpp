/*
 * icuasw_pus_service9.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */



#include <public/emu_hw_timecode_drv_v1.h>
#include <public/icuasw_pus_services_iface_v1.h>

void  PUSService9::ExecTC(CDTCHandler &tcHandler, CDTMList &tmList){

   switch (tcHandler.GetSubType()) {
   	case (129):
		EmuHwTimeCodeSetNextUniTimeY2K(tcHandler.GetNextUInt32());
   		PUSService1::BuildTM_1_7(tcHandler, tmList);
     break;

  }

}


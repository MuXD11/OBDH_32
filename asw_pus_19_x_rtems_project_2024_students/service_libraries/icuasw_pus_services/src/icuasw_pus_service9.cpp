/*
 * icuasw_pus_service9.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */



#include <public/emu_hw_timecode_drv_v1.h>
#include <public/icuasw_pus_services_iface_v1.h>

void  PUSService9::ExecTC(CDTCHandler &tc_handler, CDTMList &tm_list){

   switch (tc_handler.GetSubType()) {
   	case (129):
		EmuHwTimeCodeSetNextUniTimeY2K(tc_handler.GetNextUInt32());
   		PUSService1::BuildTM_1_7(tc_handler, tm_list);
     break;

  }

}

uint32_t PUSService9::GetCurrentUniTimeY2K(){

	return EmuHwTimeCodeGetCurrentUniTimeY2K();

}


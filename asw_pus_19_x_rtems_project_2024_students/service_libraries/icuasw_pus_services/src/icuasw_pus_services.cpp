/*
 * icuasw_pus_services.cpp
 *
 *  Created on: Jan 10, 2017
 *      Author: user
 */

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/serialize.h"
#include "public/tmtc_dyn_mem.h"
#include "public/ccsds_pus.h"

//***********************SYSTEM DATA POOL************************************
sysdatapool_element_t SystemDataPool::sParamCurrentValue[DATAPOOL_PARAMNumber];

void SystemDataPool::Init() {
	for (uint8_t i = 0; i < DATAPOOL_PARAMNumber; i++)
		sParamCurrentValue[i] = i;
}
;

void PUSPrioTCExecutor::ExecTC(CDTCHandler &tc_handler, CDTMList &tm_list,
		CDEventList &eventList) {

	tc_handler.StartUpExecution();
	switch (tc_handler.GetType()) {

	case (2):
		PUSService2::ExecTC(tc_handler, tm_list);
		break;
	case (9):
		PUSService9::ExecTC(tc_handler, tm_list);
		break;
	case (17):
		PUSService17::ExecTC(tc_handler, tm_list);
		break;
	default: //This must be an event
		break;
	}
	tc_handler.FreeTCDescriptor();
}

void PUS_HK_FDIR_TCExecutor::ExecTC(CDTCHandler &tc_handler, CDTMList &tm_list,
		CDEventList &eventList) {

	tc_handler.StartUpExecution();

	switch (tc_handler.GetType()) {

	case (3):
		PUSService3::ExecTC(tc_handler, tm_list);
		break;
	case (5):
		PUSService5::ExecTC(tc_handler, tm_list);
		break;
	case (12):
		PUSService12::ExecTC(tc_handler, tm_list);
		break;
	case (19):
		PUSService19::ExecTC(tc_handler, tm_list);
		break;
	default: //This must be an event
		break;
	}
	tc_handler.FreeTCDescriptor();
}

void PUS_BKGTCExecutor::ExecTC(CDTCHandler &tc_handler, CDTMList &tm_list,
		CDEventList &eventList) {
	tc_handler.StartUpExecution();

	switch (tc_handler.GetType()) {
	case (20):
		PUSService20::ExecTC(tc_handler, tm_list);
		break;
	default: //This must be an event
		break;
	}
	tc_handler.FreeTCDescriptor();

}

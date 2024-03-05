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

void SystemDataPool::Init(){
		for(uint8_t i=0; i < DATAPOOL_PARAMNumber; i++)
		sParamCurrentValue[i]=i;
	};

void PUSPrioTCExecutor::ExecTC(CDTCHandler &tcHandler, CDTMList &tmList,
		CDEventList &eventList){

		tcHandler.StartUpExecution();
		switch (tcHandler.GetType()) {
		//TODO Complete Execute Prio TCs
					//case (9):
						//
					//  break;
					case (17):
						//PUSService17::ExecTC(tcHandler,tmList);
						break;
					default:
						break;
		}
		tcHandler.FreeTCDescriptor();
}


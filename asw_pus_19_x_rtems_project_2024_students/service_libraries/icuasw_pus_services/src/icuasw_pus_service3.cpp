/*
 * icuaasw_pus_service3.cpp
 *
 *  Created on: Dec 22, 2023
 *      Author: user
 */


#include <stdio.h>

#include <public/icuasw_pus_services_iface_v1.h>

HKConfig_t PUSService3::HKConfig[PUS_SERVICE3_MAX_NUM_OF_SIDS]={
    {true,0,10,0,4,{0,1,2,3,0,0,0,0,0,0,0,0,0,0,0,0}},
    {true,10,30,0,3,{4,5,6,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {true,11,60,0,6,{7,8,9,10,11,12,0,0,0,0,0,0,0,0,0,0}},
    {false,0,0,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {false,0,0,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {false,0,0,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {false,0,0,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {false,0,0,0,0,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}
};

void PUSService3::Init(){

	SystemDataPool::Init();
}

void PUSService3::ExecTC(CDTCHandler &tcHandler, CDTMList &List) {

	switch (tcHandler.GetSubType()) {
	case (5):
		Exec3_5TC(tcHandler, List);
		break;
	case (6):
		Exec3_6TC(tcHandler, List);
		break;
	case (31):
		Exec3_31TC(tcHandler, List);
		break;
	default:
		; //This is an error in acceptance, can be modeled with an event..
	}
}

bool PUSService3::GetSIDIndex(uint16_t SID, uint8_t &index) {
	bool encontrado = false;
	for (int j = 0; ((j < PUS_SERVICE3_MAX_NUM_OF_SIDS) && !encontrado); j++) {
		if (SID == HKConfig[j].SID) {
			index = j;
			encontrado = true;
		}
	}
	return encontrado;
}

void PUSService3::ExecEnableConfigTC(CDTCHandler &tcHandler, CDTMList &tmList,
		bool newEnableConfig) {

	uint8_t index;
	uint16_t SID = tcHandler.GetNextUInt16();

	if (GetSIDIndex(SID, index)) {
		HKConfig[index].enabled = newEnableConfig;
		HKConfig[index].intervalControl = 0;
		PUSService1::BuildTM_1_7(tcHandler, tmList);
	} else {
		PUSService1::BuildTM_1_8_TC_3_X_SIDNotValid(tcHandler, tmList,SID);
	}

}

void PUSService3::Exec3_5TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	ExecEnableConfigTC(tcHandler, tmList, true);

}
void PUSService3::Exec3_6TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	ExecEnableConfigTC(tcHandler, tmList, false);

}
void PUSService3::Exec3_31TC(CDTCHandler &tcHandler, CDTMList &tmList) {
	uint8_t index;

	uint16_t SID = tcHandler.GetNextUInt16();

	if (GetSIDIndex(SID, index)) {
		uint8_t interval = tcHandler.GetNextUInt8();
		HKConfig[index].interval = interval;
		//printf("Cambio SID % i period a %i\n", index, HKConfig[index].interval);
		PUSService1::BuildTM_1_7(tcHandler, tmList);
	} else {
		PUSService1::BuildTM_1_8_TC_3_X_SIDNotValid(tcHandler, tmList,SID);
	}

}



void PUSService3::DoHK(CDTMList &tmList) {


	printf("Do_HK\n");

	//TODO param sampling

	for (int i = 0; i < PUS_SERVICE3_MAX_NUM_OF_SIDS; i++) {
		if (HKConfig[i].enabled) {
			HKConfig[i].intervalControl++;
			if (HKConfig[i].intervalControl >= HKConfig[i].interval) {

				BuildTM_3_25(tmList, HKConfig[i]);

				HKConfig[i].intervalControl = 0;
			}
		}
	}

}

void PUSService3::BuildTM_3_25(CDTMList &tmList, HKConfig_t &hkConfig){

	CDTMHandler tm_handler(3, 25);

	tm_handler.SetUInt16AppDataField(hkConfig.SID);

	for (int j = 0; j < hkConfig.ParamNum; j++) {
		uint8_t pid=hkConfig.ParamDef[j];
		uint16_t paramValue=SystemDataPool::sParamCurrentValue[pid];
		tm_handler.SetUInt16AppDataField(paramValue);

	}

	tmList.AddTM(tm_handler.CloseTM());

}

/*
 * emu_sc_pus_service3.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <stdio.h>

#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service3.h"
#include "public/icuasw_pus_services_iface_v1.h"

#define TC_3_5_APPDATA_LENGTH 2
#define TC_3_6_APPDATA_LENGTH 2
#define TC_3_31_APPDATA_LENGTH 3


EmuGSS_TCProgram3_5::EmuGSS_TCProgram3_5(uint32_t uniTime2YK,
                         char * brief,
                         uint16_t sid)
                        :EmuGSS_TCProgram(uniTime2YK,3,5,
                        		TC_3_5_APPDATA_LENGTH,brief){

	mSID=sid;
    NewProgram(this);
}

void EmuGSS_TCProgram3_5::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextUInt16(mSID);

}


EmuGSS_TCProgram3_6::EmuGSS_TCProgram3_6(uint32_t uniTime2YK,
                         char * brief,
                         uint16_t sid)
                        :EmuGSS_TCProgram(uniTime2YK,3,6,
                        		TC_3_6_APPDATA_LENGTH,brief){

	mSID=sid;
    NewProgram(this);
}

void EmuGSS_TCProgram3_6::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextUInt16(mSID);

}

EmuGSS_TCProgram3_31::EmuGSS_TCProgram3_31(uint32_t uniTime2YK,
                         char * brief,
                         uint16_t sid, uint8_t collecInterval)
                        :EmuGSS_TCProgram(uniTime2YK,3,31,
                        		TC_3_31_APPDATA_LENGTH,brief){

	mSID=sid;
	mCollectInterval=collecInterval;

    NewProgram(this);
}

void EmuGSS_TCProgram3_31::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextUInt16(mSID);
	SetNextUInt8(mCollectInterval);


}

//********************************************************+
void EmuGSS_ShowServ3TM(const struct tm_descriptor *pTMDescriptor) {

	GSSServ3TMHandler serv3TMHandler(pTMDescriptor->p_tm_bytes);
	serv3TMHandler.ShowTM();

}



GSSServ3TMHandler::GSSServ3TMHandler(uint8_t *pTMBytes) :
		GSSTMHandler(pTMBytes) {

}

void GSSServ3TMHandler::ShowTM(){

	switch (mDFHeader.subtype) {
	case (25):
		ShowTM_3_25();
		break;

	}
}

void GSSServ3TMHandler::ShowTM_3_25(){

	uint16_t sid= GetNextUInt16AppDataField();

	printf(" SID %d Param Values",sid);

	uint8_t index;
	if(PUSService3::GetSIDIndex(sid, index)){

		uint8_t num_of_param=PUSService3::HKConfig[index].ParamNum;

		for(uint8_t i=0; i < num_of_param; i++){

			uint16_t pid_value= GetNextUInt16AppDataField();
			if(0==i)
				printf(" [%d",pid_value);
			else if ((num_of_param-1)==i)
				printf(",%d]",pid_value);
			else
				printf(",%d",pid_value);
		}

		printf(" \n");

	}else{
		printf(" is invalid \n");
	}


}

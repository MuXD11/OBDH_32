/*
 * emu_sc_pus_service3.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <stdio.h>

#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service20.h"
#include "public/icuasw_pus_services_iface_v1.h"

#define TC_20_1_APPDATA_LENGTH 2
#define TC_20_3_APPDATA_LENGTH 4

EmuGSS_TCProgram20_1::EmuGSS_TCProgram20_1(uint32_t uniTime2YK,
                         char * brief,
                         uint16_t pid)
                        :EmuGSS_TCProgram(uniTime2YK,20,1,
                        		TC_20_1_APPDATA_LENGTH,brief){

	mPID=pid;
    NewProgram(this);
}

void EmuGSS_TCProgram20_1::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextUInt16(mPID);

}

EmuGSS_TCProgram20_3::EmuGSS_TCProgram20_3(uint32_t uniTime2YK,
                         char * brief,
                         uint16_t pid, uint16_t value)
                        :EmuGSS_TCProgram(uniTime2YK,20,3,
                        		TC_20_3_APPDATA_LENGTH,brief){

	mPID=pid;
	mValue=value;

    NewProgram(this);
}

void EmuGSS_TCProgram20_3::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextUInt16(mPID);
	SetNextUInt16(mValue);

}

//********************************************************+
void EmuGSS_ShowServ20TM(const struct tm_descriptor *pTMDescriptor) {

	GSSServ20TMHandler serv20TMHandler(pTMDescriptor->p_tm_bytes);
	serv20TMHandler.ShowTM();

}



GSSServ20TMHandler::GSSServ20TMHandler(uint8_t *pTMBytes) :
		GSSTMHandler(pTMBytes) {

}

void GSSServ20TMHandler::ShowTM(){

	switch (mDFHeader.subtype) {
	case (2):
		ShowTM_20_2();
		break;

	}
}

void GSSServ20TMHandler::ShowTM_20_2(){

	uint16_t pid= GetNextUInt16AppDataField();
	uint16_t pid_value= GetNextUInt16AppDataField();

	printf(" PID %d value = %d \n",pid,pid_value);


}

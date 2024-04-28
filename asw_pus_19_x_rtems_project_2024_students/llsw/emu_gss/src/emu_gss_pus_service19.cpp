/*
 * emu_sc_pus_service12.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <stdio.h>

#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service19.h"
#include "emu_gss/emu_gss_pus_service2.h"
#include "public/icuasw_pus_services_iface_v1.h"

#define TC_2_1_APPDATA_LENGTH  2
#define TC_2_1_PACK_BYTES  (10 + TC_2_1_APPDATA_LENGTH + 2)
#define TC_19_1_ACT_2_1_APPDATA_LENGTH (2 + TC_2_1_PACK_BYTES)

#define TC_19_2_APPDATA_LENGTH 2
#define TC_19_4_APPDATA_LENGTH 2
#define TC_19_5_APPDATA_LENGTH 2

EmuGSS_TCProgram19_1_Action_2_1::EmuGSS_TCProgram19_1_Action_2_1(
								uint32_t uniTime2YK, char *brief
								, uint16_t evID
								, uint8_t deviceID
								, enum DeviceCommandOnOff_t devicecommand):
		EmuGSS_TCProgram(uniTime2YK, 19, 1,
				TC_19_1_ACT_2_1_APPDATA_LENGTH, brief),
		mProgram_2_1(deviceID,devicecommand){

	mEvID=evID;
	NewProgram(this);
}

void EmuGSS_TCProgram19_1_Action_2_1::BuildTCAppData(tc_descriptor_t &tc_descriptor) {

	tc_descriptor_t tc_2_1_descriptor;
	uint8_t tc_2_1_bytes[14];
	tc_2_1_descriptor.p_tc_bytes=tc_2_1_bytes;

	SetNextUInt16(mEvID);

	mProgram_2_1.BuildTC(tc_2_1_descriptor);
	for(int i=0; i < tc_2_1_descriptor.tc_num_bytes; i++)
		SetNextUInt8(tc_2_1_descriptor.p_tc_bytes[i]);

}

EmuGSS_TCProgram19_2::EmuGSS_TCProgram19_2(uint32_t uniTime2YK, char *brief
		, uint16_t evID) :
		EmuGSS_TCProgram(uniTime2YK, 19, 2,
		TC_19_2_APPDATA_LENGTH, brief) {

	mEvID=evID;
	NewProgram(this);
}

void EmuGSS_TCProgram19_2::BuildTCAppData(tc_descriptor_t &tc_descriptor) {

	SetNextUInt16(mEvID);

}

EmuGSS_TCProgram19_4::EmuGSS_TCProgram19_4(uint32_t uniTime2YK, char *brief
		, uint16_t evID) :
		EmuGSS_TCProgram(uniTime2YK, 19, 4,
		TC_19_4_APPDATA_LENGTH, brief) {

	mEvID=evID;
	NewProgram(this);
}

void EmuGSS_TCProgram19_4::BuildTCAppData(tc_descriptor_t &tc_descriptor) {

	SetNextUInt16(mEvID);

}

EmuGSS_TCProgram19_5::EmuGSS_TCProgram19_5(uint32_t uniTime2YK, char *brief
		, uint16_t evID) :
		EmuGSS_TCProgram(uniTime2YK, 19, 5,
		TC_19_5_APPDATA_LENGTH, brief) {

	mEvID=evID;
	NewProgram(this);
}

void EmuGSS_TCProgram19_5::BuildTCAppData(tc_descriptor_t &tc_descriptor) {

	SetNextUInt16(mEvID);

}


//********************************************************+
void EmuGSS_ShowServ19TM(const struct tm_descriptor *pTMDescriptor) {

	GSSServ19TMHandler serv9TMHandler(pTMDescriptor->p_tm_bytes);
	serv9TMHandler.ShowTM();

}

GSSServ19TMHandler::GSSServ19TMHandler(uint8_t *pTMBytes) :
		GSSTMHandler(pTMBytes) {

}

void GSSServ19TMHandler::ShowTM() {

}


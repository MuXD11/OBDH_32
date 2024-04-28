/*
 * emu_sc_pus_service12.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <stdio.h>

#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service12.h"
#include "public/icuasw_pus_services_iface_v1.h"

#define TC_12_1_APPDATA_LENGTH 2
#define TC_12_2_APPDATA_LENGTH 2
#define TC_12_5_APPDATA_LENGTH 13
#define TC_12_6_APPDATA_LENGTH 2

EmuGSS_TCProgram12_1::EmuGSS_TCProgram12_1(uint32_t uniTime2YK, char *brief,
		uint16_t pmonid) :
		EmuGSS_TCProgram(uniTime2YK, 12, 1,
		TC_12_1_APPDATA_LENGTH, brief) {

	mPMONID = pmonid;
	NewProgram(this);
}

void EmuGSS_TCProgram12_1::BuildTCAppData(tc_descriptor_t &tc_descriptor) {

	SetNextUInt16(mPMONID);

}

EmuGSS_TCProgram12_2::EmuGSS_TCProgram12_2(uint32_t uniTime2YK, char *brief,
		uint16_t pmonid) :
		EmuGSS_TCProgram(uniTime2YK, 12, 2,
		TC_12_2_APPDATA_LENGTH, brief) {

	mPMONID = pmonid;
	NewProgram(this);
}

void EmuGSS_TCProgram12_2::BuildTCAppData(tc_descriptor_t &tc_descriptor) {

	SetNextUInt16(mPMONID);

}

EmuGSS_TCProgram12_5::EmuGSS_TCProgram12_5(uint32_t uniTime2YK, char *brief,
		uint16_t pmonid, uint16_t pid, uint8_t interval, uint16_t lowlimit,
		uint16_t lowlimit_rid, uint16_t highlimit, uint16_t highlimit_rid) :
		EmuGSS_TCProgram(uniTime2YK, 12, 5,
		TC_12_5_APPDATA_LENGTH, brief) {

	mPMONID=pmonid;
	mPID=pid;
	mInterval=interval;
	mLowlimit=lowlimit;
	mLowlimitRID=lowlimit_rid;
	mHighlimit=highlimit;
	mHighlimitRID=highlimit_rid;
	NewProgram(this);
}

void EmuGSS_TCProgram12_5::BuildTCAppData(tc_descriptor_t &tc_descriptor) {

	SetNextUInt16(mPMONID);
	SetNextUInt16(mPID);
	SetNextUInt8(mInterval);
	SetNextUInt16(mLowlimit);
	SetNextUInt16(mLowlimitRID);
	SetNextUInt16(mHighlimit);
	SetNextUInt16(mHighlimitRID);

}

EmuGSS_TCProgram12_6::EmuGSS_TCProgram12_6(uint32_t uniTime2YK, char *brief,
		uint16_t pmonid) :
		EmuGSS_TCProgram(uniTime2YK, 12, 6,
		TC_12_6_APPDATA_LENGTH, brief) {

	mPMONID = pmonid;
	NewProgram(this);
}

void EmuGSS_TCProgram12_6::BuildTCAppData(tc_descriptor_t &tc_descriptor) {

	SetNextUInt16(mPMONID);

}

//********************************************************+
void EmuGSS_ShowServ12TM(const struct tm_descriptor *pTMDescriptor) {

	GSSServ12TMHandler serv12TMHandler(pTMDescriptor->p_tm_bytes);
	serv12TMHandler.ShowTM();

}

GSSServ12TMHandler::GSSServ12TMHandler(uint8_t *pTMBytes) :
		GSSTMHandler(pTMBytes) {

}

void GSSServ12TMHandler::ShowTM() {

}


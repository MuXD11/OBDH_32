/*
 * emu_sc_pus_service3.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <stdio.h>

#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service5.h"
#include "public/icuasw_pus_services_iface_v1.h"

#define TC_5_5_APPDATA_LENGTH 2
#define TC_5_6_APPDATA_LENGTH 2


EmuGSS_TCProgram5_5::EmuGSS_TCProgram5_5(uint32_t uniTime2YK,
                         char * brief,
                         uint16_t rid)
                        :EmuGSS_TCProgram(uniTime2YK,5,5,
                        		TC_5_5_APPDATA_LENGTH,brief){

	mRID=rid;
    NewProgram(this);
}

void EmuGSS_TCProgram5_5::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextUInt16(mRID);

}


EmuGSS_TCProgram5_6::EmuGSS_TCProgram5_6(uint32_t uniTime2YK,
                         char * brief,
                         uint16_t rid)
                        :EmuGSS_TCProgram(uniTime2YK,5,6,
                        		TC_5_6_APPDATA_LENGTH,brief){

	mRID=rid;
    NewProgram(this);
}

void EmuGSS_TCProgram5_6::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextUInt16(mRID);

}



//********************************************************+
void EmuGSS_ShowServ5TM(const struct tm_descriptor *pTMDescriptor) {

	GSSServ5TMHandler serv5TMHandler(pTMDescriptor->p_tm_bytes);
	serv5TMHandler.ShowTM();

}



GSSServ5TMHandler::GSSServ5TMHandler(uint8_t *pTMBytes) :
		GSSTMHandler(pTMBytes) {

}

void GSSServ5TMHandler::ShowTM(){

	switch (mDFHeader.subtype) {
	case (1):
		ShowTM_5_1();
		break;
	case (2):
		ShowTM_5_2();
		break;
	case (3):
		ShowTM_5_3();
		break;
	case (4):
		ShowTM_5_4();
		break;

	}
}

void GSSServ5TMHandler::ShowTM_5_1(){

	uint16_t rid= GetNextUInt16AppDataField();

	printf(" Informative RID = 0x%X \n",rid);

}

void GSSServ5TMHandler::ShowTM_5_2(){

	uint16_t rid= GetNextUInt16AppDataField();

	printf(" Low Severity Anomaly RID = 0x%X \n",rid);

}

void GSSServ5TMHandler::ShowTM_5_3(){

	uint16_t rid= GetNextUInt16AppDataField();

	printf(" Medium Severity Anomaly RID 0x%X \n",rid);

}

void GSSServ5TMHandler::ShowTM_5_4(){

	uint16_t rid= GetNextUInt16AppDataField();

	printf(" High Severity Anomaly RID 0x%X \n",rid);


}




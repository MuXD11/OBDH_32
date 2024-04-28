/*
 * emu_gss_pus_service1.cpp
 *
 *  Created on: Jan 4, 2024
 *      Author: opolo70
 */

#include <stdio.h>

#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service1.h"

#define TM_1_2_CRC_ERROR_CODE 					2
#define TM_1_2_APID_NOT_VALID_ERROR_CODE 		3
#define TM_1_2_SOURCE_ID_NOT_VALID_ERROR_CODE 	4
#define TM_1_2_TYPE_NOT_VALID_ERROR_CODE 		5
#define TM_1_2_SUBTYPE_NOT_VALID_ERROR_CODE 	6

void EmuGSS_ShowServ1TM(const struct tm_descriptor *pTMDescriptor) {

	GSSServ1TMHandler serv1TMHandler(pTMDescriptor->p_tm_bytes);
	serv1TMHandler.ShowTM();

}

GSSServ1TMHandler::GSSServ1TMHandler(uint8_t *pTMBytes) :
		GSSTMHandler(pTMBytes) {

}

void GSSServ1TMHandler::ShowTM(){

	//TC PackID
	GetNextUInt16AppDataField();
	//TC Pack Seq Ctrl
	GetNextUInt16AppDataField();

	switch (mDFHeader.subtype) {
	case (2):
		ShowTM_1_2();
		break;

	}
}
void GSSServ1TMHandler::ShowTM_1_2() {

	uint8_t error_code = GetNextUInt8AppDataField();
	switch (error_code) {
	case (TM_1_2_CRC_ERROR_CODE):

		printf(": CRC ERROR ");
		break;

	case (TM_1_2_APID_NOT_VALID_ERROR_CODE):

		printf(": APID ERROR ");
		break;

	case (TM_1_2_SOURCE_ID_NOT_VALID_ERROR_CODE):

		printf(": SOURCE ID ERROR ");
		break;

	case (TM_1_2_TYPE_NOT_VALID_ERROR_CODE):

		printf(": TYPE NOT VALID");

		break;

	case (TM_1_2_SUBTYPE_NOT_VALID_ERROR_CODE):

		printf(": SUBTYPE NOT VALID");

		break;

	}

}


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

#define TM_1_8_TC_3_X_INVALID_SID 				1
#define TM_1_8_TC_20_X_INVALID_PID 				2
#define TM_1_8_TC_5_X_UNKNOWN_RID				3
#define TM_1_8_TC_12_X_PMONID_UNDEFINED			4
#define TM_1_8_TC_12_X_PMONID_DEFINED			5
#define TM_1_8_TC_12_X_INVALID_PMONID			6
#define TM_1_8_TC_19_X_EV_ACTION_IS_ENABLED  	8
#define TM_1_8_TC_19_1_MAX_EV_ACTIONS_REACHED 	9
#define TM_1_8_TC_19_1_EV_ACTION_REJECTED 		10
#define TM_1_8_TC_19_X_EV_ACTION_NOT_DEFINED  	11
#define TM_1_8_TC_2_X_DEVICE_NOT_VALID  		12

void EmuGSS_ShowServ1TM(const struct tm_descriptor *pTMDescriptor) {

	GSSServ1TMHandler serv1TMHandler(pTMDescriptor->p_tm_bytes);
	serv1TMHandler.ShowTM();

}

GSSServ1TMHandler::GSSServ1TMHandler(uint8_t *pTMBytes) :
		GSSTMHandler(pTMBytes) {

}

void GSSServ1TMHandler::ShowTM() {

	//TC PackID
	GetNextUInt16AppDataField();
	//TC Pack Seq Ctrl
	GetNextUInt16AppDataField();

	switch (mDFHeader.subtype) {
	case (2):
		ShowTM_1_2();
		break;
	case (8):
		ShowTM_1_8();
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

void GSSServ1TMHandler::ShowTM_1_8() {

	uint8_t error_code = GetNextUInt8AppDataField();
	switch (error_code) {
		case (TM_1_8_TC_3_X_INVALID_SID):

		printf(": INVALID SID ");
		break;

		case (TM_1_8_TC_20_X_INVALID_PID):

		printf(": INVALID PID ");
		break;

		case (TM_1_8_TC_5_X_UNKNOWN_RID):

		printf(": UNKNOWN RID ");
		break;

		case (TM_1_8_TC_12_X_PMONID_UNDEFINED):

		printf(": PMODID UNDEFINED");

		break;

		case (TM_1_8_TC_12_X_PMONID_DEFINED):

		printf(": PMODID IS DEFINED");

		break;

		case (TM_1_8_TC_12_X_INVALID_PMONID):

		printf(": INVALID PMONID" );

		break;
		case (TM_1_8_TC_19_X_EV_ACTION_IS_ENABLED):

		printf(": EV ACTION IS ENABLED");

		break;
		case (TM_1_8_TC_19_1_MAX_EV_ACTIONS_REACHED):

		printf(": MAX EV ACTIONS USED");

		break;

		case (TM_1_8_TC_19_1_EV_ACTION_REJECTED):

		printf(": EV ACTION REJECTED");

		break;

		case (TM_1_8_TC_19_X_EV_ACTION_NOT_DEFINED):

		printf(": EV ACTION NOT DEFINED");

		break;

		case (TM_1_8_TC_2_X_DEVICE_NOT_VALID):

		printf(": DEVICE NOT VALID");

		break;

	}
}

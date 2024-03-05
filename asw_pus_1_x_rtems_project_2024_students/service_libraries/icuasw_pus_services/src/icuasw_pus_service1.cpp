/*
 * icuasw_pus_service1.cpp
 *
 *  Created on: Dec 21, 2016
 *      Author: user
 */

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/cdtchandler.h"
#include "public/ccsds_pus.h"

#define TM_1_2_CRC_ERROR_CODE 					2
#define TM_1_2_APID_NOT_VALID_ERROR_CODE 		3
#define TM_1_2_SOURCE_ID_NOT_VALID_ERROR_CODE 	4
#define TM_1_2_TYPE_NOT_VALID_ERROR_CODE 		5
#define TM_1_2_SUBTYPE_NOT_VALID_ERROR_CODE 	6

//SourceID TC Counters
uint16_t SOLO_Mission_TimeLine_TC_Counter = 0;

uint16_t SOLO_TC_Sequences_TC_Counter = 0;

uint16_t SOLO_Direct_Commands_TC_Counter=0;



bool_t PUSService1::IsCRCValid(CDTCHandler &tcHandler) {

	uint16_t tc_cal_crc_value = tcHandler.GetCalculatedCRC();
	uint16_t tc_packet_err_ctrl = tcHandler.GetPacketErrorCtrl();

	//Compare with valid APIDs
	bool_t isValid = (tc_cal_crc_value == tc_packet_err_ctrl);

	return isValid;

}

bool_t PUSService1::IsAPIDValid(CDTCHandler &tcHandler) {

	//Compare with valid APIDs
	bool_t isValid = (EPD_APID == tcHandler.GetAPID());

	return isValid;

}

bool_t PUSService1::IsSourceIDValid(CDTCHandler &tcHandler) {

	//Get SourceID field
	uint16_t SourceID = tcHandler.GetSourceID();

	//Compare with valid SourceIDs
	bool_t isValid = ((SOLO_Mission_TimeLine_SourceID == SourceID)
			|| (SOLO_TC_Sequences_SourceID == SourceID)
			|| (SOLO_Direct_Commands_SourceID == SourceID) );

	return isValid;

}

void PUSService1::TryTCAcceptation(CDTCHandler &tcHandler) {


	TTCAcceptationStatus acceptationStatus = TCAcceptationOK;

	if (!IsCRCValid(tcHandler)) {

		acceptationStatus = TCAcceptationCRCError;

	} else if (!IsAPIDValid(tcHandler)) {

		acceptationStatus = TCAcceptationAPIDError;

	} else if (!IsSourceIDValid(tcHandler)) {

		acceptationStatus = TCAcceptationSourceIDError;

	} else {

		uint8_t type = tcHandler.GetType();
		uint8_t subtype = tcHandler.GetSubType();

		switch (type) {
		//TODO TC Acceptance and TC Classification
//		case (9):
//
//			switch (subtype) {
//
//			case (129):
//				tcHandler.SetExecCtrlAsPrioTC();
//				break;
//			default:
//				acceptationStatus = TCAcceptationSubTypeError;
//			}
//			break;
		case (17):
			switch (subtype) {
			case (1):
					//TC Classified as PrioTC
				tcHandler.SetExecCtrlAsPrioTC();
				break;
			default:
				acceptationStatus = TCAcceptationSubTypeError;
			}
			break;
		default:
			//TC is not accepted
			acceptationStatus = TCAcceptationTypeError;
			break;

		}
	}

	tcHandler.SetAcceptationStatus(acceptationStatus);

}


void PUSService1::CompleteTCRejection( CDTCHandler &tcHandler){

	tcHandler.FreeTCDescriptor();

}

void PUSService1::BuildTM_1_1(CDTCHandler &tcHandler, CDTMList &tmList) {

		CDTMHandler tm_handler(1, 1);

		tm_handler.SetUInt16AppDataField(tcHandler.GetPacketID());
		tm_handler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());

		tmList.AddTM(tm_handler.CloseTM());


}

void PUSService1::BuildTM_1_2(CDTCHandler &tcHandler, CDTMList &tmList) {

		TTCAcceptationStatus acceptationStatus=tcHandler.GetAcceptationStatus();
		CDTMHandler tm_handler(1, 2);

		tm_handler.SetUInt16AppDataField(tcHandler.GetPacketID());
		tm_handler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());

		switch (acceptationStatus) {

		case (TCAcceptationCRCError):

			tm_handler.SetUInt8AppDataField(TM_1_2_CRC_ERROR_CODE);

			tm_handler.SetUInt16AppDataField(tcHandler.GetPacketErrorCtrl());
			tm_handler.SetUInt16AppDataField(tcHandler.GetCalculatedCRC());

			break;

		case (TCAcceptationAPIDError):

			tm_handler.SetUInt8AppDataField(TM_1_2_APID_NOT_VALID_ERROR_CODE);

			break;

		case (TCAcceptationSourceIDError):

			tm_handler.SetUInt8AppDataField(
					TM_1_2_SOURCE_ID_NOT_VALID_ERROR_CODE);
			tm_handler.SetUInt8AppDataField(tcHandler.GetSourceID());


			break;

		case (TCAcceptationTypeError):

			tm_handler.SetUInt8AppDataField(TM_1_2_TYPE_NOT_VALID_ERROR_CODE);

			break;

		case (TCAcceptationSubTypeError):

				tm_handler.SetUInt8AppDataField(TM_1_2_SUBTYPE_NOT_VALID_ERROR_CODE);

			break;

		default:

			break;

		}

		tmList.AddTM(tm_handler.CloseTM());


}

void PUSService1::BuildTM_1_7(CDTCHandler &tcHandler, CDTMList &tmList) {

	CDTMHandler tm_handler(1, 7);

	tm_handler.SetUInt16AppDataField(tcHandler.GetPacketID());
	tm_handler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());

	tmList.AddTM(tm_handler.CloseTM());

}

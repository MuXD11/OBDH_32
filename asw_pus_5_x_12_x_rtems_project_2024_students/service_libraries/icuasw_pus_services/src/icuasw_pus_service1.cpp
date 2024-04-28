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

#define TM_1_8_TC_3_X_INVALID_SID 				1
#define TM_1_8_TC_20_X_INVALID_PID 				2
#define TM_1_8_TC_5_X_UNKNOWN_RID				3
#define TM_1_8_TC_12_X_PMONID_UNDEFINED			4
#define TM_1_8_TC_12_X_PMONID_DEFINED			5
#define TM_1_8_TC_12_X_INVALID_PMONID			6

//SourceID TC Counters
uint16_t SOLO_Mission_TimeLine_TC_Counter = 0;

uint16_t SOLO_TC_Sequences_TC_Counter = 0;

uint16_t SOLO_Direct_Commands_TC_Counter = 0;

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
			|| (SOLO_Direct_Commands_SourceID == SourceID));

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
		case (9):
			switch (subtype) {
			case (129):
				tcHandler.SetExecCtrlAsPrioTC();
				break;
			default:
				acceptationStatus = TCAcceptationSubTypeError;
			}
			break;
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
		case (3):
			switch (subtype) {
			case (5):
				//TC Classified as HK_FDIRTC
				tcHandler.SetExecCtrlAsHK_FDIRTC();
				break;
			case (6):
				//TC Classified as HK_FDIRTC
				tcHandler.SetExecCtrlAsHK_FDIRTC();
				break;
			case (31):
				//TC Classified as HK_FDIRTC
				tcHandler.SetExecCtrlAsHK_FDIRTC();
				break;

			default:
				acceptationStatus = TCAcceptationSubTypeError;
			}
			break;
		case (5):
			switch (subtype) {
			case (5):
				//TC Classified as HK_FDIRTC
				tcHandler.SetExecCtrlAsHK_FDIRTC();
				break;
			case (6):
				//TC Classified as HK_FDIRTC
				tcHandler.SetExecCtrlAsHK_FDIRTC();
				break;
			default:
				acceptationStatus = TCAcceptationSubTypeError;
			}
			break;
			case (12):
				switch (subtype) {
				case (1):
					//TC Classified as HK_FDIRTC
					tcHandler.SetExecCtrlAsHK_FDIRTC();
					break;
				case (5):
					//TC Classified as HK_FDIRTC
					tcHandler.SetExecCtrlAsHK_FDIRTC();
					break;
				case (6):
					//TC Classified as HK_FDIRTC
					tcHandler.SetExecCtrlAsHK_FDIRTC();
					break;
				default:
					acceptationStatus = TCAcceptationSubTypeError;
				}
				break;

		case (20):
			switch (subtype) {
			case (1):
				//TC Classified as BKGTC
				tcHandler.SetExecCtrlAsBKGTC();
				break;
			case (3):
				//TC Classified as BKGTC
				tcHandler.SetExecCtrlAsBKGTC();
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

void PUSService1::CompleteTCRejection(CDTCHandler &tcHandler) {

	tcHandler.FreeTCDescriptor();

}

void PUSService1::BuildTM_1_1(CDTCHandler &tcHandler, CDTMList &tmList) {

	CDTMHandler tmHandler(1, 1);

	tmHandler.SetUInt16AppDataField(tcHandler.GetPacketID());
	tmHandler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());

	tmList.AddTM(tmHandler.CloseTM());

}

void PUSService1::BuildTM_1_2(CDTCHandler &tcHandler, CDTMList &tmList) {

	TTCAcceptationStatus acceptationStatus = tcHandler.GetAcceptationStatus();
	CDTMHandler tmHandler(1, 2);

	tmHandler.SetUInt16AppDataField(tcHandler.GetPacketID());
	tmHandler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());

	switch (acceptationStatus) {

	case (TCAcceptationCRCError):

		tmHandler.SetUInt8AppDataField(TM_1_2_CRC_ERROR_CODE);

		tmHandler.SetUInt16AppDataField(tcHandler.GetPacketErrorCtrl());
		tmHandler.SetUInt16AppDataField(tcHandler.GetCalculatedCRC());

		break;

	case (TCAcceptationAPIDError):

		tmHandler.SetUInt8AppDataField(TM_1_2_APID_NOT_VALID_ERROR_CODE);

		break;

	case (TCAcceptationSourceIDError):

		tmHandler.SetUInt8AppDataField(
		TM_1_2_SOURCE_ID_NOT_VALID_ERROR_CODE);
		tmHandler.SetUInt8AppDataField(tcHandler.GetSourceID());

		break;

	case (TCAcceptationTypeError):

		tmHandler.SetUInt8AppDataField(TM_1_2_TYPE_NOT_VALID_ERROR_CODE);

		break;

	case (TCAcceptationSubTypeError):

		tmHandler.SetUInt8AppDataField(TM_1_2_SUBTYPE_NOT_VALID_ERROR_CODE);

		break;

	default:

		break;

	}

	tmList.AddTM(tmHandler.CloseTM());

}

void PUSService1::BuildTM_1_7(CDTCHandler &tcHandler, CDTMList &tmList) {

	CDTMHandler tmHandler(1, 7);

	tmHandler.SetUInt16AppDataField(tcHandler.GetPacketID());
	tmHandler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());

	tmList.AddTM(tmHandler.CloseTM());

}

void PUSService1::BuildTM_1_8_TC_3_X_SIDNotValid(CDTCHandler &tcHandler,
		CDTMList &tmList, uint16_t SID) {

	CDTMHandler tmHandler(1, 8);

	tmHandler.SetUInt16AppDataField(tcHandler.GetPacketID());
	tmHandler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());
	tmHandler.SetUInt16AppDataField(TM_1_8_TC_3_X_INVALID_SID);
	tmHandler.SetUInt16AppDataField(SID);

	tmList.AddTM(tmHandler.CloseTM());

}

void PUSService1::BuildTM_1_8_TC_20_X_PIDNotValid(CDTCHandler &tcHandler,
		CDTMList &tmList, uint16_t PID) {

	CDTMHandler tmHandler(1, 8);

	tmHandler.SetUInt16AppDataField(tcHandler.GetPacketID());
	tmHandler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());
	tmHandler.SetUInt16AppDataField(TM_1_8_TC_20_X_INVALID_PID);
	tmHandler.SetUInt16AppDataField(PID);

	tmList.AddTM(tmHandler.CloseTM());

}

void PUSService1::BuildTM_1_8_TC_5_X_RIDUnknown(CDTCHandler &tcHandler,
		CDTMList &tmList, uint16_t RID) {

	CDTMHandler tmHandler(1, 8);

	tmHandler.SetUInt16AppDataField(tcHandler.GetPacketID());
	tmHandler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());
	tmHandler.SetUInt16AppDataField(TM_1_8_TC_5_X_UNKNOWN_RID);
	tmHandler.SetUInt16AppDataField(RID);

	tmList.AddTM(tmHandler.CloseTM());
}

void PUSService1::BuildTM_1_8_TC_12_X_PMONIDUndefined(CDTCHandler &tcHandler,
		CDTMList &tmList, uint16_t PMONID) {
	CDTMHandler tmHandler(1, 8);

	tmHandler.SetUInt16AppDataField(tcHandler.GetPacketID());
	tmHandler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());
	tmHandler.SetUInt16AppDataField(TM_1_8_TC_12_X_PMONID_UNDEFINED);
	tmHandler.SetUInt16AppDataField(PMONID);

	tmList.AddTM(tmHandler.CloseTM());

}

void PUSService1::BuildTM_1_8_TC_12_X_PMONIDDefined(CDTCHandler &tcHandler,
		CDTMList &tmList, uint16_t PMONID) {

	CDTMHandler tmHandler(1, 8);

	tmHandler.SetUInt16AppDataField(tcHandler.GetPacketID());
	tmHandler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());
	tmHandler.SetUInt16AppDataField(TM_1_8_TC_12_X_PMONID_DEFINED);
	tmHandler.SetUInt16AppDataField(PMONID);

	tmList.AddTM(tmHandler.CloseTM());

}

void PUSService1::BuildTM_1_8_TC_12_X_PMONIDNotValid(CDTCHandler &tcHandler,
		CDTMList &tmList, uint16_t PMONID) {

	CDTMHandler tmHandler(1, 8);

	tmHandler.SetUInt16AppDataField(tcHandler.GetPacketID());
	tmHandler.SetUInt16AppDataField(tcHandler.GetPackSeqCtrl());
	tmHandler.SetUInt16AppDataField(TM_1_8_TC_12_X_INVALID_PMONID);
	tmHandler.SetUInt16AppDataField(PMONID);

	tmList.AddTM(tmHandler.CloseTM());

}


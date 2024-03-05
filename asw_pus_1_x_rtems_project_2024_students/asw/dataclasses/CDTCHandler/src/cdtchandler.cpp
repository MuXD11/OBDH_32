/*
 * cdtchandler.cpp
 *
 *  Created on: Dec 29, 2023
 *      Author: opolo70
 */

#include "public/cdtchandler.h"
#include "public/serialize.h"
#include "public/crc.h"



bool_t CDTCHandler::HandleIRQ(){

	return false;
	//return SC_Channel_RxData();

}

CDTCHandler::CDTCHandler() {

	mAcceptationStatus=TCAcceptationNotProcessed;
	mTCDescriptor.tc_num_bytes = 0;
	mTCDescriptor.p_tc_bytes=NULL;
}

uint8_t CDTCHandler::StartUpExecution() {

	uint8_t error = 0;
	//Check if descriptor is valid
	if (mTCDescriptor.p_tc_bytes) {

		mTCAppDataIndex = EPD_PUS_TC_APP_DATA_OFFSET;

	} else {
		//If not valid, report error and disable GetNexXXX Methods
		error = 1;
		mTCAppDataIndex = EPD_PUS_TC_MAX_NUM_OF_BYTES;
	}

	return error;

}

uint8_t CDTCHandler::FreeTCDescriptor(){

	uint8_t error = 0;
	//Check if descriptor is valid
	if (mTCDescriptor.p_tc_bytes) {

		tmtc_pool_free(mTCDescriptor.p_tc_bytes);

	} else {
		//If not valid, report error and disable GetNexXXX Methods
		error = 1;
	}
	mTCDescriptor.tc_num_bytes=0;
	mAcceptationStatus=TCAcceptationNotProcessed;

	return error;

}


uint8_t CDTCHandler::GetNextUInt8() {
	uint8_t data;
	if (IsValidTCField(1)) {

		data = mTCDescriptor.p_tc_bytes[mTCAppDataIndex];
		mTCAppDataIndex += 1;
	}
	return data;
}
uint16_t CDTCHandler::GetNextUInt16() {
	uint16_t data;
	if (IsValidTCField(2)) {
		data = deserialize_uint16(&mTCDescriptor.p_tc_bytes[mTCAppDataIndex]);
		mTCAppDataIndex += 2;
	}
	return data;
}
uint32_t CDTCHandler::GetNextUInt32() {
	uint32_t data;
	if (IsValidTCField(4)) {
		data = deserialize_uint32(&mTCDescriptor.p_tc_bytes[mTCAppDataIndex]);
		mTCAppDataIndex += 4;
	}
	return data;
}
uint64_t CDTCHandler::GetNextUInt64() {
	uint64_t data;
	if (IsValidTCField(8)) {
		data = deserialize_uint64(&mTCDescriptor.p_tc_bytes[mTCAppDataIndex]);
		mTCAppDataIndex += 8;
	}
	return data;
}

int8_t CDTCHandler::GetNextInt8() {
	int8_t data;
	if (IsValidTCField(1)) {
		data = mTCDescriptor.p_tc_bytes[mTCAppDataIndex];
		mTCAppDataIndex += 1;
	}
	return data;
}

int16_t CDTCHandler::GetNextInt16() {
	int16_t data;
	if (IsValidTCField(2)) {
		data = deserialize_int16(&mTCDescriptor.p_tc_bytes[mTCAppDataIndex]);
		mTCAppDataIndex += 2;
	}
	return data;
}

int32_t CDTCHandler::GetNextInt32() {
	int32_t data;
	if (IsValidTCField(4)) {
		data = deserialize_int32(&mTCDescriptor.p_tc_bytes[mTCAppDataIndex]);
		mTCAppDataIndex += 4;
	}
	return data;
}
int64_t CDTCHandler::GetNextInt64() {
	uint64_t data;
	if (IsValidTCField(8)) {
		data = deserialize_int64(&mTCDescriptor.p_tc_bytes[mTCAppDataIndex]);
		mTCAppDataIndex += 8;
	}
	return data;
}



uint16_t CDTCHandler::GetPacketID() {

	uint16_t tc_packet_id = 0;

	if (mTCDescriptor.p_tc_bytes) {

		tc_packet_id = deserialize_uint16(mTCDescriptor.p_tc_bytes);

	}
	return tc_packet_id;

}


uint16_t CDTCHandler::GetAPID() {

	uint16_t apid = 0;

	if (mTCDescriptor.p_tc_bytes) {

		uint16_t tc_packet_id = deserialize_uint16(mTCDescriptor.p_tc_bytes);

		apid = ccsds_pus_tc_get_APID(tc_packet_id);

	}
	return apid;

}

uint16_t CDTCHandler::GetPackSeqCtrl(){

	uint16_t tc_packet_seq_ctrl = 0;

	if (mTCDescriptor.p_tc_bytes) {

		tc_packet_seq_ctrl = deserialize_uint16(
				mTCDescriptor.p_tc_bytes + 2);


	}
	return tc_packet_seq_ctrl;

}

uint8_t CDTCHandler::GetSeqFlags() {

	uint8_t seqflags = 0;

	if (mTCDescriptor.p_tc_bytes) {

		uint16_t tc_packet_seq_ctrl = deserialize_uint16(
				mTCDescriptor.p_tc_bytes + 2);

		seqflags = ccsds_pus_tc_get_seq_flags(tc_packet_seq_ctrl);

	}
	return seqflags;

}

uint16_t CDTCHandler::GetSeqCount() {

	uint16_t seq_count = 0;

	if (mTCDescriptor.p_tc_bytes) {

		uint16_t tc_packet_seq_ctrl = deserialize_uint16(
				mTCDescriptor.p_tc_bytes + 2);

		seq_count = ccsds_pus_tc_get_seq_count(tc_packet_seq_ctrl);

	}

	return seq_count;
}

uint16_t CDTCHandler::GetPackLength() {

	uint16_t pack_length = 0;

	if (mTCDescriptor.p_tc_bytes) {

		pack_length = deserialize_uint16(mTCDescriptor.p_tc_bytes + 4);

	}

	return pack_length;
}

uint8_t CDTCHandler::GetAck() {

	uint8_t ack = 0;

	if (mTCDescriptor.p_tc_bytes) {

		ack = ccsds_pus_tc_get_ack(mTCDescriptor.p_tc_bytes[6]);

	}
	return ack;

}

uint8_t CDTCHandler::GetType() {

	uint8_t type = 0;

	if (mTCDescriptor.p_tc_bytes) {

		type = mTCDescriptor.p_tc_bytes[7];

	}
	return type;

}

uint8_t CDTCHandler::GetSubType() {

	uint8_t subtype = 0;

	if (mTCDescriptor.p_tc_bytes) {

		subtype = mTCDescriptor.p_tc_bytes[8];

	}
	return subtype;

}

uint8_t CDTCHandler::GetSourceID() {

	uint8_t sourceID = 0;

	if (mTCDescriptor.p_tc_bytes) {

		sourceID = mTCDescriptor.p_tc_bytes[9];

	}
	return sourceID;

}

uint16_t CDTCHandler::GetCalculatedCRC(){

	uint16_t crc_value = 0xFFFF;

	if (mTCDescriptor.p_tc_bytes) {

		uint16_t crc_offset= GetPackLength() + 5;
		crc_value = cal_crc_16(mTCDescriptor.p_tc_bytes,crc_offset);
	}

	return crc_value;

}

uint16_t CDTCHandler::GetPacketErrorCtrl(){

	uint16_t tc_packet_err_ctrl=0;

	if (mTCDescriptor.p_tc_bytes) {

		uint16_t crc_offset= GetPackLength() + 5;
		tc_packet_err_ctrl=
			deserialize_uint16(mTCDescriptor.p_tc_bytes + crc_offset);

		}

	return tc_packet_err_ctrl;

}

/*
 * emu_gss_tm_handler.cpp
 *
 *  Created on: Jan 9, 2024
 *      Author: opolo70
 */

#include "public/emu_gss_v1.h"
#include "public/serialize.h"
#include "public/crc.h"

#define PUS_TM_TYPE_OFFSET 7
#define PUS_TM_SUBTYPE_OFFSET 8

#define PUS_TM_APPDATA_OFFSET 10

uint8_t GSSTMHandler::GetPUSType(const struct tm_descriptor *pTMDescriptor) {

	uint8_t type = 0;
	if (pTMDescriptor->p_tm_bytes) {
		type = pTMDescriptor->p_tm_bytes[PUS_TM_TYPE_OFFSET];
	}
	return type;

}

uint8_t GSSTMHandler::GetPUSSubtype(
		const struct tm_descriptor *pTMDescriptor) {

	uint8_t subtype = 0;
	if (pTMDescriptor->p_tm_bytes) {
		subtype = pTMDescriptor->p_tm_bytes[PUS_TM_SUBTYPE_OFFSET];
	}
	return subtype;

}

GSSTMHandler::GSSTMHandler(uint8_t *pTMBytes) {

	mTMPacketHeader.packet_id = deserialize_uint16(pTMBytes);
	mTMPacketHeader.packet_seq_ctrl = deserialize_uint16(pTMBytes + 2);
	mTMPacketHeader.packet_length = deserialize_uint16(pTMBytes + 4);

	mDFHeader.version = pTMBytes[6];
	mDFHeader.type = pTMBytes[7];
	mDFHeader.subtype = pTMBytes[8];
	mDFHeader.destinationID = pTMBytes[9];

	pmNextAppBytes = pTMBytes + PUS_TM_APPDATA_OFFSET;

}

uint8_t GSSTMHandler::GetNextUInt8AppDataField() {

	uint8_t data;
	data = *pmNextAppBytes;
	pmNextAppBytes++;
	return data;
}

uint16_t GSSTMHandler::GetNextUInt16AppDataField() {

	uint16_t data;
	data = deserialize_uint16(pmNextAppBytes);
	pmNextAppBytes += 2;
	return data;
}

uint32_t GSSTMHandler::GetNextUInt32AppDataField() {

	uint32_t data;
	data = deserialize_uint32(pmNextAppBytes);
	pmNextAppBytes += 4;
	return data;

}

uint64_t GSSTMHandler::GetNextUInt64AppDataField() {

	uint64_t data;
	data = deserialize_uint64(pmNextAppBytes);
	pmNextAppBytes += 8;
	return data;

}

int8_t GSSTMHandler::GetNextInt8AppDataField() {
	int8_t data;
	data = *pmNextAppBytes;
	pmNextAppBytes++;
	return data;

}

int16_t GSSTMHandler::GetNextInt16AppDataField() {

	int16_t data;
	data = deserialize_int16(pmNextAppBytes);
	pmNextAppBytes += 2;
	return data;

}

int32_t GSSTMHandler::GetNextInt32AppDataField() {

	int32_t data;
	data = deserialize_int32(pmNextAppBytes);
	pmNextAppBytes += 4;
	return data;

}

int64_t GSSTMHandler::GetNextInt64AppDataField() {

	int64_t data;
	data = deserialize_int64(pmNextAppBytes);
	pmNextAppBytes += 8;
	return data;
}

/*
 * emu_gss_tc_program.cpp
 *
 *  Created on: Jan 9, 2024
 *      Author: opolo70
 */



#include "public/emu_gss_v1.h"
#include "public/serialize.h"
#include "public/crc.h"


EmuGSS_TCProgram *EmuGSS_TCProgram::sFirstTCProgram = NULL;
EmuGSS_TCProgram *EmuGSS_TCProgram::sCurrentTCProgram = NULL;
uint32_t EmuGSS_TCProgram::sTCSeqCounter = 0;

EmuGSS_TCProgram * EmuGSS_TCProgram::GetCurrentTCProgramed(){

	return EmuGSS_TCProgram::sCurrentTCProgram;

}

EmuGSS_TCProgram::EmuGSS_TCProgram(uint32_t uniTime2YK, uint8_t type,
		uint8_t subtype, uint16_t appDataLength, char *brief) {

	UniTime2YK = uniTime2YK;
	mType = type;
	mSubtype = subtype;
	mBrief = brief;
	mAppDataLength = appDataLength;
	pmAppData = NULL;
}

bool EmuGSS_TCProgram::SetCurrentTCProgramed(uint32_t uniTime2YK) {
	bool found = false;
	if (sFirstTCProgram) {
		if (sFirstTCProgram->UniTime2YK <= uniTime2YK) {
			sCurrentTCProgram = sFirstTCProgram;
			sFirstTCProgram = sFirstTCProgram->pmNext;
			found = true;
		}
	}
	return found;
}

void EmuGSS_TCProgram::NewProgram(EmuGSS_TCProgram *pTCProgram) {
	if (pTCProgram) {

		if (NULL == EmuGSS_TCProgram::sFirstTCProgram) {
			EmuGSS_TCProgram::sFirstTCProgram = pTCProgram;
			pTCProgram->pmNext = NULL;
		} else {
			bool found = false;
			EmuGSS_TCProgram *current;
			EmuGSS_TCProgram *prev = NULL;
			current = EmuGSS_TCProgram::sFirstTCProgram;
			while (!found) {
				if (current->UniTime2YK > pTCProgram->UniTime2YK) {
					if (prev) {
						prev->pmNext = pTCProgram;
					} else {
						EmuGSS_TCProgram::sFirstTCProgram = pTCProgram;
					}
					pTCProgram->pmNext = current;
					found = true;
				} else {
					prev = current;
					current = current->pmNext;
					if (NULL == current) {
						prev->pmNext = pTCProgram;
						pTCProgram->pmNext = NULL;
						found = true;
					}
				}
			}
		}
	}
}

void EmuGSS_TCProgram::BuildTC(tc_descriptor_t &tc_descriptor) {

	if (tc_descriptor.p_tc_bytes) {

		BuildTCPackHeader(tc_descriptor);
		BuildTCDFHeader(tc_descriptor);
		pmAppData = tc_descriptor.p_tc_bytes + 10;
		this->BuildTCAppData(tc_descriptor);

		uint16_t crc_offset = mAppDataLength + 10;
		uint16_t crc_value = cal_crc_16(tc_descriptor.p_tc_bytes, crc_offset);
		serialize_uint16(crc_value, tc_descriptor.p_tc_bytes + crc_offset);

		tc_descriptor.tc_num_bytes=mAppDataLength + 12;
	}

}
void EmuGSS_TCProgram::BuildTCPackHeader(tc_descriptor_t &tc_descriptor) {

	if (tc_descriptor.p_tc_bytes) {
		uint16_t packet_id = ccsds_pus_tm_build_packet_id(EPD_APID);

		uint16_t packet_seq_ctrl = ccsds_pus_tm_build_packet_seq_ctrl(0x3,
				sTCSeqCounter);

		sTCSeqCounter++;

		uint16_t packet_length = 5 + mAppDataLength;

		serialize_uint16(packet_id, tc_descriptor.p_tc_bytes);

		// Serialize Packet Sequence Control from packet_seq_ctrl
		serialize_uint16(packet_seq_ctrl, tc_descriptor.p_tc_bytes + 2);

		// Serialize Packet Length from packet_length
		serialize_uint16(packet_length, tc_descriptor.p_tc_bytes + 4);

	}

}
void EmuGSS_TCProgram::BuildTCDFHeader(tc_descriptor_t &tc_descriptor) {

	if (tc_descriptor.p_tc_bytes) {
		tc_descriptor.p_tc_bytes[6] = EPD_PUS_VERSION;
		tc_descriptor.p_tc_bytes[7] = mType;
		tc_descriptor.p_tc_bytes[8] = mSubtype;
		tc_descriptor.p_tc_bytes[9] = EPD_DESTINATION_ID;
	}
}

void EmuGSS_TCProgram::SetNextUInt8(uint8_t &data) {
	*pmAppData = data;
	pmAppData += 1;
}

void EmuGSS_TCProgram::SetNextUInt16(uint16_t &data) {
	serialize_uint16(data, pmAppData);
	pmAppData += 2;
}

void EmuGSS_TCProgram::SetNextUInt32(uint32_t &data) {
	serialize_uint32(data, pmAppData);
	pmAppData += 4;
}
void EmuGSS_TCProgram::SetNextUInt64(uint64_t &data) {
	serialize_uint64(data, pmAppData);
	pmAppData += 8;
}

void EmuGSS_TCProgram::SetNextInt8(int8_t &data) {
	*pmAppData = (uint8_t) data;
	pmAppData += 1;
}
void EmuGSS_TCProgram::SetNextInt16(int16_t &data) {
	serialize_int16(data, pmAppData);
	pmAppData += 2;
}

void EmuGSS_TCProgram::SetNextInt32(int32_t &data) {
	serialize_int32(data, pmAppData);
	pmAppData += 4;
}
void EmuGSS_TCProgram::SetNextInt64(int64_t &data) {
	serialize_int64(data, pmAppData);
	pmAppData += 8;
}

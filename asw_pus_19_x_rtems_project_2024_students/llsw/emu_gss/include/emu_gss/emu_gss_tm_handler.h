/*
 * emu_gss_tm_handler.h
 *
 *  Created on: Jan 9, 2024
 *      Author: opolo70
 */

#ifndef LLSW_EMU_GSS_INCLUDE_PUBLIC_EMU_GSS_TM_HANDLER_H_
#define LLSW_EMU_GSS_INCLUDE_PUBLIC_EMU_GSS_TM_HANDLER_H_

class GSSTMHandler{

protected:

	struct ccsds_pus_tmtc_packet_header mTMPacketHeader;
	struct ccsds_pus_tm_df_header mDFHeader;

	uint8_t *pmNextAppBytes;

public:


	GSSTMHandler(uint8_t * pTMBytes);

	static uint8_t GetPUSType(const struct tm_descriptor *pTMDescriptor);
	static uint8_t GetPUSSubtype(const struct tm_descriptor *pTMDescriptor);


	uint8_t GetNextUInt8AppDataField();
	uint16_t GetNextUInt16AppDataField();
	uint32_t GetNextUInt32AppDataField();
	uint64_t GetNextUInt64AppDataField();

	int8_t GetNextInt8AppDataField();
	int16_t GetNextInt16AppDataField();
	int32_t GetNextInt32AppDataField();
	int64_t GetNextInt64AppDataField();


};





#endif /* LLSW_EMU_GSS_INCLUDE_PUBLIC_EMU_GSS_TM_HANDLER_H_ */

/*
 * cdtmhandler.h
 *
 *  Created on: Jan 4, 2024
 *      Author: opolo70
 */

#ifndef ASW_DATACLASSES_CDTMHANDLER_INCLUDE_CDTMHANDLER_H_
#define ASW_DATACLASSES_CDTMHANDLER_INCLUDE_CDTMHANDLER_H_

#include "public/config.h"
#include "public/basic_types.h"
#include "public/ccsds_pus.h"
#include "public/tmtc_dyn_mem.h"


class CDTMHandler{

	friend class PUSService1;
	friend class PUSService3;
	friend class PUSService17;

private:

	//Offset to the next field
	uint16_t mAppDataNextFieldOffset;

	//telemetry descriptor
	struct tm_descriptor mTMDescriptor;

	//TM Sequence Counter
	static uint16_t  sGlobalTMSeqCounter;


	//Constructor
	CDTMHandler(uint8_t type, uint8_t subtype);


protected:

	struct tm_descriptor CloseTM();


	void SetUInt8AppDataField(uint8_t appDataField);

	void SetUInt16AppDataField(uint16_t data);

	void SetUInt32AppDataField(uint32_t data);

	void SetUInt64AppDataField(uint64_t data);

	void SetInt8AppDataField(int8_t data);

	void SetInt16AppDataField(int16_t data);

	void SetInt32AppDataField(int32_t data);

	void SetInt64AppDataField(int64_t data);

};



#endif /* ASW_DATACLASSES_CDTMHANDLER_INCLUDE_CDTMHANDLER_H_ */

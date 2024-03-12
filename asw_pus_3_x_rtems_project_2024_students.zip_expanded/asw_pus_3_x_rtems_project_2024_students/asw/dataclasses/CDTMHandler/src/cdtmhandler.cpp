/*
 * cdtmhandler.cpp
 *
 *  Created on: Jan 4, 2024
 *      Author: opolo70
 */


#include "public/cdtmhandler.h"
#include "public/serialize.h"



//****************************CDTMHandler************************************


uint16_t  CDTMHandler::sGlobalTMSeqCounter=0;


CDTMHandler::CDTMHandler(uint8_t type, uint8_t subtype){


	mTMDescriptor.p_tm_bytes=tmtc_pool_alloc();

	if(mTMDescriptor.p_tm_bytes){

		mTMDescriptor.p_tm_bytes[6]=EPD_PUS_VERSION;
		mTMDescriptor.p_tm_bytes[7]=type;
		mTMDescriptor.p_tm_bytes[8]=subtype;
		mTMDescriptor.p_tm_bytes[9]=EPD_DESTINATION_ID;

		mAppDataNextFieldOffset=10;
	}else{

		mTMDescriptor.tm_num_bytes=0;
		//This disable the writting in the AppData bytes
		mAppDataNextFieldOffset=EPD_PUS_TM_MAX_NUM_OF_BYTES;
	}

}

void CDTMHandler::SetUInt8AppDataField(uint8_t data){

	//Check validity of mAppDataNextFieldOffset
	if(mAppDataNextFieldOffset < (EPD_PUS_TM_MAX_NUM_OF_BYTES-1)){

		mTMDescriptor.p_tm_bytes[mAppDataNextFieldOffset]=data;

		mAppDataNextFieldOffset++;

	}

}

void CDTMHandler::SetUInt16AppDataField(uint16_t data){

	//Check validity of mAppDataNextFieldOffset
	if(mAppDataNextFieldOffset < (EPD_PUS_TM_MAX_NUM_OF_BYTES-2)){

		serialize_uint16(data,
				mTMDescriptor.p_tm_bytes + mAppDataNextFieldOffset);

		mAppDataNextFieldOffset+=2;
	}


}

void CDTMHandler::SetUInt32AppDataField(uint32_t data){

	//Check validity of mAppDataNextFieldOffset
	if(mAppDataNextFieldOffset < (EPD_PUS_TM_MAX_NUM_OF_BYTES-4)){

		serialize_uint32(data,
				mTMDescriptor.p_tm_bytes + mAppDataNextFieldOffset);

		mAppDataNextFieldOffset+=4;


	}

}

void CDTMHandler::SetUInt64AppDataField(uint64_t data){

	//Check validity of mAppDataNextFieldOffset
	if(mAppDataNextFieldOffset < (EPD_PUS_TM_MAX_NUM_OF_BYTES-8)){

		serialize_uint64(data,
				mTMDescriptor.p_tm_bytes + mAppDataNextFieldOffset);

		mAppDataNextFieldOffset+=8;


	}

}

void CDTMHandler::SetInt8AppDataField(int8_t data){


	//Check validity of mAppDataNextFieldOffset
	if(mAppDataNextFieldOffset < (EPD_PUS_TM_MAX_NUM_OF_BYTES-1)){

		mTMDescriptor.p_tm_bytes[mAppDataNextFieldOffset]=(uint8_t)data;

			mAppDataNextFieldOffset++;

	}

}

void CDTMHandler::SetInt16AppDataField(int16_t data){

	//Check validity of mAppDataNextFieldOffset
	if(mAppDataNextFieldOffset < (EPD_PUS_TM_MAX_NUM_OF_BYTES-2)){

		serialize_int16(data,
				mTMDescriptor.p_tm_bytes + mAppDataNextFieldOffset);

		mAppDataNextFieldOffset+=2;


	}

}

void CDTMHandler::SetInt32AppDataField(int32_t data){

	//Check validity of mAppDataNextFieldOffset
	if(mAppDataNextFieldOffset < (EPD_PUS_TM_MAX_NUM_OF_BYTES-4)){

		serialize_int32(data,
				mTMDescriptor.p_tm_bytes + mAppDataNextFieldOffset);

		mAppDataNextFieldOffset+=4;


	}


}

void CDTMHandler::SetInt64AppDataField(int64_t data){

	//Check validity of mAppDataNextFieldOffset
	if(mAppDataNextFieldOffset < (EPD_PUS_TM_MAX_NUM_OF_BYTES-8)){

		serialize_int64(data,
				mTMDescriptor.p_tm_bytes + mAppDataNextFieldOffset);

		mAppDataNextFieldOffset+=8;

	}

}


struct tm_descriptor CDTMHandler::CloseTM(){

	if(mTMDescriptor.p_tm_bytes){

		 uint16_t packet_id = ccsds_pus_tm_build_packet_id(EPD_APID);

		 uint16_t packet_seq_ctrl =
		            ccsds_pus_tm_build_packet_seq_ctrl(0x3, sGlobalTMSeqCounter);

		 //Increase the sequence counter
		 sGlobalTMSeqCounter++;


		 uint16_t packet_length = mAppDataNextFieldOffset-6-1;

		 // Serialize Packet ID

		 serialize_uint16(packet_id, mTMDescriptor.p_tm_bytes);

		 // Serialize Packet Sequence Control from packet_seq_ctrl
		 serialize_uint16(packet_seq_ctrl, mTMDescriptor.p_tm_bytes + 2);

		 // Serialize Packet Length from packet_length
		 serialize_uint16(packet_length, mTMDescriptor.p_tm_bytes + 4);

		 mTMDescriptor.tm_num_bytes = mAppDataNextFieldOffset;


	}

	return mTMDescriptor;
}


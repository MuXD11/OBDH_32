/*
 * emu_gss_tc_program.h
 *
 *  Created on: Jan 9, 2024
 *      Author: opolo70
 */

#ifndef LLSW_EMU_GSS_INCLUDE_EMU_GSS_EMU_GSS_TC_PROGRAM_H_
#define LLSW_EMU_GSS_INCLUDE_EMU_GSS_EMU_GSS_TC_PROGRAM_H_



class EmuGSS_TCProgram{

	friend void EmuGSS_SendProgrammedTCs();
	friend void SC_Channel_GetNextTC(CDTCHandler *tc);

protected:
  //tc_descriptor_t tc_descriptor;
  uint32_t UniTime2YK;
  EmuGSS_TCProgram *pmNext;

  uint8_t mType;
  uint8_t mSubtype;
  uint16_t mAppDataLength;

  char * mBrief;

  static uint32_t sTCSeqCounter;

  static EmuGSS_TCProgram *sFirstTCProgram;
  static EmuGSS_TCProgram *sCurrentTCProgram;

  byte_t *pmAppData;

  static void NewProgram(EmuGSS_TCProgram *);

  EmuGSS_TCProgram(uint32_t uniTime2YK,
            uint8_t type,
            uint8_t subtype,
			uint16_t appDataLength,
            char * brief);
public:
  static bool SetCurrentTCProgramed(uint32_t uniTime2YK);

  uint8_t GetType(){return mType;}
  uint8_t GetSubtype(){return mSubtype;}
  char * GetBrief(){return mBrief;}

private:
  void BuildTCPackHeader(tc_descriptor_t &tc_descriptor);
  void BuildTCDFHeader(tc_descriptor_t &tc_descriptor);
  virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor)=0;

protected:

  static EmuGSS_TCProgram * GetCurrentTCProgramed();

  void BuildTC(tc_descriptor_t &tc_descriptor);


  void SetNextUInt8(uint8_t & data);

  void SetNextUInt16(uint16_t & data);

  void SetNextUInt32(uint32_t & data);

  void SetNextUInt64(uint64_t & data);

  void SetNextInt8(int8_t & data);

  void SetNextInt16(int16_t & data);

  void SetNextInt32(int32_t & data);

  void SetNextInt64(int64_t & data);

};




#endif /* LLSW_EMU_GSS_INCLUDE_EMU_GSS_EMU_GSS_TC_PROGRAM_H_ */

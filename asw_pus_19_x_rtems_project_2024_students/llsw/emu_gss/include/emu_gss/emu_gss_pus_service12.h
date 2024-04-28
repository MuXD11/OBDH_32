/*
 * emu_sc_pus_service12.h
 *
 *  Created on: Jan 16, 2024
 *      Author: user
 */

#ifndef EMU_SC_PUS_SERVICE12_H_
#define EMU_SC_PUS_SERVICE12_H_

class EmuGSS_TCProgram12_1: public EmuGSS_TCProgram {

	uint16_t mPMONID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram12_1(uint32_t uniTime2YK, char *brief, uint16_t PMONID);

};

class EmuGSS_TCProgram12_2: public EmuGSS_TCProgram {

	uint16_t mPMONID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram12_2(uint32_t uniTime2YK, char *brief, uint16_t PMONID);

};

class EmuGSS_TCProgram12_5: public EmuGSS_TCProgram {

	uint16_t mPMONID;
	uint16_t mPID;
	uint8_t mInterval;
	uint16_t mLowlimit;
	uint16_t mLowlimitRID;
	uint16_t mHighlimit;
	uint16_t mHighlimitRID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram12_5(uint32_t uniTime2YK, char *brief, uint16_t pmonid,
			uint16_t pid, uint8_t interval, uint16_t lowlimit,
			uint16_t lowlimit_rid, uint16_t highlimit, uint16_t highlimit_rid);

};

class EmuGSS_TCProgram12_6: public EmuGSS_TCProgram {

	uint16_t mPMONID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram12_6(uint32_t uniTime2YK, char *brief, uint16_t PMONID);

};

void EmuGSS_ShowServ12TM(struct tm_descriptor *pTMDescriptor);

class GSSServ12TMHandler: public GSSTMHandler {

	friend void EmuGSS_ShowServ12TM(const struct tm_descriptor*);

protected:

	GSSServ12TMHandler(uint8_t *pTMBytes);

	void ShowTM();

};

#endif /* EMU_SC_PUS_SERVICE12_H_ */

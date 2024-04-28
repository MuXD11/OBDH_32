/*
 * emu_sc_pus_service3.h
 *
 *  Created on: Jan 16, 2024
 *      Author: user
 */

#ifndef EMU_SC_PUS_SERVICE20_H_
#define EMU_SC_PUS_SERVICE20_H_

class EmuGSS_TCProgram20_1:public EmuGSS_TCProgram{

	uint16_t mPID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram20_1(uint32_t uniTime2YK,
                 char * brief,uint16_t PID);


};

class EmuGSS_TCProgram20_3:public EmuGSS_TCProgram{

	uint16_t mPID;
	uint16_t mValue;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram20_3(uint32_t uniTime2YK,
                 char * brief,uint16_t PID, uint16_t value);


};


void EmuGSS_ShowServ20TM(struct tm_descriptor *pTMDescriptor);


class GSSServ20TMHandler:public GSSTMHandler{

	friend void EmuGSS_ShowServ20TM(const struct tm_descriptor * );

protected:

	GSSServ20TMHandler(uint8_t * pTMBytes);

	void ShowTM();

	void ShowTM_20_2();


};



#endif /* EMU_SC_PUS_SERVICE9_H_ */

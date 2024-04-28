/*
 * emu_sc_pus_service3.h
 *
 *  Created on: Jan 16, 2017
 *      Author: user
 */

#ifndef EMU_SC_PUS_SERVICE3_H_
#define EMU_SC_PUS_SERVICE3_H_

class EmuGSS_TCProgram3_5:public EmuGSS_TCProgram{

	uint16_t mSID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram3_5(uint32_t uniTime2YK,
                 char * brief,uint16_t SID);


};

class EmuGSS_TCProgram3_6:public EmuGSS_TCProgram{

	uint16_t mSID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram3_6(uint32_t uniTime2YK,
                 char * brief,uint16_t SID);


};

class EmuGSS_TCProgram3_31:public EmuGSS_TCProgram{

	uint16_t mSID;
	uint8_t mCollectInterval;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram3_31(uint32_t uniTime2YK,
                 char * brief,uint16_t SID, uint8_t collectInterval);


};


void EmuGSS_ShowServ3TM(struct tm_descriptor *pTMDescriptor);


class GSSServ3TMHandler:public GSSTMHandler{

	friend void EmuGSS_ShowServ3TM(const struct tm_descriptor * );

protected:

	GSSServ3TMHandler(uint8_t * pTMBytes);

	void ShowTM();

	void ShowTM_3_25();


};



#endif /* EMU_SC_PUS_SERVICE9_H_ */

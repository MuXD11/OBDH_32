/*
 * emu_sc_pus_service5.h
 *
 *  Created on: Jan 16, 2024
 *      Author: user
 */

#ifndef EMU_SC_PUS_SERVICE5_H_
#define EMU_SC_PUS_SERVICE5_H_

class EmuGSS_TCProgram5_5:public EmuGSS_TCProgram{

	uint16_t mRID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram5_5(uint32_t uniTime2YK,
                 char * brief,uint16_t SID);


};

class EmuGSS_TCProgram5_6:public EmuGSS_TCProgram{

	uint16_t mRID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram5_6(uint32_t uniTime2YK,
                 char * brief,uint16_t SID);


};

void EmuGSS_ShowServ5TM(struct tm_descriptor *pTMDescriptor);


class GSSServ5TMHandler:public GSSTMHandler{

	friend void EmuGSS_ShowServ5TM(const struct tm_descriptor * );

protected:

	GSSServ5TMHandler(uint8_t * pTMBytes);

	void ShowTM();

	void ShowTM_5_1();

	void ShowTM_5_2();

	void ShowTM_5_3();

	void ShowTM_5_4();
};




#endif /* EMU_SC_PUS_SERVICE9_H_ */

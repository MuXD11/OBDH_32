/*
 * emu_sc_pus_service19.h
 *
 *  Created on: Jan 16, 2024
 *      Author: user
 */

#ifndef EMU_SC_PUS_SERVICE19_H_
#define EMU_SC_PUS_SERVICE19_H_

class EmuGSS_TCProgram19_1_Action_2_1: public EmuGSS_TCProgram {

	uint16_t mEvID;
	EmuGSS_TCProgram2_1 mProgram_2_1;
	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram19_1_Action_2_1(uint32_t uniTime2YK, char *brief
							, uint16_t evID
							, uint8_t deviceID
							, enum DeviceCommandOnOff_t devicecommand);

};

class EmuGSS_TCProgram19_2: public EmuGSS_TCProgram {

	uint16_t mEvID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram19_2(uint32_t uniTime2YK, char *brief, uint16_t mEvID);

};

class EmuGSS_TCProgram19_4: public EmuGSS_TCProgram {

	uint16_t mEvID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram19_4(uint32_t uniTime2YK, char *brief, uint16_t mEvID);

};

class EmuGSS_TCProgram19_5: public EmuGSS_TCProgram {

	uint16_t mEvID;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram19_5(uint32_t uniTime2YK, char *brief, uint16_t mEvID);

};

void EmuGSS_ShowServ19TM(struct tm_descriptor *pTMDescriptor);

class GSSServ19TMHandler: public GSSTMHandler {

	friend void EmuGSS_ShowServ19TM(const struct tm_descriptor*);

protected:

	GSSServ19TMHandler(uint8_t *pTMBytes);

	void ShowTM();

};

#endif /* EMU_SC_PUS_SERVICE12_H_ */

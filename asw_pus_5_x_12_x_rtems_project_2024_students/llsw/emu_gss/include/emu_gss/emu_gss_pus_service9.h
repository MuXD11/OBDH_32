/*
 * emu_sc_pus_service9.h
 *
 *  Created on: Jan 16, 2017
 *      Author: user
 */

#ifndef EMU_SC_PUS_SERVICE9_H_
#define EMU_SC_PUS_SERVICE9_H_

class EmuGSS_TCProgram9_129:public EmuGSS_TCProgram{

	uint32_t mNextUniTime2YK;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram9_129(uint32_t uniTime2YK,
                 char * brief,uint32_t nextUniTime2YK);


};





#endif /* EMU_SC_PUS_SERVICE9_H_ */

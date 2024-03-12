/*
 * emu_gss_pus_service1.h
 *
 *  Created on: Jan 4, 2024
 *      Author: opolo70
 */

#ifndef LLSW_EMU_GSS_INCLUDE_EMU_GSS_EMU_GSS_PUS_SERVICE1_H_
#define LLSW_EMU_GSS_INCLUDE_EMU_GSS_EMU_GSS_PUS_SERVICE1_H_

#include "public/emu_gss_v1.h"


void EmuGSS_ShowServ1TM(struct tm_descriptor *pTMDescriptor);


class GSSServ1TMHandler:public GSSTMHandler{

	friend void EmuGSS_ShowServ1TM(const struct tm_descriptor * );

protected:

	GSSServ1TMHandler(uint8_t * pTMBytes);

	void ShowTM();

	void ShowTM_1_2();

	void ShowTM_1_8();


};




#endif /* LLSW_EMU_GSS_INCLUDE_EMU_GSS_EMU_GSS_PUS_SERVICE1_H_ */

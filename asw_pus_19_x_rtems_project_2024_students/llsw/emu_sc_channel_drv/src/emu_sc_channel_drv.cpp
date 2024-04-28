/*
 * sc_channel_drv.c
 *
 *  Created on: Dec 20, 2016
 *      Author: user
 */

#include <public/sc_channel_drv_v1.h>
#include "public/emu_gss_v1.h"
#include "public/tmtc_dyn_mem.h"



void SC_Channel_Init() {
	init_tmtc_pool();
}

bool_t SC_Channel_RxData(){

	return false;
}

void SC_Channel_GetNextTC(CDTCHandler *tc) {

	EmuGSS_TCProgram * ptc_program=EmuGSS_TCProgram::GetCurrentTCProgramed();

	tc->mTCDescriptor.p_tc_bytes=tmtc_pool_alloc();

	ptc_program->BuildTC(tc->mTCDescriptor);

}



void SC_Channel_TxTM(const tm_descriptor_t *pTMDescriptor) {

	EmuGSS_ShowTM(pTMDescriptor);

}

void SC_Channel_TxTMList(CDTMList *pTmList) {
	for (uint8_t i = 0; i < pTmList->GetTMNumber(); i++) {

		SC_Channel_TxTM(pTmList->GetpTM(i));

		tmtc_pool_free(pTmList->GetTM(i).p_tm_bytes);
	}
}


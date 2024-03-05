/*
 * emu_gss.cpp
 *
 *  Created on: Jan 3, 2024
 *      Author: opolo70
 */

#include <stdio.h>

#include "public/emu_gss_v1.h"

#include <public/ccepdmanager_iface_v1.h>
#include <public/emu_hw_timecode_drv_v1.h>


#include "public/serialize.h"



void EmuGSS_ShowTM(const struct tm_descriptor *pTMDescriptor) {

	//Get TM Type
	uint8_t tm_type = GSSTMHandler::GetPUSType(pTMDescriptor);
	uint8_t tm_subtype = GSSTMHandler::GetPUSSubtype(pTMDescriptor);

	printf("GSS Rx TM (%i,%i)", tm_type, tm_subtype);

	switch (tm_type) {

	case (1):

		EmuGSS_ShowServ1TM(pTMDescriptor);

		break;

	case (3):
		//EmuGSS_ShowServ3TM(pTMDescriptor);
		break;

	case (5):

		break;

	};

	printf("\n");

}

void EmuGSS_PassSecond() {

//Emulate Hw TimeCode reception TO_DO

	printf("\nCurrent UniTime is = %i\n", EmuHwTimeCodeGetCurrentUniTimeY2K());

	EmuGSS_SendProgrammedTCs();

}

void EmuGSS_SendProgrammedTCs() {

	uint32_t currentUniTimeY2K = EmuHwTimeCodeGetCurrentUniTimeY2K();
	while (EmuGSS_TCProgram::SetCurrentTCProgramed(currentUniTimeY2K)) {

		printf("\nGSS Tx TC(%i,%i) ",
				(EmuGSS_TCProgram::sCurrentTCProgram)->GetType(),
				(EmuGSS_TCProgram::sCurrentTCProgram)->GetSubtype());

		printf(EmuGSS_TCProgram::sCurrentTCProgram->GetBrief());

		printf("\n");

//TODO Signal EDP RxTC IRQ vector (18) Bottom Half
		//CCEPDManager::EDROOMEventIRQ18.SignalFromTask();

		Pr_DelayIn(Pr_Time(0, 20000));

	}
}



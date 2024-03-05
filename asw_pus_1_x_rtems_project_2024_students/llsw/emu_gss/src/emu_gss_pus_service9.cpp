/*
 * emu_sc_pus_service9.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service9.h"

#define TC_9_129_APPDATA_LENGTH 4

EmuGSS_TCProgram9_129::EmuGSS_TCProgram9_129(uint32_t uniTime2YK,
                         char * brief,
                         uint32_t nextUniTime2YK)
                        :EmuGSS_TCProgram(uniTime2YK,9,129,
                        		TC_9_129_APPDATA_LENGTH,brief){

	mNextUniTime2YK=nextUniTime2YK;
    NewProgram(this);
}

void EmuGSS_TCProgram9_129::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextUInt32(mNextUniTime2YK);

}

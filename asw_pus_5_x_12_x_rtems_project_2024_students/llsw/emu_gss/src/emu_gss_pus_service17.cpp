/*
 * emu_sc_pus_service17.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: user
 */



#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service17.h"

EmuGSS_TCProgram17_1::EmuGSS_TCProgram17_1(uint32_t uniTime2YK,
                         char * brief)
                        :EmuGSS_TCProgram(uniTime2YK,17,1,0,brief){

     NewProgram(this);
}

void EmuGSS_TCProgram17_1::BuildTCAppData(tc_descriptor_t &tc_descriptor){


}

#define TC_17_3_APPDATA_LENGTH 2

EmuGSS_TCProgram17_3::EmuGSS_TCProgram17_3(uint32_t uniTime2YK,
        				char * brief,uint16_t APID)
                        :EmuGSS_TCProgram(uniTime2YK,17,3,TC_17_3_APPDATA_LENGTH,brief){

	mAPID=APID;
    NewProgram(this);
}

void EmuGSS_TCProgram17_3::BuildTCAppData(tc_descriptor_t &tc_descriptor){


}

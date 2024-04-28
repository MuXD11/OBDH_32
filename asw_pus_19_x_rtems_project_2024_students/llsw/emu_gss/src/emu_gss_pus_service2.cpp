/*
 * emu_sc_pus_service2.cpp
 *
 *  Created on: Jan 13, 2024
 *      Author: user
 */

#include <stdio.h>

#include "public/emu_gss_v1.h"
#include "emu_gss/emu_gss_pus_service2.h"
#include "public/icuasw_pus_services_iface_v1.h"

#define TC_2_1_APPDATA_LENGTH 2


EmuGSS_TCProgram2_1::EmuGSS_TCProgram2_1(uint32_t uniTime2YK,
                         char * brief,
						 uint8_t deviceID,
						 enum DeviceCommandOnOff_t devicecommand)
                        :EmuGSS_TCProgram(uniTime2YK,2,1,
                        		TC_2_1_APPDATA_LENGTH,brief){

	mDeviceOnOffCommand=deviceID | (devicecommand <<8);

    NewProgram(this);
}

EmuGSS_TCProgram2_1::EmuGSS_TCProgram2_1(
						 uint8_t deviceID,
						 enum DeviceCommandOnOff_t devicecommand)
                        :EmuGSS_TCProgram(0,2,1,
                        		TC_2_1_APPDATA_LENGTH,"NULL"){

	mDeviceOnOffCommand=deviceID | (devicecommand <<8);

	//No Program
    //NewProgram(this);
}

void EmuGSS_TCProgram2_1::BuildTCAppData(tc_descriptor_t &tc_descriptor){

	SetNextUInt16(mDeviceOnOffCommand);

}





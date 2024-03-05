/*
 * emu_timecode_hw.cpp
 *
 *  Created on: Jan 5, 2024
 *      Author: opolo70
 */

#include <public/emu_hw_timecode_drv_v1.h>


uint32_t EMU_TIME_CODE_HW_NextUniTimeY2KSecns=UNITIME_AFTER_POWER_ON + 1;
uint32_t EMU_TIME_CODE_HW_CurrentUniTimeY2KSecns=UNITIME_AFTER_POWER_ON;

void EmuHwTimeCodePassSecond(){

	EMU_TIME_CODE_HW_CurrentUniTimeY2KSecns =
										EMU_TIME_CODE_HW_NextUniTimeY2KSecns;
	EMU_TIME_CODE_HW_NextUniTimeY2KSecns++;

}

void EmuHwTimeCodeSetNextUniTimeY2K(uint32_t nextUniTimeY2KSecns){

	EMU_TIME_CODE_HW_NextUniTimeY2KSecns=nextUniTimeY2KSecns;
}

uint32_t EmuHwTimeCodeGetCurrentUniTimeY2K(){

	return EMU_TIME_CODE_HW_CurrentUniTimeY2KSecns;

}

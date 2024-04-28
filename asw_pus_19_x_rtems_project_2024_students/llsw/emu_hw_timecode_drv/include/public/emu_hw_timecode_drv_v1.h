/*
 * emu_hw_timecode_drv.h
 *
 *  Created on: Jan 5, 2024
 *      Author: opolo70
 */

#ifndef LLSW_EMU_HW_TIMECODE_DRV_INCLUDE_PUBLIC_EMU_HW_TIMECODE_DRV_V1_H_
#define LLSW_EMU_HW_TIMECODE_DRV_INCLUDE_PUBLIC_EMU_HW_TIMECODE_DRV_V1_H_

#include "public/basic_types.h"

#define UNITIME_AFTER_POWER_ON 100000

void EmuHwTimeCodePassSecond();

void EmuHwTimeCodeSetNextUniTimeY2K(uint32_t nextUniTimeY2KSecns);

uint32_t EmuHwTimeCodeGetCurrentUniTimeY2K();


#endif /* LLSW_EMU_HW_TIMECODE_DRV_INCLUDE_PUBLIC_EMU_HW_TIMECODE_DRV_V1_H_ */

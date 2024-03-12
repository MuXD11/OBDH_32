/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: user
 */

#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>



//#define FT_SOLO_EPD_ICU_SERV_17_0010
//#define FT_SOLO_EPD_ICU_SERV_9_0020
//#define FT_SOLO_EPD_ICU_SERV_1_REJECTED_TC_0030

//TODO Enable service 3 test
//#define FT_SOLO_EPD_ICU_SERV_3_DISABLE_SID0_0040
//#define FT_SOLO_EPD_ICU_SERV_3_UPDATE_INTERVAL_TC_0050


#ifdef FT_SOLO_EPD_ICU_SERV_17_0010

EmuGSS_TCProgram17_1 prog_FT_0010_step_0(UNITIME_AFTER_POWER_ON + 6,
					"FT_SOLO_EPD_ICU_SERV_17_0010 step 0, Connection Test");


#endif

#ifdef FT_SOLO_EPD_ICU_SERV_9_0020

#define FT_SOLO_EPD_ICU_SERV_9_0020_TIME 200000

EmuGSS_TCProgram9_129 prog_FT_0020_step_0(UNITIME_AFTER_POWER_ON + 10 ,
		"FT_SOLO_EPD_ICU_SERV_9_0020 step 0, Update UniTime Test",
		FT_SOLO_EPD_ICU_SERV_9_0020_TIME);



#endif

#ifdef FT_SOLO_EPD_ICU_SERV_1_REJECTED_TC_0030


#define FT_SOLO_EPD_ICU_SERV_1_0030_TIME (FT_SOLO_EPD_ICU_SERV_9_0020_TIME + 2)

EmuGSS_TCProgram17_3 prog_FT_0030_step_0(FT_SOLO_EPD_ICU_SERV_1_0030_TIME,
		"FT_SOLO_EPD_ICU_SERV_1_0030 step 0, Rejected TC",0xFF);

#endif


#ifdef FT_SOLO_EPD_ICU_SERV_3_DISABLE_SID0_0040

#define FT_SOLO_EPD_ICU_SERV_3_0040_TIME (UNITIME_AFTER_POWER_ON + 30)

EmuGSS_TCProgram3_6 prog_FT_0040_step_0(FT_SOLO_EPD_ICU_SERV_3_0040_TIME,
		"FT_SOLO_EPD_ICU_SERV_3_0040 step 0, Disable SID 0 ",0);

#endif



#ifdef FT_SOLO_EPD_ICU_SERV_3_UPDATE_INTERVAL_TC_0050


#define FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step0 (UNITIME_AFTER_POWER_ON + 35)
#define FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step1 (FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step0 + 10)
#define FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step2 (FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step1 + 10)


EmuGSS_TCProgram3_31 prog_FT_0050_step_0(FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step0,
		"FT_SOLO_EPD_ICU_SERV_3_0050 step 0, Update SID 10 Rate to 5",10,5);

EmuGSS_TCProgram3_6 prog_FT_0050_step_1(FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step1,
		"FT_SOLO_EPD_ICU_SERV_3_0050 step 1, Disable SID 10 ",10);

EmuGSS_TCProgram3_5 prog_FT_0050_step_2(FT_SOLO_EPD_ICU_SERV_3_0050_TIME_step2,
		"FT_SOLO_EPD_ICU_SERV_3_0050 step 2, Enable SID 10 ",10);


#endif



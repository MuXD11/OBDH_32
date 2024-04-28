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

//TODO
//#define FT_SOLO_EPD_ICU_SERV_3_DISABLE_SID0_0040
//#define FT_SOLO_EPD_ICU_SERV_3_UPDATE_INTERVAL_TC_0050

//#define FT_SOLO_EPD_ICU_SERV_20_UPDATE_PARAM_VALUE_0060

//#define FT_SOLO_EPD_ICU_Monitoring_0070

//#define FT_SOLO_EPC_ICU_SERV_5_0080

#define FT_SOLO_EPC_ICU_SERV_5_0090

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

#ifdef FT_SOLO_EPD_ICU_SERV_20_UPDATE_PARAM_VALUE_0060


#define FT_SOLO_EPD_ICU_SERV_20_0060_TIME_step0 (UNITIME_AFTER_POWER_ON + 5)
#define FT_SOLO_EPD_ICU_SERV_20_0060_TIME_step1 (UNITIME_AFTER_POWER_ON + 8)


EmuGSS_TCProgram20_3 prog_FT_0060_step_0(FT_SOLO_EPD_ICU_SERV_20_0060_TIME_step0,
		"FT_SOLO_EPD_ICU_SERV_20_0060 step 0, Update PID 1 to 99",1,99);

EmuGSS_TCProgram20_1 prog_FT_0060_step_1(FT_SOLO_EPD_ICU_SERV_20_0060_TIME_step1,
		"FT_SOLO_EPD_ICU_SERV_20_0060 step 1, Get PID 1 Value",1);


#endif

#ifdef FT_SOLO_EPD_ICU_Monitoring_0070

#define FT_0070_TIME_step0 (UNITIME_AFTER_POWER_ON + 5)
#define FT_0070_TIME_step1 (UNITIME_AFTER_POWER_ON + 7)
#define FT_0070_TIME_step2 (UNITIME_AFTER_POWER_ON + 20)
#define FT_0070_TIME_step3 (UNITIME_AFTER_POWER_ON + 40)
#define FT_0070_TIME_step4 (UNITIME_AFTER_POWER_ON + 60)


//Configurar el monitor con ID 0:GENERAMOS UNA RID JODIDA DE COJONES (TIPO4) SI VIOLAMOS EL RANGO DEL LÍMITE
EmuGSS_TCProgram12_5 prog_FT_0070_step_0(FT_0070_TIME_step0,
		"FT_SOLO_EPD_ICU_Monitoring_0070 step 0, Config PMODID 0 for monitoring PID 1",
		0, 1, 5, 1, 0x4000, 10, 0x4001);

//Activar la monitorización
EmuGSS_TCProgram12_1 prog_FT_0070_step_1(FT_0070_TIME_step1,
		"FT_SOLO_EPD_ICU_Monitoring_0070 step 1, Enable Monitoring PMODID 0", 0);

//cambiar el valor del parámetro a un valor FUERA DEL RANGO (por encima)
EmuGSS_TCProgram20_3 prog_FT_0070_step_2(FT_0070_TIME_step2,
		"FT_SOLO_EPD_ICU_Monitoring_0070 step 2, Update PID 1 to 99", 1, 99);

//cambiar el valor del parámetro a un valor DENTRO DEL RANGO (generará evento?)
EmuGSS_TCProgram20_3 prog_FT_0070_step_3(FT_0070_TIME_step3,
		"FT_SOLO_EPD_ICU_Monitoring_0070 step 3, Update PID 1 to 5", 1, 5);

////cambiar el valor del parámetro a un valor FUERA DEL RANGO (por debajo)
EmuGSS_TCProgram20_3 prog_FT_0070_step_4(FT_0070_TIME_step4,
		"FT_SOLO_EPD_ICU_Monitoring_0070 step 4, Update PID 1 to 0", 1, 0);

#endif


//nuevo test. similar al anterior pero ahora desactivamos los eventos y observamos que no se produce la [5,4]

#ifdef FT_SOLO_EPC_ICU_SERV_5_0080

#define FT_0080_TIME_step0 (UNITIME_AFTER_POWER_ON + 1)
#define FT_0080_TIME_step1 (UNITIME_AFTER_POWER_ON + 2)
#define FT_0080_TIME_step2 (UNITIME_AFTER_POWER_ON + 5)
#define FT_0080_TIME_step3 (UNITIME_AFTER_POWER_ON + 7)
#define FT_0080_TIME_step4 (UNITIME_AFTER_POWER_ON + 20)
#define FT_0080_TIME_step5 (UNITIME_AFTER_POWER_ON + 40)
#define FT_0080_TIME_step6 (UNITIME_AFTER_POWER_ON + 60)



EmuGSS_TCProgram5_6 prog_FT_0080_step_0(FT_0080_TIME_step0,"FT_SOLO_EPC_ICU_SERV_5_0080 step 0, Disable event reports with RID=0x4000",0x4000);
EmuGSS_TCProgram5_6 prog_FT_0080_step_1(FT_0080_TIME_step1,"FT_SOLO_EPC_ICU_SERV_5_0080 step 1, Disable event reports with RID=0x4001",0x4001);

//Configurar el monitor con ID 0: MONITORIZAMOS EL RANGO DEL PARÁMETRO Y SI SE VIOLA SE PRODUCE UNA RID TIPO4
EmuGSS_TCProgram12_5 prog_FT_0080_step_2(FT_0080_TIME_step2,
		"FT_SOLO_EPD_ICU_Monitoring_0080 step 2, Config PMODID 0 for monitoring PID 1",
		0, 1, 5, 1, 0x4000, 10, 0x4001);

//Activar la monitorización
EmuGSS_TCProgram12_1 prog_FT_0080_step_3(FT_0080_TIME_step3,
		"FT_SOLO_EPD_ICU_Monitoring_0080 step 3, Enable Monitoring PMODID 0", 0);

//cambiar el valor del parámetro a un valor FUERA DEL RANGO (por encima)
EmuGSS_TCProgram20_3 prog_FT_0080_step_4(FT_0080_TIME_step4,
		"FT_SOLO_EPD_ICU_Monitoring_0080 step 4, Update PID 1 to 99", 1, 99);

//cambiar el valor del parámetro a un valor DENTRO DEL RANGO (generará evento?)
EmuGSS_TCProgram20_3 prog_FT_0080_step_5(FT_0080_TIME_step5,
		"FT_SOLO_EPD_ICU_Monitoring_0080 step 5, Update PID 1 to 5", 1, 5);

////cambiar el valor del parámetro a un valor FUERA DEL RANGO (por debajo)
EmuGSS_TCProgram20_3 prog_FT_0080_step_6(FT_0080_TIME_step6,
		"FT_SOLO_EPD_ICU_Monitoring_0080 step 6, Update PID 1 to 0", 1, 0);
#endif





#ifdef FT_SOLO_EPC_ICU_SERV_5_0090

#define FT_0080_TIME_step0 (UNITIME_AFTER_POWER_ON + 1)
#define FT_0080_TIME_step1 (UNITIME_AFTER_POWER_ON + 2)
#define FT_0080_TIME_step2 (UNITIME_AFTER_POWER_ON + 5)
#define FT_0080_TIME_step3 (UNITIME_AFTER_POWER_ON + 7)
#define FT_0080_TIME_step4 (UNITIME_AFTER_POWER_ON + 20)
#define FT_0080_TIME_step5 (UNITIME_AFTER_POWER_ON + 40)
#define FT_0080_TIME_step6 (UNITIME_AFTER_POWER_ON + 60)
#define FT_0080_TIME_step7 (UNITIME_AFTER_POWER_ON + 65)


/* //desactivar eventos 4001
EmuGSS_TCProgram5_6 prog_FT_0080_step_1(FT_0080_TIME_step1,"FT_SOLO_EPC_ICU_SERV_5_0080 step 1, Disable event reports with RID=0x4001",0x4001); */

//Configurar el monitor con ID 0: MONITORIZAMOS EL RANGO DEL PARÁMETRO Y SI SE VIOLA SE PRODUCE UNA RID TIPO4
EmuGSS_TCProgram12_5 prog_FT_0080_step_2(FT_0080_TIME_step2,
		"FT_SOLO_EPD_ICU_Monitoring_0080 step 2, Config PMODID 0 for monitoring PID 1",
		0, 1, 1, 1, 0x4000, 10, 0x4001);

//Activar el monitor con ID 0
EmuGSS_TCProgram12_1 prog_FT_0080_step_3(FT_0080_TIME_step3,
		"FT_SOLO_EPD_ICU_Monitoring_0080 step 3, Enable Monitoring PMODID 0", 0);

//cambiar el valor del parámetro a un valor FUERA DEL RANGO (por encima)
EmuGSS_TCProgram20_3 prog_FT_0080_step_4(FT_0080_TIME_step4,
		"FT_SOLO_EPD_ICU_Monitoring_0080 step 4, Update PID 1 to 99", 1, 99);

//activar de nuevo los eventos 4001
EmuGSS_TCProgram5_5 prog_FT_0080_step_5(FT_0080_TIME_step5,"FT_SOLO_EPC_ICU_SERV_5_0080 step 5, Enable event reports with RID=0x4001",0x4001);


//cambiar el valor del parámetro a un valor DENTRO DEL RANGO (generará evento?)
EmuGSS_TCProgram20_3 prog_FT_0080_step_6(FT_0080_TIME_step6,
		"FT_SOLO_EPD_ICU_Monitoring_0080 step 5, Update PID 1 to 5", 1, 5);


////cambiar de nuevo el valor del parámetro a un valor FUERA DEL RANGO (por debajo)
EmuGSS_TCProgram20_3 prog_FT_0080_step_7(FT_0080_TIME_step7,
		"FT_SOLO_EPD_ICU_Monitoring_0080 step 7, Update PID 1 to 0", 1, 0);


#endif


/*
 * icuaasw_pus_service3.h
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */


#ifndef PUBLIC__ICUASW_PUS_SERVICE3_H
#define PUBLIC__ICUASW_PUS_SERVICE3_H

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/cdtchandler.h"


struct HKConfig_t{
  bool  enabled;
  uint16_t SID;
  uint8_t interval;
  uint8_t intervalControl;
  uint8_t ParamNum;
  uint8_t ParamDef[16];
};

#define PUS_SERVICE3_MAX_NUM_OF_SIDS 8

class PUSService3{

	friend class PUSHK_FDIRTCExecutor;
	//Only in debug
	friend class GSSServ3TMHandler;



public:
  static void Init();

  static void ExecTC( CDTCHandler &tcHandler, CDTMList &tmList);

  static void DoHK(CDTMList &tmList);


private:

  static HKConfig_t HKConfig[PUS_SERVICE3_MAX_NUM_OF_SIDS];

  static bool GetSIDIndex(uint16_t SID, uint8_t &index);

  static void ExecEnableConfigTC(CDTCHandler &tcHandler, CDTMList &tmList,
                                 bool newEnableConfig);

  static void Exec3_5TC( CDTCHandler &tcHandler, CDTMList &tmList);
  static void Exec3_6TC( CDTCHandler &tcHandler, CDTMList &tmList);
  static void Exec3_31TC( CDTCHandler &tcHandler, CDTMList &tmList);

  static void BuildTM_3_25(CDTMList &tmList, HKConfig_t &hkConfig);

};

#endif


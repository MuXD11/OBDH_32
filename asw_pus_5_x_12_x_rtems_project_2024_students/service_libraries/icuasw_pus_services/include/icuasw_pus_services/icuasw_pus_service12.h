/*
 * icuasw_pus_service12.h
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */

#ifndef PUBLIC__ICUASW_PUS_SERVICE12_H
#define PUBLIC__ICUASW_PUS_SERVICE12_H

#define MAX_Number_PMON_IDs 16

enum CheckStatus_t{
  MonitorUnselected,MonitorUnchecked,MonitorAboveHighLimit,MonitorBelowLowLimit
  ,MonitorWithinLimits
};

struct ParamMonitoringConfig_t{
  CheckStatus_t  prevstatus;
  CheckStatus_t  status;
  uint32_t transition_Y2K;
  bool  enabled;
  uint8_t PID;
  uint8_t interval;
  uint8_t intervalControl;
};

struct ParamLimitCheckDefinition_t{
  uint16_t highLimitRID;
  uint64_t highLimit;
  uint16_t lowLimitRID;
  uint64_t lowLimit;

};

class PUSService12{

public:

  static ParamMonitoringConfig_t  PARAMMonitoringConfig[MAX_Number_PMON_IDs];
  static ParamLimitCheckDefinition_t PARAMLimitDefinition[MAX_Number_PMON_IDs];

  static void ExecTC( CDTCHandler &tcHandler, CDTMList &tmList);

  static void DoMonitoring(CDEventList & eventList);

protected:

  static void Exec12_5TC( CDTCHandler &tcHandler, CDTMList &tmList);
  static void Exec12_1TC( CDTCHandler &tcHandler, CDTMList &tmList);
  static void Exec12_2TC( CDTCHandler &tcHandler, CDTMList &tmList);
};

#endif

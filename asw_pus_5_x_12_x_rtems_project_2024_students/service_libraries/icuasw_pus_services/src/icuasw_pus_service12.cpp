/*
 * icuasw_pus_service12.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */

#include <public/icuasw_pus_services_iface_v1.h>
#include <stdio.h>

ParamMonitoringConfig_t PUSService12::PARAMMonitoringConfig[MAX_Number_PMON_IDs] =
		{

		{ MonitorUnselected, MonitorUnselected, 0, false, 0, 1, 0 }, {
				MonitorUnselected, MonitorUnselected, 0, false, 0, 1, 0 }, {
				MonitorUnselected, MonitorUnselected, 0, false, 0, 1, 0 }, {
				MonitorUnselected, MonitorUnselected, 0, false, 0, 1, 0 }, {
				MonitorUnselected, MonitorUnselected, 0, false, 0, 1, 0 }, {
				MonitorUnselected, MonitorUnselected, 0, false, 0, 1, 0 }, {
				MonitorUnselected, MonitorUnselected, 0, false, 0, 1, 0 }, {
				MonitorUnselected, MonitorUnselected, 0, false, 0, 1, 0 }

		};


/*struct ParamMonitoringConfig_t{
  CheckStatus_t  prevstatus;
  CheckStatus_t  status;
  uint32_t transition_Y2K;
  bool  enabled;
  uint8_t PID;
  uint8_t interval;
  uint8_t intervalControl;
};*/




ParamLimitCheckDefinition_t PUSService12::PARAMLimitDefinition[MAX_Number_PMON_IDs] =
		{

		{ 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0,
				0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }

		};

void PUSService12::ExecTC(CDTCHandler &tcHandler, CDTMList &tmList) {

	switch (tcHandler.GetSubType()) {

	case (1):
		Exec12_1TC(tcHandler, tmList);
		break;
	case (2):
		Exec12_2TC(tcHandler, tmList);
		break;
	case (5):
		Exec12_5TC(tcHandler, tmList);
		break;

	default:
		break;
		//List.Add(1,8);

	}
}

void PUSService12::Exec12_5TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	uint16_t PMONID;
	uint16_t PID;
	uint8_t interval;
	uint16_t lowlimit;
	uint16_t lowlimitRID;
	uint16_t highlimit;
	uint16_t highlimitRID;

	PMONID = tcHandler.GetNextUInt16();

	if (PMONID < MAX_Number_PMON_IDs) {		//SOLO IMPLEMENTAMOS MONITOREO POR INTERVALO?

		//SI NO ESTÁ LLENO
		if (PUSService12::PARAMMonitoringConfig[PMONID].status
				== MonitorUnselected) {

			PID = tcHandler.GetNextUInt16();

			if (PID < DATAPOOL_PARAMNumber) {

				interval = tcHandler.GetNextUInt8();
				lowlimit = tcHandler.GetNextUInt16();
				lowlimitRID = tcHandler.GetNextUInt16();
				highlimit = tcHandler.GetNextUInt16();
				highlimitRID = tcHandler.GetNextUInt16();

				PUSService12::PARAMMonitoringConfig[PMONID].PID = PID;
				PUSService12::PARAMMonitoringConfig[PMONID].interval = interval;
				PUSService12::PARAMMonitoringConfig[PMONID].intervalControl = 0;
				PUSService12::PARAMMonitoringConfig[PMONID].status=
						MonitorUnchecked;

				PUSService12::PARAMLimitDefinition[PMONID].lowLimit = lowlimit;

				PUSService12::PARAMLimitDefinition[PMONID].lowLimitRID =
						lowlimitRID;

				PUSService12::PARAMLimitDefinition[PMONID].highLimit =
						highlimit;

				PUSService12::PARAMLimitDefinition[PMONID].highLimitRID =
						highlimitRID;

				PUSService1::BuildTM_1_7(tcHandler, tmList);

			} else {

				PUSService1::BuildTM_1_8_TC_20_X_PIDNotValid(tcHandler, tmList,
						PID);

			}

		} else {
			PUSService1::BuildTM_1_8_TC_12_X_PMONIDDefined(tcHandler, tmList,
					PMONID);

		}

	} else {

		PUSService1::BuildTM_1_8_TC_12_X_PMONIDNotValid(tcHandler, tmList,
				PMONID);

	}

}

void PUSService12::Exec12_1TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	uint16_t PMONID;

	PMONID = tcHandler.GetNextUInt16();

	if (PMONID < MAX_Number_PMON_IDs) {
		if (PARAMMonitoringConfig[PMONID].status != MonitorUnselected) {
			PARAMMonitoringConfig[PMONID].enabled = true;
			PARAMMonitoringConfig[PMONID].intervalControl = 0;

			PUSService1::BuildTM_1_7(tcHandler, tmList);
		} else {

			PUSService1::BuildTM_1_8_TC_12_X_PMONIDUndefined(tcHandler, tmList,
					PMONID);

		}

	}
}

void PUSService12::Exec12_2TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	uint16_t PMONID;

	PMONID = tcHandler.GetNextUInt16();

	if (PMONID < MAX_Number_PMON_IDs) {
		if (PARAMMonitoringConfig[PMONID].status != MonitorUnselected) {
			PARAMMonitoringConfig[PMONID].enabled = false;

			PUSService1::BuildTM_1_7(tcHandler, tmList);
		} else {

			PUSService1::BuildTM_1_8_TC_12_X_PMONIDUndefined(tcHandler, tmList,
					PMONID);

		}

	}
}

void PUSService12::DoMonitoring(CDEventList &eventList) {

	printf("Do_Monitoring\n");

	for (int i = 0; i < MAX_Number_PMON_IDs; i++) {

		if (PARAMMonitoringConfig[i].enabled) {

			uint8_t PID = PARAMMonitoringConfig[i].PID;
			uint16_t PIDCurrentValue = SystemDataPool::sParamCurrentValue[PID];
			if (PARAMMonitoringConfig[i].intervalControl
					>= PARAMMonitoringConfig[i].interval) {
				PARAMMonitoringConfig[i].intervalControl = 0;
				//Monitor Limits

				if (PARAMMonitoringConfig[i].status != MonitorUnselected) {
					if ((PARAMMonitoringConfig[i].status
							!= MonitorAboveHighLimit)
							&& (PARAMMonitoringConfig[i].status
									!= MonitorBelowLowLimit)) {

						if (PARAMLimitDefinition[i].highLimit
								< PIDCurrentValue) {
							struct EventInfo_t evInfo;
							evInfo.mEvRID =
									PARAMLimitDefinition[i].highLimitRID;
							evInfo.mEvAuxDataSize = 0;
							eventList.AddEvent(&evInfo);
							PARAMMonitoringConfig[i].prevstatus =
									PARAMMonitoringConfig[i].status;
							PARAMMonitoringConfig[i].status =
									MonitorAboveHighLimit;

							PARAMMonitoringConfig[i].transition_Y2K =
									PUSService9::GetCurrentUniTimeY2K();
						} else if (PARAMLimitDefinition[i].lowLimit
								> PIDCurrentValue) {

							struct EventInfo_t evInfo;
							evInfo.mEvRID = PARAMLimitDefinition[i].lowLimitRID;
							evInfo.mEvAuxDataSize = 0;
							eventList.AddEvent(&evInfo);
							PARAMMonitoringConfig[i].prevstatus =
									PARAMMonitoringConfig[i].status;
							PARAMMonitoringConfig[i].status =
									MonitorBelowLowLimit;
							PARAMMonitoringConfig[i].transition_Y2K =
									PUSService9::GetCurrentUniTimeY2K();
						} else {
							if (PARAMMonitoringConfig[i].status
									== MonitorUnchecked) {
								PARAMMonitoringConfig[i].prevstatus =
										PARAMMonitoringConfig[i].status;
								PARAMMonitoringConfig[i].transition_Y2K =
										PUSService9::GetCurrentUniTimeY2K();
								PARAMMonitoringConfig[i].status =
										MonitorWithinLimits;
							}
						}

					} else {
						//printf("high limit %i", (int) PARAMLimitDefinition[i].highLimit);
						if ((PARAMLimitDefinition[i].highLimit > PIDCurrentValue)
								&& (PARAMLimitDefinition[i].lowLimit
										< PIDCurrentValue)) {
							//printf("Param Valid again\n");
							PARAMMonitoringConfig[i].prevstatus =
									PARAMMonitoringConfig[i].status;
							PARAMMonitoringConfig[i].status =
									MonitorWithinLimits;
							PARAMMonitoringConfig[i].transition_Y2K =
									PUSService9::GetCurrentUniTimeY2K();
						}
					}
				}
			} else {
				PARAMMonitoringConfig[i].intervalControl++;
			}
		}
	}


}


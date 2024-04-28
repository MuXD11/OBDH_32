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

	if (PMONID < MAX_Number_PMON_IDs) {

		if (PUSService12::PARAMMonitoringConfig[PMONID].status
				== MonitorUnselected) {  //comprobación de que no existe monitorización asociada al evento


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
				PUSService12::PARAMMonitoringConfig[PMONID].status =
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

/*por ciernew TC[12,6]: En vez de borrar la definición de los parámetros del monitor, lo fijamos como "unselected", de manera
//que el PMONID pasa a estar disponible y el contenido de los parámetros, si lo hubiera, se machacará luego*/

void PUSService12::Exec12_6TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	uint16_t PMONID;

	PMONID = tcHandler.GetNextUInt16();

	if (PMONID < MAX_Number_PMON_IDs) {  //PMON ID válido
		if (PARAMMonitoringConfig[PMONID].status != MonitorUnselected) {
			PARAMMonitoringConfig[PMONID].status = MonitorUnselected;

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

			//Get PID and PID Current Value
			uint8_t PID = PARAMMonitoringConfig[i].PID;
			uint16_t PIDCurrentValue = SystemDataPool::sParamCurrentValue[PID];

			//Check if monitoring is
			if (PARAMMonitoringConfig[i].intervalControl
					>= PARAMMonitoringConfig[i].interval) {

				//reset interval
				PARAMMonitoringConfig[i].intervalControl = 0;

				//Monitor must be selected
				if (PARAMMonitoringConfig[i].status != MonitorUnselected) {

					//Check Monitor Status
					if ((PARAMMonitoringConfig[i].status
							!= MonitorAboveHighLimit)
							&& (PARAMMonitoringConfig[i].status
									!= MonitorBelowLowLimit)) {

						//Check if it has crossed the High Limit
						if (PARAMLimitDefinition[i].highLimit
								< PIDCurrentValue) {

							//Trigger Event
							TriggerEvent(eventList,
									PARAMLimitDefinition[i].highLimitRID, PID,
									PIDCurrentValue,
									PARAMLimitDefinition[i].highLimit);

							//Update Status
							UpdateStatus(i, MonitorAboveHighLimit);

							//Check if it has crossed the Low Limit
						} else if (PARAMLimitDefinition[i].lowLimit
								> PIDCurrentValue) {

							//Trigger Event
							TriggerEvent(eventList,
									PARAMLimitDefinition[i].lowLimitRID, PID,
									PIDCurrentValue,
									PARAMLimitDefinition[i].lowLimit);

							//Update Status
							UpdateStatus(i, MonitorBelowLowLimit);

						} else {
							//If it was unchecked, update status
							if (PARAMMonitoringConfig[i].status
									== MonitorUnchecked) {

								//Update Status
								UpdateStatus(i, MonitorWithinLimits);

							}
						}

					} else {

						//Check if it is again within the limits

						if ((PARAMLimitDefinition[i].highLimit > PIDCurrentValue)
								&& (PARAMLimitDefinition[i].lowLimit
										< PIDCurrentValue)) {

							//Update Status
							UpdateStatus(i, MonitorWithinLimits);

						}
					}
				}
			} else {
				PARAMMonitoringConfig[i].intervalControl++;
			}
		}
	}

}

void PUSService12::TriggerEvent(CDEventList &eventList, uint16_t RID,
		uint16_t PID, uint16_t PIDValue, uint16_t limit) {

	struct EventInfo_t evInfo;
	evInfo.mEvRID = RID;
	serialize_uint16(PID, &evInfo.mEvAuxData[0]);
	serialize_uint16(PIDValue, &evInfo.mEvAuxData[2]);
	serialize_uint16(limit, &evInfo.mEvAuxData[4]);
	evInfo.mEvAuxDataSize = 6;
	eventList.AddEvent(&evInfo);

}

void PUSService12::UpdateStatus(uint16_t PMONID, enum CheckStatus_t newStatus) {

	//Check PMONID is valid
	if (PMONID < MAX_Number_PMON_IDs) {
		//Save current status
		PARAMMonitoringConfig[PMONID].prevstatus =
				PARAMMonitoringConfig[PMONID].status;

		//Set new status
		PARAMMonitoringConfig[PMONID].status = newStatus;

		//Set Timestamp
		PARAMMonitoringConfig[PMONID].transition_Y2K =
				PUSService9::GetCurrentUniTimeY2K();

	}
}


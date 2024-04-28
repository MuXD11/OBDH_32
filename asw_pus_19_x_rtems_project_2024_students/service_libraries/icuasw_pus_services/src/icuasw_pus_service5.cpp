/*
 * icuaasw_pus_service5.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */

#include <public/icuasw_pus_services_iface_v1.h>

//Enable Config, the events defined are enabled by default
uint32_t PUSService5::RIDEnableConfig[4] = { 0x00000007, 0x0000000F, 0x00000000,
		0x0000FFFF };

uint8_t PUSService5::GetRIDEnableConfigIndex(uint16_t RID) {

	enum TRIDType RIDType = GetRIDType(RID);

	uint8_t index = 4; //Not valid index.

	switch (RIDType) {
	case (RIDTypeInformative):
		index = 0;
		break;
	case (RIDTypeLowSevAnomaly):
		index = 1;
		break;
	case (RIDTypeMediumSevAnomaly):
		index = 2;
		break;
	case (RIDTypeHighSevAnomaly):
		index = 3;
		break;
	default:
		index = 4;
	}

	return index;
}

uint8_t PUSService5::GetRIDEnableConfigOffset(uint16_t RID) {

	//Maximum RIDs of each type in the baseline configuration is 32,
	//from 0xX000 to 0xX01F, where X is the RID type
	uint8_t offset = RID & 0x1F;

	return offset;
}

bool PUSService5::IsIndexValid(uint8_t index) {

	//With the actual configuration, index < 4 is valid
	return (index < 4);

}

enum TRIDType PUSService5::GetRIDType(uint16_t RID) {

	enum TRIDType RIDType = RIDNotValid;
	int auxType = RID >> 12;
	int auxID = RID & 0xFFF;

	switch (auxType) {
	case (1):
		if (auxID < PUS_5_InformativeRIDs) {
			RIDType = RIDTypeInformative;
		}
		break;
	case (2):
		if (auxID < PUS_5_LowSeverityAnomalyRIDs) {
			RIDType = RIDTypeLowSevAnomaly;
		}
		break;
	case (3):
		if (auxID < PUS_5_MediumSeverityAnomalyRIDs) {
			RIDType = RIDTypeMediumSevAnomaly;
		}
		break;
	case (4):
		if (auxID < PUS_5_HighSeverityAnomalyRIDs) {
			RIDType = RIDTypeHighSevAnomaly;
		}

		break;

	default:
		RIDType = RIDNotValid;
	}

	return RIDType;
}

bool PUSService5::IsRIDEnabled(uint16_t RID) {

	bool enabled = false;
	uint8_t index;
	uint8_t offset;

	index = GetRIDEnableConfigIndex(RID);

	offset = GetRIDEnableConfigOffset(RID);

	if (IsIndexValid(index)) {

		if ((RIDEnableConfig[index] >> offset) & 0x01)
			enabled = true;

	}

	return enabled;
}

void PUSService5::BuildEventListTMs(CDEventList &eventList, CDTMList &tmList) {

	//RIDEnableConfig_t

	uint8_t numberOfEvents = eventList.GetNumberOfEvents();
	for (uint8_t i = 0; i < numberOfEvents; i++) {

		const struct EventInfo_t *pEventInfo = eventList.GetEventInfo(i);

		if (IsRIDEnabled(pEventInfo->mEvRID)) {

			uint8_t index = GetRIDEnableConfigIndex(pEventInfo->mEvRID);

			if (index < 4) {

				CDTMHandler tm_handler(5, index + 1);
				tm_handler.SetUInt16AppDataField(pEventInfo->mEvRID);
				for (int i = 0; i < pEventInfo->mEvAuxDataSize; i++) {
					tm_handler.SetUInt8AppDataField(pEventInfo->mEvAuxData[i]);
				}
				tmList.AddTM(tm_handler.CloseTM());
			}

		}
	}

}

//TO_DO
void PUSService5::Exec5_5TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	uint8_t index;
	uint8_t offset;
	uint16_t RID;

	RID = tcHandler.GetNextUInt16();
	index = GetRIDEnableConfigIndex(RID);
	offset = GetRIDEnableConfigOffset(RID);

	if (IsIndexValid(index)) {

		RIDEnableConfig[index] |= (0x01 << offset);

		PUSService1::BuildTM_1_7(tcHandler, tmList);

	} else {

		PUSService1::BuildTM_1_8_TC_5_X_RIDUnknown(tcHandler, tmList, RID);
	}
}

//TO_DO
void PUSService5::Exec5_6TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	uint8_t index;
	uint8_t offset;
	uint16_t RID;

	RID = tcHandler.GetNextUInt16();

	index = GetRIDEnableConfigIndex(RID);
	offset = GetRIDEnableConfigOffset(RID);

	if (IsIndexValid(index)) {

		RIDEnableConfig[index] &= ~(0x01 << offset);

		PUSService1::BuildTM_1_7(tcHandler, tmList);

	} else {

		PUSService1::BuildTM_1_8_TC_5_X_RIDUnknown(tcHandler, tmList, RID);
	}
}

void PUSService5::ExecTC(CDTCHandler &tcHandler, CDTMList &tmList) {

	switch (tcHandler.GetSubType()) {

	case (5):

		Exec5_5TC(tcHandler, tmList);
		break;
	case (6):

		Exec5_6TC(tcHandler, tmList);
		break;
	default:
		//This must be not possible
		break;
	}
}


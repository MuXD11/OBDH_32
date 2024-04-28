/*
 * icuasw_pus_service16.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */

#include <public/icuasw_pus_services_iface_v1.h>
#include <stdio.h>
#include <public/ccepdmanager_iface_v1.h>

EventActionConfig_t PUSService19::EventActionConfig[MAX_EVENT_ACTION_DEFINITIONS] =
		{

		{ false, 0 }, { false, 0 }, { false, 0 }, { false, 0 },
		{ false, 0 }, { false, 0 }, { false, 0 }, { false, 0 },
		{ false, 0 }, { false, 0 }, { false, 0 }, { false, 0 },
		{ false, 0 }, { false, 0 }, { false, 0 }, { false, 0 }

		};

EventActionPacket_t PUSService19::EventActionPacks[MAX_EVENT_ACTION_DEFINITIONS];

CDEvAction PUSService19::PendingActionQueue[4][EVENT_ACTION_QUEUE_DIMENSION];
uint8_t PUSService19::PendingActionNumber[4] = { 0, 0, 0, 0 };
uint8_t PUSService19::PendingActionHead[4] = { 0, 0, 0, 0 };

Pr_Mutex PUSService19::PendActQueueMutex;

bool PUSService19::GetEvActionConfig(uint16_t EvID, uint8_t &index,
		bool &enabled) {
	bool found = false;
	for (int j = 0; ((j < MAX_EVENT_ACTION_DEFINITIONS) && !found); j++) {
		if (EvID == EventActionConfig[j].EvID) {
			index = j;
			enabled = EventActionConfig[j].enabled;
			found = true;
		}
	}
	return found;
}

bool PUSService19::GetFreeEvActionIndex(uint8_t &index) {
	bool found = false;
	for (int j = 0; ((j < MAX_EVENT_ACTION_DEFINITIONS) && !found); j++) {
		if (0 == EventActionConfig[j].EvID) {
			index = j;
			found = true;
		}
	}
	return found;
}

void PUSService19::Exec19_1TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	uint8_t index;
	bool found = false;
	bool enabled = false;

	enum TRIDType evType;
	uint16_t EvID;

	EvID = tcHandler.GetNextUInt16();

	evType = PUSService5::GetRIDType(EvID);

	if (RIDNotValid == evType) {

		PUSService1::BuildTM_1_8_TC_5_X_RIDUnknown(tcHandler, tmList, EvID);

	} else {

		if (GetEvActionConfig(EvID, index, enabled)) {
			found = true;
		} else if (GetFreeEvActionIndex(index)) {
			found = true;
			enabled = false;
		}
		//Not found means MAX of defined Event Actions has been reached
		if (!found) {

			PUSService1::BuildTM_1_8_TC_19_1_MaxEvActions(tcHandler, tmList,
					EvID);

		} else {

			if (enabled) { //Error, event action cannot be redefined if is enabled

				PUSService1::BuildTM_1_8_TC_19_X_EvActionEnabled(tcHandler,
						tmList, EvID);

			} else {

				uint8_t actionPackLength;
				//Check if packet can be accepted
				//Use reference to mTCHandler
				CDTCHandler &actionHandler = EventActionPacks[index].mTCHandler;

				actionHandler.mTCDescriptor.p_tc_bytes =
						EventActionPacks[index].mActionPacketBytes;

				//Complete action bytes
				actionPackLength=tcHandler.GetPackLength()-7;

				for (uint8_t i = 0; i < actionPackLength; i++) {
					actionHandler.mTCDescriptor.p_tc_bytes[i] =
							tcHandler.GetNextUInt8();
				}
				actionHandler.mTCDescriptor.tc_num_bytes =actionPackLength;


				//Try TC acceptation
				PUSService1::TryTCAcceptation(actionHandler);

				if (!actionHandler.IsAccepted()) {

					PUSService1::BuildTM_1_8_TC_19_1_EvActionRejected(tcHandler,
							tmList, EvID);

				} else {

					EventActionConfig[index].EvID = EvID;
					EventActionConfig[index].enabled = false;

					PUSService1::BuildTM_1_7(tcHandler, tmList);
				}

			}

		}

	}

}

void PUSService19::Exec19_2TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	uint8_t index;

	bool enabled = false;

	enum TRIDType evType;
	uint16_t EvID;

	EvID = tcHandler.GetNextUInt16();

	evType = PUSService5::GetRIDType(EvID);

	if (RIDNotValid == evType) {

		PUSService1::BuildTM_1_8_TC_5_X_RIDUnknown(tcHandler, tmList, EvID);

	} else {

		if (GetEvActionConfig(EvID, index, enabled)) {

			if (enabled) {
				PUSService1::BuildTM_1_8_TC_19_X_EvActionEnabled(tcHandler,
						tmList, EvID);
			} else {

				//Event ID must be 0
				EventActionConfig[index].EvID = 0;
				EventActionConfig[index].enabled = false;
				PUSService1::BuildTM_1_7(tcHandler, tmList);

			}

		} else {

			PUSService1::BuildTM_1_8_TC_19_X_EvActionNotDefined(tcHandler,
					tmList, EvID);
		}
	}

}

void PUSService19::Exec19_4TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	uint8_t index;

	bool enabled = false;

	enum TRIDType evType;
	uint16_t EvID;

	EvID = tcHandler.GetNextUInt16();

	evType = PUSService5::GetRIDType(EvID);

	if (RIDNotValid == evType) {

		PUSService1::BuildTM_1_8_TC_5_X_RIDUnknown(tcHandler, tmList, EvID);

	} else {

		if (GetEvActionConfig(EvID, index, enabled)) {

			EventActionConfig[index].enabled = true;
			PUSService1::BuildTM_1_7(tcHandler, tmList);

		} else {

			PUSService1::BuildTM_1_8_TC_19_X_EvActionNotDefined(tcHandler,
					tmList, EvID);
		}
	}

}

void PUSService19::Exec19_5TC(CDTCHandler &tcHandler, CDTMList &tmList) {

	uint8_t index;

	bool enabled = false;

	enum TRIDType evType;
	uint16_t EvID;

	EvID = tcHandler.GetNextUInt16();

	evType = PUSService5::GetRIDType(EvID);

	if (RIDNotValid == evType) {

		PUSService1::BuildTM_1_8_TC_5_X_RIDUnknown(tcHandler, tmList, EvID);

	} else {

		if (GetEvActionConfig(EvID, index, enabled)) {

			EventActionConfig[index].enabled = false;
			PUSService1::BuildTM_1_7(tcHandler, tmList);

		} else {

			PUSService1::BuildTM_1_8_TC_19_X_EvActionNotDefined(tcHandler,
					tmList, EvID);
		}
	}
}

void PUSService19::ExecTC(CDTCHandler &tcHandler, CDTMList &tmList) {

	switch (tcHandler.GetSubType()) {

	case (1):
		Exec19_1TC(tcHandler, tmList);
		break;
	case (2):
		Exec19_2TC(tcHandler, tmList);
		break;
	case (4):
		Exec19_4TC(tcHandler, tmList);
		break;
	case (5):
		Exec19_5TC(tcHandler, tmList);
		break;

	default:
		break;

	}
}

void PUSService19::ManageEventActions(CDEventList &eventList) {

	uint8_t numberOfEvents = eventList.GetNumberOfEvents();
	for (uint8_t i = 0; i < numberOfEvents; i++) {

		const struct EventInfo_t *pEventInfo = eventList.GetEventInfo(i);

		if (PUSService5::IsRIDEnabled(pEventInfo->mEvRID)) {

			uint8_t index;

			bool enabled = false;

			if (GetEvActionConfig(pEventInfo->mEvRID, index, enabled)) {
				if (enabled) {

					NewPendingEvAction(pEventInfo->mEvRID, index);


				}
			}
		}
	}
	//Clear event list

	eventList.ClearEventList();
}

bool PUSService19::InsertEvAction(uint16_t evID, uint8_t packIndex,
		uint8_t *pActionBytes, uint16_t num_of_bytes) {

	enum TRIDType evType;
	evType = PUSService5::GetRIDType(evID);
	int index = 0;
	uint8_t tailIndex;

	bool inserted=false;

	switch (evType) {

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
		break;

	}

	//Critical section entry
	PendActQueueMutex.Wait();

	if(PendingActionNumber[index]<MAX_EVENT_ACTION_DEFINITIONS){
		//Get tail Index
		tailIndex = (PendingActionHead[index] + PendingActionNumber[index])
			% MAX_EVENT_ACTION_DEFINITIONS;

		PendingActionNumber[index]++; //Update tail

		PendingActionQueue[index][tailIndex].mTCHandler.mTCDescriptor.p_tc_bytes =
			pActionBytes;
		PendingActionQueue[index][tailIndex].mTCHandler.mTCDescriptor.tc_num_bytes =
				num_of_bytes;

		inserted=true;
	}
	PendActQueueMutex.Signal();
	//Critical section exit

	return inserted;
}

bool PUSService19::NewPendingEvAction(uint16_t evID, uint8_t packIndex) {

	uint8_t *p_tc_bytes = tmtc_pool_alloc();
	uint16_t num_of_bytes;
	num_of_bytes=EventActionPacks[packIndex].mTCHandler.mTCDescriptor.tc_num_bytes;
	for (int i = 0; i < num_of_bytes; i++) {
		p_tc_bytes[i] = EventActionPacks[packIndex].mActionPacketBytes[i];
	}

	return InsertEvAction(evID, packIndex, p_tc_bytes,num_of_bytes);

}


bool PUSService19::IsEvActionQueueEmpty() {

	uint8_t totalPendingAction = 0;
	PendActQueueMutex.Wait();
	for (int i = 0; i < 4; i++)
		totalPendingAction += PendingActionNumber[i];
	PendActQueueMutex.Signal();
	return (0 == totalPendingAction);
}

bool PUSService19::ExtractEvActionFromQueue(CDEvAction &EvAction) {

	bool found=false;
	int i=4;

	do{
		i--;
		//Critical section entry
		PendActQueueMutex.Wait();
		if(PendingActionNumber[i]){
			int index=PendingActionHead[i];
			PendingActionHead[i]=(PendingActionHead[i]+1)%MAX_EVENT_ACTION_DEFINITIONS;
			PendingActionNumber[i]--;
			EvAction.SetActionTCPacket(EventActionPacks[index].mTCHandler);
			found=true;
		}
		PendActQueueMutex.Signal();
	}while(!found && i != 0);

	return found;

}

void PUSService19::GetEvActionTCHandler(CDEvAction &evAction,
		CDTCHandler &tcHandler) {

	tcHandler=evAction.mTCHandler;
}

void PUSService19::TriggerEvActionExecution() {

	CCEPDManager::EDROOMEventIRQ10.SignalFromTask();
}



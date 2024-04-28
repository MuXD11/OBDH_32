/*
 * icuasw_pus_service19.h
 *
 *  Created on: Dec 22, 2023
 *      Author: user
 */

#ifndef PUBLIC__ICUASW_PUS_SERVICE19_H
#define PUBLIC__ICUASW_PUS_SERVICE19_H

#include "public/basic_types.h"

#include "public/icuasw_pus_services_iface_v1.h"
#include "public/cdevaction.h"
#include "public/cdtchandler.h"
#include "public/cdtmlist.h"
#include "public/edroombp.h"
#include "public/edroombp.h"

#define MAX_EVENT_ACTION_DEFINITIONS 16
#define EVENT_ACTION_QUEUE_DIMENSION 8
#define EVENT_ACTION_MAX_BYTES  	(EPD_PUS_TC_MAX_NUM_OF_BYTES-14)

struct EventActionConfig_t {
	bool_t enabled;
	uint16_t EvID; //EvID 0 means not used
};

struct EventActionPacket_t {
	uint8_t mActionPacketBytes[EVENT_ACTION_MAX_BYTES];
	CDTCHandler mTCHandler;
};

class PUSService19 {

	friend class PUSService5;

	//Event Action Configuration
	static EventActionConfig_t EventActionConfig[MAX_EVENT_ACTION_DEFINITIONS];

	//Event Action Definitions
	static EventActionPacket_t EventActionPacks[MAX_EVENT_ACTION_DEFINITIONS];

	//Pending Event Action Q
	static CDEvAction PendingActionQueue[4][EVENT_ACTION_QUEUE_DIMENSION];
	static uint8_t PendingActionNumber[4];
	static uint8_t PendingActionHead[4];
	static Pr_Mutex PendActQueueMutex;

	/* \brief get the index of the EvID in the EvIDEnableConfig structure
	 * \param EvID Event Identifier
	 * \param i   updated with the index of the configured Event Action
	 * \param enabled updated to true if the Event Action Definition is enabled,
	 * 		updated false if not
	 * \returns true if an action for this EvID is configured, false if not
	 */
	static bool GetEvActionConfig(uint16_t EvID, uint8_t &i, bool &enabled);

	/* \brief get a free index
	 * \param i   updated with the index of the free Event Action
	 * \returns true if a free index has been found, false if not
	 */
	static bool GetFreeEvActionIndex(uint8_t &i);

	static void Exec19_1TC(CDTCHandler &tcHandler, CDTMList &tmList);
	static void Exec19_2TC(CDTCHandler &tcHandler, CDTMList &tmList);
	static void Exec19_4TC(CDTCHandler &tcHandler, CDTMList &tmList);
	static void Exec19_5TC(CDTCHandler &tcHandler, CDTMList &tmList);


	/* \brief Insert Event Action in the Pending Actions Queue
	* return true if EvAction has been inserted
	*/
	static bool InsertEvAction(uint16_t evID, uint8_t packIndex
										, uint8_t *pActionBytes
										,uint16_t num_of_bytes);

	/* \brief New Event Action in the Pending Actions Queue
	* return true if EvAction has been added
	*/
	static bool NewPendingEvAction(uint16_t evID, uint8_t packIndex);

public:

	/* \brief Exec telecommands
	*/
	static void ExecTC(CDTCHandler &tcHandler, CDTMList &tmList);

	/* \brief Manage Event Actions
	*/
	static void ManageEventActions(CDEventList &eventList);

	/* \brief Check if EvAction Queue is empty
	 * \return true if EvAction Queue is empty
	*/
	static bool IsEvActionQueueEmpty();

	/* \brief Extract EvAction From Queue
	 * \return true if EvAction is extracted
	*/
	static bool ExtractEvActionFromQueue(CDEvAction &EvAction);

	/* \brief Get the TC descriptor from the EvAction
	*/
	static void GetEvActionTCHandler(CDEvAction &EvAction,
			CDTCHandler &tcHandler);

	/* \brief Trigger EvAction Execution
	*/
	static void TriggerEvActionExecution();
};

#endif


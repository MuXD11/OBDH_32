#ifndef FCDEventListH
#define FCDEventListH

#include "public/basic_types.h"

#define EVENT_LIST_MAX_NUM_OF_ELEMENTS 16
#define EVENT_AUX_DATA_MAX_SIZE 64

struct EventInfo_t {

	uint16_t mEvRID;
	uint8_t mEvAuxData[EVENT_AUX_DATA_MAX_SIZE];
	uint8_t mEvAuxDataSize;

};

class CDEventList {

public:

	EventInfo_t mEventsInfo[EVENT_LIST_MAX_NUM_OF_ELEMENTS];
	uint8_t mHead;
	uint8_t mEvCounter;

	void AddEvent(const struct EventInfo_t *pEvInfo) {

		if (mEvCounter < EVENT_LIST_MAX_NUM_OF_ELEMENTS) {
			mEventsInfo[mEvCounter].mEvRID = pEvInfo->mEvRID;

			//Limit auxiliary data size
			if (pEvInfo->mEvAuxDataSize > EVENT_AUX_DATA_MAX_SIZE)
				mEventsInfo[mEvCounter].mEvAuxDataSize = EVENT_AUX_DATA_MAX_SIZE;
			else
				mEventsInfo[mEvCounter].mEvAuxDataSize = pEvInfo->mEvAuxDataSize;

			//copy event auxiliary data
			for (int i = 0; i < pEvInfo->mEvAuxDataSize; i++)
				mEventsInfo[mEvCounter].mEvAuxData[i] = pEvInfo->mEvAuxData[i];

			mEvCounter++;
		}
	}

	uint8_t ExtractFirstEvent(struct EventInfo_t *pEvInfo) {

		uint8_t error = 0;
		if (mEvCounter) {
			*pEvInfo = mEventsInfo[0];

			for (int i = 0; i < mEvCounter; i++)
				mEventsInfo[i] = mEventsInfo[i + 1];

			mEvCounter--;
		} else
			error = 1;

		return error;
	}

	const struct EventInfo_t * GetEventInfo(uint8_t index) {

		struct EventInfo_t * pEvInfo=NULL;
			if (index< mEvCounter) {
				pEvInfo = &mEventsInfo[index];
			}

			return pEvInfo;
	}

	void ClearEventList() {
		mHead=0;
		mEvCounter=0;

	}

	uint8_t GetNumberOfEvents() {
		return mEvCounter;
	}

	/*
	uint16_t GetEventRID(uint8_t index) {
		uint16_t RID = 0;
		if (index < EVENT_LIST_MAX_NUM_OF_ELEMENTS)
			RID = mRID[index];
		return RID;
	}*/

	CDEventList() {

		ClearEventList();
	}

protected:

private:

};
#endif

#ifndef FCDTMListH
#define FCDTMListH

#include "public/config.h"
#include "public/basic_types.h"
#include "public/tmtc_dyn_mem.h"

#define TM_LIST_MAX_LENGTH 16


class CDTMList{

	friend class PUSService1;
	friend class PUSService17;

	protected:

	//Number of telemetries
	uint8_t mTMNumber;

	//telemetries descriptors
	tm_descriptor_t mTMDescriptors[TM_LIST_MAX_LENGTH];

	//Add a Telemetry to the list
	uint8_t AddTM(tm_descriptor_t descriptor);

	public:

	CDTMList();

	// assignment operator
	CDTMList& operator = (const CDTMList &tmlist);

	//Inline Method Get
	uint8_t GetTMNumber(){return mTMNumber;}
	
	tm_descriptor_t GetTM(uint8_t i){return mTMDescriptors[i];}

	const tm_descriptor_t * GetpTM(uint8_t i){return (mTMDescriptors + i);}
	
	void Clear(){mTMNumber=0;}
	
	private:
	
};
#endif

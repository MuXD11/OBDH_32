/*
 * cdtmlist.cpp
 *
 *  Created on: Jan 3, 2024
 *      Author: opolo70
 */

#include "public/cdtmlist.h"


uint8_t CDTMList::AddTM(tm_descriptor_t descriptor){

	uint8_t error=1;

	if(mTMNumber<TM_LIST_MAX_LENGTH){

		mTMDescriptors[mTMNumber]=descriptor;

		mTMNumber++;

		error=0;
	}

	return error;
}

CDTMList::CDTMList(){

	mTMNumber=0;

}

CDTMList& CDTMList::operator = (const CDTMList &tmlist){

	mTMNumber=tmlist.mTMNumber;

	for(int i =0; i < mTMNumber; i++){
		mTMDescriptors[i]= tmlist.mTMDescriptors[i];

	}

	return *this;
}

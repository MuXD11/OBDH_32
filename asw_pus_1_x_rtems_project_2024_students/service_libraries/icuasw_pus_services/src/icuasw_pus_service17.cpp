/*
 * icuasw_pus_Service17.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */

#include <public/icuasw_pus_services_iface_v1.h>

void PUSService17::ExecTC(CDTCHandler &tcHandler, CDTMList &tmList) {

	switch (tcHandler.GetSubType()) {
	case (1):

		BuildTM_17_2(tmList);

		PUSService1::BuildTM_1_7(tcHandler, tmList);
		break;
	default:
		break;
	}


}

void PUSService17::BuildTM_17_2(CDTMList &tmList) {

	CDTMHandler tm_handler(17, 2);

	tmList.AddTM(tm_handler.CloseTM());

}

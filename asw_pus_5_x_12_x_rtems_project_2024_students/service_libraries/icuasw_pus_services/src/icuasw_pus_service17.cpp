/*
 * icuasw_pus_Service17.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */

#include <public/icuasw_pus_services_iface_v1.h>

void PUSService17::ExecTC(CDTCHandler &tc_handler, CDTMList &tm_list) {

	switch (tc_handler.GetSubType()) {
	case (1):

		BuildTM_17_2(tm_list);

		PUSService1::BuildTM_1_7(tc_handler, tm_list);
		break;
	default:
		break;
	}


}

void PUSService17::BuildTM_17_2(CDTMList &tm_list) {

	CDTMHandler tm_handler(17, 2);

	tm_list.AddTM(tm_handler.CloseTM());

}

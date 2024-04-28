/*
 * icuasw_pus_Service17.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */

#include <public/icuasw_pus_services_iface_v1.h>

#define DEVICE_MAX_ID 5
void PUSService2::ExecTC(CDTCHandler &tc_handler, CDTMList &tm_list) {

	switch (tc_handler.GetSubType()) {
	case (1):

		Exec2_1TC(tc_handler, tm_list);

		break;
	default:
		break;
	}

}

void PUSService2::Exec2_1TC(CDTCHandler &tcHandler, CDTMList &tmList) {
	uint16_t on_off_command;

	on_off_command = tcHandler.GetNextUInt16();

	uint8_t on_off = on_off_command >> 8;
	uint8_t device_id = on_off_command & 0xFF;

	if (device_id > DEVICE_MAX_ID) {

		PUSService1::BuildTM_1_8_TC_2_X_DeviceNotValid(tcHandler, tmList,
				device_id);

	} else {

		if (on_off) {

			printf("\tDevice %d Switch On\n", device_id);

		} else {

			printf("\tDevice %d Switch Off\n", device_id);

		}
		PUSService1::BuildTM_1_7(tcHandler, tmList);
	}
}

/*
 * emu_sc_pus_service5.h
 *
 *  Created on: Jan 16, 2024
 *      Author: user
 */

#ifndef EMU_SC_PUS_SERVICE2_H_
#define EMU_SC_PUS_SERVICE2_H_

enum DeviceCommandOnOff_t { DeviceCommandOff=0, DeviceCommandOn=1};

class EmuGSS_TCProgram2_1: public EmuGSS_TCProgram {

	friend class EmuGSS_TCProgram19_1_Action_2_1;
	uint16_t mDeviceOnOffCommand;

	virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

public:

	EmuGSS_TCProgram2_1(uint32_t uniTime2YK, char *brief, uint8_t deviceID,
			enum DeviceCommandOnOff_t devicecommand);

	//Constructor for 19_1 event action program
	EmuGSS_TCProgram2_1(uint8_t deviceID,
				enum DeviceCommandOnOff_t devicecommand);

};



#endif /* EMU_SC_PUS_SERVICE9_H_ */

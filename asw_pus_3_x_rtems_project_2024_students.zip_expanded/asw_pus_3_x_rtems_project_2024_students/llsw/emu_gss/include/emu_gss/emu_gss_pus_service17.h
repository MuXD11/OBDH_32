/*
 * emu_sc_pus_service17.h
 *
 *  Created on: Nov 12, 2018
 *      Author: user
 */

#ifndef EMU_SC_PUS_SERVICE17_H_
#define EMU_SC_PUS_SERVICE17_H_

class EmuGSS_TCProgram17_1:public EmuGSS_TCProgram{

  void BuildTCAppData(tc_descriptor_t &tc_descriptor);


public:

  EmuGSS_TCProgram17_1(uint32_t uniTime2YK,
                 char * brief);


};


class EmuGSS_TCProgram17_3:public EmuGSS_TCProgram{

  virtual void BuildTCAppData(tc_descriptor_t &tc_descriptor);

  uint16_t mAPID;

public:

  EmuGSS_TCProgram17_3(uint32_t uniTime2YK,char * brief,uint16_t APID);

};


#endif /* EMU_SC_PUS_SERVICE17_H_ */

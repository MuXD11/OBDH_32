/*
 * icuasw_pus_private_services.cpp
 *
 *  Created on: Dec 22, 2016
 *      Author: user
 */


#include <public/icuasw_pus_services_iface_v1.h>


void  PUSService20::ExecTC( CDTCHandler &tcHandler, CDTMList &List){

  switch(tcHandler.GetSubType()){
                case(1):
					Exec20_1TC(tcHandler, List);
                	break;
                case(3):
                	Exec20_3TC(tcHandler, List);
                    break;
                  break;
                default:
                	; //This is an error in acceptance, can be modeled with an event..
  }

}

void PUSService20::Exec20_3TC( CDTCHandler &tcHandler, CDTMList &tmList){

  uint16_t PID=tcHandler.GetNextUInt16();

  uint16_t paramValue=tcHandler.GetNextUInt16();

  if(PID < DATAPOOL_PARAMNumber){
	  SystemDataPool::sParamCurrentValue[PID]=paramValue;

	  PUSService1::BuildTM_1_7(tcHandler, tmList);
  }else
	  PUSService1::BuildTM_1_8_TC_20_X_PIDNotValid(tcHandler, tmList,PID);


}
void PUSService20::Exec20_1TC( CDTCHandler &tcHandler, CDTMList &tmList){

  uint16_t PID=tcHandler.GetNextUInt16();



  if(PID< DATAPOOL_PARAMNumber){
	  CDTMHandler tm_handler(20,2);

	  uint16_t paramValue=SystemDataPool::sParamCurrentValue[PID];
	  tm_handler.SetUInt16AppDataField(PID);
	  tm_handler.SetUInt16AppDataField(paramValue);

	  tmList.AddTM(tm_handler.CloseTM());
      PUSService1::BuildTM_1_7(tcHandler, tmList);


  }else
	  PUSService1::BuildTM_1_8_TC_20_X_PIDNotValid(tcHandler, tmList,PID);


}


/*
 * icuaasw_pus_service5.cpp
 *
 *  Created on: Dec 22, 2023
 *      Author: user
 */



#ifndef PUBLIC__ICUASW_PUS_SERVICE5_H
#define PUBLIC__ICUASW_PUS_SERVICE5_H



#define PUS_5_RIDNumber  16

//Informative RIDs 0x1000,0x1001,0x1002
#define PUS_5_InformativeRIDs 			3

//Low Severity Anomaly RIDs 0x2000,0x2001,0x2002,0x2003
#define PUS_5_LowSeverityAnomalyRIDs 	4

//Medium Severity Anomaly RIDs None
#define PUS_5_MediumSeverityAnomalyRIDs 0

//High Severity Anomaly RIDs 0x4000,0x4001,0x4002,0x4003,...0x400F
#define PUS_5_HighSeverityAnomalyRIDs 	16

/* brief enum that defines RID types
 * 0 for valid informative RIDs, 1 for valid Low Severity Anomaly,
  * 3 for a valid medium Severity Anomaly,4 for a valid high Severity Anomaly
  * 4 if is not a valid RID identifier
  */
enum TRIDType {
	RIDTypeInformative=0, RIDTypeLowSevAnomaly=1,RIDTypeMediumSevAnomaly=2
	,RIDTypeHighSevAnomaly=3,RIDNotValid=4
};


class PUSService5{

	  static uint32_t RIDEnableConfig[4];

	  /* \brief get the index of the RID in the RIDEnableConfig structure
	   * \returns 0 for a valid informative RIDs, 1 for a valid Low Severity Anomaly,
	  * 2 for a valid medium Severity Anomaly,3 for a valid high Severity Anomaly
	  * 4 if is not a valid RID identifier
	  */
	  static uint8_t GetRIDEnableConfigIndex(uint16_t RID);

	  /* \brief get the offset of the RID in the 32 bit element
	   * of the array RIDEnableConfig
	   * \returns the offset of the RID
	  */
	  static uint8_t GetRIDEnableConfigOffset(uint16_t RID);

	  /* \brief check if the index of the array RIDEnableConfig is valid
	  	   * \returns true if the index is valid
	  	  */
	  static bool IsIndexValid(uint8_t index);

public:

  /*returns 1 for a valid informative RIDs, 2 for a valid Low Severity Anomaly,
  * 3 for a valid medium Severity Anomaly,4 for a valid high Severity Anomaly
  * 0 if is not a valid RID identifier
  */
  static enum TRIDType  GetRIDType(uint16_t RID);

  //Enable RID. Return true if RID is enabled, false if not
  static bool IsRIDEnabled(uint16_t RID);

  //Enable RID. Return 0 if RID is valid, 1 if not
  static uint8_t EnableRID(uint16_t RID);
  //Disable RID. Return 0 if RID is valid, 1 if not
  static bool DisableRID(uint16_t RID);

  //Build RID TMs from Event List.
  static void BuildEventListTMs( CDEventList & eventList, CDTMList &tmList);
  static void ExecTC( CDTCHandler &tcHandler, CDTMList &tmList);
  static void Exec5_5TC( CDTCHandler &tcHandler, CDTMList &tmList);
  static void Exec5_6TC( CDTCHandler &tcHandler, CDTMList &tmList);

};
#endif


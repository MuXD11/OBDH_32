#ifndef INCLUDE__EPD_PUS_MISSION_H_
#define INCLUDE__EPD_PUS_MISSION_H_

/**
 * \brief Assigned Application Process ID
 */
#define EPD_APID    0x32C

/**
 * \brief Destination ID to be used on the TM packets
 */
#define EPD_DESTINATION_ID  0x78


/**
 * \brief Source IDs to be used on the TM packets
 */
enum EPD_ICU_SourceIDs{SOLO_Mission_TimeLine_SourceID=110
	  	  	  	  	  , SOLO_TC_Sequences_SourceID=111
					  , SOLO_Direct_Commands_SourceID=120};

/**
 * \brief PUS VERSION IN EPD MISSION
 */

#define EPD_PUS_VERSION  0x10

#define EPD_PUS_TC_MAX_NUM_OF_BYTES 256

#define EPD_PUS_TC_APPDATA_MAX_NUM_OF_BYTES (TC_MAX_NUM_OF_BYTES - 6 - 4 - 2)

#define EPD_PUS_TM_MAX_NUM_OF_BYTES 256

#define EPD_PUS_TM_APPDATA_MAX_NUM_OF_BYTES (TC_MAX_NUM_OF_BYTES - 6 - 4)

#define EPD_PUS_TC_APP_DATA_OFFSET 10

#define EPD_PUS_TM_APP_DATA_OFFSET 10

#endif /* INCLUDE__EPD_PUS_MISSION_H_ */

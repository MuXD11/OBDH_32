#ifndef PUBLIC__SC_CHANNEL_DRV_IFACE_V1_H
#define PUBLIC__SC_CHANNEL_DRV_IFACE_V1_H



#include "public/icuasw_pus_services_iface_v1.h"
#include "public/config.h"
#include "public/basic_types.h"
#include "public/tmtc_dyn_mem.h"

/**
 * \brief	Get Next Telecommand.*/

void SC_Channel_Init();


/**
 * \brief	Rx Data from the SC_Channel.
 * @return true if a complete Telecommand has been received.
 */
bool_t SC_Channel_RxData();
/**
 * \brief	Get Next Telecommand.
 * @param tc PUS TC Decriptor.
 */
void SC_Channel_GetNextTC(CDTCHandler *tc);

/**
 * \brief	telemetry transmission
 * @param ptm_descritpor telemetry descriptor pointer
 */
void SC_Channel_TxTM(const tm_descriptor_t *ptm_descriptor);

/**
 * \brief telemetry list transmission
 * @param tmlist list telemetry pointer
 */
void SC_Channel_TxTMList(CDTMList * tmlist);
/*PROTECTED REGION END*/



#endif // PUBLIC__CONSOLE_DRV_IFACE_V1_H

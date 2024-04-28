#ifndef FCDEvActionH
#define FCDEvActionH
#include "public/basic_types.h"
class CDEvAction{

 friend class PUSService19;
 CDTCHandler mTCHandler;
 public:
 /* \brief get the TCHandler associated to the action
 * \returns the TCHandler associated to the action
 */
 CDTCHandler GetActionTCPacket(){
 return mTCHandler;
 }
 // \brief Set the TCHandler associated to the action
 void SetActionTCPacket(CDTCHandler & actionPacket){
 mTCHandler=actionPacket;
 }
 CDEvAction(){
 mTCHandler.mTCDescriptor.p_tc_bytes=NULL;
 mTCHandler.mTCDescriptor.tc_num_bytes=0;
 }
};
#endif

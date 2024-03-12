/*************************************************************************** 
 * 
 *		EDROOM SERVICE LIBRARY   
 *    
 *		Copyright (C) 2007-2015  Oscar Rodriguez Polo
 * 
 *      Contact: opolo@aut.uah.es  
 * 
 ****************************************************************************/

/**************************************************************************** 
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation; either version 2 
 *   of the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,USA.
 *
 *
 ****************************************************************************/

/*!
 * \brief edroom services library cpp
 * 
 * \author Oscar Rodrguez Polo
 * \date $Date: 2010-02-15 10:09:39 $
 * \version $Revision: 1.1.4.3 $
 */

#include "public/edroomsl_iface_v1.h"
#include "public/edroomsl_types.h"
//#include <public/xprintf_iface_v1.h>
/*************************************************************************** 
 *************************************************************************** 
 * 
 *					TARGET OPTIONS DEFINES   
 *    
 *************************************************************************** 
 ****************************************************************************/

//!This code is affected for the following defines
/*************************************************************************** 
 *		DEFINES THAT EDROOM AUTOMATICALLY GENERATES
 *
 *	EDROOM automatically configure this defines in the edroomdf.h file
 *
 * _EDROOM_IS_EMBEDDED_		Embedded C++ compliant: do not use malloc nor template
 *
 *
 ****************************************************************************/

/*************************************************************************** 
 *		DEFINES THAT MUST BE SET IN THE EDROOM CONFIG TARGET FILE edroomtc.h 
 *
 *								
 *  _EDROOM_HANDLE_IRQS			Use this define if it's needed handle IRQs
 *
 *
 ****************************************************************************/

/*!
 * \brief CEDROOMMemory cpp (edroom services library) 
 * 
 * \author Oscar Rodrguez Polo
 * \date $Date: 2010-02-15 10:09:17 $
 * \version $Revision: 1.1.4.4 $
 * 
 * $Log: edroommemory.cpp,v $
 * Revision 1.1.4.4  2010-02-15 10:09:17  opolo
 * actualizados los nombres de los archivos y servicios
 *
 * Revision 1.1.4.3  2006/11/09 15:18:19  opolo
 * Rename the classes that manage the pools
 *
 * Revision 1.1.4.2  2006/10/18 18:31:51  opolo
 * Add Log
 *
 *
 * Revision 1.1.4.1  2006/10/18 18:07:20  opolo
 * *** empty log message ***
 * 
 */

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// class CEDROOMMemoryPool
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// CONSTRUCTOR
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void CEDROOMMemoryPool::SetMemory(TEDROOMUInt32 dimension, void *pDataMemory,
		TEDROOMBool *pMarksMemory, TEDROOMUInt32 elementSize) {

	TEDROOMUInt32 l_n;

	//Init PDataMemory
	PDataMemory = (TEDROOMByte*) pDataMemory;

	//Init Free Marks
	PFreeMarks = pMarksMemory;

	for (l_n = 0; l_n < dimension; l_n++)
		*(PFreeMarks + l_n) = true;  // All are Free

	//Init Size
	ElementSize = elementSize;

	//Init Dimension
	Dimension = dimension;

	//Init FreeIndex
	NextFreeIndex = 0;

}

TEDROOMUInt32 CEDROOMMemoryPool::GetElementSize(void) {
	return ElementSize;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// AllocData
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TEDROOMByte* CEDROOMMemoryPool::AllocData() {

	TEDROOMUInt32 l_elemindex;
	//Call to AllocData with index
	return AllocData(l_elemindex);

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// AllocData
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TEDROOMByte* CEDROOMMemoryPool::AllocData(TEDROOMUInt32 &rElemIndex) {

	TEDROOMByte *l_new = NULL;
	TEDROOMUInt32 l_counter, l_index;

	//Check if there is any element free
	if (NextFreeIndex < Dimension) {

		// Pointer to the free element
		l_new = PDataMemory + (NextFreeIndex * ElementSize);

		// Mark the element as not free
		*(PFreeMarks + NextFreeIndex) = false;
		rElemIndex = NextFreeIndex;

		// Look for another free element,
		l_counter = 0;
		l_index = NextFreeIndex;
		NextFreeIndex = Dimension; //This is the FT Free Index

		do {
			//next index
			l_index = (l_index + 1 + l_counter) % Dimension;

			if (*(PFreeMarks + l_index)) {

				//It is free
				NextFreeIndex = l_index;
			}
			l_counter++;

		} while ((l_counter < Dimension) && (NextFreeIndex == Dimension));

	} else {
		l_new = PDataMemory + (Dimension * ElementSize);
	}

	return (l_new);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// FreeData
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TEDROOMInt8 CEDROOMMemoryPool::FreeData(void *pData) {

	TEDROOMInt8 l_error;
	TEDROOMByte *l_pAux;

	TEDROOMUInt64 l_position, l_dimensionUInt64;
	TEDROOMUInt32 l_index;

	l_pAux = (TEDROOMByte*) pData;

	//It is needed to work with UInt64
	l_position = (l_pAux - PDataMemory) / ElementSize;

	l_dimensionUInt64 = Dimension;

	if ((l_position < 0) || (l_position >= l_dimensionUInt64)) {

		//It does not

		l_error = -1;

	} else {

		//It is checked that is less than Dimension and > 0
		l_index = (TEDROOMUInt32) l_position;

		//Mark as free
		*(PFreeMarks + l_index) = true;

		//If the pool was empty
		if (NextFreeIndex == Dimension)
			NextFreeIndex = l_index;

		pData = NULL; // pData returns with NULL

		l_error = 0;

	}
	return (l_error);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
// class CEDROOMProtectedMemoryPool
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// CONSTRUCTOR
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifdef _EDROOM_IS_DEBUG_
CEDROOMProtectedMemoryPool::CEDROOMProtectedMemoryPool(TEDROOMUInt32 dimension,
		void *pDataMemory, TEDROOMBool *pMarksMemory, TEDROOMUInt32 elementSize):
		Mutex("ProcMemPool")
		{
	SetMemory(dimension, pDataMemory, pMarksMemory, elementSize);

}

#else
CEDROOMProtectedMemoryPool::CEDROOMProtectedMemoryPool(TEDROOMUInt32 dimension,
		void *pDataMemory, TEDROOMBool *pMarksMemory, TEDROOMUInt32 elementSize)

		{
	SetMemory(dimension, pDataMemory, pMarksMemory, elementSize);

}
#endif

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// AllocData
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TEDROOMByte* CEDROOMProtectedMemoryPool::AllocData() {

	TEDROOMUInt32 l_elemindex;
	//Call to AllocData with index
	return AllocData(l_elemindex);

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// AllocData
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TEDROOMByte* CEDROOMProtectedMemoryPool::AllocData(TEDROOMUInt32 &rElemIndex) {

	TEDROOMByte *l_pData;

	Mutex.Wait();

	l_pData = CEDROOMMemoryPool::AllocData(rElemIndex);

	Mutex.Signal();

	return (l_pData);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// FreeData
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TEDROOMInt8 CEDROOMProtectedMemoryPool::FreeData(void *pData) {

	TEDROOMInt8 l_error;

	Mutex.Wait();

	l_error = CEDROOMMemoryPool::FreeData(pData);

	Mutex.Signal();

	return l_error;

}

/*!
 * \brief edroommessage cpp (edroom services library) 
 * 
 * \author Oscar Rodrguez Polo
 * \date $Date: 2010-03-04 09:08:17 $
 * \version $Revision: 1.1.4.5 $
 *
 * $Log: edroommessage.cpp,v $
 * Revision 1.1.4.5  2010-03-04 09:08:17  opolo
 * Changed the names of the attributes
 *
 * Revision 1.1.4.4  2010-02-15 10:09:17  opolo
 * actualizados los nombres de los archivos y servicios
 *
 * Revision 1.1.4.3  2006/11/09 15:23:12  opolo
 * Use the new name of the classes that manage the pools
 * 	EDROOMPool EDROOMMemoryPool and EDROOMProtectedMemoryPool
 *
 * Revision 1.1.4.2  2006/10/18 18:31:51  opolo
 * Add Log
 *
 *
 * Revision 1.1.4.1  2006/10/18 18:07:20  opolo
 * *** empty log message ***
 * 
 */

//*************************************************************************
//******************FUNCIONES MIEMBRO PUBLICAS DE CEDROOMMessage *************
//*************************************************************************
//CONSTRUCTOR
CEDROOMMessage::CEDROOMMessage() {

	mp_MsgPool = NULL;
	mp_DataPool = NULL;

}

//*************************************************************************
//FreeDeliveryInfo

void CEDROOMMessage::FreeDeliveryInfo() {
	;
} //Nothing for regular Msgs

//*************************************************************************
//CEDROOMInterface

CEDROOMInterface* CEDROOMMessage::GetPInterface() {
	return (mp_Interface);

}

TEDROOMWord32 CEDROOMMessage::GetMsgDataSize() {
	TEDROOMWord32 size = 0;
	if (mp_DataPool)
		size = mp_DataPool->GetElementSize();

	return size;
}

//*************************************************************************
//reply

void CEDROOMMessage::reply(TEDROOMSignal signal) {

	// send through the same interface

	mp_Interface->send(signal);
}
//**************************************************************************

void CEDROOMMessage::reply(TEDROOMSignal signal, void *dataObjetPtr,
		CEDROOMMemoryPool *apManMemDat) {

	// send through the same interface

	mp_Interface->send(signal, dataObjetPtr, apManMemDat);
}

//*************************************************************************
//******************FUNCIONES MIEMBRO PUBLICAS DE CEDROOMSynchrMessage ******

//*************************************************************************
//CONSTRUCTOR

CEDROOMSynchrMessage::CEDROOMSynchrMessage() :
		m_SynchrSem(0) {
	mp_MsgBack = NULL;
}

//*************************************************************************
//reply()

void CEDROOMSynchrMessage::reply(TEDROOMSignal signal) {

	CEDROOMSynchrMessage::reply(signal, NULL, NULL);

}

//**************************************************************************

void CEDROOMSynchrMessage::reply(TEDROOMSignal signal, void *dataObjetPtr,
		CEDROOMMemoryPool *pDataPool) {

	if (m_IsSenderWaiting) {
		// Complete Msg
		mp_MsgBack->signal = mp_Interface->applyConverFunct(signal);
		mp_MsgBack->data = dataObjetPtr;

		if (pDataPool) {
			if (pDataPool->IsEmpty())
				mp_Interface->mp_Component->SetErrorFlag(
						EDROOMReplyDataPoolEmpty);
		}
		mp_MsgBack->mp_DataPool = pDataPool;

		m_IsSenderWaiting = false; // No wait
		m_SynchrSem.Signal(); //Signal emisor
	}
}

//**************************************************************************

//*************************************************************************
//FreeDeliveryInfo

void CEDROOMTimeOutMessage::FreeDeliveryInfo() {

	mp_Mutex->Wait(); //Get Mutex

	if (mp_TimerInfo) { // Check this, but it must be always true

		void *aux_void_pTimerInf = mp_TimerInfo;

		mp_TimerInfoPool->FreeData(aux_void_pTimerInf);  // Devuelve la memoria

		mp_TimerInfo = NULL;

	}

	mp_Mutex->Signal(); //Free mutex

}

//*************************************************************************

//*******************************************************************************
//******************FUNCIONES MIEMBRO PUBLICAS DE CEDROOMSynchrMessagesPool ******

// Constructor

CEDROOMSynchrMessagesPool::CEDROOMSynchrMessagesPool(
		CEDROOMSynchrMessage *pSynMsg) :
#ifdef _EDROOM_IS_DEBUG_
		m_Mutex("SynMsgPool",1) {
#else
		m_Mutex(1) {
#endif

	mp_SynchrMsg = pSynMsg;

}

TEDROOMUInt32 CEDROOMSynchrMessagesPool::GetElementSize() {
	return sizeof(CEDROOMSynchrMessage);
}

//	 AllocData

CEDROOMSynchrMessage* CEDROOMSynchrMessagesPool::AllocData(void) {

	m_Mutex.Wait();
	return mp_SynchrMsg; //Synch Sem

}

TEDROOMInt8 CEDROOMSynchrMessagesPool::FreeData(void *apunt) {

	m_Mutex.Signal();
	return 0;
}

void CEDROOMMessagesPool::SetMemory(TEDROOMUInt32 dimension,
		CEDROOMMessage *pMessagePool, TEDROOMBool *pMemoryMarks) {

	CEDROOMMemoryPool::SetMemory(dimension, pMessagePool, pMemoryMarks,
			sizeof(CEDROOMMessage));

}

CEDROOMMessage* CEDROOMMessagesPool::AllocData() {

	return (CEDROOMMessage*) CEDROOMMemoryPool::AllocData();

}

void CEDROOMTimeOutMessagesPool::SetMemory(TEDROOMUInt32 elemNumber,
		CEDROOMTimeOutMessage *pDataPool, TEDROOMBool *pPoolMarks) {

	CEDROOMMemoryPool::SetMemory(elemNumber, pDataPool, pPoolMarks,
			sizeof(CEDROOMTimeOutMessage));

}

CEDROOMTimeOutMessage* CEDROOMTimeOutMessagesPool::AllocData() {

	return (CEDROOMTimeOutMessage*) CEDROOMMemoryPool::AllocData();
}

/*!
 * \brief CEDROOMInterface cpp (edroom services library)
 *
 * \author Oscar Rodrguez Polo
 * \date $Date: 2010-03-04 09:08:17 $
 * \version $Revision: 1.1.4.5 $
 *
 * $Log: edroominterface.cpp,v $
 * Revision 1.1.4.5  2010-03-04 09:08:17  opolo
 * Changed the names of the attributes
 *
 * Revision 1.1.4.4  2010-02-15 10:09:17  opolo
 * actualizados los nombres de los archivos y servicios
 *
 * Revision 1.1.4.3  2006/11/09 15:23:12  opolo
 * Use the new name of the classes that manage the pools
 * 	CEDROOMPool EDROOMMemoryPool and EDROOMProtectedMemoryPool
 *
 * Revision 1.1.4.2  2006/10/18 18:31:51  opolo
 * Add Log
 *
 *
 * Revision 1.1.4.1  2006/10/18 18:07:20  opolo
 * *** empty log message ***
 *
 */

//*****************************************************************************************
//********************************** DENINICION DE LAS FUNCIONES MIEMBRO DE ***************
//********************************************CEDROOMInterface ********************************
//*****************************************************************************************
//************************************CEDROOMInterface::send ********************************
void CEDROOMInterface::send(TEDROOMSignal signal) {

	//send message without data
	mp_Channel->send(signal, NULL, NULL);

}

void CEDROOMInterface::send(TEDROOMSignal signal, void *dataObjetPtr,
		CEDROOMMemoryPool *apMemDats) {

	//send message with data

	mp_Channel->send(signal, dataObjetPtr, apMemDats);

}

//*****************************************************************************************
//************************************CEDROOMInterface::invoke ********************************

CEDROOMMessage* CEDROOMInterface::invoke(TEDROOMSignal signal) {

	return invoke(signal, NULL, NULL);
}

//*****************************************************************************************
//************************************CEDROOMInterface::invoke ********************************

CEDROOMMessage* CEDROOMInterface::invoke(TEDROOMSignal signal,
		void *dataObjetPtr, CEDROOMMemoryPool *apMemDats) {

	return mp_Channel->invoke(signal, dataObjetPtr, apMemDats);

}

//*****************************************************************************************
//************************************CEDROOMInterface::applyConverFunct ********************************

TEDROOMSignal CEDROOMInterface::applyConverFunct(TEDROOMSignal signal_) {

	return mp_Channel->mp_SenderToReceiverSignalTranslator(signal_);

}

//identity test functions:

TEDROOMBool CEDROOMInterface::operator ==(CEDROOMInterface &rEDROOMInterface) {
	return (m_IdInterface == rEDROOMInterface.m_IdInterface);
}

TEDROOMBool CEDROOMInterface::operator !=(CEDROOMInterface &rEDROOMInterface) {
	return (m_IdInterface != rEDROOMInterface.m_IdInterface);
}

#ifdef _EDROOM_HANDLE_IRQS

//**************************************************************************
//********* CEDROOMInterfaceIRQ ***********************************************

void CEDROOMIRQInterface::InstallHandler() {
	if (!IRQInstalled) {
		Pr_IRQManager::InstallIRQHandler(HandIRQ, 0, IRQ);
		//Pr_IRQManager::EnableIRQ(IRQ);
		IRQInstalled = 1;
	}

}

void CEDROOMIRQInterface::DeInstallHandler() {
	if (IRQInstalled) {
		Pr_IRQManager::MaskIRQ(IRQ);
		Pr_IRQManager::InstallIRQHandler(HandIdle, 0, IRQ);
		Pr_IRQManager::UnMaskIRQ(IRQ);
		IRQInstalled = 0;

	}
}

void CEDROOMIRQInterface::EndIRQHandlerTask() {

	Pr_IRQManager::MaskIRQ(IRQ);
	if (EndIRQLook)
		EndIRQLook->Signal();
	if (IRQEventLook)
		IRQEventLook->Signal();

}

void CEDROOMIRQInterface::MaskIRQ() {

	Pr_IRQManager::MaskIRQ(IRQ);
}

void CEDROOMIRQInterface::UnMaskIRQ() {

	Pr_IRQManager::UnMaskIRQ(IRQ);
}

CEDROOMIRQInterface::CEDROOMIRQInterface(Pr_IRQHandler HandIRQ_,
		Pr_IRQHandler HandIdle_, Pr_IRQEvent &IRQEventLook_,
		Pr_SemaphoreBin &EndIRQLook_, TEDROOMInt8 IRQ_) {

	HandIRQ = HandIRQ_;
	HandIdle = HandIdle_;
	EndIRQLook = &EndIRQLook_;
	IRQEventLook = &IRQEventLook_;
	IRQInstalled = 0;
	IRQ = IRQ_;

}

void CEDROOMIRQInterface::NewIRQMsg(TEDROOMSignal signal, void *dataObjetPtr,
		CEDROOMMemoryPool *pDataPool) {

	CEDROOMMessage *apMsg;

	//Get Mutex
	mp_Component->m_Mutex.Wait();

	// Check Msg Pool
	if (mp_Component->mp_MsgPool->IsEmpty()) {

		// Msg Pool Is Empty
		mp_Component->SetErrorFlag(EDROOMAsyncMsgPoolEmpty);

	} else if (mp_Component->m_MsgQueue.IsFull()) {

		// Msg Pool Is Empty
		mp_Component->SetErrorFlag(EDROOMMsgQueueFull);

	} else {

		// Get msg memory
		apMsg = mp_Component->mp_MsgPool->AllocData();

		// Field attributes

		apMsg->signal = signal;

		//Msg pool

		apMsg->mp_MsgPool = mp_Component->mp_MsgPool;

		//data
		apMsg->data = dataObjetPtr;

		//data pool
		apMsg->mp_DataPool = pDataPool;

		if (pDataPool) {
			if (pDataPool->IsEmpty())
				mp_Component->SetErrorFlag(EDROOMIRQDataPoolEmpty);

		}
		//prio

		apMsg->priority = mp_Component->GetNomPriority();

		//Complete interface
		apMsg->mp_Interface = this;

		// Put msg in queue
		mp_Component->m_MsgQueue.In(apMsg);

	}

	// Free mutex
	mp_Component->m_Mutex.Signal();

}

//**************************************************************************
//********* CEDROOMNonMaskableIRQsInterface: *******************************

CEDROOMNonMaskIRQInterface::CEDROOMNonMaskIRQInterface(Pr_IRQHandler irqHandler,
		Pr_IRQHandler idleIrqHandler, Pr_IRQEvent &IRQEventLook,
		Pr_SemaphoreBin &endIrqLook, TEDROOMUInt8 irqVectorCount,
		TEDROOMUInt8 *pirqVectors) :
		CEDROOMIRQInterface(irqHandler, idleIrqHandler, IRQEventLook,
				endIrqLook, 0) {

	m_IRQVectorCount = irqVectorCount;
	mp_IRQVectors = pirqVectors;

}

void CEDROOMNonMaskIRQInterface::InstallHandler() {

	if ((!IRQInstalled) && (mp_IRQVectors != NULL)) {
		for (TEDROOMUInt8 i = 0; i < m_IRQVectorCount; i++)
			Pr_IRQManager::InstallIRQHandler(HandIRQ, 0, mp_IRQVectors[i]);

		IRQInstalled = 1;
	}

}

void CEDROOMNonMaskIRQInterface::DeInstallHandler() {
	if ((IRQInstalled) && (mp_IRQVectors != NULL)) {
		for (TEDROOMUInt8 i = 0; i < m_IRQVectorCount; i++)
			Pr_IRQManager::InstallIRQHandler(HandIdle, 0, mp_IRQVectors[i]);
		IRQInstalled = 0;

	}
}

void CEDROOMNonMaskIRQInterface::EndIRQHandlerTask() {

	if (EndIRQLook)
		EndIRQLook->Signal();
	if (IRQEventLook)
		IRQEventLook->Signal();

}

#endif

/*!
 * \brief edroomtiming header (edroom services library)
 *
 * \author Oscar Rodrguez Polo
 * \date $Date: 2010-03-04 09:08:17 $
 * \version $Revision: 1.1.4.5 $
 *
 * $Log: edroomtiming.cpp,v $
 * Revision 1.1.4.5  2010-03-04 09:08:17  opolo
 * Changed the names of the attributes
 *
 * Revision 1.1.4.4  2010-02-15 10:09:17  opolo
 * actualizados los nombres de los archivos y servicios
 *
 * Revision 1.1.4.3  2006/11/09 15:21:40  opolo
 * Define the CEDROOMTimingInterface class
 * Use the new name of the classes that manage the pools
 * 	CEDROOMPool EDROOMMemoryPool and EDROOMProtectedMemoryPool
 *
 * Revision 1.1.4.2  2006/10/18 18:31:51  opolo
 * Add Log
 *
 *
 * Revision 1.1.4.1  2006/10/18 18:07:20  opolo
 * *** empty log message ***
 *
 */

//*********************************************************************
//*********************************************************************
// class CEDROOMTimer
CEDROOMTimer::CEDROOMTimer() {
	m_Index = EDROOMUINT32_MAX;
}  // Se inicializa el Index a UINT_MA

TEDROOMBool CEDROOMTimer::IsValid() {
	return (TEDROOMBool) (m_Index < EDROOMUINT32_MAX);
}

//*********************************************************************
//*********************************************************************
// class CEDROOMTimingInterface

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// CONSTRUCTOR
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

CEDROOMTimingInterface::CEDROOMTimingInterface(CEDROOMTimingSAP *pTimingSAP,
		TEDROOMUInt32 maxNumTimers) {

	mp_TimingSAP = pTimingSAP;

	m_MaxNumTimers = maxNumTimers;

}

//**********************************************************************
//funcion miembro       InformAt

CEDROOMTimer CEDROOMTimingInterface::InformAt(Pr_Time timeValue) {

	return mp_TimingSAP->InformAt(this, timeValue);

}

//**********************************************************************

// relative timing functions:

//**********************************************************************
//funcion miembro       InformIn

CEDROOMTimer CEDROOMTimingInterface::InformIn(Pr_Time timeoutValue) {

	Pr_Time time;

	time.GetTime(); // Get current time

	time += timeoutValue;

	// return the timer identifier
	return (mp_TimingSAP->InformAt(this, time));

}

//**********************************************************************
//       currentTime

void CEDROOMTimingInterface::currentTime(Pr_Time &time) {
	time.GetTime();
}

//**********************************************************************
//       currentTime

Pr_Time CEDROOMTimingInterface::currentTime() {
	Pr_Time time;
	time.GetTime();
	return time;

}

//*********************************************************************
//*********************************************************************
// class CEDROOMTimingSAP

//**********************************************************************
// CONSTRUCTOR

CEDROOMTimingSAP::CEDROOMTimingSAP(CEDROOMComponent *p_Component_,
		unsigned int maxNumTimers, CEDROOMTimingMemory *pTimingMemory) :

#ifdef _EDROOM_IS_DEBUG_
		m_Mutex("TimingSAPMutex"),
		m_SynchrSem("TimingSAPSem",0), m_TimerTask(EDROOMfunTimer,"EDROOMfunTimer"
		, p_Component_->m_NomPriority,
		_EDROOM_TIMING_TASK_STACK)
		, m_WaitComponentSem("WaitCmpSem",0)
#else

		m_SynchrSem(0), m_TimerTask(EDROOMfunTimer
		, p_Component_->m_NomPriority,
		_EDROOM_TIMING_TASK_STACK)
		, m_WaitComponentSem(0)
#endif

{

	mp_TimerTask = &m_TimerTask;

	mp_Component = p_Component_; //pointer to component

	mp_TimerInfoPool = &pTimingMemory->m_TimerInfoMem;

	mp_TimeOutMsgPool = &pTimingMemory->m_TimeOutMessMem;

	mp_NextTimer = NULL;

}

//**********************************************************************
// Funcin Amiga funEDROOMTimer que implementa el timer

Pr_TaskRV_t CEDROOMTimingSAP::EDROOMfunTimer(Pr_TaskP_t) {

	CEDROOMComponent *pComponent;  //pointer to component

	CEDROOMTimingSAP *ptimerSAP;   //pointer to Timing SAP

	CEDROOMTimerConfig timerConfig; //Timer Configuration

	Pr_Time currentTime;
	Pr_Time nextTime;

	bool receiveTimerInfo;

	receiveTimerInfo = true;

	//Component sends the TimingSAP
	Pr_Receive(&ptimerSAP, sizeof(CEDROOMTimingSAP*));

	//Get Component pointer
	pComponent = ptimerSAP->mp_Component;

	do {

		if (receiveTimerInfo) {
			// Wait to receive the timer Configuration.

			Pr_Receive(&timerConfig, sizeof(CEDROOMTimerConfig));

			ptimerSAP->m_WaitComponentSem.Signal();
		}

		receiveTimerInfo = 1;

		// Set to priority URGENT
		ptimerSAP->mp_TimerTask->SetMaxPrioTmp(EDROOMprioURGENT);

		currentTime.GetTime();

		// Compare Timer Timeout with current Time
		if (timerConfig.m_Time > currentTime) {

			//Timeout is higher, so a waitTimed is needed
			nextTime = timerConfig.m_Time;

			//Round Micros ToTicks
			currentTime.RoudMicrosToTicks();
			nextTime.RoudMicrosToTicks();

			nextTime -= currentTime;

			//Round to Ticks
			//nextTime.RoudToTicks();

			ptimerSAP->m_SynchrSem.WaitTimed(nextTime);

		}

		// Restore prio Msg, this is the prio of the component
		ptimerSAP->mp_TimerTask->RestorePrioMsg();

		//Get SAP Mutex
		ptimerSAP->m_Mutex.Wait();

		// clear the SynchrSem

		ptimerSAP->m_SynchrSem.WaitCond();

		// Is Timer Active

		if (timerConfig.mp_TimerInfo->m_State == edroomTimerActive) {

			//Next Timer
			ptimerSAP->mp_NextTimer = timerConfig.mp_TimerInfo->mp_Next;

			// TimeOut Message is Sent.

			timerConfig.mp_TimerInfo->m_State = edroomTimerSent;

			//Free SAP Mutex
			ptimerSAP->m_Mutex.Signal();

			//Take component Mutex
			pComponent->m_Mutex.Wait();

			if (pComponent->m_MsgQueue.IsFull()) {

				pComponent->SetErrorFlag(EDROOMMsgQueueFull);

			} else {

				pComponent->m_MsgQueue.In(timerConfig.mp_TimerInfo->mp_Msg);

			}

			//Free component Mutex
			pComponent->m_Mutex.Signal();

			//Get SAP Mutex
			ptimerSAP->m_Mutex.Wait();

		}

		//Check if there is a Timer to queue
		while (receiveTimerInfo && ptimerSAP->mp_NextTimer) {

			currentTime.GetTime();

			timerConfig.mp_TimerInfo = ptimerSAP->mp_NextTimer;

			timerConfig.m_Time = timerConfig.mp_TimerInfo->m_Time;

			//Compare time
			if (timerConfig.m_Time > currentTime) {

				//No need to receive next timer. ptimerSAP->mp_NextTimer
				receiveTimerInfo = 0;

				// It is Active
				timerConfig.mp_TimerInfo->m_State = edroomTimerActive;

			} else {

				//Timer to queue
				timerConfig.mp_TimerInfo->m_State = edroomTimerSent;

				//Free SAP Mutex
				ptimerSAP->m_Mutex.Signal();

				//Take component Mutex
				pComponent->m_Mutex.Wait();

				if (pComponent->m_MsgQueue.IsFull()) {

					pComponent->SetErrorFlag(EDROOMMsgQueueFull);

				} else {

					pComponent->m_MsgQueue.In(timerConfig.mp_TimerInfo->mp_Msg);

				}

				//Free component Mutex
				pComponent->m_Mutex.Signal();

				//Take SAP Mutex
				ptimerSAP->m_Mutex.Wait();

				//Next Timer
				ptimerSAP->mp_NextTimer = timerConfig.mp_TimerInfo->mp_Next;

			}

		}

		//Free SAP Mutex
		ptimerSAP->m_Mutex.Signal();

	} while (1);

}

//**********************************************************************
//**************** PUBLIC METHODS **************************

//**********************************************************************
//       InformAt

CEDROOMTimer CEDROOMTimingSAP::InformAt(CEDROOMTimingInterface *interf,
		Pr_Time timeValue) {

	TEDROOMUInt32 indice;
	CEDROOMTimerInfo *pTimerInfo;
	CEDROOMTimeOutMessage *pTimeOutMsg;
	CEDROOMTimer TimerId;

	//Get Component Mutex
	mp_Component->m_Mutex.Wait();

	if (mp_TimeOutMsgPool->IsEmpty() || mp_TimerInfoPool->IsEmpty()) {

		mp_Component->SetErrorFlag(EDROOMTimeoutMsgPoolEmpty);

		//Free Mutex
		mp_Component->m_Mutex.Signal();

		//TimerId is ;

	} else {

		//Get TimeOutMsg
		pTimeOutMsg = mp_TimeOutMsgPool->AllocData();

		//Free Mutex
		mp_Component->m_Mutex.Signal();

		//Get SAP Mutex
		m_Mutex.Wait();

		//Get Timer Info
		pTimerInfo = mp_TimerInfoPool->AllocData(indice);

		//Free SAP Mutex
		m_Mutex.Signal();

		Pr_Time currentTime;

		currentTime.GetTime();

		// ******Set TimerInfo

		// timer is active
		pTimerInfo->m_State = edroomTimerActive;

		// set time
		pTimerInfo->m_Time = timeValue;

		// *******Set TimerId

		TimerId.mp_TimerInfo = pTimerInfo;

		// *******Complete TimerOutMsg

		pTimeOutMsg->signal = 0; // Timeout signal is always 0

		pTimeOutMsg->Time = timeValue;   //Time

		pTimeOutMsg->priority = mp_Component->GetNomPriority(); //Priority

		pTimeOutMsg->mp_MsgPool = mp_TimeOutMsgPool; //Msg Pool

		pTimeOutMsg->data = NULL;			//data

		pTimeOutMsg->mp_DataPool = NULL;  //data Pool

		pTimeOutMsg->mp_Interface = interf; //interface

		pTimeOutMsg->mp_TimerInfo = pTimerInfo;   //TimerInfo

		pTimeOutMsg->mp_TimerInfoPool = mp_TimerInfoPool; //TimerInfoPool

		pTimeOutMsg->mp_Mutex = &m_Mutex;   // Msg points to SAP Mutex

		// *******COMPLETE TimerInfo

		pTimerInfo->mp_Msg = pTimeOutMsg;

		// Get MUTEX

		m_Mutex.Wait();

		if (mp_NextTimer) {

			// Update Timers Queue

			if ((mp_NextTimer->m_State == edroomTimerActive)
					&& (mp_NextTimer->m_Time > timeValue)) {

				// It must be the first in Queue

				//Replace the current one

				mp_NextTimer->m_State = edroomTimerReady;

				pTimerInfo->mp_Next = mp_NextTimer;
				mp_NextTimer = pTimerInfo;

				//Signal SynchrSem

				m_SynchrSem.Signal();

				//Free SAP Mutex
				m_Mutex.Signal();

			} else {

				bool found;

				found = false;

				// It is not the first, so it is ready, not active

				pTimerInfo->m_State = edroomTimerReady;

				CEDROOMTimerInfo *aux;
				aux = mp_NextTimer;

				// Insert in the queue

				while (aux->mp_Next && !found) {

					if (aux->mp_Next->m_Time > timeValue) {

						found = true;

					} else
						aux = aux->mp_Next;

				}
				pTimerInfo->mp_Next = aux->mp_Next;
				aux->mp_Next = pTimerInfo;

				// Free MUTEX

				m_Mutex.Signal();

			}

		} else {

			// Queue is empty

			CEDROOMTimerConfig timerConfig;

			mp_NextTimer = pTimerInfo;
			pTimerInfo->mp_Next = NULL;

			// Complete TimerConfig

			//timer config

			timerConfig.m_Time = timeValue;

			timerConfig.mp_TimerInfo = pTimerInfo;

			// Free MUTEX

			m_Mutex.Signal();

			// Send TimerConfig

			Pr_Send(m_TimerTask, &timerConfig); // manda el dato al timer
			m_WaitComponentSem.Wait();

		}

		// Index is the timer identifier
		TimerId.m_Index = indice;

	}

	// return the timer identifier
	return (TimerId);
}

//**********************************************************************
//       Start

void CEDROOMTimingSAP::Start() {

	CEDROOMTimingSAP *pTimingSAP;

	pTimingSAP = this;
	Pr_Send(m_TimerTask, &pTimingSAP); // manda el dato apComponentr

}

//**********************************************************************
//       CEDROOMTimmingMemory SetMemory

void CEDROOMTimingMemory::SetMemory(TEDROOMUInt32 elemNumber,
		CEDROOMTimerInfo *pTimerInfoMem_, TEDROOMBool *pTimerInfoMemMarks,
		CEDROOMTimeOutMessage *pTimeOutMessageMem,
		TEDROOMBool *pTimeOutMessageMemMarks)

		{

	m_TimeOutMessMem.SetMemory(elemNumber, pTimeOutMessageMem,
			pTimeOutMessageMemMarks);

	m_TimerInfoMem.SetMemory(elemNumber, pTimerInfoMem_, pTimerInfoMemMarks);

}

//**********************************************************************
//       CEDROOMTimerInfoPool::SetMemory

void CEDROOMTimerInfoPool::SetMemory(TEDROOMUInt32 elemNumber,
		CEDROOMTimerInfo *PDataPool, TEDROOMBool *pPoolMarks) {

	CEDROOMMemoryPool::SetMemory(elemNumber, PDataPool, pPoolMarks,
			sizeof(CEDROOMTimerInfo));

}

//**********************************************************************
//       CEDROOMTimerInfoPool::AllocData

CEDROOMTimerInfo* CEDROOMTimerInfoPool::AllocData(TEDROOMUInt32 &ind) {

	return (CEDROOMTimerInfo*) CEDROOMMemoryPool::AllocData(ind);
}

/*!
 * \brief edroomqueue cpp (edroom services library)
 *
 * \author Oscar Rodrguez Polo
 * \date $Date: 2010-03-04 09:08:17 $
 * \version $Revision: 1.1.4.5 $
 *
 * $Log: edroomqueue.cpp,v $
 * Revision 1.1.4.5  2010-03-04 09:08:17  opolo
 * Changed the names of the attributes
 *
 * Revision 1.1.4.4  2010-02-15 10:09:17  opolo
 * actualizados los nombres de los archivos y servicios
 *
 * Revision 1.1.4.3  2006/11/09 15:23:12  opolo
 * Use the new name of the classes that manage the pools
 * 	EDROOMPool EDROOMMemoryPool and EDROOMProtectedMemoryPool
 *
 * Revision 1.1.4.2  2006/10/18 18:31:51  opolo
 * Add Log
 *
 *
 * Revision 1.1.4.1  2006/10/18 18:07:20  opolo
 * *** empty log message ***
 *
 */

//***************************************************************************
// CEDROOMQueue::CQueueNode
CEDROOMQueue::CQueueNode::CQueueNode() {
	mp_Msg = NULL;
	mp_Next = NULL;
}

//***************************************************************************
// CEDROOMQueue::CQueueHead

CEDROOMQueue::CQueueHead::CQueueHead() {
	mp_First = NULL;
	mp_Last = NULL;
	mp_Next = NULL;
}

//***************************************************************************
// CEDROOMQueue CONSTRUCTOR

CEDROOMQueue::CEDROOMQueue(TEDROOMUInt32 Max_Num_Mess, Pr_Task *pTask,
		Pr_SemaphoreRec *pMutexSem, TEDROOMUInt16 prioNumber,
		CEDROOMQueueNodesPool *pNodesPool, CQueueHead *pQueueHeads) :
		m_NewMsgSem(0)

{

	m_MaxNumMsg = Max_Num_Mess;

	m_IsBlocked = 0;
	m_MsgCounter = 0;
	m_PrioNumber = prioNumber;

	mp_Task = pTask;
	mp_MutexSem = pMutexSem;

	mp_NodesPool = pNodesPool;
	mp_QueueHeads = pQueueHeads;

	for (unsigned int i = 0; i < m_PrioNumber; i++)
		mp_QueueHeads[i].m_Priority = (TEDROOMPriority) i;

	mp_FirstQueueHead = NULL;

}

// ****************************************************************************
// **************PUBLIC METHODS ****************************
// ****************************************************************************

// ****************************************************************************
// CEDROOMQueue IsFull

TEDROOMBool CEDROOMQueue::IsFull() {

	return (TEDROOMBool) (m_MsgCounter == m_MaxNumMsg);
}

// ****************************************************************************
// CEDROOMQueue In

void CEDROOMQueue::In(CEDROOMMessage *pMsg) {

	TEDROOMPriority priority = pMsg->priority;

	CQueueNode *p_new_node; // Aux pointer

	p_new_node = mp_NodesPool->AllocData(); // New node
	p_new_node->mp_Msg = pMsg;
	p_new_node->mp_Next = NULL;

	m_MsgCounter++;

	//Add in the queue of this priority

	if (PutInNode(mp_QueueHeads + priority, p_new_node))
		// Update sorted Queue Heads
		UpDateSortedQueueHeadsList(priority);

	// Wake Receptor.

	if (m_IsBlocked) {

		m_IsBlocked = 0;
		m_NewMsgSem.Signal();

	}

}

// ****************************************************************************
// CEDROOMQueue Out

TEDROOMBool CEDROOMQueue::Out(CEDROOMMessage *&p_Msg) {

	CQueueNode *p_node; // aux pointer

	TEDROOMPriority priority;  // Msg Prio

	// Get Mutex
	mp_MutexSem->Wait();

	// Check Queue State

	if (!mp_FirstQueueHead) {

		m_IsBlocked++;  // There is blocked tasks

		// Free Mutex

		mp_MutexSem->Signal();

		// Wait new message
		m_NewMsgSem.Wait();

		// New Msg is in queue

		// Get Mutex

		mp_MutexSem->Wait();

	}

	// Here there is a msg

	// Take node
	TakeOutNode(p_node, priority);

	m_MsgCounter--;

	p_Msg = p_node->mp_Msg;

	// return node memory

	void *aux_void_p_node = p_node;

	mp_NodesPool->FreeData(aux_void_p_node);

	p_node = NULL;

	// Free Mutex.

	mp_MutexSem->Signal();

	return (false);

}

void CEDROOMQueue::UpDateSortedQueueHeadsList(TEDROOMPriority priority) {

	CQueueHead *aux, *previous, *newHead;

	newHead = mp_QueueHeads + priority;

	TEDROOMBool newHeadManaged = false;

	if (!mp_FirstQueueHead) {

		mp_FirstQueueHead = newHead;
		mp_FirstQueueHead->mp_Next = NULL;

	} else if (mp_FirstQueueHead->m_Priority > priority) {

		aux = mp_FirstQueueHead;
		mp_FirstQueueHead = newHead;
		mp_FirstQueueHead->mp_Next = aux;

	} else {
		aux = mp_FirstQueueHead;

		while ((!newHeadManaged)) {

			if (!aux->mp_Next) {   // Only one queue

				aux->mp_Next = newHead;
				newHead->mp_Next = NULL;    // no next head
				newHeadManaged = 1;

			} else {

				previous = aux;
				aux = aux->mp_Next;

				if (aux->m_Priority > priority) { //More heads, but with less priority

					newHead->mp_Next = aux;  // Put into queue
					previous->mp_Next = newHead;
					newHeadManaged = 1;
				}
			}
		}

	}

}

// ****************************************************************************
//  PRIVATE METHODS
// ****************************************************************************

// ****************************************************************************
// PutInNode

TEDROOMBool CEDROOMQueue::PutInNode(CQueueHead *head, CQueueNode *p_node) {
	TEDROOMBool empty = true;

	if (head->mp_First)  // it is not  empty
	{
		head->mp_Last->mp_Next = p_node;  // to the end
		head->mp_Last = p_node;
		empty = 0;
	} else  // Is Empty.
	{
		head->mp_First = p_node;

		head->mp_Last = head->mp_First;  // only one element

	}
	return empty;

}

// ****************************************************************************
// TakeOutNode

// It must be one element in the queue

void CEDROOMQueue::TakeOutNode(CQueueNode *&p_node, TEDROOMPriority &priority) //Saco de colas no urgentes

		{

	//First
	p_node = mp_FirstQueueHead->mp_First;

	priority = mp_FirstQueueHead->m_Priority;

	//Update pointer
	mp_FirstQueueHead->mp_First = p_node->mp_Next;

	//If empty, get next

	if (!mp_FirstQueueHead->mp_First)

		mp_FirstQueueHead = mp_FirstQueueHead->mp_Next;

}

// ****************************************************************************
// SetMemory

void CEDROOMQueue::CEDROOMQueueNodesPool::SetMemory(TEDROOMUInt32 elemNumber,
		CQueueNode *pPoolData, TEDROOMBool *pPoolMarks) {

	CEDROOMMemoryPool::SetMemory(elemNumber, pPoolData, pPoolMarks,
			sizeof(CEDROOMQueue::CQueueNode));

}

// ****************************************************************************
// AllocData

CEDROOMQueue::CQueueNode* CEDROOMQueue::CEDROOMQueueNodesPool::AllocData() {

	return (CEDROOMQueue::CQueueNode*) CEDROOMMemoryPool::AllocData();
}

/*!
 * \brief edroomcomm cpp (edroom services library)
 *
 * \author Oscar Rodrguez Polo
 * \date $Date: 2010-03-04 09:08:17 $
 * \version $Revision: 1.1.4.5 $
 *
 * $Log: edroomcomm.cpp,v $
 * Revision 1.1.4.5  2010-03-04 09:08:17  opolo
 * Changed the names of the attributes
 *
 * Revision 1.1.4.4  2010-02-15 10:09:17  opolo
 * actualizados los nombres de los archivos y servicios
 *
 * Revision 1.1.4.3  2006/11/09 15:23:12  opolo
 * Use the new name of the classes that manage the pools
 * 	CEDROOMPool EDROOMMemoryPool and EDROOMProtectedMemoryPool
 *
 * Revision 1.1.4.2  2006/10/18 18:31:51  opolo
 * Add Log
 *
 *
 * Revision 1.1.4.1  2006/10/18 18:07:20  opolo
 * *** empty log message ***
 *
 */

//***************************************************************************
//							CEDROOMLocalTXChannel PUBLIC METHODS
//***************************************************************************
//***************************************************************************
//Constructor
CEDROOMLocalTXChannel::CEDROOMLocalTXChannel() {

	mp_SenderPort = NULL;    //Init pointers
	mp_ReceiverPort = NULL;

	mp_SenderCmp = NULL;
	mp_ReceiverCmp = NULL;

}

//***************************************************************************
//send

void CEDROOMLocalTXChannel::send(TEDROOMSignal signal, void *p_data,
		CEDROOMMemoryPool *p_DataPool) {

	CEDROOMMessage *p_Msg;

	// Check DataPool
	if (p_DataPool) {
		if (p_DataPool->IsEmpty()) {
			mp_SenderCmp->m_Mutex.Wait();

			// Data Pool Is Empty
			mp_SenderCmp->SetErrorFlag(EDROOMSendDataPoolEmpty);

			mp_SenderCmp->m_Mutex.Signal();
		}
	}

	// Get memory msg
	mp_ReceiverCmp->m_Mutex.Wait();

	//Check if Receiver Msg Pool is Empty
	if (mp_ReceiverCmp->mp_MsgPool->IsEmpty()) {

		// Msg Pool Is Empty
		mp_ReceiverCmp->SetErrorFlag(EDROOMAsyncMsgPoolEmpty);

		mp_ReceiverCmp->m_Mutex.Signal();

	} else if (mp_ReceiverCmp->m_MsgQueue.IsFull()) {

		// Msg Pool Is Empty
		mp_ReceiverCmp->SetErrorFlag(EDROOMMsgQueueFull);

		mp_ReceiverCmp->m_Mutex.Signal();

	} else {

		p_Msg = mp_ReceiverCmp->mp_MsgPool->AllocData();
		mp_ReceiverCmp->m_Mutex.Signal();

		// fill msg attributes

		//signal conversion
		p_Msg->signal = (*mp_SenderToReceiverSignalTranslator)(signal);

		//Msg Pool
		p_Msg->mp_MsgPool = mp_ReceiverCmp->mp_MsgPool;

		//Msg data
		p_Msg->data = p_data;

		//Msg data Pool
		p_Msg->mp_DataPool = p_DataPool;

		//The nominal priority of the receiver
		p_Msg->priority = mp_ReceiverCmp->GetNomPriority();

		//Msg interface
		p_Msg->mp_Interface = mp_ReceiverPort;

		// Put in component Queue
		mp_ReceiverCmp->m_Mutex.Wait();
		mp_ReceiverCmp->m_MsgQueue.In(p_Msg);
		mp_ReceiverCmp->m_Mutex.Signal();

	}

}

//***************************************************************************
//invoke

CEDROOMMessage* CEDROOMLocalTXChannel::invoke(TEDROOMSignal signal,
		void *p_data, CEDROOMMemoryPool *p_DataPool) {

	CEDROOMSynchrMessage *p_Msg;
	TEDROOMBool queuefull = false;

	Pr_SemaphoreBin *apSemSincr;

	// Alloc Synchr Msg. It waits until the message is free, so Synchr Msg Pool
	// is never empty

	p_Msg = mp_SenderCmp->m_SynchrMsgPool.AllocData();

	// Complete attributes;

	//signal conversion
	p_Msg->signal = (*mp_SenderToReceiverSignalTranslator)(signal);

	//Msg Pool
	p_Msg->mp_MsgPool = &mp_SenderCmp->m_SynchrMsgPool;

	//Msg Data
	p_Msg->data = p_data;

	//Msg Data Pool
	p_Msg->mp_DataPool = p_DataPool;

	//Check If Data Pool is Empty
	if (p_DataPool)
		if (p_DataPool->IsEmpty())
			mp_SenderCmp->SetErrorFlag(EDROOMInvokeDataPoolEmpty);

	//Priority
	p_Msg->priority = mp_ReceiverCmp->GetNomPriority();
	;

	//Interface

	p_Msg->mp_Interface = mp_ReceiverPort;

	//Synchr Sem

	apSemSincr = &(p_Msg->m_SynchrSem);

	//Free Component->MsgBack, if it is not NULL
	mp_SenderCmp->EDROOMFreeMsgBackData();

	//Pointer to Msg Back;
	p_Msg->mp_MsgBack = &(mp_SenderCmp->m_MessageBack);

	// sender is waiting
	p_Msg->m_IsSenderWaiting = 1;

	// Put msg in queue
	mp_ReceiverCmp->m_Mutex.Wait();

	if (mp_ReceiverCmp->m_MsgQueue.IsFull()) {
		CEDROOMMessage *auxMsg;
		queuefull = true;
		// Msg Pool Is Empty
		mp_ReceiverCmp->SetErrorFlag(EDROOMMsgQueueFull);
		p_Msg->mp_MsgBack->signal = 0; //timeout
		p_Msg->mp_MsgBack->data = NULL;
		p_Msg->mp_MsgBack->mp_DataPool = NULL;
		auxMsg = (CEDROOMMessage*) p_Msg;
		mp_ReceiverCmp->EDROOMFreeMessage(auxMsg);

	} else
		mp_ReceiverCmp->m_MsgQueue.In(p_Msg);

	mp_ReceiverCmp->m_Mutex.Signal();

	if (!queuefull) {
		// Wait reply if message has been sent (queue is not full)
		apSemSincr->Wait();
	}

	//return the pointer
	return (&(mp_SenderCmp->m_MessageBack));

}

//***************************************************************************
//	COMM SAP METHODS
//***************************************************************************

//***************************************************************************
// *****************        RegisterInterface *******************************

TEDROOMInt32 CEDROOMLocalCommSAP::RegisterInterface(TEDROOMInterfaceID id,
		CEDROOMInterface &interf, CEDROOMComponent *component) {

	interf.m_IdInterface = id; //interface id

	interf.mp_Component = component; 	// component pointer

	return (0);
}

//***************************************************************************
// *****************        DeregisterInterface *******************************

void CEDROOMLocalCommSAP::Connect(CEDROOMInterface &inter1,
		CEDROOMInterface &inter2, CEDROOMLocalConnection &connection,
		TEDROOMSignal (f1)(TEDROOMSignal), TEDROOMSignal (f2)(TEDROOMSignal)) {

	//Connect ports

	connection.m_Channel1.mp_SenderPort = &inter1;     //puertos que la forman

	connection.m_Channel1.mp_ReceiverPort = &inter2;     //puertos que la forman

	connection.m_Channel2.mp_SenderPort = &inter2;     //puertos que la forman

	connection.m_Channel2.mp_ReceiverPort = &inter1;     //puertos que la forman

	// pointers to channels

	inter1.mp_Channel = &connection.m_Channel1;
	inter2.mp_Channel = &connection.m_Channel2;

	// pointer to components

	connection.m_Channel1.mp_SenderCmp = inter1.mp_Component;
	connection.m_Channel1.mp_ReceiverCmp = inter2.mp_Component;
	connection.m_Channel2.mp_SenderCmp = inter2.mp_Component;
	connection.m_Channel2.mp_ReceiverCmp = inter1.mp_Component;

	//Signal conversion

	connection.m_Channel1.mp_SenderToReceiverSignalTranslator = f1;
	connection.m_Channel2.mp_SenderToReceiverSignalTranslator = f2;

}

/*!
 * \brief EDROOMComponent cpp (edroom services library)
 *
 * \author Oscar Rodrguez Polo
 * \date $Date: 2010-03-04 09:08:16 $
 * \version $Revision: 1.1.2.2 $
 *
 * $Log: edroomcomponent.cpp,v $
 * Revision 1.1.2.2  2010-03-04 09:08:16  opolo
 * Changed the names of the attributes
 *
 * Revision 1.1.2.1  2010-02-15 10:09:17  opolo
 * actualizados los nombres de los archivos y servicios
 *
 * Revision 1.1.4.3  2006/11/09 15:23:12  opolo
 * Use the new name of the classes that manage the pools
 * 	EDROOMPool EDROOMMemoryPool and EDROOMProtectedMemoryPool
 *
 * Revision 1.1.4.2  2006/10/18 18:31:51  opolo
 * Add Log
 *
 *
 * Revision 1.1.4.1  2006/10/18 18:07:20  opolo
 * *** empty log message ***
 *
 */

//*****************************************************************//
//                             Component class                     //
//*****************************************************************//
//*****************************************************************//
//******************** CONSTRUCTOR ************************//

#ifdef _EDROOM_IS_DEBUG_

CEDROOMComponent::CEDROOMComponent(const char *name,
		TEDROOMComponentID componentID, TEDROOMUInt16 numPri,
		TEDROOMUInt32 numMaxM, TEDROOMPriority prioTask, TEDROOMUInt32 stack,
		CEDROOMComponentMemory *pComponentMemory) :
		EDROOMName(name), m_ComponentID(componentID), m_Mutex("CmpMutex"),m_SynchrMsgPool(
				&m_SynchrMsgOut), m_ComponentTask(EDROOMComponentTask, name, prioTask,
				stack), m_MsgQueue(numMaxM, &m_ComponentTask, &this->m_Mutex,
				numPri, &pComponentMemory->m_QueueNodesPool,
				pComponentMemory->mp_QueueHeads)

{

	mp_ComponentTask = &m_ComponentTask; // Task

	mp_MsgPool = &pComponentMemory->m_MessagesPool; // msg pool

	Msg = NULL;               //No msg

	MsgBack = NULL;           //No msgBack

	m_MessageBack.data = NULL; //No data
	m_MessageBack.mp_DataPool = NULL; //No pool

	m_NomPriority = prioTask;

	m_ErrorFlags = EDROOMNoError;		//NoError

}

#else

CEDROOMComponent::CEDROOMComponent(TEDROOMComponentID componentID,
		TEDROOMUInt16 numPri, TEDROOMUInt32 numMaxM, TEDROOMPriority prioTask,
		TEDROOMUInt32 stack, CEDROOMComponentMemory *pComponentMemory) :
		EDROOMName("Cmp"), m_ComponentID(componentID), m_SynchrMsgPool(
				&m_SynchrMsgOut), m_ComponentTask(EDROOMComponentTask, prioTask,
				stack), m_MsgQueue(numMaxM, &m_ComponentTask, &this->m_Mutex,
				numPri, &pComponentMemory->m_QueueNodesPool,
				pComponentMemory->mp_QueueHeads)

{

	mp_ComponentTask = &m_ComponentTask; // Task

	mp_MsgPool = &pComponentMemory->m_MessagesPool; // msg pool

	Msg = NULL;               //No msg

	MsgBack = NULL;           //No msgBack

	m_MessageBack.data = NULL; //No data
	m_MessageBack.mp_DataPool = NULL; //No pool

	m_NomPriority = prioTask;

	m_ErrorFlags = EDROOMNoError;		//NoError

}
#endif
//*****************************************************************//
// Destructor

CEDROOMComponent::~CEDROOMComponent() {

}

//*****************************************************************//
// Destroy component

void CEDROOMComponent::EDROOMDestroy() {

	CEDROOMMessage *Msg;

	m_Mutex.Wait();

	Msg = mp_MsgPool->AllocData(); //New msg

	Msg->signal = 1;   // EDROOMDestroy

	Msg->mp_MsgPool = mp_MsgPool;

	//No data
	Msg->data = NULL;

	//No pool
	Msg->mp_DataPool = NULL;

	//Priority

	Msg->priority = EDROOMprioVeryHigh;

	if (m_MsgQueue.IsFull()) {

		// Msg Pool Is Empty
		SetErrorFlag(EDROOMMsgQueueFull);

	} else {

		m_MsgQueue.In(Msg); // Put in queue
	}

	m_Mutex.Signal();

}

//*****************************************************************//
// Start

int CEDROOMComponent::EDROOMStart() {
	CEDROOMComponent *ap_component;

	ap_component = this; // pointer to component

	Pr_Send(*mp_ComponentTask, &ap_component);

	return (1); // No errors
}

//*****************************************************************//
//******************** PUBLIC METHODS ************************//

//*****************************************************************//
//EDROOMNewMsg
void CEDROOMComponent::EDROOMNewMsg() {

	//Get mutex
	m_Mutex.Wait();

	//Free previous msg Data
	EDROOMFreeMsgBackData();

	//Free previous msg
	EDROOMFreeMessage(Msg);

	//Free mutex
	m_Mutex.Signal();

	//Get msg from queue
	m_MsgQueue.Out(Msg);

	//Free Delivery Info
	Msg->FreeDeliveryInfo();

}

//*************************************************************************
//EDROOMFreeMessage

void CEDROOMComponent::EDROOMFreeMessage(CEDROOMMessage *&apMsg) {
	//Pointer is NULL?

	if (apMsg) {

		if (apMsg->data) {       //There is data in the msg
			if (apMsg->mp_DataPool)
				if (0 != apMsg->mp_DataPool->FreeData(apMsg->data)) {
					//Data is out of Pool!!!
					SetErrorFlag(EDROOMDataOutOfPool);
				}

		}
		//Use Msg Pool

		void *auxApMsg = apMsg;

		if (apMsg->mp_MsgPool)
			apMsg->mp_MsgPool->FreeData(auxApMsg);

		apMsg = NULL; //Mem is free

	}
}

//*************************************************************************
//EDROOMFreeMsgBack

void CEDROOMComponent::EDROOMFreeMsgBackData() {

	if (m_MessageBack.data) {       //Check if there is data
		if (m_MessageBack.mp_DataPool) {
			m_MessageBack.mp_DataPool->FreeData(m_MessageBack.data);
			m_MessageBack.mp_DataPool = NULL;
		}
		m_MessageBack.data = NULL;

	}

}

//******************    FRIEND FUNCTIONS     ***************************

//*****************************************************************//
//                             EDROOMComponentTask

Pr_TaskRV_t CEDROOMComponent::EDROOMComponentTask(Pr_TaskP_t) {

	CEDROOMComponent *ap_component;
	Pr_Receive(&ap_component, sizeof(CEDROOMComponent*));
	//Call to Behaviour function
	ap_component->EDROOMBehaviour();

}

//*****************************************************************//
//                                    CEDROOMComponentMemory                                //
//*****************************************************************//

//*****************************************************************//
//                            SetMemory

void CEDROOMComponentMemory::SetMemory(TEDROOMUInt32 asynMsgNumber,
		CEDROOMMessage *pMessagesMemory, TEDROOMBool *pMessagesMarksMemory,
		TEDROOMUInt32 queueNodesNumber,
		CEDROOMQueue::CQueueNode *pQueueNodesMemory,
		TEDROOMBool *pQueueNodesMarksMemory,
		CEDROOMQueue::CQueueHead *pQueueHeadsMemory) {

	m_MessagesPool.SetMemory(asynMsgNumber, pMessagesMemory,
			pMessagesMarksMemory);
	m_QueueNodesPool.SetMemory(queueNodesNumber, pQueueNodesMemory,
			pQueueNodesMarksMemory);

	mp_QueueHeads = pQueueHeadsMemory;

}

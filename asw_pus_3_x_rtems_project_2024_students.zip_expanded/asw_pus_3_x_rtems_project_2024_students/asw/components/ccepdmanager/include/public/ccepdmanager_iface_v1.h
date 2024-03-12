#ifndef CCEPDMANAGER_H_
#define CCEPDMANAGER_H_

//******************************************************************************
// EDROOM Service Library

#define _EDROOM_IS_EMBEDDED_

#include <public/edroomsl_iface_v1.h>

//******************************************************************************
// Data Classes

#include <public/cdtchandler_iface_v1.h>
#include <public/cdtmlist_iface_v1.h>
#include <public/cdeventlist_iface_v1.h>


//******************************************************************************
// Required software interfaces

#include <public/icuasw_pus_services_iface_v1.h>
#include <public/sc_channel_drv_v1.h>


/**
 * \class   CCEPDManager
 *
 */
class CCEPDManager: public CEDROOMComponent {

public:

	/**
	 * \enum TEDROOMCCEPDManagerSignal
	 * \brief Component Signal Enum Type
	 *
	 */
	 enum TEDROOMCCEPDManagerSignal { EDROOMSignalTimeout, 
							EDROOMSignalDestroy, 
							SHK_FDIR_TC, 
							EDROOMIRQsignal, 
							STxTM, 
							STMQueued };

	/**
	 * \class CCEPDManager::CEDROOMMemory
	 * \brief Component Memory
	 *
	 */
	class CEDROOMMemory: public CEDROOMComponentMemory{

		private:

			//!Array of Message Queue Heads, one for each priority
			CEDROOMQueue::CQueueHead QueueHeads[EDROOMprioMINIMUM+1];

	// ********************************************************************
	// ******************* Component Message Data Pools *******************
	// ********************************************************************

		public:

			//! CDTMList Data Pool Memory
			CDTMList	poolCDTMList[10+1];
			//! CDTMList Data Pool Marks Memory
			bool	poolMarkCDTMList[10];
			//! CDTCHandler Data Pool Memory
			CDTCHandler	poolCDTCHandler[10+1];
			//! CDTCHandler Data Pool Marks Memory
			bool	poolMarkCDTCHandler[10];


			/** \brief This function is used for setting the Component Memory
			 * 
			 * \param numberOfMsgs number of messages that the component can store
			 * \param msgsMemory memory for the messages that the component can store
			 * \param msgsMemoryMarks memory marks for the messages that the component can store
			 * \param numberOfNodes number of nodes that the component needs
			 * \param queueNodesMemory memory for the component message queues 
			 * \param queueNodesMemoryMarks memory marks for the component message queues 
			 */
			void SetMemory(TEDROOMUInt32 numberOfMsgs
						, CEDROOMMessage * msgsMemory
						, bool * msgsMemoryMarks
						, TEDROOMUInt32 numberOfNodes
						, CEDROOMQueue::CQueueNode * queueNodesMemory
						, bool * queueNodesMemoryMarks);

	};


	// ********************************************************************
	//******************  Component Communication Ports *******************
	// ********************************************************************

	//! HK_FDIRCtrl Component Port
	CEDROOMInterface	HK_FDIRCtrl;
	//! TMChannelCtrl Component Port
	CEDROOMInterface	TMChannelCtrl;


	// ********************************************************************
	// ************************* Component IRQ Handling *******************
	// ********************************************************************

	// ********************************
	// Handling IRQ vector 18

	//! Event for trigger the bottom half associated to the IRQ vector 18
	static Pr_IRQEvent	EDROOMEventIRQ18;
	//! Binary Semaphore for signal the end of the bottom half of the IRQ vector 18
	static Pr_SemaphoreBin	EDROOMSemEndIRQ18;
	//! IRQ Handler for the IRQ vector 18
	static Pr_IRQHandler_RetType	EDROOMIRQ18Handler(void);
	//! Top Half Function for IRQ Handler  18
	static void	EDROOMIRQ18HandlerTopHalfFunction(void);
	//! Idle IRQ Handler for the IRQ vector 18
	static Pr_IRQHandler_RetType	EDROOMIRQ18IdleHandler(void);
	//! Bottom Half Task Function for the IRQ vector 18
	static Pr_TaskRV_t 	EDROOMIRQ18BottomHalfTask(Pr_TaskP_t);
	//! Bottom Half Pr_Task Object for the IRQ vector 18
	Pr_Task 	EDROOMIRQ18BottomHalfT;
	//! Component Port associated to the IRQ vector 18
	static CEDROOMIRQInterface	RxTC;
	//! Global variable required for the botton half of the IRQ vector 18
	static CDTCHandler	EDROOMVarIRQ18;
	/**
	 * \class CEDROOMPOOLIRQ18CDTCHandler
	 * \brief Data Pool Class required for the botton half of the IRQ vector 18
	 *
	 */
	class CEDROOMPOOLIRQ18CDTCHandler:public CEDROOMProtectedMemoryPool {
		//! Data Pool Memory
		CDTCHandler mem[10+1];
		//! Data Pool Memory Marks
		bool marks[10];
		public:
		//! Constructor
		CEDROOMPOOLIRQ18CDTCHandler():CEDROOMProtectedMemoryPool(10,mem,marks, sizeof(CDTCHandler)){}
		//! Function for allocating a data from the pool
		CDTCHandler	* AllocData(){ return ( CDTCHandler	* ) CEDROOMProtectedMemoryPool::AllocData();}
	};
	 //!Data Pool required for the botton half of the IRQ vector 18
	static CEDROOMPOOLIRQ18CDTCHandler	EDROOMPoolIRQ18;




	// *************************************************************************
	// **************************** Frame Service Methods	********************
	// *************************************************************************



	//! Constructor
	CCEPDManager(TEDROOMComponentID id, TEDROOMUInt32 roomNumMaxMens, TEDROOMPriority roomtaskPrio, 
		TEDROOMStackSizeType roomStack, CEDROOMMemory * pActorMemory );




	//! Component Configuration 
	 int EDROOMConfig();


	//! Component Start 
	 int EDROOMStart();




	#ifdef _EDROOM_SYSTEM_CLOSE

	//! Method that returns true if component is finished 
	bool EDROOMIsComponentFinished();


	#endif

protected:



	//! Component behaviour 
	virtual void EDROOMBehaviour();




public:

	// *****************************	Behaviour  *************************

	// ***********************************************************************

	// class EDROOM_CTX_Top_0

	// ***********************************************************************



	class EDROOM_CTX_Top_0 {

	protected:

	/**
	 * \enum TEDROOMCCEPDManagerSignal
	 * \brief Component Signal Enum Type
	 *
	 */
	enum TEDROOMCCEPDManagerSignal { EDROOMSignalTimeout,
		EDROOMSignalDestroy,
		SHK_FDIR_TC,
		EDROOMIRQsignal,
		STxTM,
		STMQueued };


		friend class CCEPDManager;

		//!component reference
		CCEPDManager &EDROOMcomponent;

		//!Current message pointer reference
		CEDROOMMessage * &Msg;

		//!Synchronous message back pointer reference
		CEDROOMMessage * &MsgBack;

		//!Component ports
		CEDROOMInterface & HK_FDIRCtrl;
		CEDROOMInterface & TMChannelCtrl;
		CEDROOMIRQInterface & RxTC;


		//! State Identifiers
		enum TEDROOMStateID{I,
			Ready,
			Reboot,
			ValidTC};

		//!Transition Identifiers
		enum TEDROOMTransitionID{Init,
			NewRxTC,
			NewRxTC_Accepted,
			NewRxTC_NotAccepted,
			HandleTC,
			HandleTC_ToReboot,
			HandleTC_FwdHK_FDIRTC,
			HandleTC_ExecPrioTC,
			EDROOMMemoryTrans };



		//!Variables
		CDEventList &VCurrentEvList;
		CDTCHandler &VCurrentTC;
		CDTMList &VCurrentTMList;


		// Pools *************************************************

		class CEDROOMPOOLCDTMList:public CEDROOMProtectedMemoryPool {
			public:
			CEDROOMPOOLCDTMList(TEDROOMUInt32 elemCount,CDTMList *pMem, bool *pMarks);
			CDTMList	* AllocData();
		};
		CEDROOMPOOLCDTMList	& EDROOMPoolCDTMList;
		class CEDROOMPOOLCDTCHandler:public CEDROOMProtectedMemoryPool {
			public:
			CEDROOMPOOLCDTCHandler(TEDROOMUInt32 elemCount,CDTCHandler *pMem, bool *pMarks);
			CDTCHandler	* AllocData();
		};
		CEDROOMPOOLCDTCHandler	& EDROOMPoolCDTCHandler;


		//!Constructor
		EDROOM_CTX_Top_0 (CCEPDManager &act,
				CDEventList & EDROOMpVarVCurrentEvList,
				CDTCHandler & EDROOMpVarVCurrentTC,
				CDTMList & EDROOMpVarVCurrentTMList,
				CEDROOMPOOLCDTMList & EDROOMpPoolCDTMList,
				CEDROOMPOOLCDTCHandler & EDROOMpPoolCDTCHandler );

		//!Copy constructor
		EDROOM_CTX_Top_0 (EDROOM_CTX_Top_0 &context);

	public:

		/**
		 * \brief Search Context transition 
		 * \param edroomCurrentTrans returns the context transition 

		 * \return true if context transition is found 

		 */
		bool EDROOMSearchContextTrans(TEDROOMTransId &edroomCurrentTrans);

		//! \brief Get new message from the Queue

		void EDROOMNewMessage()
		{ EDROOMcomponent.EDROOMNewMsg(); }

		/**
		 * \brief Get and Clear the Error Flags 
		 * \return the error flags  

		 */
		 TEDROOMUInt32 GetAndClearErrorFlags(){ return EDROOMcomponent.GetAndClearErrorFlags();}

		// User-defined Functions

		/**
		 * \brief  
		 */
		void	FExecPrioTC();

		/**
		 * \brief  
		 */
		void	FGetTC();

		/**
		 * \brief  
		 */
		void	FInit();

		/**
		 * \brief  
		 */
		void	FInvokeTxTMList();

		/**
		 * \brief  
		 */
		void	FMngTCAcceptation();

		/**
		 * \brief  
		 */
		void	FMngTCRejection();

		/**
		 * \brief  
		 */
		bool	GAcceptTC();

		/**
		 * \brief  
		 */
		bool	GToReboot();

		/**
		 * \brief 
		 */
		bool	GFwdToHK_FDIR();

		/**
		 * \brief 
		 */
		void	FFwdHK_FDIRTC();

	};

	// ***********************************************************************

	// class EDROOM_SUB_Top_0

	// ***********************************************************************



	class EDROOM_SUB_Top_0 : public EDROOM_CTX_Top_0 {

	protected:



		//!current state identifier
		EDROOM_CTX_Top_0::TEDROOMStateID edroomCurrentState;

		//!next state identifier
		EDROOM_CTX_Top_0::TEDROOMStateID edroomNextState;

		//!Variables
		CDEventList VCurrentEvList;
		CDTCHandler VCurrentTC;
		CDTMList VCurrentTMList;


		// Pools**************************************************
		CEDROOMPOOLCDTMList	EDROOMPoolCDTMList;
		CEDROOMPOOLCDTCHandler	EDROOMPoolCDTCHandler;


	public:

		//! Constructor
		EDROOM_SUB_Top_0 (CCEPDManager &act, CEDROOMMemory *pEDROOMMemory  );


		//! Top Context Behaviour 

		void EDROOMBehaviour();

		//!Top Context Init
		void EDROOMInit();

		//! Initial substate arrival
		TEDROOMTransId EDROOMIArrival();

		// ***********************************************************************

		// JoinPoint ValidTC

		// ***********************************************************************



		TEDROOMTransId EDROOMValidTCArrival();

		// ***********************************************************************

		// Leaf SubState Ready

		// ***********************************************************************



		TEDROOMTransId EDROOMReadyArrival();

		// ***********************************************************************

		// Leaf SubState Reboot

		// ***********************************************************************



		TEDROOMTransId EDROOMRebootArrival();

	};

protected:

	//!Top State
	EDROOM_SUB_Top_0 edroomTopState;



};
#endif

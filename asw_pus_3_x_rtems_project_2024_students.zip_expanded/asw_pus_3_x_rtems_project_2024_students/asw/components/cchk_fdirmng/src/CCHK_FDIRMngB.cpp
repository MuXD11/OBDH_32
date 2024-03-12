#include <public/cchk_fdirmng_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCHK_FDIRMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCHK_FDIRMng &act,
	 CDTMList & EDROOMpVarVCurrentTMList,
	 Pr_Time & EDROOMpVarVNextTimeout,
	 CEDROOMPOOLCDTMList & EDROOMpPoolCDTMList ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	HK_FDIRCtrl(EDROOMcomponent.HK_FDIRCtrl),
	TMChannelCtrl(EDROOMcomponent.TMChannelCtrl),
	HK_FDIRTimer(EDROOMcomponent.HK_FDIRTimer),
	VCurrentTMList(EDROOMpVarVCurrentTMList),
	VNextTimeout(EDROOMpVarVNextTimeout),
	EDROOMPoolCDTMList(EDROOMpPoolCDTMList)
{
}

CCHK_FDIRMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	HK_FDIRCtrl(context.HK_FDIRCtrl),
	TMChannelCtrl(context.TMChannelCtrl),
	HK_FDIRTimer(context.HK_FDIRTimer),
	VCurrentTMList(context.VCurrentTMList),
	VNextTimeout(context.VNextTimeout),
	EDROOMPoolCDTMList(context.EDROOMPoolCDTMList )
{

}

	// EDROOMSearchContextTrans********************************************

bool CCHK_FDIRMng::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
			TEDROOMTransId &edroomCurrentTrans)
			{

	bool edroomValidMsg=false; 

	 switch(Msg->signal)
	{

		 case ( EDROOMSignalDestroy ): 

			 edroomValidMsg=true;
			 edroomCurrentTrans.distanceToContext = 0 ;
			 edroomCurrentTrans.localId = -1 ;
			 break;

	}

	return(edroomValidMsg);

}

	// User-defined Functions   ****************************

void	CCHK_FDIRMng::EDROOM_CTX_Top_0::FDoHK_FDIR()

{
   //Define absolute time
  Pr_Time time;
 
VNextTimeout+= Pr_Time(1,0); // Add X sec + Y microsec 
time=VNextTimeout; 
PUSService3::DoHK(VCurrentTMList);	
   //Program absolute timer 
   HK_FDIRTimer.InformAt( time ); 
}



void	CCHK_FDIRMng::EDROOM_CTX_Top_0::FInitHK_FDIR()

{
   //Define absolute time
  Pr_Time time;
 
time.GetTime(); // Get current monotonic time   
time+=Pr_Time(1,0); // Add X sec + Y microsec    
VNextTimeout=time;
PUSService3::Init(); //Init PUSService 3
 
   //Program absolute timer 
   HK_FDIRTimer.InformAt( time ); 
}



void	CCHK_FDIRMng::EDROOM_CTX_Top_0::FInvokeTxTMList()

{
   //Allocate data from pool
  CDTMList * pSTxTM_Data = EDROOMPoolCDTMList.AllocData();
	
		// Complete Data 
	
	*pSTxTM_Data=VCurrentTMList;    
	VCurrentTMList.Clear();
   //Invoke synchronous communication 
   MsgBack=TMChannelCtrl.invoke(STxTM,pSTxTM_Data,&EDROOMPoolCDTMList); 
}



void	CCHK_FDIRMng::EDROOM_CTX_Top_0::FExecHK_FDIR_TC()

{
   //Handle Msg->data
  CDTCHandler & varSHK_FDIR_TC = *(CDTCHandler *)Msg->data;
	
		// Data access
	
   CDEventList TCExecEventList;  
   PUS_HK_FDIR_TCExecutor::ExecTC(varSHK_FDIR_TC,VCurrentTMList,TCExecEventList);

}



	//********************************** Pools *************************************

	//CEDROOMPOOLCDTMList

CCHK_FDIRMng::EDROOM_CTX_Top_0::CEDROOMPOOLCDTMList::CEDROOMPOOLCDTMList(
			TEDROOMUInt32 elemCount,CDTMList* pMem,bool * pMemMarks):
				CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks,
					sizeof(CDTMList))
{
}

CDTMList *	CCHK_FDIRMng::EDROOM_CTX_Top_0::CEDROOMPOOLCDTMList::AllocData()
{
	return(CDTMList*)CEDROOMProtectedMemoryPool::AllocData();
}



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCHK_FDIRMng::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCHK_FDIRMng&act
	,CEDROOMMemory *pEDROOMMemory):
		EDROOM_CTX_Top_0(act,
			VCurrentTMList,
			VNextTimeout,
			EDROOMPoolCDTMList),
		EDROOMPoolCDTMList(
			10, pEDROOMMemory->poolCDTMList,
			pEDROOMMemory->poolMarkCDTMList)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCHK_FDIRMng::EDROOM_SUB_Top_0::EDROOMBehaviour()
{

	TEDROOMTransId edroomCurrentTrans;

	//Behaviour starts from Init State

	edroomCurrentTrans = EDROOMIArrival();

	do
	{

		//Take next transition

		switch(edroomCurrentTrans.localId)
		{

			//Next Transition is Init
			case (Init):
				//Execute Action 
				FInitHK_FDIR();
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//Next Transition is DoHK_FDIR
			case (DoHK_FDIR):
				//Execute Action 
				FDoHK_FDIR();
				//Invoke Synchronous Message 
				FInvokeTxTMList();
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//Next Transition is ExecTC
			case (ExecTC):
				//Msg->Data Handling 
				FExecHK_FDIR_TC();
				//Invoke Synchronous Message 
				FInvokeTxTMList();
				//Next State is Ready
				edroomNextState = Ready;
				break;
		}

		//Entry into the Next State 
		switch(edroomNextState)
		{

				//Go to the state I
			case (I):
				//Arrival to state I
				edroomCurrentTrans=EDROOMIArrival();
				break;

				//Go to the state Ready
			case (Ready):
				//Arrival to state Ready
				edroomCurrentTrans=EDROOMReadyArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCHK_FDIRMng::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCHK_FDIRMng::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Ready

	// ***********************************************************************



TEDROOMTransId CCHK_FDIRMng::EDROOM_SUB_Top_0::EDROOMReadyArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == HK_FDIRTimer)
				{

					//Next transition is  DoHK_FDIR
					edroomCurrentTrans.localId= DoHK_FDIR;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

			case (SHK_FDIR_TC): 

				 if (*Msg->GetPInterface() == HK_FDIRCtrl)
				{

					//Next transition is  ExecTC
					edroomCurrentTrans.localId= ExecTC;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}




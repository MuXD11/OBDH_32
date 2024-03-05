#ifndef FCDTCDescriptorH
#define FCDTCDescriptorH


#include <platform/basic_types.h>

byte_t sc_channel_drv_get_char();

enum TTCExecCtrl{ExecAsPrioTC, ExecAsChangeModeTC, ExecAsHK_FDIRTC
	, ExecAsSensorMngTC
	,ExecAsBKGTC, ExecAsResetTC};

struct __attribute__((__packed__)) TCPackHeader_t{

 word16_t packID;
 word16_t seqCtrl;
 uint16_t length;

};

struct __attribute__((__packed__)) TCDataFieldHeader_t{
	byte_t flat_pusVersion_Ack;
	uint8_t service;
	uint8_t subservice;
	uint8_t dummy;
};

class CDTCDescriptor{

	friend class PUSService1;
	friend class PUSService19;

	protected:
	
	TTCExecCtrl tcexecCtrl;

	public:
	
	uint8_t rxBytesCounter;

	TCPackHeader_t packHeader;

	TCDataFieldHeader_t dataFieldHeader;

	uint8_t appData[256];

	bool_t IsPrioTC(){return ExecAsPrioTC==tcexecCtrl;}
	bool_t IsChangeModeTC(){return ExecAsChangeModeTC==tcexecCtrl;}
	bool_t IsHK_FDIRTC(){return ExecAsHK_FDIRTC==tcexecCtrl;}
	bool_t IsSensorMngTC(){return ExecAsSensorMngTC==tcexecCtrl;}
	bool_t IsBKGTC(){return ExecAsBKGTC==tcexecCtrl;}
	bool_t IsResetTC(){return ExecAsResetTC==tcexecCtrl;}
	bool_t IsRebootTC(){return ExecAsResetTC==tcexecCtrl;}

	CDTCDescriptor(){

		rxBytesCounter=0;

	}
	//returns true if the TC is commpleted after IRQ 
	bool HandleIRQ(){

		RxByte(sc_channel_drv_get_char());
		return (0==rxBytesCounter);
	}
	void RxByte(byte_t rxByte){
			
		if(rxBytesCounter< 6 ){
			byte_t * aux=(byte_t*)&packHeader;
			*(aux + rxBytesCounter)=rxByte;
		  	rxBytesCounter++;
		}else if(rxBytesCounter< 10 ){
			byte_t * aux=(byte_t*)&dataFieldHeader;
			*(aux + rxBytesCounter-6)=rxByte;
		  	rxBytesCounter++;			
		}else {
			appData[rxBytesCounter-10]=rxByte;
			rxBytesCounter++;
			if (rxBytesCounter == (6 + packHeader.length + 1))
				rxBytesCounter=0;
			
		}
		
	}

	private:
	
};

#endif

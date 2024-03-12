#ifndef FCDTCDescriptorH
#define FCDTCDescriptorH

#include "public/config.h"
#include "public/basic_types.h"
#include "public/ccsds_pus.h"
#include "public/tmtc_dyn_mem.h"

enum TTCExecCtrl {
	ExecCtrlPrioTC, ExecCtrlReboot,ExecCtrlHK_FDIRTC
};

enum TTCAcceptationStatus {
	TCAcceptationNotProcessed,
	TCAcceptationOK,
	TCAcceptationCRCError,
	TCAcceptationAPIDError,
	TCAcceptationSourceIDError,
	TCAcceptationTypeError,
	TCAcceptationSubTypeError
};

class CDTCHandler {

	friend class PUSService1;
	friend class PUSService9;
	friend class PUSService3;
	friend class PUSService17;

	friend class PUSPrioTCExecutor;
	friend class PUS_HK_FDIR_TCExecutor;

	friend void SC_Channel_GetNextTC(CDTCHandler *tc);

protected:

	//TC descriptor
	tc_descriptor_t mTCDescriptor;

	//TC App Data Index to control TC fields retrieving
	uint16_t mTCAppDataIndex;

	//Attribute to control which task executes the telecommand
	TTCExecCtrl mTCExecCtrl;

	//Attribute that defines the acceptation error;
	TTCAcceptationStatus mAcceptationStatus;

	/**
	 * \brief Start up the Execution of the telecommand
	 *
	 * \return 0 if StartUp Execution is correct
	 */
	uint8_t StartUpExecution();

	/**
	 * \brief Free the telecommand descriptor memory
	 *
	 * \return 0 if descriptor memory is properly freed
	 */
	uint8_t FreeTCDescriptor();

	//Get the Next uint field of the telecommand
	uint8_t GetNextUInt8();
	uint16_t GetNextUInt16();
	uint32_t GetNextUInt32();
	uint64_t GetNextUInt64();

	int8_t GetNextInt8();
	int16_t GetNextInt16();
	int32_t GetNextInt32();
	int64_t GetNextInt64();

	//return true if index is valid
	bool_t IsValidTCField(uint8_t field_size) {
		return (mTCAppDataIndex + field_size) <= mTCDescriptor.tc_num_bytes;
	}

	/**
	 * \brief Set mTCExecCtrl to ExecCtrlEPDManagerTask
	 *
	 */

	void SetExecCtrlAsPrioTC() {
		mTCExecCtrl = ExecCtrlPrioTC;

	}

	/**
	 * \brief Set mTCExecCtrl to ExecCtrlReboot
	 *
	 */

	void SetExecCtrlAsRebootTC() {

		mTCExecCtrl = ExecCtrlReboot;
	}

	/**
	 * \brief Set mTCExecCtrl to ExecCtrlHK_FDIRTC
	 *
	 */

	void SetExecCtrlAsHK_FDIRTC() {

		mTCExecCtrl = ExecCtrlHK_FDIRTC;
	}


	/**
	 * \brief Set Acceptation Status
	 *
	 */

	void SetAcceptationStatus(TTCAcceptationStatus status) {

		mAcceptationStatus = status;

	}

	/**
	 * \brief Get Acceptation Status
	 *
	 */

	TTCAcceptationStatus GetAcceptationStatus() {

		return mAcceptationStatus;

	}

	/**
	* \brief Get Acceptation Status
	*
	*/

	static bool_t HandleIRQ();

public:

	//Constructor
	CDTCHandler();

	/**
	 * \brief Get APID
	 *
	 * \return the telecommand's APID
	 */

	bool_t IsAccepted() {
		return (TCAcceptationOK == mAcceptationStatus);
	}
	;

	bool_t IsPrioTC() {
		return ExecCtrlPrioTC == mTCExecCtrl;
	}

	bool_t IsRebootTC() {
		return ExecCtrlReboot == mTCExecCtrl;
	}

	bool_t IsHK_FDIRTC() {
			return ExecCtrlHK_FDIRTC == mTCExecCtrl;
	}

	/**
	 * \brief Get APID
	 *
	 * \return the telecommand's APID
	 */

	uint16_t GetPacketID();

	/**
	 * \brief Get APID
	 *
	 * \return the telecommand's APID
	 */

	uint16_t GetAPID();

	/**
	 * \brief Get Packet Sequence Control
	 *
	 * \return the telecommand's Packet Sequence Control
	 */

	uint16_t GetPackSeqCtrl();

	/**
	 * \brief Get Sequence Count
	 *
	 * \return the telecommand's Sequence Flags
	 */

	uint8_t GetSeqFlags();

	/**
	 * \brief Get Sequence Count
	 *
	 * \return the telecommand's Sequence Count
	 */

	uint16_t GetSeqCount();

	/**
	 * \brief Get Packet Length
	 *
	 * \return the telecommand's Sequence Count
	 */

	uint16_t GetPackLength();

	/**
	 * \brief Get Ack from a telecommand's Data Field Header.
	 *
	 * \return the telecommand's Ack
	 */

	uint8_t GetAck();

	/**
	 * \brief Get Type from a telecommand's Data Field Header.
	 *
	 * \return the telecommand's type
	 */

	uint8_t GetType();

	/**
	 * \brief Get SubType from a telecommand's Data Field Header.
	 *
	 * \return the telecommand's subtype
	 */

	uint8_t GetSubType();

	/**
	 * \brief Get SourceID from a telecommand's Data Field Header.
	 *
	 * \return the telecommand's SourceID
	 */

	uint8_t GetSourceID();

	/**
	 * \brief Get the calculated telecommand's Pack Error Ctrl .
	 *
	 * \return the calculated telecommand's Pack Error Ctrl
	 */

	uint16_t GetCalculatedCRC();

	/**
	 * \brief Get telecommand's Pack Error Ctrl.
	 *
	 * \return the telecommand's Pack Error Ctrl
	 */

	uint16_t GetPacketErrorCtrl();

};

#endif

/*
 * \file	edroombp.h created for edroombp project
 * \brief
 *
 * \author	Alberto Carrasco Gallardo, <acarrasco@srg.aut.uah.es>
 *
 * \internal
 * Created: 	23-mar-2011
 * Compiler: 	gcc/g++
 * Company:  Space Research Group, Universidad de Alcal�.
 * Copyright: Copryright (c) 2011, Alberto Carrasco Gallardo
 *
 * For further information, please visit http://srg.aut.uah.es
 *
 * This software is provided under the terms of the GNU General Public v2
 * Licence. A full copy of the GNU GPL is provided in the file COPYING
 * found in the development root of ERCOS-RT project.
 *
 */

#ifndef _RTEMSAPI_RTEMS_4_6_EDROOMBP_H_
#define _RTEMSAPI_RTEMS_4_6_EDROOMBP_H_

/*global definitions*/
#include <rtems.h>
#include <stdio.h>

#include "public/config.h"
#include "../../edroomtypes.h"



#define EDROOMPrioWRAPPER   (EDROOMprioIDLE + 1)

#define GETPRIORITY(prio)   (EDROOMPrioWRAPPER - prio)

/*	EDROOM priorities	*/
enum TEDROOMPriority{
    EDROOMprioURGENT = 1,
    EDROOMprioVeryHigh,
    EDROOMprioHigh,
    EDROOMprioNormal,
    EDROOMprioLow,
    EDROOMprioVeryLow,
    EDROOMprioMINIMUM,
    EDROOMprioIDLE,
};

/**	Structure for time handling	*/
typedef struct
{
   uint32_t seconds;
   uint32_t microseconds;
}
EDROOMTimeSpec;

#define EDROOM_PRIO_MINIMUM EDROOMprioIDLE

typedef unsigned TEDROOMStackSizeType;


#define EDROOMClockTicksType uint32_t


typedef unsigned char EDROOMByte;
typedef void Pr_TaskRV_t;		/*return value of the test task*/
typedef uint32_t Pr_TaskP_t;			/*parameter passed to the task*/
typedef void Pr_IRQHandler_RetType;		/*	return type for IRQ handlers	*/

//*****************************************************


//********************************************************
//********************  Pr_Kernel  ***********************
//********************************************************

class Pr_Kernel
{
public:

    Pr_Kernel();
    ~Pr_Kernel(){};

    /**
     * Kernel start method
     *
     * This methos may be invoqued to start the kernel threads.
     */
    void Start();
};

//********************************************************
//********************  Pr_Semaphore  ********************
//********************************************************

class Pr_Time;
/**
 * \class Pr_Semaphore
 * \brief	semaphore class declaration
 */
class Pr_Semaphore
{

public:
    /**
     * Default constructor.
     *
     * \param _value :   This parameter is the semaphore counter value.
     *
     * The default semaphore value is 1.
     */
    Pr_Semaphore(uint32_t _value=0);

    /**
     * Semaphore Signal
     */
    void Signal();

    /**
     * Semaphore Wait
     */
    void Wait();

    /**
     * Semaphore conditional wait.
     *
     * The method catch the semaphore if it is possible. In any other case the
     * thread is not blocked.
     *
     * \return The method return 1 in case of the semaphore is catched. In any
     * other case the method returns 0.
     */
    int WaitCond();

    /**
     * \brief	the method try to catch the semaphore during a period of time.
     *	\param	interval	interval to wait
     * \return true if catched, false otherwise.
     */
    bool WaitTimed(const Pr_Time & interval);

    /**
     * Destructor
     */
    ~Pr_Semaphore(){
    }

};

//********************************************************
//********************  Pr_SemaphoreBin  *****************
//********************************************************

/**
 * \class Pr_SemaphoreBin
 * \brief	Binary semaphore class declaration
 */
class Pr_SemaphoreBin  :  public Pr_Semaphore
{

protected:
    /** This attribute is the class semaphore   */
	uint32_t sem;

public:

#ifdef _EDROOM_IS_DEBUG_

    const char *name;

    Pr_SemaphoreBin(char *p_name="semaphore", uint32_t _value = 0);

#else

    /**
     * Default Constructor.
     */
    Pr_SemaphoreBin(uint32_t _value = 0);

#endif

    /**
     * Semaphore Signal
     */
    void Signal();

    /**
     * Semaphore Wait
     */
    void Wait();

    /**
     * Semaphore conditional wait.
     *
     * The method catch the semaphore if it is possible. In any other case the
     * thread is not blocked.
     *
     * \return The method return 1 in case of the semaphore is catched. In any
     * other case the method returns 0.
     */
    int32_t WaitCond();

    /**
	 * \brief	the method try to catch the semaphore during a period of time.
	 *	\param	interval	interval to wait
	 *
	 * \return true if catched, false otherwise.
	 */
    bool WaitTimed(const Pr_Time & interval);

    /**
     * Default Destructor.
     *
     * The destructor destroys the semaphore.
     */
    ~Pr_SemaphoreBin();

};


//********************************************************
//********************  Pr_SemaphoreRec  *****************
//********************************************************

/**
 * \class Pr_SemaphoreRec
 * \brief	Resource semaphore class declaration
 */
class Pr_SemaphoreRec : public Pr_Semaphore
{
private:
    /** This attribute is the class mutex   */
    uint32_t mutex;

    /** Mutex attributes */
    uint32_t prio_type;
	uint32_t prio_ceiling;


public:

#ifdef _EDROOM_IS_DEBUG_

    const char * name;

    /** Default Debug constructor */
    Pr_SemaphoreRec(const char *name);

    /** Constructor for priority ceiling resource sempahore */
    Pr_SemaphoreRec(const char *name, int prioceiling);

#else

    /** Default constructor */
    Pr_SemaphoreRec();

    /** Constructor for priority ceiling resource sempahore */
    Pr_SemaphoreRec(int32_t prioceiling);

#endif

    /**
     * Semaphore signal.
     */
    void Signal(void);

    /**
     * Semaphore wait.
     */
    void Wait(void);

    /**
     * Semaphore conditional wait.
     *
     * The method catch the semaphore if it is possible. In any other case the
     * thread is not blocked.
     *
     * \return The method return 1 in case of the semaphore is catched. In any
     * other case the method returns 0.
     */
    int32_t WaitCond(void);

    /* Not implemented	*/
    int32_t WaitTimed(Pr_Time & interval);

    /**
     * Default Destructor
     */
    // POSIX
    ~Pr_SemaphoreRec();
};

#define Pr_Mutex Pr_SemaphoreRec
//********************************************************
//********************  Pr_Task  *************************
//********************************************************



class Pr_Task
{
/**
 * This method sends information to any other task.
 *
 * \param _task :     This is the receiver task.
 * \param _p_data :   This parameter is the data pointer to be sent.
 */
friend void Pr_Send(Pr_Task & task, void * p_data);

/**
 * This method receives a data from sent by other task.
 *
 * \param _ap_data :      This parameter is the pointer to the received data.
 * \param _datalength :   This parameter is the data length.
 */
friend void Pr_Receive(void * ap_data,unsigned datalength);

private:

    /** This member is the task identifier  */
	uint32_t taskID;

#ifdef _EDROOM_IS_DEBUG_

    /** This is the task name   */
    const char *name;

#endif


    /** Pointer to the data sent through Pr_Send method  */
    void  *p_data;

    //*************   SEMAPHORES *****************

    /**
     * This semaphore is used in the Pr_Send/Pr_Receive methods to synchronize
     * the sender and receiver threads
     */
   Pr_SemaphoreBin semSend;

    /**
     * This semaphore is used in the Pr_Send/Pr_Receive methods to synchronize
     * the sender and receiver threads
     */
   Pr_SemaphoreBin semReceive;

    /**
     * Change the task priority
     *
     * \param _priority :    This parameter is the task priority
     */
    void ChangePriority(TEDROOMPriority _priority);

    /**
     * This member is the IP task pointer.
     */
    Pr_TaskRV_t (*TaskIP)(Pr_TaskP_t);



    static Pr_TaskRV_t TaskFunction(Pr_TaskP_t arg);


protected:

    /**
     * Message priority.
     *
     * This is the message treatment priority
     */
    TEDROOMPriority priorityMsg;

    /**
     * Temporal priority.
     */
    TEDROOMPriority priorityTmp;

public:


#ifdef CONFIG_SWI_EDROOMBP_IFACE_V3_0_RTEMSAPI_4_8_IMPR_TESTING_METHODS
    /**
     * \brief return the identificator of the TASK
     * @return
     */
    uint32_t GetTaskID (){return taskID;}

#endif /* CONFIG_SWI_EDROOMBP_IFACE_V3_0_RTEMSAPI_4_8_IMPR_TESTING_METHODS */

    /**
     * \brief return the temp prio of the TASK
     * @return
     */
    TEDROOMPriority GetTmpTaskPrio();



    /**
     * Default Constructor
     */
    Pr_Task(){}

#ifdef _EDROOM_IS_DEBUG_

    /**
     * Debug Constructor
     *
     * \param _taskCode:    This parameter is the pointer to the task code
     * \param _p_name:      This parameter is the task name
     * \param _priority:    This parameter is the task priority
     * \param _stackSize:   This parameter is the task stack size
     *
     * The constructor creates a task. Assigns the needed stack size and the
     * IP code pointer to the task structure.
     */
    Pr_Task(Pr_TaskRV_t (*_taskCode)(Pr_TaskP_t), /*  Task IP */
            const char *_p_name,              /*  Task name   */
            TEDROOMPriority _priority,     /*  task priority   */
            unsigned _stackSize);       /*  stack size  */

#else

    /**
     * Debug Constructor
     *
     * \param _taskCode :    This parameter is the pointer to the task code
     * \param _priority :    This parameter is the task priority
     * \param _stackSize :   This parameter is the task stack size
     *
     * The constructor creates a task. Assigns the needed stack size and the
     * IP code pointer to the task structure.
     */
    Pr_Task(Pr_TaskRV_t (*_taskCode)(Pr_TaskP_t), /*  Task IP */
            TEDROOMPriority _priority,     /*  task priority   */
            unsigned _stackSize);       /*  stack size  */

#endif

    /**
     * This methos stablis the task priority
     *
     * \param _priority :    This parameter is the task priority
     */
    void SetPriority(TEDROOMPriority _priority);

    /**
     * This method modifies temporally the task priority.
     *
     * \param _priority :    the task priority
     *
     * The task priority is only modify when the priority pass argument is
     * greater than the current task priority. The attribute priorityTmp takes
     * the mayor value between the priority passed an its value.
     * The attribute priorityMsg is not modified.
     */
    void SetMaxPrioTmp(TEDROOMPriority _priority);

    /**
     * This method stablish the message treatment priority.
     *
     * \param _priority :    the task priority
     *
     * The priorityMsg attribute is modified only if the priority passed
     * argument is greater than priorityMsg.
     * The attributes priorityMsg and priorityTmp takes the greater value
     * between these and the priority passed argument.
     */
    void SetMaxPrioMsg(TEDROOMPriority _priority);

    /**
     * This method restores the task priority to the message priority.
     *
     * The method is invoked after been modified the temporal priority task
     * (priorityTmp). The priorityTmp takes the priorityMsg value to maintain
     * the coherence between the real priority task and the priorityTmp value.
     */
    void RestorePrioMsg(void);

    /**
     * Returns the task priority
     *
     * \return This method returns the current task priority.
     */
    TEDROOMPriority GetTaskPrio();

    /**
     * Defaul Destructor
     */
    ~Pr_Task(){}
};

void Pr_Send(Pr_Task &task, void *p_data);
void Pr_Receive(void * ap_data,unsigned datalength);

//********************************************************
//********************  Pr_Time  *************************
//********************************************************

/**
 * \class Pr_Time
 *
 * \brief   This class implements the time EDROOM time management.
 *
 * The class allows to modify the time, set absolute and relative delays and
 * work with the time in many units.
 */
class Pr_Time
{
friend class Pr_Kernel;
friend class Pr_SemaphoreBin;
friend class Pr_IRQEvent;

public:
    /** This enumeration declares all the time units */
    enum unit {/** Time ticks  */
        ticks,
        /** Microseconds    */
        micros,
        /** Milliseconds    */
        millis,
        /** Seconds */
        secns,
        /** Minutes */
        mints
    };

private:

    /** This parameter stores the system time    */
	EDROOMTimeSpec time;

public:

    /**
     * Default Constructor
     */
    Pr_Time();

    /**
     * Constructor.
     *
     * \param   _time	the time value
     *
     * The constructor inits the object with the time value and units passed
     * as parameters.
     */

    Pr_Time(EDROOMTimeSpec _time);

    /**
	 * Constructor.
	 *
	 * \param   _secs	the seconds value
	 *	\param   _usecs	the microseconds value
	 * The constructor inits the object with the time value and units passed
	 * as parameters.
	 */

	Pr_Time(uint32_t _secs, uint32_t _usecs);


    /**
     * Constructor.
     *
     * \param   _time :  This parameter is a Pr_Time object used to init the
     * current object.
     *
     * This contructor inits the current object with the same value of the object
     * passed as parameter.
     */
    Pr_Time(const Pr_Time & _time);

    /**
     * \brief	Relative Delay method.
     *
     * \param   _delay :  This parameter is the time delay
     *
     * The method sleeps the caller task during the delay passed as parameter.
     */
    friend void Pr_DelayIn( const Pr_Time & _delay);

    /**
     * \brief	Absolute Delay method.
     *
     * \param   _time :  This parameter is the time to be awaked
     *
     * The method sleeps the caller. The system awake the task at the specified
     * time  (_time)
     */
    friend void Pr_DelayAt( const Pr_Time & _time);

    /**
     * Get the current system time.
     *
     * This method stores in the _time object the current system time.
     */
    void GetTime(void);

    /**
     * + Operator overload
     *
     * \param   _time :  This parameter is the time structure.
     */
    Pr_Time& operator+=(const Pr_Time& _time);

    /**
     * - Operator overload
     *
     * \param   _time :  This parameter is the time structure.
     */
    Pr_Time& operator-=(const Pr_Time& _time);

    /**
     * = operator overload
     *
     * \param   _time :  This parameter is the time structure.
     */
    Pr_Time& operator=(const Pr_Time& _time);

    /**
     * == operator overload
     *
     * \param   _time :  This parameter is the time structure.
     */
    int operator==(const Pr_Time& _time);

    /**
     * != operator overload
     *
     * \param   _time :  This parameter is the time structure.
     */
    int operator!=(const Pr_Time & _time);

    /**
     * > operator overload
     *
     * \param   _time :  This parameter is the time structure.
     */
    int operator>(const Pr_Time& _time);

    /**
     * < operator overload
     *
     * \param   _time :  This parameter is the time structure.
     */
    int operator<(const Pr_Time& _time);

    /**
     * >= operator overload
     *
     * \param   _time :  This parameter is the time structure.
     */
    int operator>=(const Pr_Time& _time);

    /**
     * <= operator overload
     *
     * \param   _time :  This parameter is the time structure.
     */
    int operator<=(const Pr_Time& _time);

    /**
     * Value of the system clock in ticks
     *
     * \return This method returns the value of the system clock in ticks.
     */
    uint32_t Ticks() const;

    /**
    * Round up or down to the closer ticks
    */
    void RoudMicrosToTicks();


    /**
     * Value of the system clock in ticks
     *
     * \return This method returns the value of the system clock in ticks.
     */
    uint32_t Secns() const {return time.seconds;}

    /**
      * Value of the system clock in ticks
      *
      * \return This method returns the value of the system clock in ticks.
      */
    EDROOMTimeSpec TimeSpec() const {return time;}


    /**
     *
     */
    EDROOMClockTicksType GetTicks();



};

//********************************************************
//********************  Pr_IRQManager ********************
//********************************************************

/** Interrupt handler routine prototype */
typedef void (* Pr_IRQHandler) (void);

typedef uint8_t TEDROOMIRQMask;

class Pr_IRQManager{


public:

 	/*!
 	 * \brief Set a new IRQ Mask
 	 * @param irqMask
 	 */
	static inline void NewIRQMask(TEDROOMIRQMask irqMask) {};

 	/*!
     * \brief Get the current IRQ Mask
     *
     */
	static inline TEDROOMIRQMask GetIRQMask(void) { return 0; };

    /*!
     * \brief This method disables all interrupts but does not change the IRQ
     * mask
     */
	static void DisableAllIRQs(void);

    /*!
     * \brief This method disables all interrupts but does not change the IRQ
     * mask
     */
	static void EnableAllIRQs(void);

    /*!
     * \brief This method apply the curent IRQ Mask that was in NewIRQMask
     */
	static void ApplyCurrentIRQMask(void);

    /*!
     * \brief This method installs a user interrupt service routine
     * @param handler	pointer to the handler
     * @param IRQLevel	level of the IRQ
     * @param IRQVectorNumber number of the IRQ
     */
	static void InstallIRQHandler(Pr_IRQHandler handler,
                        uint8_t IRQLevel,
                        uint8_t IRQVectorNumber );

    /*!
     * \brief This method deinstall therestore the original service routines
     * @param IRQLevel level of the IRQ
     * @param IRQVectorNumber number of the IRQ
     */
	static void DeinstallIRQHandler(unsigned char IRQLevel
   											,unsigned char IRQVectorNumber);


    /**
     * Prologue hook for an interrupt handler
     *
     * This method must be called from the first line of an application-defined
     * interrupt service routine.  Its implementation may call (if needed) to
     * to the kernel isr prologue.
     *
     * Note that, for the EDROOMBP implementation over ERCOS, this is a dummy
     * method
     */
    static inline void HandlerEntry (void) {};

    /**
     * Epilogue hook for an interrupt handler
     *
     * This method must be called from the last line of an application-defined
     * interrupt service routine.  Its implementation may call (if needed) to
     * to the kernel isr prologue.
     *
     * Note that, for the EDROOMBP implementation over ERCOS, this is a dummy
     * method
     */
    static inline void HandlerExit (void) {};
    /**
     * \brief	 Mask an IRQ
     * @param IRQVectorNumber	the number of IRQ
     */
    static void MaskIRQ(uint32_t IRQVectorNumber);
    static void DisableIRQ(uint32_t IRQVectorNumber){ MaskIRQ(IRQVectorNumber);}

    /**
     * \brief	UnMask an IRQ
     * @param IRQVectorNumber the number of IRQ
     */
    static void UnMaskIRQ(uint32_t IRQVectorNumber);
    static void EnableIRQ(uint32_t IRQVectorNumber){UnMaskIRQ(IRQVectorNumber);}

};

//********************************************************
//********************  Pr_IRQEvent **********************
//********************************************************

/**
 * \class Pr_IRQEvent
 * This class implements the event handling. The class allows the threads
 * waitting for an interrupt event with the Wait methods.
 * The irq handlers will also signal the event to propagate it to the waiting
 * threads.
 */

class Pr_IRQEvent{

private:
	uint32_t irq_event;
	uint32_t caller_task_id;

public:

#ifdef _EDROOM_IS_DEBUG_

    const char *name;

    /**
     * Debug Constructor.
     *
     * \param name: This parameter is the irq event name.
     * \param IRQ:  This parameter is the IRQ vector number.
     */
    Pr_IRQEvent(const char * name,unsigned char IRQ);

#else

    /**
     * Constructor.
     *
     * \param IRQ :  This parameter is the IRQ vector number.
     */
    Pr_IRQEvent(unsigned char IRQ);

#endif

    /**
     * Signal event.
     *
     * This method signals the bottom half of an interrupt. The signaling provokes the event
     * propagation to the waiting threads.
     */
    void Signal();

    /**
     * Signal event from a Task.
     *
     * This method signals the bottom half of an interrupt. The signaling provokes the event
     * propagation to the waiting threads.
     */
    void SignalFromTask(){Signal();}
    /**
     * Wait for an event.
     *
     * This method allows threads to wait for an interrupt event.
     */
    void Wait();

    /**
     * Conditional Wait for an event.
     *
     * This method allows threads to wait for an interrupt event.
     */
    bool_t WaitCond();

    /**
     * Timed Waitting for an event.
     *
     * This method allows threads to wait for an interrupt event for a time.
     * \param time interval to wait.
     */
    bool_t WaitTimed(Pr_Time time);

};
//********************************************************
//********************  Pr_Trace **********************
//********************************************************

/**
 * \class Pr_Trace. This class allows the upper layers to generate trace
 * information
 */


#ifdef CONFIG_EDROOMBP_SWR_TRACE_METHODS
class Pr_Trace {
private:
	uint32_t evid;

	void trace (const uint64_t & val);
	void trace (const uint32_t & val);
	void trace (const int32_t & val);
	void trace (const float & val);

public:

	Pr_Trace (void);
	Pr_Trace (const char * str);
	Pr_Trace (const char * str, unsigned level);

	void open (const char * str, unsigned level);
	void close (void);

	Pr_Trace &operator << (const char * str);
	Pr_Trace &operator << (uint64_t & val);
	Pr_Trace &operator << (uint32_t val);
	Pr_Trace &operator << (int32_t & val);
	Pr_Trace &operator << (uint16_t & val);
	Pr_Trace &operator << (uint8_t & val);
	Pr_Trace &operator << (float & val);
};

extern Pr_Trace Pr_deb;
extern Pr_Trace Pr_err;

#endif


#endif	/*_RTEMSAPI_RTEMS_4_6_EDROOMBP_H_*/


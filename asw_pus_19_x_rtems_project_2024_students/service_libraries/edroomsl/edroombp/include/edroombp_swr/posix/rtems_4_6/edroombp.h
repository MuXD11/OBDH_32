/*
    Copyright 2004-2005 (c) by Aitor Viana Sanchez,
    University of Alcala,
    Computer Engineering Department.

    For further information, please visit http://atc1.aut.uah.es

    This software is provided under the terms of the GNU General Public v2
    Licence. A full copy of the GNU GPL is provided in the file COPYING
    found in the development root of ERCOS-RT.
*/

#ifndef _POSIX_RTEMS_EDROOM_BP_H_
#define _POSIX_RTEMS_EDROOM_BP_H_

#include <public/edroomdf.h>
#include <edroomtc/edroomtc.h>
#include <public/posix.h>
#include "../../../../../edroombp/include/edroombp_swr/edroomtypes.h"	/* data types uintXX_t */


#define EDROOMPrioWRAPPER   (EDROOMprioIDLE + 1)

#define GETPRIORITY(prio)   (EDROOMPrioWRAPPER - prio)

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

#define EDROOM_PRIO_MINIMUM EDROOMprioIDLE

typedef unsigned TEDROOMStackSizeType;

#define EDROOMClockTicksType unsigned int

#define _EDROOM_MainMustWait
#define _EDROOM_TASK_POSIX_

typedef unsigned char EDROOMByte;
#define Pr_TaskRV_t void		/*return value of the test task*/
#define Pr_TaskP_t  void		/*parameter passed to the task*/
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

    //TODO metodo panic añadido.
    /** Kernel panic.  This method will halt the system */
    static void Panic (const char * msg);
};

//********************************************************
//********************  Pr_Semaphore  ********************
//********************************************************

class Pr_Time;
/**
 * \class Semaphore class declaration
 */
class Pr_Semaphore
{

public:
    /**
     * \todo Default constructor.
     *
     * \param _value:   This parameter is the semaphore counter value.
     *
     * The default semaphore value is 1.
     */
    Pr_Semaphore(unsigned int _value=0);

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
     * \todo Documentar este método
     */
    bool WaitTimed(const Pr_Time &);

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
 * \class Binary semaphore class declaration
 */
class Pr_SemaphoreBin  :  public Pr_Semaphore
{

protected:
    /** This attribute is the class mutex   */
    sem_t sem;

public:

#ifdef _EDROOM_IS_DEBUG_

    const char *name;

    Pr_SemaphoreBin(const char *p_name="semaphore", uint32_t _value = 0);

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
    int WaitCond();

    /**
     * \todo Documentar este método
     */
    bool WaitTimed(const Pr_Time &);

    /**
     * Default Destructor.
     *
     * The destructor destroys the semaphore.
     */
    ~Pr_SemaphoreBin()
    {
        sem_destroy(&sem);
    }

};


//********************************************************
//********************  Pr_SemaphoreRec  *****************
//********************************************************

/**
 * \class Resource semaphore class declaration
 */
class Pr_SemaphoreRec : public Pr_Semaphore
{
private:
    /** This attribute is the class mutex   */
    pthread_mutex_t mutex;

    /** This attribute is the mutex attr    */
    pthread_mutexattr_t attr;


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
    Pr_SemaphoreRec(int prioceiling);

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
    int WaitCond(void);

    /**
     * \todo Documentar este m�todo
     * \todo Implementar este m�todo
     */
    int WaitTimed(Pr_Time &_time);

    /**
     * Default Destructor
     */
    ~Pr_SemaphoreRec(){pthread_mutex_destroy(&mutex);}
};

//********************************************************
//********************  Pr_Task  *************************
//********************************************************



class Pr_Task
{
/**
 * This method sends information to any other task.
 *
 * \param task:     This is the receiver task.
 * \param p_data:   This parameter is the data pointer to be sent.
 */
friend void Pr_Send(Pr_Task &task, void *p_data);

/**
 * This method receives a data from sent by other task.
 *
 * \param ap_data:      This parameter is the pointer to the received data.
 * \param datalenght:   This parameter is the data length.
 */
friend void Pr_Receive(void * ap_data,unsigned datalength);

private:

    /** This member is the task identifier  */
    pthread_t   taskID;

#ifdef _EDROOM_IS_DEBUG_

    /** This is the task name   */
    const char *name;

#endif

    /** This is the thread attributes defined in <sys/types.h<   */
    pthread_attr_t attr;

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
     * \param _priority:    This parameter is the task priority
     */
    void ChangePriority(TEDROOMPriority _priority);

    /**
     * This member is the IP task pointer.
     */
    Pr_TaskRV_t (*TaskIP)(Pr_TaskP_t);

    static void *TaskFunction(void *arg);

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
    Pr_Task(void (*_taskCode)(void), /*  Task IP */
            const char *_p_name,              /*  Task name   */
            TEDROOMPriority _priority,     /*  task priority   */
            unsigned _stackSize);       /*  stack size  */

#else

    /**
     * Debug Constructor
     *
     * \param _taskCode:    This parameter is the pointer to the task code
     * \param _priority:    This parameter is the task priority
     * \param _stackSize:   This parameter is the task stack size
     *
     * The constructor creates a task. Assigns the needed stack size and the
     * IP code pointer to the task structure.
     */
    Pr_Task(void (*_taskCode)(void), /*  Task IP */
            TEDROOMPriority _priority,     /*  task priority   */
            unsigned _stackSize);       /*  stack size  */

#endif

    /**
     * This methos stablis the task priority
     *
     * \param _priority:    This parameter is the task priority
     */
    void SetPriority(TEDROOMPriority _priority);

    /**
     * This method modifies temporally the task priority.
     *
     * \param _priority:    the task priority
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
     * \param _priority:    the task priority
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
    struct timespec time;

public:

    /**
     * Default Constructor
     */
    Pr_Time();

    /**
     * Constructor.
     *
     * \param   _unit:  This parameter is the time unit.
     * \param   _value: This parameter is the time value.
     *
     * The constructor inits the object with the time value and units passed
     * as parameters.
     */
    Pr_Time(struct timespec _time);

    /**
     * Constructor.
     *
     * \param   _seconds:   This parameter is the time value in seconds.
     *
     * This constructor inits the object with the time value expressed in
     * seconds.
     */
    Pr_Time(float _seconds);

    /**
     * Constructor.
     *
     * \param   _time:  This parameter is a Pr_Time object used to init the
     * current object.
     *
     * This contructor inits the current object with the same value of the object
     * passed as parameter.
     */
    Pr_Time(const Pr_Time &_time);

    /**
     * \todo Comentar este constructor
     */
    Pr_Time(Pr_Time::unit _units, uint32_t _measure);

    /**
     * Relative Delay method.
     *
     * \param   _delay:  This parameter is the time delay
     *
     * The method sleeps the caller task during the delay passed as parameter.
     */
    friend void Pr_DelayIn( const Pr_Time &_delay);

    /**
     * Absolute Delay method.
     *
     * \param   _time:  This parameter is the time to be awaked
     *
     * The method sleeps the caller. The system awake the task at the specified
     * time  (_time)
     */
    friend void Pr_DelayAt( const Pr_Time &_time);

    /**
     * Get the current system time.
     *
     * This method stores in the _time object the current system time.
     */
    void GetTime(void);

    /**
     * + Operator overload
     *
     * \param   _time:  This parameter is the time structure.
     */
    Pr_Time& operator+=(const Pr_Time& _time);

    /**
     * - Operator overload
     *
     * \param   _time:  This parameter is the time structure.
     */
    Pr_Time& operator-=(const Pr_Time& _time);

    /**
     * = operator overload
     *
     * \param   _time:  This parameter is the time structure.
     */
    Pr_Time& operator=(const Pr_Time& _time);

    /**
     * == operator overload
     *
     * \param   _time:  This parameter is the time structure.
     */
    int operator==(const Pr_Time& _time);

    /**
     * != operator overload
     *
     * \param   _time:  This parameter is the time structure.
     */
    int operator!=(const Pr_Time & _time);

    /**
     * > operator overload
     *
     * \param   _time:  This parameter is the time structure.
     */
    int operator>(const Pr_Time& _time);

    /**
     * < operator overload
     *
     * \param   _time:  This parameter is the time structure.
     */
    int operator<(const Pr_Time& _time);

    /**
     * >= operator overload
     *
     * \param   _time:  This parameter is the time structure.
     */
    int operator>=(const Pr_Time& _time);

    /**
     * <= operator overload
     *
     * \param   _time:  This parameter is the time structure.
     */
    int operator<=(const Pr_Time& _time);

    /**
     * This routine adds time to the Pr_Time object
     *
     * \param seconds:  This parameter is the number of seconds that must be
     * added.
     *
     * \return The routine does not return anything
     */
    void Add(float seconds);

    /**
     * Value of the system clock in minutes
     *
     * \return This method returns the value of the system clock in minutes.
     */
    float Mints() const;

    /**
     * Value of the system clock in seconds
     *
     * \return This method returns the value of the system clock in seconds.
     */
    float Secns() const;

    /**
     * Value of the system clock in milliseconds
     *
     * \return This method returns the value of the system clock in milliseconds.
     */
    float Millis() const;

    /**
     * Value of the system clock in ticks
     *
     * \return This method returns the value of the system clock in ticks.
     */
    float Ticks() const;

    /**
     * Value of the system clock in microseconds
     *
     * \return This method returns the value of the system clock in microseconds.
     */
    float Micros() const;

    /**
     * \todo Implementar este método si hace falta.
     */
    static float period();

    /**
     * \todo Implementar este método si hace falta.
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
     */
	static inline void NewIRQMask(TEDROOMIRQMask irqMask) {};

 	/*!
     * \brief Get the current IRQ Mask
     * \todo
     */
	static inline TEDROOMIRQMask GetIRQMask(void) { return 0; };

    /*!
     * \brief This method disables all interrupts but does not change the IRQ
     * mask
     */
	static void DisableAllIRQs(void);

    /*!
     * \brief This method apply the curent IRQ Mask that was in NewIRQMask
     */
	static void ApplyCurrentIRQMask(void);

    /*!
     * \brief This method installs a user interrupt service routine
     */
	static void InstallIRQHandler(Pr_IRQHandler handler,
                        uint8_t IRQLevel,
                        uint8_t IRQVectorNumber );

    /*!
     * \brief This method deinstall therestore the original service routines
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

    static void DisableIRQ(uint32_t IRQVectorNumber);

    static void EnableIRQ(uint32_t IRQVectorNumber);

};

//********************************************************
//********************  Pr_IRQEvent **********************
//********************************************************

/**
 * \class Pr_IRQEvent. This class implements the event handling.
 *
 * The class allows the threads waitting for an interrupt event with the
 * Wait methods.
 * The irq handlers will also signal the event to propagate it to the waiting
 * threads.
 */

class Pr_IRQEvent{

private:
    Pr_SemaphoreBin eventSem;

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
     * \param IRQ:  This parameter is the IRQ vector number.
     */
    Pr_IRQEvent(unsigned char IRQ);

#endif

    /**
     * Signal event.
     *
     * This method signals an interrupt. The signaling provokes the event
     * propagation to the waiting threads.
     */
    void Signal();

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
    bool WaitCond();

    /**
     * Timed Waitting for an event.
     *
     * This method allows threads to wait for an interrupt event for a time.
     */
    bool WaitTimed(Pr_Time time);

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


#endif	/*_POSIX_RTEMS_EDROOM_BP_H_*/


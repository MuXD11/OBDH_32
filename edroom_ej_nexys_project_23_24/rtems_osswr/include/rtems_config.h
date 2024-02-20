/*
 * \file	rtems_config.h created for pelican_drv_ping_pong_ut_master_mmesp_project project
 * \brief
 *	
 * \author	Alberto Carrasco Gallardo, <acarrasco@srg.aut.uah.es>
 * \author	Oscar Rodriguez Polo, <opolo@srg.aut.uah.es>
 * 
 * \internal
 * Created: 	23/05/2011
 * Compiler: 	gcc/g++
 * Company:  Space Research Group, Universidad de Alcala.
 * Copyright: Copryright (c) 2011, Alberto Carrasco Gallardo
 * 								   Oscar Rodriguez Polo
 *
 *
 * For further information, please visit http://srg.aut.uah.es
 *
 * This software is provided under the terms of the GNU General Public v2
 * Licence. A full copy of the GNU GPL is provided in the file COPYING
 * found in the development root of the project.
 * 	
 */

#ifndef RTEMS_CONFIG_H_
#define RTEMS_CONFIG_H_


#include <public/config.h>
#include <rtems.h>

//void *POSIX_Init (void *arg);
rtems_task Init(uint32_t arg);
//******************* RTEMS CONFIGURATION ***********************

//*************** RTEMS DRIVERS CONFIGURATION *******************
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_MICROSECONDS_PER_TICK	CONFIG_PLATFORM_RTEMS_USECS_PER_TICK
//#define CONFIGURE_TICKS_PER_TIMESLICE           10

//**************** END DRIVERS CONFIGURATION ********************




//#define CONFIGURE_RTEMS_INIT_TASK_TABLE
#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

//*********** RTEMS FILESYSTEM  CONFIGURATION *******************

//Maiximum number of files that can be concurrently opened
//#define CONFIGURE_LIBIO_MAXIMUM_FILE_DESCRIPTORS    10
//#undef CONFIGURE_LIBIO_MAXIMUM_FILE_DESCRIPTORS
//#define CONFIGURE_NUMBER_OF_TERMIOS_PORTS           2
//#undef CONFIGURE_NUMBER_OF_TERMIOS_PORTS
//the application wishes to use the full functionality of the IMFS
#undef CONFIGURE_USE_IMFS_AS_BASE_FILESYSTEM

//*********** END FILESYSTEM  CONFIGURATION *******************

// Stack checker
//#define STACK_CHECKER_ON

//*********** RTEMS OS CONFIGURATION *******************
//#define CONFIGURE_EXECUTIVE_RAM_SIZE	    (128*1024)
#define CONFIGURE_MAXIMUM_SEMAPHORES	    (CONFIG_RTEMS_OSSWR_DEMANDED_SEM + 25)
#define CONFIGURE_MAXIMUM_TASKS		        (CONFIG_RTEMS_OSSWR_DEMANDED_TASKS + 25)
#define CONFIGURE_EXTRA_TASK_STACKS         (25 * RTEMS_MINIMUM_STACK_SIZE)

//#define CONFIGURE_MAXIMUM_TIMERS            2
//#define CONFIGURE_MAXIMUM_MESSAGE_QUEUES    0



// it is the stack size of the single initialization task defined
// by the Classic API initialization TAsk Table
#define CONFIGURE_INIT_TASK_STACK_SIZE	(64*1024)
#define CONFIGURE_INIT_TASK_PRIORITY	  100
#define CONFIGURE_INIT_TASK_INITIAL_MODES (RTEMS_PREEMPT | \
                                           RTEMS_NO_TIMESLICE | \
                                           RTEMS_NO_ASR | \
                                           RTEMS_INTERRUPT_LEVEL(0))

//******************* END RTEMS CONFIGURATION ***********************

#define CONFIGURE_INIT

#include <bsp.h>
#include <confdefs.h>
#include <stdio.h>


/* Esto no se para que vale, lo tenian en el ejemplo. Yo lo he quitado
 * y sigue funcionando */
//TEST_EXTERN pthread_t Init_id;
//TEST_EXTERN pthread_t Task_id;

#endif /* RTEMS_CONFIG_H_ */

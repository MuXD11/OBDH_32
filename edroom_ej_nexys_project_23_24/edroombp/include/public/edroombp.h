#ifndef _PUBLIC_EDROOMBP_H_
#define _PUBLIC_EDROOMBP_H_

#include <public/config.h>

#ifdef CONFIG_OSAPI_POSIX
	#ifdef CONFIG_OS_ERCOS
		#include "../../../edroombp/include/edroombp_swr/posix/ercos_v1/edroombp.h"
	#endif
	#ifdef CONFIG_OS_RTEMS
		#include "../../../edroombp/include/edroombp_swr/posix/rtems_4_6/edroombp.h"
	#endif
	#ifdef CONFIG_OS_LINUX
		#include "../../../edroombp/include/edroombp_swr/posix/linux_2_6/edroombp.h"
	#endif
#endif
#ifdef CONFIG_OSAPI_RTEMSAPI
	#include	"../../../edroombp/include/edroombp_swr/rtemsapi_4_6/rtems_4_6/edroombp.h"
#endif


#endif


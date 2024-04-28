#ifndef INCLUDE__TMTC_POOL__H_
#define INCLUDE__TMTC_POOL__H_

#include <rtems.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initializes the TM/TC pool static structures.
 */
rtems_status_code init_tmtc_pool();

/**
 * \brief Allocates a new block from the memory pool.
 *
 * @return The address of the allocated block or NULL if there were no free
 *         blocks in the pool.
 */
uint8_t * tmtc_pool_alloc();

/**
 * \brief Frees a previously allocated block of the memory pool.
 *
 * @param p_block the address of the block to deallocate.
 */
void tmtc_pool_free(uint8_t * p_block);

#ifdef __cplusplus
}
#endif


#endif /* INCLUDE__TMTC_POOL__H_ */

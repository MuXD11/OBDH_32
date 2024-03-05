#ifndef INCLUDE__TM_DESCRIPTOR__H_
#define INCLUDE__TM_DESCRIPTOR__H_


/**
 * \brief Structure that stores a single TM descriptor. It contains a pointer
 *        to the allocated memory that stores the TM packet and the number of
 *        bytes that are actually in use by the TM packet.
 */
struct tm_descriptor {

    uint8_t * p_tm_bytes;
    uint16_t tm_num_bytes;

};

typedef struct tm_descriptor tm_descriptor_t;


#endif /* INCLUDE__TM_DESCRIPTOR__H_ */

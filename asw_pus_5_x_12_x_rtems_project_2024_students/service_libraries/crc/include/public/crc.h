#ifndef INCLUDE__CRC_H_
#define INCLUDE__CRC_H_

#include "public/basic_types.h"

#ifdef __cplusplus
extern "C" {
#endif

uint16_t cal_crc_16(uint8_t data[], uint16_t nbytes);

#ifdef __cplusplus
}
#endif

#endif

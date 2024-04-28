#include "public/crc.h"

uint16_t cal_crc_16(uint8_t data[], uint16_t nbytes) {

    uint16_t crc_value = 0xFFFF;

    for (uint16_t i = 0; i < nbytes; i++ ) {

        crc_value = crc_value ^ (data[i] << 8);

        for (uint8_t j = 0; j < 8; j++) {

            if ((crc_value & 0x8000) != 0) {
                crc_value = (crc_value << 1) ^ 0x1021;
            } else {
                crc_value = crc_value << 1;
            }
        }
    }

    return crc_value;
}

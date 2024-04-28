#ifndef INCLUDE__CCSDS_PUS_FORMAT_H_
#define INCLUDE__CCSDS_PUS_FORMAT_H_

#include "public/basic_types.h"


/**
 * \brief Structure type to the Packet Header field of a TM/TC packet.
 */

struct ccsds_pus_tmtc_packet_header {

    uint16_t packet_id;
    uint16_t packet_seq_ctrl;
    uint16_t packet_length;

};

/**
 * \brief Structure type to store the Data Field Header field of a TC packet.
 */
struct ccsds_pus_tc_df_header {

    uint8_t flag_ver_ack;
    uint8_t type;
    uint8_t subtype;
    uint8_t sourceID;

};

/**
 * \brief Structure type to store the Data Field Header field of a TM packet.
 */
struct ccsds_pus_tm_df_header {

    uint8_t version;
    uint8_t type;
    uint8_t subtype;
    uint8_t destinationID;

};

/**
 * \brief Get APID from a telecommand's Packet ID.
 *
 * \param tc_packet_id the telecommand's Packet ID
 *
 * \return the telecommand's APID
 */
#define ccsds_pus_tc_get_APID(tc_packet_id) ((tc_packet_id) & 0x07FF)

/**
 * \brief Get Sequence Count from a telecommand's Packet Sequence Control.
 *
 * \param tc_packet_seq_ctrl the telecommand's Packet Sequence Control
 *
 * \return the telecommand's Sequence Flags
 */
#define ccsds_pus_tc_get_seq_flags(tc_packet_seq_ctrl) (((tc_packet_seq_ctrl) & 0xC000) >> 14)

/**
 * \brief Get Sequence Count from a telecommand's Packet Sequence Control.
 *
 * \param tc_packet_seq_ctrl the telecommand's Packet Sequence Control
 *
 * \return the telecommand's Sequence Count
 */
#define ccsds_pus_tc_get_seq_count(tc_packet_seq_ctrl) ((tc_packet_seq_ctrl) & 0x3FFF)

/**
 * \brief Get Ack from a telecommand's Data Field Header.
 *
 * \param tc_df_header the telecommand's Data Field Header
 *
 * \return the telecommand's Ack
 */
#define ccsds_pus_tc_get_ack(flag_ver_ack) ((flag_ver_ack) & 0x0F)

/**
 * \brief Deserializes the fields of a telecommand stored in a vector
 *
 * \param tc_bytes vector that stores the bytes of the telecommand
 * \param p_tc_packet_header pointer to the struct that shall store the Packet
 *          Header
 * \param p_tc_df_header pointer to the struct that shall store the Data Field
 *                    Header
 * \param p_tc_packet_err_ctrl pointer to the variable that shall store the
 *                          Packet Error Control
 */
void ccsds_pus_tc_get_fields(uint8_t tc_bytes[],
                        struct ccsds_pus_tmtc_packet_header * p_tc_packet_header,
                        struct ccsds_pus_tc_df_header * p_tc_df_header,
                        uint16_t * p_tc_packet_err_ctrl);

/**
 * \brief Builds the Packet ID of a telmetry.
 *
 * \param apid the value of the APID subfield
 *
 * \return the Packet ID field
 */
#define ccsds_pus_tm_build_packet_id(apid) ((1 << 11) | ((apid) & 0x07FF))

/**
 * \brief Builds the Packet Sequence Control of a telmetry.
 *
 * \param flags the value of the Sequence Flags subfield
 * \param count the value of the Sequence Count subfield
 *
 * \return the Packet Sequence Control field
 */
#define ccsds_pus_tm_build_packet_seq_ctrl(flags, count) \
    ((((flags) & 0x3) << 14) | ((count) & 0x3FFF))

/**
 * \brief Builds the most significant byte of the Data Field Header of a telmetry.
 *
 * \param version the value of the Version subfield
 *
 * \return the MSB of the Data Field Header
 */
#define ccsds_pus_tm_build_df_header_version(version) (((version) & 0xF) << 4)

/**
 * \brief Serializes and stores into a vector the main fields of a TM packet.
 *
 * \param tm_bytes vector that will store the generated serialized telemetry
 * \param p_tm_packet_header const pointer to the struct that defines the
 *                           Packet Header
 * \param p_tm_df_header the const pointer to the struct that defines the
 *                           TM Data Field Header
 */
void ccsds_pus_tm_set_fields(uint8_t tm_bytes[],
                        const struct ccsds_pus_tmtc_packet_header * p_tm_packet_header,
                        const struct ccsds_pus_tm_df_header * p_tm_df_header);

#endif /* INCLUDE_CCSDS_PUS_FORMAT_H_ */

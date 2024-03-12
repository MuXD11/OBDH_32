#include "public/ccsds_pus.h"
#include "public/serialize.h"

void ccsds_pus_tc_get_fields(uint8_t tc_bytes[],
        struct ccsds_pus_tmtc_packet_header * p_tc_packet_header,
        struct ccsds_pus_tc_df_header * p_tc_df_header,
        uint16_t * p_tc_packet_err_ctrl) {

    // Deserialize Packet ID and store it into field packet_id
    p_tc_packet_header->packet_id = deserialize_uint16(&tc_bytes[0]);

    // Deserialize Packet Seq. Control and store it into field packet_seq_ctrl
    p_tc_packet_header->packet_seq_ctrl = deserialize_uint16(&tc_bytes[2]);

    // Deserialize Packet Seq. Control and store it into field packet_length
    p_tc_packet_header->packet_length = deserialize_uint16(&tc_bytes[4]);

    // Deserialize Data Field Header

    // Read the MSB of the Data Field Header and store it into flag_ver_ack
    p_tc_df_header->flag_ver_ack = tc_bytes[6];

    // Read the remaining fields of the Data Field Header into the struct
    p_tc_df_header->type = tc_bytes[7];
    p_tc_df_header->subtype = tc_bytes[8];
    p_tc_df_header->sourceID = tc_bytes[9];

    // Deserialize Packet Error Control and store it at p_tc_packet_err_ctrl
    *p_tc_packet_err_ctrl = deserialize_uint16(
            &tc_bytes[p_tc_packet_header->packet_length + 5]);

}

void ccsds_pus_tm_set_fields(uint8_t tm_bytes[],
        const struct ccsds_pus_tmtc_packet_header * p_tm_packet_header,
        const struct ccsds_pus_tm_df_header * p_tm_df_header) {

    serialize_uint16(p_tm_packet_header->packet_id, &tm_bytes[0]);

    // Serialize Packet Sequence Control from packet_seq_ctrl
    serialize_uint16(p_tm_packet_header->packet_seq_ctrl, &tm_bytes[2]);

    // Serialize Packet Length from packet_length
    serialize_uint16(p_tm_packet_header->packet_length, &tm_bytes[4]);

    // Store version field into the corresponding byte
    tm_bytes[6] = p_tm_df_header->version;

    // Store the remaining fields into their respective locations
    tm_bytes[7] = p_tm_df_header->type;
    tm_bytes[8] = p_tm_df_header->subtype;
    tm_bytes[9] = p_tm_df_header->destinationID;

}

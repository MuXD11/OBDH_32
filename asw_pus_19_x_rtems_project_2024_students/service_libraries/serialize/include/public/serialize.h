#ifndef INCLUDE__SERIALIZE_H_
#define INCLUDE__SERIALIZE_H_

#include "public/config.h"
#include "public/basic_types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * \brief Deserializes a 16-bit integer
 *
 * \param data_bytes vector containing the MSB and LSB bytes of the word
 *
 * \return the deserialized 16-bit integer
 */
uint16_t deserialize_int16(uint8_t data_bytes[]);


/**
 * \brief Deserializes a 16-bit word
 *
 * \param data_bytes vector containing the MSB and LSB bytes of the word
 *
 * \return the deserialized 16-bit word
 */
uint16_t deserialize_uint16(uint8_t data_bytes[]);

/**
 * \brief Deserializes a 32-bit integer
 *
 * \param data_bytes vector containing the 4 bytes of the word
 *
 * \return the deserialized 32-bit integer
 */
int32_t deserialize_int32(uint8_t data_bytes[]);

/**
 * \brief Deserializes a 32-bit word
 *
 * \param data_bytes vector containing the 4 bytes of the word
 *
 * \return the deserialized 32-bit word
 */
uint32_t deserialize_uint32(uint8_t data_bytes[]);

/**
 * \brief Deserializes a 64-bit integer
 *
 * \param data_bytes vector containing the 8 bytes of the word
 *
 * \return the deserialized 64-bit integer
 */
int64_t deserialize_int64(uint8_t data_bytes[]);

/**
 * \brief Deserializes a 64-bit word
 *
 * \param data_bytes vector containing the 8 bytes of the word
 *
 * \return the deserialized 64-bit word
 */
uint64_t deserialize_uint64(uint8_t data_bytes[]);


/**
 * \brief Serializes a 16-bit integer
 *
 * \param var the 16-bit integer to serialize
 * \param data_bytes vector that will store the serialized 16-bit integer
 *
 */
void serialize_int16(int16_t var, uint8_t data_bytes[]);


/**
 * \brief Serializes a 16-bit word
 *
 * \param var the 16-bit word to serialize
 * \param data_bytes vector that will store the serialized 16-bit word
 *
 */
void serialize_uint16(uint16_t var, uint8_t data_bytes[]);

/**
 * \brief Serializes a 32-bit integer
 *
 * \param var the 32-bit integer to serialize
 * \param data_bytes vector that will store the serialized 32-bit integer
 *
 */
void serialize_int32(int32_t var, uint8_t data_bytes[]);


/**
 * \brief Serializes a 32-bit word
 *
 * \param var the 32-bit word to serialize
 * \param data_bytes vector that will store the serialized 32-bit word
 *
 */
void serialize_uint32(uint32_t var, uint8_t data_bytes[]);

/**
 * \brief Serializes a 64-bit integer
 *
 * \param var the 64-bit integer to serialize
 * \param data_bytes vector that will store the serialized 64-bit integer
 *
 */
void serialize_int64(int64_t var, uint8_t data_bytes[]);


/**
 * \brief Serializes a 64-bit word
 *
 * \param var the 64-bit word to serialize
 * \param data_bytes vector that will store the serialized 32-bit word
 *
 */
void serialize_uint64(uint64_t var, uint8_t data_bytes[]);


#ifdef __cplusplus
}
#endif


#endif /* INCLUDE__SERIALIZE_H_ */

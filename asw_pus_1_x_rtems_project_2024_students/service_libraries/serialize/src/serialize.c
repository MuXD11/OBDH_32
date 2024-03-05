#include "public/serialize.h"

uint16_t deserialize_int16(uint8_t data_bytes[]) {

	union {
		int16_t data;
		uint8_t bytes[2];
	} serializer;

	for (int i = 0; i < 2; i++) {

#ifdef BIG_ENDIAN
		serializer.bytes[i] = data_bytes[i];
#else
		serializer.bytes[1-i]=data_bytes[i];
#endif

	}

	return serializer.data;

}

uint16_t deserialize_uint16(uint8_t data_bytes[]) {

	union {
		uint16_t data;
		uint8_t bytes[2];
	} serializer;

	for (int i = 0; i < 2; i++) {

#ifdef BIG_ENDIAN
		serializer.bytes[i] = data_bytes[i];
#else
		serializer.bytes[1-i]=data_bytes[i];
#endif

	}

	return serializer.data;

}

int32_t deserialize_int32(uint8_t data_bytes[]) {

	union {
		int32_t data;
		uint8_t bytes[4];
	} serializer;

	for (int i = 0; i < 4; i++) {

#ifdef BIG_ENDIAN
		serializer.bytes[i] = data_bytes[i];
#else
		serializer.bytes[3-i]=data_bytes[i];
#endif

	}

	return serializer.data;

}

uint32_t deserialize_uint32(uint8_t data_bytes[]) {

	union {
		uint32_t data;
		uint8_t bytes[4];
	} serializer;

	for (int i = 0; i < 4; i++) {

#ifdef BIG_ENDIAN
		serializer.bytes[i] = data_bytes[i];
#else
		serializer.bytes[3-i]=data_bytes[i];
#endif

	}

	return serializer.data;

}

int64_t deserialize_int64(uint8_t data_bytes[]) {

	union {
		int64_t data;
		uint8_t bytes[8];
	} serializer;

	for (int i = 0; i < 8; i++) {

#ifdef BIG_ENDIAN
		serializer.bytes[i] = data_bytes[i];
#else
		serializer.bytes[7-i]=data_bytes[i];
#endif

	}

	return serializer.data;

}

uint64_t deserialize_uint64(uint8_t data_bytes[]) {

	union {
		uint64_t data;
		uint8_t bytes[8];
	} serializer;

	for (int i = 0; i < 8; i++) {

#ifdef BIG_ENDIAN
		serializer.bytes[i] = data_bytes[i];
#else
		serializer.bytes[7-i]=data_bytes[i];
#endif

	}

	return serializer.data;

}

void serialize_int16(int16_t var, uint8_t data_bytes[]) {

	union {
		int16_t data;
		uint8_t bytes[2];
	} serializer;

	serializer.data = var;

	for (int i = 0; i < 2; i++)

#ifdef BIG_ENDIAN

		data_bytes[i] = serializer.bytes[i];

#else



		data_bytes[i] = serializer.bytes[1 - i];

#endif

}

void serialize_uint16(uint16_t var, uint8_t data_bytes[]) {

	union {
		uint16_t data;
		uint8_t bytes[2];
	} serializer;

	serializer.data = var;

	for (int i = 0; i < 2; i++)

#ifdef BIG_ENDIAN
		data_bytes[i] = serializer.bytes[i];
#else
		data_bytes[i] = serializer.bytes[1 - i];
#endif

}

void serialize_int32(int32_t var, uint8_t data_bytes[]) {

	union {
		int32_t data;
		uint8_t bytes[4];
	} serializer;

	serializer.data = var;

	for (int i = 0; i < 4; i++)

#ifdef BIG_ENDIAN
		data_bytes[i] = serializer.bytes[i];

#else
		data_bytes[i] = serializer.bytes[3 - i];

#endif

}

void serialize_uint32(uint32_t var, uint8_t data_bytes[]) {
	union {
		uint32_t data;
		uint8_t bytes[4];
	} serializer;

	serializer.data = var;

	for (int i = 0; i < 4; i++)

#ifdef BIG_ENDIAN
		data_bytes[i] = serializer.bytes[i];
#else
		data_bytes[i] = serializer.bytes[3 - i];

#endif

}

void serialize_int64(int64_t var, uint8_t data_bytes[]) {

	union {
	    int64_t data;
	    uint8_t bytes[8];
	} serializer;

	serializer.data=var;

	for (int i = 0; i < 8; i++)

#ifdef BIG_ENDIAN
		data_bytes[i] = serializer.bytes[i];
#else

		data_bytes[i] = serializer.bytes[7 - i];

#endif

}

void serialize_uint64(uint64_t var, uint8_t data_bytes[]) {

	union {
	    uint64_t data;
	    uint8_t bytes[8];
	} serializer;

	serializer.data=var;

	for (int i = 0; i < 8; i++)

#ifdef BIG_ENDIAN
		data_bytes[i] = serializer.bytes[i];
#else

		data_bytes[i] = serializer.bytes[7 - i];

#endif

}

#include "../../edroomsl_types/include/public/edroomsl_types.h"


void TEDROOMUInt64_Serialize(TEDROOMUInt64 * input, TEDROOMUInt64 * output)
{
	*output = edroom_htonll(*input);
}

void TEDROOMUInt64_Deserialize(TEDROOMUInt64 * input, TEDROOMUInt64 * output)
{
	*output = edroom_ntohll(*input);
}

void TEDROOMUInt32_Serialize(TEDROOMUInt32 * input, TEDROOMUInt32 * output)
{
	*output = edroom_htonl(*input);
}

void TEDROOMUInt32_Deserialize(TEDROOMUInt32 * input, TEDROOMUInt32 * output)
{
	*output = edroom_ntohl(*input);
}

void TEDROOMUInt16_Serialize(TEDROOMUInt16 * input, TEDROOMUInt16 * output)
{
	*output = edroom_htons(*input);
}

void TEDROOMUInt8_Serialize(TEDROOMUInt8 * input, TEDROOMUInt8 * output)
{
	*output = *input;
}

void TEDROOMUInt8_Deserialize(TEDROOMUInt8 * input, TEDROOMUInt8 * output)
{
	*output = *input;
}

void TEDROOMUInt16_Deserialize(TEDROOMUInt16 * input, TEDROOMUInt16 * output)
{
	*output = edroom_ntohs(*input);
}

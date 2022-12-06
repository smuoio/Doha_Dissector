/**
* \file Internet Protocol.h
* \brief the file manages the eth field decoded 
* \author Salvatore Muoio
*/

#ifndef _IP_H_
#define _IP_H_

#include "Type.h"

#define IP_VERSION              3
#define IP_DSF                  2
#define IP_TOTAL_LENGTH         6
#define IP_IDENTIFICATION       6
#define IP_FLAGS                6
#define IP_TIME2LIVE            3
#define IP_PROTOCOL             3
#define IP_HEADERCHECKSUM       6
#define IP_SOURCEADDRESS       12
#define IP_DESTINATIONADDRESS  12
#define IP_PORT                 6

namespace ip_
{
#pragma pack(push, 1)
	/**
 	* \struct t_ip
 	* \brief ip structure 
 	*/
	typedef struct
	{
		type_::UINT8 Version[IP_VERSION];
		type_::UINT8 DSF[IP_DSF];
		type_::UINT8 Total_Length[IP_TOTAL_LENGTH];
		type_::UINT8 Identification[IP_IDENTIFICATION];
		type_::UINT8 Flags[IP_FLAGS];
		type_::UINT8 Time2Live[IP_TIME2LIVE];
		type_::UINT8 Protocol[IP_PROTOCOL];
		type_::UINT8 HeaderCheckSum[IP_HEADERCHECKSUM];
		type_::UINT8 SourceAddress[IP_SOURCEADDRESS];
		type_::UINT8 DestinationAddress[IP_DESTINATIONADDRESS];
		type_::UINT8 SourcePort[IP_PORT];
		type_::UINT8 DestinationPort[IP_PORT];
		type_::UINT8 Length[IP_PORT];
		type_::UINT8 CheckSum[IP_PORT];
	}t_ip;
#pragma(pop)
}
#endif

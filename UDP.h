/**
* \file UDP.h
* \brief the file manages the eth field decoded 
* \author Salvatore Muoio
*/

#ifndef _UDP_H_
#define _UDP_H_

#define UDP_SEQUENCECOUNTER  12
#define UDP_PROTOCOLVERSION   6
#define UDP_MESSAGETYPE       6
#define UDP_COMID            12
#define UDP_TOPOCOUNT        12
#define UDP_DATASETLENGTH    12
#define UDP_RESERVED         24
#define UDP_REPLYIPADDRESS   12
#define UDP_DESTINATIONID     3
#define UDP_RESERVED_16      48
#define UDP_COMMONDATA       24
#define UDP_COMMDATASTS      12
#define UDP_BRAKEREQUEST     72
#define UDP_AXLESPEED       144




namespace udp_
{
#pragma pack(1)
	/**
 	* \struct t_udp
 	* \brief udp structure 
 	*/

	typedef struct
	{
		type_::UINT8 SequenceCounter[UDP_SEQUENCECOUNTER];
		type_::UINT8 ProtocolVersion[UDP_PROTOCOLVERSION];
		type_::UINT8 MessageType[UDP_MESSAGETYPE];
		type_::UINT8 ComID[UDP_COMID];
		type_::UINT8 TopoCount[UDP_TOPOCOUNT];
		type_::UINT8 DatasetLength[UDP_DATASETLENGTH];
		type_::UINT8 Reserved[UDP_RESERVED];
		type_::UINT8 ReplyIpAddress[UDP_REPLYIPADDRESS];
		type_::UINT8 DestinationID[UDP_DESTINATIONID];
		type_::UINT8 Spare[UDP_DESTINATIONID];
		type_::UINT8 DataLengthUpper[UDP_DESTINATIONID];
		type_::UINT8 DataLengthLower[UDP_DESTINATIONID];
		type_::UINT8 Reserved_16[UDP_RESERVED_16];
		type_::UINT8 Year[UDP_DESTINATIONID];
		type_::UINT8 Month[UDP_DESTINATIONID];
		type_::UINT8 Day[UDP_DESTINATIONID];
		type_::UINT8 Hour[UDP_DESTINATIONID];
		type_::UINT8 Minute[UDP_DESTINATIONID];
		type_::UINT8 Second[UDP_DESTINATIONID];
		type_::UINT8 Tset[UDP_DESTINATIONID];
		type_::UINT8 ReservedSO27[UDP_DESTINATIONID];
		type_::UINT8 CommonDataTrainOpInf[UDP_COMMONDATA];
		type_::UINT8 CommonDataFaultInf[UDP_COMMONDATA];
		type_::UINT8 CommonDataStatusInf[UDP_COMMDATASTS];
		type_::UINT8 BrakeRequest[UDP_BRAKEREQUEST];
		type_::UINT8 BrakeRequestBcuFault[UDP_BRAKEREQUEST];
		type_::UINT8 AxleSpeed[UDP_AXLESPEED];
		type_::UINT8 ASPressure[UDP_AXLESPEED];
		type_::UINT8 ASPressureControl[UDP_BRAKEREQUEST];
		type_::UINT8 BCUPressure[UDP_AXLESPEED];
		type_::UINT8 EDBrakeForce[UDP_BRAKEREQUEST];
		type_::UINT8 EDBrakeForceDistribution[UDP_BRAKEREQUEST];
	}t_udp;
#pragma(pop)
}


#endif

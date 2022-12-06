/**
* \file Decod.cpp
* \brief the file manages the decod class
* \author Salvatore Muoio
*/
#include <iostream>
#include <fstream>
#include "Decod.h"
#include "Packet.h"

using namespace std;


#define SIZE_FILE 1500

decod_::t_data data;

decod::decod()
{
	// PimP to add for other 
	//decod_::offset = 0x07;
}


decod& decod::instance(void)
{
	static decod obj_decod;

	return(obj_decod);
}

decod_::t_data* decod::getdatapacket(void)
{
	return(&data);
	//return 0;
}

void decod::createfile(void)
{
	type_::UINT8 dest[6];
	ifstream file;
	ofstream ofile;
	file.open("decod.bin", ios::in | ios::binary); 
	ofile.open("DecodPDr.xls",ios::out|ios::binary);
	if(file.is_open())
	{
		// call eth field function
		//cout<<sizeof(getpacket()->eth.destination)<<endl;
		//file.seekg(decod_::offset, ios::beg);
		type_::CHAR8 raw[SIZE_FILE];
		//type_::UINT8 byte;
		//type_::CHAR8 byte = 0x00U;
		//file.read((char*)&getpacket()->eth.destination, sizeof(getpacket()->eth.destination));
		file.read((char*)&raw, sizeof(raw));
		//file.read((char*)&getpacket()->pack, sizeof(raw));
		memcpy(getpacket(), &raw[0], sizeof(packet_::t_packet));
		//for(int ii = 0; ii < 47; ii++)
		//	cout<<raw[ii]<<endl;
		cout<<raw<<endl;
		// create byte
		//cout<<raw[6]<<endl;
		//cout<<raw[7]<<endl;
		//byte = /*((raw[6]&0x0F)<<4) | */(raw[6]<<4);
		//byte =  byte|raw[7];
		//raw[6] = (raw[6]<<4)&0xF0;
		//byte = byte|raw[7];
		//cout<<"byte = " << byte<<endl;
		//cout<<"raw[6] = "<< raw[6]<<endl;
		// ethernet II destination -->
		
		//byte = (looktablechar(raw[6])<<4);
		//byte = byte | looktablechar(raw[7]);
		//cout<<"byte = "<<byte<<endl;
		//getclasseth().create_destination(raw);
		//getclasseth().create_source(raw);
		//getclasseth().create_type(raw);
		if(ofile.is_open())
		{
			ofile<<"-----ETH fields-----:"<<endl;
			ofile<<"Destination:\t";
			//for(int ii = 0; ii < ETH_DESTINATION; ii++)
			//	ofile<<getpacket()->packeth.destination[ii];
			//ofile<<endl;
			ConvertAddress(getpacket()->packeth.destination, ETH_DESTINATION, ofile);
			ofile<<endl;
			ofile<<"Address:\t";
			//for(int ii = 0; ii < ETH_SOURCE; ii++)
			//	ofile<<getpacket()->packeth.source[ii];
			ConvertAddress(getpacket()->packeth.source, ETH_SOURCE, ofile);
			ofile<<endl;
			ofile<<"Type:\t";
			for(int ii = 0; ii < ETH_TYPE; ii++)
				ofile<<getpacket()->packeth.type[ii];
			ofile<<endl;
			ofile<<"-----Internet Protocol fields-----:"<<endl;
			ofile<<"Version:\t";
			ofile<<dec<<(static_cast<int>(looktablechar(getpacket()->packip.Version[0])));
			ofile<<endl;
			ofile<<"DSF:\t";
			for(int ii = 0; ii < IP_DSF; ii++)
				ofile<<getpacket()->packip.DSF[ii];
			ofile<<endl;
			ofile<<"Total Length:\t";
			ConvertChar2Num(IP_TOTAL_LENGTH, getpacket()->packip.Total_Length, &getdatapacket()->TotalLength);
			ofile<<dec<<(static_cast<type_::UINT16>(getdatapacket()->TotalLength));
			ofile<<endl;		
			ofile<<"Identification:\t";
			for(int ii = 0; ii < IP_IDENTIFICATION; ii++)
				ofile<<getpacket()->packip.Identification[ii];
			ofile<<endl;	
			ofile<<"Flags:\t";
			for(int ii = 0; ii < IP_FLAGS; ii++)
				ofile<<getpacket()->packip.Flags[ii];
			ofile<<endl;	
			ofile<<"Time to Live:\t";
			for(int ii = 0; ii < IP_TIME2LIVE; ii++)
				ofile<<getpacket()->packip.Time2Live[ii];
			ofile<<endl;	
			ofile<<"Protocol:\t";
			for(int ii = 0; ii < IP_PROTOCOL; ii++)
				ofile<<getpacket()->packip.Protocol[ii];
			type_::INT8 value = (((looktablechar(getpacket()->packip.Protocol[1]) << 4)&0xF0) | (looktablechar(getpacket()->packip.Protocol[2])&0x0F) );
			ofile<<"  ("<<looktableprotcol(value)<<")";
			ofile<<endl;	
			ofile<<"Header check sum:\t";
			for(int ii = 0; ii < IP_HEADERCHECKSUM; ii++)
				ofile<<getpacket()->packip.HeaderCheckSum[ii];
			ofile<<endl;		
			ofile<<"Source Address:\t";
			ConvertAddress(getpacket()->packip.SourceAddress, IP_SOURCEADDRESS, ofile);	
			ofile<<endl;	
			ofile<<"Destination Address:\t";
			cout<<endl;
			ConvertAddress(getpacket()->packip.DestinationAddress, IP_DESTINATIONADDRESS, ofile);	
			ofile<<endl;
			ofile<<"Source Port:\t";
			for(int ii = 0; ii < IP_PORT; ii++)
				ofile<<getpacket()->packip.SourcePort[ii];
			ofile<<endl;		
			ofile<<"Destination Port:\t";
			for(int ii = 0; ii < IP_PORT; ii++)
				ofile<<getpacket()->packip.DestinationPort[ii];
			ofile<<endl;		
			ofile<<"Length:\t";
			ConvertChar2Num(IP_PORT, getpacket()->packip.Length, &getdatapacket()->DatasetLength);
			ofile<<dec<<(static_cast<type_::UINT64>(getdatapacket()->DatasetLength));
			ofile<<endl;
			ofile<<"Check Sum:\t";	
			for(int ii = 0; ii < IP_PORT; ii++)
				ofile<<getpacket()->packip.CheckSum[ii];
			ofile<<endl;	
			ofile<<"------UDP------: "<<endl;
			ofile<<"Sequence Counter:\t"; 
			for(int ii = 0; ii < UDP_SEQUENCECOUNTER; ii++)
				ofile<<getpacket()->packudp.SequenceCounter[ii];
			ofile<<endl;
			ofile<<"Protocol Version:\t"; 	
			for(int ii = 0; ii < UDP_MESSAGETYPE; ii++)
				ofile<<getpacket()->packudp.ProtocolVersion[ii];
			ofile<<endl;	
			ofile<<"Message Type:\t"; 	
			for(int ii = 0; ii < UDP_MESSAGETYPE; ii++)
				ofile<<getpacket()->packudp.MessageType[ii];
			ofile<<endl;	
			ofile<<"Com ID:\t"; 	
			for(int ii = 0; ii < UDP_COMID; ii++)
				ofile<<getpacket()->packudp.ComID[ii];
			ofile<<endl;	
			ofile<<"Topo Count:\t"; 	
			for(int ii = 0; ii < UDP_TOPOCOUNT; ii++)
				ofile<<getpacket()->packudp.TopoCount[ii];
			ofile<<endl;	
			ofile<<"DatasetLength:\t"; 	
			for(int ii = 0; ii < UDP_TOPOCOUNT; ii++)
				ofile<<getpacket()->packudp.DatasetLength[ii];
			ofile<<endl;	
			ofile<<"Reserved:\t"; 	
			for(int ii = 0; ii < UDP_RESERVED; ii++)
				ofile<<getpacket()->packudp.Reserved[ii];
			ofile<<endl;	
			ofile<<"Reply IP Address:\t"; 	
			for(int ii = 0; ii < UDP_REPLYIPADDRESS; ii++)
				ofile<<getpacket()->packudp.ReplyIpAddress[ii];
			ofile<<endl;	
			ofile<<"Destination ID:\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.DestinationID[ii];
			ofile<<endl;	
			ofile<<"Reserved:\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.Spare[ii];
			ofile<<endl;	
			ofile<<"Data Length (Upper):\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.DataLengthUpper[ii];
			ofile<<endl;	
			ofile<<"Data Length (Lower):\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.DataLengthLower[ii];
			ofile<<endl;	
			ofile<<"Reserved 16 bytes:\t"; 	
			for(int ii = 0; ii < UDP_RESERVED_16; ii++)
				ofile<<getpacket()->packudp.Reserved_16[ii];
			ofile<<endl;	
			ofile<<"Year:\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.Year[ii];
			ofile<<endl;	
			ofile<<"Month:\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.Month[ii];
			ofile<<endl;	
			ofile<<"Day:\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.Day[ii];
			ofile<<endl;	
			ofile<<"Hour:\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.Hour[ii];
			ofile<<endl;	
			ofile<<"Minute:\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.Minute[ii];
			ofile<<endl;	
			ofile<<"Second:\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.Second[ii];
			ofile<<endl;	
			ofile<<"TSET:\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.Tset[ii];
			ofile<<endl;
			ofile<<"Reserved S027:\t"; 	
			for(int ii = 0; ii < UDP_DESTINATIONID; ii++)
				ofile<<getpacket()->packudp.ReservedSO27[ii];
			ofile<<endl;	
			ofile<<"Common Data Train Operating Information:\t"; 	
			for(int ii = 0; ii < UDP_COMMONDATA; ii++)
				ofile<<getpacket()->packudp.CommonDataTrainOpInf[ii];
			ofile<<endl;	
			ofile<<"Common Data Fault Information:\t"; 	
			for(int ii = 0; ii < UDP_COMMONDATA; ii++)
				ofile<<getpacket()->packudp.CommonDataFaultInf[ii];
			ofile<<endl;	
			ofile<<"Common Data Status Information:\t"; 	
			for(int ii = 0; ii < UDP_COMMDATASTS; ii++)
				ofile<<getpacket()->packudp.CommonDataFaultInf[ii];
			ofile<<endl;	
			ofile<<"Brake Request:\t"; 	
			for(int ii = 0; ii < UDP_BRAKEREQUEST; ii++)
				ofile<<getpacket()->packudp.BrakeRequest[ii];
			ofile<<endl;	
			ofile<<"Brake Request BCU Fault:\t"; 	
			for(int ii = 0; ii < UDP_BRAKEREQUEST; ii++)
				ofile<<getpacket()->packudp.BrakeRequestBcuFault[ii];
			ofile<<endl;	
			ofile<<"Axle Speed:\t"; 	
			for(int ii = 0; ii < UDP_AXLESPEED; ii++)
				ofile<<getpacket()->packudp.AxleSpeed[ii];
			ofile<<endl;	
			ofile<<"AS Pressure:\t"; 	
			for(int ii = 0; ii < UDP_AXLESPEED; ii++)
				ofile<<getpacket()->packudp.ASPressure[ii];
			ofile<<endl;	
			ofile<<"AS Pressure for Control:\t"; 	
			for(int ii = 0; ii < UDP_BRAKEREQUEST; ii++)
				ofile<<getpacket()->packudp.ASPressureControl[ii];
			ofile<<endl;	
			ofile<<"BCU Pressure:\t"; 	
			for(int ii = 0; ii < UDP_AXLESPEED; ii++)
				ofile<<getpacket()->packudp.BCUPressure[ii];
			ofile<<endl;	
			ofile<<"ED Brake Force:\t"; 	
			for(int ii = 0; ii < UDP_BRAKEREQUEST; ii++)
				ofile<<getpacket()->packudp.EDBrakeForce[ii];
			ofile<<endl;	
			ofile<<"ED Brake Force Distribution:\t"; 	
			for(int ii = 0; ii < UDP_BRAKEREQUEST; ii++)
				ofile<<getpacket()->packudp.EDBrakeForceDistribution[ii];
			ofile<<endl;	
			ofile.close();
		}
	}
	
}

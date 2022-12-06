/**
* \file Packet.cpp
* \brief the file manages the packet 
* \author Salvatore Muoio
*/

#include "Packet.h"

static packet_::t_packet pack;

packet_::t_packet *getpacket(void)
{
	return(&pack);
}


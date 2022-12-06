/**
* \file Packet.h
* \brief the file manages the packet 
* \author Salvatore Muoio
*/


#ifndef _PACKET_H_
#define _PACKET_H_

#include "Type.h"
#include "Eth.h"
#include "IP.h"
#include "UDP.h"

namespace packet_
{
#pragma pack(push, 1)
	/**
 	* \struct t_packet
 	* \brief packet structure used for the PDrequest from TCMS
 	*/
	typedef struct
	{
		eth_::t_eth packeth; /*!< eth data section */
		ip_::t_ip packip;    /*!< ip data section */
		udp_::t_udp packudp; /*!< udp data section */
	}t_packet;
}
#pragma(pop)
/**
* \fn packet_::t_packet *getpacket(void)
* \brief function used to access to packet
* \return address to structure 
*/
packet_::t_packet *getpacket(void);

#endif

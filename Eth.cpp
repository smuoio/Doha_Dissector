/**
* \file Eth.c
* \brief the file manages the eth field decoded 
* \author Salvatore Muoio
*/
#include <iostream>
#include "Packet.h"
//#include "Eth.h"

using namespace std;

//static eth obj_eth;
static eth_::t_eth packet = {0};


eth::eth()
{
	//eth &eth = eth::instance();
	offset = 0x07;
	
}

/*
eth& eth::instance(void)
{
	static eth obj_eth;
	return(obj_eth);
}


eth_::t_eth *getethpacket(void)
{
	static eth_::t_eth packet;
	return(&packet);
}
*/

eth_::t_eth* eth::getethpacket(void) const
{
	return(&packet);
}

void eth::create_destination(type_::CHAR8 *pdest)
{
	type_::e_result lret = type_::RESULT_OK;
	lret = checkarg((type_::CHAR8*)pdest);
	if(lret == type_::RESULT_OK)
	{
		cout<<"create_destination"<<endl;
		//for(int ii = 0; ii < 17; ii++/*, pdest++*/)
		{
			//if(pdest[ii] != ' ')
			{
				static type_::INT16 jj = 0x0;
				static type_::INT16 ii = offset;
				memcpy(&getpacket()->packeth.destination[jj], &pdest[ii], (ETH_DESTINATION));
				//cout<<"tmp[0] = "<<(looktablechar(pdest[ii])<<4)<<endl;
				//cout<<"tmp[1] = "<<((looktablechar(pdest[ii])<<4) | (looktablechar(pdest[ii+1])&0x0F))<<endl;
				//getethpacket()->destination[jj] = (((looktablechar(pdest[ii]) << 4)&0xF0) | (looktablechar(pdest[ii+1])&0x0F) );
				//getpacket()->pack.destination[jj] = getethpacket()->destination[jj];
				//cout<<"getethpacket()->destination[jj] = "<<getethpacket()->destination[jj]<<endl;
				//ii++;
				//jj++;
			} //
			
		}//if check pointer
		// copy the data in the packet or use the access to the packet!!!
	}
}

void eth::create_source(type_::CHAR8 *pdest)
{
	type_::e_result lret = type_::RESULT_OK;
	lret = checkarg((type_::CHAR8*)pdest);
	if(lret == type_::RESULT_OK)
	{
		cout<<"create_source"<<endl;
		{
			{
				static type_::INT16 jj = 0x0;
				static type_::INT16 ii = offset+ETH_DESTINATION+1;
				memcpy(&getpacket()->packeth.source[jj], &pdest[ii], (ETH_SOURCE));
			} //
			
		}
		// copy the data in the packet or use the access to the packet!!!
	}//if check pointer
}

void eth::create_type(type_::CHAR8 *pdest)
{
	type_::e_result lret = type_::RESULT_OK;
	lret = checkarg((type_::CHAR8*)pdest);
	//if(lret == type_::RESULT_OK)
	if(SUCCEEDED(lret))
	{
		cout<<"create_type"<<endl;
		static type_::INT16 jj = 0x0;
		static type_::INT16 ii = offset + ETH_DESTINATION + ETH_SOURCE +1;
//		for(int zz = ii;zz<ii+ETH_TYPE+1; zz++)
//			cout<<pdest[zz]<<endl;
		memcpy(&getpacket()->packeth.type[jj], &pdest[ii],(ETH_TYPE));
	}
}
eth& getclasseth(void)
{
	static eth eth_obj;
	return(eth_obj);
}

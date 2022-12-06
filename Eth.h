/**
* \file Eth.h
* \brief the file manages the eth field decoded 
* \author Salvatore Muoio
*/

#ifndef _ETH_H_
#define _ETH_H_

#include "Util.h"
#include "Type.h"

#define ETH_DESTINATION 18
#define ETH_SOURCE      18
#define ETH_TYPE        6

namespace eth_
{
#pragma pack(push, 1)
	typedef struct
	{
		type_::UINT8 destination[ETH_DESTINATION];	
		type_::UINT8 source[ETH_SOURCE];
		type_::UINT8 type[ETH_TYPE];
	}t_eth;
}//namespace eth_
#pragma(pop)

class eth:public util
{
	private:
		type_::UINT8 offset;
	public:
	eth();
	//static eth& instance(void);
	eth_::t_eth *getethpacket(void) const;
	void create_destination(type_::CHAR8 *pdest);
	void create_source(type_::CHAR8 *pdest);
	void create_type(type_::CHAR8 *pdest);
	virtual ~eth(){};
};

eth& getclasseth(void);
//eth_::t_eth *getethpacket(void);
#endif

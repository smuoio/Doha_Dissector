/**
* \file Util.h
* \brief the file manages the util functions
* \author Salvatore Muoio
*/

#ifndef _UTIL_H_
#define _UTIL_H_

#include <fstream>
#include "Type.h"


namespace util_
{
}

class util
{
	public:
	util();
	void readbyte(type_::UINT8 up, type_::UINT8 low, type_::UINT8 *out);
	type_::UINT16 looktablechar(type_::CHAR8 value); 
	type_::CHAR8* looktableprotcol(type_::INT8 value);
	type_::e_result checkarg(void *parg);
	type_::e_result ConvertChar2Num(type_::UINT16 size, type_::UINT8 *field, type_::UINT64 *out);
	type_::e_result ConvertAddress(type_::UINT8 *field, type_::UINT16 size, std::ostream& file);
	virtual ~util(){};		
};

#endif

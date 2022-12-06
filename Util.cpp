/**
* \file Util.cpp
* \brief the file manages the util functions
* \author Salvatore Muoio
*/
#include <iostream>
#include "Util.h"

util::util()
{
	
}

void util::readbyte(type_::UINT8 up, type_::UINT8 low, type_::UINT8 *out)
{
	if(out != 0)
	{
		type_::UINT8 tmp = 0x0U;
		tmp = (up<<4)| low;
		*out = tmp;
	}
}

type_::UINT16 util::looktablechar(type_::CHAR8 value)
{
	type_::CHAR8 Tab[22] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','A','B','C','D','E','F'};
	type_::UINT16  lOut = 0x00U;
	type_::INT16     ii = 0x0000;
	for(type_::INT16 ii = 0x0; ii< sizeof(Tab); ii++)
	{
		if(value == Tab[ii])
		{
			if((ii>=0) && (ii<=9))
				lOut = value-48;
			else if((ii>=10) && (ii<=15))
				lOut = value - 87;
			else
				lOut = value - 55;
			break;
		}//if
	}//for
	return(lOut);
}

type_::e_result util::checkarg(void *parg)
{
	return((parg != 0) ? type_::RESULT_OK : type_::RESULT_POINTER_NOT_ADDRESSED);
}

type_::CHAR8* util::looktableprotcol(type_::INT8 value)
{
	const type_::CHAR8 *Tab[] = {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","UDP"};
	return((type_::CHAR8*)Tab[value]);
}

type_::e_result util::ConvertChar2Num(type_::UINT16 size, type_::UINT8 *field, type_::UINT64 *out)
{
	type_::INT16 lret = type_::RESULT_OK;
	type_::UINT16 num = 0x0U;
	lret |= (checkarg((type_::UINT8*)field));
	lret |= checkarg((type_::UINT16*)out);
	if(SUCCEEDED(lret))
	{
		for(int ii = 0; ii < size; ii++, field++)
		{
			if(*field != ' ')
			{
				if(ii == (size-1))
				{
					num|= (looktablechar(*field));
				}
				else
				{
					num|= (looktablechar(*field));
					num = num<<4;
				}
			}
		}
		*out = num;
	}
	return((type_::e_result)lret);
}

type_::e_result util::ConvertAddress(type_::UINT8 *field, type_::UINT16 size,std::ostream& file)
{
	type_::INT16 lret = type_::RESULT_OK;
	static type_::UINT16 sum = 0x0U;
	lret |= checkarg((type_::UINT8*)field);
	if(SUCCEEDED(lret))
	{
		for(int ii = 0; ii < size; ii++,field++)
		{
			if(*field != ' ')
			{
				static type_::INT8 jj = 0;
				if(jj++ == 0)
					sum = ((looktablechar(*field))<<4);
				else
				{
					sum|= (looktablechar(*field));
					jj = 0;
					file<<std::dec<<(static_cast<int>(sum))<<".";
			   	}
           	}		   
	   }
	}
    return ((type_::e_result)lret);
}

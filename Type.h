/**
* \file Typde.h
* \brief the file manages the custom typedef
* \author Salvatore Muoio
*/

#ifndef _TYPE_H_
#define _TYPE_H_

namespace type_
{
	typedef char           CHAR8;
	typedef unsigned char  UINT8;
	typedef unsigned short UINT16;
	typedef unsigned int   UINT64;
	typedef signed char    INT8;
	typedef signed short   INT16;
	typedef signed int     INT64;

	/**
 	* \enum e_result
 	* \brief the enum is used as validity check in the methods
 	*/
	typedef enum
	{
		RESULT_OK,                     /*!< Result of check ok */
		RESULT_POINTER_NOT_ADDRESSED,  /*!< Result of pointer check ko */
		RESULT_OUT_OF_RANGE,           /*!< Result of range check ko */
		RESULT_NOT_READY_UART = 4,     /*!< Result of uart not ready */
	}e_result;

#define SUCCEEDED(X) ((X) == type_::RESULT_OK)	
}


#endif

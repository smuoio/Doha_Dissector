/**
* \file Decod.h
* \brief the file manages the decod class
* \author Salvatore Muoio
*/


#ifndef _DECOD_H_
#define _DECOD_H_

#include "Type.h"
#include "Eth.h"
#include "Util.h"
namespace decod_
{
	/**
 	* \struct t_data
 	* \brief data structure used in engine decod
 	*/
	typedef struct
	{
		type_::UINT64 TotalLength;   /*!< Total length */
		type_::UINT64 DatasetLength; /*!< Dataset length */
	}t_data;
	
	
} //namespace decod

/** \class decod 
 *  \brief This is the main class  and manages the parser and the decod.
 *
 * Some details about the Test class.
*/
class decod:public util
{
	private:
	public:
	    decod_::t_data *getdatapacket(void);
		decod();
		static decod& instance(void);
		void createfile(void);
		virtual ~decod(){};
		
};//class decod





#endif



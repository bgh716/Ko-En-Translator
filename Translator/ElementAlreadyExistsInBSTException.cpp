/*
 * ElementAlreadyExistsInBSTException.cpp
 *
 * Class Description: Defines the exception that is thrown when the
 *                    data collection ADT class already has same data.
 *
 * Author: Kihyun Byun
 * Date: Nov 28 2019
 */


#include "ElementAlreadyExistsInBSTException.h"  

ElementAlreadyExistsInBSTException::ElementAlreadyExistsInBSTException(const string& message) :
	logic_error("Data Collection ADT Class Exception: " + message)
{
}  // end constructor

// End of implementation file.
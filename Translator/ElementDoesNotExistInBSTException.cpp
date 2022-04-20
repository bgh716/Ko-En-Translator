/*
 * ElementDoesNotExistInBSTException.cpp
 *
 * Class Description: Defines the exception that is thrown when the
 *                    data collection ADT class is empty or does not have a target element.
 *
 * Author: Kihyun Byun
 * Date: Nov 28 2019
 */


#include "ElementDoesNotExistInBSTException.h"  

ElementDoesNotExistInBSTException::ElementDoesNotExistInBSTException(const string& message) :
	logic_error("Data Collection ADT Class Exception: " + message)
{
}  // end constructor

// End of implementation file.
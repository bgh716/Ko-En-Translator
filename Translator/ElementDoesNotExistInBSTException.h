#pragma once
/*
 * ElementDoesNotExistInBSTException.h
 *
 * Class Description: Defines the exception that is thrown when the
 *                    data collection ADT class is empty or does not have a target element.
 *
 * Author: Kihyun Byun
 * Date: Nov 28 2019
 */

#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class ElementDoesNotExistInBSTException : public logic_error
{
public:
	ElementDoesNotExistInBSTException(const string& message = "");

}; // end ElementDoesNotExistInBSTException 
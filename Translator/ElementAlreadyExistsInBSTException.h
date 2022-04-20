#pragma once
/*
 * ElementAlreadyExistsInBSTException.h
 *
 * Class Description: Defines the exception that is thrown when the
 *                    data collection ADT class already has same data.
 *
 * Author: Kihyun Byun
 * Date: Nov 28 2019
 */

#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class ElementAlreadyExistsInBSTException : public logic_error
{
public:
	ElementAlreadyExistsInBSTException(const string& message = "");

}; // end ElementAlreadyExistsInBSTException 
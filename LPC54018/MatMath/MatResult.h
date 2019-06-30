// Copyright 2019 OwlThree LLC
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify,
// merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following 
// conditions: 
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software. 
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT,  TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

// @author Charles L. Sherman
// @author OwlThree LLC
// @version
// @since v1.0

#ifndef MATRESULT_H
#define MATRESULT_H

#pragma once

#include <vector>

/**
 * Write a description of class MatResult here.
 * 
 * @author  Chuck Sherman 
 * @version v0.1
 */
class MatResult
{
private:
	const std::vector<std::vector<int>> result;
	const int row, col;

	/**
	 * Constructor for objects of class MatResult
	 */
public:
	MatResult(std::vector<std::vector<int>> &result, int row, int col);

	virtual MatResult *get();

	virtual void get(std::vector<std::vector<int>> &result, int row, int col);
};

#endif // MATRESULT_H
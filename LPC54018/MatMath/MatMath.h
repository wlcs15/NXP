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

#ifndef MATMATH_H
#define MATMATH_H
#pragma once

#include <vector>

using namespace std;

/**
 * MatMath interface
 * 
 * @author Charles Sherman
 * @version v0.1
 */

class MatMath
{
	/**
	 * Multiply method for two matrix
	 * 
	 * @param  int[][] a - First Matrix
	 * @param  int[][] b - Second Matrix
	 * @param  int[][] result - Resulting Matrix product
	 * @return None
	 */
public:
	virtual void multiply(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result) = 0; // multiply A and B into result

	/**
	 * Add method for two matrix
	 * 
	 * @param  int[][] a - First Matrix
	 * @param  int[][] b - Second Matrix
	 * @param  int[][] result - Resulting Matrix sum
	 * @return None
	 */
	virtual void add(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result) = 0; // add A and B into result

	/**
	 * Print method
	 * 
	 * @param  int[][] a matrix to be printed
	 * @return None
	 */
	virtual void print(std::vector<std::vector<int>> &a) = 0; // pretty print matrix
};

#endif //MATMATH_H

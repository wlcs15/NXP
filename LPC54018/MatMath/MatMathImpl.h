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

#ifndef MATMATHIMPL_H
#define MATMATHIMPL_H

/**
 * MatMathImpl class
 * 
 * @author Charles Sherman
 * @version v0.1
 */
#pragma once

#include "MatMath.h"
#include <vector>
#include <iostream>
#include "exceptionhelper.h"

class MatResult;
class RowColProdExecutable;
class RowColSumExecutable;

class MatMathImpl : public MatMath
{
private:
	const int NTHREADS = 32; // Use lots of threads
	//ExecutorService *const executor; // From Doug Lea

	/**
	 * Constructor for objects of class RowColProdExecutable
	*/
public:
	virtual ~MatMathImpl()
	{
		//delete executor;
	}

	MatMathImpl();

	/**
	 * Multiply method for two matrix
	 * 
	 * @param  int[][] a - First Matrix
	 * @param  int[][] b - Second Matrix
	 * @param  int[][] result - Resulting Matrix product
	 * @return None
	 */
	void multiply(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result) override; // multiply A and B into result

private:
	class CallableAnonymousInnerClass //: public Callable<MatResult*>
	{
	private:
		MatMathImpl *outerInstance;

		RowColProdExecutable *element;

	public:
		virtual ~CallableAnonymousInnerClass()
		{
			delete element;
		}

		CallableAnonymousInnerClass(MatMathImpl *outerInstance, RowColProdExecutable *element);

		MatResult *call();
	};

	/**
	 * Add method for two matrix
	 * 
	 * @param  int[][] a - First Matrix
	 * @param  int[][] b - Second Matrix
	 * @param  int[][] result - Resulting Matrix sum
	 * @return None
	 */
public:
	void add(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result) override; // add A and B into result

private:
	class CallableAnonymousInnerClass2 //: public Callable<MatResult*>
	{
	private:
		MatMathImpl *outerInstance;

		RowColSumExecutable *element;

	public:
		virtual ~CallableAnonymousInnerClass2()
		{
			delete element;
		}

		CallableAnonymousInnerClass2(MatMathImpl *outerInstance, RowColSumExecutable *element);

		MatResult *call();
	};

	/**
	 * Print method which prints non-rectangular matrix
	 * 
	 * @param  int[][] Matrix to be printed
	 * @return None
	 */
public:
	void print(std::vector<std::vector<int>> &a) override; // pretty print matrix

	/**
	 * isRectangular method for matrix
	 * 
	 * @param  int[][] a - First Matrix
	 * @return boolean - True if rectangular, False if not
	 */
private:
	bool isRectangular(std::vector<std::vector<int>> &a);
};

#endif //MATMATHIMPL_H
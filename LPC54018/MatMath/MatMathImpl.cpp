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

/**
 * MatMathImpl class
 * 
 * @author Charles Sherman
 * @version v0.1
 */
#include "MatMathImpl.h"
#include "RowColProdExecutable.h"
#include "MatResult.h"
#include "RowColSumExecutable.h"
#include "RectangularVectors.h"

using namespace std;

/**
 * Constructor for objects of class RowColProdExecutable
 */
MatMathImpl::MatMathImpl() //: executor(Executors::newFixedThreadPool(NTHREADS))
{
	//executor = Executors.newSingleThreadExecutor() 
	//executor = Executors.newCachedThreadPool();
        //executor = Executors.newFixedThreadPool(NTHREADS);
}

/**
 * Multiply method for two matrix
 * 
 * @param  int[][] a - First Matrix
 * @param  int[][] b - Second Matrix
 * @param  int[][] result - Resulting Matrix product
 * @return None
 */
void MatMathImpl::multiply(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result) // multiply A and B into result
{

	// Check the size of a and b to ensure they can be multiplied
	// a's columns need to equal b's rows, the results matrix must also match
	if ((a[0].size() != b.size()) || (a.size() != result.size()) || (b[0].size() != result[0].size()))
	{
		std::wcout << L"Can't multiply: Number of columns does not match rows" << std::endl;
		print(a);
		print(b);
		print(result);
		return; // Exit without modifying result
	}

	// Ensure they are square matrix
	if (!isRectangular(a) || !isRectangular(b) || !isRectangular(result))
	{
		std::wcout << L"Can't multiply: Not rectangular" << std::endl;
		print(a);
		print(b);
		print(result);
		return; // Exit without modifying result
	}

	// Allocated result of the correct size which is a.length and b[0].length
	//result = new int[a.length][b[0].length];

	// Loop through the elements
	std::vector<RowColProdExecutable*> eList;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b[0].size(); j++)
		{
			// No threads for testing purposes
			//RowColProdExecutable e = new RowColProdExecutable(a,b,result,i,j,a[0].length);
			//e.run();
			RowColProdExecutable tempVar(a,b,result,i,j,a[0].size());
			eList.push_back(&tempVar); //ToDo: Put the matrix into a list of matrix elements
		}
	}

	// Create threads and run them, adapted from Doug Lea
	//CompletionService<MatResult*> *completionService = new ExecutorCompletionService<MatResult*>(executor);

	// Loop through the list and launch the threads
	for (auto element : eList)
	{
		CallableAnonymousInnerClass tempVar2(this, element);
		//completionService->submit(&tempVar2);
	}

	try
	{
		// Modified from Doug Lea
		for (int t = 0, n = eList.size(); t < n; t++)
		{
			//Future<MatResult*> *f = completionService->take();
			//MatResult *r = f->get();

			// put result into the matrix
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
                        //ORIGINAL LINE: int[][] sum = new int[4][4];
			std::vector<std::vector<int>> sum = RectangularVectors::RectangularIntVector(4, 4);
			int row = 0;
			int col = 0;
			//r->get(sum, row, col);
			result[row][col] = sum[row][col];

		}
	}
	catch (const InterruptedException &e)
	{
		//Thread::currentThread().interrupt();
	}
	catch (const ExecutionException &e)
	{
		//throw launderThrowable(e.getCause)); //ToDo: Pull in Doug Lea's classes
	}

	//delete completionService;
}

MatMathImpl::CallableAnonymousInnerClass::CallableAnonymousInnerClass(MatMathImpl *outerInstance, RowColProdExecutable *element)
{
	this->outerInstance = outerInstance;
	this->element = element;
}

MatResult *MatMathImpl::CallableAnonymousInnerClass::call()
{
	element->run();
	return element->get();
}

/**
 * Add method for two matrix
 * 
 * @param  int[][] a - First Matrix
 * @param  int[][] b - Second Matrix
 * @param  int[][] result - Resulting Matrix sum
 * @return None
 */
void MatMathImpl::add(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result)
{
	// Check the size of a and b to ensure they can be added
	if ((a.size() != b.size()) || (a[0].size() != b[0].size()) || (a.size() != result.size()) || (a[0].size() != result[0].size()))
	{
		std::wcout << L"Can't add matrix: Not same size" << std::endl;
		print(a);
		print(b);
		print(result);
		return; // Exit without modifying result
	}
	// Ensure they are square matrix of exactly the same size
	if (!isRectangular(a) || !isRectangular(b) || !isRectangular(result))
	{
		std::wcout << L"Can't add matrix: Not rectangular";
		print(a);
		print(b);
		print(result);
		return; // Exit without modifying result
	}

	// Allocated result of the correct size which is a.length and b[0].length
	//result = new int[a.length][b[0].length];

	// Loop through the matrix elements
	std::vector<RowColSumExecutable*> eList;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			// No threads for testing purposes
			//RowColSumExecutable e = new RowColSumExecutable(a,b,result,i,j);
			//e.run();
			RowColSumExecutable tempVar(a,b,result,i,j);
			eList.push_back(&tempVar); //ToDo: Put the matrix into a list of matrix elements
		}
	}

	// Create threads and run them
	//CompletionService<MatResult*> *completionService = new ExecutorCompletionService<MatResult*>(executor);

	// Loop through the list and launch the threads
	for (auto element : eList)
	{
		//CallableAnonymousInnerClass2 tempVar2(this, element);
		//completionService->submit(&tempVar2);
	}

	try
	{
		// Modified from Doug Lea
		for (int t = 0, n = eList.size(); t < n; t++)
		{
			//Future<MatResult*> *f = completionService->take();
			//MatResult *r = f->get();

			// put result into the matrix
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int[][] sum = new int[4][4];
			//std::vector<std::vector<int>> sum = RectangularVectors::RectangularIntVector(4, 4);
			int row = 0;
			int col = 0;
			//r->get(sum, row, col);
			//result[row][col] = sum[row][col];
		}
	}
	catch (const InterruptedException &e)
	{
		//Thread::currentThread().interrupt();
	}
	catch (const ExecutionException &e)
	{
		//throw launderThrowable(e.getCause)); //ToDo: Pull in Doug Lea's classes
	}

	//delete completionService;
}

MatMathImpl::CallableAnonymousInnerClass2::CallableAnonymousInnerClass2(MatMathImpl *outerInstance, RowColSumExecutable *element)
{
	this->outerInstance = outerInstance;
	this->element = element;
}

MatResult *MatMathImpl::CallableAnonymousInnerClass2::call()
{
	element->run();
	return element->get();
}

/**
 * Print method which prints non-rectangular matrix
 * 
 * @param  int[][] Matrix to be printed
 * @return None
 */
void MatMathImpl::print(std::vector<std::vector<int>> &a)
{
	// Determine if the matrix is null       
	if (a.empty())
	{
		std::wcout << L"Null Matrix" << std::endl;
		return; // Exit if passed a null array
	}

	// Determine if need to print open bracket for the rows
	if (a.size() > 0)
	{
		std::wcout << L"["; // Print open bracket
	}

	// Loop through all of the rows
	for (int row = 0; row < a.size(); row++)
	{
		if (a[row].size() > 0) // Determine if need an column bracket
		{
			std::wcout << L"["; // Open the column with a bracket also
		}

		bool columnComma = false; // Assume only one value in column

		// Loop through all of the columns
		for (int col = 0; col < a[row].size(); col++)
		{
			if (columnComma) // Determine if we have multiple values
			{
				std::wcout << L","; // Print a comma
			}
			std::wcout << L" " << a[row][col];
			columnComma = true; // Continue to print commas
		}
		std::wcout << L" ]";
	}
	std::wcout << L"]" << std::endl;
}

/**
 * isRectangular method for matrix
 * 
 * @param  int[][] a - First Matrix
 * @return boolean - True if rectangular, False if not
 */
bool isRectangular(std::vector<std::vector<int>> &a)
{   
    for (int row = 0; row < a.size(); row++)
    {
        if (a[0].size() != a[row].size())
        {
            return false; // Number of columns in every row does not match
        }
    }
    return true;
}
    

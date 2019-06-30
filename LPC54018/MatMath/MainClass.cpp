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

#include "MainClass.h"
#include "MatMathImpl.h"
#include "RectangularVectors.h"

using namespace std;

void MainClass::main(void)
{
	const std::vector<std::vector<int>> A =
	{
		std::vector<int> {1, 3},
		std::vector<int> {1, 0},
		std::vector<int> {1, 2}
	};
	const std::vector<std::vector<int>> B =
	{
		std::vector<int> {0, 0},
		std::vector<int> {7, 5},
		std::vector<int> {2, 1}
	};
	const std::vector<std::vector<int>> SUM =
	{
		std::vector<int> {1, 3},
		std::vector<int> {8, 5},
		std::vector<int> {3, 3}
	};
	const std::vector<std::vector<int>> C =
	{
		std::vector<int> {1, 0, 2},
		std::vector<int> {-1, 3, 1}
	};
	const std::vector<std::vector<int>> D =
	{
		std::vector<int> {3, 1},
		std::vector<int> {2, 1},
		std::vector<int> {1, 0}
	};
	const std::vector<std::vector<int>> PRODUCT =
	{
		std::vector<int> {5, 1},
		std::vector<int> {4, 2}
	};
	const std::vector<std::vector<int>> PRODUCT2 =
	{
		std::vector<int> {-2, 9, 5},
		std::vector<int> {3, 15, 21},
		std::vector<int> {0, 9, 9}
	};
	const std::vector<std::vector<int>> PRODUCT3 =
	{
		std::vector<int> {17, 7},
		std::vector<int> {60, 18},
		std::vector<int> {27, 9}
	};

        //ORIGINAL LINE: int[][] r = new int[A.length][A[0].length];
	//std::vector<std::vector<int>> r = RectangularVectors::RectangularIntVector(A.size(), A[0].size()); // Need to pre-allocate for some reason
        //ORIGINAL LINE: int[][] p = new int[C.length][D[0].length];
	//std::vector<std::vector<int>> p = RectangularVectors::RectangularIntVector(C.size(), D[0].size());
        //ORIGINAL LINE: int[][] s = new int[r.length][C[0].length];
	//std::vector<std::vector<int>> s = RectangularVectors::RectangularIntVector(r.size(), C[0].size());
        //ORIGINAL LINE: int[][] t = new int[s.length][D[0].length];
	//std::vector<std::vector<int>> t = RectangularVectors::RectangularIntVector(s.size(), D[0].size());

	MatMathImpl *u = new MatMathImpl();

	// code to initialize A,B,C,D
	//u->add(A,B,r);

	// Verify the addition
	//if (!Arrays::equals(r[0],SUM[0]) && !Arrays::equals(r[1],SUM[1]) && !Arrays::equals(r[2],SUM[2]))
	{
		std::wcout << L"Add failed." << std::endl;
	}

	//u->multiply(C,D,p);

	// Verify the multiplication
	//if (!Arrays::equals(p[0],PRODUCT[0]) && !Arrays::equals(p[1],PRODUCT[1]))
	{
		std::wcout << L"Multiply failed." << std::endl;
	}

	//u->multiply(r,C,s);

	// Verify the multiplication
	//if (!Arrays::equals(s[0],PRODUCT2[0]) && !Arrays::equals(s[1],PRODUCT2[1]) && !Arrays::equals(s[2],PRODUCT2[2]))
	{
		std::wcout << L"Multiply failed." << std::endl;
	}

	//u->multiply(s,D,t);

	 // Verify the multiplication
	//if (!Arrays::equals(t[0],PRODUCT3[0]) && !Arrays::equals(t[1],PRODUCT3[1]) && !Arrays::equals(t[2],PRODUCT3[2]))
	{
		std::wcout << L"Multiply failed." << std::endl;
	}

	// Display the resulting Matrix
	//u->print(r);
	//u->print(p);
	//u->print(s);
	//u->print(t);

	delete u;
}

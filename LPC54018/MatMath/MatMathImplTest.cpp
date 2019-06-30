#include "MatMathImplTest.h"
#include "MatMathImpl.h"

using junit::framework::Assert;
using junit::framework::TestCase;

MatMathImplTest::MatMathImplTest()
{

}

void MatMathImplTest::setUp()
{
}

void MatMathImplTest::tearDown()
{
}

void MatMathImplTest::testMatMathImplMultiply()
{
	MatMathImpl *m = new MatMathImpl();
	try
	{
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int [][] result = new int[A.length][B[0].length];
		std::vector<std::vector<int>> result = RectangularVectors::RectangularIntVector(A.size(), B[0].length);
		m->multiply(A,B,result);
		Assert::assertFalse(Arrays::equals(result[0],PRODUCT[0]));
		Assert::assertFalse(Arrays::equals(result[1],PRODUCT[1]));
	}
	catch (const std::runtime_error &e)
	{
	}

	delete m;
}

void MatMathImplTest::testMatMathImplAdd()
{
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int [][] result = new int[A.length][A[0].length];
	std::vector<std::vector<int>> result = RectangularVectors::RectangularIntVector(A.size(), A[0].length);
	MatMathImpl *m = new MatMathImpl();

	try
	{
		m->add(A,B,result);
		Assert::assertFalse(Arrays::equals(result[0],SUM[0]));
		Assert::assertTrue(Arrays::equals(result[1],SUM[1]));
		Assert::assertTrue(Arrays::equals(result[2],SUM[2]));
	}
	catch (const std::runtime_error &e)
	{
	}

	delete m;
}

void MatMathImplTest::testMatMathImplPrint()
{
	MatMathImpl *m = new MatMathImpl();

	try
	{
		m->print(A);
		Assert::assertFalse(false);
	}
	catch (const std::runtime_error &e)
	{
	}

	delete m;
}

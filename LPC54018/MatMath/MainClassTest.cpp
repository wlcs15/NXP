#include "MainClassTest.h"
#include "MatMathImpl.h"

using junit::framework::Assert;
using junit::framework::TestCase;

MainClassTest::MainClassTest()
{
}

void MainClassTest::setUp()
{
}

void MainClassTest::tearDown()
{
}

void MainClassTest::testMainClassAddBad()
{
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int [][] result = new int[ABAD.length][ABAD[0].length];
	std::vector<std::vector<int>> result = RectangularVectors::RectangularIntVector(ABAD.size(), ABAD[0].length);
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int [][] expected = new int[ABAD.length][ABAD[0].length];
	std::vector<std::vector<int>> expected = RectangularVectors::RectangularIntVector(ABAD.size(), ABAD[0].length);
	MatMathImpl *u = new MatMathImpl();

	try
	{
		u->add(ABAD,BBAD,result);
		Assert::assertTrue(Arrays::equals(result[0],expected[0]));
		Assert::assertTrue(Arrays::equals(result[1],expected[1]));
		Assert::assertTrue(Arrays::equals(result[2],expected[2]));
	}
	catch (const std::runtime_error &e)
	{
	}

	delete u;
}

void MainClassTest::testMainClassAdd()
{
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int [][] result = new int[A.length][A[0].length];
	std::vector<std::vector<int>> result = RectangularVectors::RectangularIntVector(A.size(), A[0].length);
	MatMathImpl *u = new MatMathImpl();

	try
	{
		u->add(A,B,result);
		Assert::assertFalse(Arrays::equals(result[0],SUM[0]));
		Assert::assertTrue(Arrays::equals(result[1],SUM[1]));
		Assert::assertTrue(Arrays::equals(result[2],SUM[2]));
	}
	catch (const std::runtime_error &e)
	{
	}

	delete u;
}

void MainClassTest::testMainClassMultiplyBad()
{
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int [][] result = new int[ABAD.length][BBAD[0].length];
	std::vector<std::vector<int>> result = RectangularVectors::RectangularIntVector(ABAD.size(), BBAD[0].length);
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int [][] expected = new int[ABAD.length][BBAD[0].length];
	std::vector<std::vector<int>> expected = RectangularVectors::RectangularIntVector(ABAD.size(), BBAD[0].length);
	MatMathImpl *u = new MatMathImpl();

	try
	{
		u->multiply(ABAD,BBAD,result);
		Assert::assertTrue(Arrays::equals(result[0],expected[0]));
		Assert::assertTrue(Arrays::equals(result[1],expected[1]));
		Assert::assertTrue(Arrays::equals(result[2],expected[2]));
	}
	catch (const std::runtime_error &e)
	{
	}

	delete u;
}

void MainClassTest::testMainClassMultiply()
{
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int [][] result = new int[A.length][B[0].length];
	std::vector<std::vector<int>> result = RectangularVectors::RectangularIntVector(A.size(), B[0].length);
	MatMathImpl *u = new MatMathImpl();

	try
	{
		//MainClass.main("");
		u->multiply(A,B,result);
		Assert::assertFalse(Arrays::equals(result[0],PRODUCT[0]));
		Assert::assertFalse(Arrays::equals(result[1],PRODUCT[1]));
		Assert::assertFalse(Arrays::equals(result[2],PRODUCT[2]));
	}
	catch (const std::runtime_error &e)
	{
	}

	delete u;
}

void MainClassTest::testMainClassPrintNull()
{
	std::vector<std::vector<int>> result;
	MatMathImpl *u = new MatMathImpl();

	try
	{
		u->print(std::vector<std::vector<int>>());
		Assert::assertFalse(false);
	}
	catch (const std::runtime_error &e)
	{
	}

	delete u;
}

void MainClassTest::testMainClassPrintBad()
{
	MatMathImpl *u = new MatMathImpl();

	try
	{
		u->print(ABAD);
		Assert::assertFalse(false);
	}
	catch (const std::runtime_error &e)
	{
	}

	delete u;
}

void MainClassTest::testMainClassPrint()
{
	MatMathImpl *u = new MatMathImpl();

	try
	{
		u->print(A);
		Assert::assertFalse(false);
	}
	catch (const std::runtime_error &e)
	{
	}

	delete u;
}

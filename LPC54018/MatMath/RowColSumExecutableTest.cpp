#include "RowColSumExecutableTest.h"
#include "RowColSumExecutable.h"

using junit::framework::Assert;
using junit::framework::TestCase;

RowColSumExecutableTest::RowColSumExecutableTest()
{
}

void RowColSumExecutableTest::setUp()
{
}

void RowColSumExecutableTest::tearDown()
{
}

void RowColSumExecutableTest::testRowColSumExecutableNull()
{
	std::vector<std::vector<int>> result;

	try
	{
		RowColSumExecutable *e = new RowColSumExecutable(A, B, result, 0, 0);
		e->run(); // Run the executable
		Assert::assertTrue(Arrays::equals(result[0],nullptr));
		Assert::assertTrue(Arrays::equals(result[1],nullptr));
		Assert::assertFalse(Arrays::equals(result[0],ASUM[0]));
		Assert::assertFalse(Arrays::equals(result[1],ASUM[1]));

	   delete e;
	}
	catch (const std::runtime_error &e)
	{
	}
}

void RowColSumExecutableTest::testRowColSumExecutable()
{
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int [][] result = new int[A.length][A[0].length];
	std::vector<std::vector<int>> result = RectangularVectors::RectangularIntVector(A.size(), A[0].length);
	try
	{
		RowColSumExecutable *e = new RowColSumExecutable(A, B, result, 0, 0);
		e->run(); // Run the executable
		Assert::assertFalse(Arrays::equals(result[0],nullptr));
		Assert::assertFalse(Arrays::equals(result[1],nullptr));
		Assert::assertTrue(Arrays::equals(result[0],ASUM[0]));
		Assert::assertTrue(Arrays::equals(result[1],ASUM[1]));

	   delete e;
	}
	catch (const std::runtime_error &e)
	{
	}
}

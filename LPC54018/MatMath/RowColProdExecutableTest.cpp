#include "RowColProdExecutableTest.h"
#include "RowColProdExecutable.h"

using junit::framework::Assert;
using junit::framework::TestCase;

RowColProdExecutableTest::RowColProdExecutableTest()
{
}

void RowColProdExecutableTest::setUp()
{
}

void RowColProdExecutableTest::tearDown()
{
}

void RowColProdExecutableTest::testRowColProdExecutableNull()
{
	std::vector<std::vector<int>> result;

	try
	{
		RowColProdExecutable *e = new RowColProdExecutable(A, B, result, 0, 0, A.size());
		e->run(); // Run the executable
		Assert::assertTrue(Arrays::equals(result[0],nullptr));
		Assert::assertTrue(Arrays::equals(result[1],nullptr));
		Assert::assertFalse(Arrays::equals(result[0],APRODUCT[0]));
		Assert::assertFalse(Arrays::equals(result[1],APRODUCT[1]));

		delete e;
	}
	catch (const std::runtime_error &e)
	{
	}
}

void RowColProdExecutableTest::testRowColProdExecutable()
{
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: int [][] result = new int[A.length][B[0].length];
	std::vector<std::vector<int>> result = RectangularVectors::RectangularIntVector(A.size(), B[0].length);
	try
	{
		RowColProdExecutable *e = new RowColProdExecutable(A, B, result, 0, 0, A.size());
		e->run(); // Run the executable
		Assert::assertTrue(Arrays::equals(result[0],nullptr));
		Assert::assertTrue(Arrays::equals(result[1],nullptr));
		Assert::assertFalse(Arrays::equals(result[0],APRODUCT[0]));
		Assert::assertFalse(Arrays::equals(result[1],APRODUCT[1]));

		 delete e;
	}
	catch (const std::runtime_error &e)
	{
	}
}

#pragma once

#include <vector>
#include <stdexcept>

using junit::framework::TestCase;

/**
 * The test class RowColProdExecutableTest.
 *
 * @author  Charles Sherman
 * @version v0.1
 */
class RowColProdExecutableTest : public TestCase
{
public:
	const std::vector<std::vector<int>> A =
	{
		{1,3},
		{1,0},
		{1,2}
	}; // 3x2 Matrix
	const std::vector<std::vector<int>> B =
	{
		{0,0},
		{7,5},
		{2,1}
	}; // 3x2 Matrix
	const std::vector<std::vector<int>> SUM =
	{
		{1,3},
		{8,5},
		{3,3}
	}; // 3x2 Sum
	const std::vector<std::vector<int>> C =
	{
		{1,0,2},
		{-1,3,1}
	}; // 2x3 Matrix
	const std::vector<std::vector<int>> D =
	{
		{3,1},
		{2,1},
		{1,0}
	}; // 3x2 Matrix
	const std::vector<std::vector<int>> PRODUCT =
	{
		{5,1},
		{4,2}
	}; // 2x2 Product
	const std::vector<std::vector<int>> APRODUCT =
	{
		{5,0},
		{0,0}
	}; // 2x2 Product

	/**
	 * Default constructor for test class RowColProdExecutableTest
	 */
	RowColProdExecutableTest();

	/**
	 * Sets up the test fixture.
	 *
	 * Called before every test case method.
	 */
protected:
	virtual void setUp();

	/**
	 * Tears down the test fixture.
	 *
	 * Called after every test case method.
	 */
	virtual void tearDown();

	/**
	 * Test of the print method in the RowColProdExecutable class
	 */
public:
	virtual void testRowColProdExecutableNull();

	/**
	 * Test of the print method in the RowColProdExecutable class
	 */
	virtual void testRowColProdExecutable();
};

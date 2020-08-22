#include "pch.h"


#include <algorithm>


#include "../p21-euler/p21-euler/Divisors.h"


TEST(TestGetDivisors, DivisorsOf220)
{
	Divisors divisors;

	std::deque<unsigned int> ex_divs = { 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110 };
	std::deque<unsigned int> ac_divs = divisors.getDivisors(220);

	std::sort(ac_divs.begin(), ac_divs.end());


	EXPECT_EQ(ex_divs, ac_divs);
}

TEST(TestGetDivisors, DivisorsOf284)
{
	Divisors divisors;

	std::deque<unsigned int> ex_divs = { 1, 2, 4, 71, 142 };
	std::deque<unsigned int> ac_divs = divisors.getDivisors(284);

	std::sort(ac_divs.begin(), ac_divs.end());


	EXPECT_EQ(ex_divs, ac_divs);
}



TEST(TestSumOfDivisors, SumOfDivisorsOf220)
{
	Divisors divisors;
	unsigned int sumDiv = 284;

	EXPECT_EQ(sumDiv, divisors.sumOfDivisors(220));
}


TEST(TestSumOfDivisors, SumOfDivisorsOf284)
{
	Divisors divisors;
	unsigned int sumDiv = 220;

	EXPECT_EQ(sumDiv, divisors.sumOfDivisors(284));
}




TEST(TestSumOfDivisors, SumOfDivisorsOf6)
{
	Divisors divisors;
	unsigned int sumDiv = 6;

	EXPECT_EQ(sumDiv, divisors.sumOfDivisors(6));
}


	

TEST(TestGetSumsOfDivisorsUntil, SumsOfDivisorsUntil7)
{
	Divisors divisors;

	std::deque<numAndSumDivisors> numsAndSums;
	numAndSumDivisors numSum;
	numSum.number = 1;
	numSum.sumOfDivisors = 1;
	numsAndSums.push_back(numSum);

	numSum.number = 2;
	numSum.sumOfDivisors = 1;
	numsAndSums.push_back(numSum);

	numSum.number = 3;
	numSum.sumOfDivisors = 1;
	numsAndSums.push_back(numSum);

	numSum.number = 4;
	numSum.sumOfDivisors = 3;
	numsAndSums.push_back(numSum);

	numSum.number = 5;
	numSum.sumOfDivisors = 1;
	numsAndSums.push_back(numSum);

	numSum.number = 6;
	numSum.sumOfDivisors = 6;
	numsAndSums.push_back(numSum);

	numSum.number = 7;
	numSum.sumOfDivisors = 1;
	numsAndSums.push_back(numSum);

	std::deque<numAndSumDivisors> ac_numsAndSums = divisors.getSumsOfDivisorsUntil(7);


	for (size_t i = 0; i < numsAndSums.size(); ++i)
	{
		EXPECT_EQ(numsAndSums.at(i).number, ac_numsAndSums.at(i).number);
		EXPECT_EQ(numsAndSums.at(i).sumOfDivisors, ac_numsAndSums.at(i).sumOfDivisors);
	}



}



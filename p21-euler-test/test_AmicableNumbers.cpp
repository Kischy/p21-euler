#include "pch.h"

#include "../p21-euler/p21-euler/AmicableNumbers.h"
#include "../p21-euler/p21-euler/Divisors.h"

TEST(TestIsAmicableNumber, ReturnsTrueFor220AndReaches284)
{
	AmicableNumbers an;
	Divisors d;
	std::deque<numAndSumDivisors> numDivs = d.getSumsOfDivisorsUntil(284);

	EXPECT_TRUE(an.isAmicableNumber(220, numDivs));
}

TEST(TestIsAmicableNumber, ReturnsTrueFor284AndReaches220)
{
	AmicableNumbers an;
	Divisors d;
	std::deque<numAndSumDivisors> numDivs = d.getSumsOfDivisorsUntil(220);


	EXPECT_TRUE(an.isAmicableNumber(284, numDivs));
}


TEST(TestIsAmicableNumber, ReturnsFalseFor284AndDoesNotReach220)
{
	AmicableNumbers an;
	Divisors d;
	std::deque<numAndSumDivisors> numDivs = d.getSumsOfDivisorsUntil(219);


	EXPECT_FALSE(an.isAmicableNumber(284, numDivs));
}


TEST(TestGetAmicNumbers, SumOfAmicNumbersUntil284ShouldBe504)
{
	unsigned long ex_sum = 504;

	AmicableNumbers an;
	unsigned long ac_sum = an.getSumOfAmicNumbers(284);


	EXPECT_EQ(ex_sum, ac_sum);
}

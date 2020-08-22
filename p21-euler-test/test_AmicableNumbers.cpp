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
	unsigned long ac_sum = 0;

	AmicableNumbers an;
	std::deque<possAmicableNumber> pANs = an.getPossAmicUntil(284);

	for (const auto& pAN : pANs)
	{
		if (pAN.isAmicable)
		{
			ac_sum += pAN.number;
		}
	}



	EXPECT_EQ(ex_sum, ac_sum);
}

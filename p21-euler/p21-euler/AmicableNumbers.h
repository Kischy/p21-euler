#pragma once


#include "Divisors.h"


struct possAmicableNumber
{
	unsigned int number;
	bool isAmicable = false;
};


class AmicableNumbers
{
private:
	Divisors divisors;


	bool isAmicablePair(numAndSumDivisors lhs, numAndSumDivisors rhs)
	{
		if (lhs.number != rhs.number)
		{
			if (lhs.number == rhs.sumOfDivisors && rhs.number == lhs.sumOfDivisors)
			{
				return true;
			}
		}

		return false;
	}

public:
	unsigned int getSumOfAmicNumbers(const unsigned int upperLimit)
	{
		unsigned long sum = 0;

		std::deque<possAmicableNumber> pANs = getPossAmicUntil(upperLimit);

		for (const auto& pAN : pANs)
		{
			if (pAN.isAmicable)
			{
				sum += pAN.number;
			}
		}

		return sum;
	}


	std::deque<possAmicableNumber> getPossAmicUntil(const unsigned int upperLimit)
	{
		std::deque<numAndSumDivisors> numDivs = divisors.getSumsOfDivisorsUntil(upperLimit);


		std::deque<possAmicableNumber> amicNum;

		for (unsigned int i = 1; i <= upperLimit; ++i)
		{
			possAmicableNumber pan;
			pan.number = i;
			pan.isAmicable = isAmicableNumber(i, numDivs);


			amicNum.push_back(pan);
		}


		return amicNum;
	}



	bool isAmicableNumber(const unsigned int number, const std::deque<numAndSumDivisors> & numDivs)
	{
		numAndSumDivisors num;
		num.number = number;
		num.sumOfDivisors = divisors.sumOfDivisors(number);		

		for (const auto& nd: numDivs)
		{
			if (isAmicablePair(num,nd))
			{
				return true;
			}
		}

		return false;
	}

};


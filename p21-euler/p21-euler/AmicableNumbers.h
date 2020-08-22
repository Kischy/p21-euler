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

public:
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

		unsigned int sumDivNumber = divisors.sumOfDivisors(number);

		for (const auto& nd: numDivs)
		{
			if (number != nd.number)
			{
				if (nd.sumOfDivisors == number && nd.number == sumDivNumber)
				{
					return true;
				}
			}
		}

		return false;
	}

};


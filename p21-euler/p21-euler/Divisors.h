#pragma once

#include <deque>
#include <cmath>

struct numAndSumDivisors
{
	unsigned int number;
	unsigned int sumOfDivisors;
};



class Divisors
{
public:

	std::deque<numAndSumDivisors> getSumsOfDivisorsUntil(const unsigned int number)
	{
		std::deque< numAndSumDivisors> numsAndSums;

		for (unsigned int i = 1; i <= number; ++i)
		{
			numAndSumDivisors nsd;
			nsd.number = i;
			nsd.sumOfDivisors = sumOfDivisors(i);

			numsAndSums.push_back(nsd);
		}


		return numsAndSums;
	}


	unsigned int sumOfDivisors(const unsigned int number)
	{
		unsigned int sum = 0;

		for (const auto div : getDivisors(number))
		{
			sum += div;
		}

		return sum;
	}



	std::deque<unsigned int> getDivisors(const unsigned int number)
	{
		std::deque<unsigned int> divs = {1};

		unsigned int upper = static_cast<unsigned int>(std::sqrt(number)) + 1;

		for (unsigned int i = 2; i < upper ; i++)
		{
			if (number % i == 0)
			{
				unsigned int secDiv = number / i;

				if (i != secDiv)
				{
					divs.push_back(i);
					divs.push_back(secDiv);
				}
				else
				{
					divs.push_back(i);
				}

			}
		}


		return divs;
	}


};


#include <iostream>

#include "AmicableNumbers.h"

using namespace std;

int main()
{
    cout << "Calculation started" << endl;

    AmicableNumbers an;

    int answer_p21 = an.getSumOfAmicNumbers(9999);


    cout << "The answer to problem 21 of project Euler is " << answer_p21 << "." << endl;
}


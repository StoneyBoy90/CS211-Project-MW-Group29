#include "luhn_helper.h"
using namespace std;

bool checkLuhn(string number) //Checks if the credit card number is valid.
{
    int sum = 0; //Stores the sum.
    bool doubleDigit = false; //The farthest right digit is not initially double.

    for(int i = 15; i >= 0; i--) //Cycles through each digit from right to left.
    {
        int digit = number[i] - '0'; //Converts character to integer.

        if(doubleDigit) //Doubles the digit according to Luhn program.
        {
            digit *= 2; //Doubles the digit.

            if(digit > 9) //If greater than 9, subtract 9.
            {
                digit -= 9; //Subracts 9.
            }
        }
        sum += digit; //Adds the digit to the stored sum.
        doubleDigit = !doubleDigit; //Alternates between doubling and not doubling digits.
    }
    return sum % 10 == 0; //Passes if the sum is divisible by 10.
}

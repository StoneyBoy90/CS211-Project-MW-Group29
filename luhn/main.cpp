#include <iostream>
#include <string>
#include "luhn_helper.h"
using namespace std;

int main()
{
    string number; //Stores the credit card number.

    while(true) //Asks for input from the user until a valid 16-digit credit card number is entered.
    {
        cout<<"Please enter a 16-digit credit card number: "; //Asks user for 16 digit credit card number.

        if(!getline(cin, number)) //Checks if input is valid.
        {
            break; //Exits loop.
        }
        if(number == "e" || number == "E") //Exits if the user enters 'e' or 'E'.
        {
            break; //Exits loop.
        }
        if(number.length() != 16)
        {
            cout<<"Credit Card number must be 16 digits."<<endl; //Displays error message if input is not 16 digits.
            continue; //Asks user for input again.
        }

        bool allDigits = true; //Checks if all characters inputed are digits.
        for(int i = 0; i < 16; i++) //Cycles through each character in the input.
        {
            if(number[i] < '0' || number[i] > '9') //
            {
                allDigits = false; //Returns false if a non-digit is found.
                break; //Exits loop.
            }
        }
        if(!allDigits) //Checks if all characters are integers.
        {
            cout<<"Please only enter numbers. No spaces or letters."<<endl; //Displays error message for non-digits.
            continue; //Asks user for input again.
        }
        if(checkLuhn(number)) //Checks if the number passes the Luhn algorithm
        {
            cout<<"Valid Luhn checksum."<<endl; //Displays confirmation of a valid Luhn checksum.    
        }
        else //If invalid Luhn checksum.
        {
            cout<<"Invalid Luhn checksum."<<endl; //Displays error message for an invalid Luhn check.
        }
    }
    return 0; //Ends program.
}
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int bin_to_dec(string);
string dec_to_bin(int);
int hex_to_dec(string);  
string dec_to_hex(int);

// comment 1: Creating the function chartoint to convert string ASCII values to their respective integer values.
int chartoint(char a);


int main() 
{

// comment 2: Sample runs for our functions
	cout<<"100010 binary = "<<bin_to_dec("100010")<<" decimal\n";
	cout<<"001010 binary = "<<bin_to_dec("001010")<<" decimal\n";
	cout<<"111010 binary = "<<bin_to_dec("111010")<<" decimal\n";
	cout<<"010010 binary = "<<bin_to_dec("010010")<<" decimal\n\n";
	
	cout<<"105010 decimal = "<<dec_to_bin(105010)<<" binary\n";
	cout<<"210010 decimal = "<<dec_to_bin(210010)<<" binary\n";
	cout<<"315010 decimal = "<<dec_to_bin(315010)<<" binary\n";
	cout<<"420010 decimal = "<<dec_to_bin(420010)<<" binary\n\n";
	
	cout<<"AA010 hexadecimal = "<<hex_to_dec("AA010")<<" decimal\n";
	cout<<"BB010 hexadecimal = "<<hex_to_dec("BB010")<<" decimal\n";
	cout<<"CC010 hexadecimal = "<<hex_to_dec("CC010")<<" decimal\n";
	cout<<"DD010 hexadecimal = "<<hex_to_dec("DD010")<<" decimal\n\n";
	
	cout<<"105010 decimal = "<<dec_to_hex(105010)<<" hexadecimal\n";
	cout<<"210010 decimal = "<<dec_to_hex(210010)<<" hexadecimal\n";
	cout<<"315010 decimal = "<<dec_to_hex(315010)<<" hexadecimal\n";
	cout<<"420010 decimal = "<<dec_to_hex(420010)<<" hexadecimal\n\n";
	
	
	system("PAUSE");
	return 0;

}


// comment 3: Implementation of our function
int chartoint(char a) {

// comment 4: Since every string value for numbers 0-9 start on the on the ASCII 48, we reduce the value of the ASCII to get the integer values
    a -= 48;


// comment 5: Because of not covering for values A-F, we reduce what's left to get the respective values 10-15 for their char ASCII's. In this case, we took 48 and then 7, making it 55 in total, obtaining the respective integer value
    if (a > 9){
        a -= 7;
    }
    return a;
}

int bin_to_dec(string s) 
{
    int len = s.size();
    int sum = 0;


// comment 6: We loop trough all the string using our function and find the number in decimal
    for (int i = 0; i < len; i++) {
        int elem = chartoint(s[i]);

// comment 7: Using the pow function, we sum up all the values from binary to decimal as follows: 2^(len - 1)*VAL1 + 2^(len - 2)*VAL2 + ... + 2^0*val_N
        sum += pow(2, len - i - 1)*elem;
    }

    return sum;
}	

string dec_to_bin(int n) {
    string num;

// comment 8: We take the mod 2 of the number until its zero and use the built in function to_string to store those values, and then return it at the end of the function
    while (n > 0){
        int digit = n % 2;
        num = to_string(digit) + num;

        n /= 2;
    }

    return num;
}



// comment 9: We repeat the same process as for binary to decimal, but this time using 16 as the base
int hex_to_dec(string s) 
{
    int len = s.size();
    int sum = 0;

    for (int i = 0; i < len; i++) {
        int elem = chartoint(s[i]);
        sum += pow(16, len - i - 1)*elem;
    }

    return sum;
}


// comment 10: We finally do the same as previously with base 16 to obtain the hexadeximal value of the inputted decimal
string dec_to_hex(int n) {
    string hex;

    while (n > 0) {
    int digit = n % 16;

    if (digit < 10) {
        hex = to_string(digit) + hex;
    } else {

// comment 11: If the digit is greater than 10, we print the letter and modifying its ASCII if necessary
        hex = char('A' + digit - 10) + hex;
    }

    n /= 16;
    }
    return hex;
}




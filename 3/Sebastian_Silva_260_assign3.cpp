#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string addbin(string, string);  
string addhex(string, string); 


int main()
{

    // comment 1: we make the test to use for our functions
    cout << "binary 10010 + 11011 = " << addbin("10010", "11011") << endl;
    cout << "binary 101011 + 10010 = " << addbin("101011", "10010") << endl;
    cout << "binary 1110100 + 101010 = " << addbin("1110100", "101010") << endl;
    cout << "binary 1100111 + 111111 = " << addbin("1100111", "111111") << endl;
    cout << "binary 100100 + 111001 = " << addbin("100100", "111001") << endl;

    cout << "hexadecimal 12 + 34 = " << addhex("12", "34") << endl;
    cout << "hexadecimal 9F + 7E = " << addhex("9F", "7E") << endl;
    cout << "hexadecimal B789 + 0AB = " << addhex("B789", "0AB") << endl;
    cout << "hexadecimal 4D + 6C = " << addhex("4D", "6C") << endl;
    cout << "hexadecimal DEF012 + 345 = " << addhex("DEF012", "345") << endl;

	system("PAUSE");
	return 0;
	
}

// comment 2: state the addbin function
string addbin(string bin1, string bin2) {


    // comment 3: get both lengths of bin1 and bin2
    int len1 = bin1.length();
    int len2 = bin2.length();

    // comment 4: compare both lengths and have the max ready for adding 0's
    int maxLength = max(len1, len2);

    // comment 5: add 0's for the bin1 or bin2 if necessary
    while (bin1.length() < maxLength) {
        bin1 = "0" + bin1;
    }
    while (bin2.length() < maxLength) {
        bin2 = "0" + bin2;
    }

    string result = "";

    // comment 6: declare a carry integer for handling the carrying number when summing
    int carry = 0;

    for (int i = maxLength - 1; i >= 0; i--) {

        // comment 7: loop through the numbers and adding them, storing the carrying value
        int sum = (bin1[i] - '0') + (bin2[i] - '0') + carry;
        result = to_string(sum % 2) + result;
        carry = sum / 2;
    }

    // comment 8: if there's a carrying value in the end, put it in the front
    if (carry) {
        result = "1" + result;
    }

    return result;
}

// comment 9: repeating the same process with addbin but in hexadecimal
string addhex(string hex1, string hex2) {

    int len1 = hex1.length();
    int len2 = hex2.length();

    int maxLength = max(len1, len2);

    while (hex1.length() < maxLength) {
        hex1 = "0" + hex1;
    }
    while (hex2.length() < maxLength) {
        hex2 = "0" + hex2;
    }

    string result = "";
    int carry = 0;

    // comment 10: have a string for the possible values in the hexadecimal numbers
    string hexDigits = "0123456789ABCDEF";

    for (int i = maxLength - 1; i >= 0; i--) {


        // comment 11: handling the summing and keeping the carrying value
        int val1;
        if (hex1[i] >= 'A' && hex1[i] <= 'F') {
            val1 = 10 + hex1[i] - 'A';
        } else {
            val1 = hex1[i] - '0';
        }

        int val2;
        if (hex2[i] >= 'A' && hex2[i] <= 'F') {
            val2 = 10 + hex2[i] - 'A';
        } else {
            val2 = hex2[i] - '0';
        }

        int sum = val1 + val2 + carry;
        result = hexDigits[sum % 16] + result;
        carry = sum / 16;
    }

    // comment 12: if there's a carrying value in the end, put it in the front of the array
    if (carry) {
        result = hexDigits[carry] + result;
    }

    return result;
}


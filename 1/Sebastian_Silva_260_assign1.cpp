#include <iostream>
using namespace std;

const int COLS = 5;

int getTotal(int [][COLS], int);
double getAverage(int [][COLS], int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int, int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);

int main()
{
	const int ROWS = 4;

    // comment 1: We establish our Array example number by number.
	int testArray[ROWS][COLS] =
					{ { 0,   1,  0,  1,  0 },
                      { 0,   1,  0,  1,  0 },
                      { 0,   1,  0,  1,  0 },
                      { 0,   1,  0,  1,  0 } };
   

    // comment 2: We call our functions individually to display the total, average, row total, column total, highest, and lowest values.
	cout << "The total of the array elements is "
         << getTotal(testArray, ROWS)
		 << endl;
   

	cout << "The average value of an element is "
		 << getAverage(testArray, ROWS)
		 << endl;


	cout << "The total of row 0 is "
		 << getRowTotal(testArray, 0)
		 << endl;


	cout << "The total of col 2 is "
		 << getColumnTotal(testArray, 2, ROWS)
		 << endl;

     
	cout << "The highest value in row 2 is "
		 << getHighestInRow(testArray, 2)
		 << endl;


	cout << "The lowest value in row 2 is "
		 << getLowestInRow(testArray, 2)
		 << endl;

    system("PAUSE");
	return 0;
}

// comment 3: Defining our Total function used above.
int getTotal(int array[][COLS], int rows)
{
    int total = 0;

    // comment 4: Looping on a double for loop to add all the elements of the array to the total variable.
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < COLS; j++){
            total += array[i][j];
        }
    }

    return total;
}


// comment 5: Defining our Average function used above
double getAverage(int array[][COLS], int rows)
{
    // comment 6: We define the total variable as a Double since we need to return it for this function.
    double total = 0;

    // comment 7: We loop through all the elements again to obtain the total.
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < COLS; j++){
            total += array[i][j];
        }
    }

    // comment 8: We calculate the average by dividing the total to the number of elements on the array.
    double average = total/(COLS*rows);

    return average;
}

// comment 9: We obtain the total of the row "rowToTotal" by looping through all the elements in said row.
int getRowTotal(int array[][COLS], int rowToTotal)
{
    int total = 0;
    for (int i = 0; i < COLS; i++){
        total += array[rowToTotal][i];
    }

    return total;
}

// comment 10: We do the same as the previous function but with "colToTotal".
int getColumnTotal(int array[][COLS], int colToTotal, int rows)
{
    int total = 0;
    for (int i = 0; i < rows; i++){
        total += array[i][colToTotal];
    }

    return total;
}

// comment 11: We loop through the row "rowToSearch" and compare every value with the max function to obtain the maximum value on the row.
int getHighestInRow(int array[][COLS], int rowToSearch)
{
    int highest = 0;
    for (int i = 0; i < COLS; i++){
        highest = max(array[rowToSearch][i], highest);
    }

    return highest;
}


// comment 12: We loop through the row "rowToSearch" and compare every value with the min function to obtain the minimum value on the row.
int getLowestInRow(int array[][COLS], int rowToSearch)
{
    int lowest = array[rowToSearch][0];
    for (int i = 0; i < COLS; i++){
        lowest = min(array[rowToSearch][i], lowest);
    }

    return lowest;
}


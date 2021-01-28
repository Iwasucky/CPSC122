/*
Name: Kai Iwasaki
Class: CPSC 122
Date Submitted: January 28, 2021
Assignment: Project 4
Description: This program takes a file name in the funtion call to print a
			 specified number (x) of prime numbers to in a specified amount 
			 (y) of columns.
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

static int COL_WIDTH = 6;		// set width of columns for fout

bool isPrime(int num, int primes[], int i) {
	// return true if num is prime
	// return false if num is composite
	for(int j = 0; j < i; j++) {
		// loop through all prime numbers found till now
		if (num/primes[j] < 2)
			// there are no numbers that fully divide when divisor is 
			// greater than half of dividend
			return true;
		if (num%primes[j] == 0){
			// if current number fully divides into a prime, number is 
			// composite
			return false;
		}
	}
	return true;		// return true if nothing fully divided
}


//////////////////////////// main /////////////////////////////////
int main(int argc, char* argv[])
{
	if (argc != 2){
		// if number of input arguments is not 2
		cout << "Incorrect number of command line arguments" << endl;
		exit(EXIT_FAILURE);
	}
	
	ofstream fout;			// declare output file
	fout.open(argv[1]);		// match out file as first argument in call
	
	int x, y;			
	// ask for number of prime numbers and store into x
	cout << "How many Prime Numeros, Señor? ";
	cin >> x;			
	// ask for number of columns to print into and store into y
	cout << "How many columns would you like it to be printed in, Señor? ";
	cin >> y;			
	
	// in case of negative numbers for inputs
	if (x < 0 || y < 1) {
		cout << "Error: Invalid input parameters" << endl;
		exit(EXIT_FAILURE);
	}

	int primes[x] = {};		// declare array to store prime numbers into
	
	int currentNumber = 2; 	// first prime is 2
	if (x > 0) {
		// edge case for first prime, since there are nothing in array primes[]
		primes[0] = currentNumber;
		fout << setw(COL_WIDTH) << currentNumber << ' ';
		currentNumber++;
	}
	
	// loop until x number of primes has been found
	for (int i = 1; i < x; i++) {
		if (i%y == 0){
		// new line when column has been reached
			fout << endl;
		}
		
		while(!isPrime(currentNumber, primes, i))
			// loop while incrementing until you find prime number
			currentNumber++;
		
		// store prime into array primes[] and print it to file 
		primes[i] = currentNumber;
		fout << setw(COL_WIDTH) << currentNumber << ' ';
		// increment for next prime search
		currentNumber++;
	} 
}


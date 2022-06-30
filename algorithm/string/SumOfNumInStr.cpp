// C++ program to calculate sum of all numbers present 
// in a string containing alphanumeric characters 
#include <iostream>
#include <string>
using namespace std; 

// Function to calculate sum of all numbers present 
// in a string containing alphanumeric characters 
int findSum(string str) 
{ 
	// A temporary string 
	string temp = "0"; 

	// holds sum of all numbers present in the string 
	int sum = 0; 

	// read each character in input string 
	for (char ch : str) { 
		// if current character is a digit 
		if (isdigit(ch)) 
			temp += ch; 

		// if current character is an alphabet 
		else { 
			// increment sum by number found earlier 
			// (if any) 
			sum += stoi(temp); 

			// reset temporary string to empty 
			temp = "0"; 
		} 
	} 

	// atoi(temp.c_str()) takes care of trailing 
	// numbers 
	return sum + stoi(temp); 
} 

// Driver code 
int main() 
{ 
	// input alphanumeric string 
	string str = "12abc20yz68"; 

	// Function call 
	cout << findSum(str); 

	return 0; 
}

// Functions...

#include<iostream>

using namespace std;
void sum();                // prototype of sum function

int main()
{
	sum();                  // calling sum function here
	return 0;
}

void sum()				// defining sum function here..
{
	int a, b, c;
	cout << "Enter 1st number: ";        // << is an insertion operator
	cin >> a;                            // cin allows to read input.  
										 // >> is an extraction operator   
	cout << "Enter 2nd number: ";
	cin >> b;
	c = a + b;
	cout << "Sum of both the numbers is: " << c << endl;
}
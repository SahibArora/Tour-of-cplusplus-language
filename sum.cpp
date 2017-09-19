// addition of two numbers

#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	cout << "Enter 1st number: ";        // << is an insertion operator
	cin >> a;                            // cin allows to read input.  
										// >> is an extraction operator   
	cout << "Enter 2nd number: ";
	cin >> b;
	c = a + b;
	cout << "Sum of both the numbers is: " << c << endl;
	return 0;
}
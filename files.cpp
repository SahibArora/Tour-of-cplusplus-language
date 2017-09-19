// files     //content in files.txt

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char name[20];
	int marks;
	ifstream fin;                      // making object of fstream
	fin.open("files.txt",ios::in);            // opening the file
	fin.getline(name,20,',');           // reading the input from file through getline function...
	fin >> marks;
	cout << " Name: " << name << " Marks: " << marks << endl;
	return 0;
}
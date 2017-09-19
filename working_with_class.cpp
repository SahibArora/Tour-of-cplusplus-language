// classes

#include<iostream>
#include<string>

using namespace std;
class Student                                   // class makes student as a its own type giving it some properties of its own...
{
	//by default data member will be private..
	int marks;                                 // these are the data members of class
	char name[20];
public:
	void set(int marks1,char* name);              // these are the member-functions of the class 
	void display();                             

};

// defining member-functions of the class

void Student::set(int marks1,char* name1)             // function which sets data of the data members of the class
{
	marks = marks1;
	int n = strlen(name1);
	strncpy(name, name1, n+1);
	name[n+1] = '\0';
}

void Student::display()                           // function which display the content of the class
{
	cout << "Name: " << name << endl;
	cout << "Marks: " << marks << endl;
}

int main()
{
	int marks;
	char name[20];
	Student s;
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the marks: ";
	cin >> marks;
	s.set(marks,name);         // calling the member functions of class with (.) operator
	s.display();               
	return 0;
}
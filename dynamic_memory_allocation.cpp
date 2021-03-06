// dynamic data allocation, constructors and destructors...

#include<iostream>
#include<string>

using namespace std;
class Student                                   // class makes student as a its own type giving it some properties of its own...
{
	//by default data member will be private..
	int marks;                                 // these are the data members of class
	char* name;                              
public:
	Student();                                   // this is a constructor
	void set(int marks1,char* name);              // these are the member-functions of the class 
	void display();           
	~Student();                                   // its a destructor

};

// defining member-functions of the class

Student::Student()                 
{
	name = nullptr;
	marks = 0;
}

void Student::set(int marks1,char* name1)             // function which sets data of the data members of the class
{
	marks = marks1;
	int n = strlen(name1);
	
	name = new char[n+1];   // +1 for the null character

	strncpy(name, name1, n+1);
	name[n] = '\0';
}

void Student::display()                           // function which display the content of the class
{
	cout << "Name: " << name << endl;
	cout << "Marks: " << marks << endl;
}

Student::~Student()
{
	delete[] name;
	name = nullptr;
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
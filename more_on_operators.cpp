//more on operators...

#include<iostream>
#include<cstring>

using namespace std;
class String
{
	char m[100];
public :
	String(const char* p);
	void get() const;
	String& operator +=(char c);          // += operator
};

String::String(const char* p)             // parameterized constructor 
{
	int n = strlen(p);                      // finding the length of p;
	for (int i = 0; i < n; i++)
	{
		m[i] = p[i];                      // copying p into data member of the class.
	}
	                 // or strncpy(m,p,n+1);
	m[n] = '\0';
	
}
void String::get() const                     // returns the m;
{
	cout << m;
}
String& String::operator+=(char c)               // += operator, this operatopr adds a character at the last of the string...
{
	int n;
	if (m[0] != '\0')
	{
		n = strlen(m);
	}
	else
	n = 0;
	m[n] = c;
	m[n + 1] = '\0';
	return *this;
}

int main()
{
	String s("hii, how are ");
	String s2 = "";
	s+= 'u';                        // adding u at the end of data member of s object..
	s.get();
	cout << endl;
	

	/*char name[] = {'s','a','h','i','b','/0'};
	ofstream fout("a.txt");
	//fout.open("a.txt");
	fout << "sahib";
	fout.close();
	ifstream fin("a.txt");
	fin >> name;
	cout << name << endl;*/
	return 0;
}
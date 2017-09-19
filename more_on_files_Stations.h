// More on files....

#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
enum PassType {Student_Pass,Adult_Pass};            
// enum here 
//  Student_Pass has value of 0;
//  Adult_Pass has value of 1;

namespace w2
{
	class Station
	{
	public:
		string name;
		unsigned st_pass;
		unsigned ad_pass;
	
		Station()                     // initializing the data members...
		{
			name = '\0';
			st_pass = 0;
			ad_pass = 0;
		}

		void set(const string& s, unsigned s_pass, unsigned a_pass)    // sets the data members to given values...
		{
			name = s;
			st_pass = s_pass;
			ad_pass = a_pass;
		}

		void update(PassType ps, int n)        // updates the number of passes according to the type...
		{
			if (ps == 0)                   // checking if the PassType ps == Student_Pass....
			{
				if(n < 0)                    // if the n is -ve than subtracting the passes from the quantity we have...
				{
					st_pass = st_pass - (-n);
				}
				else
				{
					st_pass = st_pass + n;
				}
			}
			else
			{
				if (n < 0)
				{
					ad_pass = ad_pass - (-n);
				}
				else
				{
					ad_pass = ad_pass + n;
				}
			}
		}

		unsigned inStock(PassType ps) const             // returns the number of passes accordingly 
		{
			if (ps == 0)
			{
				return st_pass;
			}
			else
			{
				return ad_pass;
			}
		}

		const string& getName() const        // returns the name, data member of class...
		{
			return name;
		}


	};

	class Stations
	{
	public:
		int No_of_Stations;                   
		Station* station = nullptr;
		Stations(const char* filename) 
		{
			ifstream fin;
			fin.open(filename, ios::in);
			string s;
			int n1,n2;
			
			fin >> No_of_Stations;                     // reading the number of stations from the file Stations.dat...  
			fin.ignore();                             // ignoring the ';'
			//station = new Station[No_of_Stations];     
			for (int i = 0; i < No_of_Stations; i++)
			{
				getline(fin, s);                       // reading from file
				getline(fin, s, ';');                 // same thing read twice to eliminate the space after 4; and other numbers in Station.dat 
				fin >> n1;                            // storing st_pass from the file...
				{
					//station[i].update(Student_Pass, n);		 //other ways to store value in Station class's variables...
					//station[i].st_pass = n;                   //  only Possible because station class's data members are public;
				}
				fin >> n2;                           // storing the ad_pass from the file...
				{
					//station[i].update(Adult_Pass,n);           //
					//station[i].ad_pass = n;                     //other ways to store value in Station class's variables...
				}
				{
					station[i].set(s, n1, n2);               // storing all the values into the station's data mebers...
					//station[i].name = s;
				}
				//cout << "Station Names: " << station[i].name << endl;                                    just checking if they are stored or not...
				//cout << "Passes it Got: " << station[i].st_pass << "  " << station[i].ad_pass << endl;
			}
			fin.close();
		}

		void update() const
		{
			int i = 0;
			int* st;
			st = new int[No_of_Stations];
			int* ad;
			ad = new int[No_of_Stations];
			cout << "Passes Sold :" << endl;
			cout << "-------------" << endl;
			while (i < No_of_Stations)
			{
				cout << station[i].getName() << endl;
				//cout << station[i].name << endl;
				cout << " Student Passes sold : ";
				cin >> st[i];
				station[i].update(Student_Pass,-st[i]);       // updating the passes in particular station...
				//station[i].st_pass = station[i].st_pass - st[i];     //other way to do it...   
				//cout << endl;
				cout << " Adult   Passes sold : ";
				cin >> ad[i];
				station[i].update(Adult_Pass, -ad[i]);
				//station[i].ad_pass = station[i].ad_pass - ad[i];     // other way to do it...
				//cout << endl;
				i++;
			}
			cout << endl;
			/*for (int i = 0; i < No_of_Stations; i++)                  // checking if proccessing correctly...
			{
				cout << "St_Pass: " << station[i].st_pass << endl;
				cout << "Ad_Pass: " << station[i].ad_pass << endl;
			}*/
		}

		void restock()
		{
			int i = 0;
			int* st;
			st = new int[No_of_Stations];
			int* ad;
			ad = new int[No_of_Stations];
			cout << "Passes Added :" << endl;
			cout << "--------------" << endl;
			while (i < No_of_Stations)
			{
				cout << station[i].getName() << endl;
				//cout << station[i].name << endl;
				cout << " Student Passes added :";
				cin >> st[i];
				
				station[i].update(Student_Pass,st[i]);
				//station[i].st_pass = station[i].st_pass + st[i];    // other way to do it as station's data members are public:
				
				cout << " Adult   Passes added :";
				cin >> ad[i];
				
				station[i].update(Adult_Pass, ad[i]);
				//station[i].ad_pass = station[i].ad_pass + ad[i];      // other way to do it...
				i++;
			}
		 	/*for (int i = 0; i < No_of_Stations; i++)               // checking if its processing accordingly...
 			{                           
				cout << "St_Pass: " << station[i].st_pass << endl;
				cout << "Ad_Pass: " << station[i].ad_pass << endl;
			}*/
			cout << endl;
		}

		void report() const
		{
			cout << "Passes in Stock : Student Adult" << endl;
			cout << "-------------------------------" << endl;
			
			//cout << station[0].name << "               " << station[0].st_pass << "   " << station[0].ad_pass << endl;

			for (int i = 0; i < No_of_Stations; i++)
			{
				cout.width(22);                                // aligning the output accordingly...
				cout.setf(ios::adjustfield,ios::left);            
				cout << station[i].getName();                  
				cout.width(6);
				cout << station[i].inStock(Student_Pass);
				cout << station[i].inStock(Adult_Pass) << endl;
			}
		}
		~Stations()
		{
			delete [] station;                // deleteing the memory allocated...
		}
	};
}

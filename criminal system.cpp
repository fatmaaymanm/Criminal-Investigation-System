#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <string>
using namespace std;

struct user
{
	string id;
	string username;
	string password;
	int age;
	string jobtitle;
};



int main()

{
	string username[15];
	string password[15];
	bool found = 0;
	int crimeorcriminal;
	int choice;
	
	user officeroradmin[100];


	officeroradmin[0].username = "aliragy";
	officeroradmin[0].password = "1234";


	cout << "PLEASE ENTER YOUR USERNAME";
	cin >> username;

	cout << "PLEASE ENTER YOUR PASSWORD";
	cin >> password;


	
	for (int i = 0; i < 100; i++)

	{
		if (username == officeroradmin[i].username && password == officeroradmin[i].password)
		{
			
			found = 1;
			
			
				cout << "login successful";

				cout << "1-crimes" << endl;
				cout << "2-criminals" << endl;

				cin >> crimeorcriminal;

				



				switch (crimeorcriminal)
				{


				 case'1':

				   {
					//for(int i==0;i>size.arrayofcrimes;i++)
					//{cout << crimes[i]<<endl;}

					if (officeroradmin[i].jobtitle == "admin")
					{
						cout << "1-add crime" << endl;
						cout << "2-update crime details" << endl;
						cout << "3-delete crime" << endl;
						cout << "4-display crime" << endl;
						cout << "5-back to menu" << endl;
						cout << "enter your choice" << endl;
						cin >> choice;


						switch (choice)

						{
						  case '1':
						  {
						
						
						
						  }



						  case '2':
						  {



						  }


						  case '3':
						  {



						  }


						  case '4':
						  {



						  }

						  case '5':
						  {



						  }


						}
					}
				   }

                 
				 case'2':

				 {
					 //for(int i==0;i>size.arrayofcrimes;i++)
					 //{cout << criminals[i]<<endl;}

					 if (officeroradmin[i].jobtitle == "admin")
					 {
						 cout << "1-add criminal" << endl;
						 cout << "2-update criminal details" << endl;
						 cout << "3-delete criminal" << endl;
						 cout << "4-display criminal" << endl;
						 cout << "5-back to menu" << endl;
						 cout << "enter your choice" << endl;
						 cin >> choice;


						 switch (choice)

						 {
						 case '1':
						 {



						 }



						 case '2':
						 {



						 }


						 case '3':
						 {



						 }


						 case '4':
						 {



						 }

						 case '5':
						 {



						 }


				   

				}

				
			


		}
	}
    
	










	         }

        }
#include <iostream>
using namespace std;

void displayallcrimesformat()

{
    cout << "crime name \t" << "crime id\t" << "crime type\t" << "crime date\t" << "crime time\t" << "number of criminals\t" << endl;

    cout << crimeregistry[i].name << "\t" << crimeregistry[i].crimeid <<"\t"<< crimeregistry[i].crimetype << "/t" << crimeregistry[i].crimeday << "/" << crimeregistry[i].crimemonth << "/" << crimeregistry[i].crimeyear << "\t" << crimeregistry[i].crimehour << ":" << crimeregistry.crimeminute <<"t" << crimeregistry[i].nOfCriminals << endl;

}

void printcrime()
{
    cout << "crime name: " << crimeregistry[i].name << endl;
    cout << "crime id: " << crimeregistry[i].crimeid << endl;
    cout << "crime type: " << crimeregistry[i].crimetype << endl;
    cout << "crime date: " << crimeregistry[i].crimeday <<"/"<< crimeregistry[i].crimemonth << "/" << crimeregistry[i].crimeyear << endl;
    cout << "crime time: " << crimeregistry[i].crimehour << ":" << crimeregistry.crimeminute << endl;
    cout << "number of criminals: " << crimeregistry[i].nOfCriminals << endl;
}

void displayallcriminalsformat()

{
    cout << "criminal name\t" << "criminal id\t" << "criminal age\t" << "criminal birthday\t" << "number of crimes commited\t" << "number of judgementyears" << endl;

    cout<< criminalregistry[i].name <<"\t"<< criminalregistry[i].criminalid <<"\t"<< criminalregistry[i].criminalage<<"\t"<< criminalregistry[i].criminalbirthday << "/" << criminalregistry[i].criminalbirthmonth << "/" << criminalregistry[i].criminalbirthyear<<"\t"<< criminalregistry[i].numofcrimes<<"\t"<< criminalregistry[i].criminalJudgementYears << endl;
}

void printcriminal()
{
    cout << "criminal name: " << criminalregistry[i].name << endl;
    cout << "criminal id: " << criminalregistry[i].criminalid << endl;
    cout << "criminal age: " << criminalregistry[i].criminalage << endl;
    cout << "criminal birthday: " << criminalregistry[i].criminalbirthday << "/" << criminalregistry[i].criminalbirthmonth << "/" << criminalregistry[i].criminalbirthyear << endl;
    cout << "number of crimes commited: " << criminalregistry[i].numofcrimes << endl;
    cout << "number of judgementyears: " << criminalregistry[i].criminalJudgementYears << endl;
}



void searchcriminal()

{
    int id;

    bool foundcriminal = 0;

    
       
        cout << "please enter the criminal id you want to search for";
         
        cin >> id;

        for (int i = 0; i < criminalarraysize; i++)

        {
            if (id == criminal[i].criminalid)
            {
                bool foundcriminal = 1;

                printcriminal();

            }

            while (foundcriminal == 0)
            {
                cout << "please enter a valid id to search for";
                system("pause");
                system("cls");
                searchcriminal();
            }


        }

       bool foundcriminal = 0;
}


void searchcrime()

{
    int id;

    bool foundcrime = 0;



    cout << "please enter the crime id you want to search for";

    cin >> id;

    for (int i = 0; i < crimearraysize; i++)

    {
        if (id == crimeregistry[i].criminalid)
        {
            bool foundcrime = 1;

            printcrime();

        }

        while (foundcrime == 0)
        {
            cout << "please enter a valid id to search for";
            system("pause");
            system("cls");
            searchcrime();
        }


    }
    bool foundcrime = 0;
}

void displayallcrimes()
{
    for (int i = 0; i < crimearraysize; i++)
    
    {
        displayallcrimesformat();
    }
}

void displayallcriminals()

{
    for (int i = 0; i < criminalarraysize; i++)

    {
        displayallcriminalsformat();
    }
}



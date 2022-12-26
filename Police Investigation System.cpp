// Police Investigation System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <array>
using namespace std;

int crimeArraySize = 0;
int criminalArraySize = 0;
int x;



struct crime
{
    int crimeID = 0;
    char crimeName[100] = {};
    char crimeType[100] = {};
    int crimeDay = 0;
    int crimeMonth = 0;
    int crimeYear = 0;
    int crimeHour = 0;
    int crimeMinute = 0;
    int nOfCriminals = 0;
    int criminalsID[100] = {};
    bool flag = 0;

} crimes;

struct criminal
{
    int criminalID = 0;
    char criminalName[100] = {};
    int criminalAge = 0;
    int crimianlBirthDay = 0;
    int crimianlBirthMonth = 0;
    int crimianlBirthYear = 0;
    int numOfcrimes = 0;
    float criminalJudgementYears = 0;
    bool flag = 0;
};

crime* crimeRegistry{ new crime[crimeArraySize]{} };
criminal* criminalRegistry{ new criminal[criminalArraySize]{} };



void addCrime();

void addCriminal();

void deleteCrime();

void deleteCriminal();


int main()
{

    return 0;
}

void addCrime()
{
    ++crimeArraySize;

    cout << "Enter crime ID: ";
    cin >> crimeRegistry[crimeArraySize - 1].crimeID;
    cin.ignore();
    cout << "Enter crime name: ";
    gets_s(crimeRegistry[crimeArraySize - 1].crimeName, 100);
    cout << "Enter crime Type: ";
    gets_s(crimeRegistry[crimeArraySize - 1].crimeType, 100);
    cout << "Enter crime date: ";
    cin >> crimeRegistry[crimeArraySize - 1].crimeDay;
    cin >> crimeRegistry[crimeArraySize - 1].crimeMonth;
    cin >> crimeRegistry[crimeArraySize - 1].crimeYear;
    cout << "Enter crime time: ";
    cin >> crimeRegistry[crimeArraySize - 1].crimeHour;
    cin >> crimeRegistry[crimeArraySize - 1].crimeMinute;
    cout << "Enter number of criminals: ";
    cin >> crimeRegistry[crimeArraySize - 1].nOfCriminals;

    for (int i = 0; i < crimeRegistry[crimeArraySize - 1].nOfCriminals; i++)
    {
        cout << "Enter criminal " << i + 1 << " ID: ";
        cin >> crimeRegistry[crimeArraySize - 1].criminalsID[i];
    }
}

void deleteCrime()
{
    int ID = 0;
    cout << "Enter the ID of the crime: ";
    cin >> ID;

    if (crimeArraySize == 1 && crimeRegistry[0].crimeID == ID)
    {
        crimeArraySize--;
        cout << "The crime is deleted sucessfully!";
        
    }
    for (int i = 0; i < crimeArraySize; i++)
    {
        if (crimeRegistry[i].crimeID == ID) 
        {
            for (int j = i; j < crimeArraySize - 1; j++)
            {
                crimeRegistry[j].crimeID = crimeRegistry[j + 1].crimeID;
                strcpy_s(crimeRegistry[j].crimeName, crimeRegistry[j + 1].crimeName);
                strcpy_s(crimeRegistry[j].crimeType, crimeRegistry[j + 1].crimeType);
                crimeRegistry[j].crimeDay = crimeRegistry[j + 1].crimeDay;
                crimeRegistry[j].crimeMonth = crimeRegistry[j + 1].crimeMonth;
                crimeRegistry[j].crimeYear = crimeRegistry[j + 1].crimeYear;
                crimeRegistry[j].crimeHour = crimeRegistry[j + 1].crimeHour;
                crimeRegistry[j].crimeMinute = crimeRegistry[j + 1].crimeMinute;
                crimeRegistry[j].nOfCriminals = crimeRegistry[j + 1].nOfCriminals;
                for (int k = 0; k < crimeRegistry[j].nOfCriminals; k++)
                {
                    crimeRegistry[j].criminalsID[k] = crimeRegistry[j + 1].criminalsID[k];
                }

            }
            cout << "The crime is deleted sucessfully!";
            crimeArraySize--; 
            break; 
        }
    }
}

void addCriminal()
{
    ++criminalArraySize;

    cout << "Enter criminal ID: ";
    cin >> criminalRegistry[criminalArraySize - 1].criminalID;
    cin.ignore();
    cout << "Enter criminal name: ";
    gets_s(criminalRegistry[criminalArraySize - 1].criminalName, 100);
    cout << "Enter criminal age: ";
    cin >> criminalRegistry[criminalArraySize - 1].criminalAge;
    cout << "Enter criminal birth date: ";
    cin >> criminalRegistry[criminalArraySize - 1].crimianlBirthDay;
    cin >> criminalRegistry[criminalArraySize - 1].crimianlBirthMonth;
    cin >> criminalRegistry[criminalArraySize - 1].crimianlBirthYear;
    cout << "Enter number of crimes done by criminal: ";
    cin >> criminalRegistry[criminalArraySize - 1].numOfcrimes;
    cout << "Enter criminal judgement years: ";
    cin >> criminalRegistry[criminalArraySize - 1].criminalJudgementYears;
}

void deleteCriminal()
{
    int ID = 0;
    cout << "Enter the ID of the criminal: ";
    cin >> ID;

    if (criminalArraySize == 1 && criminalRegistry[0].criminalID == ID)
    {
        criminalArraySize--;
        cout << "The criminal data is deleted sucessfully!";

    }
    for (int i = 0; i < criminalArraySize; i++)
    {
        if (criminalRegistry[i].criminalID == ID)
        {
            for (int j = i; j < criminalArraySize - 1; j++)
            {
                criminalRegistry[j].criminalID = criminalRegistry[j + 1].criminalID;
                strcpy_s(criminalRegistry[j].criminalName, criminalRegistry[j + 1].criminalName);
                criminalRegistry[j].criminalAge = criminalRegistry[j + 1].criminalAge;
                criminalRegistry[j].crimianlBirthDay = criminalRegistry[j + 1].crimianlBirthDay;
                criminalRegistry[j].crimianlBirthMonth = criminalRegistry[j + 1].crimianlBirthMonth;
                criminalRegistry[j].crimianlBirthYear = criminalRegistry[j + 1].crimianlBirthYear;
                criminalRegistry[j].numOfcrimes = criminalRegistry[j + 1].numOfcrimes;
                criminalRegistry[j].criminalJudgementYears = criminalRegistry[j + 1].criminalJudgementYears;

            }
            cout << "The criminal data is deleted sucessfully!";
            criminalArraySize--;
            break;
        }
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

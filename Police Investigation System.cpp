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
    int* criminalsID{ new int[nOfCriminals]{} };
    char temp = ' ';

} crimes;

struct criminal
{
    int criminalID;
    string criminalName;
    int criminalAge;
    int crimianlBirthDay;
    int crimianlBirthMonth;
    int crimianlBirthYear;
    int numOfcrimes;
    float criminalJudgementYears;
};

crime* crimeRegistry{ new crime[crimeArraySize]{} };
criminal* criminalRegistry{ new criminal[criminalArraySize]{} };



void addCrime()
{
    ++crimeArraySize;
    
    
    cin >> crimeRegistry[crimeArraySize - 1].crimeID;
    cin.ignore();
    gets_s(crimeRegistry[crimeArraySize-1].crimeName,100);
    gets_s(crimeRegistry[crimeArraySize - 1].crimeType, 100);
    cin >> crimeRegistry[crimeArraySize - 1].crimeDay;
    cin >> crimeRegistry[crimeArraySize - 1].crimeMonth;
    cin >> crimeRegistry[crimeArraySize - 1].crimeYear;
    cin >> crimeRegistry[crimeArraySize - 1].crimeHour;
    cin >> crimeRegistry[crimeArraySize - 1].crimeMinute;
    cin >> crimeRegistry[crimeArraySize - 1].nOfCriminals;
    for (int i = 0; i < crimeRegistry[crimeArraySize - 1].nOfCriminals; i++)
    {
        cin >> crimeRegistry[crimeArraySize - 1].criminalsID[i];
    }
}






int main()
{
    addCrime();
    return 0;
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

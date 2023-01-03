

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <array>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;


int crimeArraySize = 0;
int criminalArraySize = 0;
int x;
char y[15];

void login();
void MainMenu();
void CrimeMenu(char username[]);
void CriminalMenu(char username[]);
void addCrime();
void addCriminal();
void deleteCrime();
void deleteCriminal();
void updateCrime();
void updateCriminal();
void searchcriminal();
void displayallcrimes();
void displayallcriminals();
void searchcrime();
void crimeBubbleSort();
void criminalBubbleSort();

struct user
{
    int id = 0;
    char username[15] = {};
    char password[15] = {};
    int age = 0;
    char jobtitle[15] = {};

};


struct crime
{
    int crimeID = 0;
    char crimeName[15] = {};
    char crimeType[15] = {};
    int crimeDay = 0;
    int crimeMonth = 0;
    int crimeYear = 0;
    int crimeHour = 0;
    int crimeMinute = 0;
    int criminalID = 0;
    bool flag = 0;

};


struct criminal
{
    int criminalID = 0;
    char criminalName[15] = {};
    int criminalAge = 0;
    int criminalBirthDay = 0;
    int criminalBirthMonth = 0;
    int criminalBirthYear = 0;
    int numOfcrimes = 0;
    float criminalJudgementYears = 0;
    bool flag = 0;
};

struct user officeroradmin[100] = { {1, "aliragy", "1234", 20, "officer"}, {2, "fatma", "2003", 19, "admin"} };
crime* crimeRegistry{ new crime[crimeArraySize]{} };
criminal* criminalRegistry{ new criminal[criminalArraySize]{} };




int main()
{
    login();
    delete[] crimeRegistry;
    delete[] criminalRegistry;
    return 0;
}

void displayallcrimes()

{
    crimeBubbleSort();
    cout << '\n' << setw(20) << "crime name" << setw(20) << "crime id" << setw(20) << "crime type" << setw(20) << "crime date" << setw(20) << "crime time" << setw(20) << "Criminals IDs" << endl;
    cout << "\n\n====================================================================================================================================\n\n";
    for (int i = 0; i < crimeArraySize; i++)

    {
       
        cout << setw(20) << crimeRegistry[i].crimeName << setw(20) << crimeRegistry[i].crimeID << setw(20) << crimeRegistry[i].crimeType << "\t\t" << crimeRegistry[i].crimeDay << "/" << crimeRegistry[i].crimeMonth << "/" << crimeRegistry[i].crimeYear << "\t\t" << crimeRegistry[i].crimeHour << ":" << crimeRegistry[i].crimeMinute << setw(20) << crimeRegistry[i].criminalID;


        cout << endl;
    }

    cout << "you will be redirected to main menu " << endl;

    system("pause");
    system("cls");

    MainMenu();
}



void displayallcriminals()

{
    criminalBubbleSort();
    cout << endl << setw(20) << "criminal name" << setw(20) << "criminal id" << setw(20) << "criminal age" << setw(20) << "criminal birthday" << setw(30) << "number of crimes committed" << setw(30) << "number of judgement years" << endl;
    cout << "\n\n========================================================================================================================================================\n\n";
    for (int i = 0; i < criminalArraySize; i++)
    {

        cout << setw(20) << criminalRegistry[i].criminalName << setw(20) << criminalRegistry[i].criminalID << setw(20) << criminalRegistry[i].criminalAge << "\t\t" << criminalRegistry[i].criminalBirthDay << "/" << criminalRegistry[i].criminalBirthMonth << "/" << criminalRegistry[i].criminalBirthYear << setw(30) << criminalRegistry[i].numOfcrimes << setw(30) << criminalRegistry[i].criminalJudgementYears << endl;

    }

    cout << "you will be redirected to main menu " << endl;

    system("pause");
    system("cls");
    
    MainMenu();



}


void searchcriminal()

{
    int id;
    char othersearch;

    bool foundcriminal = 0;



    cout << "please enter the criminal id you want to search for " << endl;

    cin >> id;

    for (int i = 0; i < criminalArraySize; i++)

    {
        if (id == criminalRegistry[i].criminalID)
        {
            foundcriminal = 1;

            cout << "criminal name: " << criminalRegistry[i].criminalName << endl;
            cout << "criminal id: " << criminalRegistry[i].criminalID << endl;
            cout << "criminal age: " << criminalRegistry[i].criminalAge << endl;
            cout << "criminal birthday: " << criminalRegistry[i].criminalBirthDay << "/" << criminalRegistry[i].criminalBirthMonth << "/" << criminalRegistry[i].criminalBirthYear << endl;
            cout << "number of crimes commited: " << criminalRegistry[i].numOfcrimes << endl;
            cout << "number of judgement years: " << criminalRegistry[i].criminalJudgementYears << endl;
            break;


        }

    }


    if (foundcriminal == 0)
    {
        cout << "please enter a valid id to search for";
    }


    cout << "Do you want to search for other criminal?" << endl;

    cout << "if yes press Y if no press N" << endl;

    cin >> othersearch;

    switch (othersearch)

    {
    case 'Y':

        system("cls");
        searchcriminal();
        break;

    case 'N':

        system("cls");
        MainMenu();
        break;

    default:

        cout << "Invalid Input\n You will be directed to the main menu\n";
        system("pause");
        system("cls");
        MainMenu();

    }

}


void searchcrime()

{
    int id;
    char othersearch;
    bool foundcrime = 0;



    cout << "please enter the crime id you want to search for" << endl;

    cin >> id;

    for (int i = 0; i < crimeArraySize; i++)

    {
        if (id == crimeRegistry[i].crimeID)
        {
            foundcrime = 1;

            cout << "crime name: " << crimeRegistry[i].crimeName << endl;
            cout << "crime id: " << crimeRegistry[i].crimeID << endl;
            cout << "crime type: " << crimeRegistry[i].crimeType << endl;
            cout << "crime date: " << crimeRegistry[i].crimeDay << "/" << crimeRegistry[i].crimeMonth << "/" << crimeRegistry[i].crimeYear << endl;
            cout << "crime time: " << crimeRegistry[i].crimeHour << ":" << crimeRegistry[i].crimeMinute << endl;
            cout << "Criminal ID: " << crimeRegistry[i].criminalID << endl;



        }


    }

    if (foundcrime == 0)
    {
        cout << "please enter a valid id to search for";
    }

    cout << "Do you want to search for other criminal?" << endl;

    cout << "if yes press Y if no press N" << endl;

    cin >> othersearch;

    switch (othersearch)

    {
    case 'Y':

        system("cls");
        searchcrime();
        break;

    case 'N':

        system("cls");
        MainMenu();
        break;

    default:

        cout << "Invalid Input\n You will be directed to the main menu\n";
        system("pause");
        system("cls");
        MainMenu();

    }

}


void login()
{
    char username[15];
    char password[15];
    bool found = 0;
    bool correct = 0;
    int k = 0;


    cout << "\n\n\n\n\n\t\t\t\t\t ======================================= \n\t\t\t\t\t      CRIMINAL INVESTIGATION SYSTEM \n\t\t\t\t\t =======================================";
    cout << "\n\n\n\t\t\t\t\tUSERNAME: ";
    cin >> username;
    strcpy_s(y, username);

    cout << "\n\t\t\t\t\tPASSWORD: ";
    cin >> password;

    for (int i = 0; i < 100; i++)
    {
        if (strcmp(username, officeroradmin[i].username) == 0 || strcmp(password, officeroradmin[i].password) == 0)
        {
            found = 1;
            if (strcmp(username, officeroradmin[i].username) == 0 && strcmp(password, officeroradmin[i].password) == 0)
            {
                correct = 1;
                break;
            }
        }
    }

    if (found == 1 && correct == 1)
    {
        cout << "\n\t\t\t\t\t\tLOGIN SUCCESSFUL\n";
        system("pause");
        system("cls");
        MainMenu();

    }
    else if (found == 1 && correct == 0)
    {
        cout << "\n\t\t\t\t\t\tUsername or Password is incorrect\n";
        cout << "\n\t\t\t\t\t\tDo you want to exit the program?\n\t\t\t\t\t\t Enter: \n\t\t\t\t\t\t Y if Yes\n\t\t\t\t\t\t N if No\n";
        char choice8;
        cin >> choice8;
        switch (choice8)
        {

        case('Y'):
            exit(0);
            break;

        case('N'):
            system("cls");
            login();
            break;

        default:
            cout << "\n\t\t\t\t\t\tInvalid Input\n\t\t\t\t\t\t You will be directed to login again\n";
            system("pause");
            system("cls");
            login();
            break;
        }
        
        
    }
    else
    {
        cout << "\n\t\t\t\t\t\tUser not found\n";
        cout << "\n\t\t\t\t\t\tDo you want to exit the program?\n\t\t\t\t\t\t Enter: \n\t\t\t\t\t\t Y if Yes\n\t\t\t\t\t\t N if No\n";
        char choice8;
        cin >> choice8;
        switch (choice8)
        {

        case('Y'):
            exit(0);
            break;

        case('N'):
            system("cls");
            login();
            break;

        default:
            cout << "\n\t\t\t\t\t\tInvalid Input\n\t\t\t\t\t\t You will be directed to login again\n";
            system("pause");
            system("cls");
            login();
            break;
        }

    }
}

void MainMenu()
{
    int choice = 0;
    cout << "\n\n\n\n\n\t\t\t\t\t ======================================= \n\t\t\t\t\t               MAIN MENU  \n\t\t\t\t\t ======================================= \n\t\t\t\t\t " << endl;

    cout << " \n\n\t\t\t\t\t1. Crimes" << endl;
    cout << " \n\n\t\t\t\t\t2. Criminals" << endl;
    cout << " \n\n\t\t\t\t\t3. Back to Login" << endl;
    cout << " \n\n\t\t\t\t\t4. Exit program" << endl;
    cout << " \n\n\t\t\t\t\tEnter your choice (1, 2, 3 or 4): ";
    cin >> choice;

    switch (choice)
    {

    case (1):
        CrimeMenu(y);
        break;

    case (2):
        CriminalMenu(y);
        break;

    case (3):
        system("cls");
        login();
        break;

    case (4):
        exit(0);

    default:
        cout << "\n\n\t\t\t\t\tInvalid Input! Try Again!";
        MainMenu();
        break;
    }
}

void CrimeMenu(char username[])
{
    bool view = 0;
    int choice1 = 0;

    for (int i = 0; i < 100; i++)
    {
        if (strcmp(username, officeroradmin[i].username) == 0)
        {
            if (strcmp(officeroradmin[i].jobtitle, "admin") == 0)
            {
                view = 1;
                break;
            }
            else if (strcmp(officeroradmin[i].jobtitle, "officer") == 0)
            {
                view = 0;
                break;
            }
        }
    }

    if (view == 1)
    {
        cout << "\n\n\n\n\n\t\t\t\t\t ======================================= \n\t\t\t\t\t               CRIMES MENU\n\t\t\t\t\t ======================================= \n\t\t\t\t\t" << endl;

        cout << " \n\n\t\t\t\t\t1. Add New Crime" << endl;
        cout << " \n\n\t\t\t\t\t2. Delete a Crime" << endl;
        cout << " \n\n\t\t\t\t\t3. Display all Crimes" << endl;
        cout << " \n\n\t\t\t\t\t4. Update a Crime" << endl;
        cout << " \n\n\t\t\t\t\t5. Search for a Crime" << endl;
        cout << " \n\n\t\t\t\t\t6. Back to Main Menu" << endl;
        cout << " \n\n\t\t\t\t\tEnter your choice (1, 2, 3, 4, 5 or 6): ";
        cin >> choice1;

        switch (choice1)
        {

        case (1):

            addCrime();

            break;

        case (2):

            deleteCrime();

            break;

        case (3):

            displayallcrimes();

            break;

        case (4):

            updateCrime();

            break;

        case (5):

            searchcrime();

            break;

        case (6):
            system("cls");
            MainMenu();

        default:
            cout << "\n\n\t\t\t\t\tInvalid Input! Try Again!";
            CrimeMenu(y);
            break;
        }
    }
    else if (view == 0)
    {
        cout << "\n\n\n\n\n\t\t\t\t\t ======================================= \n\t\t\t\t\t               CRIMES MENU\n\t\t\t\t\t ======================================= \n\t\t\t\t\t               " << endl;

        cout << " \n\n\t\t\t\t\t1. Display all Crimes" << endl;
        cout << " \n\n\t\t\t\t\t2. Search for a Crime" << endl;
        cout << " \n\n\t\t\t\t\t3. Back to Main Menu" << endl;
        cout << " \n\n\t\t\t\t\tEnter your choice (1, 2 or 3): ";
        cin >> choice1;

        switch (choice1)
        {

        case (1):

            displayallcrimes();

            break;

        case (2):

            searchcrime();

            break;

        case (3):
            system("cls");
            MainMenu();

        default:
            cout << "\n\n\t\t\t\t\tInvalid Input! Try Again!";
            CrimeMenu(y);
            break;
        }
    }
}

void CriminalMenu(char username[])
{
    bool view = 0;
    int choice2 = 0;

    for (int i = 0; i < 100; i++)
    {
        if (strcmp(username, officeroradmin[i].username) == 0)
        {
            if (strcmp(officeroradmin[i].jobtitle, "admin") == 0)
            {
                view = 1;
                break;
            }
            else if (strcmp(officeroradmin[i].jobtitle, "officer") == 0)
            {
                view = 0;
                break;
            }
        }
    }

    if (view == 1)
    {
        cout << "\n\n\n\n\n\t\t\t\t\t ======================================= \n\t\t\t\t\t               CRIMINALS MENU\n\t\t\t\t\t ======================================= \n\t\t\t\t\t" << endl;

        cout << " \n\n\t\t\t\t\t1. Add New Criminal" << endl;
        cout << " \n\n\t\t\t\t\t2. Delete a Criminal" << endl;
        cout << " \n\n\t\t\t\t\t3. Display all Criminals" << endl;
        cout << " \n\n\t\t\t\t\t4. Update a Criminal" << endl;
        cout << " \n\n\t\t\t\t\t5. Search for a Criminal" << endl;
        cout << " \n\n\t\t\t\t\t6. Back to Main Menu" << endl;
        cout << " \n\n\t\t\t\t\tEnter your choice (1, 2, 3, 4, 5 or 6): ";
        cin >> choice2;

        switch (choice2)
        {

        case (1):

            addCriminal();

            break;

        case (2):

            deleteCriminal();

            break;

        case (3):

            displayallcriminals();

            break;

        case (4):

            updateCriminal();

            break;

        case (5):

            searchcriminal();

            break;

        case (6):
            system("cls");
            MainMenu();

        default:
            cout << "\n\n\t\t\t\t\tInvalid Input! Try Again!";
            CriminalMenu(y);
            break;
        }
    }
    else if (view == 0)
    {
        cout << "\n\n\n\n\n\t\t\t\t\t ======================================= \n\t\t\t\t\t               CRIMINALS MENU\n\t\t\t\t\t ======================================= \n\t\t\t\t\t" << endl;

        cout << " \n\n\t\t\t\t\t1. Display all Criminals" << endl;
        cout << " \n\n\t\t\t\t\t2. Search for a Criminal" << endl;
        cout << " \n\n\t\t\t\t\t3. Back to Main Menu" << endl;
        cout << " \n\n\t\t\t\t\tEnter your choice (1, 2 or 3): ";
        cin >> choice2;

        switch (choice2)
        {

        case (1):

            displayallcriminals();

            break;

        case (2):

            searchcriminal();

            break;

        case (3):
            system("cls");
            MainMenu();

        default:
            cout << " \n\n\t\t\t\t\tInvalid Input! Try Again!";
            CriminalMenu(y);
            break;
        }
    }

}

void addCrime()
{
    
    ++crimeArraySize;

    cout << "Enter crime ID: ";
    cin >> crimeRegistry[crimeArraySize - 1].crimeID;
    cin.ignore();
    cout << "Enter crime name: ";
    gets_s(crimeRegistry[crimeArraySize - 1].crimeName, 15);
    cout << "Enter crime Type: ";
    gets_s(crimeRegistry[crimeArraySize - 1].crimeType, 15);
    cout << "Enter crime date: ";
    cin >> crimeRegistry[crimeArraySize - 1].crimeDay;
    cin >> crimeRegistry[crimeArraySize - 1].crimeMonth;
    cin >> crimeRegistry[crimeArraySize - 1].crimeYear;
    cout << "Enter crime time: ";
    cin >> crimeRegistry[crimeArraySize - 1].crimeHour;
    cin >> crimeRegistry[crimeArraySize - 1].crimeMinute;
    cout << "Enter criminal ID \n";
    cin >> crimeRegistry[crimeArraySize - 1].criminalID;
    

    cout << "The crime was added successfully!\n";

    cout << "Do you want to add another crime ? \n Enter: \n\n Y if yes \n N if no \n";
    char choice3;
    cin >> choice3;

    switch (choice3)
    {

    case ('Y'):

        system("cls");
        addCrime();
        break;

    case('N'):

        system("cls");
        CrimeMenu(y);
        break;

    default:
        cout << "Invalid Input \n You will be directed back to the crimes menu\n";
        system("pause");
        system("cls");
        CrimeMenu(y);
        break;
    }
}

void deleteCrime()
{
    int ID = 0;
    cout << "Enter the ID of the crime: ";
    cin >> ID;

    if (crimeArraySize == 0)
    {
        cout << "There are no crimes to be deleted\nYou will be directed to the crimes menu\n";
        system("pause");
        system("cls");
        CrimeMenu(y);
    }

    if (crimeArraySize == 1 && crimeRegistry[0].crimeID == ID)
    {
        crimeArraySize--;
        cout << "The crime is deleted sucessfully!";

    }
    else if (crimeArraySize == 1 && crimeRegistry[0].crimeID != ID)
    {
        cout << "This ID wasn't found\nTry Again\n";
        deleteCrime();
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
                crimeRegistry[j].criminalID = crimeRegistry[j + 1].criminalID;

            }
            cout << "The crime is deleted sucessfully!\n";
            crimeArraySize--;
            break;
        }
    }

    cout << "Do you want to delete another crime ? \n Enter: \n\n Y if yes \n N if no \n";
    char choice5;
    cin >> choice5;

    switch (choice5)
    {

    case ('Y'):

        system("cls");
        deleteCrime();
        break;

    case('N'):

        system("cls");
        CrimeMenu(y);
        break;

    default:
        cout << "Invalid Input \n You will be diercted back to the crimes menu\n";
        system("pause");
        system("cls");
        CrimeMenu(y);
        break;
    }
}

void updateCrime()
{
    int ID;
    bool found = 0;
    cout << "Enter crime ID: ";
    cin >> ID;


    if (crimeArraySize == 0)
    {
        cout << "There are no crimes to be updated\nYou will be directed to the crimes menu\n";
        system("pause");
        system("cls");
        CrimeMenu(y);
    }

    for (int i = 0; i < crimeArraySize; i++)
    {
        if (ID == crimeRegistry[i].crimeID)
        {
            found = 1;
            cout << "Enter: \n N to update name \n T to update type \n D to update date \n M to update time \n I to update criminals IDs \n";
            char choose;
            cin >> choose;

            switch (choose)
            {
            case('N'):
                cout << "Enter crime new name: ";
                cin.ignore();
                gets_s(crimeRegistry[i].crimeName, 15);
                break;

            case('T'):
                cout << "Enter crime new type: ";
                cin.ignore();
                gets_s(crimeRegistry[i].crimeType, 15);
                break;

            case('D'):
                cout << "Enter crime new date: ";
                cin >> crimeRegistry[i].crimeDay;
                cin >> crimeRegistry[i].crimeMonth;
                cin >> crimeRegistry[i].crimeYear;
                break;

            case('M'):
                cout << "Enter crime new time: ";
                cin >> crimeRegistry[i].crimeHour;
                cin >> crimeRegistry[i].crimeMinute;
                break;

            case('I'):
                cout << "Enter criminal IDs: \n";
                cin >> crimeRegistry[i].criminalID;
                break;

            default:
                cout << "Invalid Input";
                break;
            }

            cout << "The crime was updated successfully!\n";
            break;
        }
    }
    if (found == 0)
    {
        cout << "Invalid Input\n";
    }

    cout << "Do you want to update another crime ? \n Enter: \n\n Y if yes \n N if no \n";
    char choice7;
    cin >> choice7;

    switch (choice7)
    {

    case ('Y'):

        system("cls");
        updateCrime();
        break;

    case('N'):

        system("cls");
        CrimeMenu(y);
        break;

    default:
        cout << "Invalid Input \n You will be diercted back to the crimes menu\n";
        system("pause");
        system("cls");
        CrimeMenu(y);
        break;
    }


}

void crimeBubbleSort()
{
    crime temp;
    for (int i = 0; i < crimeArraySize; i++)
        for (int j = 0; j + 1 < crimeArraySize - i; j++)
            if (crimeRegistry[j].crimeID > crimeRegistry[j + 1].crimeID)
            {
                temp = crimeRegistry[j];
                crimeRegistry[j] = crimeRegistry[j + 1];
                crimeRegistry[j + 1] = temp;
            }
}


void addCriminal()
{
    ++criminalArraySize;

    cout << "Enter criminal ID: ";
    cin >> criminalRegistry[criminalArraySize - 1].criminalID;
    cin.ignore();
    cout << "Enter criminal name: ";
    gets_s(criminalRegistry[criminalArraySize - 1].criminalName, 15);
    cout << "Enter criminal age: ";
    cin >> criminalRegistry[criminalArraySize - 1].criminalAge;
    cout << "Enter criminal birth date (day): ";
    cin >> criminalRegistry[criminalArraySize - 1].criminalBirthDay;
    cout << "Enter criminal birth date (month): ";
    cin >> criminalRegistry[criminalArraySize - 1].criminalBirthMonth;
    cout << "Enter criminal birth date (year): ";
    cin >> criminalRegistry[criminalArraySize - 1].criminalBirthYear;
    cout << "Enter number of crimes done by criminal: ";
    cin >> criminalRegistry[criminalArraySize - 1].numOfcrimes;
    cout << "Enter criminal judgement years: ";
    cin >> criminalRegistry[criminalArraySize - 1].criminalJudgementYears;

    cout << "The criminal data was added successfully!";

    cout << "Do you want to add another criminal ? \n Enter: \n\n Y if yes \n N if no \n";
    char choice4;
    cin >> choice4;

    switch (choice4)
    {

    case ('Y'):

        system("cls");
        addCriminal();
        break;

    case('N'):

        system("cls");
        CriminalMenu(y);
        break;

    default:
        cout << "Invalid Input \n You will be diercted back to the criminals menu\n";
        system("pause");
        system("cls");
        CriminalMenu(y);
        break;
    }
}

void deleteCriminal()
{
    int ID = 0;
    cout << "Enter the ID of the criminal: ";
    cin >> ID;

    if (criminalArraySize == 0)
    {
        cout << "There are no criminals to be deleted\nYou will be directed to the criminals menu\n";
        system("pause");
        system("cls");
        CriminalMenu(y);
    }

    if (criminalArraySize == 1 && criminalRegistry[0].criminalID == ID)
    {
        criminalArraySize--;
        cout << "The criminal data is deleted sucessfully!";

    }
    else if (criminalArraySize == 1 && criminalRegistry[0].criminalID != ID)
    {
        cout << "This ID wasn't found\nTry Again\n";
        deleteCriminal();
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
                criminalRegistry[j].criminalBirthDay = criminalRegistry[j + 1].criminalBirthDay;
                criminalRegistry[j].criminalBirthMonth = criminalRegistry[j + 1].criminalBirthMonth;
                criminalRegistry[j].criminalBirthYear = criminalRegistry[j + 1].criminalBirthYear;
                criminalRegistry[j].numOfcrimes = criminalRegistry[j + 1].numOfcrimes;
                criminalRegistry[j].criminalJudgementYears = criminalRegistry[j + 1].criminalJudgementYears;

            }
            cout << "The criminal data is deleted sucessfully!";
            criminalArraySize--;
            break;
        }
    }

    cout << "Do you want to delete another criminal ? \n Enter: \n\n Y if yes \n N if no \n";
    char choice6;
    cin >> choice6;

    switch (choice6)
    {

    case ('Y'):

        system("cls");
        deleteCriminal();
        break;

    case('N'):

        system("cls");
        CriminalMenu(y);
        break;

    default:
        cout << "Invalid Input \n You will be diercted back to the criminals menu\n";
        system("pause");
        system("cls");
        CriminalMenu(y);
        break;
    }
}



void updateCriminal()
{
    int ID;
    bool found = 0;
    cout << "Enter criminal ID: ";
    cin >> ID;

    if (criminalArraySize == 0)
    {
        cout << "There are no criminals to be updated\nYou will be directed to the criminals menu\n";
        system("pause");
        system("cls");
        CriminalMenu(y);
    }

    for (int i = 0; i < criminalArraySize; i++)
    {
        if (ID == criminalRegistry[i].criminalID)
        {
            found = 1;
            cout << "Enter: \n N to update name \n A to update age \n B to update birth date \n C to update number of crimes done by criminal \n J to update criminal judgement years \n";
            char choose;
            cin >> choose;

            switch (choose)
            {
            case('N'):
                cout << "Enter criminal new name: ";
                cin.ignore();
                gets_s(criminalRegistry[i].criminalName, 15);
                break;

            case('A'):
                cout << "Enter criminal new age: ";
                cin >> criminalRegistry[i].criminalAge;
                break;

            case('B'):
                cout << "Enter criminal new birth date: ";
                cin >> criminalRegistry[i].criminalBirthDay;
                cin >> criminalRegistry[i].criminalBirthMonth;
                cin >> criminalRegistry[i].criminalBirthYear;
                break;

            case('C'):
                cout << "Enter number of crimes done by criminal: ";
                cin >> criminalRegistry[i].numOfcrimes;
                break;

            case('J'):
                cout << "Enter criminal judgement years: ";
                cin >> criminalRegistry[i].criminalJudgementYears;
                break;

            default:
                cout << "Invalid Input";
                break;
            }

            cout << "The criminal data was updated successfully!";

            break;
        }
    }
    if (found == 0)
    {
        cout << "Invalid Input\n";
    }

    cout << "Do you want to update another criminal ? \n Enter: \n\n Y if yes \n N if no \n";
    char choice8;
    cin >> choice8;

    switch (choice8)
    {

    case ('Y'):

        system("cls");
        updateCriminal();
        break;

    case('N'):

        system("cls");
        CriminalMenu(y);
        break;

    default:
        cout << "Invalid Input \n You will be directed back to the criminals menu\n";
        system("pause");
        system("cls");
        CriminalMenu(y);
        break;
    }


}

void criminalBubbleSort()
{
    criminal temp;
    for (int i = 0; i < criminalArraySize; i++)
        for (int j = 0; j + 1 < criminalArraySize - i; j++)
            if (criminalRegistry[j].criminalID > criminalRegistry[j + 1].criminalID)
            {
                temp = criminalRegistry[j];
                criminalRegistry[j] = criminalRegistry[j + 1];
                criminalRegistry[j + 1] = temp;
            }
}




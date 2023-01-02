

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
    char crimeName[30] = {};
    char crimeType[30] = {};
    int crimeDay = 0;
    int crimeMonth = 0;
    int crimeYear = 0;
    int crimeHour = 0;
    int crimeMinute = 0;
    int nOfCriminals = 0;
    int criminalsID[30] = {};
    bool flag = 0;

};


struct criminal
{
    int criminalID = 0;
    char criminalName[30] = {};
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
    return 0;
}

void displayallcrimes()

{
    for (int i = 0; i < crimeArraySize; i++)

    {
        cout << "crime name \t" << "crime id\t" << "crime type\t" << "crime date\t" << "crime time\t" << "number of criminals\t" << endl;

        cout << crimeRegistry[i].crimeName << "\t" << crimeRegistry[i].crimeID << crimeRegistry[i].crimeType << "/t" << crimeRegistry[i].crimeDay << "/" << crimeRegistry[i].crimeMonth << "/" << crimeRegistry[i].crimeYear << "\t" << crimeRegistry[i].crimeHour << ":" << crimeRegistry[i].crimeMinute<<"\t"<<crimeRegistry[i].nOfCriminals<< endl;
    }
}


void displayallcriminals()

{
    for (int i = 0; i < criminalArraySize; i++)
    {
        cout << "criminal name\t" << "criminal id\t" << "criminal age\t" << "criminal birthday\t" << "number of crimes commited\t" << "number of judgementyears" << endl;

        cout << criminalRegistry[i].criminalName << "\t" << criminalRegistry[i].criminalID << "\t" << criminalRegistry[i].criminalAge << "\t" << criminalRegistry[i].criminalBirthDay << "/" << criminalRegistry[i].criminalBirthMonth << "/" << criminalRegistry[i].criminalBirthYear << "\t" << criminalRegistry[i].numOfcrimes << "\t" << criminalRegistry[i].criminalJudgementYears << endl;

    }

}


void searchcriminal()

{
    int id;

    bool foundcriminal = 0;



    cout << "please enter the crime id you want to search for";

    cin >> id;

    for (int i = 0; i < criminalArraySize; i++)

    {
        if (id == criminalRegistry[i].criminalID)
        {
            bool foundcriminal = 1;

            cout << "criminal name: " << criminalRegistry[i].criminalName << endl;
            cout << "criminal id: " << criminalRegistry[i].criminalID << endl;
            cout << "criminal age: " << criminalRegistry[i].criminalAge << endl;
            cout << "criminal birthday: " << criminalRegistry[i].criminalBirthDay << "/" << criminalRegistry[i].criminalBirthMonth << "/" << criminalRegistry[i].criminalBirthYear << endl;
            cout << "number of crimes commited: " << criminalRegistry[i].numOfcrimes << endl;
            cout << "number of judgementyears: " << criminalRegistry[i].criminalJudgementYears << endl;

        }

        while (foundcriminal == 0)
        {
            cout << "please enter a valid id to search for";
            system("pause");
            system("cls");
            searchcriminal();
        }


    }


}


void searchcrime()

{
    int id;

    bool foundcrime = 0;



    cout << "please enter the crime id you want to search for";

    cin >> id;

    for (int i = 0; i < crimeArraySize; i++)

    {
        if (id == crimeRegistry[i].crimeID)
        {
            bool foundcrime = 1;

            cout << "crime name: " << crimeRegistry[i].crimeName << endl;
            cout << "crime id: " << crimeRegistry[i].crimeID << endl;
            cout << "crime type: " << crimeRegistry[i].crimeType << endl;
            cout << "crime date: " << crimeRegistry[i].crimeDay << "/" << crimeRegistry[i].crimeMonth << "/" << crimeRegistry[i].crimeYear << endl;
            cout << "crime time: " << crimeRegistry[i].crimeHour << ":" << endl;
            cout << "number of criminals: " << crimeRegistry[i].nOfCriminals << endl;

        }

        while (foundcrime == 0)
        {
            cout << "please enter a valid id to search for";
            system("pause");
            system("cls");
            searchcrime();
        }


    }

}


void login()
{
    char username[15];
    char password[15];
    bool found = 0;
    bool correct = 0;
    int k = 0;

    cout << "PLEASE ENTER YOUR USERNAME ";
    cin >> username;
    strcpy_s(y, username);

    cout << "PLEASE ENTER YOUR PASSWORD ";
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
        cout << "Login Successful\n";
        system("pause");
        system("cls");
        MainMenu();

    }
    else if (found == 1 && correct == 0)
    {
        cout << "Username or Password is incorrect";
        system("pause");
        system("cls");
        login();
    }
    else
    {
        cout << "User not found";
        system("pause");
        system("cls");
        login();
    }
}

void MainMenu()
{
    int choice = 0;
    cout << "\t\t\t\tMAIN MENU" << endl;

    cout << " 1. Crimes" << endl;
    cout << " 2. Criminals" << endl;
    cout << " 3. Back to Login" << endl;
    cout << "Enter your choice (1, 2 or 3): ";
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

    default:
        cout << "Invalid Input! Try Again!";
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
        cout << "\t\t\t\tCRIMES MENU" << endl;

        cout << " 1. Add New Crime" << endl;
        cout << " 2. Delete a Crime" << endl;
        cout << " 3. Display all Crimes" << endl;
        cout << " 4. Update a Crime" << endl;
        cout << " 5. Search for a Crime" << endl;
        cout << " 6. Back to Main Menu" << endl;
        cout << "Enter your choice (1, 2, 3, 4, 5 or 6): ";
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
            cout << "Invalid Input! Try Again!";
            CrimeMenu(y);
            break;
        }
    }
    else if (view == 0)
    {
        cout << "\t\t\t\tCRIMES MENU" << endl;

        cout << " 1. Display all Crimes" << endl;
        cout << " 2. Search for a Crime" << endl;
        cout << " 3. Back to Main Menu" << endl;
        cout << "Enter your choice (1, 2 or 3): ";
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
            cout << "Invalid Input! Try Again!";
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
        cout << "\t\t\t\tCRIMINALS MENU" << endl;

        cout << " 1. Add New Criminal" << endl;
        cout << " 2. Delete a Criminal" << endl;
        cout << " 3. Display all Criminals" << endl;
        cout << " 4. Update a Criminal" << endl;
        cout << " 5. Search for a Criminal" << endl;
        cout << " 6. Back to Main Menu" << endl;
        cout << "Enter your choice (1, 2, 3, 4, 5 or 6): ";
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
            cout << "Invalid Input! Try Again!";
            CriminalMenu(y);
            break;
        }
    }
    else if (view == 0)
    {
        cout << "\t\t\t\tCRIMINALS MENU" << endl;

        cout << " 1. Display all Criminals" << endl;
        cout << " 2. Search for a Criminal" << endl;
        cout << " 3. Back to Main Menu" << endl;
        cout << "Enter your choice (1, 2 or 3): ";
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
            cout << "Invalid Input! Try Again!";
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
    gets_s(crimeRegistry[crimeArraySize - 1].crimeName, 30);
    cout << "Enter crime Type: ";
    gets_s(crimeRegistry[crimeArraySize - 1].crimeType, 30);
    cout << "Enter crime date: ";
    cin >> crimeRegistry[crimeArraySize - 1].crimeDay;
    cin >> crimeRegistry[crimeArraySize - 1].crimeMonth;
    cin >> crimeRegistry[crimeArraySize - 1].crimeYear;
    cout << "Enter crime time: ";
    cin >> crimeRegistry[crimeArraySize - 1].crimeHour;
    cin >> crimeRegistry[crimeArraySize - 1].crimeMinute;
    cout << "Enter number of criminals: ";
    cin >> crimeRegistry[crimeArraySize - 1].nOfCriminals;
    fill(crimeRegistry[crimeArraySize - 1].criminalsID, crimeRegistry[crimeArraySize - 1].criminalsID + 30, 0);
    for (int i = 0; i < crimeRegistry[crimeArraySize - 1].nOfCriminals; i++)
    {
        cout << "Enter criminal " << i + 1 << " ID: ";
        cin >> crimeRegistry[crimeArraySize - 1].criminalsID[i];
    }

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
                crimeRegistry[j].nOfCriminals = crimeRegistry[j + 1].nOfCriminals;
                for (int k = 0; k < crimeRegistry[j].nOfCriminals; k++)
                {
                    crimeRegistry[j].criminalsID[k] = crimeRegistry[j + 1].criminalsID[k];
                }

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
            cout << "Enter: \n N to update name \n T to update type \n D to update date \n M to update time \n U to update number of criminals \n I to update criminals IDs \n";
            char choose;
            cin >> choose;

            switch (choose)
            {
            case('N'):
                cout << "Enter crime new name: ";
                cin.ignore();
                gets_s(crimeRegistry[i].crimeName, 30);
                break;

            case('T'):
                cout << "Enter crime new type: ";
                cin.ignore();
                gets_s(crimeRegistry[i].crimeType, 30);
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

            case('U'):
                cout << "Enter new number of criminals: ";
                cin >> crimeRegistry[i].nOfCriminals;
                break;

            case('I'):
                cout << "Enter new criminals IDs: \n";
                for (int j = 0; j < crimeRegistry[i].nOfCriminals; j++)
                {
                    cout << "Enter criminal " << j + 1 << " ID: ";
                    cin >> crimeRegistry[i].criminalsID[j];
                }
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
        cout << "Invalid Input\nTry Again\n";
        updateCrime();
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


void addCriminal()
{
    ++criminalArraySize;

    cout << "Enter criminal ID: ";
    cin >> criminalRegistry[criminalArraySize - 1].criminalID;
    cin.ignore();
    cout << "Enter criminal name: ";
    gets_s(criminalRegistry[criminalArraySize - 1].criminalName, 30);
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
                gets_s(criminalRegistry[i].criminalName, 30);
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
        cout << "Invalid Input\nTry Again\n";
        updateCriminal();
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

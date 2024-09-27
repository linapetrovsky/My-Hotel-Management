#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define R 5
#define C 40

class hotel
{
    int room_no;
    char name[30];
    char address[50];
    char phone[10];
    int breakfast;
    static int clean;
    static int count;


public:
    void main_menu();       //to display the main menu
    void add();             //to book a room
    void display();         //to display the customer record
    void rooms();           //to display allotted rooms
    void edit();            //to edit the customer record
    int check(int);         //to check room status
    void modify(int);       //to modify the record
    void delete_rec(int);   //to delete the record
    void secure_login();    //main display with password
    void feedbacks(int**, char**);
    void addfeedback(int**, char**); //to add feedback
    void printfeedbacks(int**, char**);  // to dispay feedbacks
    void housekeeping();     // to check if a room is clean or to ask for cleaning
};

int hotel::count = 0;
int hotel::clean = 1;

void hotel::main_menu()
{
    int** rates = new int* [C];
    for (int i = 0; i < C; i++)
    {
        rates[i] = new int[R];
    }
    char** names = new char* [C];

    int choice = 0;
    while (choice != 7)
    {

        //  clrscr();
        cout << "\n\t\t\t\t*************";
        cout << "\n\t\t\t\t* MAIN MENU *";
        cout << "\n\t\t\t\t*************";
        cout << "\n\n\n\t\t\t1.Book A Room";
        cout << "\n\t\t\t2.Customer Record";
        cout << "\n\t\t\t3.Rooms Allotted";
        cout << "\n\t\t\t4.Edit Record";
        cout << "\n\t\t\t5.Feedback";
        cout << "\n\t\t\t6.Housekeeping";
        cout << "\n\t\t\t7.Exit";
        cout << "\n\n\t\t\t Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: add();
            break;
        case 2: display();
            break;
        case 3: rooms();
            break;
        case 4: edit();
            break;
        case 5:
        {
            feedbacks(rates, names);
            break;
        }
        case 6: housekeeping();
            break;
        case 7: break;
        default:
        {
            cout << "\n\n\t\t\tWrong choice...!!!";
            cout << "\n\t\t\tPress any key to continue..!!";
            getch();
        }
        }
    }
}

void hotel::feedbacks(int** rates, char** names)
{

    int choice;
    cout << "\n -------";
    cout << "\n\n 1.Add a feedback";
    cout << "\n 2.Display all previous feedbacks";

    cout << "\n Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1: addfeedback(rates, names);
        break;
    case 2: printfeedbacks(rates, names);
        break;
    default:
    {
        cout << "\n Wrong Choice..!!";
        cout << "\n Press any key to continue...!!!";

    }
    }
}

void hotel::addfeedback(int** rates, char** names)
{
    int rate;
    char name[20];
    int number;
    cout << "\n --------";
    cout << "\nenter your name: ";
    cin >> name;
    names[count] = new char[strlen(name) + 1];
    strcpy(names[count], name);
    cout << "\n --------";
    cout << "Rate on a scale of 1-5";
    cout << "\ncleanliness: ";
    cin >> rate;
    rates[count][0] = rate;
    cout << "\nhotel employees: ";
    cin >> rate;
    rates[count][1] = rate;
    cout << "\ncheck-in waiting time: ";
    cin >> rate;
    rates[count][2] = rate;
    cout << "\nmeals: ";
    cin >> rate;
    rates[count][3] = rate;
    cout << "\nrecommend the hotel to others: ";
    cin >> rate;
    rates[count][4] = rate;

    count++;
    cout << "\nThank you for your time!\n";

}

void hotel::printfeedbacks(int** rates, char** names)
{

    for (int i = 0; i < count; i++)
    {
        cout << "name: " << names[i] << endl;

        cout << "cleanliness: " << rates[i][0] << "\t";
        cout << "hotel employees: " << rates[i][1] << "\t";
        cout << "check-in waiting time: " << rates[i][2] << "\t";
        cout << "meals: " << rates[i][3] << "\t";
        cout << "recommend the hotel to others: " << rates[i][4] << "\n";


    }

    if (!count)
    {
        cout << "No feedback was received in the system\n";
    }

}

void hotel::add()
{
    //clrscr();
    int r, flag;
    ofstream fout("Record", ios::app);

    cout << "\n Enter Customer Detalis";
    cout << "\n --------";
    cout << "\n\n Room no: ";
    cin >> r;
    flag = check(r);

    if (flag)
        cout << "\n Sorry..!!! Room is already booked";

    else
    {
        room_no = r;
        cout << " Name: ";
        cin >> name;
        cout << " Address: ";
        cin >> address;
        cout << " Phone No: ";
        cin >> phone;
        cout << " Eats breakfast (yes : press 1 / no : press 0) : ";
        cin >> breakfast;
        //clean = 1;
        fout.write((char*)this, sizeof(hotel));
        cout << "\n Room is booked...!!!";
    }

    cout << "\n Press any key to continue...!!";
    getch();
    fout.close();
}

void hotel::display()
{
    //clrscr();
    ifstream fin("Record", ios::in);
    int r, flag=0;
    cout << "\n Enter room no: ";
    cin >> r;

    while (!fin.eof())
    {
        fin.read((char*)this, sizeof(hotel));
        if (room_no == r)
        {
            //clrscr();
            cout << "\n Customer Details";
            cout << "\n -------";
            cout << "\n\n Room no: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone no: " << phone;
            if (clean==1)
                cout << "\n Housekeeping : The room is clean.";
            else
                cout << "\n Housekeeping : Not clean.";
            if (breakfast)
                cout << "\n Eats breakfast at hotel";
            else
                cout << "\n No breakfast at hotel";
            flag = 1;
            break;
        }
    }

    if (!flag)
        cout << "\n Sorry Room no. not found or vacant..!!";

    cout << "\n\n Press any key to continue..!!";
    getch();
    fin.close();

}

void hotel::rooms()
{
    //clrscr();
    ifstream fin("Record", ios::in);
    cout << "\n\t\t\t    List Of Rooms Allotted";
    cout << "\n\t\t\t    -------";
    cout << "\n\n Room No.\tName\t\tAddress\t\tPhone No.\t\tBreakfast";

    while (!fin.eof())
    {
        fin.read((char*)this, sizeof(hotel));
        cout << "\n\n " << room_no << "\t\t" << name;
        cout << "\t\t" << address << "\t\t" << phone;
        if (breakfast)
            cout << "\t\t\tEats breakfast";
        else
            cout << " \t\t\tNo breakfast";
    }
    cout << "\n\n\n\t\t\tPress any key to continue...!!";
    getch();
    fin.close();
}

void hotel::edit()
{
    //clrscr();
    int choice, r;

    cout << "\n EDIT MENU";
    cout << "\n -------";
    cout << "\n\n 1.Modify Customer Record";
    cout << "\n 2.Delete Customer Record";

    cout << "\n Enter your choice: ";
    cin >> choice;
    //clrscr();
    cout << "\n Enter room no: ";
    cin >> r;
    switch (choice)
    {
    case 1: modify(r);
        break;
    case 2: delete_rec(r);
        break;
    default: cout << "\n Wrong Choice..!!";
    }
    cout << "\n Press any key to continue...!!!";
    getch();
}

int hotel::check(int r)
{
    int flag = 0;
    ifstream fin("Record", ios::in);
    while (!fin.eof())
    {
        fin.read((char*)this, sizeof(hotel));
        if (room_no == r)
        {
            flag = 1;
            break;
        }
    }

    fin.close();
    return(flag);
}

void hotel::modify(int r)
{
    long pos, flag = 0;
    fstream file("Record", ios::in | ios::out | ios::binary);
    while (!file.eof())
    {
        pos = file.tellg();                     //returns the position
        file.read((char*)this, sizeof(hotel));
        if (room_no == r)
        {
            cout << "\n Enter New Details";
            cout << "\n -------";
            cout << "\n Name: ";
            cin >> name;
            cout << " Address: ";
            cin >> address;
            cout << " Phone no: ";
            cin >> phone;
            cout << " Eats breakfast (yes : press 1 / no : press 0) : ";
            cin >> breakfast;
            clean = 0;
            file.seekg(pos);
            file.write((char*)this, sizeof(hotel));
            cout << "\n Record is modified..!!";
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "\n Sorry Room no. not found or vacant..!!";
    file.close();
}

void hotel::delete_rec(int r)
{
    int flag = 0;
    char ch;
    ifstream fin("Record", ios::in);
    ofstream fout("temp", ios::out);
    while (!fin.eof())
    {
        fin.read((char*)this, sizeof(hotel));
        if (room_no == r)
        {
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Pone No: " << phone;
            cout << "\n\n Do you want to delete this record(y/n): ";
            cin >> ch;

            if (ch == 'n')
                fout.write((char*)this, sizeof(hotel));
            flag = 1;
        }
        else
            fout.write((char*)this, sizeof(hotel));
    }

    fin.close();
    fout.close();
    if (flag == 0)
        cout << "\n Sorry room no. not found or vacant..!!";
    else
    {
        remove("Record");
        rename("temp", "Record");
    }
}

void hotel::secure_login()
{
    char pwd[] = "password", verify[20], ch;
    int i, chance = 1;
start:                 //label defined
    //clrscr();
    i = 0;
    cout << "\n\t\t\t****************************";
    cout << "\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
    cout << "\n\t\t\t****************************";


    cout << "\n\n\n\n\t\tMade By:";

    cout << "\t SHUBHAM AGRAWAL ";

    cout << "\n\n\t\tSubmitted To:";

    cout << "\t Mr. Narendra Aliani sir";
    cout << "\n\n\nEnter the password to verify: ";
    do
    {
        ch = getch();
        if (ch != 13)     //carriage return
        {
            verify[i++] = ch;
            cout << "*";
        }
        else
        {
            verify[i++] = '\0';
        }
    } while (ch != 13);

    if (strcmp(pwd, verify) == 0)
    {
        cout << "\nPassword Matched...";
        cout << "\nWelcome Shubham Agrawal....";
    }
    else
    {
        cout << "\nPassword Wrong....\n";
        cout << chance << " used of 3 chances...";
        cout << "\nEnter the correct credentials";
        chance++;
        getch();
        if (chance <= 3) goto start;
    }
}

void hotel::housekeeping()
{
    ifstream fin("Record", ios::in);
    int r, flag = 0, choice;
    cout << "\n Please enter a room number: ";
    cin >> r;
    while (!fin.eof())
    {
        fin.read((char*)this, sizeof(hotel));
        if (room_no == r)
        {
            if (clean)
            {
                cout << "\n The room is already clean.";
                flag = 1;
                break;
            }
            else
                  cout << "\n The room is not clean. Do you want to send housekeeper ? ( Yes(1) / No(0) ):  ";
                  cin >> choice;
                  if (choice == 1)
                  {
                      cout << "\n We've sent the housekeeper to clean your room.";
                      clean++;
                      flag = 1;
                      break;
                  }
                  if (choice == 0)
                  {
                      
                      flag = 1;
                      break;
                  }
                
        }
    }
    if (flag == 0)
    {
        cout << "\n The room doesn't exist.";
    }
    cout << "\n\n Press any key to continue..!!";
    getch();
    fin.close();
    
}

void main()
{
    hotel h;
    //textbackground(BLACK);
    //textcolor(WHITE);

    //clrscr();

    //h.secure_login();
    h.main_menu();
    getch();
}

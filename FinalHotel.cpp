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
enum { Red = 1, Blue, Purple, Turquoise, Pink };
enum { Bachelor = 1, Bachelorette };

class hotel
{
    int room_no;
    char name[30];
    char address[50];
    char phone[10];
    int breakfast;
    int num_of_person_restaurant;
    static int num_of_possible_reservation;
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
    void feedbacks(int**, char**); // to leave a feedback
    void addfeedback(int**, char**); //to add feedback
    void printfeedbacks(int**, char**);  // to dispay feedbacks
    void housekeeping();     // to check if a room is clean or to ask for cleaning
    bool room_design(int); //to choose room design
    void restaurant();      //to see number of table
};


int hotel::count = 0;
int hotel::clean = 1;
int hotel::num_of_possible_reservation = 150;

void hotel::main_menu()
{
    int** rates = new int* [C];
    for (int i = 0; i < C; i++)
    {
        rates[i] = new int[R];
    }
    char** names = new char* [C];

    int choice = 0;
    while (choice != 8)
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
        cout << "\n\t\t\t7.Restaurant";
        cout << "\n\t\t\t8.Exit";
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

        case 7: restaurant();
            break;

        case 8: break;
        default:
        {
            cout << "\n\n\t\t\tWrong choice...!!!";
            cout << "\n\t\t\tPress any key to continue..!!";
            getch();
        }
        }
    }
}

bool hotel::room_design(int age)
{

    cout << "\n Choose desired design: " << endl;
    cout << "1. Birthday party design" << endl;
    cout << "2. Surprise party design" << endl;
    cout << "3. Bachelor/Bachelorette party design " << endl;
    cout << "4. Honeymoon design " << endl;
    int design;
    cin >> design;
    if (design < 1 || design>4)
    {
        return false;
    }
    if (design == 3 || design == 4 && age < 18)
    {
        return false;
        //Can not choose these designs if under 18

    }

    switch (design)
    {
    case 1:
    {
        int color;
        cout << "Choose age baloons color " << endl;
        cout << "1. Red" << endl;
        cout << "2. Blue" << endl;
        cout << "3. Purple " << endl;
        cout << "4. Turquoise " << endl;
        cout << "5. Pink " << endl;
        cin >> color;
        if (color<Red || color> Pink)
        {
            cout << " Sorry, you selected a non-existent color " << endl;
            return false;
        }
        break;
    }
    case 2:
    {
        unsigned int guests;
        cout << "Enter number of guests " << endl;
        cin >> guests;
        if (guests > 30)
        {
            cout << " Sorry, room can contain up to 30 guests only " << endl;
            return false;
        }
        
        break;
    }
    case 3:
    {
        int sex;
        unsigned int guests;
        cout << "Press [1] for Bachelor party design  " << endl <<
            "Press [2] for Bachelorette party design" << endl;
        cin >> sex;
        cout << "Enter number of guests " << endl;
        cin >> guests;
        if (guests > 30)
        {
            cout << " Sorry, room can contain up to 30 guests only " << endl;
            return false;
        }
        if (sex == Bachelor)
        {
            cout << "Enter number of guests (male only) " << endl;
            cin >> guests;
            cout << "We will prepare " << guests * 5 << " beers for you" << endl;
        }
        if (sex == Bachelorette)
        {
            cout << "Enter number of guests (female only) " << endl;
            cin >> guests;
            cout << "We will prepare " << guests * 3 << " coctails for you" << endl;
        }
        break;
    }
    case 4:
    {

        int petals;
        cout << " Choose rose petals color " << endl;
        cout << "1. Red" << endl;
        cout << "2. Blue" << endl;
        cout << "3. Purple " << endl;
        cout << "4. Turquoise " << endl;
        cout << "5. Pink " << endl;
        cin >> petals;
        if (petals != Red)
        {
            cout << "Sorry, we have only red rose petals" << endl;
            return false;
        }
        break;
    }
    default:
        cout << "Wrong input" << endl;
        return false;
        break;
    }

    return true;
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
    cout << "\nEnter your name: ";
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
        char design;
        int age, num_choice, num, num_choice_design;
        room_no = r;
        cout << " Name: ";
        cin >> name;
        cout << " Address: ";
        cin >> address;
        cout << " Phone No: ";
        cin >> phone;
        cout << " Eats breakfast (yes : press 1 / no : press 0) : ";
        cin >> breakfast;
        cout << " Guest age : ";
        cin >> age;
        cout << " Does " << name << " need some special design of the room?" << endl <<
            "[1]-yes" << endl << "[Any other key]-no" << endl;
        cin >> design;
        if (design == '1')
        {
            if (room_design(age))
            {
                cout << "The request for special design was successfully processed " << endl <<
                    "Price of the servise is 50$" << endl;
            }
            else
            {
                cout << "An error occurred " << endl <<
                    "The request to design the room was rejected" << endl;
            }
        }

        cout << "reservation for the restaurant (yes : press 1 / no : press 0) ";
        cin >> num_choice;
        if (num_choice == 0)
            num_of_person_restaurant = 0;
        else if (num_choice == 1)
        {
            cout << "How much people for reservation ";
            cin >> num;
            if (num < num_of_possible_reservation)
            {
                num_of_person_restaurant = num;
                num_of_possible_reservation = num_of_possible_reservation - num;
            }
            else
            {
                cout << "too much people,no place\n";
                num_of_person_restaurant = 0;
            }
        }
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
    int r, flag = 0;
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
            cout << "\n Number of people for restaurant:  " << num_of_person_restaurant;
            if (clean == 1)
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
            cout << "Modify your reservation in restaurant. How many people are you?";
            num_of_possible_reservation = num_of_possible_reservation + num_of_person_restaurant;
            cin >> num_of_person_restaurant;
            num_of_possible_reservation = num_of_possible_reservation - num_of_person_restaurant;
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
            cout << "\n Phone No: " << phone;
            cout << "\n Table in restaurant" << num_of_person_restaurant;
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

void hotel::restaurant()
{
    cout << "\n number of possible reservation : " << num_of_possible_reservation;
    if (num_of_possible_reservation == 0)
    {
        cout << "\nUnfortunately ,we dont have place,sorry.\n ";
    }

    cout << "\n\n Press any key to continue..!!";
    getch();


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

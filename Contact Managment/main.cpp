#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

string fname,lname,phone_num;

int main(){
    short int choice;
    system("cls");
    system("color 0b");
    cout<<"\n\n\n\t\t\t Contact Management.";
    cout<<"\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t";
    cin>>choice;
    switch (choice)
    {
    case 1:
        addContact();
        break;
    case 2:
        searchContact();
        break;
    case 3:
        help();
        break;
    case 4:
        self_exit();
        break;
    default:
        cout<<"\n\n\t Invalid Input";
        cout<<"\n\tPress Any Key To Continue..";
        getch();
        main();
        break;
    }
    return 0;


}
void self_exit(){
    system("cls");
    cout<<"\n\n Thank You for Using";
    exit(1);

}
void help(){
    cout<<"This Display Help";

}
void addContact(){
    ofstream phone("number.txt",ios::app);
    system("cls");
    cout<<"\n\n\t Enter First Name :-";
    cin>> fname;
    cout<<"\n\t Enter Last Name:-";
    cin>> lname;
    cout<<"\n\t Enter 10-Digit phone Number :- ";
    cin>> phone_num;
    if(check_digits(phone_num)==true)
    {
        if(check_numbers(phone_num)==true){
            if(phone.is_open()){
                phone<<fname<<" - "<<lname<<" - " <<phone_num<<endl;
                cout<<"\n\tContact Saved Successfully";

            }
            else{
                cout<<"\n\t Error opening File!";
            }

        }
        else{
            cout<<"\n\t A phone number must contains Numbers Only.";
        }
    }
    else
    {
        cout<<"\n\t A phone number must be of 10 Digits.";
    }
    phone.close();
}
void searchContact(){
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout<<"\n\t Enter Name to search : - ";
    cin>> keyword;
    while (myfile>>fname>>lname>>phone_num)
    {
        if (keyword == fname || keyword == lname)
        {
            system("cls");
            cout<<"\n\n\n\t\t Contact details...";
            cout<<"\n\n\t First Name :- "<<fname;
            cout<<"\n\t Last Name :- "<<lname;
            cout<<"\n\t Phone Number :- "<<lname;
            found = true;
            break;
        }
        
    }
    if (found==false)
    cout<<"\n\t No Such Contact Found";
}
bool check_digits(string x)
{
    if(x.length()==10)
    return true;
    else;
    return false;
}
bool check_numbers(string x)
{
    bool check = true;

    for (int i = 0;i<x.length();i++)
    {
        if(!(int(x[i])>= 48 && int(x[i])<=57)){
            check = false;
            break;
        }
    }
    if(check == true)
    return true;
    if (check == false)
    return false;
}

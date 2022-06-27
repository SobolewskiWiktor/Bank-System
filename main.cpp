#include <iostream>
#include <math.h>
#include <string.h>
#include <fstream>
#include <conio.h>
#include "login.h"
#include "functions.h"
#include "classes.h"

using namespace std;

bool check_pass(string login, string pass, string type)
{
  ifstream read_pass("pass.txt");
  if(!read_pass)
  {
    cout<<"[ERROR] - fail read pass file "<<endl;
  }
  else
  {
    string Login;
    string Password;
    string Type;
    
    string line;
    int spacer = 0;

    getline(read_pass, line);
    int length_line = line.length();
    for(int i=0; i<length_line; i++)
    {
      if(line[i] == ' ')
       {
        spacer ++;
        continue; 
       }
       if(spacer == 0)
       {
        Login = Login + line[i] ;
       }
       if(spacer == 1)
       {
        Password = Password + line[i];
       }
       if(spacer == 2)
       {
        Type = Type + line[i];
       }
    }
      if(Password == pass)
      {
        if(Login == login)
        {
         if(login == Login && Password == pass && Type == type)
         {
           return 1; 
         }
         else
         {
            cout<<"[ERROR] - Wrong accout type "<<endl;
            return 0;
         }
        }
        else
        {
            cout<<"[ERROR] - Wrong login "<<endl;
            return 0;
        }
      }
      else
      {
        cout<<"[ERROR] - Wrong password "<<endl;
        return 0;
      }
    
  }
    return 0; 
}
int main()
{
    int wybor;  
    while (true)
    {
      cout<<endl;
        cout<<"== LOGIN MENU =="<<endl;
        cout<<"1. WORKER"<<endl;
        cout<<"2. USER"<<endl;
        cout<<"Choice: ";
        cin >> wybor; 
        switch (wybor)
        {
        case 1:
        {
            string login;
            string haslo;
            char c = ' '; 
            cout<<endl;
            cout<<"=== WORKER LOGIN ==="<<endl;
            cout<<"Login: ";
            cin>>login;
            cout<<"PASSWORD: ";
            while(c!=13)
            {
                c=getch();
                if(c!= 13)
                {
                    haslo = haslo + c; 
                    cout<<"*"; 
                }
            }
            cout<<endl;       
            bool acces = check_pass(login, haslo ,"administrator");
            if(acces == true)
            {
              cout<<endl;
              cout<<"[SUCCES] - ACESS GRANTED"<<endl;
              while (true)
              {
                int menu_worker_choice; 
                string submited_id_number;
                cout<<endl;
                cout<<"== WORKER MENU == "<<endl;
                cout<<"1. Find Customer"<<endl;
                cout<<"2. Edit Menu"<<endl; 
                cout<<"3. Withdrawal"<<endl;
                cout<<"4. Deposit money"<<endl;
                cout<<"5. Add Customer"<<endl;
                cout<<"6. Exit program"<<endl; 
                cout<<"Choice: ";
                cin>>menu_worker_choice;
                switch (menu_worker_choice)
                {
                case 1:
                {
                  cout<<endl;
                  cout<<endl;
                  cout<<"Enter ID number"<<endl;
                  cout<<"ID number: ";
                  cin>> submited_id_number; 
                  find_user(submited_id_number);
                  cout<<endl;
                  cout<<"FIND USER: "<<endl;
                  downloaded.show_all_data(); 
                  break;
                }
                case 2: 
                {
                  while (true)
                  {
                    int edit_menu_choice; 
                    cout<<endl;
                    cout<<endl;
                    cout<<"== EDIT MENU =="<<endl;
                    cout<<"1. Edit Name"<<endl;
                    cout<<"2. Edit Surname"<<endl;
                    cout<<"3. Edit Id number"<<endl;
                    cout<<"4. Edit PESEL"<<endl; 
                    cout<<"5. Edit Card Number"<<endl;
                    cout<<"6. Edit Accout number"<<endl; 
                    cout<<"Choice: ";
                    cin >> edit_menu_choice; 
                     switch (edit_menu_choice)
                     {
                      case 1:
                      {
                        string Name;
                        cout<<"Name: ";
                        cin>>Name;
                        downloaded.set_name(Name);
                        break;
                      }
                      case 2:
                      {
                        string temp;
                        cout<<"Surname: ";
                        cin>>temp;
                        downloaded.set_surname(temp);
                        break;
                      }
                      case 3:
                      {
                        string temp;
                        cout<<"Id number: ";
                        cin>>temp;
                        downloaded.set_id_number(temp);
                        break;
                      }
                      case 4:
                      {
                        string temp;
                        cout<<"PESEL: ";
                        cin>>temp;
                        downloaded.set_pesel(temp);
                        break;
                      }
                      case 5:
                      {
                        string temp;
                        cout<<"Card number: ";
                        cin>>temp;
                        downloaded.set_card_number(temp);
                        break;
                      }
                      case 6:
                      {
                        string temp;
                        cout<<"Accout number: ";
                        cin>>temp;
                        downloaded.set_account(temp);
                        break;
                      }
                     }
                  }
                  break;
                }
                case 3: 
                {
                  int amount;
                  cout<<endl;
                  cout<<"Cash ammount: ";
                  cin >> amount; 
                  withdrawal(amount);
                  save();
                  break;
                }
                case 4:
                {
                  int amount;
                  cout<<endl;
                  cout<<"Cash ammount: ";
                  cin >> amount;
                  deposit(amount);
                  save();
                  break; 
                }
                case 5:
                {
                 string temp;
                 int tempint;
                 cout<<"Name: ";
                 cin>>temp;
                 added.set_name(temp);
                 temp="";
                 cout<<"Surname: ";
                 cin>>temp;
                 added.set_surname(temp);
                 temp="";
                 cout<<"Id Number: ";
                 cin >> temp;
                 added.set_id_number(temp);
                 cout<<"Pesel: ";
                 cin>>temp;
                 added.set_pesel(temp);
                 temp = ""; 
                 cout<<"Account Id: ";
                 cin>>temp;
                 added.set_account(temp);
                 temp="";
                 cout<<"Card number: ";
                 cin>>temp;
                 added.set_card_number(temp); 
                 cout<<"Deposit ammount: ";
                 cin>>tempint;
                 added.set_money(tempint); 
                 cout<<endl;
                 cout<<"== YOU ADDED =="<<endl;
                 added.show_all_data();
                 save(); 
                 break;
                }
                case 6:
                {
                  return 0;
                }
                }
              }
              
            }
            
            break;
        }
        case 2:
        {
            cout<<"user login"<<endl;
            break;
        }
        
        default:
        {
            cout<<"Choose right option"<<endl;
        }
        }
    }
    
}

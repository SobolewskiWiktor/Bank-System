#ifndef  know_functions
#define functions

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "classes.h"

using namespace std;

user downloaded ("Name", "Surname", "Account", 0, "Card_Number", "Pesel", "Id_number");
user added ("Name", "Surname", "Account", 0, "Card_Number", "Pesel", "Id_number");
user * start_two = nullptr; 
user * start = nullptr; 

void find_user(string id_number)
{
    string line; 

    string Id_number = "";
    string Name= "";
    string Surname= "";
    string Pesel= "";
    string Account= "";
    string Card_Number= ""; 
    string temp = "";
    long long int Money = 0;

    ifstream from("uers.txt");
    if(!from)
    {
        cout<<"[ERROR] - fail read users file "<<endl;
    }
    else
    {
        int find = 0;
    do
    {
        getline(from, line); 
        /* money-pesel-id_numer-name-surname-account-card_number */
        int length = line.length();
        int spacer = 0;
        cout<<"[test - I'll find]"<<endl; 
        for(int i=0; i<length; i++)
        {
            if(line[i] == ';')
            {
                spacer ++;
                continue;
            }
           if(spacer == 0)
           {
             temp = temp + line[i];
           }
           if(spacer == 1)
           {
            Pesel = Pesel + line[i];
           }
           if(spacer == 2)
           {
            Id_number = Id_number + line[i];
           }
           if(spacer == 3)
           {
             Name = Name + line[i];
           }
           if(spacer == 4)
           {
            Surname = Surname + line[i]; 
           }
           if(spacer == 5)
           {
            Account = Account + line[i];
           }
           if(spacer == 6)
           {
           Card_Number = Card_Number + line[i]; 
           }
        }
        Money = stoi(temp);
        cout<<"[info] - get: "<<id_number <<" in base: "<<Id_number<<endl;
        if(Id_number == id_number)
        {
            cout<<"[test] - finded"<<endl;
            downloaded.set_name(Name);
            downloaded.set_surname(Surname);
            downloaded.set_pesel(Pesel);
            downloaded.set_account(Account);
            downloaded.set_card_number(Card_Number);
            downloaded.set_id_number(Id_number);
            downloaded.set_money(Money);
            break; 
        }
        else
        {
            find = 0; 
        }
        spacer = 0; 
        Money = 0; 
        Id_number = "";
        Name= "";
        Surname= "";
        Pesel= "";
        Account= "";
        Card_Number= ""; 
        temp = ""; 

    } while (!from.eof());
    if(find == 0)
    {
        cout<<"[ERROR] - NO user in database "<<endl;
    }
    }

}
void withdrawal (int Amount)
{
    if(downloaded.get_id_number() == "Id_number")
    {
        cout<<"[ERROR] - You have to find coustomer first"<<endl;
    }
    else
    {
        int money;
        money = downloaded.get_money()-Amount;
        downloaded.set_money(money); 
        cout<<"== MONEY ==="<<endl;
        cout<<downloaded.get_name()<<" have: "<<downloaded.get_money() <<" on yout account"<<endl;
    }
}
void deposit(int Amount)
{
    if(downloaded.get_id_number() == "Id_number")
    {
        cout<<"[ERROR] - You have to find coustomer first"<<endl;
    }
    else
    {
        int money;
        money = downloaded.get_money()+Amount;
        downloaded.set_money(money); 
        cout<<"== MONEY ==="<<endl;
        cout<<downloaded.get_name()<<" have: "<<downloaded.get_money() <<" on yout account"<<endl;
    }
}

void save()
{
    //Czytanie z pliku users
    ifstream from("uers.txt");
    if(!from)
    {
        cout<<"[ERROR] - Can't read users file"<<endl;
    }
    else
    {
        string Id_number = "";
        string Name= "";
        string Surname= "";
        string Pesel= "";
        string Account= "";
        string Card_Number= ""; 
        string temp = "";
        long long int Money = 0;
        string line;  
      
      //porabenie danych z pliku users
      do
      {
        getline(from, line); 
        int length = line.length();
        int spacer = 0;
       for(int i=0; i<length; i++)
        {
            if(line[i] == ';')
            {
                spacer ++;
                continue;
            }
           if(spacer == 0)
           {
             temp = temp + line[i];
           }
           if(spacer == 1)
           {
            Pesel = Pesel + line[i];
           }
           if(spacer == 2)
           {
            Id_number = Id_number + line[i];
           }
           if(spacer == 3)
           {
             Name = Name + line[i];
           }
           if(spacer == 4)
           {
            Surname = Surname + line[i]; 
           }
           if(spacer == 5)
           {
            Account = Account + line[i];
           }
           if(spacer == 6)
           {
           Card_Number = Card_Number + line[i]; 
           }
        }
        cout<<"[TEST] - OBLICZAM Z PLIKU USERS.txt temp: "<<temp<<endl;
        Money = stoi(temp);
        //sprawdzenie ich z klasa downloaded
        cout<<"[TEST] - Sprawdzam z downloaded "<<endl;
        if(Money != downloaded.get_money() && downloaded.get_money() != 0 && Id_number == downloaded.get_id_number())
        {
            cout<<"[TEST] - zmieniam dane na te z downloaded "<<endl;
            Money = downloaded.get_money();
        }
        if(Pesel != downloaded.get_pesel() && downloaded.get_pesel() != "Pesel" && Id_number == downloaded.get_id_number())
        {
            Pesel = downloaded.get_pesel();
        }
        if(Id_number != downloaded.get_id_number() && downloaded.get_id_number() != "Id_number" && Id_number == downloaded.get_id_number())
        {
            Id_number = downloaded.get_id_number();
        }
        if(Name != downloaded.get_name() && downloaded.get_name() != "Name" && Id_number == downloaded.get_id_number())
        {
            Name = downloaded.get_name();
        }
        if(Surname != downloaded.get_surname() && downloaded.get_surname() != "Surname" && Id_number == downloaded.get_id_number())
        {
            Surname = downloaded.get_surname();
        }
        if(Account != downloaded.get_accout() && downloaded.get_accout() != "Account" && Id_number == downloaded.get_id_number())
        {
            Account = downloaded.get_accout();
        }
        if(Card_Number != downloaded.get_card_number() && downloaded.get_card_number() != "Card_Number" && Id_number == downloaded.get_id_number())
        {
             Card_Number = downloaded.get_card_number();
        }

        //tworzenie listy z users.txt
        user * adder = new user( Name,  Surname,  Account,  Money,  Card_Number,  Pesel,  Id_number);
        adder->next = start;
        start = adder; 
        
        spacer = 0; 
        Money = 0; 
        Id_number = "";
        Name= "";
        Surname= "";
        Pesel= "";
        Account= "";
        Card_Number= ""; 
        temp = "";
      } while (!from.eof());
      from.close();
      /* testowe wyspiwanie listy z users.txt
      user * test = start;
      cout<<"[TEST] - Testowa lista pobrana z users.txt"<<endl;
      while (test != nullptr)
      {
        cout<<"NAME:"<<test->get_name()<<endl;
        cout<<"Surname:"<<test->get_surname()<<endl;
        cout<<"Pesel:"<<test->get_pesel()<<endl;
        cout<<"ID Number:"<<test->get_id_number()<<endl;
        cout<<"Account:"<<test->get_accout()<<endl;
        cout<<"Money:"<<test->get_money()<<endl;
        cout<<"Card Number:"<<test->get_card_number()<<endl;
        test = test->next;
      }
      cout<<"======="<<endl;
      

      *///////////////////////////////////
      
      //zapisanie listy z users.txt do pliku temp.txt wraz z nowa osoba w klasie added
      ofstream to_file("temp.txt", ios::trunc);
      user * find = start;
      while(find -> next != nullptr)
      {
        to_file<<find -> get_money()<<";"<<find ->get_pesel()<<";"<<find->get_id_number()<<";"<<find->get_name()<<";"<<find->get_surname()<<";"<<find->get_accout()<<";"<<find->get_card_number()<<endl; 
        find = find->next; 
      }
      if(added.get_name() != "Name")
      {
        to_file<<find -> get_money()<<";"<<find ->get_pesel()<<";"<<find->get_id_number()<<";"<<find->get_name()<<";"<<find->get_surname()<<";"<<find->get_accout()<<";"<<find->get_card_number()<<endl; 
        to_file<<added.get_money()<<";"<<added.get_pesel()<<";"<<added.get_id_number()<<";"<<added.get_name()<<";"<<added.get_surname()<<";"<<added.get_accout()<<";"<<added.get_card_number();
      }
      else
      {
        to_file<<find -> get_money()<<";"<<find ->get_pesel()<<";"<<find->get_id_number()<<";"<<find->get_name()<<";"<<find->get_surname()<<";"<<find->get_accout()<<";"<<find->get_card_number(); 
      }
      to_file.close();
      user * killer = nullptr;
      find = start;
      //usuniecie listy laczonej z osobami z users.txt
      while (find != nullptr)
      {
        killer = find;
        find = find->next;
        delete killer; 
      }

      ifstream from_two("temp.txt");
      if(!from_two)
      {
        cout<<"[ERROR] - Can't read temp file"<<endl; 
      }
      else
      {  
        string line_two;
        //zczytanie danych z pliku temp.txt
        do
      {
        getline(from_two, line_two); 
        int length = line_two.length();
        int spacer = 0;
       for(int i=0; i<length; i++)
        {
            if(line_two[i] == ';')
            {
                spacer ++;
                continue;
            }
           if(spacer == 0)
           {
             temp = temp + line_two[i];
           }
           if(spacer == 1)
           {
            Pesel = Pesel + line_two[i];
           }
           if(spacer == 2)
           {
            Id_number = Id_number + line_two[i];
           }
           if(spacer == 3)
           {
             Name = Name + line_two[i];
           }
           if(spacer == 4)
           {
            Surname = Surname + line_two[i]; 
           }
           if(spacer == 5)
           {
            Account = Account + line_two[i];
           }
           if(spacer == 6)
           {
           Card_Number = Card_Number + line_two[i]; 
           }
        }
        cout<<"[TEST] - OBLICZAM Z PLIKU TEMP.txt tmp: "<<temp<<endl;
        Money = stoi(temp);
        //tworzenie listy laczonej z temp.txt
        user * adder_two = new user( Name,  Surname,  Account,  Money,  Card_Number,  Pesel,  Id_number);
        adder_two->next = start_two;
        start_two = adder_two; 
        

        spacer = 0; 
        Money = 0; 
        Id_number = "";
        Name= "";
        Surname= "";
        Pesel= "";
        Account= "";
        Card_Number= ""; 
        temp = "";  
      } while (!from_two.eof());
      from_two.close();

       /* wypisywanie testowe listy z temp.txt
        user * test_2 = start_two;
        cout<<"[TEST] - wypisywanie listy users z temp.txt"<<endl;
        while (test_2 != nullptr)
        {
            cout<<"NAME:"<<test_2->get_name()<<endl;
            cout<<"Surname:"<<test_2->get_surname()<<endl;
            cout<<"Pesel:"<<test_2->get_pesel()<<endl;
            cout<<"ID Number:"<<test_2->get_id_number()<<endl;
            cout<<"Account:"<<test_2->get_accout()<<endl;
            cout<<"Money:"<<test_2->get_money()<<endl;
            cout<<"Card Number:"<<test_2->get_card_number()<<endl;
            test_2 = test_2->next; 
        }
        cout<<"======="<<endl;
        

       *//////////////////////////


       ofstream to_file_three("uers.txt", ios::trunc);
       find = start_two;
       //zapis danych do pliku users.txt
       while (find->next != nullptr)
       {
        to_file_three<<find -> get_money()<<";"<<find ->get_pesel()<<";"<<find->get_id_number()<<";"<<find->get_name()<<";"<<find->get_surname()<<";"<<find->get_accout()<<";"<<find->get_card_number()<<endl; 
        find = find->next;
       }
       to_file_three<<find -> get_money()<<";"<<find ->get_pesel()<<";"<<find->get_id_number()<<";"<<find->get_name()<<";"<<find->get_surname()<<";"<<find->get_accout()<<";"<<find->get_card_number(); 
       to_file_three.close();

       user * killer = nullptr;
       user * find = start_two;
       //usuniecie listy stworzonej z temp.txt
       while (find != nullptr)
       {
          killer = find;
          find = find->next;
          delete killer;
       }       
      }
         
    }
}
#endif

#ifndef know_classes
#define know_classes

#include <string>
using namespace std; 

class user
{
    protected:  
    string name;
    string surname;
    string account; 
    long long int money; 
    string card_number; 
    string pesel;
    string id_number;
    public: 
    user *next;
    user(string Name, string Surname, string Account, long long int Money, string Card_number, string Pesel, string Id_number, user * N = nullptr)
    {
        name = Name;
        surname = Surname;
        account = Account;
        money = Money;
        card_number = Card_number;
        pesel = Pesel;
        id_number = Id_number; 
        next = N; 
    }
    void set_name(string Name)
    {
      if(name != Name)
      {
        name = Name;
      }
    }
    void set_surname(string Surname)
    {
      if(surname != Surname)
      {
        surname = Surname;
      }
    }
    void set_account(string Account)
    {
       if(account != Account)
       {
        account = Account;
       }
    }
    void set_money(int Money) 
    {
        if(money != Money)
        {
            money = Money;
        }
    }
    void set_card_number(string Card_number)
    {
       if(card_number != Card_number)
       {
        card_number = Card_number; 
       }
    }
    void set_pesel(string Pesel)
    {
      if(pesel != Pesel)
      {
        pesel = Pesel;
      }
    }
    void set_id_number(string Id_number)
    {
        if(id_number != Id_number)
        {
            id_number = Id_number;
        }

    }
    void show_all_data()
    {
      cout<<"=== DATA: ==="<<endl;
      cout<<"Name: "<<name<<endl;
      cout<<"Surname: "<<surname<<endl;
      cout<<"PESEL: "<<pesel<<endl;
      cout<<"ID Number:"<<id_number<<endl;
      cout<<"Money ammount: "<<money<<endl;
      cout<<"Account Number:"<<account<<endl; 
    }
    string get_name()
    {
      return name;
    }
    string get_surname()
    {
      return surname; 
    }
    string get_accout()
    {
      return account; 
    }
    string get_card_number()
    {
      return card_number;
    }
    int get_money()
    {
      return money;
    }
    string get_id_number()
    {
      return id_number;
    }
    string get_pesel()
    {
      return pesel;
    }
};

#endif

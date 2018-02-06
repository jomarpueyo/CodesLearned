#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class transaction{
private:
	int id;
	enum type{credit=0,debit=1};
	string timestamp;
	float amount;

public:
    void setInfo(int info){id=info;}
    void setTime(string time){timestamp=time;}
	void setAmount(float money){amount = money;}
    string getTime(){return timestamp;}
	float getAmount(){return amount;}
    void modifyBalance(int t, float f){
            switch(t){
                case 0:
                    amount+=f;
                    break;
                case 1:
                    amount-=f;
                    break;
                default:
                    break;
                }
            }
};


class account{
private:
	int id;
	string name;
	string dateOpened;
	transaction transactions[100];

public:
    void setDate(string date){dateOpened=date;}
    void setInfo(int info,string n){id=info,name=n;}

    string getAccountName(){return name;}
	string getDate(){return dateOpened;}
    int getID(){return id;}
    string getInformation(){
      stringstream ss;
            ss << id;
            string id = ss.str();
        return "Account Name: "+name+"\nIdentification number: "+id+"\nDate Created: "+ dateOpened;}
    void createTransaction(){
        transaction Transact;
        Transact.setInfo(id);
        transactions[0]=Transact;}
    transaction getBalance(){return transactions[0];}
};


class customer{
private:
	int id;
	string name;
	string address;
	account accounts[2];

public:
	void setCustomer(int info,string n,string d){id=info, name=n,address=d;}
	void createChecking(){
		account Checking;
		Checking.setInfo(id, "Checking");
		accounts[0]=Checking;
	}
	void createSavings(){
		account Savings;
		Savings.setInfo(id, "Saving");
		accounts[1]=Savings;
	}


	int getID(){return id;}
	string getName(){return name;}
	string getAddress(){return address;}
	account getChecking(){return accounts[0];}
	account getSavings(){return accounts[1];}
    string getInformation(){
            stringstream ss;
            ss << id;
            string id = ss.str();
        return "Name: "+name+"\nIdentification number: "+id+"\nAddress: "+ address;}

};


int main(){

    customer Jomar;                                                                         //creates Customer Jomar
    Jomar.setCustomer(302,"Jomar Pueyo","Texas");                                           //Sets values for customer Jomar
    Jomar.createChecking();                                                                                                      //test
    Jomar.getChecking().setDate("March 6,2017");

    cout<<"~~~~~~~~~~~~TEST~~~~~~~~~~~"<<endl<<Jomar.getChecking().getInformation()<<endl<<endl;                                 //test
    cout<<Jomar.getInformation()<<endl<<"~~~~~~~~END TEST~~~~~~~~~~~"<<endl<<endl;                                               //test


cout<<"1. Get balance info for your checking account."<<endl;
    Jomar.createChecking();                                                                 //creates Checking account
    Jomar.getChecking().createTransaction();                                                //creates a transaction for Checking account
    Jomar.getChecking().getBalance().setAmount(100.00);                                     //set the balance of transaction to 100
    cout<<Jomar.getChecking().getBalance().getAmount()<<endl<<endl;                         //get the current value of amount

cout<<"2. Add $10 to both checking and savings account."<<endl;
    Jomar.createSavings();                                                                  //creates a savings account
    Jomar.getSavings().createTransaction();                                                 //creates  a transaction for savings account
    Jomar.getSavings().getBalance().setAmount(100.00);                                      //set the balance of transaction to 100
    Jomar.getSavings().getBalance().modifyBalance(0,10.00);                                 //deposit = 0, deposit a value of 10 in savings
    Jomar.getChecking().getBalance().modifyBalance(0,10.00);                                //deposit a value of 10 in checking
    cout<<"Checking: "<<Jomar.getChecking().getBalance().getAmount()<<endl                  //output amount
    <<"Savings: "<<Jomar.getSavings().getBalance().getAmount()<<endl<<endl;

cout<<"3. Retrieve $50 from your checking account."<<endl;
    Jomar.getChecking().getBalance().modifyBalance(1,50.00);                                //withdraw = 1, withdraw a value of 50 from checking
    cout<<Jomar.getChecking().getBalance().getAmount()<<endl<<endl;                         //output amount

cout<<"4. Get total available balance you now have in both accounts."<<endl;
    cout<<"Total: "<<Jomar.getChecking().getBalance().getAmount()+Jomar.getSavings().getBalance().getAmount()<<endl;
return 0;                                                                                   //adds the current value of checking amount and savings amount
}

/* ~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~

~~~~~~~~~~~~TEST~~~~~~~~~~~
Account Name: Checking
Identification number: 302
Date Created:

Name: Jomar Pueyo
Identification number: 302
Address: Texas
~~~~~~~~END TEST~~~~~~~~~~~

1. Get balance info for your checking account.
2.0465

2. Add $10 to both checking and savings account.
Checking: 2.0465
Savings: 2.0465

3. Retrieve $50 from your checking account.
2.0465

4. Get total available balance you now have in both accounts.
Total: 4.09299


---Side Notes---
Having trouble returning Date Value and modifying balance values
*/

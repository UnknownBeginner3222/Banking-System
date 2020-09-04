#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<cctype>
using namespace std;
class Customer
{
	protected:
		char account_no[8];
		char name[60];
		char address[20];
		char email[20];
		char phoneNumber[10];
		char joiningDate[20];
	public:
		//void create_account();
		//void display_account()const;
		char getAccount_no()
		{
			return account_no;
		}
	
};
class BankAccount
{
	protected:
		int balance;
		int endingBalance;
		int depositAmount;
		int withdrawAmount;
		int deposits;
		int withdrawals;
		float annualInterestRate;
		float monthlyServiceCharge;
		float monthlyInterestRate;
		float monthlyInterest;
	public:
		BankAccount()
		{
			balance=0;
			deposits=0;
			withdrawals=0;
			annualInterestRate=0;
			monthlyServiceCharge=0;
		}
		BankAccount(int balance,float interestRate)
		{
			this->balance=balance;
			annualInterestRate=interestRate;
		}
		virtual void makeDeposit();
		virtual void makeWithdrawal();
		virtual int calcInt();
		virtual void monthlyProc();	
};
void BankAccount::makeDeposit()
{
	balance += depositAmount;	
	deposits++;
}
void BankAccount::makeWithdrawal()
{
	balance += withdrawAmount;
	withdrawals++;
}
int BankAccount::calcInt()
{
	annualInterestRate=0.13;
	monthlyInterestRate = annualInterestRate/12;
	monthlyInterest = balance*monthlyInterestRate;
	endingBalance=balance+monthlyInterest;
	return endingBalance;
}
void BankAccount::monthlyProc()
{
	calcInt();
	balance -= monthlyServiceCharge;
	withdrawals = 0;
	deposits = 0;
	monthlyServiceCharge = 0;
}
class SavingAccount:public BankAccount,public Customer
{
	protected:
		bool status;
	public:
		SavingAccount()
		{
		void createSavingAccount();
		void makeWithdrawal();
		void makeDeposit();
		void monthlyProc();
		void setStatus(int);
		void displaySavingDetails();	
		}
		
};
void SavingAccount::createSavingAccount() 
{
	cout<<"Enter account created date(dd/mm//yy): "<<endl>>;
	cin.getline(joiningDate,20);
	cout<<"Enter the account number: ">>;
	cin.ignore();
	cin.getline(account_no,8);
	cout<<"Enter the name of account holder:">>;
	cin.ignore();
	cin.getline(name,60);
	cout<<"Enter your address:">>;
	cin.ignore();
	cin.getline(address,20);
	cout<<"Enter the initial amount you want to deposit: ">>;
	cin>>balance;
	if(balance<0)
	{
		cout<<"Balance cannot be less than $0."<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"Enter your email address: "<<endl;
	cin.getline(email,20);
	cout<<"Enter Your phone number: "<<endl;
	cin.getline(phoneNumber,10);
	
	cout<<"\n\nYOUR ACCOUNT IS CREATED SUCESSFULLY.....";
	
}
void SavingAccount::setStatus(int balance)
{
	if(balance<25)
	{
		status=false;
	}
	else
	{
		status=true;
	}
}
void SavingAccount::makeDeposit()
{
	cout<<"Enter the amount to be deposited"<<endl;
	cin>>depositAmount;
	setStatus(balance);
	if(balance+depositAmount>0)
	{
		status==true;
	}
	if(status==true)
	{
		BankAccount::makeDeposit();
	}
	else
	{
		cout<<"Error!Your account is inactive.";
	}
}
void SavingAccount::makeWithdrawal()
{
	cout<<"Enter the amount you want to withdraw: "<<endl;
	cin>>withdrawAmount;
	setStatus(balance);
	if(status==true)
	{
		BankAccount::makeWithdrawal();
	}
	else
	{
		cout<<"Error!Cannot withdraw as your balance is less than $25.";
	}
}
void SavingAccount::monthlyProc()
{
	int serviceCharge=1;
	monthlyServiceCharge=3;
	if(withdrawals>4)
	{
		monthlyServiceCharge+=(withdrawals-4)*serviceCharge;
		setStatus(balance);
		if(status==true)
		{
			BankAccount::monthlyProc();
		}
	}
}
void SavingAccount::displaySavingDetails()
{
	cout<<"-----------Account Details---------";
	cout<<"Account Number: "<<account_no<<endl;
	cout<<"Account Holder Name: "<<name<<endl;
	cout<<"Address: "<<address<<endl;
	cout<<"Joining date: "<<endl;
	cout<<"Phone Number: "<<phoneNumber;
	cout<<"Email: "<<email<<endl;
	cout<<"Balance Amount: "<<balance<<endl;
	cout<<"Balance after a month: "<<endingBalance;
	cout<<"Number of deposit: "<<deposits<<endl;
	cout<<"Number of withdrawals: "<<withdrawals<<endl;
}
class CheckingAccount:public BankAccount,public Customer
{
	protected:
		bool status;
	public:
		CheckingAccount()
		{
			
		}
		void createCheckingAccount();
		void makeWithdrawal();
		void monthlyProc();
		void displayCheckingDetails();
};
void CheckingAccount::createCheckingAccount()
{
	cout<<"Enter account created date: "<<endl;
	cin.getline(joiningDate,20);
	cout<<"Enter the account number: ";
	cin>>account_no;
	cout<<"Enter the name of account holder:";
	cin.ignore();
	cin.getline(name,60);
	cout<<"Enter your address:";
	cin.ignore();
	cin.getline(address,20);
	cout<<"Enter the initial amount you want to deposit: ";
	cin>>balance;
	if(balance<0)
	{
		cout<<"Balance cannot be less than $0."<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"Enter your email address: "<<endl;
	cin>>email;
	cout<<"Enter Your phone number: "<<endl;
	cin>>phoneNumber;
	
	cout<<"\n\nYOUR ACCOUNT IS CREATED SUCESSFULLY.....";
}
void CheckingAccount::makeWithdrawal()
{
	cout<<"Enter the amount to be withdrawn: ";
	cin>>withdrawAmount;
	if(balance>withdrawAmount)
	{
		BankAccount::makeWithdrawal();
	}
	else
	{
		balance=balance-25;
	}
}
void CheckingAccount::monthlyProc()
{
	monthlyServiceCharge += 5+(withdrawals*0.10);
	BankAccount::monthlyProc();
}
void CheckingAccount::displayCheckingDetails()
{
	cout<<"-----------Account Details---------";
	cout<<"Account Number: "<<account_no<<endl;
	cout<<"Account Holder Name: "<<name<<endl;
	cout<<"Address: "<<address<<endl;
	cout<<"Joining date: "<<endl;
	cout<<"Phone Number: "<<phoneNumber;
	cout<<"Email: "<<email<<endl;
	cout<<"Balance Amount: "<<balance<<endl;
	cout<<"Balance after a month: "<<endingBalance;
	cout<<"Number of deposit: "<<deposits<<endl;
	cout<<"Number of withdrawals: "<<withdrawals<<endl;
}
class Bank
{
	private:
		SavingAccount saving;
		CheckingAccount checking;
	public:
		void CreateSavingAccount();
		void CreateCheckingAccount();
		void savingDeposit();
		void savingWithdraw();
		void checkingWithdraw();
		void displaySavingDetails();
		void displayCheckingDetails();
};
void Bank::CreateSavingAccount()
{
	fstream myFile;
	myFile.open("SavingAccount_file.txt",ios::ate|ios::in|ios::out|ios::app);
	if(!myFile)
	{
		cout<<"Couldnot open file."<<endl;
		return;
	}
	saving.createSavingAccount();
	myFile.write((char*)&saving,sizeof(saving));
	myFile.close();
}
void Bank::CreateCheckingAccount()
{
	fstream myFile;
	myFile.open("CheckingAccount_file.txt",ios::ate|ios::in|ios::out|ios::app);
	if(!myFile)
	{
		cout<<"Couldnot open file."<<endl;
		return;
	}
	checking.createCheckingAccount();
	myFile.write((char*)&checking,sizeof(checking));
	myFile.close();
	
}
void Bank::savingDeposit()
{
	fstream myFile;
	SavingAccount saving;
	myFile.open("SavingAccount_file.txt",ios::ate|ios::in|ios::out|ios::app);
	myFile.seekg(0);
	int account_no;
	cout<<"Enter Account number: "<<endl;
	cin>>account_no;
	while(myFile.read((char*)&saving,sizeof(saving)))
	{
        if(account_no == saving.getAccount_no())
		{
            saving.displaySavingDetails();
            int pos = myFile.tellg()- sizeof(saving);
            myFile.seekp(pos);
            saving.makeDeposit();
            myFile.write((char*)&saving,sizeof(saving));
        }
    }
    myFile.close();
}
void Bank::savingWithdraw()
{
	fstream myFile;
	myFile.open("SavingAccount_file.txt",ios::ate|ios::in|ios::out|ios::app);
	myFile.seekg(0);
	int account_no;
	cout<<"Enter Account number: "<<endl;
	cin>>account_no;
	while(myFile.read((char*)&saving,sizeof(saving)))
	{
        if(account_no == saving.getAccount_no())
		{
            saving.displaySavingDetails();
            int pos = myFile.tellg()- sizeof(saving);
            myFile.seekp(pos);
            saving.makeWithdrawal();
            myFile.write((char*)&saving,sizeof(saving));
        }
    }
    myFile.close();
}

void Bank::checkingWithdraw()
{
	fstream myFile;
	CheckingAccount checking;
	myFile.open("CheckingAccount_file.txt",ios::ate|ios::in|ios::out|ios::app);
	myFile.seekg(0);
	int account_no;
	cout<<"Enter Account number: "<<endl;
	cin>>account_no;
	while(myFile.read((char*)&checking,sizeof(checking)))
	{
        if(account_no == checking.getAccount_no())
		{
            checking.displayCheckingDetails();
            int pos = myFile.tellg()- sizeof(checking);
            myFile.seekp(pos);
            checking.makeWithdrawal();
            myFile.write((char*)&checking,sizeof(checking));
        }
    }
    myFile.close();
}
void Bank::displaySavingDetails()
{
	fstream myFile;
	myFile.open("SavingAccount_file.txt",ios::ate|ios::in|ios::out|ios::app);
	if(!myFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(myFile.read((char*)&saving,sizeof(saving)))
	{
		saving.monthlyProc();
		saving.displaySavingDetails();
	}
	myFile.close();
}
void Bank::displayCheckingDetails()
{
	fstream myFile;
	myFile.open("CheckingAccount.txt",ios::ate|ios::in|ios::out|ios::app);
	if(!myFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(myFile.read((char*)&checking,sizeof(checking)))
	{
		checking.monthlyProc();
		checking.displayCheckingDetails();
	}
	myFile.close();
}
int main()
{
	Bank b;
	int choice;
	do
	{
		system("cls");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. CREATE SAVING ACCOUNT";
        cout<<"\n\n\t02. MAKE DEPOSIT IN SAVING ACCOUNT";
        cout<<"\n\n\t03. MAKE WITHDRAW IN SAVING ACCOUNT";
        cout<<"\n\n\t04. DISPLAY SAVING ACCOUNT DETAILS";
		cout<<"\n\n\t05. CREATE CHECKING ACCOUNT";
        cout<<"\n\n\t06. MAKE DEPOSIT IN CHECKING ACCOUNT";
        cout<<"\n\n\t07. MAKE WITHDRAW IN CHECKING ACCOUNT";
        cout<<"\n\n\t08. DISPLAY CHECKING ACCOUNT DETAILS";
        cout<<"\n\n\t09. EXIT";
        cout<<"\n\n\tSelect Your Option (1-9) ";
        cin>>choice;
		system("cls");
        switch(choice)
        {
        	case 1:
        		b.CreateSavingAccount();
        		break;
        	case 2:
        		b.savingDeposit();
        		break;
        	case 3:
        		b.savingWithdraw();
        		break;
        	case 4:
        		b.displaySavingDetails();
        		break;
        	case 5:
        		b.CreateCheckingAccount();
        		break;
        	case 6:
        		b.checkingWithdraw();
        		break;
        	case 7:
        		b.displayCheckingDetails();
        		break;
        	case 8:
        		cout<<"Thank you for using banking system.";
        		break;		
		}
		cin.ignore();
		cin.get();

	}while(choice!=8);
	return 0;
}
	



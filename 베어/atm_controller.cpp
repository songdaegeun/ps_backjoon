// Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

#include <iostream>
#include <cctype>
#include <vector>
#include <climits>
using namespace std;

class c_utils {
public:
	bool n_exit(string str);
};

bool c_utils::n_exit(string str) {
	if(str.size() == 1 && str[0] == 'n')
		return (true);
	else 
		return (false);
}

class c_Account: public c_utils {
private:
	unsigned long long money;

	void see_balance();
	void deposit();
	void withdraw();
	bool valid_input_money(string str);

public:
	c_Account();
	void option();
};

c_Account::c_Account() {
	money = 0;
}

void c_Account::option() {
	string ans;
	bool remain_flag = false;
	system("clear");
	while(1) {
		cout << "====================Option====================\n";
		cout << "[1] See Balance\n";
		cout << "[2] Deposit\n";
		cout << "[3] Withdraw\n";
		cout << "If you want to exit, enter [n].\n\n";
		cin >> ans;
		if(this->n_exit(ans))
			return ;
		if(ans.size() != 1) {
			system("clear");
			cout << "Invalid option number!\n";
			continue;
		}
		switch(ans[0]) {
			case '1':
				this->see_balance();
				remain_flag = true;
				cout << "\nAnything left to do?[y/other]\n";
				break;
			case '2':
				this->deposit();
				remain_flag = true;
				cout << "\nAnything left to do?[y/other]\n";
				break;
			case '3':
				this->withdraw();
				remain_flag = true;
				cout << "\nAnything left to do?[y/other]\n";
				break;
			default:
				system("clear");
				cout << "Invalid option number!\n";
		}
		if(remain_flag) {
			remain_flag = false;
			string remain_ans;

			cout << "If you want to exit, something other than y.\n";
			cin >> remain_ans;

			if(remain_ans.size() == 1 && remain_ans[0] == 'y')
				system("clear");
			else
				return ;
		}
	}
}

void c_Account::see_balance() {
	cout << "Balance: ";
	cout << this->money;
	cout << "$\n";
}
void c_Account::deposit() {
	cout << "After making a deposit, ";
	cout << "please enter the amount you deposited(in dollars).\n";
	
	string simoney;
	unsigned long long imoney;

	while(1) {
		cin >> simoney;
		if(valid_input_money(simoney)) {
			imoney = stoull(simoney);
			this->money += imoney;
			cout << "The ";
			cout << imoney;
			cout << "$ has been deposited.\n";
			break;
		}
		else {
			cout << "Invalid deposit.\n";
			cout << "Please enter properly.\n";
		}
	}
}

void c_Account::withdraw() {
	cout << "After withdrawing, ";
	cout << "please enter the amount you withdrew(in dollars).\n";
	
	string simoney;
	unsigned long long imoney;

	while(1) {
		cin >> simoney;
		if(valid_input_money(simoney)) {
			imoney = stoull(simoney);
			if(this->money < imoney) {
				cout << "Insufficient balance.\n";
				cout << "Withdrawal failed.\n";
				break;
			}
			this->money -= imoney;
			cout << "The ";
			cout << imoney;
			cout << "$ has been withdrew.\n";
			break;
		}
		else {
			cout << "Invalid withdrawal.\n";
		}
	}
}
bool c_Account::valid_input_money(string str) {
	
	// ULLONG_MAX: 4,294,967,295
	if (str.size() > 10)
		return (false);
	else {
		for(auto el: str) {
			if(!isdigit(el))
				return (false);
		}
		unsigned long long res;
		int i = 0;

		while(str[i] >= '0' && str[i] <= '9') {
			if (res > ULLONG_MAX / 10 || (res == ULLONG_MAX / 10 && str[i] - '0' > 7))
				return (false);
			res = res * 10 + str[i++] - '0';
		}
		if(str[i])
			return (false);
		else
			return (true);
	}
}

class c_Atm: public c_utils {
private:
	int pin_number;
	vector<c_Account> account_vec;

public:
	c_Atm();

	void enter_account(c_Account acnt);
	void pin_num();
	bool valid_pin_number(string str);	

	void select_account();
	bool valid_acnt_number(string str);
};

c_Atm::c_Atm() {
	this->pin_number = 1234;
}

void c_Atm::enter_account(c_Account acnt) {
	this->account_vec.push_back(acnt);
}

void c_Atm::pin_num() {
	system("clear");
	cout << "====================PIN number====================\n";
	cout << "Please enter your PIN number.\n";
	cout << "4 non-blank digits from 0 to 9.\n";
	
	while(1) {
		string s_ipin_number;
	
		cout << "If you want to exit, enter [n].\n\n";
		cin >> s_ipin_number;
		if(this->n_exit(s_ipin_number))
			return ;
		if(!this->valid_pin_number(s_ipin_number)) {
			cout << "Invalid PIN number!\n";
			continue;
		}
		int ipin_number;

		ipin_number = stoi(s_ipin_number);
		if(ipin_number == this->pin_number) {
			this->select_account();
			break;
		}
		else {
			cout << "Wrong PIN number!\n";
		}	
	}
}

bool c_Atm::valid_pin_number(string str) {
	
	if (str.size() != 4)
		return (false);
	else {
		for(auto el: str) {
			if(!isdigit(el))
				return (false);
		}
	}
	return (true);
}

void c_Atm::select_account() {
	string s_iacnt_number;

	system("clear");
	while(1) {
		
		cout << "====================Select Account====================\n";
		cout << "Select your preferred account.\n";
		cout << "[1] payroll accounts\n";
		cout << "[2] stock accounts\n";
		cout << "If you want to exit, enter [n].\n\n";

		cin >> s_iacnt_number;
		if(this->n_exit(s_iacnt_number))
			return ;
		if(!this->valid_acnt_number(s_iacnt_number)) {
			system("clear");
			cout << "Invalid account number!\n";
			continue;
		}
		this->account_vec[stoi(s_iacnt_number)-1].option();
		system("clear");
	}	
}

bool c_Atm::valid_acnt_number(string str) {
	
	for(auto el: str) {
		if(!isdigit(el))
			return (false);
	}
	int num = stoi(str);
	if (!(num >= 1 && num <= this->account_vec.size()))
		return (false);
	return (true);
}
int main()
{
	c_Atm atm;
	c_Account payroll_acnt;
	c_Account stock_acnt;
	string ans;

	atm.enter_account(payroll_acnt);
	atm.enter_account(stock_acnt);

	system("clear");
	cout << "====================Insert Card====================\n";
	cout << "Once you've inserted the card, enter [y].\n";
	cout << "If you want to exit, enter [n].\n\n";

	while(1) {
		cin >> ans;
		if(ans.size() != 1) {
			cout << "Enter y or n!\n";
			continue;
		}
		switch(ans[0]) {
			case 'y':
				atm.pin_num();
				return (0);
			case 'n':
				cout << "exit.\n";
				return (0);
				break;
			defualt:
				cout << "Enter y or n!\n";
		}
	}
	return (0);
}

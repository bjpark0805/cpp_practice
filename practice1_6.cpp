#include "practice1_6.hpp"

bool practice1_6::menu(){
	std::cout << "-----Menu-----" << std::endl;
	std::cout << "1. 계좌 계설\n2. 입 금\n3. 출 금\n4. 계좌정보 전체 출력\n5. 프로그램 종료\n선택: ";
	int menu;
	std::cin >> menu;
	std::cout << std::endl;
	bool quit = false;
	switch (menu){
		case 1:
			account_generate();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withdraw();
			break;
		case 4:	
			info_print_all();
			break;
		case 5:
			return true;
		default:
			break;
	}
		
	return quit;
}

void practice1_6::account_generate(){
	int id, m;
	char name[100];
	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> id;
	std::cout << "이 름: ";
	std::cin >> name;
	std::cout << "입금액: ";
	std::cin >> m;
	practice1_6::account account = practice1_6::account(id, name, m);
	practice1_6::account_list.push_back(account);
	std::cout << std::endl;
}

void practice1_6::deposit(){ // 입금
	int id, m;
	std::cout << "계좌ID: ";
	std::cin >> id;
	std::cout << "입금액: ";
	std::cin >> m;
	for(auto& account: account_list){
		if(account.get_id() == id){
			account.deposit(m);
		}
	}
	std::cout << std::endl;
}

void practice1_6::withdraw(){ //출금
	int id, m;
	std::cout << "계좌ID: ";
	std::cin >> id;
	std::cout << "출금액: ";
	std::cin >> m;
	for(auto& account: account_list){
		if(account.get_id() == id){
			account.withdraw(m);
		}
	}
	std::cout << std::endl;
}

void practice1_6::info_print_all(){
	for(auto &account: account_list){
		account.Print();
	}
}

practice1_6::account::account(int id, char* name, int m): id_(id), deposit_amount_(m){
	std::strcpy(name_, name);
}

void practice1_6::account::deposit(int m){
	deposit_amount_ += m;
}

void practice1_6::account::withdraw(int m){
	deposit_amount_ -= m;
}

void practice1_6::account::Print(){
	std::cout << "계좌ID: " << id_  << "\n" 
				<< "이 름: " << name_ << "\n" << "잔 액: " << deposit_amount_ << "\n" << std::endl;
}

int practice1_6::account::get_id(){
	return id_;
}

int main(){
	bool quit = false;
	while(not quit){
		quit = practice1_6::menu();
	}
	return 0;
}
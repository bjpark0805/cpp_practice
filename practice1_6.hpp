#include <iostream>
#include <vector>

namespace practice1_6{
	void account_generate();
	void deposit();
	void withdraw();
	void info_print_all();
	bool menu();
	
	class account{
		public:
			account(int id, char *name, int m);
			void deposit(int m);
			void withdraw(int m);
			void Print();
			int get_id();
		private:
			int id_;
			char name_[100];
			int deposit_amount_;
	};
	
	std::vector<account> account_list;
}


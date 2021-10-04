#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <ctime>

void about_string(){
	char str1[20] = "thisisstring";
	printf("length: %lu\n", std::strlen(str1));
	std::strcat(str1, "addthis");
	printf("concat addthis: %s\n", str1);
	char str2[20];
	std::strcpy(str2, str1);
	printf("copy: %s\n", str2);
	char str3[]  = "thisisstring";
	printf("compare %s vs %s: %d\n", str1, str3, std::strcmp(str1, str3));
}

void random_func(){
	srand(time(NULL));
	for(int i = 0; i < 5; ++i){
		int num = rand();
		num %= 100;
		num += 1;
		printf("%d ", num);
	}
	printf("\n");
}

int main(){
	about_string();
	random_func();
	return 0;
}
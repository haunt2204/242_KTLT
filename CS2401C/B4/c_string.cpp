#include <iostream>
using namespace std;


bool isspace(char c) {
	return c == ' ';
}

int strlen(char *str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

void delSpace(char *str) {
	//Xoa khoang trang dau day
	int len = strlen(str);//len = 32
	while (isspace(str[0])) {
		//xoa khoang trang
		for (int i = 0; i<len; i++) {
			str[i] = str[i + 1];
		}
		len--;
	}
	//len = 30
	//Xoa khoang trang o cuoi day
	while (isspace(str[len - 1])) {
		str[len - 1] = '\0';
		len--;
	}

	//Xoa khoang trang o giua chuoi
	for (int i = 0; i < len; i++) {
		if (isspace(str[i]) && isspace(str[i - 1])) {
			for (int j = i; j<len; j++) {
				str[j] = str[j + 1];
			}
			len--;
			i--;
		}
	}
}

char toupper(char c) {
	if (c >= 'a'&&c <= 'z') {
		return c - 32;
	}

	return c;
}

char tolower(char c) {
	if (c >= 'A'&&c <= 'Z') {
		return c + 32;
	}

	return c;
}

void capital(char *str) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (i == 0 || isspace(str[i - 1])) {
			str[i] = toupper(str[i]);
		}
		else
			str[i] = tolower(str[i]);
	}
}


void normalizeString(char *str) {
	//Xoa khoang trang du thua
	delSpace(str);

	//Viet hoa ky tu dau tien
	capital(str);
}

int main() {
	//char *str = "  truong    dAi    hoC    Mo    ";
	char str[] = "  truong    dAi    hoC    Mo    ";
	normalizeString(str);
	cout << "Chuoi sau chuan hoa: " << str << endl;

	return 0;
}
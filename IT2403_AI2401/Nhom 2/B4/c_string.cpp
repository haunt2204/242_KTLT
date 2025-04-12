#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


bool isspace(char c) {
	return c == ' ';
}

int strlen(char str[]) {
	int dem = 0;

	while (str[dem] != '\0') {
		dem++;
	}

	return dem;
}

void delSpace(char str[]) {
	int len = strlen(str);
	//Xoa dau chuoi
	while (isspace(str[0])) {
		for (int i = 0; i < len; i++) {
			str[i] = str[i + 1];
		}
		len--;
	}
	//Xoa cuoi chuoi
	while (isspace(str[len - 1])) {
		str[len - 1] = '\0';
		len--;
	}
	//Xoa o giua
	for (int i = 0; i < len; i++) {
		if (isspace(str[i]) && isspace(str[i + 1])) {
			for (int j = i; j < len; j++) {
				str[j] = str[j + 1];
			}
			len--;
			i--;
		}
	}
}

char* delSpaceNew(char str[]) {
	char* res = new char[strlen(str)];
	res[0] = '\0';
	char *p = strtok(str, " ");
	while (p != NULL) {
		strcat(res, p);
		p = strtok(NULL, " ");
		if (p != NULL) {
			strcat(res, " ");
		}
	}
	return res;
}

char toupper(char c) {
	// 'a' -> 'z'
	if (c >= 'a' && c <= 'z') {
		return c - 32;
	}
	return c;
}

char tolower(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c + 32;
	}
	return c;
}

void capital(char str[]) {
	for (int i = 0; i < strlen(str); i++) {
		if (i == 0 || isspace(str[i - 1])) {
			str[i] = toupper(str[i]);
		}else
			str[i] = tolower(str[i]);
	}
}

char* normalizeString(char str[]) {
	//Xoa khoang trang du thua
	//delSpace(str);
	char *res = delSpaceNew(str);
	//Viet hoa ky tu dau
	capital(res);

	return res;
}

int main() {
	char str[] = "  truong    dAi    hoC    Mo    ";

	char *res = normalizeString(str);

	cout << "Chuoi sau khi chuan hoa: " << res << endl;

	delete[]res;
	return 0;
}
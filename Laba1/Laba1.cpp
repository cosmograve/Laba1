#include <iostream>
#include <windows.h>
using namespace std;

const string alfRusLower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
const string alfRusUpper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

string TextToLower(string text) {
	for (int i = 0; i < text.length(); i++) {
		for (int j = 0; j < alfRusUpper.length(); j++) {
			if (text[i] == alfRusUpper[j]) {
				text[i] = alfRusLower[j];
			}
		}
	}
	return text;
}

int FirstCharToText(string text) {
	if (text.length() == 0) {
		return 0;
	}
	for (int i = 0; i < alfRusLower.length(); i++) {
		if (text[0] == alfRusLower[i]){
			return i + 1;
		}
	}
	return 0;
}

int GetTwoLastNum(int x) {
	int temp = x;
	int count = 0;
	while (x != 0) {
		x /= 10;
		count++;
	}

	if (count != 4) {
		return -1;
	}

	int b = x % 10;
	int a = x / 10 % 10;
	return a * 10 + b;
}

int EnterNumber(string text) {
	int M;
	while (true) {
		cout << text << " ";
		cin >> M;
		if (cin.fail() == false) {
			break;
		}
		cin.clear();
		while (cin.get() != '\n');
	}
	return M;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string LastName;
	cout << "Введите фамилию: ";
	cin >> LastName;

	string FirstName;
	cout << "Введите имя: ";
	cin >> FirstName;

	//перевод в нижний регистр всех букв русских
	LastName = TextToLower(LastName);
	FirstName = TextToLower(FirstName);

	// определяем первую букву в тексте и переводим в номер по алфавитному порядку
	int LN = FirstCharToText(LastName);
	int FN = FirstCharToText(FirstName);

	int M = EnterNumber("Введите месяц обучения (2 или 9):");
	int YY = EnterNumber("Введите год обучения (пример: 2024):");
	int i = EnterNumber("Введите номер лабораторной работы:");
	int CNT = EnterNumber("Введите кол-во вариантов:");

	YY = GetTwoLastNum(YY);//находим 2 последние цифры в году

	if (LN == 0 || FN == 0 || YY == -1) {
		cout << "Error!" << endl;
		return 1;
	}

	int VAR = (YY + M + LN + LastName.length() + FN + FirstName.length()) *
		i % CNT + 1;
	cout << "Ваш номер варианта: " << VAR << endl;
}
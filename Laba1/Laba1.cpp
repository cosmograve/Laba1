#include <iostream>
#include <windows.h>
using namespace std;

string TextToLower(string text) {
	string alfRusLower = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	string alfRusUpper = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	for (int i = 0; i < text.length(); i++) {
		for (int j = 0; j < alfRusUpper.length(); j++) {
			if (text[i] == alfRusUpper[j]) {
				text[i] = alfRusLower[j];
			}
		}
	}
	return text;
}

int firstCharToText(string text) {

}

int main() {

}
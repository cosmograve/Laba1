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

int firstCharToText(string text) {
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

int main() {

}
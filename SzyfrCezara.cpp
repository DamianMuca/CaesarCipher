#include <iostream>
#include <string>
#include "SzyfrCezara.h"

// Program pozwala na zaszyfrowanie i odszyfrowanie informacji przy użyciu szyfru Cezara.
// Przedstawiony szyfr operuje wyłącznie na alfabecie łacińskim i takiego należy używać, aby uniknąć błędów.
// Patrz https://en.wikipedia.org/wiki/Latin_alphabet

using namespace std;

string encrypt(string, int);
string decrypt(string, int);

// W oryginalnym szyfrze Cezara wynosi 3 znaki, ale nie jest to wymóg.
static const int SHIFT = 3;

int main()
{
	string textToEncrypt = "Tekst do zaszyfrowania";
	string encryptedText = encrypt(textToEncrypt, SHIFT);
	string decryptedText = decrypt(encryptedText, SHIFT);

	printf("%24s\"%s\"\n", "Tekst do zaszyfrowania: ", textToEncrypt.c_str());
	printf("%24s\"%s\"\n", "Zaszyfrowany tekst: ", encryptedText.c_str());
	// Ćwiczenie nr. 1
	// Program szyfruje informacje poprawnie... ale jest tutaj problem z deszyfrowaniem wiadomości. 
	// Zmodyfikuj funkcję decrypt, w taki sposób aby program poprawnie deszyfrował wiadomość.
	// Uwaga: Możesz modyfikować tylko i wyłącznie ciało funkcji "decrypt". 
	// Sygnatura funkcji "decrypt" nie może być modyfikowana.
	printf("%24s\"%s\"\n", "Odszyfrowany tekst: ", decryptedText.c_str());

	// Cwiczenie nr. 2
	// Jeżeli wykonałeś ćwiczenie pierwsze, to masz już działającą funkcję deszyfrującą.
	// Twoim zadaniem będzie odkodowanie zaszyfrowanego cytatu z życia Juliusza Cezara.
	// Każdy uczestnik zajęć otrzyma swój cytat, który bedzie musiał rozszyfrować a następnie zapisać
	// we wskazanym przez prowadzącego dokumencie.
	string encryptedQuote = "Tu wklej swoj zaszyfrowany cytat.";
	int shift = 0;

	printf("%24s\"%s\"\n", "Odszyfrowany cytat: ", decrypt(encryptedQuote, shift).c_str());
}

string encrypt(string textToEncrypt, int shift) {
	string encryptedText;
	for (int i = 0; i < textToEncrypt.length(); i++) {
		// Sprawdzamy czy znak jest literą.
		if (isalpha(textToEncrypt[i])) {
			// Duże litery w tablicy ASCII zaczynają się od indeksu 65, a małe od 97. 
			// Patrz http://www.asciitable.com/
			int asciiIndex = isupper(textToEncrypt[i]) ? 65 : 97;
			encryptedText += char(int(textToEncrypt[i] + shift - asciiIndex) % 26 + asciiIndex);
		}
		// Znak nie jest literą, więc go przepisujemy.
		else {
			encryptedText += textToEncrypt[i];
		}
	}
	return encryptedText;
}

string decrypt(string textToDecrypt, int shift) {
	return encrypt(textToDecrypt, shift);
}
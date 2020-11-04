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
	string textToEncrypt = "Tekst do zaszyfrowania.";
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
	// Spróbujmy więć złamać kilka zaszyfrowanych informacji.
	// Poniżej zaszyfrowane są cytaty z życia Juliusza Cezara, użyj funkcji deszyfrującej,
	// aby je odszyfrować i dowiedzieć się co oznaczają!
	string encryptedQuote1 = "J uz, Csvuvtjf, qsafdjx nojf?";
	string encryptedQuote2 = "Cemlolyrz, mbonpmlyrz, mjlpvrmlyrz.";
	string encryptedQuote3 = "Eimwc timnufs ltowihy";

	printf("%24s\"%s\"\n", "Cytat 1: ", encryptedQuote1.c_str());
	printf("%24s\"%s\"\n", "Cytat 2: ", encryptedQuote2.c_str());
	printf("%24s\"%s\"\n", "Cytat 3: ", encryptedQuote3.c_str());
}

string encrypt(string textToEncrypt, int shift) {
	string encryptedText;
	for (int i = 0; i < textToEncrypt.length(); i++) {
		// Sprawdzamy czy znak jest literą.
		if (isalpha(textToEncrypt[i])) {
			// Szyfruje duże litery.
			if (isupper(textToEncrypt[i])) {
				// Duże litery w tablicy ASCII zaczynają się od indeksu 65. Patrz http://www.asciitable.com/
				// Alfabet łaciński posiada 26 znaków.
				encryptedText += char(int(textToEncrypt[i] + shift - 65) % 26 + 65);
			}
			// Szyfruje małe litery.
			else {
				if (isalpha(textToEncrypt[i])) {
					// Małe litery w tablicy ASCII zaczynają się od indeksu 97.
					encryptedText += char(int(textToEncrypt[i] + shift - 97) % 26 + 97);
				}
			}
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
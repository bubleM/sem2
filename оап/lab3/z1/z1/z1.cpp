#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX_LINES = 100; 
const int MAX_LENGTH = 256; 

void checkWord(string lines[], string firstWord, int lineCount, ofstream& file2) {
    int wordLength = firstWord.length();

    for (int i = 0; i < lineCount; ++i) {
        string line = lines[i];
        int lineLength = line.length();
        bool found = false;

        for (int j = 0; j <= lineLength - wordLength; ++j) {
            bool match = true;
            for (int k = 0; k < wordLength; k++) {
                if (line[j + k] != firstWord[k]) {
                    match = false;
                    break;
                }
            }
            if (match && (j == 0 || line[j - 1] == ' ') && (j + wordLength == lineLength || line[j + wordLength] == ' ')) {
                found = true;
                break;
            }
        }
        if (!found && i != 0) {
            file2 << line << endl;
        }
    }
}

int countConsonants(const string& line) {
    int count = 0;
    for (char s : line) {
        if (isalpha(s) && !(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' ||
            s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')) {
            count++;
        }
    }
    return count;
}


int main() {
    setlocale(LC_ALL, "rus");
    ifstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");

    if (!file1.is_open()) {
        cout << "Файл FILE1.txt не может быть открыт!\n";
        return 1;
    }

    if (!file2.is_open()) {
        cout << "Файл FILE2.txt не может быть открыт!\n";
        return 1;
    }

    string firstWord;
    file1 >> firstWord; 
    file1.ignore();
    cout << firstWord << " - 1-е слово 1-ой стр." << endl;

    string lines[MAX_LINES];
    int lineCount = 0;

    while (getline(file1, lines[lineCount]) && lineCount < MAX_LINES) {
        lineCount++;
    }

    checkWord(lines, firstWord, lineCount, file2);

    file1.close();
    file2.close();

    ifstream file2Read("FILE2.txt");
    if (!file2Read.is_open()) {
        cout << "Файл FILE2.txt не может быть открыт!\n";
        return 1;
    }

    string firstLine;
    if (getline(file2Read, firstLine)) {
        int consonantCount = countConsonants(firstLine);
        cout << "Число согласных букв в первой строке 2-го файла: " << consonantCount << endl;
    }
    file2Read.close();
    return 0;
}

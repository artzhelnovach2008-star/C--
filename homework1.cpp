#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin("input.txt");     // відкриваємо файл для читання
    ofstream fout("output1.txt");  // відкриваємо новий файл для запису

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    string word;
    while (fin >> word) { // читаємо слова по черзі
        if (word.length() >= 7) { // перевіряємо довжину слова
            fout << word << " ";  // записуємо у новий файл
        }
    }

    fin.close();
    fout.close();
    cout << "Завдання 1 виконано!" << endl;
    return 0;
}









#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output2.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) { // читаємо рядок за рядком
        fout << line << endl;    // записуємо рядок у новий файл без змін
    }

    fin.close();
    fout.close();
    cout << "Завдання 2 виконано!" << endl;
    return 0;
}












#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output3.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    
    // Зберігаємо всі рядки у вектор
    while (getline(fin, line)) {
        lines.push_back(line);
    }
    fin.close();

    // Записуємо рядки у новий файл у зворотному порядку
    for (int i = lines.size() - 1; i >= 0; i--) {
        fout << lines[i] << endl;
    }

    fout.close();
    cout << "Завдання 3 виконано!" << endl;
    return 0;
}









#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output4.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(fin, line)) {
        lines.push_back(line);
    }
    fin.close();

    int lastIndex = -1; // індекс останнього рядка без пробілу

    // Шукаємо рядок без пробілів
    for (int i = 0; i < lines.size(); i++) {
        bool hasSpace = false;
        for (int j = 0; j < lines[i].length(); j++) {
            if (lines[i][j] == ' ') {
                hasSpace = true;
                break;
            }
        }
        // Якщо пробілу немає, запам'ятовуємо цей індекс
        if (!hasSpace) {
            lastIndex = i;
        }
    }

    string dashLine = "------------";

    // Записуємо рядки у новий файл і вставляємо риски після потрібного рядка
    for (int i = 0; i < lines.size(); i++) {
        fout << lines[i] << endl;
        if (i == lastIndex) {
            fout << dashLine << endl;
        }
    }

    // Якщо таких рядків взагалі не було, додаємо в самий кінець
    if (lastIndex == -1) {
        fout << dashLine << endl;
    }

    fout.close();
    cout << "Завдання 4 виконано!" << endl;
    return 0;
}
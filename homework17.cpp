#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class Contact {
private:
    char* fullName;     // ПІБ (динамічна пам'ять за вимогою)
    string phone;       // Мобільний телефон
    string info;        // Додаткова інформація

public:
    // Конструктор за замовчуванням з ініціалізатором
    Contact() : phone(""), info("") {
        fullName = new char[1];
        fullName[0] = '\0';
    }

    // Деструктор
    ~Contact() {
        delete[] fullName;
    }

    // Inline-функція для отримання ПІБ
    inline const char* getFullName() const {
        return fullName;
    }

    // Введення контакту з клавіатури
    void input() {
        cin.ignore();
        string nameTemp;
        cout << "Введіть ПІБ: ";
        getline(cin, nameTemp);

        delete[] fullName;
        fullName = new char[nameTemp.length() + 1];
        strcpy_s(fullName, nameTemp.length() + 1, nameTemp.c_str());

        cout << "Введіть телефон: ";
        getline(cin, phone);
        cout << "Введіть додаткову інформацію: ";
        getline(cin, info);
    }

    // Виведення контакту
    void print() const {
        cout << "ПІБ: " << fullName << endl;
        cout << "Телефон: " << phone << endl;
        cout << "Інфо: " << info << endl;
        cout << "--------------------------" << endl;
    }

    // Збереження у файл
    void save(ofstream& fout) const {
        fout << fullName << endl;
        fout << phone << endl;
        fout << info << endl;
    }

    // Завантаження з файлу
    void load(ifstream& fin) {
        string nameTemp;
        getline(fin, nameTemp);

        delete[] fullName;
        fullName = new char[nameTemp.length() + 1];
        strcpy_s(fullName, nameTemp.length() + 1, nameTemp.c_str());

        getline(fin, phone);
        getline(fin, info);
    }
};

class PhoneBook {
private:
    Contact* contacts; // Динамічний масив контактів
    int count;

public:
    PhoneBook() : contacts(nullptr), count(0) {}

    ~PhoneBook() {
        delete[] contacts;
    }

    // Додати контакт
    void add() {
        Contact* temp = new Contact[count + 1];
        for (int i = 0; i < count; i++) {
            temp[i] = contacts[i]; // копіюємо старі
        }
        temp[count].input(); // вводимо новий на останнє місце

        delete[] contacts;
        contacts = temp;
        count++;
        cout << "Контакт додано!\n";
    }

    // Показати всі
    void showAll() const {
        if (count == 0) {
            cout << "Книга порожня!\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "№ " << i + 1 << endl;
            contacts[i].print();
        }
    }

    // Пошук за ПІБ
    void search(const string& query) const {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (string(contacts[i].getFullName()).find(query) != string::npos) {
                contacts[i].print();
                found = true;
            }
        }
        if (!found) cout << "Нічого не знайдено.\n";
    }

    // Зберегти у файл
    void saveToFile() const {
        ofstream fout("phonebook.txt");
        fout << count << endl;
        for (int i = 0; i < count; i++) {
            contacts[i].save(fout);
        }
        fout.close();
        cout << "Збережено у файл!\n";
    }

    // Завантажити з файлу
    void loadFromFile() {
        ifstream fin("phonebook.txt");
        if (!fin.is_open()) {
            cout << "Файл не знайдено!\n";
            return;
        }
        fin >> count;
        fin.ignore();

        delete[] contacts;
        contacts = new Contact[count];
        for (int i = 0; i < count; i++) {
            contacts[i].load(fin);
        }
        fin.close();
        cout << "Завантажено з файлу!\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    PhoneBook book;
    int choice;

    do {
        cout << "\n1. Показати всіх\n2. Додати контакт\n3. Пошук за ПІБ\n4. Зберегти у файл\n5. Завантажити з файлу\n0. Вихід\nВибір: ";
        cin >> choice;

        switch (choice) {
            case 1: book.showAll(); break;
            case 2: book.add(); break;
            case 3: {
                cin.ignore();
                string q;
                cout << "Введіть ПІБ для пошуку: ";
                getline(cin, q);
                book.search(q);
                break;
            }
            case 4: book.saveToFile(); break;
            case 5: book.loadFromFile(); break;
        }
    } while (choice != 0);

    return 0;
}
```[cite: 2]
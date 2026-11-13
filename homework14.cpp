#include <iostream>

using namespace std: // исправлено на точку с запятой после подключения или ниже стандартно

// Своя реализация strcmp() (сравнение строк)
int my_strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Своя реализация strcat() (конкатенация/объединение строк)
void my_strcat(char *dest, const char *src) {
    int i = 0;
    // Доходим до конца первой строки (до символа '\0')
    while (dest[i] != '\0') {
        i++;
    }
    // Копируем символы второй строки в конец первой
    int j = 0;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0'; // Закрываем строку нулевым символом
}

int main() {
    // Тест strcmp
    char s1[] = "Apple";
    char s2[] = "Banana";
    cout << "Rezultat sravneniya 'Apple' i 'Banana': " << my_strcmp(s1, s2) << endl;

    // Тест strcat
    char destination[50] = "Hello, ";
    const char *source = "World!";
    my_strcat(destination, source);
    cout << "Rezultat ob'edineniya strok: " << destination << endl;

    return 0;
}














#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Vvedite stroku dlya proverki na palindrom: ";
    cin >> str; // Считываем слово (без пробелов для простоты)

    bool is_palindrome = true;
    int length = str.length();

    // Сравниваем символы с начала и с конца навстречу друг другу
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) {
        cout << "Etot tekst - PALINDROM!" << endl;
    } else {
        cout << "Etot tekst - NE palindrom." << endl;
    }

    return 0;
}















#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    cout << "Vvedite tekst: ";
    cin.ignore(); // Очищаем буфер после предыдущего ввода (если нужно)
    getline(cin, text); // Считываем всю строку с пробелами

    int word_count = 0;
    bool in_word = false;

    // Проходим по каждому символу строки
    for (int i = 0; i < text.length(); i++) {
        // Если символ не пробел
        if (text[i] != ' ') {
            if (!in_word) {
                in_word = true; // Началось новое слово
                word_count++;
            }
        } else {
            in_word = false; // Встретили пробел, слово закончилось
        }
    }

    cout << "Kolichestvo slov v stroke: " << word_count << endl;

    return 0;
}
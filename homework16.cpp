#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;   // чисельник
    int denominator; // знаменник

public:
    // Метод для введення значень з клавіатури
    void input() {
        cout << "Введіть чисельник: ";
        cin >> numerator;
        cout << "Введіть знаменник: ";
        cin >> denominator;
        
        // Перевірка, щоб знаменник не був нулем
        if (denominator == 0) {
            cout << "Помилка! Знаменник не може дорівнювати нулю. Встановлено 1." << endl;
            denominator = 1;
        }
    }

    // Метод для виведення дробу на екран
    void print() {
        cout << numerator << "/" << denominator << endl;
    }

    // Додавання дробів: (a/b + c/d = (a*d + c*b) / (b*d))
    Fraction add(Fraction other) {
        Fraction result;
        result.numerator = (numerator * other.denominator) + (other.numerator * denominator);
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Віднімання дробів: (a/b - c/d = (a*d - c*b) / (b*d))
    Fraction sub(Fraction other) {
        Fraction result;
        result.numerator = (numerator * other.denominator) - (other.numerator * denominator);
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Множення дробів: (a/b * c/d = (a*c) / (b*d))
    Fraction mul(Fraction other) {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Ділення дробів: (a/b / c/d = (a*d) / (b*c))
    Fraction div(Fraction other) {
        Fraction result;
        if (other.numerator == 0) {
            cout << "Помилка: ділення на нуль (чисельник другого дробу дорівнює 0)!" << endl;
            result.numerator = 0;
            result.denominator = 1;
            return result;
        }
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        return result;
    }
};

int main() {
    // Налаштування локалі для коректного відображення символів
    setlocale(LC_ALL, "Russian");

    Fraction f1, f2;

    cout << "--- Введення першого дробу ---" << endl;
    f1.input();

    cout << "\n--- Введення другого дробу ---" << endl;
    f2.input();

    cout << "\nВаші дроби:" << endl;
    cout << "Перший дріб: ";
    f1.print();
    cout << "Другий дріб: ";
    f2.print();

    cout << "\n--- Результати арифметичних операцій ---" << endl;

    Fraction resAdd = f1.add(f2);
    cout << "Додавання: ";
    resAdd.print();

    Fraction resSub = f1.sub(f2);
    cout << "Віднімання: ";
    resSub.print();

    Fraction resMul = f1.mul(f2);
    cout << "Множення: ";
    resMul.print();

    Fraction resDiv = f1.div(f2);
    cout << "Ділення: ";
    resDiv.print();

    return 0;
}
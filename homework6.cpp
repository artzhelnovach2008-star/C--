#include <iostream>

// Рекурсивная функция возведения в степень
double power(double base, int exp) {
    // Базовый случай: любое число в степени 0 равно 1
    if (exp == 0) {
        return 1;
    }
    // Если степень отрицательная
    if (exp < 0) {
        return 1.0 / power(base, -exp);
    }
    // Рекурсивный шаг
    return base * power(base, exp - 1);
}

int main() {
    double base;
    int exp;

    std::cout << "Введите число: ";
    std::cin >> base;
    std::cout << "Введите степень: ";
    std::cin >> exp;

    std::cout << base << " в степени " << exp << " = " << power(base, exp) << std::endl;

    return 0;
}







#include <iostream>

// Рекурсивная функция вывода звездочек
void printStars(int n) {
    // Базовый случай: если N <= 0, останавливаемся
    if (n <= 0) {
        return;
    }
    // Выводим одну звездочку
    std::cout << "*";
    // Рекурсивный вызов для оставшихся (n - 1) звездочек
    printStars(n - 1);
}

int main() {
    int n;
    std::cout << "Введите количество звездочек N: ";
    std::cin >> n;

    std::cout << "Результат: ";
    printStars(n);
    std::cout << std::endl;

    return 0;
}










#include <iostream>

// Рекурсивная функция суммы в диапазоне [a, b]
int sumRange(int a, int b) {
    // Если пользователь перепутал порядок (a > b), меняем их местами
    if (a > b) {
        return sumRange(b, a);
    }
    // Базовый случай: когда дошли до конца диапазона
    if (a == b) {
        return a;
    }
    // Рекурсивный шаг: текущее число + сумма остальных
    return a + sumRange(a + 1, b);
}

int main() {
    int a, b;
    std::cout << "Введите a и b: ";
    std::cin >> a >> b;

    std::cout << "Сумма чисел от " << a << " до " << b << " = " << sumRange(a, b) << std::endl;

    return 0;
}









#include <iostream>

int main() {
    const int MONTHS = 12;
    double profit[MONTHS];
    double totalProfit = 0;
    
    // Названия месяцев для удобства
    std::string monthNames[MONTHS] = {
        "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
        "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    std::cout << "Введите прибыль фирмы за каждый месяц:\n";
    for (int i = 0; i < MONTHS; ++i) {
        std::cout << monthNames[i] << ": ";
        std::cin >> profit[i];
        totalProfit += profit[i];
    }

    // Ищем максимум и минимум
    int maxMonth = 0;
    int minMonth = 0;

    for (int i = 1; i < MONTHS; ++i) {
        if (profit[i] > profit[maxMonth]) {
            maxMonth = i;
        }
        if (profit[i] < profit[minMonth]) {
            minMonth = i;
        }
    }

    double avgProfit = totalProfit / MONTHS;

    std::cout << "\n--- Результаты ---\n";
    std::cout << "Общая прибыль за год: " << totalProfit << "\n";
    std::cout << "Средняя прибыль в месяц: " << avgProfit << "\n";
    std::cout << "Месяц с максимальной прибылью: " << monthNames[maxMonth] << " (" << profit[maxMonth] << ")\n";
    std::cout << "Месяц с минимальной прибылью: " << monthNames[minMonth] << " (" << profit[minMonth] << ")\n";

    return 0;
}











#include <iostream>

int main() {
    const int SIZE = 10;
    int arr[SIZE] = { 5, 12, 3, 8, 20, 15, 7, 1, 9, 14 };

    std::cout << "Массив в обычном порядке:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\nМассив в обратном порядке:\n";
    for (int i = SIZE - 1; i >= 0; --i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}










#include <iostream>

int main() {
    const int SIDES = 5;
    double sides[SIDES];
    double perimeter = 0;

    std::cout << "Введите длину 5 сторон пятиугольника:\n";
    for (int i = 0; i < SIDES; ++i) {
        std::cout << "Сторона " << i + 1 << ": ";
        std::cin >> sides[i];
        perimeter += sides[i];
    }

    std::cout << "Периметр пятиугольника = " << perimeter << "\n";

    return 0;
}










#include <iostream>

int main() {
    const int SIZE = 9;
    int arr[SIZE] = { 0, -11, 0, 12, 54, 0, 0, -40, 11 };

    std::cout << "Массив до сжатия: { ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << (i < SIZE - 1 ? ", " : " ");
    }
    std::cout << "}\n";

    // Создаем вспомогательный массив для результата
    int result[SIZE];
    int resIndex = 0;

    // Сначала записываем все элементы, не равные нулю
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] != 0) {
            result[resIndex++] = arr[i];
        }
    }

    // Оставшиеся места заполняем -1
    while (resIndex < SIZE) {
        result[resIndex++] = -1;
    }

    std::cout << "Массив после сжатия: { ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << result[i] << (i < SIZE - 1 ? ", " : " ");
    }
    std::cout << "}\n";

    return 0;
}











#include <iostream>

int main() {
    const int SIZE1 = 5;
    const int SIZE2 = 5;
    const int TOTAL_SIZE = SIZE1 + SIZE2;

    int arr1[SIZE1] = { 10, 0, 52, -10, -44 };
    int arr2[SIZE2] = { 54, 0, -100, 12, 4 };
    int result[TOTAL_SIZE];
    int resIndex = 0;

    // 1. Копируем все элементы > 0
    for (int i = 0; i < SIZE1; ++i) {
        if (arr1[i] > 0) result[resIndex++] = arr1[i];
    }
    for (int i = 0; i < SIZE2; ++i) {
        if (arr2[i] > 0) result[resIndex++] = arr2[i];
    }

    // 2. Копируем все элементы == 0
    for (int i = 0; i < SIZE1; ++i) {
        if (arr1[i] == 0) result[resIndex++] = arr1[i];
    }
    for (int i = 0; i < SIZE2; ++i) {
        if (arr2[i] == 0) result[resIndex++] = arr2[i];
    }

    // 3. Копируем все элементы < 0
    for (int i = 0; i < SIZE1; ++i) {
        if (arr1[i] < 0) result[resIndex++] = arr1[i];
    }
    for (int i = 0; i < SIZE2; ++i) {
        if (arr2[i] < 0) result[resIndex++] = arr2[i];
    }

    // Вывод результата
    std::cout << "Результат: { ";
    for (int i = 0; i < TOTAL_SIZE; ++i) {
        std::cout << result[i] << (i < TOTAL_SIZE - 1 ? ", " : " ");
    }
    std::cout << "}\n";

    return 0;
}
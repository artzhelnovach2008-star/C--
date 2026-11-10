#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
    srand(time(0));
    
    const int ROWS = 3;
    const int COLS = 4;
    int arr[ROWS][COLS];

    int sum = 0;
    int minVal = 100; // для поиска минимума
    int maxVal = -1;  // для поиска максимума

    std::cout << "Массив:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = rand() % 50 + 1; // случайные числа от 1 до 50
            std::cout << std::setw(4) << arr[i][j];

            sum += arr[i][j];
            
            if (arr[i][j] < minVal) {
                minVal = arr[i][j];
            }
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
        std::cout << "\n";
    }

    double average = (static_cast<double>(sum)) / (ROWS * COLS);

    std::cout << "\n--- Результаты ---\n";
    std::cout << "Сумма всех элементов: " << sum << "\n";
    std::cout << "Среднее арифметическое: " << average << "\n";
    std::cout << "Минимальный элемент: " << minVal << "\n";
    std::cout << "Максимальный элемент: " << maxVal << "\n";

    return 0;
}












#include <iostream>
#include <iomanip>

int main() {
    const int ROWS = 3;
    const int COLS = 4;
    int arr[ROWS][COLS] = {
        { 3,  5,  6,  7 },
        { 12, 1,  1,  1 },
        { 0,  7,  12, 1 }
    };

    int totalSum = 0;

    // Вывод массива с суммами строк справа и столбцов снизу
    for (int i = 0; i < ROWS; ++i) {
        int rowSum = 0;
        for (int j = 0; j < COLS; ++j) {
            std::cout << std::setw(4) << arr[i][j] << " ";
            rowSum += arr[i][j];
        }
        std::cout << " | " << std::setw(4) << rowSum << "\n";
    }

    std::cout << "--------------------------------\n";

    // Вывод сумм по столбцам и общей суммы в правом углу
    for (int j = 0; j < COLS; ++j) {
        int colSum = 0;
        for (int i = 0; i < ROWS; ++i) {
            colSum += arr[i][j];
        }
        std::cout << std::setw(4) << colSum << " ";
        totalSum += colSum; // общая сумма всех элементов
    }

    std::cout << " | " << std::setw(4) << totalSum << "\n";

    return 0;
}













#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
    srand(time(0));

    const int ROWS = 5;
    const int COLS1 = 10;
    const int COLS2 = 5;

    int arr1[ROWS][COLS1];
    int arr2[ROWS][COLS2];

    // Заполнение первого массива 5x10 случайными числами от 0 до 50
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS1; ++j) {
            arr1[i][j] = rand() % 51;
        }
    }

    // Заполнение второго массива 5x5 по условию задачи
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS2; ++j) {
            // Берем пары элементов из первой строки: (0 и 1), (2 и 3), (4 и 5) и т.д.
            int index1 = j * 2;
            int index2 = j * 2 + 1;
            arr2[i][j] = arr1[i][index1] + arr1[i][index2];
        }
    }

    // Вывод первого массива (5x10)
    std::cout << "Первый массив (5x10):\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS1; ++j) {
            std::cout << std::setw(3) << arr1[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nВторой массив (5x5, суммы пар):\n";
    // Вывод второго массива (5x5)
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS2; ++j) {
            std::cout << std::setw(4) << arr2[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
#include <iostream>

using namespace std;

// 1. Функция, которая выводит в консоль каждый бит числа
void printBits(unsigned int n) {
    // Проходим по всем 32 битам числа (от старших к младшим)
    for (int i = 31; i >= 0; i--) {
        // Сдвигаем число вправо на i позиций и с помощью & 1 получаем текущий бит
        int bit = (n >> i) & 1;
        cout << bit;
        
        // Делаем пробел каждые 4 бита для удобства чтения
        if (i % 4 == 0) {
            cout << " ";
        }
    }
    cout << endl;
}

// 2. Проверка, является ли число четным или нечетным с помощью побитовых операций
bool isEven(int n) {
    // Если самый младший бит равен 0, то число четное
    if ((n & 1) == 0) {
        return true;  // четное
    } else {
        return false; // нечетное
    }
}

// 3. Функция, которая очищает (устанавливает в 0) бит по заданному индексу
unsigned int clearBit(unsigned int n, int index) {
    // Создаем маску, где в нужном индексе стоит 0, а остальные биты — 1
    unsigned int mask = ~(1 << index);
    return n & mask;
}

// 4. Функция, которая устанавливает бит по заданному индексу в 1
unsigned int setBit(unsigned int n, int index) {
    // Создаем маску, где в нужном индексе стоит 1
    unsigned int mask = 1 << index;
    return n | mask;
}

// 5. Функция, которая инвертирует бит по заданному индексу (0 становится 1, а 1 — 0)
unsigned int toggleBit(unsigned int n, int index) {
    unsigned int mask = 1 << index;
    return n ^ mask;
}

// 6. Функция, которая подсчитывает количество единичных и нулевых битов у числа
void countBits(unsigned int n) {
    int ones = 0;
    int zeros = 0;
    
    for (int i = 0; i < 32; i++) {
        if ((n >> i) & 1) {
            ones++;
        } else {
            zeros++;
        }
    }
    
    cout << "Количество единиц (1): " << ones << endl;
    cout << "Количество нулей (0): " << zeros << endl;
}

// 7. Проверка, является ли число степенью двойки
bool isPowerOfTwo(unsigned int n) {
    if (n == 0) {
        return false;
    }
    // У степеней двойки ровно один бит равен 1 (например: 2, 4, 8, 16...).
    // Трюк: выражение n & (n - 1) стирает этот единственный бит.
    if ((n & (n - 1)) == 0) {
        return true;
    } else {
        return false;
    }
}

// 8. Получить индекс младшего установленного (1) бита числа
int lowestSetBitIndex(unsigned int n) {
    if (n == 0) {
        return -1; // Если число 0, то установленных битов нет
    }
    
    int index = 0;
    // Сдвигаем число вправо, пока младший бит не станет равен 1
    while ((n & 1) == 0) {
        n = n >> 1;
        index++;
    }
    return index;
}

// 9. Функция, которая обнуляет самый младший установленный бит у числа
unsigned int clearLowestSetBit(unsigned int n) {
    return n & (n - 1);
}

int main() {
    // Проверим работу функций на примере числа 5 (в двоичной системе это 101)
    unsigned int number = 5;
    
    cout << "=== Задание 1: Вывод битов числа 5 ===" << endl;
    cout << "Биты: ";
    printBits(number);
    
    cout << "\n=== Задание 2: Проверка на четность ===" << endl;
    if (isEven(number)) {
        cout << number << " - четное число" << endl;
    } else {
        cout << number << " - нечетное число" << endl;
    }
    
    cout << "\n=== Задание 3: Очистить бит с индексом 0 ===" << endl;
    cout << "Было: " << number << ", Стало: " << clearBit(number, 0) << endl;
    
    cout << "\n=== Задание 4: Установить бит с индексом 1 в 1 ===" << endl;
    cout << "Было: " << number << ", Стало: " << setBit(number, 1) << endl;
    
    cout << "\n=== Задание 5: Инвертировать бит с индексом 2 ===" << endl;
    cout << "Было: " << number << ", Стало: " << toggleBit(number, 2) << endl;
    
    cout << "\n=== Задание 6: Подсчет нулей и единиц для числа 5 ===" << endl;
    countBits(number);
    
    cout << "\n=== Задание 7: Проверка, является ли 8 степенью двойки ===" << endl;
    if (isPowerOfTwo(8)) {
        cout << "Число 8 является степенью двойки" << endl;
    } else {
        cout << "Число 8 не является степенью двойки" << endl;
    }
    
    cout << "\n=== Задание 8: Индекс младшего установленного бита для 12 (1100 в двоичной) ===" << endl;
    cout << "Индекс: " << lowestSetBitIndex(12) << endl;
    
    cout << "\n=== Задание 9: Обнулить младший установленный бит для 12 ===" << endl;
    cout << "Результат: " << clearLowestSetBit(12) << endl;

    return 0;
}
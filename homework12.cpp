#include <iostream>

using namespace std;

int main() {
    const int SIZE = 5;
    int source[SIZE] = {10, 20, 30, 40, 50};
    int destination[SIZE]; // массив, куда будем копировать

    // Указатели на начало исходного и целевого массивов
    int *p_src = source;
    int *p_dest = destination;

    // Указатель для остановки цикла (конец исходного массива)
    int *p_end = source + SIZE;

    // Копируем элементы с помощью арифметики указателей и разыменования
    while (p_src < p_end) {
        *p_dest = *p_src; // копируем значение по адресу
        p_src++;          // сдвигаем указатель источника на следующий элемент
        p_dest++;         // сдвигаем указатель приемника
    }

    // Выводим скопированный массив, чтобы проверить результат
    cout << "Skopirovanniy massiv: ";
    p_dest = destination; // возвращаем указатель на начало
    for (int i = 0; i < SIZE; i++) {
        cout << *(p_dest + i) << " ";
    }
    cout << endl;

    return 0;
}














#include <iostream>

using namespace std;

int main() {
    const int SIZE = 6;
    int arr[SIZE] = {1, 2, 3, 4, 5, 6};

    cout << "Ishodny massiv: ";
    for (int i = 0; i < SIZE; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    // Указатель на начало массива
    int *p_start = arr;
    // Указатель на конец массива (на последний элемент)
    int *p_end = arr + SIZE - 1;

    // Меняем местами элементы с помощью временной переменной и указателей
    while (p_start < p_end) {
        int temp = *p_start;
        *p_start = *p_end;
        *p_end = temp;

        p_start++; // сдвигаем левый указатель вправо
        p_end--;   // сдвигаем правый указатель влево
    }

    // Выводим перевернутый массив
    cout << "Obratniy massiv: ";
    for (int i = 0; i < SIZE; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    return 0;
}
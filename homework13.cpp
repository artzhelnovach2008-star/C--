#include <iostream>

using namespace std;

// Функция вывода массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 6;
    int arr1[SIZE] = {64, 25, 12, 22, 11, 90};
    int arr2[SIZE] = {12, 11, 13, 5, 6, 22};

    cout << "=== 1. SORTIROVKA VYBOROM (Selection Sort) ===" << endl;
    cout << "Ishodny massiv: ";
    printArray(arr1, SIZE);

    // Алгоритм сортировки выбором
    for (int i = 0; i < SIZE - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr1[j] < arr1[min_idx]) {
                min_idx = j;
            }
        }
        // Меняем местами минимальный элемент с текущим
        int temp = arr1[min_idx];
        arr1[min_idx] = arr1[i];
        arr1[i] = temp;
    }

    cout << "Otsortirovanniy massiv: ";
    printArray(arr1, SIZE);


    cout << "\n=== 2. SORTIROVKA VSTAVKAMI (Insertion Sort) ===" << endl;
    cout << "Ishodny massiv: ";
    printArray(arr2, SIZE);

    // Алгоритм сортировки вставками
    for (int i = 1; i < SIZE; i++) {
        int key = arr2[i];
        int j = i - 1;
        while (j >= 0 && arr2[j] > key) {
            arr2[j + 1] = arr2[j];
            j = j - 1;
        }
        arr2[j + 1] = key;
    }

    cout << "Otsortirovanniy massiv: ";
    printArray(arr2, SIZE);

    return 0;
}
















#include <iostream>

using namespace std;

int main() {
    const int SIZE = 10;
    double grades[SIZE];
    bool is_entered = false;
    int choice;

    do {
        cout << "\n=== MENYU 'USPESHNYST' ===" << endl;
        cout << "1. Vvod 10 ocenok studenta" << endl;
        cout << "2. Vyvod ocenok (soderzhimoe massiva)" << endl;
        cout << "3. Peresdacha ispity (izmenit ocenku po nomeru)" << endl;
        cout << "4. Proverit, vyhodit li stipendiya (sredniy ball >= 10.7)" << endl;
        cout << "5. Vyhod" << endl;
        cout << "Vyberite punkt (1-5): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Vvedite 10 ocenok:" << endl;
            for (int i = 0; i < SIZE; i++) {
                cout << "Ocenka " << i + 1 << ": ";
                cin >> grades[i];
            }
            is_entered = true;
            cout << "Ocenki uspeshno vvedeny!" << endl;
        } 
        else if (choice == 2) {
            if (!is_entered) {
                cout << "Snachala vvedite ocenki (punkt 1)!" << endl;
                continue;
            }
            cout << "Tekushchie ocenki: ";
            for (int i = 0; i < SIZE; i++) {
                cout << grades[i] << " ";
            }
            cout << endl;
        } 
        else if (choice == 3) {
            if (!is_entered) {
                cout << "Snachala vvedite ocenki (punkt 1)!" << endl;
                continue;
            }
            int index;
            double new_grade;
            cout << "Vvedite nomer elementa dlya peresdachi (ot 1 do 10): ";
            cin >> index;
            if (index < 1 || index > 10) {
                cout << "Oshibka: neverniy nomer!" << endl;
                continue;
            }
            cout << "Vvedite novuyu ocenku: ";
            cin >> new_grade;
            grades[index - 1] = new_grade;
            cout << "Ocenka obnovlena!" << endl;
        } 
        else if (choice == 4) {
            if (!is_entered) {
                cout << "Snachala vvedite ocenki (punkt 1)!" << endl;
                continue;
            }
            double sum = 0;
            for (int i = 0; i < SIZE; i++) {
                sum += grades[i];
            }
            double avg = sum / SIZE;
            cout << "Sredniy ball: " << avg << endl;
            if (avg >= 10.7) {
                cout << "Ura! Stipendiya vyhodit!" << endl;
            } else {
                cout << "K sozhaleniyu, sredniy ball nizhe 10.7, stipendii net." << endl;
            }
        }
    } while (choice != 5);

    return 0;
}















#include <iostream>

using namespace std;

// Функция разделения массива для Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // опорный элемент — последний
    int i = (low - 1);     // индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Рекурсивная функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int SIZE = 8;
    int arr[SIZE] = {10, 7, 8, 9, 1, 5, 3, 6};

    cout << "Ishodny massiv: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, SIZE - 1);

    cout << "Otsortirovanniy massiv (Quick Sort): ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}















#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Возьмем размер массива, кратный 3, для удобства (например, 9)
    const int SIZE = 9;
    int arr[SIZE] = {-2, 5, 1, 8, -3, 4, 9, -1, 2};

    cout << "Ishodny massiv: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 1. Считаем среднее арифметическое всех элементов
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    double avg = sum / SIZE;
    cout << "Srednee arifmeticheskoe: " << avg << endl;

    int third = SIZE / 3; // одна треть размера (например, 3)

    if (avg > 0) {
        // Если больше нуля: сортируем первые две трети (от 0 до 2 * third) по возрастанию
        cout << "Srednee > 0. Sortiruem pervyye 2 treti (6 elementov)." << endl;
        sort(arr, arr + (2 * third));
    } else {
        // В ином случае: сортируем только первую треть (от 0 до third) по возрастанию
        cout << "Srednee <= 0. Sortiruem tolko pervuyu tret (3 elementa)." << endl;
        sort(arr, arr + third);
    }

    // 2. Оставшуюся часть массива располагаем в обратном порядке (реверс)
    // Если сортировали 2 трети, то остаток с 2*third до SIZE. Если 1 треть, то с third до SIZE.
    int start_reverse = (avg > 0) ? (2 * third) : third;
    
    // Ручной реверс оставшейся части
    int left = start_reverse;
    int right = SIZE - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }

    // Выводим результат
    cout << "Rezul'tat: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
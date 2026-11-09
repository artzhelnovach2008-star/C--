#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для заполнения массива случайными числами
void fillRandomArray(vector<int>& arr, int size, int minVal, int maxVal) {
    arr.resize(size);
    for (int i = 0; i < size; i++) {
        // Случайное число в диапазоне от minVal до maxVal
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел
    int n = 10;
    vector<int> myArray;

    fillRandomArray(myArray, n, 1, 100);

    cout << "Zavdannya 1. Zypovnenyy masyv:\n";
    for (int i = 0; i < myArray.size(); i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;
}






#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cout << "Vvedit rozmir pershoho masyvu (M): ";
    cin >> m;
    cout << "Vvedit rozmir druhoho masyvu (N): ";
    cin >> n;

    vector<int> A(m);
    vector<int> B(n);

    cout << "Vvedit elementy masyvu A:\n";
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    cout << "Vvedit elementy masyvu B:\n";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // Создаем третий массив минимально возможного размера (просто объединяем оба)
    vector<int> C;
    C.reserve(m + n); // резервируем память для оптимизации

    for (int i = 0; i < m; i++) {
        C.push_back(A[i]);
    }
    for (int i = 0; i < n; i++) {
        C.push_back(B[i]);
    }

    cout << "\nZavdannya 2. Tretiy masyv (ob'yednannya):\n";
    for (int i = 0; i < C.size(); i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}










#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cout << "Vvedit rozmir pershoho masyvu (M): ";
    cin >> m;
    cout << "Vvedit rozmir druhoho masyvu (N): ";
    cin >> n;

    vector<int> A(m);
    vector<int> B(n);

    cout << "Vvedit elementy masyvu A:\n";
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    cout << "Vvedit elementy masyvu B:\n";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    vector<int> C;

    // Ищем общие элементы без повторений
    for (int i = 0; i < m; i++) {
        int val = A[i];
        
        // Проверяем, есть ли такой элемент в B
        bool foundInB = false;
        for (int j = 0; j < n; j++) {
            if (B[j] == val) {
                foundInB = true;
                break;
            }
        }

        // Проверяем, не добавляли ли мы его уже в третий массив C (чтобы не было повторов)
        bool alreadyInC = false;
        for (int k = 0; k < C.size(); k++) {
            if (C[k] == val) {
                alreadyInC = true;
                break;
            }
        }

        // Если элемент есть в B и его еще нет в C, добавляем
        if (foundInB && !alreadyInC) {
            C.push_back(val);
        }
    }

    cout << "\nZavdannya 3. Spilni elementy bez povtorenʹ:\n";
    if (C.empty()) {
        cout << "Spilnykh elementiv nemaye." << endl;
    } else {
        for (int i = 0; i < C.size(); i++) {
            cout << C[i] << " ";
        }
        cout << endl;
    }

    return 0;
}










#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m;
    cout << "Vvedit rozmir masyvu (M): ";
    cin >> m;

    vector<int> A(m);
    cout << "Vvedit elementy masyvu:\n";
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    int choice;
    cout << "\nMenu vyboru:\n";
    cout << "1. Vydalyty parni znachennya\n";
    cout << "2. Vydalyty neparni znachennya\n";
    cout << "Vash vybir (1 abo 2): ";
    cin >> choice;

    // Удаляем элементы из вектора с помощью цикла и итераторов/индексов
    for (int i = 0; i < A.size(); ) {
        if (choice == 1 && A[i] % 2 == 0) {
            A.erase(A.begin() + i); // удаляем парное
        } 
        else if (choice == 2 && A[i] % 2 != 0) {
            A.erase(A.begin() + i); // удаляем непарное
        } 
        else {
            i++; // если удалять не нужно, переходим к следующему
        }
    }

    cout << "\nZavdannya 4. Rezultat:\n";
    if (A.empty()) {
        cout << "Masyv pustyy." << endl;
    } else {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    return 0;
}














#include <iostream>

using namespace std;

// 1. Функція виділення динамічної пам'яті
int* allocateMemory(int size) {
    return new int[size];
}

// 2. Функція ініціалізації динамічного масиву (заповнення нулями або значеннями)
void initArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

// 3. Функція виводу динамічного масиву
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 4. Функція видалення динамічної пам'яті
void deleteArray(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

// 5. Функція додавання елемента в кінець масиву
void addElementEnd(int*& arr, int& size, int newValue) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = newValue; // записуємо новий елемент в кінець
    delete[] arr;            // видаляємо стару пам'ять
    arr = newArr;            // перенаправляємо вказівник
    size++;
}

// 6. Функція вставки елемента за вказаним індексом
void insertElement(int*& arr, int& size, int index, int newValue) {
    if (index < 0 || index > size) return;
    
    int* newArr = new int[size + 1];
    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i == index) {
            newArr[i] = newValue;
        } else {
            newArr[i] = arr[j++];
        }
    }
    delete[] arr;
    arr = newArr;
    size++;
}

// 7. Функція видалення елемента за вказаним індексом
void removeElement(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) return;
    
    if (size == 1) {
        delete[] arr;
        arr = nullptr;
        size = 0;
        return;
    }

    int* newArr = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i == index) continue; // пропуск елемента, що видаляється
        newArr[j++] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}

int main() {
    int size = 3;
    int* arr = allocateMemory(size);
    
    // Заповнимо початковими значеннями
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    
    cout << "Pochatkovyy masyv: ";
    printArray(arr, size);

    addElementEnd(arr, size, 40);
    cout << "Pislya dodavannya v kinec (40): ";
    printArray(arr, size);

    insertElement(arr, size, 1, 99);
    cout << "Pislya vstavky 99 za indeksom 1: ";
    printArray(arr, size);

    removeElement(arr, size, 2);
    cout << "Pislya vydalennya elementa za indeksom 2: ";
    printArray(arr, size);

    deleteArray(arr);
    return 0;
}









#include <iostream>

using namespace std;

// Допоміжна функція перевірки, чи є число простим
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Функція видалення простих чисел
int* removePrimes(int* arr, int size, int& newSize) {
    newSize = 0;
    // 1. Рахуємо, скільки залишиться елементів (не простих)
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newSize++;
        }
    }

    if (newSize == 0) return nullptr;

    // 2. Виділяємо пам'ять під новий масив
    int* newArr = new int[newSize];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[j++] = arr[i];
        }
    }

    return newArr;
}

int main() {
    int size = 5;
    int* arr = new int[size] {2, 3, 4, 5, 6}; // тут прості: 2, 3, 5

    cout << "Zavdannya 2. Pochatkovyy masyv: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    int newSize = 0;
    int* newArr = removePrimes(arr, size, newSize);

    cout << "Masyv bez prostykh chysel: ";
    for (int i = 0; i < newSize; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] newArr;
    return 0;
}










#include <iostream>

using namespace std;

void distributeArray(int* staticArr, int size, 
                     int*& posArr, int& posSize, 
                     int*& negArr, int& negSize, 
                     int*& zeroArr, int& zeroSize) {
    posSize = 0;
    negSize = 0;
    zeroSize = 0;

    // 1. Рахуємо розміри для кожного майбутнього масиву
    for (int i = 0; i < size; i++) {
        if (staticArr[i] > 0) posSize++;
        else if (staticArr[i] < 0) negSize++;
        else zeroSize++;
    }

    // 2. Виділяємо пам'ять
    posArr = (posSize > 0) ? new int[posSize] : nullptr;
    negArr = (negSize > 0) ? new int[negSize] : nullptr;
    zeroArr = (zeroSize > 0) ? new int[zeroSize] : nullptr;

    // 3. Заповнюємо масиви
    int pIdx = 0, nIdx = 0, zIdx = 0;
    for (int i = 0; i < size; i++) {
        if (staticArr[i] > 0) {
            posArr[pIdx++] = staticArr[i];
        } else if (staticArr[i] < 0) {
            negArr[nIdx++] = staticArr[i];
        } else {
            zeroArr[zIdx++] = staticArr[i];
        }
    }
}

int main() {
    const int size = 6;
    int staticArr[size] = {-5, 0, 3, 10, -2, 0};

    int *posArr = nullptr, *negArr = nullptr, *zeroArr = nullptr;
    int posSize = 0, negSize = 0, zeroSize = 0;

    distributeArray(staticArr, size, posArr, posSize, negArr, negSize, zeroArr, zeroSize);

    cout << "Zavdannya 3 Rezultaty:\n";
    
    cout << "Dodatni: ";
    for (int i = 0; i < posSize; i++) cout << posArr[i] << " ";
    cout << endl;

    cout << "Vid'emni: ";
    for (int i = 0; i < negSize; i++) cout << negArr[i] << " ";
    cout << endl;

    cout << "Nulovi: ";
    for (int i = 0; i < zeroSize; i++) cout << zeroArr[i] << " ";
    cout << endl;

    // Очищення пам'яті динамічних масивів
    delete[] posArr;
    delete[] negArr;
    delete[] zeroArr;

    return 0;
}






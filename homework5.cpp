#include <iostream>

using namespace std;

void printRectangle(int height, int width, char symbol) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << symbol;
        }
        cout << endl;
    }
}

int main() {
    cout << "--- Zavdannya 1 ---" << endl;
    printRectangle(3, 5, '*');
    return 0;
}











#include <iostream>

using namespace std;

long long getFactorial(int n) {
    if (n < 0) return -1; // факторіал від'ємних не існує
    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    cout << "--- Zavdannya 2 ---" << endl;
    int num = 5;
    cout << "Faktorial chysla " << num << " = " << getFactorial(num) << endl;
    return 0;
}








#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cout << "--- Zavdannya 3 ---" << endl;
    int num = 7;
    cout << "Chyslo " << num << " proste? " << (isPrime(num) ? "Tak" : "Ni") << endl;
    return 0;

}













#include <iostream>

using namespace std;

double getCube(double n) {
    return n * n * n;
}

int main() {
    cout << "--- Zavdannya 4 ---" << endl;
    double num = 3.0;
    cout << "Kub chysla " << num << " = " << getCube(num) << endl;
    return 0;
}








#include <iostream>

using namespace std;

int getMax(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    cout << "--- Zavdannya 5 ---" << endl;
    cout << "Naybilshe z 10 i 20 = " << getMax(10, 20) << endl;
    return 0;
}









#include <iostream>

using namespace std;

bool isPositive(double n) {
    return n > 0;
}

int main() {
    cout << "--- Zavdannya 6 ---" << endl;
    double val = 5.5;
    cout << "Chyslo " << val << " dodatne? " << (isPositive(val) ? "true" : "false") << endl;
    return 0;
}








#include <iostream>
#include <vector>

using namespace std;

void printMinMax(const vector<int>& arr) {
    if (arr.empty()) return;

    int minVal = arr[0], maxVal = arr[0];
    int minIndex = 0, maxIndex = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    cout << "Minimum: " << minVal << " (indeks: " << minIndex << ")" << endl;
    cout << "Maksimum: " << maxVal << " (indeks: " << maxIndex << ")" << endl;
}

int main() {
    cout << "--- Zavdannya 7 ---" << endl;
    vector<int> arr = {4, 2, 9, 1, 7};
    printMinMax(arr);
    return 0;
}














#include <iostream>
#include <vector>

using namespace std;

void reverseArray(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main() {
    cout << "--- Zavdannya 8 ---" << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    
    reverseArray(arr);
    
    cout << "Masyv navpaky: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}






















#include <iostream>
#include <vector>

// Допоміжна функція перевірки на простоту з завдання 3
bool isPrimeNum(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

using namespace std;

int countPrimes(const vector<int>& arr) {
    int count = 0;
    for (int num : arr) {
        if (isPrimeNum(num)) {
            count++;
        }
    }
    return count;
}

int main() {
    cout << "--- Zavdannya 9 ---" << endl;
    vector<int> arr = {2, 3, 4, 5, 6, 11}; // прості: 2, 3, 5, 11 (їх 4)
    cout << "Kilkist prostykh chysel u masyvi = " << countPrimes(arr) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

// Функция добавления строки в конец
void addRowEnd(vector<vector<int>>& matrix, const vector<int>& newRow) {
    matrix.push_back(newRow);
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    vector<int> newRow = {7, 8, 9};
    addRowEnd(matrix, newRow);

    cout << "Zavdannya 1. Rezultat:\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}







#include <iostream>
#include <vector>

using namespace std;

// Функция добавления строки в начало
void addRowBeginning(vector<vector<int>>& matrix, const vector<int>& newRow) {
    matrix.insert(matrix.begin(), newRow);
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    vector<int> newRow = {7, 8, 9};
    addRowBeginning(matrix, newRow);

    cout << "Zavdannya 2. Rezultat:\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}






#include <iostream>
#include <vector>

using namespace std;

// Функция добавления строки в указанную позицию (индекс)
void addRowAt(vector<vector<int>>& matrix, const vector<int>& newRow, int index) {
    if (index >= 0 && index <= matrix.size()) {
        matrix.insert(matrix.begin() + index, newRow);
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {3, 3, 3}
    };
    
    vector<int> newRow = {2, 2, 2};
    addRowAt(matrix, newRow, 1); // вставляем посередине

    cout << "Zavdannya 3. Rezultat:\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}










#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int rows = 4, cols = 3;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // Заполняем случайными числами (включая нули для примера)
    cout << "Pochatkova matrytsya:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 5; // числа от 0 до 4
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Удаляем строки, содержащие хотя бы один нуль
    for (int i = 0; i < matrix.size(); ) {
        bool hasZero = false;
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        
        if (hasZero) {
            matrix.erase(matrix.begin() + i); // удаляем строку и не увеличиваем i
        } else {
            i++; // переходим к следующей строке
        }
    }

    cout << "\nMatrytsya pislya vydalennya ryadkiv z nuliamy:\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}










#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int rows, cols;
    cout << "Vvedit kilkist ryadkiv: ";
    cin >> rows;
    cout << "Vvedit kilkist stovpchykiv: ";
    cin >> cols;

    vector<vector<int>> A(rows, vector<int>(cols));
    vector<vector<int>> B(rows, vector<int>(cols));
    vector<vector<int>> C(rows, vector<int>(cols));

    cout << "\nMatrytsya A:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = rand() % 10;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatrytsya B:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B[i][j] = rand() % 10;
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    // Поэлементное суммирование
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nRezultuyucha matrytsya C (A + B):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}











#include <iostream>
#include <vector>

using namespace std;

// Функция умножения матриц
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();
    int n = A[0].size();
    int k = B[0].size();
    
    vector<vector<int>> C(m, vector<int>(k, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            for (int p = 0; p < n; p++) {
                C[i][j] += A[i][p] * B[p][j];
            }
        }
    }
    return C;
}

int main() {
    // A: 2x3
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    // B: 3x2
    vector<vector<int>> B = {
        {7, 8},
        {9, 1},
        {2, 3}
    };

    vector<vector<int>> C = multiplyMatrices(A, B);

    cout << "Zavdannya 6. Rezultat mnozhennya matryts:\n";
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}












#include <iostream>
#include <vector>

using namespace std;

// Функция преобразования 1D в 2D массив
vector<vector<int>> convert1DTo2D(const vector<int>& arr, int rows, int cols) {
    if (arr.size() != rows * cols) {
        cout << "Pomyłka: rozmir odnovymirnoho masyvu ne zbigayetʹsya z kilkistyu ryadkiv i stovpchykiv!\n";
        return {};
    }

    vector<vector<int>> matrix(rows, vector<int>(cols));
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = arr[index++];
        }
    }
    return matrix;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int rows = 2, cols = 3;

    vector<vector<int>> matrix = convert1DTo2D(arr, rows, cols);

    cout << "Zavdannya 7. Rezultat:\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}













#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int count = 5;
    vector<string> surnames(count);

    cout << "Vvedit 5 prizvyshch studentiv:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << "-e prizvyshche: ";
        cin >> surnames[i];
    }

    string longest = surnames[0];

    for (int i = 1; i < count; i++) {
        if (surnames[i].length() > longest.length()) {
            longest = surnames[i];
        }
    }

    cout << "\nNaydovshe prizvyshche: " << longest << endl;
    cout << "Dosyahnuta dovzhyna: " << longest.length() << " symvoliv." << endl;

    return 0;
}
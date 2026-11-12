#include <iostream>

using namespace std;

int main() {
    int num, max_num;

    cout << "Vvedite 7 celyh chisel:" << endl;
    
    // Вводим первое число и считаем его максимальным на старте
    cin >> max_num;

    // В цикле вводим остальные 6 чисел и сравниваем с текущим максимумом
    for (int i = 2; i <= 7; i++) {
        cin >> num;
        if (num > max_num) {
            max_num = num;
        }
    }

    cout << "Maksimalnoe chislo: " << max_num << endl;

    return 0;
}













#include <iostream>

using namespace std;

int main() {
    double ab, bc, weight;
    
    cout << "Vvedite rasstoyanie mezhdu A i B (km): ";
    cin >> ab;
    cout << "Vvedite rasstoyanie mezhdu B i C (km): ";
    cin >> bc;
    cout << "Vvedite ves gruza (kg): ";
    cin >> weight;

    // Проверка веса груза
    if (weight > 2000) {
        cout << "Oshibka: s takim vesom (> 2000 kg) samolyot ne podnimaetsya!" << endl;
        return 0;
    }

    // Определяем расход топлива на 1 км в зависимости от веса
    double consumption = 0;
    if (weight <= 500) {
        consumption = 1;
    } else if (weight <= 1000) {
        consumption = 4;
    } else if (weight <= 1500) {
        consumption = 7;
    } else if (weight <= 2000) {
        consumption = 9;
    }

    // Считаем топливо для первого отрезка (A -> B)
    double fuel_ab = ab * consumption;
    if (fuel_ab > 300) {
        cout << "Poles nevozmozhen: rasstoyanie A-B trebuet bolshe topliva, chem yemkost baka (300 l)." << endl;
        return 0;
    }

    // Считаем топливо для второго отрезка (B -> C)
    double fuel_bc = bc * consumption;
    if (fuel_bc > 300) {
        cout << "Poles nevozmozhen: rasstoyanie B-C trebuet bolshe topliva, chem yemkost baka (300 l)." << endl;
        return 0;
    }

    // Сколько топлива останется после перелета A -> B
    double fuel_left = 300 - fuel_ab;

    // Сколько нужно дозаправить в пункте B, чтобы хватило до C
    double refuel = 0;
    if (fuel_left < fuel_bc) {
        refuel = fuel_bc - fuel_left;
    }

    cout << "\nNuzhno dozapravit v punkte B: " << refuel << " litrov topliva." << endl;

    return 0;
}















#include <iostream>

using namespace std;

int main() {
    double sales[3];
    double salaries[3];
    double base = 200.0;

    // Ввод продаж для трех менеджеров
    for (int i = 0; i < 3; i++) {
        cout << "Vvedite uroven prodazh dlya menedzhera " << i + 1 << " ($): ";
        cin >> sales[i];

        double percent = 0;
        if (sales[i] <= 500) {
            percent = 0.03; // 3%
        } else if (sales[i] <= 1000) {
            percent = 0.05; // 5%
        } else {
            percent = 0.08; // 8%
        }

        salaries[i] = base + (sales[i] * percent);
    }

    // Поиск лучшего менеджера (у кого больше зарплата)
    int best_index = 0;
    for (int i = 1; i < 3; i++) {
        salaries[i];
        if (salaries[i] > salaries[best_index]) {
            best_index = i;
        }
    }

    // Начисление премии лучшему менеджеру (+200$)
    salaries[best_index] += 200.0;

    // Вывод результатов
    cout << "\n--- ITOGI ---" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Menedzher " << i + 1 << " zarplata: " << salaries[i] << " $";
        if (i == best_index) {
            cout << " (LUCHSHIY! S premiey)";
        }
        cout << endl;
    }

    return 0;
}












#include <iostream>

using namespace std;

int main() {
    int choice;
    cout << "=== MENYU VASY ===" << endl;
    cout << "1. Vvod zhelannogo dohoda i kolichestva opozdaniy -> uznat skolko strok nuzhno napisat" << endl;
    cout << "2. Vvod kolichestva strok i zhelannoy zarplaty -> uznat skolko raz mozhno opozdat" << endl;
    cout << "3. Vvod strok i opozdaniy -> uznat itogovuyu zarplatu" << endl;
    cout << "Vyberite punkt (1-3): ";
    cin >> choice;

    if (choice == 1) {
        double target_salary;
        int lats;
        cout << "Vvedite zhelanniy dohod ($): ";
        cin >> target_salary;
        cout << "Vvedite kolichestvo opozdaniy: ";
        cin >> lats;

        // Штраф: каждое третье опоздание отнимает 20$
        double fine = (lats / 3) * 20.0;
        double needed_gross = target_salary + fine; // сколько грязными нужно заработать за код

        if (needed_gross < 0) needed_gross = 0;

        // За каждые 100 строк платится 50$ -> за 1 строку платится 0.5$
        double lines_needed = needed_gross / 0.5;

        cout << "Vashemu nuzhno napisat strok kodu: " << (int)lines_needed << endl;
    } 
    else if (choice == 2) {
        int lines;
        double target_salary;
        cout << "Vvedite kolichestvo napisannykh strok kodu: ";
        cin >> lines;
        cout << "Vvedite zhelanniy obsyom zarplaty ($): ";
        cin >> target_salary;

        double base_earned = (lines / 100) * 50.0;
        double allowed_deficit = base_earned - target_salary; // сколько может забрать штраф

        if (allowed_deficit <= 0) {
            cout << "Vasa dazhe bez opozdaniy ne smozhet poluchit takuyu summu pri takom kolichestve strok!" << endl;
        } else {
            // За каждые 3 опоздания снимают 20$ (значит за каждые 20$ штрафа это 3 опоздания)
            int fines_count = allowed_deficit / 20.0;
            int max_lats = fines_count * 3;
            cout << "Vasa mozhet opozdat maksimum (raz): " << max_lats << endl;
        }
    } 
    else if (choice == 3) {
        int lines, lats;
        cout << "Vvedite kolichestvo strok kodu: ";
        cin >> lines;
        cout << "Vvedite kolichestvo opozdaniy: ";
        cin >> lats;

        double base_earned = (lines / 100) * 50.0;
        double fine = (lats / 3) * 20.0;
        double total = base_earned - fine;

        if (total < 0) {
            total = 0; // Зарплата не может быть отрицательной
        }

        cout << "Vasye zaplatyat: " << total << " $" << endl;
    } 
    else {
        cout << "Neverniy vybor menyu!" << endl;
    }

    return 0;
}
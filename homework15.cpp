#include <iostream>

using namespace std;

int main() {
    long total_seconds;
    cout << "Vvedite vremya v sekundah: ";
    cin >> total_seconds;

    long hours = total_seconds / 3600;
    long remainder = total_seconds % 3600;
    long minutes = remainder / 60;
    long seconds = remainder % 60;

    cout << total_seconds << " sek. eto: " 
         << hours << " chas., " 
         << minutes << " min., " 
         << seconds << " sek." << endl;

    return 0;
}












#include <iostream>

using namespace std;

int main() {
    double amount;
    cout << "Vvedite drobnoe chislo (naprimer, 12.5): ";
    cin >> amount;

    int grivnas = (int)amount; // целая часть — гривны
    // дробная часть переводится в шаги (копейки)
    int steps = (int)((amount - grivnas) * 100 + 0.5); 

    cout << grivnas << " grn. " << steps << " shagov." << endl;

    return 0;
}








#include <iostream>

using namespace std;

int main() {
    double distance_m;
    double time_input;

    cout << "Vvedite dlinu distancii (metrov): ";
    cin >> distance_m;
    cout << "Vvedite vremya (min.sek, naprimer 3.25): ";
    cin >> time_input;

    int minutes = (int)time_input; // минуты
    int seconds = (int)((time_input - minutes) * 100 + 0.5); // секунды

    int total_seconds = minutes * 60 + seconds;
    double distance_km = distance_m / 1000.0;
    double hours = total_seconds / 3600.0;

    double speed_kmh = distance_km / hours;

    cout << "Distanciya: " << distance_m << " m." << endl;
    cout << "Vremya: " << minutes << " hv. " << seconds << " sek = " << total_seconds << " sek." << endl;
    cout << "Vy bgli zi skv1dk1styu: " << speed_kmh << " km/god." << endl;

    return 0;
}











#include <iostream>

using namespace std;

int main() {
    int days;
    cout << "Vvedite kolichestvo dney: ";
    cin >> days;

    int weeks = days / 7;
    int remaining_days = days % 7;

    cout << days << " dney eto: " << weeks << " nedeli i " << remaining_days << " dney." << endl;

    return 0;
}












#include <iostream>

using namespace std;

int main() {
    double distance, hours;
    cout << "Vvedite rasstoyanie do aeroportu (km): ";
    cin >> distance;
    cout << "Vvedite vremya v chasah, za kotoroe nuzhno doehat: ";
    cin >> hours;

    if (hours <= 0) {
        cout << "Oshibka: vremya dolzhno byt bolshe nulia!" << endl;
        return 0;
    }

    double speed = distance / hours;
    cout << "Nuzhno ehat so skorostyu: " << speed << " km/ch." << endl;

    return 0;
}












#include <iostream>

using namespace std;

int main() {
    double distance, consumption_per_100;
    double price1, price2, price3;

    cout << "Vvedite rasstoyanie (km): ";
    cin >> distance;
    cout << "Vvedite rashod benzina na 100 km (litrov): ";
    cin >> consumption_per_100;
    cout << "Vvedite stoimost 1 litra 1-go vida benzina: ";
    cin >> price1;
    cout << "Vvedite stoimost 1 litra 2-go vida benzina: ";
    cin >> price2;
    cout << "Vvedite stoimost 1 litra 3-go vida benzina: ";
    cin >> price3;

    double total_fuel = (distance / 100.0) * consumption_per_100;

    double cost1 = total_fuel * price1;
    double cost2 = total_fuel * price2;
    double cost3 = total_fuel * price3;

    cout << "\n--- SRAVNITELNAYA TABLICA STOIMOSTI ---" << endl;
    cout << "Obshiy obsyom topliva: " << total_fuel << " litrov" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Benzin 1: " << cost1 << " uah" << endl;
    cout << "Benzin 2: " << cost2 << " uah" << endl;
    cout << "Benzin 3: " << cost3 << " uah" << endl;

    return 0;
}













#include <iostream>

using namespace std;

int main() {
    long seconds_from_start;
    cout << "Vvedite sekund, proshedshih ot nachala dnya: ";
    cin >> seconds_from_start;

    const long total_day_seconds = 86400; // 24 часа * 3600 секунд

    if (seconds_from_start < 0 || seconds_from_start > total_day_seconds) {
        cout << "Oshibka: nekorrektnoe kolichestvo sekund!" << endl;
        return 0;
    }

    // Текущее время
    long hours = seconds_from_start / 3600;
    long rem = seconds_from_start % 3600;
    long minutes = rem / 60;
    long seconds = rem % 60;

    cout << "Tekushchee vremya: " << hours << " chas. " << minutes << " min. " << seconds << " sek." << endl;

    // Время до полуночи
    long seconds_left = total_day_seconds - seconds_from_start;
    long left_hours = seconds_left / 3600;
    long left_rem = seconds_left % 3600;
    long left_minutes = left_rem / 60;
    long left_seconds = left_rem % 60;

    cout << "Do polnichi ostalos: " << left_hours << " chas. " << left_minutes << " min. " << left_seconds << " sek." << endl;

    return 0;
}











#include <iostream>

using namespace std;

int main() {
    long seconds_from_work_start;
    cout << "Vvedite sekund, proshedshih ot nachala rabochego dnya: ";
    cin >> seconds_from_work_start;

    const long work_day_seconds = 8 * 3600; // 8 часов в секундах

    if (seconds_from_work_start >= work_day_seconds) {
        cout << "Rabochiy den uzhe zakonchilsya!" << endl;
    } else if (seconds_from_work_start < 0) {
        cout << "Oshibka: otritsatelnoe znachenie!" << endl;
    } else {
        long seconds_left = work_day_seconds - seconds_from_work_start;
        long full_hours_left = seconds_left / 3600;

        cout << "Do konca rabochego dnya ostalos celih chasov: " << full_hours_left << endl;
    }

    return 0;
}




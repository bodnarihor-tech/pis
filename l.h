#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y;

    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть y: ";
    cin >> y;

    double numerator = sqrt(pow(2 + y, 2) + sqrt(sin(y + 5)));

    double denominator = log(x + 1) - pow(y, 3);

    if (fabs(denominator) < 1e-12) {
        cout << "Помилка: знаменник дорівнює нулю!" << endl;
        return 1;
    }

    double F = numerator / denominator;

    cout << "Вхідні дані: x = " << x << ", y = " << y << endl;
    cout << "Результат F = " << F << endl;

    return 0;
}
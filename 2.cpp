#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x * x - 2; 
}
double Chord(double x0, double x1, double h, int maxIt) {
    double x_n = x0;
    double x_n1 = x1;
    for (int n = 0; n < maxIt; ++n) {
        double x_next = x_n1 - f(x_n1) * (x_n1 - x_n) / (f(x_n1) - f(x_n));
        cout << "Итерация " << n + 1 << ": x = " << x_next << endl;
        if (fabs(x_next - x_n1) < h) {
            return x_next;
        }
        x_n = x_n1;
        x_n1 = x_next;
    }
    cout << "Макс итерация." << endl;
    return x_n1;
}
int main() {
    setlocale(LC_ALL, "Russian");
    double x0; 
    double x1; 
    double h; 
    int maxIt; 
    cout << "Введите 1 начальное приближение (x0): ";
    cin >> x0;
    cout << "Введите 2 начальное приближение (x1): ";
    cin >> x1;
    cout << "Введите (h): ";
    cin >> h;
    cout << "Максимальная итерация: ";
    cin >> maxIt;
    double root = Chord(x0, x1, h, maxIt);
    cout << "Предполагаемый корень: " << root << endl;
    return 0;
}
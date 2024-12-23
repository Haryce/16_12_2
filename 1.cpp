#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x * x - 2;
}
double df(double x) {
    return 2 * x; 
}
//метод касательных
double Newtonkos(double x0, double h, int maxIt) {
    double x_n = x0;
    for (int n = 0; n < maxIt; ++n) {
        double x = x_n - f(x_n) / df(x_n);
        cout << "Итерация " << n + 1 << ": x = " << x << endl;

        if (fabs(x - x_n) < h) {
            return x;
        }
        x_n = x;
    }
    cout << "Макс итерация." << endl;
    return x_n;
}
int main() {
    setlocale(LC_ALL, "Russian");
    double x0; 
    double h; 
    int maxIt; 
    cout << "Введите приближеность (x0): ";
    cin >> x0;
    cout << "Введите h: ";
    cin >> h;
    cout << "Введите максимальную итерацию: ";
    cin >> maxIt;
    double root = Newtonkos(x0, h, maxIt);
    cout << "Предполагаемый корень: " << root << endl;
    return 0;
}
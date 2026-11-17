#include <iostream>
#include <iomanip>
#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = ";
    cin >> x_p;
    cout << "x_k = ";
    cin >> x_k;
    cout << "dx  = ";
    cin >> dx;
    cout << "e   = ";
    cin >> e;
    cout << endl;

    // заголовок і шапка таблиці
    cout << "Taylor series: exp(x^2)" << endl;
    cout << string(56, '-') << endl;
    cout << "|" << setw(8) << "x"
         << "|" << setw(14) << "exp(x^2)"
         << "|" << setw(14) << "sum"
         << "|" << setw(6) << "n" << " |" << endl;
    cout << string(56, '-') << endl;

    x = x_p;
    while (x <= x_k)
    {
        sum(); // обчислення суми ряду

        cout << "|" << setw(8) << fixed << setprecision(3) << x
             << "|" << setw(14) << setprecision(6) << exp(x * x)
             << "|" << setw(14) << s
             << "|" << setw(6) << n << " |" << endl;

        x += dx;
    }
    cout << string(48, '-') << endl;

    cin.get();
    cin.get();
    return 0;
}
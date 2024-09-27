#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c)
{
    return fabs(((c.first - a.first) * (b.second - a.second) - (b.first - a.first) * (c.second - a.second)) / 2.0);
}

/*
int main()
{
    cout << setprecision(2) << fixed;
    Point a {-2.2, 4.5};
    Point b {3.5, -7};
    Point c {7.5, 3.5};
    cout << area(a, b, c) << endl;
    return 0;
}
*/

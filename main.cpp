#include <iostream>
#include <cmath>
#include <vector>
#include "curves.h"

using namespace std;

int main() {
    // Number of Curves objects to create:
    const int N = 10;

    auto all_curves = curves::FillFirstContainer(N);
    

    cout << "Coordinates of points and derivatives of all curves at t= M_PI/4:\n";
    PrintAt(all_curves, M_PI / 4);
    cout << "\n";

    auto circles = curves::FillSecondContainer(all_curves);

    cout << "Sorting the circles in second container:\n";
    curves::SortContainer(circles);
    PrintAt(circles, M_PI / 4);
    cout << "\n";

    cout << "Sum of radii: " << curves::SummOfRadii(circles)<< "\n";

    return 0;
}
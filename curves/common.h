#pragma once

#include<iostream>
#include<vector>
#include <iomanip>

enum CurveType{
    Circle,
    Ellipse,
    Helix
};

struct Point_3D{
    double x;
    double y;
    double z;
};

//Coordinates of points and derivatives of all curves in the container
template<class T>
void PrintAt(const std::vector<std::shared_ptr<T>>& v, double t){
    for(const auto& curve : v){
        Point_3D p = curve->GetPoint_3D(t);
        Point_3D d = curve->GetFirstDerivative(t);
        std::cout << "Coordinate: " << "(x: " << std::setprecision(5) << p.x << ", " <<
          "y: " << std::setprecision(5) << p.y << ", " <<
          "z: " << std::setprecision(5) << p.z << ")\n";
         std::cout << "Derivative: "<< "(x: " << std::setprecision(5) << d.x << ", " <<
          "y: " << std::setprecision(5) << d.y << ", " <<
          "z: " << std::setprecision(5) << d.z << ")\n";
    }
}

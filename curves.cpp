
#include <random>
#include <string>
#include <cmath>
#include <algorithm>
#include "curves.h"

using namespace std;


Point_3D curves::Circle::GetPoint_3D(const double t) const {
    Point_3D p = {};
    p.x = radius*cos(t);
    p.y = radius*sin(t);
    p.z = 0;
    return p;
}

Point_3D curves::Circle::GetFirstDerivative(const double t) const {
    Point_3D v = {};
    v.x = radius*sin(t)*(-1);
    v.y = radius*cos(t);
    v.z = 0;
    return v;
}


Point_3D curves::Ellipse::GetPoint_3D(const double t) const {
    Point_3D p = {};
    p.x = radius_X*cos(t);
    p.y = radius_Y*sin(t);
    p.z = 0;
    return p;
}

Point_3D curves::Ellipse::GetFirstDerivative(const double t) const {
    Point_3D v = {};
    v.x = radius_X*sin(t)*(-1);
    v.y = radius_Y*cos(t);
    v.z = 0;
    return v;
}


Point_3D curves::Helix::GetPoint_3D(const double t) const {
    Point_3D p = {};
    p.x = radius*cos(t);
    p.y = radius*sin(t);
    p.z = t * step / (2*M_PI);
    return p;
}

Point_3D curves::Helix::GetFirstDerivative(const double t) const {
    Point_3D v = {};
    v.x = radius*sin(t)*(-1);
    v.y = radius*cos(t);
    v.z = step / (2*M_PI);
    return v;
}

std::vector<std::shared_ptr<curves::Curve>> curves::FillFirstContainer(uint32_t n) {
    std::vector<std::shared_ptr<curves::Curve>> all_curves;
    for (int i =0; i < n; i++){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(0, 2);
    switch (distrib(gen) ) {
            case 0 : {
                std::uniform_int_distribution<> radii_circle(1, 100);
                all_curves.push_back(make_shared<curves::Circle> (curves::Circle(radii_circle(gen))));
            }
                break;
            case 1 : {
                std::uniform_int_distribution<> radii_circleX(1, 100);
                std::uniform_int_distribution<> radii_circleY(1, 100);
                all_curves.push_back(make_shared<curves::Ellipse> (curves::Ellipse(radii_circleX(gen), radii_circleY(gen))));
            }
                break;
            case 2 : {
                std::uniform_int_distribution<> radii_helix(1, 100);
                std::uniform_int_distribution<> step_helix(1, 10);
                all_curves.push_back(make_shared<curves::Helix> (curves::Helix(radii_helix(gen), step_helix(gen))));
            }
                break;
            default:
                break;
    }
    }
    return all_curves;
}

std::vector<std::shared_ptr<curves::Curve>> curves::FillSecondContainer(std::vector<std::shared_ptr<curves::Curve>>& all_curves) {
    std::vector<std::shared_ptr<curves::Curve>> circles;
    for (auto el: all_curves){
        if(el->GetTypeCurve() == CurveType::Circle) {
            circles.push_back(el);
        }
    }
    return circles;
}

void curves::SortContainer(std::vector<std::shared_ptr<curves::Curve>>& circles) {
    sort(circles.begin(), circles.end(), [](auto lhs, auto rhs){
        return dynamic_cast<curves::Circle*>(lhs.get())->GetRadius() < dynamic_cast<curves::Circle*>(rhs.get())->GetRadius();});
}

uint32_t curves::SummOfRadii(std::vector<std::shared_ptr<curves::Curve>>& circles){
    uint32_t res = 0;
    for (auto el: circles){
        res += dynamic_cast<curves::Circle*>(el.get())->GetRadius();
    }
    return res;
}

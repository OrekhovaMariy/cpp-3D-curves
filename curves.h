#pragma once

#include <memory>
#include <vector>
#include "common.h"

namespace curves {
    class Curve {
    public:
        virtual Point_3D GetPoint_3D(const double t) const = 0;
        virtual Point_3D GetFirstDerivative(const double t) const = 0;
        virtual CurveType GetTypeCurve() const = 0;
        
    };

    class Circle : public Curve{
    public:
        Circle(const uint32_t radius) : radius(radius), type(CurveType::Circle){};
        Point_3D GetPoint_3D(const double t) const override;
        Point_3D GetFirstDerivative(const double t) const override;
        CurveType GetTypeCurve() const override { return type; }
        uint32_t GetRadius() const {return radius;}
        
    private:
        uint32_t radius;
        CurveType type;
    };

    class Ellipse : public Curve{
    public:
        Ellipse(const uint32_t radius_X, const uint32_t radius_Y) : radius_X(radius_X), radius_Y(radius_Y), type(CurveType::Ellipse){};
        Point_3D GetPoint_3D(const double t) const override;
        Point_3D GetFirstDerivative(const double t) const override;
        CurveType GetTypeCurve() const override { return type; }
    private:
        uint32_t radius_X;
        uint32_t radius_Y;
        CurveType type;
    };

    class Helix : public Curve{
    public:
        Helix(const uint32_t radius, const uint32_t step) : radius(radius), step(step), type(CurveType::Helix){};
        Point_3D GetPoint_3D(const double t) const override;
        Point_3D GetFirstDerivative(const double t) const override;
        CurveType GetTypeCurve() const override { return type; }
    private:
        uint32_t radius;
        uint32_t step;
        CurveType type;
    };

//Fill a vector of curves in random manner with random parameters
std::vector<std::shared_ptr<Curve>>  FillFirstContainer(uint32_t n);
//Fill a vector of circles taken from vector of curves
std::vector<std::shared_ptr<Curve>> FillSecondContainer(std::vector<std::shared_ptr<Curve>>& all_curves);
 //Sorting the second container in the ascending order of circles’ radii
void SortContainer(std::vector<std::shared_ptr<Curve>>& circles);
 //The total sum of radii of all curves in the second container
uint32_t SummOfRadii(std::vector<std::shared_ptr<Curve>>& circles);


} //namespace

#include "Dimension3.h"

#include<iostream>

class Color3 : public Dimension3<Color3>{
    public: 
        Color3() : Dimension3() {}
        Color3( const double &c0, const double &c1, const double &c2 ) : Dimension3( c0, c1, c2 ) {}

        double r() const;
        double g() const;
        double b() const;
};

double Color3::r() const{
    return x();
}

double Color3::g() const{
    return y();
}

double Color3::b() const{
    return z();
}

inline std::ostream &operator<<( std::ostream &out, const Color3 &color ){
    return out << color.r() << ' ' << color.g() << ' ' << color.b() << '\n';
}
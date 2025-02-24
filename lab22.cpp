#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber {
public:
    double real, imag;
    ComplexNumber(double = 0, double = 0);
    ComplexNumber operator+(const ComplexNumber &);
    ComplexNumber operator-(const ComplexNumber &);
    ComplexNumber operator*(const ComplexNumber &);
    ComplexNumber operator/(const ComplexNumber &);
    bool operator==(const ComplexNumber &);
    double abs();
    double angle();
    
    
    friend ComplexNumber operator+(double, const ComplexNumber &);
    friend ComplexNumber operator-(double, const ComplexNumber &);
    friend ComplexNumber operator*(double, const ComplexNumber &);
    friend ComplexNumber operator/(double, const ComplexNumber &);
    friend bool operator==(double, const ComplexNumber &);
    
    
    friend ostream& operator<<(ostream &, const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x, double y) {
    real = x; 
    imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) {
    return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) {
    return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) {
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / denominator,
                         (imag * c.real - real * c.imag) / denominator);
}

bool ComplexNumber::operator==(const ComplexNumber &c) {
    return (real == c.real) && (imag == c.imag);
}

double ComplexNumber::abs() {
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle() {
    return atan2(imag, real) * 180.0 / M_PI; 
}


ComplexNumber operator+(double x, const ComplexNumber &c) {
    return ComplexNumber(x + c.real, c.imag);
}

ComplexNumber operator-(double x, const ComplexNumber &c) {
    return ComplexNumber(x - c.real, -c.imag);
}

ComplexNumber operator*(double x, const ComplexNumber &c) {
    return ComplexNumber(x * c.real, x * c.imag);
}

ComplexNumber operator/(double x, const ComplexNumber &c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((x * c.real) / denominator, (-x * c.imag) / denominator);
}

bool operator==(double x, const ComplexNumber &c) {
    return (x == c.real) && (c.imag == 0);
}


ostream& operator<<(ostream &out, const ComplexNumber &c) {
    if (c.real == 0 && c.imag == 0) {
        out << "0";
    } else {
        if (c.real != 0) {
            out << c.real;
        }
        if (c.imag != 0) {
            if (c.real != 0) {
                out << (c.imag > 0 ? "+" : "");
            }
            out << c.imag << "i";
        }
    }
    return out;
}

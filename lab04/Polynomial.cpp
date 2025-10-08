#include "Polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial(int degree, const double *coefficients){
    this->capacity = degree+1;
    this->coefficients = new double[capacity];
    for (int i = 0; i <= degree; ++i) {
            this->coefficients[i] = coefficients[i];
        }

}


Polynomial::Polynomial(const Polynomial &that){
    this->capacity = that.degree()+1;
    this->coefficients = new double[that.capacity];
    for(int i = 0; i < that.degree()+1; i++){
        this->coefficients[i] = that.coefficients[i];
    }
}


Polynomial::~Polynomial() {
    if(coefficients != nullptr){
        delete[] coefficients;
    }
}

ostream &operator<<(ostream &out, const Polynomial &what){
    for(int i =0; i <what.capacity-1; i++){
        out<<what.coefficients[i]<<"x^"<<(what.capacity-1-i)<<"+";
    }
    out<<what.coefficients[what.capacity-1]<<endl;;
    return out;
}

double Polynomial::evaluate(double x) const {
    double v = this->coefficients[0];
    for(int i = 1; i< this->capacity; i++){
        v = v*x + this->coefficients[i];
    }
    return v;
}

int Polynomial:: degree() const{
    return this->capacity-1;
}

Polynomial Polynomial :: derivative() const{
    if (this->degree() == 0) {
        double zeroCoeff[] = {0.0};
        return Polynomial(0, zeroCoeff);
    }

    int newDegree = this->degree() - 1;
    double* newCoeffs = new double[newDegree + 1];

    for (int i = 1; i <= this->degree(); i++) {
        newCoeffs[i - 1] = i * this->coefficients[i];
    }

    Polynomial result(newDegree, newCoeffs);
    delete[] newCoeffs;
    return result;
}


double Polynomial::operator[](int index) const{
    if(index < 0 || index > capacity-1){
        throw out_of_range("Index out of range");
    }
    return coefficients[index];
}

Polynomial operator -(const Polynomial &a){
    Polynomial result(a);
    for(int i = 0; i <a.degree()+1; i++){
        result.coefficients[i] = -a.coefficients[i];
    }
    return result;
}

Polynomial operator +(const Polynomial &a, const Polynomial &b){
    Polynomial result(a);
    for(int i = 0; i <a.degree()+1; i++){
        result.coefficients[i] += b.coefficients[i];
    }
    return result;
}

Polynomial operator -(const Polynomial &a, const Polynomial &b){
    Polynomial result(a);
    for(int i = 0; i <a.degree()+1; i++){
        result.coefficients[i] -= b.coefficients[i];
    }
    return result;
}

Polynomial operator *(const Polynomial &a, const Polynomial &b){
    Polynomial result(a);
    for(int i = 0; i <a.degree()+1; i++){
        result.coefficients[i] *= b.coefficients[i];
    }
    return result;
}

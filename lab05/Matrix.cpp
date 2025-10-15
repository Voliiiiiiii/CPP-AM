#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//konstruktorok - kesz

Matrix::Matrix(int rows, int cols):mRows(rows),mCols(cols),mElements(mRows*mCols,0){
}
Matrix::Matrix(const Matrix& other): mRows(other.mRows),mCols(other.mCols),mElements(other.mElements){ 
}
Matrix::Matrix(Matrix&& other) noexcept:mRows(other.mRows),mCols(other.mCols),mElements(move(other.mElements)){
}


//kiiratas - kesz
void Matrix::printMatrix(std::ostream& os) const{
    for(int i = 0; i < this->mRows;++i){
        for(int j = 0; j < this->mCols; ++j){
            os<<setw(8)<<mElements[i*mCols+j]<<" ";
        }
        os<<endl;
    }
}

//ertekadas-kesz
Matrix::Matrix& operator=(const Matrix& other){
    if (this == &other)
        return *this;

    mCols = other.mCols;
    mRows = other.mRows;
    mElements = other.mElements;

    return *this; 
}

Matrix& operator=(Matrix&& other) noexcept{
        if (this == &other)
        return *this;

    mCols = other.mCols;
    mRows = other.mRows;
    mElements = move(other.mElements);

    return *this; 
}


//feltoltesek - kesz
void Matrix::randomMatrix(int a, int b){
    srand(time(NULL));
    for(int i = 0; i < this->mRows*mCols;++i){
        double f = (double)rand()/RAND_MAX;
        mElements[i] = a + f * (b-a);
    }
}
void Matrix::fillMatrix(double value){
    for(int i = 0; i < this->mRows*mCols;++i){
        mElements[i] = value;
    }
}




//operatorok

friend Matrix operator+(const Matrix& x, const Matrix& y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }
    Matrix result(x.mRows, x.mCols);
    for (int i = 0; i < x.mRows * x.mCols; ++i) {
        result.mElements[i] = x.mElements[i] + y.mElements[i];
    }
    return result;
}

friend Matrix operator*(const Matrix& x, const Matrix& y){

}


friend std::ostream& operator<<(std::ostream& os, const Matrix& mat){
    mat.printMatrix(os);
    return os;
}
friend std::istream& operator>>(std::istream& is, Matrix& mat){
    mat.printMatrix(is);
    return is;    
}
//INDEXELES

double* Matrix::operator[](int row){
    return &mElements[rows*mCols];
}
const double* Matrix::operator[](int row) const{
    return &mElements[rows*mCols];
}
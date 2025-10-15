#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//konstruktorok

Matrix::Matrix(int rows, int cols):mRows(rows),mCols(cols),mElements(mRows*mCols,0){
}
Matrix::Matrix(const Matrix& other): mRows(other.mRows),mCols(other.mCols),mElements(other.mElements){ 
}
Matrix::Matrix(Matrix&& other) noexcept:mRows(other.mRows),mCols(other.mCols),mElements(move(other.mElements)){
}


//kiiratas
void Matrix::printMatrix(std::ostream& os) const{
    for(int i = 0; i < this->mRows;++i){
        for(int j = 0; j < this->mCols; ++j){
            os<<setw(8)<<mElements[i*mCols+j]<<" ";
        }
        os<<endl;
    }
}



//feltoltesek
void Matrix::randomMatrix(int a, int b){
    srand(time(NULL));
    for(int i = 0; i < this->mRows*mCols;++i){
        double f = (double)rand()/RAND_MAX;
        mElements[i] = a + f * (b-a);
    }
}




//operatorok

friend std::ostream& operator<<(std::ostream& os, const Matrix& mat){
    mat.printMatrix(os);
    return os;
}

//INDEXELES

double* Matrix::operator[](int row){
    return &mElements[rows*mCols];
}
const double* Matrix::operator[](int row) const{
    return &mElements[rows*mCols];
}
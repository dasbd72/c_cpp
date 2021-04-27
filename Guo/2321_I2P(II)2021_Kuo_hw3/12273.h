#ifndef function_h
#define function_h
#include <iostream>

class Matrix
{
    friend std::ostream &operator<<(std::ostream &, const Matrix &);
    friend std::istream &operator>>(std::istream &, Matrix &);
public:
    Matrix(int s = 5);

    Matrix(const Matrix &);// copy constructor

    ~Matrix();

    Matrix &operator=(const Matrix &a);

    Matrix &clockwise90();
private:
    int **matrix;
    int *buf;   // 2D matrix stored in 1D raster scan order
    int size;
}; //end class Matrix

#endif /* function_h */

std::ostream &operator<<(std::ostream &os, const Matrix &m){
    for(int i = 0; i < m.size; i++){
        for(int j = 0; j < m.size; j++){
            os << m.matrix[i][j] << ' ';
        }
        os << std::endl;
    }
}
std::istream &operator>>(std::istream &os, Matrix &m){
    for(int i = 0; i < m.size; i++){
        for(int j = 0; j < m.size; j++){
            os >> m.matrix[i][j];
        }
    }
}

Matrix::Matrix(int s){
    size = s;
    buf = new int[s*s];
    matrix = new int*[s];
    for(int i = 0; i < s; i++) matrix[i] = buf + i * s;
}

Matrix::Matrix(const Matrix &m1):size(m1.size){
    buf = new int[size * size];
    matrix = new int*[size];
    for(int i = 0; i < size; i++) {
        matrix[i] = buf + i * size;
        for(int j = 0; j < size; j++){
            matrix[i][j] = m1.matrix[i][j];
        }
    }
}

Matrix::~Matrix(){
    delete [] buf;
    delete [] matrix;
}

Matrix &Matrix::operator=(const Matrix &a){
    return *this;
}

Matrix &Matrix::clockwise90(){
    Matrix b = *this;
    for(int j = 0, _i = 0; j < size; j++, _i++){
        for(int i = size-1, _j = 0; i >= 0; i--, _j++){
            b.matrix[_i][_j] = matrix[i][j];
        }
    }
    return b;
}

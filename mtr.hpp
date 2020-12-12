#ifndef mtr_hpp
#define mtr_hpp

#include <stdio.h>
#include <iostream>

template<class T>
class Matrix{
    T** matrix;
    unsigned int SizeN;
    unsigned int SizeM;
public:
    Matrix() = delete;
    Matrix(unsigned int m, unsigned int n);
    Matrix(const class matrix& m) = delete;
    ~Matrix();
    
    unsigned int getSizeM();
    unsigned int getSizeN();
    unsigned int getSize();
    
    void clear();
    void fillMatrixRnd(T from, T to);
    void show();
    
    T& operator ()(unsigned int m, unsigned int n);
};

template<class T>
unsigned int Matrix<T>::getSizeM(){
    return SizeM;
}
template<class T>
unsigned int Matrix<T>::getSizeN(){
    return SizeN;
}
template<class T>
unsigned int Matrix<T>::getSize(){
    return SizeM*SizeN;
}

template<class T>
T& Matrix<T>::operator ()(unsigned int m, unsigned int n){
    return matrix[m][n];
}

template<class T>
Matrix<T>::Matrix(unsigned int n, unsigned int m){
    if (m <= 0 || n <= 0) return;
    matrix = new T*[m];
    for (int i = 0; i < m; i++){
        matrix[i] = new T[n];
    }
    SizeM = m;
    SizeN = n;
}

template<class T>
Matrix<T>::~Matrix(){
    if (matrix == nullptr) return;
    for (int i = 0; i < SizeM; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
    matrix = nullptr;
}

template<class T>
void Matrix<T>::fillMatrixRnd(T from, T to){
    for (int i = 0; i < SizeM; i++) {
        for (int j = 0; j < SizeN; j++) {
            matrix[i][j] = (from*100 + rand() % ((to - from)*100))/100.0;
        }
    }
}

template<class T>
void Matrix<T>::show(){
    if (matrix == nullptr){
        std::cout << "matrix is empty" << std::endl;
        return;
    }
    for (int i = 0; i < SizeM; i++) {
        for (int j = 0; j < SizeN; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<class T>
void Matrix<T>::clear(){
    for (int i = 0; i < SizeM; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
    matrix = nullptr;
}

#endif /* mtr_hpp */

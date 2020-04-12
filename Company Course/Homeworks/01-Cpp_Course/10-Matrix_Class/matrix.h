#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
public:
    Matrix(T a11=0,T a12=0,T a21=0,T a22=0);

    bool operator== (Matrix<T> &Matrix2);
    bool operator!= (Matrix<T> &Matrix2);
    bool operator<= (Matrix<T> &Matrix2);
    bool operator<  (Matrix<T> &Matrix2);
    bool operator>= (Matrix<T> &Matrix2);
    bool operator>  (Matrix<T> &Matrix2);

    const Matrix<T> &operator+ (const Matrix<T> &Matrix2);
    const Matrix<T> &operator- (const Matrix<T> &Matrix2);
    const Matrix<T> &operator* (const Matrix<T> &Matrix2);
    const Matrix<T> &operator/ (const Matrix<T> &Matrix2);

    Matrix<T> operator+= (const Matrix<T> &Matrix2);
    Matrix<T> operator-= (const Matrix<T> &Matrix2);
    Matrix<T> operator*= (const Matrix<T> &Matrix2);
    Matrix<T> operator/= (const Matrix<T> &Matrix2);

    Matrix<T> &operator++ (); //Prefix
    Matrix<T> &operator-- (); //Prefix
    const Matrix<T> operator++ (int); //Postfix
    const Matrix<T> operator-- (int); //Postfix

    friend ostream & operator<< (ostream &out, const Matrix<T> &Matrix)
    {
        out<<"|"<<Matrix.Mat[0]<<", "<<Matrix.Mat[1]<<"|"<<endl<<"|"<<Matrix.Mat[2]<<", "<<Matrix.Mat[3]<<"|";
        return  out;
    }

    friend istream & operator>> (istream &in, Matrix<T> &Matrix)
    {
        cout<<endl<<"a11: ";
        in>>Matrix.Mat[0];
        cout<<"a12: ";
        in>>Matrix.Mat[1];
        cout<<"a21: ";
        in>>Matrix.Mat[2];
        cout<<"a22: ";
        in>>Matrix.Mat[3];
        return in;
    }

private:
    T Mat[4];
};


template<typename T>
Matrix<T>::Matrix(T a11, T a12, T a21, T a22)
{
    Mat[0]=a11;
    Mat[1]=a12;//  |a11 a12|
    Mat[2]=a21;//  |a21 a22|
    Mat[3]=a22;
}

template<typename T>
bool Matrix<T>::operator==(Matrix<T> &Matrix2)
{

    for(unsigned int i=0; i<4;i++){
        if(this->Mat[i]!=Matrix2.Mat[i]){
            return false;
        }
    }
    return true;

}

template<typename T>
bool Matrix<T>::operator!=(Matrix<T> &Matrix2)
{
    return ! (*this==Matrix2);
}

template<typename T>
bool Matrix<T>::operator<=(Matrix<T> &Matrix2)
{
    for(unsigned int i=0; i<4;i++){
        if(this->Mat[i]>Matrix2.Mat[i]){
            return false;
        }
    }
    return true;
}

template<typename T>
bool Matrix<T>::operator<(Matrix<T> &Matrix2)
{
    for(unsigned int i=0; i<4;i++){
        if(this->Mat[i]>=Matrix2.Mat[i]){
            return false;
        }
    }
    return true;
}

template<typename T>
bool Matrix<T>::operator>=(Matrix<T> &Matrix2)
{
    for(unsigned int i=0; i<4;i++){
        if(this->Mat[i]<Matrix2.Mat[i]){
            return false;
        }
    }
    return true;
}

template<typename T>
bool Matrix<T>::operator>(Matrix<T> &Matrix2)
{
    for(unsigned int i=0; i<4;i++){
        if(this->Mat[i]<=Matrix2.Mat[i]){
            return false;
        }
    }
    return true;
}

template<typename T>
const Matrix<T> &Matrix<T>::operator+(const Matrix<T> &Matrix2)
{
    auto *Result = new Matrix<T>();
    for(unsigned int i=0; i<4;i++){
        Result->Mat[i] = this->Mat[i] + Matrix2.Mat[i];
    }
    return *Result;
}

template<typename T>
const Matrix<T> &Matrix<T>::operator-(const Matrix<T> &Matrix2)
{
    auto *Result = new Matrix<T>();
    for(unsigned int i=0; i<4;i++){
        Result->Mat[i] = this->Mat[i] - Matrix2.Mat[i];
    }
    return *Result;
}

template<typename T>
const Matrix<T> &Matrix<T>::operator*(const Matrix<T> &Matrix2)
{
    auto *Result = new Matrix<T>();
    for(unsigned int i=0; i<4;i++){
        Result->Mat[i] = this->Mat[i] * Matrix2.Mat[i];
    }
    return *Result;
}

template<typename T>
const Matrix<T> &Matrix<T>::operator/(const Matrix<T> &Matrix2)
{
    auto *Result = new Matrix<T>();
    for(unsigned int i=0; i<4;i++){
        Result->Mat[i] = this->Mat[i] / Matrix2.Mat[i];
    }
    return *Result;
}

template<typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T> &Matrix2)
{
    *this=(*this+Matrix2);
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator-=(const Matrix<T> &Matrix2)
{
    *this=(*this-Matrix2);
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix<T> &Matrix2)
{
    *this=(*this*Matrix2);
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator/=(const Matrix<T> &Matrix2)
{
    *this=(*this/Matrix2);
    return *this;
}

template<typename T>
Matrix<T> & Matrix<T>::operator++()
{
    for(unsigned int i=0; i<4;i++){
        this->Mat[i]++;
    }
    return *this;
}

template<typename T>
Matrix<T> & Matrix<T>::operator--()
{
    for(unsigned int i=0; i<4;i++){
        this->Mat[i]--;
    }
    return *this;
}

template<typename T>
const Matrix<T> Matrix<T>::operator++(int)
{
    auto temp = *this;
    ++*this;
    return temp;
}

template<typename T>
const Matrix<T> Matrix<T>::operator--(int)
{
    auto temp = *this;
    --*this;
    return temp;
}

#endif // MATRIX_H

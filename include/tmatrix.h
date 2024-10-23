// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>
#include <cassert>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz == 0 || sz > MAX_VECTOR_SIZE)
      throw out_of_range("Vector size must meet the conditions");
    pMem = new T[sz]();// {}; // У типа T д.б. конструктор по умолчанию
    if (pMem == nullptr)
        throw bad_alloc();
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      sz = v.sz;
      pMem = new T[sz];
      if (pMem == nullptr)
          throw bad_alloc();
      copy(v.pMem, v.pMem + sz, pMem);
  }
    TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector()
  {
      delete[] pMem;
      pMem = nullptr;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
          return *this;
      TDynamicVector Result(v);
      swap(*this, Result);
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      delete[] pMem;
      pMem = nullptr;
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; } 

  // индексация
  T& operator[](size_t ind)
  {
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind < 0 || ind >= sz)
          throw out_of_range("check ind");
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind < 0 || ind >= sz)
          throw out_of_range("check ind");
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
          return false;
      bool f = true;
      for (int i = 0; i < sz; i++)
          if (pMem[i] != v.pMem[i]) {
              f = false;
              break;
          }
      if (f)
          return true;
      else return false;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !(*this == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector Result(*this);
      for (int i = 0; i < sz; i++)
          Result.pMem[i] += val;
      return Result;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector Result(*this);
      for (int i = 0; i < sz; i++)
          Result.pMem[i] -= val;
      return Result;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector Result(*this);
      for (int i = 0; i < sz; i++)
          Result.pMem[i] *= val;
      return Result;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw logic_error("different lengths of vectors");
      TDynamicVector Result(*this);
      for (int i = 0; i < sz; i++)
          Result.pMem[i] += v.pMem[i];
      return Result;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw logic_error("different lengths of vectors");
      TDynamicVector Result(*this);
      for (int i = 0; i < sz; i++)
          Result.pMem[i] -= v.pMem[i];
      return Result;
  }
  T operator*(const TDynamicVector& v)
    //noexcept(noexcept(T()))
  {
      if (sz != v.sz)
          throw logic_error("different lengths of vectors");
      T sum = T();
      for (int i  = 0; i < sz; i++)
          sum += pMem[i] * v.pMem[i];
      return sum;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};

// Динамическая матрица -
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T> >
{
  using TDynamicVector<TDynamicVector<T> >::pMem;
  using TDynamicVector<TDynamicVector<T> >::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T> >(s)
  {
    if (s > MAX_MATRIX_SIZE)
        throw out_of_range("Matrix size must meet the conditions");
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];
    
  using TDynamicVector<TDynamicVector<T>>::size;
    
  using TDynamicVector<TDynamicVector<T>>::at;

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] != m.pMem[i])
              return 0;
      return 1;
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix Result(sz);
      for (size_t i = 0; i < sz; i++)
          Result.pMem[i] = pMem[i] * val;
      return Result;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.sz)
          throw logic_error("You can't multiply vectors of different lengths");
      TDynamicVector<T> Result(sz);
      for (size_t i = 0; i < sz; i++)
          Result[i] = pMem[i] * v;
      return Result;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw logic_error("You can't add matrices of different lengths");
      TDynamicMatrix Result(sz);
      for (size_t i = 0; i < sz; i++)
          Result.pMem[i] = pMem[i] + m.pMem[i];
      return Result;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw logic_error("You can't substract matrices of different lengths");
      TDynamicMatrix Result(sz);
      for (size_t i = 0; i < sz; i++)
          Result.pMem[i] = pMem[i] - m.pMem[i];
      return Result;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw logic_error("You can't multiply matrices of different lengths");
      TDynamicMatrix Result(sz);
      for (size_t i = 0; i < sz; i++)
          for (size_t j = 0; j < sz; j++)
              for (size_t k = 0; k < sz; k++)
                  Result.pMem[i][j] += pMem[i][k] * m.pmem[k][j];
      return Result;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          istr >> v.pMem[i];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          ostr << v.pMem[i] << endl;
      return ostr;
  }
};

#endif

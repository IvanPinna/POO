#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <iostream>
#include <ctime> 
#include <stdio.h>

using namespace std;

class Fecha {
public:

  class Invalida{
  public:
    Invalida(const char* msg) : razon_(msg){}
    const char* por_que() const {return razon_;}
  private:
    const char* razon_;
  };
    
  static const int AnnoMinimo = 1902;
  static const int AnnoMaximo = 2037;
  
  explicit Fecha(int d = 0, int m = 0, int a = 0);
  Fecha(const char*);  

  //Operadores aritmeticcos.
  Fecha& operator +=(int dias);
  Fecha& operator -=(int dias) { return *this += -dias; }
  Fecha& operator ++() { return *this += 1; }
  Fecha&  operator --() { return *this += -1; }
  
  Fecha operator++(int)
  {
    Fecha resultado(*this);
    *this += 1;
    return resultado;
  }
  
  Fecha operator--(int)
  {
    Fecha resultado(*this);
    *this += -1;
    return resultado;
  }
  
  Fecha operator+(int dias) const { return Fecha(*this) += dias; }
  Fecha operator-(int dias) const { return Fecha(*this) += -dias; }

  friend long int operator-(const Fecha& a, const Fecha& b);
  
  //Operadores de conversion
  operator char const*() const;
  
  //Funciones observadoras
  int dia() const noexcept { return dia_; }
  int mes() const noexcept { return mes_; }
  int anno() const noexcept { return anno_; }
    
private:
  int dia_, mes_, anno_;
  void valida(); //Lanza una excepcion si la fecha no es valida.
};

inline bool operator <(const Fecha& a, const Fecha& b)
{ return (a - b) < 0; }

inline bool operator ==(const Fecha& a, const Fecha& b)
{ return (a - b) == 0; }

inline bool operator !=(const Fecha& a, const Fecha& b)
{ return !(a == b); }

inline bool operator >(const Fecha& a, const Fecha& b)
{ return b < a; }

inline bool operator <=(const Fecha& a, const Fecha& b)
{ return !(b < a); }

inline bool operator >=(const Fecha& a, const Fecha& b)
{ return !(a < b); }

#endif

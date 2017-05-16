#ifndef FECHA_HPP_
#define FECHA_HPP_

#include <iostream>
#include <ctime> 
#include <stdio.h>

using namespace std;

class Fecha {
public:
    static const int AnnoMinimo = 1902;
    static const int AnnoMaximo = 2037;
    Fecha(int d = 0, int m = 0, int a = 0);
    Fecha(const char*);  
    char* cadena(); //IMPLICITO -> Convierte  fecha a cadena caracteres.
    inline  void mostrar();

  //Operadores aritmeticcos.
    Fecha& operator +=(const int);
    Fecha& operator -=(const int);
    Fecha& operator ++(); //Incrementa un dia. Preincremento
    Fecha operator ++(int);  //Postincremento
    Fecha&  operator --(); //Decrementa un dia.
    Fecha operator --(int);
    Fecha operator +(int) const;    //Devuelve el numero de dias
    Fecha operator -(int) const ; //Devuelve el numero de dias

  //Funciones observadoras
    inline const int dia_() const noexcept {return dia;};
    inline const int mes_() const noexcept {return mes;};
    inline const int anno_() const noexcept {return anno;};
    
private:
    int dia, mes, anno;
    bool valida(); //Lanza una excepcion si la fecha no es valida.
  // Fecha copiar();
};

inline bool operator ==(const Fecha&, const Fecha&);
inline bool operator !=(const Fecha&, const Fecha&);
inline bool operator <(const Fecha&, const Fecha&);
inline bool operator >(const Fecha&, const Fecha&);
inline bool operator <=(const Fecha&, const Fecha&);
inline bool operator >=(const Fecha&, const Fecha&);

#endif

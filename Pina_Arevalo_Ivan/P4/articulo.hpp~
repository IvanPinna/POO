#ifndef ARTICULO_HPP_
#define ARTICULO_HPP_

//#include <iostream>
#include "cadena.hpp"
#include "fecha.hpp"

class Articulo{
public:
  Articulo(const Cadena& ref, const Cadena& tit, const Fecha& publi,
	   double prec, unsigned stock)
    : cod_ref_(ref), titulo_(tit), f_publi_(publi), precio_(prec),
      stock_(stock)
  {}

  const Cadena& referencia() const {return cod_ref_;}
  const Cadena& titulo() const {return titulo_;}
  const Fecha& f_publi() const {return f_publi_;}
  
  double precio() const {return precio_;}
  double& precio() {return precio_;}
  
  unsigned stock() const {return stock_;}
  unsigned& stock() {return stock_;}
  
private:
  Cadena cod_ref_;
  Cadena titulo_;
  Fecha f_publi_;
  double precio_;
  unsigned stock_;
};

//Operador de flujo
ostream& operator << (ostream& os, const Articulo& a);

#endif

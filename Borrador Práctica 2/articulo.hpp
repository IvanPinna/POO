#ifndef ARTICULO_HPP_
#define ARTICULO_HPP_

#include "cadena.hpp"
#include "fecha.hpp"

class Articulo
{
public:

  Articulo(const Cadena& ref, const  Cadena& titul, const Fecha& f,
	   double precio,unsigned existencias);
  const Cadena& referencia() const { return ref_;}
  const Cadena& titulo() const { return titulo_;}
  const Fecha& f_publi() const { return f_;}
  double precio() const { return precio_;}
  double& precio() const { return precio_;}
  unsigned stock() const { return stock_;}
  unsigned& stock() const { return stock_;}
private:
  Cadena ref_, titulo_;
  Fecha f_;
  double precio_;
  unsigned stock_;
};

std::ostream& operator<<(std::ostream& os, const Articulo& a );
  
#endif

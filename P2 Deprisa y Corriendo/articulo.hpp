
#ifndef ARTICULOS_HPP
#define ARTICULOS_HPP

#include <iomanip>
#include <iostream>

#include "cadena.hpp"
#include "fecha.hpp"

using namespace std;

class Articulo
{
public:

  Articulo(const Cadena& c, const Cadena& t, const Fecha& f,
	   double p, unsigned n) : cod_(c), tit_(t), f_(f),
				   prec_(p), stock_(n) {}

  const Cadena& referencia() const noexcept { return cod_; }
  const Cadena& titulo() const noexcept { return tit_; }
  const Fecha& f_publi() const noexcept { return f_; }

  double precio() const noexcept { return prec_; }
  double& precio() noexcept { return prec_; }

  unsigned stock() const noexcept { return stock_; }
  unsigned& stock() noexcept { return stock_; }

private:
  Cadena cod_;
  Cadena tit_;
  Fecha f_;
  double prec_;
  unsigned stock_;
};

ostream& operator<<(ostream& os, const Articulo& a);

#endif

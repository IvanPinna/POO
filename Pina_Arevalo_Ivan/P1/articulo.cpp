#include "articulo.hpp"

Articulo::Articulo(const Cadena& ref, const  Cadena& titul,
		   const Fecha& f, double precio,unsigned
		   existencias): ref_(ref), titulo_(titul),
				 f_(f), precio_(precio),
				 stock_(existencias)
{} 

std::ostream& operator<<(std::ostream& os, const Articulo& a )
{
  os << '[' << ref_ << "]" << " \"" << titulo_ << "\", " << f_
     << "." << precio << "€";
  return os;
}

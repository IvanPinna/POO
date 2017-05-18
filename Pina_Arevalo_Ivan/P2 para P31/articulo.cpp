#include "articulo.hpp"
#include <iomanip>
#include <iostream>

ostream& operator<<(ostream& os, const Articulo& a)
{
	os << "[" << a.referencia() << "] \"" << a.titulo()
	<< "\", "  << a.f_publi().anno() << ". "
    << fixed << setprecision(2) << a.precio() << " €";

	return os;
}

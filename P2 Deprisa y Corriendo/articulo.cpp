#include "articulo.hpp"

ostream& operator<<(ostream& os, const Articulo& a)
{
  os << " [" << a.referencia() << "] \"" << a.titulo()
     << "\", "  << a.f_publi() << ". "
     << fixed << setprecision(2) << a.precio() << " €";

  return os;
}

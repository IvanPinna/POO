#include "articulo.hpp"
#include <iomanip>
#include <iostream>

ostream& operator<<(ostream& os, const Articulo& a)
{
  os << "[" << a.referencia() << "] \"" << a.titulo()
     << "\", "  << a.f_publi().anno() << ". "
     << fixed << setprecision(2) << a.precio() << " €\n";

    a.impresion_especifica(os);

  return os;
}

void Libro::impresion_especifica(ostream& os) const noexcept
{
    os << '\t' << pag_ << " págs., " << stock_ << " unidades.";
}

void Cederron::impresion_especifica(ostream& os) const noexcept
{
    os << '\t' << MB_ << " MB, " << stock_ << " unidades.";
}

void LibroDigital::impresion_especifica(ostream& os) const noexcept
{
    os << "\tA la venta hasta el " << exp_ << '.';
}

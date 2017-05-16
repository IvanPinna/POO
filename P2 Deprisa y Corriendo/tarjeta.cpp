
#include <iomanip>
#include "usuario.hpp"
#include "tarjeta.hpp"

using namespace std;

void eliminarChar(Cadena& cad, size_t pos)
{
  Cadena n = cad.substr(0, pos);

  if ((pos + 1) < cad.length())
    n += Cadena(cad, pos + 1);

  cad = move(n);
}

bool luhn(const Cadena& num, size_t n);

Numero::Numero(Cadena num)
{
    size_t i = 0;

    while (i < num.length())
    {
        if (isspace(num[i]))
	  eliminarChar(num, i);
        else if (num[i] < '0' or num[i] > '9')
	  throw Incorrecto(Razon::DIGITOS);
        else
	  ++i;
    }

    if (num.length() < 13 or num.length() > 19)
      throw Incorrecto(Razon::LONGITUD);

    if (!luhn(num, num.length()))
      throw Incorrecto(Razon::NO_VALIDO);

    c_num = num;
}

Tarjeta::Tarjeta(Tipo e, const Numero&  n, Usuario& u, const Fecha& f)
  : tipo_(e), num_(n), tit_(&u), fCad_(f),
    titular_facial_(u.nombre() + " " + u.apellidos())
{
  if (f < Fecha())
    throw Caducada(f);

  u.es_titular_de(*this);
}

Tarjeta::~Tarjeta()
{
  if (tit_)
    tit_->no_es_titular_de(*this);
}

ostream& operator << (ostream& os, Tarjeta::Tipo const& tipo)
{
  int t = tipo;
  switch (t)
  {
    case 0:	os << " VISA ";
      break;
    case 1: os << " Mastercard ";
      break;
    case 2: os << " Maestro ";
      break;
    case 3: os << " JCB	";
      break;
    case 4: os << " AmericanExpress ";
      break;
  }

  return os;
}

ostream& operator << (ostream& os , const Tarjeta& t)
{
  os << t.tipo() << "\n" << t.numero() << "\n"
     << t.titular_facial() << "\n" << "Caduca: "
     << setfill('0') << setw(2)
     << t.caducidad().mes() << "/" << setw(2)
     << (t.caducidad().anno() % 100);
  
  return os;
}

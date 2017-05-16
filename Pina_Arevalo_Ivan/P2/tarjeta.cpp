#include "tarjeta.hpp"
#include "usuario.hpp"
#include <iomanip>

bool luhn(const Cadena& numero);

Numero::Numero(const Cadena& num)
{
    if (num.length() < 13)
        throw Incorrecto(LONGITUD);
 
    char* tmp_num = new char[num.length()]{'\0'};
    size_t tmp_i = 0;
 
    for (char c : num) {
         if (isspace(c))
            continue;
 
         if (c < '0' or c > '9')
              throw Incorrecto(DIGITOS);
 
         tmp_num[tmp_i++] = c;
    }
 
    if (tmp_i < 13 or tmp_i > 19)
        throw Incorrecto(LONGITUD);
 
    num_ = tmp_num;
 
    if (!luhn(num_))
        throw Incorrecto(NO_VALIDO);
}

//CLASE TARJETA
Tarjeta::Tarjeta(Tipo t, const Numero& n, Usuario& u,
		 const Fecha& f):
  tip_(t), num_(n), user_(&u), cad_(f),
  titular_facial_(u.nombre() + " " + u.apellidos())
{
  Fecha actual; //Generamos una fecha actual
  if(actual > cad_)
    throw Caducada(f);

  u.es_titular_de(*this); //Le pasamos la tarjeta para asociarla al user
}

Tarjeta::~Tarjeta()
{
  if(user_ != nullptr)
    user_->no_es_titular_de(*this);
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


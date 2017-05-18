#include "tarjeta.hpp"
#include "usuario.hpp"
#include <iomanip>
#include <algorithm>

bool luhn(const Cadena& numero);

struct EsDigito // std::unary_function<char, bool> Deprecated.
{
  bool operator()(char c) const {return std::isdigit(c);}
};

Numero::Numero(const Cadena& num): num_(num)
{
  //Genera un objeto temporal EsBlanco.
  Cadena::iterator fin = std::remove_if(num_.begin(), num_.end(),
					[](char c) {
					  return std::isspace(c);
					});
  
  *fin = 0; // '\0' '\x0'
  
  
  if(fin != num.end()) {
    Cadena sd(num_.c_str());
    num_ = sd;
  }
  
  if(std::find_if(std::begin(num_), std::end(num_),
		  std::not1(std::function<bool(char)
			    >(EsDigito())) ) != num_.end())
    throw Incorrecto(DIGITOS);
  
  std::size_t j = num_.length();
  
  if(j < 13 or j >19) throw Incorrecto(LONGITUD);
  if(!luhn(num_)) throw Incorrecto(NO_VALIDO);
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


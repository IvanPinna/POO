
#ifndef TARJETA_HPP
#define TARJETA_HPP

#include "cadena.hpp"
#include "fecha.hpp"

using namespace std;

class Numero
{
public:

  enum Razon { LONGITUD, DIGITOS, NO_VALIDO };
  Numero(Cadena num);

  operator const char*() const
  { return c_num.c_str(); }

  bool operator<(const Numero& n) const
  { return c_num < n.c_num; }

  class Incorrecto
  {
  public:
    Incorrecto(Razon r) : r_(r) {}
    Razon razon() const { return r_; }
  private:
    Razon r_;
  };

private:
  Cadena c_num;
};

class Usuario;

class Tarjeta
{
public:
  enum Tipo{VISA, Mastercard, Maestro, JCB, AmericanExpress};

  Tarjeta(Tipo e, const Numero& n, Usuario& u, const Fecha& f);

  Tarjeta(const Tarjeta&) = delete;
  Tarjeta& operator=(const Tarjeta&) = delete;

  ~Tarjeta();

  const Tipo& tipo() const { return tipo_; }
  const Numero& numero() const { return num_; }
  Usuario* titular() const { return tit_; }
  const Fecha& caducidad() const { return fCad_; }
  const Cadena& titular_facial() const { return titular_facial_; }
  
  void anula_titular() { const_cast<Usuario*&>(tit_) = nullptr; }
  
  bool operator<(const Tarjeta& t) const
  { return num_ < t.num_; }
  
  class Caducada
  {
  public:
    Caducada(const Fecha& cad) : caducada(cad) {}

    const Fecha& cuando() const { return caducada; }

  private:
    Fecha caducada;
  };

private:
  Tipo tipo_;
  Numero num_;
  Usuario* const tit_;
  Fecha fCad_;
  Cadena titular_facial_;
};

ostream& operator << (ostream& os, Tarjeta::Tipo const& tipo);
ostream& operator<<(ostream& os, const Tarjeta& t);

#endif //TARJETA_HPP

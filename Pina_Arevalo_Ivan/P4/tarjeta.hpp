#ifndef TARJETA_HPP_
#define TARJETA_HPP_

#include "fecha.hpp"
#include "cadena.hpp"

class Numero{
public:
  enum Razon{LONGITUD, DIGITOS, NO_VALIDO};
  Numero(const Cadena& num);

  operator const  char*() const
  {return num_.c_str();}

  bool operator<(const Numero& n) const
  { return num_ < n.num_;}
  
  class Incorrecto {
  public:
    Incorrecto(Razon r):r_(r)
    {}
    
    const Razon& razon() const {return r_;}
    
  private:
    Razon r_;
  };

private:
  Cadena num_;
};

void eliminarChar(Cadena& c, size_t i);

class Usuario;   //Declaracion adelantada de la clase usuario. 

class Tarjeta{
public:
  enum Tipo{VISA, Mastercard, Maestro, JCB, AmericanExpress};

  Tarjeta(Tipo t, const Numero& n,  Usuario& u, const Fecha& f);

  class Caducada{
  public:
    Caducada(const Fecha& f): cadu_(f)
    {}
    const Fecha& cuando() const {return cadu_;}
  private:
    Fecha cadu_;
  };
    
  Tarjeta(const Tarjeta&) = delete;
  Tarjeta operator = (const Tarjeta&) = delete;
  
  void anula_titular() { user_ = nullptr;}
    
  //Metodos observadores
  const Tipo& tipo() const {return tip_;}
  const Numero& numero() const {return num_;}
  Usuario* titular() const {return user_;}
  const Fecha& caducidad() const {return cad_;}
  const Cadena& titular_facial() const {return titular_facial_;}
  
  ~Tarjeta();
private:
  Tipo tip_;
  Numero num_;
  Usuario* user_;
  Fecha cad_;
  Cadena titular_facial_;
};

inline bool operator<(const Tarjeta& a, const Tarjeta& b)
{ return a.numero() < b.numero(); }


ostream& operator << (ostream& os , const Tarjeta& t);

#endif

#ifndef USUARIO_HPP_
#define USUARIO_HPP_

#include <unistd.h>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include "cadena.hpp"
#include "tarjeta.hpp"
#include "articulo.hpp"

class Clave{
public:
  Clave(const char* x);
  const Cadena& clave() const {return pass_;}
  
  bool verifica(const char* x) const noexcept
  { return strcmp(crypt(x, pass_.c_str()), pass_.c_str()) == 0; }

  enum Razon{CORTA, ERROR_CRYPT};
  
  class Incorrecta{
  public:
    Incorrecta(Razon r): r_(r)
    {}
    Razon razon() const {return r_;}
  private:
    Razon r_;
  };
  
private:
  Cadena pass_;
};

class Usuario{
public:
  typedef std::map<Numero, Tarjeta*> Tarjetas;
  typedef std::unordered_map<Articulo*, unsigned int> Articulos;
  typedef std::unordered_set<Cadena> Usuarios; //Para saber todos
  
  Usuario(const Cadena& id, const Cadena& nom, const Cadena& apell,
	  const Cadena& dir, const Clave& cl);
  
  Usuario(const Usuario&) = delete;
  bool operator =(const Usuario&) = delete;

  void es_titular_de(const Tarjeta& t);
  void no_es_titular_de(const Tarjeta& t);
  
  void compra(const Articulo& a, int c = 1);
  const Articulos& compra() const {return carrito_;}
  int n_articulos() const {return carrito_.size();} 
  
  const Cadena& id() const {return id_;}
  const Cadena& nombre() const {return nom_;}
  const Cadena& apellidos() const {return apell_;}
  const Cadena& direccion() const {return dir_;}
  const Tarjetas& tarjetas() const {return tar_;}

  friend ostream& operator<<(ostream& os, const Usuario& u);
  
  class Id_duplicado{
  public:
    Id_duplicado(const Cadena& a) : c_(a)
    {}

    const Cadena& idd() const { return c_;}
    
  private:
    Cadena c_;
  };

  ~Usuario();

private:
  Cadena id_, nom_, apell_, dir_;
  Clave cl_;
  Tarjetas tar_;
  Articulos carrito_;
  static Usuarios bd_;
};

void mostrar_carro(ostream& os, const Usuario& u);

#endif

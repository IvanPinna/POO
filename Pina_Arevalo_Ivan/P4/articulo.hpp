#ifndef ARTICULO_HPP_
#define ARTICULO_HPP_

//#include <iostream>
#include "cadena.hpp"
#include "fecha.hpp"
#include <set>

class Autor{
public:
  Autor(Cadena nom, Cadena apell, Cadena dir) noexcept :
    nom_(nom), apell_(apell), dir_(dir)
  {}
private:
  Cadena nom_, apell_, dir_;
};

class Articulo{
public:
  class Autores_vacios
  {};
  
  typedef std::set<Autor*>Autores;
  
  Articulo(const Cadena& ref, const Cadena& tit, const Fecha& publi,
	   double prec, const Autores& set)
    : cod_ref_(ref), titulo_(tit), f_publi_(publi), precio_(prec),
      set_(set)
  {
    if(set.empty())
      throw Autores_vacios();
  }
  
  const Cadena& referencia() const {return cod_ref_;}
  const Cadena& titulo() const {return titulo_;}
  const Fecha& f_publi() const {return f_publi_;}
  
  double precio() const {return precio_;}
  double& precio() {return precio_;}
  
  virtual void impresion_especifica(ostream& os) const noexcept = 0;
  
protected:
  Cadena cod_ref_;
  Cadena titulo_;
  Fecha f_publi_;
  double precio_;
  Autores set_;
};

//Operador de flujo
ostream& operator << (ostream& os, const Articulo& a);

class ArticuloAlmacenable : public Articulo {
public:
  ArticuloAlmacenable(const Cadena& ref, const Cadena& tit,
		      const Fecha& publi, double prec, const Autores&
		      set, unsigned stock)
    :Articulo(ref, tit, publi, prec, set), stock_(stock)
  {}
  
  unsigned stock() const {return stock_;}
  unsigned& stock() {return stock_;}

  void impresion_especifica(ostream& os) const noexcept;
 
protected:
  unsigned stock_;
};

class Libro : public ArticuloAlmacenable {
public:
  Libro(const Autores& set, const Cadena& ref, const Cadena& tit,
	const Fecha& publi, double prec, unsigned stock,int n_pag)
    : ArticuloAlmacenable(ref, tit, publi, prec,set, stock), pag_{n_pag}
  {}
  
  const int n_pag() const {return pag_;}

  void impresion_especifica(ostream& os) const noexcept;

private:
  int pag_;
};

class Cederron : public ArticuloAlmacenable {
public:
  Cederron(const Autores& set,const Cadena& ref, const Cadena& tit,
	   const Fecha& publi, double prec, unsigned stock, double MB)
    :ArticuloAlmacenable(ref, tit, publi, prec, set, stock), MB_{MB}
  {}
  
  double tam() const  {return MB_;}
  void impresion_especifica(ostream& os) const noexcept;
private:
  double MB_;
};

class LibroDigital :public Articulo {
public:
  LibroDigital(const Autores& set, const Cadena& ref, const Cadena& tit,
	       const Fecha& publi, double prec,const Fecha& exp)
     : Articulo(ref, tit, publi, prec, set), exp_{exp}
  {}
  
  const Fecha& f_expir() const {return exp_;}

  void impresion_especifica(ostream& os) const noexcept;
 
private:
  unsigned stock_;
  Fecha exp_;
};


#endif

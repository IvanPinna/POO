#ifndef PEDIDO_HPP_
#define PEDIDO_HPP_

#include "tarjeta.hpp"
#include "usuario.hpp"
#include "articulo.hpp"

class Usuario_Pedido;
class Pedido_Articulo;

class Pedido{
public:   //Necesario pasar por referencia para modificar los enlaces.
  Pedido(Usuario_Pedido& p, Pedido_Articulo& pa, Usuario& u,
	 const Tarjeta& t, const Fecha& f = Fecha());

  class Vacio{
  public:
    Vacio(const Usuario& p):p_(&p)
      {};
    
    const Usuario& usuario() const {return *p_; }
  private:
    const Usuario* p_;
  };

  class Impostor{
  public:
    Impostor(const Usuario& p):p_(&p)
      {};
    const Usuario& usuario() const {return *p_; }
    
  private:
    const Usuario* p_;
  };

  class SinStock{
  public:
    SinStock(const Articulo& a):a_(&a)
      {};
    const Articulo& articulo() const {return *a_;}
  private:
    const Articulo* a_;
  };

  
  //Metodos observadores
  int numero() const {return num_;}
  const Tarjeta* tarjeta() const  {return tarjeta_;}
  const Fecha& fecha() const {return fecha_;}
  double total() const {return total_;}

  static int n_total_pedidos() { return N_pedidos; }
private:
  static int N_pedidos;
  int num_;
  const Tarjeta* tarjeta_;
  Fecha fecha_;
  double total_;
};

ostream& operator <<(ostream& os, const Pedido& p);

#endif

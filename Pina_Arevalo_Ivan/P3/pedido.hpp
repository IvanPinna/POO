#ifndef PEDIDO_HPP_
#define PEDIDO_HPP_
#include "tarjeta.hpp"

class Pedido{
public:   //Necesario pasar por referencia para modificar los enlaces.
  Pedido(Usuario_Pedido&  a, Pedido_Articulo& b, const Usuario& u,
	 const Tarjeta& t, Fecha f = Fecha() );

  Class Vacio{
  public:
    Vacio(Const Usuario* p):p_(p)
      {};
    const Usuario* usuario() const {return p_}
  private:
    Usuario* p_;
  };
  
  //Metodos observadores
  int numero() const {return num_;}
  const Tarjeta* tarjeta() const  {return tarjeta_;}
  const Fecha& fecha() const {return fecha_;}
  double total() const {return total_;}
private:
  int N_pedidos;
  int num_;
  Tarjeta* tarjeta_;;
  Fecha fecha_;
  double total_;
};

ostream& operator <<(ostream& os, const Pedido& p);

#endif

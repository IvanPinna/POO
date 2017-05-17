3#ifndef PEDIDO_HPP_
#define PEDIDO_HPP_
#include "tarjeta.hpp"

class Pedido{
public:   //Necesario pasar por referencia para modificar los enlaces.
  Pedido(Usuario_Pedido&  up, Pedido_Articulo& pa, const Usuario& u,
	 const Tarjeta& t, const Fecha& f = Fecha() );

  Class Vacio{
  public:
    Vacio(const Usuario* p):p_(p)
      {};
    const Usuario* usuario() const {return p_}
  private:
    Usuario* p_;
  };

  Class Impostor{
  public:
    Vacio(const Usuario* p):p_(p)
      {};
    const Usuario* usuario() const {return p_}
  private:
    Usuario* p_;
  };

  Class SinStock{
  public:
    SinStock(const Usuario* a):a_(a)
      {};
    const articulo* articulo() const {return a_;}
  private:
    Articulo* a_;
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


/*TEMPORALMENTE: Definiremos aquí la clase LineaPedido*/
class LineaPedido{
public:
private:
};

#endif

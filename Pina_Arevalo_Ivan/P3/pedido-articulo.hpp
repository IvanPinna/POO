#ifndef PEDIDO_ARTICULO_HPP
#define PEDIDO_ARTICULO_HPP

#include "pedido.hpp"

class LineaPedido //FALTA IMPLEMENTAR 
{
public:
private:.
};


//Asociación bidireccional varios-a-varios con atributos de enlace entre pedido y articulo
class Pedido_Articulo
{
public:
  typedef std::map<Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido;
  typedef std::map<Pedido*, LineaPedido, OrdenaPedidos> Pedidos;
  
  void pedir(const Pedido& p, const Articulo& a, double p,
	     int c);

  void pedir( const Articulo& a, const Pedido& p, double p,
	     int c);

  const ItemsPedido& detalle(const Pedido& p)
  {return pedart_[p];} //Observa que le estas pasando la key.

  const Pedidos& ventas(const Articulo& a)
  {return artped_[a];}
  
private:
  std::map<Pedido*, ItemsPedido, OrdenaPedidos> pedart_;
  std::map<Articulo*, Pedidos, OrdenaArticulos> artped_;
};

ostream& operator <<(ostream& os, Pedido_Articulo::ItemsPedido);
ostream& operator <<(ostream& os, Pedido_Articulo::Pedidos);


#endif

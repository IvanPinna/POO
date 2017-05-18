#ifndef PEDIDO_ARTICULO_HPP
#define PEDIDO_ARTICULO_HPP

#include "pedido.hpp"
#include <iostream>

struct OrdenaArticulos
{
  bool operator()(const Articulo* a, const Articulo* b) const
  {
    return a->referencia() < b->referencia();
  }
};

struct OrdenaPedidos
{
  bool operator()(const Pedido* a, const Pedido* b) const
  {
    return a->numero() < b->numero();
  }
};

class LineaPedido //FALTA IMPLEMENTAR 
{
public:
  LineaPedido(double p, int s = 1) : p_{p}, s_{s}
  {}
  const double precio_venta() const
  {return p_;}
  const int cantidad() const
  {return s_;}
  
private:
  double p_;
  int s_;
};

ostream& operator<<(ostream& os, const LineaPedido& l);

class Pedido_Articulo
{
public:
  typedef std::map<const Articulo*, LineaPedido,
		   OrdenaArticulos> ItemsPedido;
  
  typedef std::map<const Pedido*, LineaPedido, OrdenaPedidos> Pedidos;
  
  void pedir(const Pedido& p, const Articulo& a, double pvp, int c);

  void pedir(const Articulo& a, const Pedido& p, double pvp, int c)
  { pedir(p, a, pvp, c); } 

  const ItemsPedido& detalle(const Pedido& p)
  {
    //Problema: Si la posición no existe va a crear una nueva.
    return pedart_[&p];
  } //Observa que le estas pasando la key.

  const Pedidos& ventas(const Articulo& a)
  {return artped_[&a];}

  void mostrarDetallePedidos(std::ostream& os) const;
  void mostrarVentasArticulos(std::ostream& os) const;
private:
  std::map<const Pedido*, ItemsPedido, OrdenaPedidos> pedart_;
  std::map<const Articulo*, Pedidos, OrdenaArticulos> artped_;
};

std::ostream&
operator<<(std::ostream& os, const Pedido_Articulo::ItemsPedido&);

std::ostream&
operator<<(std::ostream& os, const Pedido_Articulo::Pedidos&);

#endif

#include "pedido.hpp"
#include "usuario-pedido.hpp"
#include "pedido-articulo.hpp"

//Versión Gerardo
int Pedido::N_pedidos = 0;

Pedido::Pedido(Usuario_Pedido& up, Pedido_Articulo& pa,
	       Usuario& u, const Tarjeta& t, const Fecha& fp)
  : num_(N_pedidos + 1), tarjeta_(&t), fecha_(fp), total_(0.0)
{
  if(u.n_articulos() == 0)  throw Vacio(u);
  if(t.titular() != &u)  throw Impostor(u);
  if(t.caducidad() < fp) throw Tarjeta::Caducada(t.caducidad());

  for(auto c : u.compra() )
    if(c.first->stock() < c.second) {
      const_cast<Usuario::Articulos&>(u.compra()) . clear();
      throw SinStock(*c.first);
    }

  /*Para quitar del carrito.
       -Problema: Mientras estamos recorriendo el contenedor 
            le estamos quitando elementos.
       -Solución: recorremos una copia, mientras borramos en 
            el original*/ 
  Usuario::Articulos carro = u.compra();
  for(auto c : carro) {
    Articulo* ptrart = c.first;
    unsigned int cantidad = c.second;
    double precio = ptrart->precio();

    ptrart->stock() -= cantidad;
    pa.pedir(*this, *ptrart, precio, cantidad);
    total_ += precio * cantidad;
    u.compra(*ptrart, 0);  
  }

  up.asocia(u, *this);
  ++N_pedidos;
}


ostream& operator <<(ostream& os, const Pedido& p)
{
  return os << "Núm. pedido: " << p.numero() << std::endl
	    << "Fecha:       " << p.fecha() << std::endl
	    << "Pagado con : " << p.tarjeta()
	    << " n.º: " << p.tarjeta()->numero() << std::endl
	    << "Importe:     " << p.total()
	    << " €" << std::endl;
    
}



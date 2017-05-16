#include "pedido.hpp"

Pedido:: Pedido(Usuario_Pedido&  a,
		Pedido_Articulo& b, const Usuario& u,
		const Tarjeta& t, Fecha f = Fecha() )
{
  //Pasamos a implementar la clase de asociacion
  //usuario-pedido
}

ostream& operator <<(ostream& os, const Pedido& p)
{
  return os << "Núm. pedido: " << p.numero() << std::endl
	    << "Fecha:       " << p.fecha() << std::endl
	    << "Pagado con : " << p.tarjeta()
	    << " n.º: " p.tarjeta()->numero() << std:: endl
	    << "Importe:     " << p.total()
	    << " €" << endl;
    
};


//Versión Gerardo
int Pedido::N_pedidos = 0;
Pe

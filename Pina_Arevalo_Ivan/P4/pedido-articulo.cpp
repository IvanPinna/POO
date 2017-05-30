#include "pedido-articulo.hpp"
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const LineaPedido& l)
{
  return os << setprecision(2) << fixed << l.precio_venta() << " €\t"
	    << l.cantidad();
}

void Pedido_Articulo::
pedir(const Pedido& p, const Articulo& a, double pvp, int c)
{
  LineaPedido lp(pvp,c);

  pedart_[&p].emplace(&a, lp);
  artped_[&a].emplace(&p, lp);
}


std::ostream& operator <<(std::ostream& os,
			  const Pedido_Articulo::ItemsPedido& cos)
{
  //Tenems que mostrar todos los items que componen un pedido. 
  for(auto const& p : cos)
  {
    const Articulo *art = p.first;
    const LineaPedido lp = p.second;
    os << setprecision(2) << fixed
       << lp.precio_venta() << " € " << lp.cantidad()
       << " [" << art->referencia() << "] "
       << art->titulo() << "\n";
  }
  
  return os;
}
  
std::ostream& operator<<(std::ostream& os,
			 Pedido_Articulo::Pedidos const& p)
{
  double importeTotal = 0;

    for (auto const& par : p)
    {
        const Pedido& ped = *par.first;
        const LineaPedido& linea = par.second;

        os << ped.total() << " € " << linea.cantidad() << ' '
           << ped.fecha() << endl;

        importeTotal += linea.precio_venta() * linea.cantidad();
    }

    return os << endl << "Importe total: " << fixed
              << setprecision(2) << importeTotal << " €" << endl;
}

void Pedido_Articulo:: mostrarDetallePedidos(ostream& os) const
{
  double total{0};
  
  for(auto const& pair : pedart_)
  {
    os << "Pedido núm. " << pair.first->numero() << '\n'
       << "Cliente: " << pair.first->tarjeta()->titular()->id()
       << "\t Fecha: " << pair.first->fecha() << '\n'
       << pair.second << '\n';

    total += pair.first->total();
  }

  os << setprecision(2) << fixed << total  << " €" << '\n';

  /*
  os << "\nTOTAL VENTAS: " << setprecision(2) << fixed << total
  << '\n';*/
}


void Pedido_Articulo::mostrarVentasArticulos(ostream& os) const
{
  for(auto const& pair: artped_)
  {
    os << "Ventas de " << pair.first->referencia()
       << ' ' << pair.first->titulo() << '\n'
       << pair.second << '\n';
  }
}

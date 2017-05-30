/*
#include "usuario_pedido.hpp"

void Usuario_Pedido::asocia(const Usuario& u, const Pedido& p)
{
  //Asociar un pedido con un usuario
  usuario_pedido_[&u].insert(&p);
  pedido_usuario_[&p] = &u;
}
  
void Usuario_Pedido::asocia(const Pedido& p, const Usuario& u)
{
  asocia(u, p);
}

const Pedidos& Usuario_Pedido::pedidos(const Usuario& u) const
{
  static Pedidos map_vacio;

  auto it = usuario_pedido_.find(&u);

  return it == usuario_pedido_.end() ? map_vacio : it->second;
}

const Usuario* Usuario_Pedido::cliente(const Pedido& p) const
{
  return const_cast<Usuario_Pedido*>(this)->pedido_usuario_[&p];
}
*/

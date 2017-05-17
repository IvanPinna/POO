#ifndef USUARIO_PEDIDO_HPP_
#define USUARIO_PEDIDO_HPP_

#include "pedido.hpp"

class Usuario_Pedido{
public:
  typedef set<Pedido*> Pedidos;
  
  void asocia(const Usuario& u, const Pedido& p);
  void asocia(const Pedido& p, const Usuario& u);
  Pedidos pedidos(const Usuario& u);
  const Usuario& cliente(const Pedido& p);
private:
  map<Usuario*, Pedidos>  usuario_pedido_; //1 user += 1 pedido.
  map<Pedido*, Usuario*> pedido_usuario_;
};

#endif

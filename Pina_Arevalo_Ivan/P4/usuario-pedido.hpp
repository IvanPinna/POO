#ifndef USUARIO_PEDIDO_HPP_
#define USUARIO_PEDIDO_HPP_

#include <set>
#include <map>

using namespace std;

#include "pedido.hpp"
#include "usuario.hpp"

class Usuario_Pedido{
public:
  typedef set<const Pedido*> Pedidos;
  
  void asocia(const Usuario& u, const Pedido& p)
  {
    up_[&u].insert(&p);
    pu_[&p] = &u;
  }
  
  void asocia(const Pedido& p, const Usuario& u) { asocia(u, p); }
  
  const Pedidos& pedidos(const Usuario& u) { return up_[&u]; }
  const Usuario* cliente(const Pedido& p) { return pu_[&p]; }
  
private:
  map<const Usuario*, Pedidos> up_; //1 user += 1 pedido.
  map<const Pedido*, const Usuario*> pu_;
};

#endif

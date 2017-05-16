#ifndef USUARIO_PEDIDO_HPP_
#define USUARIO_PEDIDO_HPP_

#include <multimap>
#include <set>

class Usuario_Pedido{
public:
  typedef std::multimap<Usuario, std:: set<Pedido>>  Pedidos;
  void asocia(Usuario u, Pedido p);
  void asocia(Pedido p, Usuario u);
private:
  Pedidos almacen_;
  std::set<Usuarios*> users_;
};

#endif

#include "usuario.hpp"
#include <random>
#include <iomanip>

Usuario::Usuarios Usuario::bd_;

Usuario::Usuario(const Cadena& id, const Cadena& nom,
		 const Cadena& apell, const Cadena& dir,
		 const Clave& cl):
  id_(id), nom_(nom), apell_(apell), dir_(dir), cl_(cl)
{
  //Si el usuario ya existe, lanzará una excepción.
  if(!bd_.insert(id_).second)
    throw Id_duplicado(id_);
}

void Usuario::es_titular_de(const Tarjeta& t)
{
  if(t.titular() == this) //La tarjeta esta asociada a nosotros
    tar_[t.numero()] = const_cast<Tarjeta*>(&t);
}

void Usuario::no_es_titular_de(const Tarjeta& t)
{
  tar_.erase(t.numero());
}

void Usuario::compra(const Articulo& a, int c)
{
  if(c == 0)
    carrito_.erase(const_cast<Articulo*>(&a));
  else
    carrito_[const_cast<Articulo*>(&a)] = c;
}


Usuario::~Usuario()
{
  for (const auto& pair : tar_)
    pair.second->anula_titular();

  bd_.erase(id_);
}


Clave::Clave(const char* c)
{
  if (strlen(c) < 5)
    throw Incorrecta(Razon::CORTA);

  random_device r;
  uniform_int_distribution<size_t> dist(0, 63);

  char const MD5chars[] =
    "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  char salt[2] = { MD5chars[dist(r)], MD5chars[dist(r)] };

  char* encriptado = crypt(c, salt);

  if(encriptado == nullptr)
    throw Incorrecta(Razon::ERROR_CRYPT);

  pass_ = encriptado;
}

ostream& operator<<(ostream& os, const Usuario& u)
{
    os << u.id_ << "[" << u.cl_.clave() << "]" << u.nom_
       << u.apell_ << endl << u.dir_ << endl << "Tarjetas:" << endl;

    for (auto& t : u.tar_)
        os << *t.second << endl;

    return os;
}

void mostrar_carro(ostream& os, const Usuario& u)
{
    os << "Carrito de compra de " << u.id() << " [Artículos: "
       << u.n_articulos() << "]" << endl;

    if (u.n_articulos() == 0)
        return;

    os << " Cant. Artículo" << endl
       << setw(65) << setfill('=') << '\n'  << setfill(' ');

    for (auto const& i : u.compra())
        os << setw(4) << i.second << "   " << *(i.first) << endl;

    os << endl;
}

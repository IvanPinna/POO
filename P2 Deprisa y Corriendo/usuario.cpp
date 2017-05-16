
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <random>

#include "usuario.hpp"

using namespace std;

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

//set estatico de usuarios.
Usuario::Usuarios Usuario::st_id;

Usuario::Usuario(const Cadena& id,const Cadena& nom,const Cadena& apel,
                 const Cadena& dir,const Clave& p)
    : u_id(id), u_nom(nom), u_apell(apel), u_dir(dir), pass(p)
{
   if (!st_id.insert(id).second)
       throw Id_duplicado(u_id);
}

void Usuario::es_titular_de(const Tarjeta& t)
{
   if(t.titular() == this)
       m_tarjetas[t.numero()] = const_cast<Tarjeta*>(&t);
}

void Usuario::no_es_titular_de(Tarjeta& t)
{ m_tarjetas.erase(t.numero()); }

void Usuario::compra(const Articulo&  a, unsigned cantidad)
{
    if (cantidad == 0)
        n_art.erase(const_cast<Articulo*>(&a));
    else
        n_art[const_cast<Articulo*>(&a)] = cantidad;
}


Usuario::~Usuario()
{
    for (auto& iterador : m_tarjetas)
        iterador.second->anula_titular();

    st_id.erase(u_id);
}

ostream& operator<<(ostream& os, const Usuario& u)
{
    os << u.u_id << "[" << u.pass.clave() << "]" << u.u_nom
       << u.u_apell << endl << u.u_dir << endl << "Tarjetas:" << endl;

    for (auto& t : u.m_tarjetas)
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

    for (auto const& iterador : u.compra())
        os << setw(4) << iterador.second << "   " << *(iterador.first) << endl;

    os << endl;
}

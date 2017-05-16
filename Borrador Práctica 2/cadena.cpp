#include "cadena.hpp"
#include <stdexcept>
#include <iomanip>

Cadena::Cadena(std::size_t n, char x)
  : s_(new char[n + 1]), tam_(n)
{
  std::memset(s_, x, tam_);
  s_[tam_] = '\0';
}

Cadena::Cadena(const char* cad, std::size_t n) : tam_(strlen(cad))
{
    if (n < tam_)
      tam_ = n;
    
    s_ = new char[tam_ + 1];
    std::strncpy(s_, cad, tam_);
    s_[tam_] = '\0';
}

Cadena::Cadena(const Cadena& a, std::size_t inipos, std::size_t n)
{
  if (inipos > a.tam_) // or inipos < 0
        throw std::out_of_range("Posicion inicial fuera de rango");

  tam_ = a.tam_ - inipos;

  if (n < tam_)
    tam_ = n;

  s_ = new char[tam_ + 1];
  std::strncpy(s_, a.s_ + inipos, tam_);
  s_[tam_] = '\0';
}

Cadena::Cadena(Cadena&& a) noexcept : s_(a.s_), tam_(a.tam_)
{
  a.s_ = nullptr;
  a.tam_ = 0;
}

Cadena& Cadena::operator=(const Cadena& original)
{
  if (this == &original)
    return *this;

  if (tam_ != original.tam_) {
    // Eliminamos el contenido actual que haya en la cadena.
    delete[] s_;
    tam_ = original.tam_;
    s_ = new char[tam_ + 1];
  }
  
  std::strcpy(s_, original.s_);
  return *this;
}

Cadena& Cadena::operator=(Cadena&& nuevo)
{
  if (this == &nuevo)
    return *this;

  delete[] s_;
  
  s_ = nuevo.s_;
  tam_ = nuevo.tam_;

  nuevo.s_ = nullptr;
  nuevo.tam_ = 0;
  
  return *this;
}

Cadena& Cadena::operator+=(const Cadena& original)
{
  tam_ += original.tam_;

  // Generamos una cadena idéntica a la original
  char* aux = s_;
  s_ = new char[tam_ + 1];

  // Volcamos el contenido que haya en s_ en aux.
  std::strcpy(s_, aux);
  delete[] aux;

  std::strcat(s_, original.s_);

  return *this;
}

char Cadena::at(std::size_t n) const
{
  if (n >= tam_)
    throw std::out_of_range("Llamada invalida a la funcion at");
  
  return (*this)[n];
}

char& Cadena::at(std::size_t n)
{
  if (n >= tam_)
    throw std::out_of_range("Llamada invalida a la funcion at");
  
  return (*this)[n];
}

Cadena Cadena::substr(std::size_t indice, std::size_t tam) const
{
  // or (indice + tam) < indice
  if(indice >= tam_ or tam > (tam_ - indice))
    throw std::out_of_range("Indice superior al tamanno de "
			    "la cadena");

  return Cadena(*this, indice, tam);
}

std::ostream& operator<<(std::ostream& os, const Cadena& a)
{
  os << a.c_str();  //Enviamos al buffer el contenido de Cadena
  return os;
}

std::istream& operator>>(std::istream& is, Cadena& a)
{
  char* pal = new char[32]{'\0'};
  is >> std::setw(32) >> pal;

  // Este objeto es temporal, y se aprovecha el operador de
  // asignación con movimiento.
  a = Cadena(pal);
  delete[] pal;
  
  return is;
}

#include "cadena.hpp"

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

Cadena& Cadena::operator=(const Cadena& original)
{
  if (this == &original)
    return *this;

  if (tam_ != original.tam_) {
    delete[] s_;    //Eliminamos el contenido actual que haya en la cadena.
    tam_ = original.tam_;
    s_ = new char[tam_ + 1];
  }
  
  std::strcpy(s_, original.s_);
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
  if(indice >= tam_ or tam > (tam_ - indice)) /*or (indice + tam) < indice*/
    throw std::out_of_range("Indice superior al tamanno de la cadena");

  return Cadena(*this, indice, tam);
}

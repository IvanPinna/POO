// $Id: luhn.cpp 311 2016-04-01 19:03:07Z gerardo $
// Verifica un número de tarjeta empleando el algoritmo de Luhn
// Referencias: 
//              http://en.wikipedia.org/wiki/Luhn_algorithm
//
#include "cadena.hpp"
#include <cstddef>
#include <ccstype>
#include <algorithm>
#include <functional>


bool luhn(const Cadena& numero);

#if 0
struct EsBlanco {
  bool operator()(char c) const { return std::isspace(c);}
};

#endif

struct EsDigito // std::unary_function<char, bool> Deprecated.
{
  bool operator()(char c) const {return std::isdigit(c);}

Numero::Numero(const Cadena& num): numero_(num)
  {
                     //Genera un objeto temporal EsBlanco.
  Cadena::iterator fin = std::remove_if(numero_.begin(), numero_.end(), EsBlanco(), [](char c) {  return std::isspace(c);} );
  
  *fin = 0; // '\0' '\x0'
    
  
  if(fin != numero.end()){ //Solamente si el iterator esta en posicion distinta al final -> Ha habido modificaciones.
    Cadena sd(numero_.c_str());
    numero_ = sd;
  }

  if( std::find_if(std::begin(numero_), std::end(numero_), std::not1(std::function<bool(char)>(EsDigito())) ) != numero_.end())
    throw Incorrecto(DIGITOS);
  
  std::size_t j = numero.length();
  if(j < 13 or j >19) throw Incorrecto(LONGITUD);
  if( not luhn(numero_)) throw Incorrecto(NO_VALIDO);
}

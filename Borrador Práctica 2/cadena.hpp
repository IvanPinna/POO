/*
 * File:   Cadena.hpp
 * Author: Iván
 *
 * Created on 27 de marzo de 2017, 13:22
 */

#ifndef CADENA_HPP
#define CADENA_HPP

#include <cstring>
#include <iostream>

class Cadena
{
public:
  const static std::size_t npos = -1;

  //Los tres primeros constructores
  explicit Cadena(std::size_t n = 0, char x = ' ');
  
  Cadena(const char* cad, std::size_t n = npos);
  
  Cadena(const Cadena& a, std::size_t inipos = 0,
	 std::size_t n = npos);

  Cadena(Cadena&& a) noexcept;
  
  Cadena& operator=(const Cadena& nuevo);
  Cadena& operator=(Cadena&& nuevo);
  
  Cadena& operator+=(const Cadena& concat);
  
  char operator [] (std::size_t n) const { return s_[n]; }
  char& operator[] (std::size_t n) { return s_[n]; }
  char at(std::size_t n) const;
  char& at(std::size_t n);

  //Operador de conversión implicita
  const char* c_str() const noexcept {return s_;} 
  std::size_t length() const noexcept {return tam_; }
  Cadena substr(std::size_t inipos, std::size_t n) const;
  ~Cadena() { delete[] s_; s_ = nullptr; tam_ = 0; }

   //Iteradores
  typedef char* iterator;
  typedef const char* const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  
  typedef std::reverse_iterator<
    const_iterator> const_reverse_iterator;

  iterator begin() { return s_; }
  iterator end() { return s_ + tam_; }
  reverse_iterator rbegin() { return reverse_iterator(end()); }
  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_iterator begin() const { return s_; }
  const_iterator end() const { return s_ + tam_; }
  const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
  const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
  
  const_iterator cbegin() const { return begin(); }
  const_iterator cend() const { return end(); }

  const_reverse_iterator crbegin() const
  { return const_reverse_iterator(end()); }

  const_reverse_iterator crend() const
  { return const_reverse_iterator(begin()); }
  
private:
  char* s_;
  std::size_t tam_;
};

inline Cadena operator +(const Cadena& a, const Cadena& b)
{
  return Cadena(a) += b;
}

inline bool operator ==(const Cadena& a, const Cadena& b) noexcept
{
  return std::strcmp(a.c_str(), b.c_str()) == 0;
}

inline bool operator!=(const Cadena& a, const Cadena& b) noexcept
{
  return !(a == b);
}

inline bool operator<(const Cadena& a, const Cadena& b) noexcept
{
  return std::strcmp(a.c_str(), b.c_str()) < 0;
}

inline bool operator>(const Cadena& a, const Cadena& b) noexcept
{
  return b < a;
}

inline bool operator<=(const Cadena& a, const Cadena& b) noexcept
{
  return !(b < a);
}

inline bool operator>=(const Cadena& a, const Cadena& b) noexcept
{
  return !(a < b);
}

// Operadores de flujo
std::ostream& operator<<(std::ostream& os, const Cadena& a);
std::istream& operator>>(std::istream& is, Cadena& a);

#endif


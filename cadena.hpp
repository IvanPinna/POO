
/*
 * File:   Cadena.hpp
 * Author: ivan
 *
 * Created on 27 de marzo de 2017, 13:22
 */

#ifndef CADENA_HPP
#define CADENA_HPP

#include <cstring>
#include <stdexcept>

class Cadena{
public:
    const static size_t npos = -1;
    Cadena(int n = 0, char x = '\0');   //Los tres primeros constructores
    Cadena(const char* cad);
    Cadena(const Cadena& a);
    Cadena(int, const char*);
    Cadena(const Cadena& a, int, int);
    Cadena& operator =(const Cadena&);
    Cadena& operator +=(const Cadena&);
    char operator [] (size_t n) const;  //Acceso al char en modo lectura.
    char& operator[] (size_t n);        //Acceso lectura/escritura.
    operator const char*() const {return s_;}
    size_t length() const noexcept {return tam_; }
    Cadena substr(size_t, size_t);
    ~Cadena();
private:
    char* s_;
    unsigned int tam_;
};

Cadena operator +(const Cadena& a, const Cadena& b);
bool operator ==(const Cadena& a, const Cadena& b) noexcept;
bool operator !=(const Cadena& a, const Cadena& b) noexcept;
bool operator >(const Cadena& a, const Cadena& b) noexcept;
bool operator <(const Cadena& a, const Cadena& b) noexcept;
bool operator >=(const Cadena& a, const Cadena& b) noexcept;
bool operator >=(const Cadena& a, const Cadena& b) noexcept;
#endif


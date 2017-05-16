#include "cadena.hpp"

Cadena::Cadena(int n, char x):tam_(n), s_(new char[n + 1])
{
    if(x != '\0')
    {
        for(int i = 0; i < n; ++i)
            s_[i] = x;
    }
    else
    {
        for(int i = 0; i < n; ++i)
            s_[i] = ' ';
    }
    s_[n] = '\0';
}

Cadena::Cadena(const char* cad)
{
    tam_ = strlen(cad);
    s_ = new char[tam_ + 1];
    strcpy(s_, cad);
}

Cadena::Cadena(const Cadena& a)
{
    tam_ = a.tam_;
    s_ = new char[tam_ + 1];
    strcpy(s_, a.s_);
}

Cadena::Cadena(int n, const char* cad)
{
    if(strlen(cad) < (unsigned)n)
    {
        s_ = new char[n + 1];
        tam_ = n;
    }
    else
    {
        s_ = new char[strlen(cad) + 1];
        tam_ = strlen(cad);
    }
    for(int i = 0; i < n && cad[i] != '\0'; ++i)
    {
        s_[i] = cad[i];
    }

    s_[strlen(s_) + 1] = '\0';
}

Cadena::Cadena(const Cadena& a, int inicio, int longitud)
{
    if((unsigned)inicio > a.tam_ or inicio < 0)
        throw std::out_of_range("Posicion inicial fuera de rango");

    if(a.tam_ > longitud)   //No habra problemas de espacio
    {
        s_ = new char[longitud + 1];
        for(int i = 0; i < longitud; ++i)
            s_[i] = a.s_[i];

        s_[longitud + 1] = '\0';
    }
    else
    {
        int tam = std::strlen(a.s_) - inicio + 1;
        s_ = new char[tam];

        for(int i = 0; i < tam; ++i)
            s_[i] = a.s_[inicio + i];
    }
}

Cadena& Cadena::operator =(const Cadena& original)
{
    delete[] s_;    //Eliminamos el contenido actual que haya en la cadena.
    int longitud = strlen(original.s_) + 1;

    s_ = new char[longitud];

    for(int i = 0; i < longitud; ++i)
        s_[i] = original.s_[i];

    s_[longitud - 1] = '\0';

    return *this;
}

Cadena& Cadena::operator +=(const Cadena& original)
{
    char aux[tam_ + 1];
    int tam_total = tam_ + original.tam_;

    strcpy(aux, s_);    //volcamos el contenido que haya en s_ en aux.
    delete[] s_;

    s_ = new char[tam_total + 1];

    for(int i = 0; i < tam_; ++i)
        s_[i] = aux[i];
    for(int i = 0; i < original.tam_; ++i)
        s_[i + tam_] = original.s_[i];
    s_[tam_total] = '\0';

    return *this;
}

Cadena Cadena::substr(size_t indice, size_t tam)
{
    if(indice >= tam or (indice + tam) > tam_ or (indice + tam) < indice)
        throw std::out_of_range("Indice superior al tamanno de la cadena");

    return Cadena(*this, indice, tam);
}

Cadena::~Cadena()
{
    delete[] s_;    //Liberamos el espacio ocupado por la cadena de caracteres.
}

Cadena operator +(const Cadena& a, const Cadena& b)
{
    Cadena resultado(a);
    resultado += b;

    return resultado;
}

bool operator ==(const Cadena& a, const Cadena& b) noexcept
{
    bool res = true;

    if(a.length() == b.length())
    {
        if(!strcmp(a,b))    //Sobrecarga del operador const *char
            res = false;
    }
    else
        res = false;

    return res;
}

bool operator !=(const Cadena& a, const Cadena& b) noexcept
{
    return !(a == b);
}

bool operator <(const Cadena& a, const Cadena& b) noexcept
{
    size_t minimo;

    if(a.length() < b.length())
        minimo = a.length();
    else
        minimo = b.length();

    for(int i = 0; i < minimo; ++i)
    {
        if(a[i] < b[i])
            return true;
        else
            return false;
    }

    return a.length() < b.length();
}

bool operator >(const Cadena& a, const Cadena& b) noexcept
{
    return b < a;
}

bool operator >=(const Cadena& a, const Cadena& b) noexcept
{
    return !(a < b);
}

bool operator <=(const Cadena& a, const Cadena& b) noexcept
{
    return !( a > b);
}


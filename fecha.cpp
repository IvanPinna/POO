#include "fecha.hpp"
#include <iomanip>

Fecha::Fecha(int d, int m, int a): dia{d}, mes{m}, anno{a}
{
    time_t tiempo_calendario = time(nullptr);
    tm* tiempo_descompuesto = localtime(&tiempo_calendario);
    
    if(dia == 0)
        dia = tiempo_descompuesto->tm_mday;
    if(mes == 0)
        mes = tiempo_descompuesto->tm_mon + 1;
    if(anno == 0)
        anno = tiempo_descompuesto->tm_year + 1900;
    
    if(valida())
        cout << "La fecha es valida" << endl;
    else
        cout << "Fecha invalida" << endl;
}

//Falta terminarla
Fecha::Fecha(const char* cadena)
{
    sscanf(cadena, "%d/%d/%d", &dia, &mes, &anno);
}

 char* Fecha::cadena() //utiliza la funcion strftime
 {
     char* fecha;
     const char *dias[] = {"domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado"};
     const char *meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
     
    time_t tiempo_calendario = time(nullptr);
    tm* tiempo_descompuesto = localtime(&tiempo_calendario);
   
    tiempo_descompuesto->tm_mday = dia;
    tiempo_descompuesto->tm_mon = mes - 1;
    tiempo_descompuesto->tm_year = anno;
    
    sprintf(fecha, "%s %d de %s de %d", dias[tiempo_descompuesto->tm_wday], dia ,meses[tiempo_descompuesto->tm_mon], anno);
    
    return fecha;
 }


Fecha& Fecha::operator +=(const int dias)
{
    time_t inicializador = time(nullptr);
    tm* t_usuario = localtime(&inicializador);
    
    t_usuario->tm_mday = dia + dias;
    t_usuario->tm_mon = mes  - 1;  
    t_usuario->tm_year = anno;
    
    time_t generado = mktime(t_usuario);
    tm resultante = *localtime(&generado);
    
    dia = resultante.tm_mday;
    mes = resultante.tm_mon + 1;
    anno = resultante.tm_year;

    return *this;
}

Fecha& Fecha::operator -=(const int dias)
{
   return *this += -dias;
}

Fecha& Fecha::operator ++()
{
  return  *this += 1;
}

Fecha Fecha::operator ++(int)
{
  Fecha resultado = *this;  //copiar();
    dia += 1;
    return resultado;
}

Fecha& Fecha::operator --()
{
    return *this += -1;
}

Fecha Fecha::operator --(int)
{
  Fecha resultado = *this; //copiar();
    dia += -1;
    return resultado;
}

Fecha Fecha::operator +(int dias) const
{
    Fecha resultado = *this;
    resultado += dias;
    return resultado;
}

Fecha Fecha::operator -(int dias) const 
{
    Fecha resultado = *this;
    resultado += dias;
    return resultado;
}

inline void Fecha::mostrar()
{
    cout << dia << "/" << mes << "/" << anno << endl;
}

bool Fecha::valida()
{
    bool resultado = true;
    
    //Objeto creado por el usuario
    time_t inicializador = time(nullptr);
    tm* t_usuario = localtime(&inicializador);
    
    t_usuario->tm_mday = dia;
    t_usuario->tm_mon = mes  - 1;  
    t_usuario->tm_year = anno;
    
    //Generando un objeto a través del sistema para compararlo con los datos que ha introducido el usuario.
    time_t generado = mktime(t_usuario);
    tm resultante = *localtime(&generado);
    
    if(dia != resultante.tm_mday)
    {
        resultado = false;
        cout << "Error en el dia" << endl;
    }
    
    if(mes != resultante.tm_mon + 1)   //Hay que tener en cuenta que mktime va de 0 a 11 en los meses
    {
        resultado = false;
        cout << "Error en el mes" << endl;
    }
    
    if(anno != resultante.tm_year)
    {
        resultado = false;
        cout << "Error en el anno" << endl;
    }
    
    if(anno < AnnoMinimo || anno > AnnoMaximo)
        resultado = false;
    
    return resultado;
}

/*Fecha Fecha::copiar()
{
   Fecha resultado;
   resultado.dia = dia;
   resultado.mes = mes;
   resultado.anno = anno;
   
   return resultado;
}*/


inline bool operator ==( const Fecha& a, const Fecha& b)
{
    bool resultado = true;
    if(a.dia_() != b.dia_() || a.mes_() != b.mes_() || a.anno_() != b.anno_())
        resultado = false;
    return resultado;
}

inline bool operator !=(const Fecha& a, const Fecha& b)
{
    return !(a == b);
}

inline bool operator <(const Fecha& a, const Fecha& b)
{
    bool resultado = true;
    
    if(a.anno_() < b.anno_())
        resultado = false;
    else if(a.mes_() < b.mes_())
        resultado = false;
    else if(a.dia_() < b.dia_())
        resultado = false;
    
    return resultado;
}

inline bool operator >(const Fecha& a, const Fecha& b)
{
    return a < b;
}

inline bool operator <=(const Fecha& a, const Fecha& b)
{
    return !(b < a);
}

inline bool operator >=(const Fecha& a, const Fecha& b)
{
    return !(a < b);
}

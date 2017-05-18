#include "fecha.hpp"
#include <iomanip>

void Fecha::valida()
{
    tm yo_cal = {};

    yo_cal.tm_mday = dia_;
    yo_cal.tm_mon = mes_  - 1;  
    yo_cal.tm_year = anno_ - 1900;
    yo_cal.tm_isdst = -1;
    
    //Generando un objeto a través del sistema para compararlo con
    // los datos que ha introducido el usuario.
    mktime(&yo_cal);
    
    if(dia_ != yo_cal.tm_mday)
      throw Invalida("Día inválido");

    //Hay que tener en cuenta que mktime va de 0 a 11 en los mes_es
    if(mes_ != yo_cal.tm_mon + 1)
      throw Invalida("Mes_ inválido");
    
    if(anno_ != yo_cal.tm_year + 1900)
          throw Invalida("Año inválido");
    
    if(anno_ < AnnoMinimo || anno_ > AnnoMaximo)
      throw Invalida("Año fuera de rango");
}

Fecha::Fecha(int d, int m, int a): dia_{d}, mes_{m}, anno_{a}
{
    time_t tiempo_calendario = time(nullptr);
    tm* tiempo_descompuesto = localtime(&tiempo_calendario);
    
    if(dia_ == 0)
        dia_ = tiempo_descompuesto->tm_mday;
    if(mes_ == 0)
        mes_ = tiempo_descompuesto->tm_mon + 1;
    if(anno_ == 0)
        anno_ = tiempo_descompuesto->tm_year + 1900;
    
    valida();
}


Fecha::Fecha(const char* cadena)
{  
  int conversiones = sscanf(cadena, "%d/%d/%d",
			    &dia_, &mes_, &anno_);
  
  if(conversiones != 3) 
    throw Invalida("Error en conversion de cadena a fecha"); 
 
  time_t tiempo_calendario = std::time(nullptr);
  tm* tiempo_descompuesto = localtime(&tiempo_calendario);

  if (dia_ == 0)
    dia_ = tiempo_descompuesto->tm_mday;
  
  if (mes_ == 0)
    mes_ = tiempo_descompuesto->tm_mon + 1;
  
  if (anno_ == 0)
    anno_ = tiempo_descompuesto->tm_year + 1900;
  
  valida();   
}

char const* Fecha::cadena() const //utiliza la funcion strftime
{
  static const char *dias[] =
    {"domingo", "lunes", "martes", "miércoles",
     "jueves", "viernes", "sábado"};
  
  static const char *meses[] =
    {"enero", "febrero", "marzo", "abril", "mayo", "junio",
     "julio", "agosto", "septiembre", "octubre", "noviembre",
     "diciembre"};
     
  tm yocal = {};
   
  yocal.tm_mday = dia_;
  yocal.tm_mon = mes_ - 1;
  yocal.tm_year = anno_ - 1900;
  yocal.tm_isdst = -1;

  mktime(&yocal);

  static char fecha[36];
     
  sprintf(fecha, "%s %d de %s de %d", dias[yocal.tm_wday],
	  dia_, meses[mes_ - 1], anno_);
    
  return fecha;
}

long int operator-(const Fecha& a, const Fecha& b)
{
  static const int seg_dias =  60 * 60 * 24;

  tm tma = {}, tmb = {};

  tma.tm_isdst = -1;
  tma.tm_isdst = -1;

  tma.tm_mday = a.dia_;
  tma.tm_mon = a.mes_ - 1;
  tma.tm_year = a.anno_ - 1900;

  tmb.tm_mday = b.dia_;
  tmb.tm_mon = b.mes_ - 1;
  tmb.tm_year = b.anno_ - 1900;

  return (mktime(&tma) - mktime(&tmb)) / seg_dias;
}

Fecha& Fecha::operator+=(const int dias)
{
  tm t_usuario = {};
    
  t_usuario.tm_mday = dia_ + dias;
  t_usuario.tm_mon = mes_  - 1;  
  t_usuario.tm_year = anno_;
  t_usuario.tm_isdst = -1;
    
  mktime(&t_usuario);
    
  dia_ = t_usuario.tm_mday;
  mes_ = t_usuario.tm_mon + 1;
  anno_ = t_usuario.tm_year;

  valida();
  
  return *this;
}

ostream& operator <<(ostream& os, const Fecha& a)
{
  return os << a.cadena();
}

istream& operator>>(istream& is, Fecha& a)
{
  char* buffer = new char[11]{'\0'};
  int dia(-1), mes(-1), anno(-1);
  
  is >> setw(11) >> buffer;  // Asignamos el flujo a buffer.
  sscanf(buffer, "%2d/%2d/%4d", &dia, &mes, &anno);
  
  try{
    a = Fecha(dia, mes, anno);
  } catch(...){
    if (is)
      is.setstate(std::ios_base::failbit);

    // Must the exception be thrown or not? The test auto
    // doesn't catch it in the "Fecha no valid" case.
    throw;
  }
    
  return is;
}


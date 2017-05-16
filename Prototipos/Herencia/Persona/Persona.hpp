
//Clase base Persona
class Persona{
public:
  Persona(char* n, int e):nombre{n}, edad{e}
  {}

  const char* LeerNombre() const
  {return nombre;}
  
  int LeerEdad() const
  {return edad;}
  
  void CambiarNombre(char* n)
  {nombre = n;}
  
  void CambiarEdad(int e)
  {edad = e;}
  
protected:
  char* nombre;
  int edad;
};

//Clase derivada Empleado
class Empleado: public Persona{
public:
  Empleado(char* n, int e, float s):salarioAnual{s}
  {
    Persona(n, e);
  }
  
  float LeerSalario() const
  {return salarioAnual;}

  void CambiarSalario(const float s)
  {salarioAnual = s;}
protected:
  float salarioAnual;
};

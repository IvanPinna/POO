#include <iostream>
#include "Persona.hpp"

using namespace std;

int main()
{
  Persona p("Antonio", 20);
  Empleado x("Ivan", 23, 30000);
  
  cout << p.LeerNombre() << endl;
  cout << x.LeerNombre() << endl;
  cout << x.LeerSalario() << endl;
}

#include <iostream>

class VehiculoRodante{
public:
  void set_ruedas(int num)
  {mRuedas = num;}

  int get_ruedas()
  {return mRuedas;}

  void set_pasajeros(int pasajeros)
  {mPasajeros = pasajeros;}

  int get_pasajeros()
  {return mPasajeros;}

private:
  int mRuedas;
  int mPasajeros;
};


class Camion : public VehiculoRodante{
public:
  void set_carga(int size)
  {mCarga = size;}

  int get_carga()
  {return mCarga;}

  void Mostrar();

private:
  int mCarga;
};


void Camion::Mostrar(void)
{
 std::cout << "ruedas: " << this->get_ruedas() << std::endl;
 std::cout << "pasajeros: " << this->get_pasajeros() << std::endl;
 std::cout << "Capacidad de carga en pies cúbicos: " << this->get_carga() << std::endl;
}


enum tipo {deportivo, berlina, turismo};

// Definición de una clase 'Automovil' derivada de la clase base 'VehiculoRodante'.
class Automovil : public VehiculoRodante
{
public:
 void set_tipo(tipo t)
 {
   mTipoDeAutomovil = t;
 }

enum tipo get_tipo(void)
 {
   mTipoDeAutomovil;
 };

void Mostrar(void);

private:
 enum tipo mTipoDeAutomovil;
};

void Automovil::Mostrar(void)
{
 std::cout << "ruedas: " << this->get_ruedas() << std::endl;
 std::cout << "pasajeros: " << this->get_pasajeros() << std::endl;
 std::cout << "tipo: ";

 switch(this->get_tipo())
 { 
   case deportivo:
    std::cout << "deportivo";
    break;

   case berlina: 
    std::cout << "berlina";
    break;

   case turismo: 
    std::cout << "turismo";
  }
 std::cout << std::endl;
}



int main(void)
{
  Camion Camion1;
  Camion Camion2;
  Automovil Automovil1;

  Camion1.set_ruedas(18);
  Camion1.set_pasajeros(2);
  Camion1.set_carga(3200);

  Camion2.set_ruedas(6);
  Camion2.set_pasajeros(3);
  Camion2.set_carga(1200);

  Camion1.Mostrar();
  std::cout << std::endl;
  Camion2.Mostrar();
  std::cout << std::endl;

  Automovil1.set_ruedas(4);
  Automovil1.set_pasajeros(6);
  Automovil1.set_tipo(tipo::deportivo);

  Automovil1.Mostrar();

  return 0;
}

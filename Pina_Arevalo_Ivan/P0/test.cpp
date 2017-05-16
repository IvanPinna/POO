#include <iostream>

#include "fecha.hpp"

using namespace std;

int main()
{
  try {
    Fecha f;
    std::cout << (f + 3) << std::endl;

    Fecha g("12/0/0");
    std::cout << (g - f) << std::endl;
    
  } catch (Fecha::Invalida const& e) {
    std::cerr << e.por_que() << std::endl;
  } catch (std::exception const& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Error desconocido" << std::endl;
  }

  return 0;
}

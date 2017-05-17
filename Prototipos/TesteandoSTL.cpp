#include <string>
#include <set>
#include <iterator>
#include <iostream>

/*
using namespace std; // para set y multiset

int main() {
  set<int> valores;
  ifstream archi( "datos.txt");
  istream_iterator<int> i(archi);
  istream_iterator<int> f;
  while( i != f)
    valores.insert(i++ );

  archi.close();
  copy( valores.begin(), valores.end(), // mostrar el. por pant.
	ostream_iterator<int>( cout, " " ) );

  set<int>::iterator p = valores.find( 0 ); //buscar elto. en estructura
  if( p != valores.end() )
    cout << "\nEl valor 0 esta en el archivo\n";
  else
    cout << "\nEl valor 0 no esta en el archivo\n";

  multiset<int> multivalores; // comparar con multiset
  archi.open( "datos.txt");
  istream_iterator<int> j(archi);
  while( j != f)
    multivalores.insert(j++ );
  archi.close();

  copy( multivalores.begin(),
	multivalores.end(),
	ostream_iterator<int>( cout, " " ));
  
  cout << "\nEl valor 0 esta " << multivalores.count( 0 )
       << " veces en el archivo\n";
  multivalores.erase( 2 ); // eliminar un elemento
  copy( multivalores.begin(), multivalores.end(),
	ostream_iterator<int>( cout," " ) );
  return 0;
} */

using namespace std;

int main()
{
  set<string> palabras;
  string palabra;

  int i{0};
  while(i < 6){
    cin >> palabra;
    palabras.insert(palabra);
    ++i;
  }

  
  /*for(auto  i: palabras)
    cout << *i << endl;*/
  copy(palabras.begin(), palabras.end(),
       ostream_iterator<string>(cout, "\n"));
}


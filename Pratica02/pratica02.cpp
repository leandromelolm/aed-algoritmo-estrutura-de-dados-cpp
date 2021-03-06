/*
 * pratica02.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: lmelo
 */

#include <iostream>
#include "veiculo.h"

using namespace std;

int main()
{
	cout<<"Prática 02 - Métodos Virtuais e Herança"<<endl;
/*
	Veiculo *v1 = new Veiculo("v1"); //Erro de compilação. O tipo "Veiculo" deve implementar o método virtual puro "Veiculo::mover"
	Veiculo v2 ("v2"); //Erro de compilação. Veiculo deve implementar o metodo virtual "Veiculo::mover"
	Terrestre tr1("tr1");
	tr1.getCapacidadeMaxima();

	Aquatico aq1("aq1");
	Aereo ar1("ar1");
*/


/*
	// Erro de compilação. precisa de cast
	Veiculo * terr, *aqua,*aereo;
	terr = new Terrestre("VT1");
	terr->setCapacidadeMaxima(45);
*/

/*
	// Como usar cast
	dynamic_cast<NovoTipo>(var)->metodo();
	Superclasse * ponteiro = new Subclasse();
	((Subclasse *)ponteiro)->metodoSubclasse();
*/

	Veiculo *terr = new Terrestre("VT1");
//	((Terrestre *) terr)->setCapacidadeMaxima(45); //Devido ao uso de herança virtual, o compilador não permite casts estáticos da superclasse Veiculo para as subclasse virtual Terrestre.
	dynamic_cast<Terrestre *>(terr)->setCapacidadeMaxima(45);

	Veiculo *aqua =new Aquatico("VQ1");
//	((Aquatico *)aqua)->setCargaMaxima(12.5); //Devido ao uso de herança virtual, o compilador não permite casts estáticos da superclasse Veiculo para as subclasse virtual  Aquatico
	dynamic_cast<Aquatico *>(aqua)->setCargaMaxima(12.5);

	Veiculo *aereo = new Aereo("VA1");
	((Aereo *)aereo)->setVelocidadeMaxima(1040.5);

	//Parte 4: Trabalhando com métodos virtuais
	cout<<endl;
	terr->mover();
	aqua->mover();
	aereo->mover();

	//Parte 4: Passo 6 destrua os objetos criados na função main() usando delete .

	delete(terr);
	delete(aqua);
	delete(aereo);

	/*
	 * Passo 7: Criando o ponteiro Veiculo * anfi na função main() de pratica2.cpp.
		Inicialize esse ponteiro com uma instância de Anfibio usando new . Chame o método
		mover() dessa instância em seguida.
	 * */
    Veiculo * anfi = new Anfibio("VANFIBIO");
    dynamic_cast<Anfibio *>(anfi)->mover();
    delete(anfi);


return 0;

}

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
	cout<<"Prática 02"<<endl;
	cout<<endl;
	/*
	Veiculo *v1 = new Veiculo("v1");
	Veiculo v2 ("v2");
	Terrestre tr1("tr1");
	tr1.getCapacidadeMaxima();

	Aquatico aq1("aq1");
	Aereo ar1("ar1");
	*/

/*
// Erro de Compilação
	Veiculo * terr, *aqua,*aereo;
	terr = new Terrestre("VT1");
	terr->setCapacidadeMaxima(45);
*/

//	cast
//	Superclasse * ponteiro = new Subclasse();
//	((Subclasse *)ponteiro)->metodoSubclasse();

	Veiculo *terr = new Terrestre("VT1");
	((Terrestre *) terr)->setCapacidadeMaxima(45);

	Veiculo *aqua =new Aquatico("VQ1");
	((Aquatico *)aqua)->setCargaMaxima(12.5);

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


return 0;

}


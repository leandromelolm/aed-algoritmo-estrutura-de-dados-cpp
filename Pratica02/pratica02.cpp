/*
 * pratica02.cpp
 *
 *  Created on: 22 de abr. de 2021
 *      Author: melo
 */

#include <iostream>

#include "veiculo.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"");
    cout << "Prática sobre herança" << endl<<endl;
    /**Construtores iniciais*/
    //Veiculo v1("normal");
    //Aquatico aq1("aquatico");
    //Terrestre t1("terrestre");
    //Aereo a1("aereo");
    Veiculo * terr = new Terrestre("VT1");
    //((Terrestre *) terr) ->setCapacidadeMax(45);
    dynamic_cast<Terrestre*> (terr) ->setCapacidadeMax(45);
    /**Chamada inicial do método mover*/
    //terr->mover();
    //((Terrestre *) terr)->mover();
    dynamic_cast<Terrestre*> (terr) ->mover();
    Veiculo * aqua = new Aquatico("VQ1");
    //((Aquatico *) aqua) -> setCargaMax(12.5);
    dynamic_cast<Aquatico*> (aqua) -> setCargaMax(12.5);
    /**Chamada inicial do método mover*/
    //aqua->mover();
    //((Aquatico *) aqua)->mover();
    dynamic_cast<Aquatico*> (aqua) -> mover();
    Veiculo * aereo = new Aereo("VA1");
    //((Aereo *) aereo) ->setVelocidadeMax(1040.5);
    dynamic_cast<Aereo*> (aereo) -> setVelocidadeMax(1040.5);
    /**Chamada inicial do método mover*/
    //aereo->mover();
    //((Aereo *) aereo)->mover();
    dynamic_cast<Aereo*> (aereo) -> mover();
    Veiculo * anfi = new Anfibio("VAN1");
    dynamic_cast<Anfibio*> (anfi) -> mover();
    delete(aereo);
    delete(aqua);
    delete(terr);
    delete(anfi);
    /**Chamada inicial de criação e de métodos*/
    //terr = new Terrestre("VT1");
    //terr->setCapacidadeMax(45);
    //aqua = new Aquatico("AQ1");
    //aqua->setCargaMax(12.5);
    //aereo = new Aereo("VA1");
    //aereo->setVelocidadeMax(1040.5);
    return 0;

}


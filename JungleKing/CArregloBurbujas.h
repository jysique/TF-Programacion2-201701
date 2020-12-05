#pragma once
using namespace System::Drawing;
#include "CBurbuja.h"
#include <cstdlib>
#include <ctime>
#include <vector>
class CArregloBurbuja { //01-07-2017 NIVEL ACUATICO YSIQUE
private:
	CBurbuja nburbuja; //01-07-2017 NIVEL ACUATICO YSIQUE
	std::vector <CBurbuja> listaBurbuja; //01-07-2017 NIVEL ACUATICO YSIQUE
public:
	CArregloBurbuja() { } //01-07-2017 NIVEL ACUATICO YSIQUE
	~CArregloBurbuja() { } //01-07-2017 NIVEL ACUATICO YSIQUE

	void agregarBurbuja(int posicionX, int posicionY, int desplazamientoX, int desplazamientoY, int direccionY, int ancho, int alto, int idSpritex, //01-07-2017 NIVEL ACUATICO YSIQUE
		int idSpritey) { //01-07-2017 NIVEL ACUATICO YSIQUE
		nburbuja = CBurbuja(posicionX, posicionY, desplazamientoX, desplazamientoY, direccionY, ancho, alto, idSpritex, idSpritey); //01-07-2017 NIVEL ACUATICO YSIQUE
		listaBurbuja.push_back(nburbuja); //01-07-2017 NIVEL ACUATICO YSIQUE
	}
	void dibujarBurbuja(Graphics ^grBurbuja, Bitmap ^bmpBurbuja, Rectangle aVisible) { //01-07-2017 NIVEL ACUATICO YSIQUE
		for (int i = 0; i < listaBurbuja.size(); i++) { //01-07-2017 NIVEL ACUATICO YSIQUE
			listaBurbuja[i].dibujarBurbuja(grBurbuja, bmpBurbuja, aVisible); //01-07-2017 NIVEL ACUATICO YSIQUE
		}
	}
	void mover() { //01-07-2017 NIVEL ACUATICO YSIQUE
		for (int i = 0; i < listaBurbuja.size(); i++) { //01-07-2017 NIVEL ACUATICO YSIQUE
			listaBurbuja[i].get_desplazamientoX(); //01-07-2017 NIVEL ACUATICO YSIQUE
			listaBurbuja[i].get_desplazamientoY(); //01-07-2017 NIVEL ACUATICO YSIQUE
			listaBurbuja[i].mover(); //01-07-2017 NIVEL ACUATICO YSIQUE
		}
	}
	void eliminarBurbuja(int posicionBurbuja) { //01-07-2017 NIVEL ACUATICO YSIQUE
		listaBurbuja.erase(listaBurbuja.begin() + posicionBurbuja); //01-07-2017 NIVEL ACUATICO YSIQUE
	}
	int getListaBurbujaTamaño() { //01-07-2017 NIVEL ACUATICO YSIQUE
		return listaBurbuja.size(); //01-07-2017 NIVEL ACUATICO YSIQUE
	} 
	CBurbuja getBurbujaEspecifico(int posicionBurbuja) { //01-07-2017 NIVEL ACUATICO YSIQUE
		return listaBurbuja[posicionBurbuja]; //01-07-2017 NIVEL ACUATICO YSIQUE
	}
	void DetectarBurbujaFinal(int altomaximo) { //01-07-2017 NIVEL ACUATICO YSIQUE
		for (int i = 0; i < listaBurbuja.size(); i++) { //01-07-2017 NIVEL ACUATICO YSIQUE
			if (listaBurbuja[i].DestruirFinal(altomaximo)) { //01-07-2017 NIVEL ACUATICO YSIQUE
				listaBurbuja.erase(listaBurbuja.begin() + i); //01-07-2017 NIVEL ACUATICO YSIQUE
			}
		}
	}
};

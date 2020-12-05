#pragma once
using namespace System::Drawing;
#include "CTiburon.h"
#include <cstdlib>
#include <ctime>
#include <vector>
class CArregloTiburon{ //01-07-2017 NIVEL ACUATICO YSIQUE
private:
	CTiburon ntiburon; //01-07-2017 NIVEL ACUATICO YSIQUE
	std::vector <CTiburon> listaTiburon;//01-07-2017 NIVEL ACUATICO YSIQUE
public:
	CArregloTiburon() { }
	~CArregloTiburon() { }

	void agregarTiburon(int posicionX, int posicionY, int desplazamientoX, int desplazamientoY, int direccionY, int ancho, int alto, //01-07-2017 NIVEL ACUATICO YSIQUE
		int idSpriteX, int idSpriteY) { //01-07-2017 NIVEL ACUATICO YSIQUE
		ntiburon = CTiburon(posicionX, posicionY, desplazamientoX, desplazamientoY, direccionY, ancho, alto, idSpriteX, idSpriteY); //01-07-2017 NIVEL ACUATICO YSIQUE
		listaTiburon.push_back(ntiburon); //01-07-2017 NIVEL ACUATICO YSIQUE
	}
	void dibujarTiburon(Graphics ^grTiburon, Bitmap ^bmpTiburon, Rectangle aVisible) { //01-07-2017 NIVEL ACUATICO YSIQUE
		for (int i = 0; i < listaTiburon.size(); i++) { //01-07-2017 NIVEL ACUATICO YSIQUE
			listaTiburon[i].dibujarTiburon(grTiburon, bmpTiburon, aVisible); //01-07-2017 NIVEL ACUATICO YSIQUE
		}
	}
	void mover() { //01-07-2017 NIVEL ACUATICO YSIQUE
		for (int i = 0; i < listaTiburon.size(); i++) { //01-07-2017 NIVEL ACUATICO YSIQUE
			listaTiburon[i].get_desplazamientoX(); //01-07-2017 NIVEL ACUATICO YSIQUE
			listaTiburon[i].get_desplazamientoY(); //01-07-2017 NIVEL ACUATICO YSIQUE
			listaTiburon[i].mover(); //01-07-2017 NIVEL ACUATICO YSIQUE
		}
	}
	void EliminarTiburon(int posicionTiburon) { //01-07-2017 NIVEL ACUATICO YSIQUE
		listaTiburon.erase(listaTiburon.begin() + posicionTiburon); //01-07-2017 NIVEL ACUATICO YSIQUE
	}
	int getListaTiburonTamaño() { //01-07-2017 NIVEL ACUATICO YSIQUE
		return listaTiburon.size(); //01-07-2017 NIVEL ACUATICO YSIQUE
	}
	CTiburon getTiburonEspecifico(int posicionTiburon) { //01-07-2017 NIVEL ACUATICO YSIQUE
		return listaTiburon[posicionTiburon]; //01-07-2017 NIVEL ACUATICO YSIQUE
	}
	void DetectarTiburonFinal(int anchoFormulario) { //01-07-2017 NIVEL ACUATICO YSIQUE
		for (int i = 0; i < listaTiburon.size(); i++) { //01-07-2017 NIVEL ACUATICO YSIQUE
			if (listaTiburon[i].DestruirFinal(anchoFormulario)) { //01-07-2017 NIVEL ACUATICO YSIQUE
				listaTiburon.erase(listaTiburon.begin() + i); //01-07-2017 NIVEL ACUATICO YSIQUE
			}
		}
	}
};


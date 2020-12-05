#pragma once
#include<vector>
#include"CEnemigoNativo.h"//01-07-2017 NIVEL RESCATE
using namespace std;
class CArregloEnemigoNativo {//01-07-2017 NIVEL RESCATE
private:
	vector<CEnemigoNativo> arregloEnemigosNativos;//01-07-2017 NIVEL RESCATE
	CEnemigoNativo nuevoEnemigoNativo;//01-07-2017 NIVEL RESCATE

public:
	CArregloEnemigoNativo() {

	}
	~CArregloEnemigoNativo() {

	}
	void AgregarEnemigoNativo(int posicionX, int posicionY, int desplazamientoX, int direccionX,
		int ancho, int alto) {//01-07-2017 NIVEL RESCATE
		nuevoEnemigoNativo = CEnemigoNativo(posicionX, posicionY, desplazamientoX, direccionX, ancho, alto);//01-07-2017 NIVEL RESCATE
		arregloEnemigosNativos.push_back(nuevoEnemigoNativo);//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
	void DibujarEnemigosNativos(Graphics^ grEnemigoNativo, Bitmap^ bmpEnemigoNativo, Rectangle areaVisible) {//01-07-2017 NIVEL RESCATE
		for (int i = 0; i < arregloEnemigosNativos.size(); i++) {//01-07-2017 NIVEL RESCATE
			arregloEnemigosNativos[i].DibujarEnemigoNativo(grEnemigoNativo, bmpEnemigoNativo, areaVisible);//01-07-2017 NIVEL RESCATE
		}//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
	void MoverEnemigosNativos(int posicionXAComparar) {//01-07-2017 NIVEL RESCATE
		for (int i = 0; i < arregloEnemigosNativos.size(); i++) {//01-07-2017 NIVEL RESCATE
			arregloEnemigosNativos[i].MoverEnemigoNativo(posicionXAComparar);//01-07-2017 NIVEL RESCATE
		}//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
	int getArregloEnemigosNativosSize() {//01-07-2017 NIVEL RESCATE
		return arregloEnemigosNativos.size();//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
	CEnemigoNativo getEnemigoNativoEspecifico(int posicionEnArreglo) {//01-07-2017 NIVEL RESCATE
		return arregloEnemigosNativos[posicionEnArreglo];//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
};
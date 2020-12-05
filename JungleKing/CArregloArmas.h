#pragma once
#include<vector>
#include"CArma.h"//01-07-2017 ARMA
using namespace std;
class CArregloArmas {//01-07-2017 ARMA
private:
	vector<CArma> arregloArmas;//01-07-2017 ARMA
	CArma nuevaArma;//01-07-2017 ARMA

public:
	CArregloArmas() {//01-07-2017 ARMA

	}
	~CArregloArmas() {//01-07-2017 ARMA

	}
	void AgregarArma(int posicionX, int posicionY, int desplazamientoX, int direccionX,
		int ancho, int alto, int tipoArma) {//01-07-2017 ARMA
		nuevaArma = CArma(posicionX, posicionY, desplazamientoX, direccionX, ancho, alto,tipoArma);//01-07-2017 ARMA
		arregloArmas.push_back(nuevaArma);//01-07-2017 ARMA
	}//01-07-2017 ARMA
	void DibujarArmas(Graphics^ grArma, Bitmap^ bmpArma, Rectangle areaVisible) {//01-07-2017 ARMA
		for (int i = 0; i < arregloArmas.size(); i++) {//01-07-2017 ARMA
			arregloArmas[i].DibujarArma(grArma, bmpArma, areaVisible);//01-07-2017 ARMA
		}//01-07-2017 ARMA
	}//01-07-2017 ARMA
	void MoverArmas() {//01-07-2017 ARMA
		for (int i = 0; i < arregloArmas.size(); i++) {//01-07-2017 ARMA
			arregloArmas[i].MoverArma();//01-07-2017 ARMA
		}//01-07-2017 ARMA
	}//01-07-2017 ARMA
	int getArregloArmasSize() {//01-07-2017 ARMA
		return arregloArmas.size();//01-07-2017 ARMA
	}//01-07-2017 ARMA
	CArma getArmaEspecifica(int posicionEnArreglo) {//01-07-2017 ARMA
		return arregloArmas[posicionEnArreglo];//01-07-2017 ARMA
	}//01-07-2017 NIVEL RESCATE
};
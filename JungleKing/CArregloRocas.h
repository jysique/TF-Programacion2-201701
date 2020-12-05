#pragma once
#include<vector>//30-06-2017 NIVEL COLINA
#include"CRoca.h"//30-06-2017 NIVEL COLINA
using namespace std;//30-06-2017 NIVEL COLINA
class CArregloRocas {//30-06-2017 NIVEL COLINA
private:
	vector<CRoca> arregloRocas;//30-06-2017 NIVEL COLINA
	CRoca nuevaRoca;//30-06-2017 NIVEL COLINA

public:
	CArregloRocas() {

	}
	~CArregloRocas() {

	}

	void AgregarRoca(int posicionX, int posicionY, int desplazamientoX, int desplazamientoY, int direccionY, int ancho,
		int alto) {//30-06-2017 NIVEL COLINA
		nuevaRoca = CRoca(posicionX, posicionY, desplazamientoX, desplazamientoY,direccionY, ancho, alto);//30-06-2017 NIVEL COLINA
		arregloRocas.push_back(nuevaRoca);//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	void DibujarRoca(Graphics^ grRoca, Bitmap^ bmpRoca, Rectangle areaVisible) {//30-06-2017 NIVEL COLINA
		for (int i = 0; i < arregloRocas.size(); i++) {//30-06-2017 NIVEL COLINA
			arregloRocas[i].DibujarRoca(grRoca, bmpRoca, areaVisible);//30-06-2017 NIVEL COLINA
		}//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	void MoverRocas(int altura1, int altura2) {//30-06-2017 NIVEL COLINA
		for (int i = 0; i < arregloRocas.size(); i++) {//30-06-2017 NIVEL COLINA
			arregloRocas[i].MoverRoca(altura1,altura2);//30-06-2017 NIVEL COLINA
		}//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	void DetectarRocaLleganAlFinal(int anchoFormulario) {//30-06-2017 NIVEL COLINA
		for (int i = 0; i < arregloRocas.size(); i++) {//30-06-2017 NIVEL COLINA
			if (arregloRocas[i].DestruirSiLlegaAlFinal(anchoFormulario)) {//30-06-2017 NIVEL COLINA
				arregloRocas.erase(arregloRocas.begin() + i);//30-06-2017 NIVEL COLINA
			}//30-06-2017 NIVEL COLINA
		}//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	int getArregloRocasSize() {//30-06-2017 NIVEL COLINA
		return arregloRocas.size();//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	CRoca getRocaEspecifica(int posicionEnArreglo) {//30-06-2017 NIVEL COLINA
		return arregloRocas[posicionEnArreglo];//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	void EliminarRocaEspecifica(int posicion) {//30-06-2017 NIVEL COLINA
		arregloRocas.erase(arregloRocas.begin() + posicion);//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA

	void EliminarTodasLasRocas() {//01-07-2017
		arregloRocas.clear();//01-07-2017
	}//01-07-2017
};
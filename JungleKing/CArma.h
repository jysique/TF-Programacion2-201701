#pragma once
#include<string>
#include<iostream>
using namespace System::Drawing;
using namespace std;
class CArma {//01-07-2017 ARMA
private:
	int posicionX;//01-07-2017 ARMA
	int posicionY;//01-07-2017 ARMA
	double desplazamientoX;//01-07-2017 ARMA
	int direccionX;//01-07-2017 ARMA
	int ancho;//01-07-2017 ARMA
	int alto;//01-07-2017 ARMA
	int tipoArma;//01-07-2017 ARMA
public://01-07-2017 ARMA
	CArma() {//01-07-2017 ARMA

	}//01-07-2017 ARMA
	CArma(int posicionX, int posicionY, int desplazamientoX, int direccionX, int ancho,
		int alto, int tipoArma) {//01-07-2017 ARMA
		this->posicionX = posicionX;
		this->posicionY = posicionY;
		this->desplazamientoX = desplazamientoX;
		this->direccionX = direccionX;
		this->ancho = ancho;
		this->alto = alto;
		this->tipoArma = tipoArma;
	}//01-07-2017 ARMA

	void DibujarArma(Graphics^ grArma, Bitmap^ bmpArma, Rectangle areaVisible) {//01-07-2017 ARMA
		grArma->DrawImage(bmpArma, posicionX, posicionY, areaVisible, GraphicsUnit::Pixel);//01-07-2017 ARMA
	//	cout << "se dibuja";
	}//01-07-2017 ARMA
	void MoverArma() {//01-07-2017 ARMA
		posicionX = posicionX + (int)(desplazamientoX*direccionX);//01-07-2017 ARMA
	}//01-07-2017 ARMA
	int getPosicionX() {//01-07-2017 ARMA
		return posicionX;//01-07-2017 ARMA
	}//01-07-2017 ARMA
	int getPosicionY() {//01-07-2017 ARMA
		return posicionY;//01-07-2017 ARMA
	}//01-07-2017 ARMA
	int getTipoArma() {//01-07-2017 ARMA
		return tipoArma;//01-07-2017 ARMA
	}//01-07-2017 ARMA
};
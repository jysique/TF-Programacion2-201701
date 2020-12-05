#pragma once
#include<string>
#include<iostream>
using namespace System::Drawing;
using namespace std;
class CEnemigoNativo {//01-07-2017 NIVEL RESCATE
private:
	int posicionX;//01-07-2017 NIVEL RESCATE
	int posicionY;//01-07-2017 NIVEL RESCATE
	int posicionInicialX;//01-07-2017 NIVEL RESCATE
	double desplazamientoX;//01-07-2017 NIVEL RESCATE
	int direccionX;//01-07-2017 NIVEL RESCATE
	int ancho;//01-07-2017 NIVEL RESCATE
	int alto;//01-07-2017 NIVEL RESCATE
public://01-07-2017 NIVEL RESCATE
	CEnemigoNativo() {//01-07-2017 NIVEL RESCATE

	}//01-07-2017 NIVEL RESCATE
	CEnemigoNativo(int posicionX, int posicionY, int desplazamientoX, int direccionX, int ancho,
		int alto) {//01-07-2017 NIVEL RESCATE
		this->posicionX = posicionX;
		this->posicionY = posicionY;
		this->desplazamientoX = desplazamientoX;
		this->direccionX = direccionX;
		posicionInicialX = posicionX;
		this->ancho = ancho;
		this->alto = alto;
	}//01-07-2017 NIVEL RESCATE
	
	void DibujarEnemigoNativo(Graphics^ grEnemigoNativo, Bitmap^ bmpEnemigoNativo, Rectangle areaVisible) {//01-07-2017 NIVEL RESCATE
		grEnemigoNativo->DrawImage(bmpEnemigoNativo, posicionX, posicionY, areaVisible, GraphicsUnit::Pixel);//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
	void MoverEnemigoNativo(int posicionXAComparar) {//01-07-2017 NIVEL RESCATE
		if (posicionX + desplazamientoX <= posicionInicialX + ancho - posicionXAComparar ||
			posicionX + ancho + desplazamientoX >= posicionInicialX + ancho + posicionXAComparar) {//01-07-2017 NIVEL RESCATE
			direccionX = direccionX*-1;//01-07-2017 NIVEL RESCATE
		}//01-07-2017 NIVEL RESCATE
		posicionX = posicionX + (int)(desplazamientoX*direccionX);//01-07-2017 NIVEL RESCATE
	}
	int getPosicionX() {//01-07-2017 NIVEL RESCATE
		return posicionX;//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
	int getPosicionY() {//01-07-2017 NIVEL RESCATE
		return posicionY;//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
};
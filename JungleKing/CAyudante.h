#pragma once
#include<string>
#include<iostream>
using namespace System::Drawing;
using namespace std;
class CAyudante {//01-07-2017 AYUDANTE
private:
	int posicionX;//01-07-2017 AYUDANTE
	int posicionY;//01-07-2017 AYUDANTE
	double desplazamientoX;//01-07-2017 AYUDANTE
	int direccionX;//01-07-2017 AYUDANTE
	int ancho;//01-07-2017 AYUDANTE
	int alto;//01-07-2017 AYUDANTE
	bool puedeCurarAlJugador;//01-07-2017 AYUDANTE
public://01-07-2017 NIVEL RESCATE
	CAyudante() {//01-07-2017 AYUDANTE

	}//01-07-2017 AYUDANTE
	~CAyudante() {//01-07-2017 AYUDANTE

	}//01-07-2017 AYUDANTE
	CAyudante(int posicionX, int posicionY, int desplazamientoX, int direccionX, int ancho,
		int alto) {//01-07-2017 AYUDANTE
		this->posicionX = posicionX;
		this->posicionY = posicionY;
		this->desplazamientoX = desplazamientoX;
		this->direccionX = direccionX;
		this->ancho = ancho;
		this->alto = alto;
	}//01-07-2017 AYUDANTE

	void DibujarAyudante(Graphics^ grEnemigoNativo, Bitmap^ bmpEnemigoNativo, Rectangle areaVisible) {//01-07-2017 AYUDANTE
		grEnemigoNativo->DrawImage(bmpEnemigoNativo, posicionX, posicionY, areaVisible, GraphicsUnit::Pixel);//01-07-2017 AYUDANTE
	}//01-07-2017 AYUDANTE
	void MoverAyudante(int posicionJugador) {//01-07-2017 AYUDANTE
		if (posicionX + desplazamientoX <= posicionJugador) {//01-07-2017 AYUDANTE
			direccionX = direccionX*-1;//01-07-2017 AYUDANTE
		}//01-07-2017 AYUDANTE
		posicionX = posicionX + (int)(desplazamientoX*direccionX);//01-07-2017 AYUDANTE
	}
	int getPosicionX() {//01-07-2017 AYUDANTE
		return posicionX;//01-07-2017 AYUDANTE
	}//01-07-2017 AYUDANTE
	int getPosicionY() {//01-07-2017 AYUDANTE
		return posicionY;//01-07-2017 AYUDANTE
	}//01-07-2017 AYUDANTE
	bool LlegoAlFinalDelFormulario(int anchoFormulario) {//01-07-2017 AYUDANTE
		if (ancho + posicionX + desplazamientoX >= anchoFormulario) {//01-07-2017 AYUDANTE
			return true;//01-07-2017 AYUDANTE
		}//01-07-2017 AYUDANTE
	}//01-07-2017 AYUDANTE
	void setPosicionX(int posicionX) {//01-07-2017 AYUDANTE
		this->posicionX = posicionX;//01-07-2017 AYUDANTE
	}//01-07-2017 AYUDANTE

	bool getPuedeCurarAlJugador() {//01-07-2017 AYUDANTE
		return puedeCurarAlJugador;//01-07-2017 AYUDANTE
	}//01-07-2017 AYUDANTE
	void setPuedeCurarAlJgador(bool puedeCurarAlJugador) {//01-07-2017 AYUDANTE
		this->puedeCurarAlJugador = puedeCurarAlJugador;//01-07-2017 AYUDANTE
	}//01-07-2017 AYUDANTE
};
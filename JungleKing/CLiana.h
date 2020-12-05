#pragma once
#include<string>
#include<iostream>
using namespace System::Drawing;
using namespace std;
class CLiana {
private:
	//char* nombreImagen;
	int posicionX;
	int posicionY;
	int posicionInicialX;
	double desplazamientoX;
	int direccionX;
	int ancho;
	int alto;
public:
	CLiana() {
		
	}
	CLiana(int posicionX, int posicionY, int desplazamientoX, int direccionX, int ancho, int alto) {
		this->posicionX = posicionX;
		this->posicionY = posicionY;
		this->desplazamientoX = desplazamientoX;
		this->direccionX = direccionX;
		posicionInicialX = posicionX;
		this->ancho = ancho;
		this->alto = alto;
	}
	/*
	~CLiana() {
		delete[] nombreImagen;
	}
	*/
	/*
	void setImagen(char *nombreNuevaImagen) {
		strcpy(nombreImagen, nombreNuevaImagen);
		System::Drawing::Bitmap ^bmp;
		bmp = gcnew Bitmap(gcnew System::String(nombreImagen));
		ancho = bmp->Width;
		alto = bmp->Height;
		delete bmp;
	}
	*/
	void DibujarLiana(Graphics^ grLiana, Bitmap^ bmpLiana, Rectangle areaVisible) {
		grLiana->DrawImage(bmpLiana, posicionX, posicionY, areaVisible, GraphicsUnit::Pixel);
	//	cout << "SE DIBUJA" << endl;
		/*
		Bitmap^ bmpLiana;
		bmpLiana = gcnew Bitmap(gcnew System::String(nombreImagen));
		grLiana->DrawImage(bmpLiana, posicionX, posicionY);
		delete bmpLiana;
		*/
	}
	void MoverLiana(int posicionXAComparar) {
		if (posicionX + desplazamientoX <= posicionInicialX + ancho - posicionXAComparar ||
			posicionX + ancho + desplazamientoX >= posicionInicialX + ancho + posicionXAComparar) {
			/*
			if (posicionX + desplazamientoX >= posicionInicialX + ancho + posicionXAComparar ||
				posicionX+desplazamientoX+ancho<=posicionInicialX-posicionXAComparar) {
				*/
			direccionX = direccionX*-1;
		}
		//cout << "si llega";
		posicionX = posicionX + (int)(desplazamientoX*direccionX);
	}
	int getPosicionX() {
		return posicionX;
	}
	int getPosicionY() {
		return posicionY;
	}
	
};
#pragma once
#include<vector>
#include"CLiana.h"
using namespace std;
class CArregloLianas {
private:
	vector<CLiana> arregloLianas;
	CLiana nuevaLiana;

public:
	CArregloLianas() {

	}
	~CArregloLianas() {

	}
	/*
	CArregloLianas(int capacidadInicial) {
		arregloLianas.capacity = capacidadInicial;
	}
	*/
	void AgregarLiana(int posicionX, int posicionY, int desplazamientoX, int direccionX, int ancho, int alto) {
		nuevaLiana = CLiana(posicionX, posicionY, desplazamientoX, direccionX, ancho, alto);
		arregloLianas.push_back(nuevaLiana);
	}
	void DibujarLianas(Graphics^ grLiana, Bitmap^ bmpLiana, Rectangle areaVisible) {
		for (int i = 0; i < arregloLianas.size(); i++) {
			arregloLianas[i].DibujarLiana(grLiana, bmpLiana, areaVisible);
		}
	}
	void MoverLianas(int posicionXAComparar) {
		for (int i = 0; i < arregloLianas.size(); i++) {
			arregloLianas[i].MoverLiana(posicionXAComparar);
		}
	}
	int getArregloLianasSize() {
		return arregloLianas.size();
	}
	CLiana getLianaEspecifica(int posicionEnArreglo) {
		return arregloLianas[posicionEnArreglo];
	}
	/*
	void SetImagenesLianas() {
		for (int i = 0; i < arregloLianas.size(); i++) {
			arregloLianas[i].setImagen("liana.png");
		}
	}
	*/
};
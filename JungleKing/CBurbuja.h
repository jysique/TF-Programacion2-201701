#pragma once

#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
using namespace System::Drawing;//01-07-2017 NIVEL ACUATICO YSIQUE
class CBurbuja{//01-07-2017 NIVEL ACUATICO YSIQUE
private://01-07-2017 NIVEL ACUATICO YSIQUE
	int posicionX;//01-07-2017 NIVEL ACUATICO YSIQUE
	int posicionY;//01-07-2017 NIVEL ACUATICO YSIQUE
	int ancho;//01-07-2017 NIVEL ACUATICO YSIQUE
	int alto;//01-07-2017 NIVEL ACUATICO YSIQUE
	int desplazamientoX;//01-07-2017 NIVEL ACUATICO YSIQUE
	int desplazamientoY;//01-07-2017 NIVEL ACUATICO YSIQUE
	int direccionY;//01-07-2017 NIVEL ACUATICO YSIQUE
	int idSpritex;//01-07-2017 NIVEL ACUATICO YSIQUE
	int idSpritey;//01-07-2017 NIVEL ACUATICO YSIQUE
public:
	CBurbuja() {}
	~CBurbuja() {}

	CBurbuja(int posicionX, int posicionY, int desplazamientoX, int desplazamientoY, int direccionY, int ancho, int alto, 
		int idSpritex, int idSpritey) {//01-07-2017 NIVEL ACUATICO YSIQUE
		this->posicionX = posicionX;//01-07-2017 NIVEL ACUATICO YSIQUE
		this->posicionY = posicionY;//01-07-2017 NIVEL ACUATICO YSIQUE
		this->desplazamientoX = desplazamientoX;//01-07-2017 NIVEL ACUATICO YSIQUE
		this->desplazamientoY = desplazamientoY;//01-07-2017 NIVEL ACUATICO YSIQUE
		this->direccionY = direccionY;//01-07-2017 NIVEL ACUATICO YSIQUE
		this->ancho = ancho;//01-07-2017 NIVEL ACUATICO YSIQUE
		this->alto = alto;//01-07-2017 NIVEL ACUATICO YSIQUE
		this->idSpritex = idSpritex;//01-07-2017 NIVEL ACUATICO YSIQUE
		this->idSpritey = idSpritey;//01-07-2017 NIVEL ACUATICO YSIQUE
	}

	void set_posX(int nuevo) { posicionX = nuevo; } //01-07-2017 NIVEL ACUATICO YSIQUE
	void set_posY(int nuevo) { posicionY = nuevo; }//01-07-2017 NIVEL ACUATICO YSIQUE
	void set_desplazamientox() { desplazamientoX = 1 + rand() % 10;	}//01-07-2017 NIVEL ACUATICO YSIQUE
	void set_desplazamientoy() { desplazamientoY = 1 + rand() % 10;	}//01-07-2017 NIVEL ACUATICO YSIQUE
	int getPosicionX() { return posicionX; }//01-07-2017 NIVEL ACUATICO YSIQUE
	int getPosicionY() { return posicionY; }//01-07-2017 NIVEL ACUATICO YSIQUE

	void dibujarBurbuja(Graphics ^grBurbuja, Bitmap ^bmpBurbuja, Rectangle aVisible) {//01-07-2017 NIVEL ACUATICO YSIQUE
		grBurbuja->DrawImage(bmpBurbuja, posicionX, posicionY, aVisible, GraphicsUnit::Pixel);	}//01-07-2017 NIVEL ACUATICO YSIQUE

	void mover() { //01-07-2017 NIVEL ACUATICO YSIQUE
		posicionY = posicionY + desplazamientoY*direccionY*(-1);//01-07-2017 NIVEL ACUATICO YSIQUE
	}
	int get_desplazamientoX() { return desplazamientoX; }//01-07-2017 NIVEL ACUATICO YSIQUE
	int get_desplazamientoY() { return desplazamientoY; }//01-07-2017 NIVEL ACUATICO YSIQUE

	bool DestruirFinal(int altomaximo) {//01-07-2017 NIVEL ACUATICO YSIQUE
		if (posicionY + desplazamientoY + alto <= altomaximo + 5) { return true;}//01-07-2017 NIVEL ACUATICO YSIQUE
	}
};

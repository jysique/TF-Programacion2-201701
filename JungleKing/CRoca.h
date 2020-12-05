#pragma once
using namespace System::Drawing;//30-06-2017 NIVEL COLINA
class CRoca {//30-06-2017 NIVEL COLINA
private:
	int posicionX;//30-06-2017 NIVEL COLINA
	int posicionY;//30-06-2017 NIVEL COLINA
	int desplazamientoX;//30-06-2017 NIVEL COLINA
	int desplazamientoY;//30-06-2017 NIVEL COLINA
	int direccionY;//30-06-2017 NIVEL COLINA
	int ancho;//30-06-2017 NIVEL COLINA
	int alto;//30-06-2017 NIVEL COLINA
public:
	CRoca() {

	}
	~CRoca() {

	}
	CRoca(int posicionX, int posicionY, int desplazamientoX, int desplazamientoY, int direccionY, int ancho,
		int alto) {//30-06-2017 NIVEL COLINA
		this->posicionX = posicionX;//30-06-2017 NIVEL COLINA
		this->posicionY = posicionY;//30-06-2017 NIVEL COLINA
		this->desplazamientoX = desplazamientoX;//30-06-2017 NIVEL COLINA
		this->desplazamientoY = desplazamientoY;//30-06-2017 NIVEL COLINA
		this->direccionY = direccionY;//30-06-2017 NIVEL COLINA
		this->ancho = ancho;//30-06-2017 NIVEL COLINA
		this->alto = alto;//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	void DibujarRoca(Graphics^ grRoca, Bitmap^ bmpRoca, Rectangle areaVisible) {//30-06-2017 NIVEL COLINA
		grRoca->DrawImage(bmpRoca, posicionX, posicionY, areaVisible, GraphicsUnit::Pixel);//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	void MoverRoca(int alturaMaxima, int alturaMinima) {//30-06-2017 NIVEL COLINA
		if (posicionY + desplazamientoY<alturaMinima || posicionY + desplazamientoY + alto>alturaMaxima) {//30-06-2017 NIVEL COLINA
			direccionY = direccionY*-1;//30-06-2017 NIVEL COLINA
		}//30-06-2017 NIVEL COLINA
		posicionX = posicionX + desplazamientoX;//30-06-2017 NIVEL COLINA
		posicionY = posicionY + (desplazamientoY*direccionY);//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	bool DestruirSiLlegaAlFinal(int anchoFormulario) {//30-06-2017 NIVEL COLINA
		if (posicionX + desplazamientoX + ancho >= anchoFormulario+20) {//30-06-2017 NIVEL COLINA
			return true;//30-06-2017 NIVEL COLINA
		}//30-06-2017 NIVEL COLINA
	}
	int getPosicionX() {
		return posicionX;
	}
	int getPosicionY() {
		return posicionY;
	}
};
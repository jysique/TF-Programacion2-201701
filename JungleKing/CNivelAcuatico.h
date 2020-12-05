#pragma once
using namespace System::Drawing;

class CNivelAgua { //01-07-2017 NIVEL ACUATICO YSIQUE
private:
	int posicionX;//01-07-2017 NIVEL ACUATICO YSIQUE
	int posicionY;//01-07-2017 NIVEL ACUATICO YSIQUE
public:
	CNivelAgua() {}
	~CNivelAgua() {	}

	CNivelAgua(int posicionX, int posicionY) {//01-07-2017 NIVEL ACUATICO YSIQUE
		this->posicionX = posicionX;//01-07-2017 NIVEL ACUATICO YSIQUE
		this->posicionY = posicionY;//01-07-2017 NIVEL ACUATICO YSIQUE
	}
	void dibujarNivelAgua(Graphics ^grNivelAgua, Bitmap^ bmpNivelAgua, Rectangle aVisibleAgua) { //01-07-2017 NIVEL ACUATICO YSIQUE
		grNivelAgua->DrawImage(bmpNivelAgua, posicionX, posicionY, aVisibleAgua, GraphicsUnit::Pixel); //01-07-2017 NIVEL ACUATICO YSIQUE
	}
};

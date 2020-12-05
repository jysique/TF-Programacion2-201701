#pragma once
#include<iostream>//30-06-2017
using namespace System::Drawing;//30-06-2017
using namespace std;//30-06-2017
class CNivelColina {
private:
	int posicionX;//30-06-2017
	int posicionY;//30-06-2017

public:
	CNivelColina() {

	}
	~CNivelColina() {

	}
	CNivelColina(int posicionX, int posicionY) {//30-06-2017
		this->posicionX = posicionX;//30-06-2017
		this->posicionY = posicionY;//30-06-2017
	}
	void DibujarNivelColina(Graphics^ grNivelColina, Bitmap^ bmpNivelColina, Rectangle areaVisible) {//30-06-2017
		grNivelColina->DrawImage(bmpNivelColina, posicionX, posicionY, areaVisible, GraphicsUnit::Pixel);//30-06-2017																				
	}//30-06-2017
};
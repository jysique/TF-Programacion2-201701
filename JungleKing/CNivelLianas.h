#pragma once
#include<iostream>//30-06-2017
using namespace System::Drawing;//30-06-2017
using namespace std;//30-06-2017
class CNivelLianas {
private:
	int posicionX;//30-06-2017
	int posicionY;//30-06-2017

public:
	CNivelLianas() {

	}
	~CNivelLianas() {

	}
	CNivelLianas(int posicionX, int posicionY) {//30-06-2017
		this->posicionX = posicionX;//30-06-2017
		this->posicionY = posicionY;//30-06-2017
	}
	void DibujarNivelLianas(Graphics^ grNivelLianas, Bitmap^ bmpNivelLianas, Rectangle areaVisible) {//30-06-2017
		grNivelLianas->DrawImage(bmpNivelLianas, posicionX, posicionY, areaVisible, GraphicsUnit::Pixel);//30-06-2017
	//	cout << "Se dibuja";
	}//30-06-2017
};
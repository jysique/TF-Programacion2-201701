#pragma once
#include<iostream>//01-07-2017
using namespace System::Drawing;//01-07-2017
using namespace std;//30-06-2017
class CNivelRescate {
private:
	int posicionX;//01-07-2017
	int posicionY;//01-07-2017

public:
	CNivelRescate() {

	}
	~CNivelRescate() {

	}
	CNivelRescate(int posicionX, int posicionY) {//01-07-2017
		this->posicionX = posicionX;//01-07-2017
		this->posicionY = posicionY;//01-07-2017
	}
	void DibujarNivelRescate(Graphics^ grNivelRescate, Bitmap^ bmpNivelRescate, Rectangle areaVisible) {//01-07-2017
		grNivelRescate->DrawImage(bmpNivelRescate, posicionX, posicionY, areaVisible, GraphicsUnit::Pixel);//01-07-2017																				
	}//01-07-2017
};
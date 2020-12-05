#pragma once
#include"CNivelLianas.h"//30-06-2017
#include"CNivelColina.h"
#include"CNivelRescate.h"//01-07-2017
#include "CNivelAcuatico.h" //01-07-2017 NIVEL ACUATICO YSIQUE

class CArregloNiveles {
private:
	CNivelLianas nivelLianas;//30-06-2017

	CNivelColina nivelColina;//30-06-2017 NIVEL COLINA

	CNivelRescate nivelRescate;//01-07-2017 NIVEL RESCATE

	CNivelAgua nivelAgua; //01-07-2017 NIVEL ACUATICO YSIQUE
public:
	CArregloNiveles() {

	}
	~CArregloNiveles() {

	}
	void setNivelLianas(int posicionX, int posicionY) {//30-06-2017
		nivelLianas = CNivelLianas(posicionX, posicionY);//30-06-2017
	//	cout << "Se agrega";
	}//30-06-2017
	CNivelLianas getNivelesLianas() {//30-06-2017
		return nivelLianas;//30-06-2017
	}//30-06-2017


	void setNivelColina(int posicionX, int posicionY) {//30-06-2017 NIVEL COLINA
		nivelColina = CNivelColina(posicionX, posicionY);//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	CNivelColina getNivelesColina() {//30-06-2017 NIVEL COLINA
		return nivelColina;//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA


	void setNivelRescate(int posicionX, int posicionY) {//01-07-2017 NIVEL RESCATE
		nivelRescate = CNivelRescate(posicionX, posicionY);//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
	CNivelRescate getNivelesRescate() {//01-07-2017 NIVEL RESCATE
		return nivelRescate;//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE


	void setNivelAgua(int posicionX, int posicionY) { //01-07-2017 NIVEL ACUATICO YSIQUE
		nivelAgua = CNivelAgua(posicionX, posicionY);//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE
	CNivelAgua getNivelesAgua() { //01-07-2017 NIVEL ACUATICO YSIQUE
		return nivelAgua; //01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE

};
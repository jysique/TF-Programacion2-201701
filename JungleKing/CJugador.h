#pragma once
#include<cmath>
#include<iostream>
#include"CArregloArmas.h"//01-07-2017 ARMA
using namespace System::Drawing;
using namespace std;
class CJugador {
private:
	int vidas;
	int posicionX;
	int posicionY;
	double desplazamientoX;
	double desplazamientoY;
	int direccionX;
	int direccionY;
	//double contadorCicloRepetitivo;
	double tiempoVuelo;
	double velocidadInicial;
	double gravedad;
	double angulo;
	int ancho;
	int alto;
	int identificadorSpriteX = 0;
	int identificadorSpriteY = 0;
	bool estaEnUnaLiana;
	bool isJump;//30-06-2017

	bool puedeAferrarALianas;//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS

	int posicionYInicial;//30-06-2017 PARA NIVEL COLINA
	bool estaEnElSueloNivelColina;//30-06-2017 PARA NIVEL COLINA

	CArregloArmas arregloArmas;//01-07-2017 ARMA

	//double desplazamientoXInicial;//30-06-2017
	//double desplazamientoYInicial;//30-06-2017
	//int anguloInicial;//30-06-2017
	//int verdaderaVelocidadInicial;//30-06-2017
public:
	CJugador() {
		velocidadInicial = 80;
		angulo = 45;
		gravedad = 9.81;
		tiempoVuelo = 2 * (velocidadInicial*sin(angulo) / gravedad);
	}
	~CJugador() {

	}
	CJugador(int posicionX, int posicionY, int desplazamientoX, int desplazamientoY, int velocidadInicial, int angulo,
		int ancho, int alto) {
		this->posicionX = posicionX;
		this->posicionY = posicionY;
		this->desplazamientoX = desplazamientoX;
		this->desplazamientoY = desplazamientoY;
		this->velocidadInicial = velocidadInicial;
		this->angulo = angulo;

		this->ancho = ancho;
		this->alto = alto;

		CalcularTiempoDeVuelo();//30-06-2017

		ancho = 91.66;
		alto = 125;
		estaEnUnaLiana = false;
		isJump = false;//30-06-2017
		direccionY = 1;
		puedeAferrarALianas = true;//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS

		posicionYInicial = posicionY;//30-06-2017 PARA NIVEL COLINA
		vidas = 3;
	}
	void DibujarJugador(Graphics^ grJugador, Bitmap^ bmpJugador, Rectangle areaVisible) {
		//	Rectangle areaVisible = Rectangle(ancho*identificadorSpriteX, alto*identificadorSpriteY, ancho, alto);
		grJugador->DrawImage(bmpJugador, posicionX, posicionY, areaVisible, GraphicsUnit::Pixel);
	}
	void Saltar(int contadorCicloRepetitivo) {
		//	cout << desplazamientoY << endl;
		//	posicionY = posicionY + desplazamientoY;

			//cout << "si llega";
			//this->contadorCicloRepetitivo = contadorCicloRepetitivo;

		if (isJump == true) {//30-06-2017
			if (estaEnUnaLiana == false) {
				contadorCicloRepetitivo = contadorCicloRepetitivo * 1 / 2;
				//	if (contadorCicloRepetitivo <= tiempoVuelo) {

				desplazamientoX = velocidadInicial*cos(angulo)*contadorCicloRepetitivo;
				desplazamientoY = velocidadInicial*sin(angulo)*contadorCicloRepetitivo - 0.5*gravedad*contadorCicloRepetitivo*
					contadorCicloRepetitivo;
				//	if (posicionY > 0) {
				posicionX = posicionX - (int)desplazamientoX;
				posicionY = posicionY - (int)desplazamientoY;
			}
		}//30-06-2017
		//	}
			/*
			gr->Clear(Color::White);
			gr->DrawEllipse(gcnew Pen(Color::Red), desplazamientoX, 400 - (int)desplazamientoY,
				20, 20);
				*/
				//	}
				//	}
				//	contadorCicloRepetitivo = contadorCicloRepetitivo + 1;

	}
	void MoverEnLiana(int teclaOprimida) {
		if (estaEnUnaLiana) {
			if (teclaOprimida == 1) {
				direccionY = -1;
				posicionY = posicionY + (int)(desplazamientoY*direccionY);
			}
			else {
				direccionY = 1;
				posicionY = posicionY + (int)(desplazamientoY*direccionY);
			}
		}
	}

	void MoverJugadorEnNivelColina(int teclaOprimida) {//30-06-2017 NIVEL COLINA
		if (teclaOprimida == 1) {//30-06-2017 NIVEL COLINA
			direccionX = -1;//30-06-2017 NIVEL COLINA
			posicionX = posicionX + (int)(desplazamientoX*direccionX);//30-06-2017 NIVEL COLINA
		}//30-06-2017 NIVEL COLINA
		if (teclaOprimida == 2) {//30-06-2017 NIVEL COLINA
			direccionX = 1;//30-06-2017 NIVEL COLINA
			posicionX = posicionX + (int)(desplazamientoX*direccionX);//30-06-2017 NIVEL COLINA
		}//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA

	void SaltarJugadorEnNivelColina(int contadorCicloRepetitivo, int alturaYAComparar) {//30-06-2017 PARA NIVEL COLINA
		/*
		if (posicionY + alto > posicionYInicial - alturaYAComparar) {
			direccionY = 1;
		}else
		*/

		/* //30-06-2017 NIVEL COLINA ULTIMO INTENTO SALTO
		if (posicionY > 530) {
			direccionY = -1;
		}else if (posicionY < 430) {
			direccionY = 1;
			estaEnElSueloNivelColina = true;
		}else if (posicionY == 530 && estaEnElSueloNivelColina == true) {
			direccionY = 0;
			isJump = false;
			estaEnElSueloNivelColina = false;
			cout << "ESTA EN EL SUELO: " << estaEnElSueloNivelColina<<endl;
			cout << "ESTA SALTANDO: " << isJump << endl;
		}
		/* //30-06-2017 NIVEL COLINA ULTIMO INTENTO SALTO

		if (posicionY - alto - desplazamientoY > posicionYInicial - alturaYAComparar - alto - desplazamientoY) {
			direccionY = -1;
		}
		else {
			direccionY = 0;
		}
		*/
		if (isJump == true) {
			//if (estaEnUnaLiana == false) {
			contadorCicloRepetitivo = contadorCicloRepetitivo * 1 / 2;
			if (contadorCicloRepetitivo <= tiempoVuelo) {

				//	desplazamientoX = velocidadInicial*cos(angulo)*contadorCicloRepetitivo;
				desplazamientoY = velocidadInicial*sin(angulo)*contadorCicloRepetitivo - 0.5*gravedad*contadorCicloRepetitivo*
					contadorCicloRepetitivo;
				if (posicionY > 0) {
					//	posicionX = posicionX - (int)desplazamientoX;
					posicionY = posicionY - (int)desplazamientoY;
				}
			}
			//}
		}


		//posicionY = posicionY + (int)(desplazamientoY*direccionY); // COMENTADO 01-07-2017

		/*
		if (estaEnElSueloNivelColina == true) {//30-06-2017 PARA NIVEL COLINA
			direccionY = -1;//30-06-2017 PARA NIVEL COLINA
			posicionY = posicionY + (int)(desplazamientoY*direccionY);//30-06-2017 PARA NIVEL COLINA
		}//30-06-2017 PARA NIVEL COLINA
		if (posicionY + alto > posicionYInicial - alturaYAComparar) {//30-06-2017 PARA NIVEL COLINA
			direccionY = 1;
		}//30-06-2017 PARA NIVEL COLINA
		if (posicionY >= posicionYInicial) {//30-06-2017 PARA NIVEL COLINA
			posicionY = posicionYInicial;//30-06-2017 PARA NIVEL COLINA
			estaEnElSueloNivelColina = true;//30-06-2017 PARA NIVEL COLINA
		}//30-06-2017 PARA NIVEL COLINA
		*/
	}//30-06-2017 PARA NIVEL COLINA
	bool getEstaEnElSueloNivelColina() {//30-06-2017 PARA NIVEL COLINA
		return estaEnElSueloNivelColina;//30-06-2017 PARA NIVEL COLINA
	}//30-06-2017 PARA NIVEL COLINA



	int getPosicionX() {
		return posicionX;
	}
	int getPosicionY() {
		return posicionY;
	}

	int getAncho() {
		return ancho;
	}
	int getAlto() {
		return alto;
	}
	void setEstaEnUnaLiana(bool estaEnUnaLiana) {
		this->estaEnUnaLiana = estaEnUnaLiana;
	}
	bool getEstaEnUnaLiana() {//30-06-2017
		return estaEnUnaLiana;//30-06-2017
	}//30-06-2017


	void setPosicionX(int posicionX) {
		this->posicionX = posicionX;
	}
	void setPosicionY(int posicionY) {//01-03-2017 PARA PONERLO EN POSICION DE OTRO NIVEL
		this->posicionY = posicionY;//01-03-2017 PARA PONERLO EN POSICION DE OTRO NIVEL
	}//01-03-2017 PARA PONERLO EN POSICION DE OTRO NIVEL

	void setIsJumpBool(bool isJump) {//30-06-2017
		this->isJump = isJump;//30-06-2017
	}//30-06-2017
	bool getIsJumpBool() {//30-06-2017
		return isJump;//30-06-2017
	}//30-06-2017

	void CalcularTiempoDeVuelo() {//30-06-2017
		gravedad = 9.81;
		tiempoVuelo = 2 * (velocidadInicial*sin(angulo) / gravedad);//30-06-2017
	}//30-06-2017

	void setPuedeAferrarseALianas(bool puedeAferrarseALianas) {//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
		this->puedeAferrarALianas = puedeAferrarALianas;//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
	}//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
	bool getPuedeAferrarseALianas() {//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
		return puedeAferrarALianas;//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
	}//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS


	int getVidasJugador() {//30-06-2017
		return vidas;//30-06-2017
	}//30-06-2017
	void RestarUnaVida() {//30-06-2017
		vidas = vidas - 1;//30-06-2017
	}//30-06-2017

	int getIdentificadorSpriteX() {//30-06-2017
		return identificadorSpriteX;//30-06-2017
	}//30-06-2017
	int getIdentificadorSpriteY() {//30-06-2017
		return  identificadorSpriteY;//30-06-2017
	}//30-06-2017

	void setearValoresInicialesDeNivelLianas(int casosPasarNivel) {//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
		switch (casosPasarNivel) {
		case 0://01-07-2017 PIERDES UNA VIDA
			if (vidas > 1) {//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
				estaEnUnaLiana = false;//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
				isJump = false;//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
							   //direccionY = 1;//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
				puedeAferrarALianas = true;//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
										   //posicionYInicial = posicionY;//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
				vidas = vidas - 1;//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
			}//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
			break;

		case 1://01-07-2017 NO PIERDES NADA
			estaEnUnaLiana = false;//01-07-2017 SETEAR VALORES INICIALES
			isJump = false;//01-07-2017 SETEAR VALORES INICIALES
			puedeAferrarALianas = true;//01-07-2017 SETEAR VALORES INICIALES
			break;
		}

	}//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
	bool DetectarSiCaeDelFormulario(int altoFormulario) {//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
		if (posicionY + alto + desplazamientoY >= altoFormulario) {//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
			return true;//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
		}//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
	}//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
	bool DetectarSiLlegasAlInicioDelFormulario() {//01-07-2017 PARA SABER SI LLEGO AL EXTREMO DEL MAPA
		if (posicionX + ancho + desplazamientoX < 0) {//01-07-2017 PARA SABER SI LLEGO AL EXTREMO DEL MAPA
			return true;//01-07-2017 PARA SABER SI LLEGO AL EXTREMO DEL MAPA
		}//01-07-2017 PARA SABER SI LLEGO AL EXTREMO DEL MAPA
	}//01-07-2017 PARA SABER SI LLEGO AL EXTREMO DEL MAPA
	void AumentarUnaVida() {//01-07-2017 PARA AUMENTAR VIDA
		vidas = vidas + 1;//01-07-2017 PARA AUMENTAR VIDA
	}//01-07-2017 PARA AUMENTAR VIDA


	void AgregarArmaAlArreglo(int posicionX, int posicionY, int desplazamientoX,
		int direccionX, int ancho, int alto, int tipoArma) {//01-07-2017 ARMA
		arregloArmas.AgregarArma(posicionX, posicionY, desplazamientoX, direccionX, ancho, alto, tipoArma);//01-07-2017 ARMA
	}//01-07-2017 ARMA
	void MoverArmas() {//01-07-2017 ARMA
		arregloArmas.MoverArmas();//01-07-2017 ARMA
	}//01-07-2017 ARMA
	void DibujarArmas(Graphics^ grArma, Bitmap^ bmpArma, Rectangle areaVisible) {//01-07-2017 ARMA
		arregloArmas.DibujarArmas(grArma, bmpArma, areaVisible);//01-07-2017 ARMA
	}//01-07-2017 ARMA
	CArregloArmas getArregloArmas() {//01-07-2017 ARMA
		return arregloArmas;//01-07-2017 ARMA
	}//01-07-2017 ARMA
};
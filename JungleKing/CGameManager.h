#pragma once
#include"CArregloLianas.h"
#include"CJugador.h"
#include"CArregloNiveles.h"//30-06-2017
#include"CNivelLianas.h"
#include"CArregloRocas.h"//30-06-2017 NIVEL COLINA
#include"CArregloEnemigoNativo.h"//01-07-2017 NIVEL RESCATE
#include"CAyudante.h"//01-07-2017 AYUDANTE
#include"CArregloBurbujas.h" //01-07-2017 NIVEL ACUATICO YSIQUE
#include"CArregloTiburon.h" //01-07-2017 NIVEL ACUATICO YSIQUE

class CGameManager {
private:
	CArregloLianas arregloLianas;
	CLiana nuevaLiana;

	CJugador jugador;

	CArregloNiveles arregloNiveles;//30-06-2017

	int nivelActual;

	CArregloRocas arregloRocas;//30-06-2017 NIVEL COLINA
	int timerCrearRoca;//30-06-2017 NIVEL COLINA

	CArregloEnemigoNativo arregloEnemigoNativo;//01-07-2017 NIVEL RESCATE

	bool ignoraColisionJugadorLiana;//01-07-2017 NIVEL LIANAS
	int contadorSetearIgnoraColisionJugadorLiana;//01-07-2017 NIVEL LIANAS

	bool puedesCargarSiguienteNivel;//01-07-2017 PARA CARGAR SIGUIENTE NIVEL

	CAyudante nuevoAyudante;//01-07-2017 AYUDANTE
	bool puedesLlamarAlAyudante;//01-07-2017 AYUDANTE
	bool existeUnAyudante;//01-07-2017 AYUDANTE

	CArregloTiburon listaTiburon;//01-07-2017 NIVEL ACUATICO YSIQUE
	int timerCrearTiburon;//01-07-2017 NIVEL ACUATICO YSIQUE

	CArregloBurbuja listaBurbuja;//01-07-2017 NIVEL ACUATICO YSIQUE
	int timerCrearBurbuja;//01-07-2017 NIVEL ACUATICO YSIQUE

public:
	CGameManager() {
		nivelActual = 2;//30-06-2017
		timerCrearRoca = 0;//30-06-2017 NIVEL COLINA
		ignoraColisionJugadorLiana = false;//01-07-2017 NIVEL LIANAS
		contadorSetearIgnoraColisionJugadorLiana = 0;//01-07-2017 NIVEL LIANAS

		puedesLlamarAlAyudante = true;//01-07-2017 AYUDANTE
		existeUnAyudante = false;//01-07-2017 AYUDANTE

		timerCrearTiburon = 0; //01-07-2017 NIVEL ACUATICO YSIQUE
		timerCrearBurbuja = 0;//01-07-2017 NIVEL ACUATICO YSIQUE
	}
	~CGameManager() {

	}
	void setJugador(int posicionX, int posicionY, int desplazamientoX, int desplazamientoY, int velocidadInicial, int angulo,
		int anchoPersonaje, int altoPersonaje) {
		jugador = CJugador(posicionX, posicionY, desplazamientoX, desplazamientoY, velocidadInicial, angulo,anchoPersonaje,
			altoPersonaje);
	}
	void moverJugador(int contadorCicloRepetitivo) {
		jugador.Saltar(contadorCicloRepetitivo);
	}
	void moverJugadorEnLianas(int teclaOprimida) {
		jugador.MoverEnLiana(teclaOprimida);
	}
	void setJugadorIsJumpBool(bool isJump) {//30-06-2017
		jugador.setIsJumpBool(isJump);//30-06-2017
	}//30-06-2017


	void setJugadorEstaEnUnaLianaBool(bool estaEnUnaLiana) {//30-06-2017
		jugador.setEstaEnUnaLiana(estaEnUnaLiana);//30-06-2017
	}//30-06-2017
	void setJugadorCalcularTiempoDeVuelo() {//30-06-2017
		jugador.CalcularTiempoDeVuelo();//30-06-2017
	}//30-06-2017

	void setJugadorPuedeAferrarALianas(bool aferrarALianas) {//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
		jugador.setPuedeAferrarseALianas(aferrarALianas);//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
	}//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS

	void setNuevoArregloLianas(int capacidadArreglo) {
	//	arregloLianas = CArregloLianas(capacidadArreglo);
	}
	void AgregarLianaALArreglo(int posicionX, int posicionY, int desplazamientoX, int direccionX, int ancho, int alto) {
		//nuevaLiana = CLiana(posicionX, posicionY, desplazamientoX, direccionX, ancho, alto);
		arregloLianas.AgregarLiana(posicionX, posicionY, desplazamientoX, direccionX, ancho, alto);
	}
	void MoverLianas(int posicionXAComparar) {
		arregloLianas.MoverLianas(posicionXAComparar);
	}
	CArregloLianas getArregloLianas() {
		return arregloLianas;
	}
	int getArregloLianasSize() {
		return arregloLianas.getArregloLianasSize();
	}
	CJugador getJugador() {
		return jugador;
	}
	void DetectarColision() {
		switch (nivelActual) {
		case 1: ////01-07-2017 NIVEL LIANAS ANTES ERA 0
			if (ignoraColisionJugadorLiana == false) {//01-07-2017 NIVEL LIANAS
				for (int i = 0; i < arregloLianas.getArregloLianasSize(); i++) {
					Rectangle rLiana(arregloLianas.getLianaEspecifica(i).getPosicionX(),
						arregloLianas.getLianaEspecifica(i).getPosicionY(), 19, 400);
					Rectangle rJugador(jugador.getPosicionX(), jugador.getPosicionY(), jugador.getAncho(),
						jugador.getAlto());
					if (rLiana.IntersectsWith(rJugador)) {
					//	if (jugador.getPuedeAferrarseALianas() == true) {//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
							jugador.setEstaEnUnaLiana(true);

							jugador.setPosicionX(arregloLianas.getLianaEspecifica(i).getPosicionX());

							jugador.setIsJumpBool(false);//30-06-2017
														 //cout << "Hubo colision" << endl;
					//	}//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
					}
				}
			}//01-07-2017 NIVEL LIANAS
			break;

		case 3://30-06-2017 NIVEL COLINA //01-07-2017 ANTES ERA 2
			for (int i = 0; i < arregloRocas.getArregloRocasSize(); i++) {
				Rectangle rRoca(arregloRocas.getRocaEspecifica(i).getPosicionX(),
					arregloRocas.getRocaEspecifica(i).getPosicionY(), 46, 47);
				Rectangle rJugador(jugador.getPosicionX(), jugador.getPosicionY(), jugador.getAncho(),
					jugador.getAlto());
				if (rRoca.IntersectsWith(rJugador)) {
					//jugador.RestarUnaVida(); //01-07-2017 COMENTADO NIVEL COLINA
					arregloRocas.EliminarRocaEspecifica(i);
					arregloRocas.EliminarTodasLasRocas();//01-07-2017
					jugador.setPosicionX(1100);//01-07-2017 NIVEL COLINA
					jugador.setPosicionY(530);//01-07-2017 NIVEL COLINA
					jugador.setearValoresInicialesDeNivelLianas(0);//01-07-2017 NIVEL COLINA
				}
			}
			break;//30-06-2017 NIVEL COLINA

		case 4:
			Rectangle rAyudante(nuevoAyudante.getPosicionX(),nuevoAyudante.getPosicionY(), 69, 59);//01-07-2017 AYUDANTE
			Rectangle rJugador(jugador.getPosicionX(), jugador.getPosicionY(), jugador.getAncho(),
				jugador.getAlto());//01-07-2017 AYUDANTE
			if (rAyudante.IntersectsWith(rJugador) && nuevoAyudante.getPuedeCurarAlJugador()) {//01-07-2017 PARA AUMENTAR VIDA
				jugador.AumentarUnaVida();//01-07-2017 PARA AUMENTAR VIDA
				nuevoAyudante.setPuedeCurarAlJgador(false);
			}//01-07-2017 PARA AUMENTAR VIDA
			break;
		}
		
	}

	void setArregloNivelesNivelLianas(int posicionX, int posicionY) {//30-06-2017
		arregloNiveles.setNivelLianas(posicionX, posicionY);//30-06-2017
	}//30-06-2017
	CArregloNiveles getArregloNiveles() {//30-06-2017
		return arregloNiveles;//30-06-2017
	}//30-06-2017

	void setArregloNivelesColina(int posicionX, int posicionY) {//30-06-2017 NIVEL COLINA
		arregloNiveles.setNivelColina(posicionX, posicionY);//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA


	void setArregloNivelesRescate(int posicionX, int posicionY) {//01-07-2017 NIVEL RESCATE
		arregloNiveles.setNivelRescate(posicionX, posicionY);//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE


	//-------------------------- NIVEL ACUATICO YSIQUE-------------------------------------
	void setArregloNivelAgua(int posicionX, int posicionY) { //01-07-2017 NIVEL ACUATICO YSIQUE
		arregloNiveles.setNivelAgua(posicionX, posicionY); //01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE


	//----------------------------------TIBURONES-------------------------------------------
	void agregarTiburonesALista(int posicionX, int posicionY, int desplazamientoX, int desplazamientoY, int direccionY, int ancho,int alto, //01-07-2017 NIVEL ACUATICO YSIQUE
		int idSpriteX, int idSpriteY) {//01-07-2017 NIVEL ACUATICO YSIQUE
		listaTiburon.agregarTiburon(posicionX, posicionY, desplazamientoX, desplazamientoY, direccionY, ancho, alto, idSpriteX, idSpriteY);//01-07-2017 NIVEL ACUATICO YSIQUE
		timerCrearTiburon = 0;//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE

	void moverTiburones() {//01-07-2017 NIVEL ACUATICO YSIQUE
		listaTiburon.mover();//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE

	CArregloTiburon getListaTiburon() { return listaTiburon; }//01-07-2017 NIVEL ACUATICO YSIQUE

	int	getTimerCrearTiburon() {//01-07-2017 NIVEL ACUATICO YSIQUE
		return timerCrearTiburon;//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE

	void setTimerCrearTiburon(int timerCrearTiburon) {//01-07-2017 NIVEL ACUATICO YSIQUE
		this->timerCrearTiburon = timerCrearTiburon;//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE

	void DetectarTiburonFinal(int anchoFormulario) {//01-07-2017 NIVEL ACUATICO YSIQUE
		listaTiburon.DetectarTiburonFinal(anchoFormulario);//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE


	 //----------------------------------BURBUJAS-------------------------------------------
	void agregarBurbujasALista(int posicionX, int posicionY, int desplazamientoX, int desplazamientoY, int direccionY, int ancho, int alto,//01-07-2017 NIVEL ACUATICO YSIQUE
	int idSpritex, int idSpritey) {//01-07-2017 NIVEL ACUATICO YSIQUE
		listaBurbuja.agregarBurbuja(posicionX, posicionY, desplazamientoX, desplazamientoY, direccionY, ancho, alto, idSpritex, idSpritey);//01-07-2017 NIVEL ACUATICO YSIQUE
		timerCrearTiburon = 0;//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE

	void moverBurbuja() {//01-07-2017 NIVEL ACUATICO YSIQUE
		listaBurbuja.mover();//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE

	CArregloBurbuja getListaBurbuja() { return listaBurbuja; }//01-07-2017 NIVEL ACUATICO YSIQUE

	int getTimerCrearBurbuja() {//01-07-2017 NIVEL ACUATICO YSIQUE
		return timerCrearBurbuja;//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE

	void setTimerCrearBurbuja(int timerCrearBurbuja) {//01-07-2017 NIVEL ACUATICO YSIQUE
		this->timerCrearBurbuja = timerCrearBurbuja;//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE

	void DetectarBurbujaFinal(int alturamaxima) {//01-07-2017 NIVEL ACUATICO YSIQUE
		listaBurbuja.DetectarBurbujaFinal(alturamaxima);//01-07-2017 NIVEL ACUATICO YSIQUE
	}//01-07-2017 NIVEL ACUATICO YSIQUE

	//-------------------------- NIVEL ACUATICO YSIQUE-------------------------------------


	int getNivelActual() {//30-06-2017
		return nivelActual;//30-06-2017
	}//30-06-2017
	void setNivelActual(int nivelActual) {//30-06-2017
		this->nivelActual = nivelActual;//30-06-2017
	}//30-06-2017

	 //30-06-2017 NIVEL COLINA
	void MoverJugadorEnNivelColina(int teclaOprimida) {//30-06-2017 NIVEL COLINA
		jugador.MoverJugadorEnNivelColina(teclaOprimida);//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	void SaltarJugadorEnNivelColina(int contadorCicloRepetitivo, int alturaYAComparar) {//30-06-2017 NIVEL COLINA
		jugador.SaltarJugadorEnNivelColina(contadorCicloRepetitivo, alturaYAComparar);//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA


	void AgregarRocaALArreglo(int posicionX, int posicionY, int desplazamientoX, int desplazamientoY, int direccionY, int ancho,
		int alto) {//30-06-2017 NIVEL COLINA
		arregloRocas.AgregarRoca(posicionX, posicionY, desplazamientoX, desplazamientoY, direccionY,
			ancho, alto);//30-06-2017 NIVEL COLINA
		timerCrearRoca = 0;
	}//30-06-2017 NIVEL COLINA
	void MoverRocas(int altura1, int altura2) {//30-06-2017 NIVEL COLINA
		arregloRocas.MoverRocas(altura1, altura2);//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	CArregloRocas getArregloRocas() {//30-06-2017 NIVEL COLINA
		return arregloRocas;//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	int getTimerCrearRocas() {//30-06-2017 NIVEL COLINA
		return timerCrearRoca;//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	void setTimerCrearRocas(int timerCrearRoca) {//30-06-2017 NIVEL COLINA
		this->timerCrearRoca = timerCrearRoca;//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA
	void DetectarRocasLleganAlFinal(int anchoFormulario) {//30-06-2017 NIVEL COLINA
		arregloRocas.DetectarRocaLleganAlFinal(anchoFormulario);//30-06-2017 NIVEL COLINA
	}//30-06-2017 NIVEL COLINA





	bool getIgnoraColisionJugadorLiana() {//01-07-2017 NIVEL LIANAS
		return ignoraColisionJugadorLiana;//01-07-2017 NIVEL LIANAS
	}//01-07-2017 NIVEL LIANAS

	void setIgnoraColisionJugadorLiana(bool i) {//01-07-2017 NIVEL LIANAS
		this->ignoraColisionJugadorLiana = true;//01-07-2017 NIVEL LIANAS
	}//01-07-2017 NIVEL LIANAS

	void ContadorSetearIgnoraColisionJugadorLiana() {//01-07-2017 NIVEL LIANAS
		if (contadorSetearIgnoraColisionJugadorLiana < 5) {//01-07-2017 NIVEL LIANAS
			contadorSetearIgnoraColisionJugadorLiana++;//01-07-2017 NIVEL LIANAS
		}//01-07-2017 NIVEL LIANAS
		else {//01-07-2017 NIVEL LIANAS
			ignoraColisionJugadorLiana = false;//01-07-2017 NIVEL LIANAS
			contadorSetearIgnoraColisionJugadorLiana = 0;//01-07-2017 NIVEL LIANAS
		}//01-07-2017 NIVEL LIANAS
	}//01-07-2017 NIVEL LIANAS
	void DetectarSiJugadorCaeDelFormulario(int altoFormulario) {//01-07-2017 NIVEL LIANAS
		if (jugador.DetectarSiCaeDelFormulario(altoFormulario)) {//01-07-2017 NIVEL LIANAS
			jugador.setPosicionX(1100);//01-07-2017 NIVEL LIANAS
			jugador.setPosicionY(150);//01-07-2017 NIVEL LIANAS
			jugador.setearValoresInicialesDeNivelLianas(0);//01-07-2017 NIVEL LIANAS
		}//01-07-2017 NIVEL LIANAS
	}//01-07-2017 NIVEL LIANAS
	void DetectarSiJugadorLlegaAlInicioDelFormulario(int posicionX, int posicionY) {//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
		switch (nivelActual) {
		case 1:
			if (jugador.DetectarSiLlegasAlInicioDelFormulario()) {//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
				puedesCargarSiguienteNivel = true;//01-07-2017 PARA CARGAR SIGUIENTE NIVEL
				jugador.setPosicionX(posicionX);//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
				jugador.setPosicionY(posicionY);//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
				jugador.setearValoresInicialesDeNivelLianas(1);//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
				nivelActual = nivelActual + 2;//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
				
			}//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
			break;//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
		}
	
	}//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL


	bool getPuedesCargarSiguienteNivel() {//01-07-2017 PARA CARGAR SIGUIENTE NIVEL
		return puedesCargarSiguienteNivel;//01-07-2017 PARA CARGAR SIGUIENTE NIVEL
	}//01-07-2017 PARA CARGAR SIGUIENTE NIVEL
	void setPuedesCargarSiguienteNivel(bool puedesCargarSiguienteNivel) {//01-07-2017 PARA CARGAR SIGUIENTE NIVEL
		this->puedesCargarSiguienteNivel = puedesCargarSiguienteNivel;//01-07-2017 PARA CARGAR SIGUIENTE NIVEL
	}//01-07-2017 PARA CARGAR SIGUIENTE NIVEL
	/*
	bool getBoolSiJugadorLlegaAlInicioDelFormulario() {//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
		return jugador.DetectarSiLlegasAlInicioDelFormulario();//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
	}//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
	*/

	void AgregarEnemigoNativoArreglo(int posicionX, int posicionY, int desplazamientoX,
		int direccionX, int ancho, int alto) {//01-07-2017 NIVEL RESCATE
		arregloEnemigoNativo.AgregarEnemigoNativo(posicionX, posicionY, desplazamientoX, direccionX, ancho, alto);//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
	void MoverEnemigosNativos(int posicionXAComparar) {//01-07-2017 NIVEL RESCATE
		arregloEnemigoNativo.MoverEnemigosNativos(posicionXAComparar);//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE
	CArregloEnemigoNativo getArregloEnemigoNativo() {//01-07-2017 NIVEL RESCATE
		return arregloEnemigoNativo;//01-07-2017 NIVEL RESCATE
	}//01-07-2017 NIVEL RESCATE

	void LlamarAlAyudante(int posicionX, int posicionY, int desplazamientoX, int direccionX, int ancho,
		int alto) {//01-07-2017 AYUDANTE
		if (puedesLlamarAlAyudante == true) {//01-07-2017 AYUDANTE
			nuevoAyudante = CAyudante(posicionX, posicionY, desplazamientoX, direccionX, ancho, alto);//01-07-2017 AYUDANTE
			puedesLlamarAlAyudante = false;//01-07-2017 AYUDANTE
			existeUnAyudante = true;//01-07-2017 AYUDANTE
			nuevoAyudante.setPuedeCurarAlJgador(true);//01-07-2017 PARA CURAR AL JUGADOR
		}//01-07-2017 AYUDANTE
	}
	void MoverAyudante() {//01-07-2017 AYUDANTE
		if (existeUnAyudante == true) {//01-07-2017 AYUDANTE
			nuevoAyudante.MoverAyudante(jugador.getPosicionX());//01-07-2017 AYUDANTE
		}//01-07-2017 AYUDANTE
	}//01-07-2017 AYUDANTE
	CAyudante getAyudante() {//01-07-2017 AYUDANTE
		return nuevoAyudante;//01-07-2017 AYUDANTE
	}//01-07-2017 AYUDANTE
	void DetectarAyudanteAlSalirDelFormulario(int anchoFormulario) {//01-07-2017 AYUDANTE
		if (existeUnAyudante == true) {//01-07-2017 AYUDANTE
			if (nuevoAyudante.LlegoAlFinalDelFormulario(anchoFormulario+500)) {//01-07-2017 AYUDANTE
				nuevoAyudante.setPosicionX(2000);//01-07-2017 AYUDANTE
				existeUnAyudante = false;//01-07-2017 AYUDANTE
				puedesLlamarAlAyudante = true;//01-07-2017 AYUDANTE
			}//01-07-2017 AYUDANTE
		}//01-07-2017 AYUDANTE
	}//01-07-2017 AYUDANTE


	void AgregarArmaAlArreglo(int posicionX, int posicionY, int desplazamientoX,
		int direccionX, int ancho, int alto, int tipoArma) {//01-07-2017 ARMA
		jugador.AgregarArmaAlArreglo(posicionX, posicionY, desplazamientoX, direccionX, ancho, alto, tipoArma);//01-07-2017 ARMA
	}//01-07-2017 ARMA
	void DibujarArmas(Graphics^ grArma, Bitmap^ bmpArma, Rectangle areaVisible) {//01-07-2017 ARMA
		
	}
	void MoverArmas() {//01-07-2017 ARMA
		jugador.MoverArmas();//01-07-2017 ARMA
	}//01-07-2017 ARMA
	CArregloArmas getArregloArmas() {//01-07-2017 ARMA
		jugador.getArregloArmas();//01-07-2017 ARMA
	}//01-07-2017 ARMA
};
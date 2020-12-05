#pragma once
#include<cmath>
#include"CGameManager.h"

#include<iostream>
using namespace std;
namespace JungleKing {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de JungleKingFormulario
	/// </summary>
	public ref class JungleKingFormulario : public System::Windows::Forms::Form
	{
	public:
		JungleKingFormulario(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			gameManager = new CGameManager();

			bitmapPantallaInicial = gcnew Bitmap("pantallaInicial.png");//01-07-2017 PANTALLA INICIAL
			areaVisiblePantallaInicial = Rectangle(0, 0, 807, 453);//01-07-2017 PANTALLA INICIAL

			bitmapNivelLianas = gcnew Bitmap("fondoLianas.png");//30-06-2017
			areaVisibleNivelLianas = Rectangle(0, 0, 2560, 720);//30-06-2017

			bitmapNivelColina = gcnew Bitmap("fondoColina.png");//30-06-2017 NIVEL COLINA
			areaVisibleNivelColina = Rectangle(0, 0, 2560, 720);//30-06-2017 NIVEL COLINA

			bitmapNivelRescate = gcnew Bitmap("fondoRescatar.png");//01-07-2017 NIVEL RESCATE
			areaVisibleNivelRescate = Rectangle(0, 0, 2560, 720);//01-07-2017 NIVEL RESCATE

			bitmapLiana = gcnew Bitmap("liana.png");
			areaVisibleLiana = Rectangle(0,0,19, 400);

			bitmapRoca = gcnew Bitmap("roca.png");//30-06-2017 NIVEL COLINA
			areaVisibleRoca = Rectangle(0, 0, 46, 47);//30-06-2017 NIVEL COLINA

			bitmapEnemigoNativo = gcnew Bitmap("enemigoNativo.png");//01-07-2017 PANTALLA INICIAL
			areaVisibleEnemigoNativo = Rectangle(0, 0, 60, 56);//01-07-2017 PANTALLA INICIAL

			bitmapAyudante = gcnew Bitmap("ayudante.png");//01-07-2017 AYUDANTE
			areaVisibleAyudante = Rectangle(0, 0, 69, 59);//01-07-2017 AYUDANTE

			bitmapArma1 = gcnew Bitmap("arma1.png");//01-07-2017 ARMA
			areaVisibleArma1 = Rectangle(0, 0, 34, 6);//01-07-2017 ARMA

			bitmapJugador = gcnew Bitmap("personaje.png");
			anchoPersonaje = bitmapJugador->Width/6;
			altoPersonaje = bitmapJugador->Height / 2;
			areaVisibleJugador = Rectangle(0, 0, anchoPersonaje, altoPersonaje);
			contadorSaltoJugador = 0;

			bitmapNivelAgua = gcnew Bitmap("fondoAgua.png");//01-07-2017 NIVEL ACUATICO YSIQUE
			aVisibleNivelAgua = Rectangle(0, 0, 2560, 720);//01-07-2017 NIVEL ACUATICO YSIQUE

			bitmapTiburon = gcnew Bitmap("shark.png");//01-07-2017 NIVEL ACUATICO YSIQUE
			idSpriteXTib = 0;//01-07-2017 NIVEL ACUATICO YSIQUE
			idSpriteYTib = 0;//01-07-2017 NIVEL ACUATICO YSIQUE

			bitmapBurbuja = gcnew Bitmap("bubbles.png");//01-07-2017 NIVEL ACUATICO YSIQUE
			idSpriteXBur = 0;//01-07-2017 NIVEL ACUATICO YSIQUE
			idSpriteYBur = 0;//01-07-2017 NIVEL ACUATICO YSIQUE
			
			r = gcnew System::Random(System::DateTime::Now.Ticks);//30-06-2017

			//
			//TODO: agregar código de constructor aquí
			//
		}
	private:
		Graphics^ gr;
		BufferedGraphics^ buffer;
		BufferedGraphicsContext^ bufferContexto;

		Bitmap^ bitmapPantallaInicial;//01-07-2017 PANTALLA INICIAL
		Rectangle areaVisiblePantallaInicial;//01-07-2017 PANTALLA INICIAL
		Rectangle destino;//01-07-2017 PANTALLA INICIAL

		Bitmap^ bitmapNivelLianas;//30-06-2017
		Rectangle areaVisibleNivelLianas;//30-06-2017

		Bitmap^ bitmapNivelColina;//30-06-2017 NIVEL COLINA
		Rectangle areaVisibleNivelColina;//30-06-2017 NIVEL COLINA

		Bitmap^ bitmapNivelRescate;//01-07-2017 NIVEL RESCATE
		Rectangle areaVisibleNivelRescate;//01-07-2017 NIVEL RESCATE

		Bitmap^ bitmapLiana;
		Rectangle areaVisibleLiana;

		Bitmap^ bitmapRoca;//30-06-2017 NIVEL COLINA
		Rectangle areaVisibleRoca;//30-06-2017 NIVEL COLINA

		Bitmap^ bitmapEnemigoNativo;//01-07-2017 NIVEL RESCATE
		Rectangle areaVisibleEnemigoNativo;//01-07-2017 NIVEL RESCATE

		Bitmap^ bitmapAyudante;//01-07-2017 AYUDANTE
		Rectangle areaVisibleAyudante;//01-07-2017 AYUDANTE

		Bitmap^ bitmapArma1;//01-07-2017 ARMA
		Rectangle areaVisibleArma1;//01-07-2017 ARMA

		Bitmap^ bitmapJugador; //01-07-2017 NIVEL ACUATICO YSIQUE
		Rectangle areaVisibleJugador;//01-07-2017 NIVEL ACUATICO YSIQUE
		int anchoPersonaje;//01-07-2017 NIVEL ACUATICO YSIQUE
		int altoPersonaje;//01-07-2017 NIVEL ACUATICO YSIQUE
		int contadorSaltoJugador;//01-07-2017 NIVEL ACUATICO YSIQUE

		Bitmap ^bitmapTiburon;//01-07-2017 NIVEL ACUATICO YSIQUE
		Rectangle aVisibleTiburon;//01-07-2017 NIVEL ACUATICO YSIQUE
		int anchoTiburon;//01-07-2017 NIVEL ACUATICO YSIQUE
		int altoTiburon;//01-07-2017 NIVEL ACUATICO YSIQUE
		int idSpriteXTib;//01-07-2017 NIVEL ACUATICO YSIQUE
		int idSpriteYTib;//01-07-2017 NIVEL ACUATICO YSIQUE

		Bitmap ^bitmapBurbuja;//01-07-2017 NIVEL ACUATICO YSIQUE
		Rectangle aVisibleBurbuja;//01-07-2017 NIVEL ACUATICO YSIQUE
		int anchoBurbuja;//01-07-2017 NIVEL ACUATICO YSIQUE
		int altoBurbuja;//01-07-2017 NIVEL ACUATICO YSIQUE
		int idSpriteXBur;//01-07-2017 NIVEL ACUATICO YSIQUE
		int idSpriteYBur;//01-07-2017 NIVEL ACUATICO YSIQUE

		Bitmap ^bitmapNivelAgua;
		Rectangle aVisibleNivelAgua;


		CGameManager* gameManager;

		System::Random^ r;//30-06-2017
	private: System::Windows::Forms::Label^  lblJugadorVidas;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Timer^  timer1;
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~JungleKingFormulario()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblJugadorVidas = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &JungleKingFormulario::timer1_Tick);
			// 
			// lblJugadorVidas
			// 
			this->lblJugadorVidas->AutoSize = true;
			this->lblJugadorVidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblJugadorVidas->Location = System::Drawing::Point(1118, 9);
			this->lblJugadorVidas->Name = L"lblJugadorVidas";
			this->lblJugadorVidas->Size = System::Drawing::Size(134, 37);
			this->lblJugadorVidas->TabIndex = 0;
			this->lblJugadorVidas->Text = L"Vidas: 3";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(896, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(197, 37);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Energía: 100";
			// 
			// JungleKingFormulario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 682);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblJugadorVidas);
			this->Name = L"JungleKingFormulario";
			this->Text = L"JungleKingFormulario";
			this->Load += gcnew System::EventHandler(this, &JungleKingFormulario::JungleKingFormulario_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JungleKingFormulario::JungleKingFormulario_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &JungleKingFormulario::JungleKingFormulario_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void CargarElementosPorNivel() {
			switch (gameManager->getNivelActual()) {
			case 1://30-06-2017 NIVEL LIANAS //01-07-2017 ANTES ERA CASO 0
				gameManager->setArregloNivelesNivelLianas(-1180, 0);//30-06-2017
				gameManager->AgregarLianaALArreglo(800, 0, 5, -1, 20, 400);
				gameManager->AgregarLianaALArreglo(300, 0, 5, 1, 20, 400);
				gameManager->setJugador(1100, 150, 20, 20, 20, 45, anchoPersonaje, altoPersonaje);
				cout << "SE LLAMO 1" << endl;
				break;//30-06-2017 NIVEL LIANAS

			case 2://01-07-2017 AQUI YSIQUE SE AÑADEN LOS ELEMENTOS INICIALES, COMO EL MAPA POR EJEMPLO
				gameManager->setArregloNivelAgua(-1180,0);//01-07-2017 NIVEL AGUA
				gameManager->setJugador(1100, 400, 20, 20, 20, 45, anchoPersonaje, altoPersonaje);//01-07-2017 NIVEL AGUA
				gameManager->agregarTiburonesALista(0, r->Next(400, 650), r->Next(10, 25), r->Next(10, 25), 1, 86, 50, idSpriteXTib, idSpriteYTib);//01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->agregarBurbujasALista(0, r->Next(400, 650), r->Next(10, 25), r->Next(10, 25), 1, 86, 50, idSpriteXTib, idSpriteYTib);//01-07-2017 NIVEL ACUATICO YSIQUE
				break;//01-07-2017 AQUI YSIQUE

			case 3://30-06-2017 NIVEL COLINA //01-07-2017 ANTES ERA CASO 2
				gameManager->setArregloNivelesColina(-1180, 0);//30-06-2017

				/* //01-07-2017 FUE COMETANDO PARA EVITAR QUE CREE UN NUEVO PERSONAJE
				gameManager->setJugador(1100, 530, 20, 20, 20, 45, anchoPersonaje, altoPersonaje);//30-06-2017
				*/ //01-07-2017 FUE COMETANDO PARA EVITAR QUE CREE UN NUEVO PERSONAJE
				gameManager->AgregarRocaALArreglo(0, 500, 10, 10, 1,
					46, 47);//30-06-2017 NIVEL COLINA
				cout << "SE LLAMO 3" << endl;
				break;//30-06-2017 NIVEL COLINA

			case 4: //01-07-2017 NIVEL RESCATE
				gameManager->setArregloNivelesRescate(-1180, 0);//01-07-2017 NIVEL RESCATE
				gameManager->AgregarEnemigoNativoArreglo(800, 600, 5, -1, 20, 400);//01-07-2017 NIVEL RESCATE
				gameManager->AgregarEnemigoNativoArreglo(300, 600, 5, 1, 20, 400);//01-07-2017 NIVEL RESCATE


				 //01-07-2017 FUE COMETANDO PARA EVITAR QUE CREE UN NUEVO PERSONAJE
				gameManager->setJugador(1100, 575, 20, 20, 20, 45, anchoPersonaje, altoPersonaje);//30-06-2017
				 //01-07-2017 FUE COMETANDO PARA EVITAR QUE CREE UN NUEVO PERSONAJE


				cout << "SE LLAMO 4" << endl;
				break;//01-07-2017 NIVEL RESCATE
			}
			
		}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//--------------------TIBURON ESTA ES LA PARTE DONDE NO PUDE INTEGRARLO EN PRIVATE------------------------
		anchoTiburon = bitmapTiburon->Width / 3;//01-07-2017 NIVEL ACUATICO YSIQUE
		altoTiburon = bitmapTiburon->Height / 4;//01-07-2017 NIVEL ACUATICO YSIQUE
		aVisibleTiburon = Rectangle(anchoTiburon*idSpriteXTib, altoTiburon*idSpriteYTib, 86, 50);//01-07-2017 NIVEL ACUATICO YSIQUE
		idSpriteXTib++;//01-07-2017 NIVEL ACUATICO YSIQUE
		idSpriteYTib++;//01-07-2017 NIVEL ACUATICO YSIQUE
		if (idSpriteXTib >= 3) {//01-07-2017 NIVEL ACUATICO YSIQUE
			idSpriteXTib = 0;//01-07-2017 NIVEL ACUATICO YSIQUE
		}//01-07-2017 NIVEL ACUATICO YSIQUE
		if (idSpriteYTib >= 2) {//01-07-2017 NIVEL ACUATICO YSIQUE
			idSpriteYTib = 0;//01-07-2017 NIVEL ACUATICO YSIQUE
		}//01-07-2017 NIVEL ACUATICO YSIQUE

		//---------------------BURBUJAS ESTA ES LA PARTE DONDE NO PUDE INTEGRARLO EN PRIVATE-------------------------
		anchoBurbuja = bitmapBurbuja->Width / 4;//01-07-2017 NIVEL ACUATICO YSIQUE
		altoBurbuja = bitmapBurbuja->Height;//01-07-2017 NIVEL ACUATICO YSIQUE
		aVisibleBurbuja = Rectangle(anchoBurbuja*idSpriteXBur, altoBurbuja*idSpriteYBur, 68, 46);//01-07-2017 NIVEL ACUATICO YSIQUE
		idSpriteXBur++;//01-07-2017 NIVEL ACUATICO YSIQUE
		if (idSpriteXBur >= 3) {//01-07-2017 NIVEL ACUATICO YSIQUE
			idSpriteXBur = 0;//01-07-2017 NIVEL ACUATICO YSIQUE
		}//01-07-2017 NIVEL ACUATICO YSIQUE

		bufferContexto = BufferedGraphicsManager::Current;
		
		switch (gameManager->getNivelActual()) {
		case 0://01-07-2017 PANTALLA INICIAL
			/*
			destino = Rectangle(0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);//01-07-2017 PANTALLA INICIAL
			buffer->Graphics->DrawImage(bitmapPantallaInicial, destino, areaVisiblePantallaInicial,
				GraphicsUnit::Pixel);//01-07-2017 PANTALLA INICIAL
			break;//01-07-2017 PANTALLA INICIAL
			*/
		case 1://30-06-2017 NIVEL LIANAS //01-07-2017 ANTES ERA CASO 0
			gameManager->MoverLianas(150);
			if (gameManager->getJugador().getIsJumpBool() == true) {//30-06-2017
				contadorSaltoJugador = contadorSaltoJugador + 1;
				gameManager->moverJugador(contadorSaltoJugador);
			}
			else {//30-06-2017
				contadorSaltoJugador = 0;//30-06-2017
			}//30-06-2017

			if (gameManager->getIgnoraColisionJugadorLiana() == true) {//01-07-2017 NIVEL LIANAS
				gameManager->ContadorSetearIgnoraColisionJugadorLiana();//01-07-2017 NIVEL LIANAS
			}//01-07-2017 NIVEL LIANAS

			gameManager->DetectarColision();

			gameManager->DetectarSiJugadorCaeDelFormulario(this->ClientRectangle.Height);//01-07-2017 NIVEL LIANAS
			areaVisibleJugador = Rectangle(anchoPersonaje * 0, altoPersonaje * 0, anchoPersonaje, altoPersonaje);
			gameManager->DetectarSiJugadorLlegaAlInicioDelFormulario(1100, 530);//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL

			if (gameManager->getPuedesCargarSiguienteNivel()) {//01-07-2017 PARA CARGAR SIGUIENTE NIVEL
				CargarElementosPorNivel();//01-07-2017 PARA CARGAR SIGUIENTE NIVEL
				gameManager->setPuedesCargarSiguienteNivel(false);//01-07-2017 PARA CARGAR SIGUIENTE NIVEL
			}//01-07-2017 PARA CARGAR SIGUIENTE NIVEL

			/*
			if (gameManager->getJugador().DetectarSiLlegasAlInicioDelFormulario()) {//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
				CargarElementosPorNivel();//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL
			}//01-07-2017 PARA CARGAR EL SIGUIENTE NIVEL

			*/
			/*
			if (gameManager->getJugador().getPosicionY() >= 720) {//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
				gameManager->getJugador().setPosicionX(1100);//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
				gameManager->getJugador().setPosicionY(530);//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
				gameManager->getJugador().setearValoresInicialesDeNivelLianas();//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
			}//01-07-2017 SETEAR VALORES INICIALES NIVEL LIANAS
			*/

			//gameManager->getJugador().Saltar(contadorSaltoJugador);
			break;//30-06-2017 NIVEL LIANAS

		case 2://01-07-2017 AQUI YSIQUE TODO LO QUE NO SEA GRÁFICO
			if (gameManager->getListaTiburon().getListaTiburonTamaño()<2 && gameManager->getTimerCrearTiburon() >= 20) { ////01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->agregarTiburonesALista(0, r->Next(400, 650), r->Next(10, 25), r->Next(10, 25), 1, 86, 50, idSpriteXTib, idSpriteYTib);//01-07-2017 NIVEL ACUATICO YSIQUE
			}//01-07-2017 NIVEL ACUATICO YSIQUE

			if (gameManager->getListaBurbuja().getListaBurbujaTamaño()<2 && gameManager->getTimerCrearBurbuja() >= 20){//01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->agregarBurbujasALista(r->Next(0, 640), 600, 2, 2, 4, 68, 46, idSpriteXBur, idSpriteYBur);//01-07-2017 NIVEL ACUATICO YSIQUE
			}//01-07-2017 NIVEL ACUATICO YSIQUE

			if (gameManager->getListaTiburon().getListaTiburonTamaño()<2) {//01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->setTimerCrearTiburon(gameManager->getTimerCrearTiburon() + 1);//01-07-2017 NIVEL ACUATICO YSIQUE
			}//01-07-2017 NIVEL ACUATICO YSIQUE

			if (gameManager->getListaBurbuja().getListaBurbujaTamaño()<2) {//01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->setTimerCrearBurbuja(gameManager->getTimerCrearBurbuja() + 10);//01-07-2017 NIVEL ACUATICO YSIQUE
			}//01-07-2017 NIVEL ACUATICO YSIQUE

			if (gameManager->getListaTiburon().getListaTiburonTamaño()>0) {//01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->moverTiburones();//01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->DetectarTiburonFinal(this->ClientRectangle.Width);//01-07-2017 NIVEL ACUATICO YSIQUE
			}//01-07-2017 NIVEL ACUATICO YSIQUE

			if (gameManager->getListaBurbuja().getListaBurbujaTamaño()>0) {//01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->moverBurbuja();//01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->DetectarBurbujaFinal(380);//01-07-2017 NIVEL ACUATICO YSIQUE
			}//01-07-2017 NIVEL ACUATICO YSIQUE

			break;//01-07-2017 AQUI YSIQUE

		case 3://30-06-2017 NIVEL COLINA //01-07-2017 ANTES ERA CASO 1
			if (gameManager->getJugador().getIsJumpBool() == true) {//30-06-2017 NIVEL COLINA
				contadorSaltoJugador = contadorSaltoJugador + 1;//30-06-2017 NIVEL COLINA
				gameManager->SaltarJugadorEnNivelColina(contadorSaltoJugador, 100);//30-06-2017 NIVEL COLINA
			}//30-06-2017 NIVEL COLINA
			if (gameManager->getArregloRocas().getArregloRocasSize() < 2 && 
				gameManager->getTimerCrearRocas() >=30) {//30-06-2017 NIVEL COLINA
				gameManager->AgregarRocaALArreglo(0, 500, r->Next(10,20), r->Next(10, 20), 1,
					46, 47);//30-06-2017 NIVEL COLINA
				/*
				gameManager->AgregarRocaALArreglo(0, 500, 10, 10, 1, 
					46, 47);//30-06-2017 NIVEL COLINA
					*/
			}
			if (gameManager->getArregloRocas().getArregloRocasSize() < 2) {//30-06-2017 NIVEL COLINA
				gameManager->setTimerCrearRocas(gameManager->getTimerCrearRocas() + 1);//30-06-2017 NIVEL COLINA
			}//30-06-2017 NIVEL COLINA
			if (gameManager->getArregloRocas().getArregloRocasSize() > 0) {//30-06-2017 NIVEL COLINA
				gameManager->MoverRocas(600, 420);//30-06-2017 NIVEL COLINA
				gameManager->DetectarRocasLleganAlFinal(this->ClientRectangle.Width);//30-06-2017 NIVEL COLINA
			}//30-06-2017 NIVEL COLINA
			gameManager->DetectarColision();//30-06-2017 NIVEL COLINA
			break;//30-06-2017 NIVEL COLINA
			
		case 4://01-07-2017 NIVEL RESCATE
			gameManager->MoverEnemigosNativos(80);//01-07-2017 NIVEL RESCATE

			gameManager->MoverAyudante();//01-07-2017 AYUDANTE
			//gameManager->getAyudante().MoverAyudante(gameManager->getJugador().getPosicionX());//01-07-2017 AYUDANTE
			gameManager->DetectarAyudanteAlSalirDelFormulario(this->ClientRectangle.Width);//01-07-2017 AYUDANTE
			gameManager->DetectarColision();//01-07-2017 AYUDANTE


			//gameManager->getJugador().MoverArmas();//01-07-2017 ARMA
			gameManager->MoverArmas();//01-07-2017 ARMA

			if (gameManager->getJugador().getIsJumpBool() == true) {//01-07-2017 NIVEL RESCATE
				contadorSaltoJugador = contadorSaltoJugador + 1;//01-07-2017 NIVEL RESCATE
				gameManager->SaltarJugadorEnNivelColina(contadorSaltoJugador, 100);//01-07-2017 NIVEL RESCATE
			}//01-07-2017 NIVEL RESCATE
			break;//01-07-2017 NIVEL RESCATE
		}
		

		
		buffer = bufferContexto->Allocate(gr, this->ClientRectangle);
		buffer->Graphics->Clear(System::Drawing::Color::White);



		switch (gameManager->getNivelActual()) {
		case 0://01-07-2017 PANTALLA INICIAL
			destino = Rectangle(0, 0, this->ClientRectangle.Width, this->ClientRectangle.Height);//01-07-2017 PANTALLA INICIAL
			buffer->Graphics->DrawImage(bitmapPantallaInicial, destino, areaVisiblePantallaInicial,
				GraphicsUnit::Pixel);//01-07-2017 PANTALLA INICIAL

			lblJugadorVidas->Text = "";
			break;//01-07-2017 PANTALLA INICIAL

		case 1://30-06-2017 NIVEL LIANAS //01-07-2017 ANTES ERA CASO 0
			gameManager->getArregloNiveles().getNivelesLianas().DibujarNivelLianas(buffer->Graphics, bitmapNivelLianas,
				areaVisibleNivelLianas);//30-06-2017

			gameManager->getArregloLianas().DibujarLianas(buffer->Graphics, bitmapLiana, areaVisibleLiana);
			if (gameManager->getJugador().getEstaEnUnaLiana() == true) {
				areaVisibleJugador = Rectangle(anchoPersonaje * 1, altoPersonaje * 1, anchoPersonaje, altoPersonaje);
				//	cout << "Bien hecho muchacho";
			}
			if (gameManager->getJugador().getIsJumpBool() == true) {
				areaVisibleJugador = Rectangle(anchoPersonaje * 1, altoPersonaje * 0, anchoPersonaje, altoPersonaje);
			}
			gameManager->getJugador().DibujarJugador(buffer->Graphics, bitmapJugador, areaVisibleJugador);

			lblJugadorVidas->Text = "VIDAS: " + Convert::ToString(gameManager->getJugador().getVidasJugador());
			break;


		case 2://01-07-2017 AQUI YSIQUE TODO LO QUE SEA GRÁFICO
			gameManager->getJugador().DibujarJugador(buffer->Graphics, bitmapJugador, areaVisibleJugador);//01-07-2017 NIVEL AGUA

			gameManager->getListaTiburon().dibujarTiburon(buffer->Graphics, bitmapTiburon, aVisibleTiburon);//01-07-2017 NIVEL ACUATICO YSIQUE
			gameManager->getListaBurbuja().dibujarBurbuja(buffer->Graphics, bitmapBurbuja, aVisibleBurbuja);//01-07-2017 NIVEL ACUATICO YSIQUE

			gameManager->getArregloNiveles().getNivelesAgua().dibujarNivelAgua(buffer->Graphics, bitmapNivelAgua, aVisibleNivelAgua);//01-07-2017 NIVEL ACUATICO YSIQUE

			if (gameManager->getListaTiburon().getListaTiburonTamaño() > 0) {//01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->getListaTiburon().dibujarTiburon(buffer->Graphics, bitmapTiburon, aVisibleTiburon);//01-07-2017 NIVEL ACUATICO YSIQUE
			}//01-07-2017 NIVEL ACUATICO YSIQUE

			if (gameManager->getListaBurbuja().getListaBurbujaTamaño()>0){//01-07-2017 NIVEL ACUATICO YSIQUE
				gameManager->getListaBurbuja().dibujarBurbuja(buffer->Graphics, bitmapBurbuja, aVisibleBurbuja);//01-07-2017 NIVEL ACUATICO YSIQUE
			}

			break;//01-07-2017 AQUI YSIQUE

		case 3://30-06-2017 NIVEL COLINA //01-07-2017 ANTES ERA CASO 2
			gameManager->getArregloNiveles().getNivelesColina().DibujarNivelColina(buffer->Graphics, bitmapNivelColina,
				areaVisibleNivelLianas);//30-06-2017 NIVEL COLINA
			gameManager->getJugador().DibujarJugador(buffer->Graphics, bitmapJugador, areaVisibleJugador);
			if (gameManager->getArregloRocas().getArregloRocasSize() > 0) {//30-06-2017 NIVEL COLINA
				gameManager->getArregloRocas().DibujarRoca(buffer->Graphics, bitmapRoca, areaVisibleRoca);//30-06-2017 NIVEL COLINA
			}//30-06-2017 NIVEL COLINA

			lblJugadorVidas->Text = "VIDAS: " + Convert::ToString(gameManager->getJugador().getVidasJugador());
			break; //30-06-2017 NIVEL COLINA

		case 4://01-07-2017 NIVEL RESCATE
			gameManager->getArregloNiveles().getNivelesRescate().DibujarNivelRescate(buffer->Graphics, bitmapNivelRescate,
				areaVisibleNivelRescate);//01-07-2017 NIVEL RESCATE
			gameManager->getArregloEnemigoNativo().DibujarEnemigosNativos(buffer->Graphics,
				bitmapEnemigoNativo, areaVisibleEnemigoNativo);//01-07-2017 NIVEL RESCATE
			gameManager->getJugador().DibujarJugador(buffer->Graphics, bitmapJugador, areaVisibleJugador);//01-07-2017 NIVEL RESCATE

			gameManager->getAyudante().DibujarAyudante(buffer->Graphics, bitmapAyudante, areaVisibleAyudante);//01-07-2017 AYUDANTE

			/*
			if (gameManager->getArregloArmas().getArregloArmasSize() > 0) {
				gameManager->armas(buffer->Graphics, bitmapArma1,
					areaVisibleArma1);//01-07-2017 ARMA
					*/
			if (gameManager->getJugador().getArregloArmas().getArregloArmasSize() > 0) {//01-07-2017 ARMA
				gameManager->getJugador().DibujarArmas(buffer->Graphics, bitmapArma1,
					areaVisibleArma1);//01-07-2017 ARMA
				gameManager->getJugador().getArregloArmas().MoverArmas();//01-07-2017 ARMA
			}//01-07-2017 ARMA
			/*
			if (gameManager->getJugador().getArregloArmas().getArregloArmasSize() > 0) {//01-07-2017 ARMA
				gameManager->getJugador().getArregloArmas().DibujarArmas(buffer->Graphics, bitmapArma1,
					areaVisibleArma1);//01-07-2017 ARMA
				gameManager->getJugador().getArregloArmas().MoverArmas();//01-07-2017 ARMA
			}//01-07-2017 ARMA
			*/


			lblJugadorVidas->Text = "VIDAS: " + Convert::ToString(gameManager->getJugador().getVidasJugador());//01-07-2017 NIVEL RESCATE
			break;//01-07-2017 NIVEL RESCATE
		}//30-06-2017

		buffer->Render(gr);
	
		
	//	cout << gameManager->getArregloLianasSize();
	}
	
	private: System::Void JungleKingFormulario_Load(System::Object^  sender, System::EventArgs^  e) {
	//	gameManager->getArregloLianas().AgregarLiana(200, 200, 10, 1, 14, 82);
		CargarElementosPorNivel();//01-07-2017
		/*
		switch (gameManager->getNivelActual()) {
		case 1://30-06-2017 NIVEL LIANAS //01-07-2017 ANTES ERA CASO 0
			gameManager->setArregloNivelesNivelLianas(-1180, 0);//30-06-2017
			gameManager->AgregarLianaALArreglo(800, 0, 5, -1, 20, 400);
			gameManager->AgregarLianaALArreglo(300, 0, 5, 1, 20, 400);
			gameManager->setJugador(1100, 150, 20, 20, 20, 45, anchoPersonaje, altoPersonaje);
			break;//30-06-2017 NIVEL LIANAS

		case 3://30-06-2017 NIVEL COLINA //01-07-2017 ANTES ERA CASO 2
			gameManager->setArregloNivelesColina(-1180, 0);//30-06-2017
			gameManager->setJugador(1100, 530, 20, 20, 20, 45, anchoPersonaje, altoPersonaje);//30-06-2017
			gameManager->AgregarRocaALArreglo(0, 500, 10, 10, 1,
				46, 47);//30-06-2017 NIVEL COLINA
			break;//30-06-2017 NIVEL COLINA
		}
		*/
	
	//	gameManager->getArregloLianas().AgregarLiana(200, 200, 10, 1, 14, 82);
	}
	private: System::Void JungleKingFormulario_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (gameManager->getNivelActual()) {
		case 3://30-06-2017 NIVEL COLINA //01-07-2017 ANTES ERA CASO 2
			if (e->KeyCode == Keys::Left) {//30-06-2017 NIVEL COLINA
				gameManager->MoverJugadorEnNivelColina(1);//30-06-2017 NIVEL COLINA
			}//30-06-2017 NIVEL COLINA
			if (e->KeyCode == Keys::Right) {//30-06-2017 NIVEL COLINA
				gameManager->MoverJugadorEnNivelColina(2);//30-06-2017 NIVEL COLINA
			}//30-06-2017 NIVEL COLINA
			break;//30-06-2017 NIVEL COLINA

		case 4://01-07-2017 NIVEL RESCATE
			if (e->KeyCode == Keys::Left) {//01-07-2017 NIVEL RESCATE
				gameManager->MoverJugadorEnNivelColina(1);//01-07-2017 NIVEL RESCATE
			}//01-07-2017 NIVEL RESCATE
			if (e->KeyCode == Keys::Right) {//01-07-2017 NIVEL RESCATE
				gameManager->MoverJugadorEnNivelColina(2);//01-07-2017 NIVEL RESCATE
			}//01-07-2017 NIVEL RESCATE
			break;//01-07-2017 NIVEL RESCATE
		}
		
	}
private: System::Void JungleKingFormulario_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	switch (gameManager->getNivelActual()) {
	case 0://01-07-2017 PANTALLA INICIAL
		if (e->KeyCode == Keys::Enter) {//01-07-2017 PANTALLA INICIAL
			gameManager->setNivelActual(1);//01-07-2017 PANTALLA INICIAL
			CargarElementosPorNivel();//01-07-2017
		}//01-07-2017 PANTALLA INICIAL
		break;//01-07-2017 PANTALLA INICIAL
	case 1://30-06-2017 NIVEL LIANAS //01-07-2017 ANTES ERA CASO 0
		if (e->KeyCode == Keys::Z) {
			if (gameManager->getJugador().getEstaEnUnaLiana()) {//01-07-2017
				gameManager->setIgnoraColisionJugadorLiana(true);
			}
			//MessageBox::Show("OC");
			//gameManager->getJugador().setIsJumpBool(true);
			/*
			if (gameManager->getJugador().getEstaEnUnaLiana() == true) {
				gameManager->setJugadorPuedeAferrarALianas(false);//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
			}
			*/
			gameManager->setJugadorIsJumpBool(true);//30-06-2017
			gameManager->setJugadorEstaEnUnaLianaBool(false);//30-06-2017
		//	gameManager->setJugadorPuedeAferrarALianas(false);//30-06-2017 PARA PODER SALTAR A OTRAS LIANAS
		}
		if (e->KeyCode == Keys::Up) {
			gameManager->moverJugadorEnLianas(2);
		}
		else if (e->KeyCode == Keys::Down) {
			gameManager->moverJugadorEnLianas(1);
		}
		break;//30-06-2017 NIVEL LIANAS

	case 3://30-06-2017 NIVEL COLINA //01-07-2017 ANTES ERA CASO 2
		if (e->KeyCode == Keys::Z) {//30-06-2017 NIVEL COLINA
			gameManager->setJugadorIsJumpBool(true);//30-06-2017 NIVEL COLINA
		}//30-06-2017 NIVEL COLINA
		break;//30-06-2017 NIVEL COLINA

	case 4://01-07-2017 NIVEL RESCATE
		if (e->KeyCode == Keys::Z) {//01-07-2017 NIVEL RESCATE
			gameManager->setJugadorIsJumpBool(true);//01-07-2017 NIVEL RESCATE
		}//01-07-2017 NIVEL RESCATE
		
		if (e->KeyCode == Keys::C) {//01-07-2017 AYUDANTE
			gameManager->LlamarAlAyudante(1200, 600, 10, -1, 69, 59);//01-07-2017 AYUDANTE
		}//01-07-2017 AYUDANTE
		if (e->KeyCode == Keys::X) {
		//	MessageBox::Show("IZI");
			
			gameManager->AgregarArmaAlArreglo(
				(gameManager->getJugador().getPosicionX() + gameManager->getJugador().getAncho() / 2) ,
				(gameManager->getJugador().getPosicionY() + gameManager->getJugador().getAlto() / 2) ,
				20, -1, 34, 6, 0);//01-07-2017 ARMA

				/*
			gameManager->getJugador().AgregarArmaAlArreglo(
				(gameManager->getJugador().getPosicionX() + gameManager->getJugador().getAncho()) / 2,
				(gameManager->getJugador().getPosicionY() + gameManager->getJugador().getAlto()) / 2,
				20, -1, 34, 6, 0);//01-07-2017 ARMA
				*/
		}
		break;//01-07-2017 NIVEL RESCATE

		/*
	case 1://30-06-2017 NIVEL COLINA
		if (e->KeyCode == Keys::Left) {//30-06-2017 NIVEL COLINA
			gameManager->MoverJugadorEnNivelColina(1);//30-06-2017 NIVEL COLINA
		}//30-06-2017 NIVEL COLINA
		if (e->KeyCode == Keys::Right) {//30-06-2017 NIVEL COLINA
			gameManager->MoverJugadorEnNivelColina(2);//30-06-2017 NIVEL COLINA
		}//30-06-2017 NIVEL COLINA
		break;//30-06-2017 NIVEL COLINA
		*/
	}
}
};
}

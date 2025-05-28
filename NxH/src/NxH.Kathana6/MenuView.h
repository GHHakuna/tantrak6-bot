#pragma once
#include "GameMemoryService.h"

namespace NxHKathana6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de MenuView
	/// </summary>
	public ref class MenuView : public System::Windows::Forms::Form
	{
	private: GameMemoryService^ gs;

	public:
		MenuView(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ cbEnableLootBug;
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::Windows::Forms::Label^ lbHpCurrent;
	private: System::Windows::Forms::Label^ lbHpMax;
	private: System::Windows::Forms::Label^ lbMpMax;
	private: System::Windows::Forms::Label^ lbMpCurrent;
	private: System::Windows::Forms::Label^ lbx;
	private: System::Windows::Forms::Label^ lby;
	private: System::Windows::Forms::Label^ lbz;







	private: System::ComponentModel::IContainer^ components;
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
			this->cbEnableLootBug = (gcnew System::Windows::Forms::CheckBox());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbHpCurrent = (gcnew System::Windows::Forms::Label());
			this->lbHpMax = (gcnew System::Windows::Forms::Label());
			this->lbMpMax = (gcnew System::Windows::Forms::Label());
			this->lbMpCurrent = (gcnew System::Windows::Forms::Label());
			this->lbx = (gcnew System::Windows::Forms::Label());
			this->lby = (gcnew System::Windows::Forms::Label());
			this->lbz = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// cbEnableLootBug
			// 
			this->cbEnableLootBug->AutoSize = true;
			this->cbEnableLootBug->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 9.75F));
			this->cbEnableLootBug->Location = System::Drawing::Point(12, 12);
			this->cbEnableLootBug->Name = L"cbEnableLootBug";
			this->cbEnableLootBug->Size = System::Drawing::Size(81, 21);
			this->cbEnableLootBug->TabIndex = 0;
			this->cbEnableLootBug->Text = L"Loot bug";
			this->cbEnableLootBug->UseVisualStyleBackColor = true;
			// 
			// timerMain
			// 
			this->timerMain->Tick += gcnew System::EventHandler(this, &MenuView::timerMain_Tick);
			// 
			// lbHpCurrent
			// 
			this->lbHpCurrent->AutoSize = true;
			this->lbHpCurrent->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbHpCurrent->Location = System::Drawing::Point(11, 65);
			this->lbHpCurrent->Name = L"lbHpCurrent";
			this->lbHpCurrent->Size = System::Drawing::Size(78, 17);
			this->lbHpCurrent->TabIndex = 1;
			this->lbHpCurrent->Text = L"HP Current";
			// 
			// lbHpMax
			// 
			this->lbHpMax->AutoSize = true;
			this->lbHpMax->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbHpMax->Location = System::Drawing::Point(11, 48);
			this->lbHpMax->Name = L"lbHpMax";
			this->lbHpMax->Size = System::Drawing::Size(56, 17);
			this->lbHpMax->TabIndex = 2;
			this->lbHpMax->Text = L"HP Max";
			// 
			// lbMpMax
			// 
			this->lbMpMax->AutoSize = true;
			this->lbMpMax->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbMpMax->Location = System::Drawing::Point(12, 82);
			this->lbMpMax->Name = L"lbMpMax";
			this->lbMpMax->Size = System::Drawing::Size(58, 17);
			this->lbMpMax->TabIndex = 4;
			this->lbMpMax->Text = L"MP Max";
			// 
			// lbMpCurrent
			// 
			this->lbMpCurrent->AutoSize = true;
			this->lbMpCurrent->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbMpCurrent->Location = System::Drawing::Point(12, 99);
			this->lbMpCurrent->Name = L"lbMpCurrent";
			this->lbMpCurrent->Size = System::Drawing::Size(80, 17);
			this->lbMpCurrent->TabIndex = 3;
			this->lbMpCurrent->Text = L"MP Current";
			// 
			// lbx
			// 
			this->lbx->AutoSize = true;
			this->lbx->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbx->Location = System::Drawing::Point(9, 285);
			this->lbx->Name = L"lbx";
			this->lbx->Size = System::Drawing::Size(14, 17);
			this->lbx->TabIndex = 5;
			this->lbx->Text = L"x";
			// 
			// lby
			// 
			this->lby->AutoSize = true;
			this->lby->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lby->Location = System::Drawing::Point(115, 285);
			this->lby->Name = L"lby";
			this->lby->Size = System::Drawing::Size(14, 17);
			this->lby->TabIndex = 6;
			this->lby->Text = L"y";
			// 
			// lbz
			// 
			this->lbz->AutoSize = true;
			this->lbz->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbz->Location = System::Drawing::Point(224, 285);
			this->lbz->Name = L"lbz";
			this->lbz->Size = System::Drawing::Size(14, 17);
			this->lbz->TabIndex = 7;
			this->lbz->Text = L"z";
			// 
			// MenuView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 311);
			this->Controls->Add(this->lbz);
			this->Controls->Add(this->lby);
			this->Controls->Add(this->lbx);
			this->Controls->Add(this->lbMpMax);
			this->Controls->Add(this->lbMpCurrent);
			this->Controls->Add(this->lbHpMax);
			this->Controls->Add(this->lbHpCurrent);
			this->Controls->Add(this->cbEnableLootBug);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(350, 350);
			this->MinimumSize = System::Drawing::Size(350, 350);
			this->Name = L"MenuView";
			this->ShowIcon = false;
			this->Text = L".:: NxH KathanaVI ::.";
			this->Load += gcnew System::EventHandler(this, &MenuView::MenuView_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MenuView_Load(System::Object^ sender, System::EventArgs^ e) {
		gs = gcnew GameMemoryService();

		timerMain->Interval = 200;
		timerMain->Start();
	}

	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		gs->SetLootBug(cbEnableLootBug->Checked);

		lbHpMax->Text = "HP Max: "+ gs->GetHpMax().ToString();
		lbMpMax->Text = "MP Max: " + gs->GetMpMax().ToString();
		lbHpCurrent->Text = "HP Current: " + gs->GetHpCurrent().ToString();
		lbMpCurrent->Text = "MP Current: " + gs->GetMpCurrent().ToString();

		lbx->Text = "x: " + gs->GetCoordX().ToString("0.00");
		lby->Text = "y: " + gs->GetCoordY().ToString("0.00");
		lbz->Text = "z: " + gs->GetCoordZ().ToString("0.00");
	}
	};
}

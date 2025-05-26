#pragma once

namespace NxHKathana6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de NxHKathana6
	/// </summary>
	public ref class NxHKathana6 : public System::Windows::Forms::Form
	{
	public:
		NxHKathana6(void)
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
		~NxHKathana6()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ cbEnableLootBug;
	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cbEnableLootBug = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// cbEnableLootBug
			// 
			this->cbEnableLootBug->AutoSize = true;
			this->cbEnableLootBug->Location = System::Drawing::Point(12, 12);
			this->cbEnableLootBug->Name = L"cbEnableLootBug";
			this->cbEnableLootBug->Size = System::Drawing::Size(99, 17);
			this->cbEnableLootBug->TabIndex = 0;
			this->cbEnableLootBug->Text = L"enable loot bug";
			this->cbEnableLootBug->UseVisualStyleBackColor = true;
			// 
			// NxHKathana6
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->cbEnableLootBug);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(300, 300);
			this->MinimumSize = System::Drawing::Size(300, 300);
			this->Name = L"NxHKathana6";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L".:: NxH KathanaVI ::.";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}

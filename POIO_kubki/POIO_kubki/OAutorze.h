#pragma once

namespace POIOkubki {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o OAutorze
	/// </summary>
	public ref class OAutorze : public System::Windows::Forms::Form
	{
	public:
		OAutorze(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~OAutorze()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ autor_info;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->autor_info = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// autor_info
			// 
			this->autor_info->Location = System::Drawing::Point(48, 61);
			this->autor_info->Multiline = true;
			this->autor_info->Name = L"autor_info";
			this->autor_info->ReadOnly = true;
			this->autor_info->Size = System::Drawing::Size(181, 143);
			this->autor_info->TabIndex = 0;
			this->autor_info->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->autor_info->TextChanged += gcnew System::EventHandler(this, &OAutorze::textBox1_TextChanged);
			// 
			// OAutorze
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->autor_info);
			this->Name = L"OAutorze";
			this->Text = L"OAutorze";
			this->Load += gcnew System::EventHandler(this, &OAutorze::OAutorze_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void OAutorze_Load(System::Object^ sender, System::EventArgs^ e) {
		autor_info->Text = "\r\n\r\nProgram kubeczki\r\n=====\r\nAutor: Tobiasz Kobza\r\n==== = \r\n2026";
	}
	};
}

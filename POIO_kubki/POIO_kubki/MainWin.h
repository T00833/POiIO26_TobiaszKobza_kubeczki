#pragma once

#include "OAutorze.h"

namespace POIOkubki {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MainWin
	/// </summary>
	public ref class MainWin : public System::Windows::Forms::Form
	{
	private:
		Generic::List<PictureBox^>^ cups = gcnew Generic::List<PictureBox^>();
	private: System::Windows::Forms::ImageList^ imageList1;
		   Generic::List<Label^>^ lbl_cups = gcnew Generic::List<Label^>();

	public:
		MainWin(void)
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
		~MainWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ plikToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ zamknijToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ edycjaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ substancjeToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ kubekToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ doToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ statystykaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dodajKubekToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ usuñKubekToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dodajSubstancjeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ oAutorzeToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;




	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWin::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->plikToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zamknijToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->edycjaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->substancjeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->doToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statystykaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->kubekToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dodajKubekToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->usuñKubekToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dodajSubstancjeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oAutorzeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->plikToolStripMenuItem,
					this->edycjaToolStripMenuItem, this->oAutorzeToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1164, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// plikToolStripMenuItem
			// 
			this->plikToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->zamknijToolStripMenuItem });
			this->plikToolStripMenuItem->Name = L"plikToolStripMenuItem";
			this->plikToolStripMenuItem->Size = System::Drawing::Size(55, 29);
			this->plikToolStripMenuItem->Text = L"Plik";
			// 
			// zamknijToolStripMenuItem
			// 
			this->zamknijToolStripMenuItem->Name = L"zamknijToolStripMenuItem";
			this->zamknijToolStripMenuItem->Size = System::Drawing::Size(176, 34);
			this->zamknijToolStripMenuItem->Text = L"Zamknij";
			this->zamknijToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::zamknijToolStripMenuItem_Click);
			// 
			// edycjaToolStripMenuItem
			// 
			this->edycjaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->substancjeToolStripMenuItem,
					this->kubekToolStripMenuItem
			});
			this->edycjaToolStripMenuItem->Name = L"edycjaToolStripMenuItem";
			this->edycjaToolStripMenuItem->Size = System::Drawing::Size(78, 29);
			this->edycjaToolStripMenuItem->Text = L"Edycja";
			// 
			// substancjeToolStripMenuItem
			// 
			this->substancjeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->doToolStripMenuItem,
					this->statystykaToolStripMenuItem
			});
			this->substancjeToolStripMenuItem->Name = L"substancjeToolStripMenuItem";
			this->substancjeToolStripMenuItem->Size = System::Drawing::Size(199, 34);
			this->substancjeToolStripMenuItem->Text = L"Substancje";
			// 
			// doToolStripMenuItem
			// 
			this->doToolStripMenuItem->Name = L"doToolStripMenuItem";
			this->doToolStripMenuItem->Size = System::Drawing::Size(239, 34);
			this->doToolStripMenuItem->Text = L"Dodaj do menu";
			// 
			// statystykaToolStripMenuItem
			// 
			this->statystykaToolStripMenuItem->Name = L"statystykaToolStripMenuItem";
			this->statystykaToolStripMenuItem->Size = System::Drawing::Size(239, 34);
			this->statystykaToolStripMenuItem->Text = L"Statystyka";
			// 
			// kubekToolStripMenuItem
			// 
			this->kubekToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->dodajKubekToolStripMenuItem,
					this->usuñKubekToolStripMenuItem, this->dodajSubstancjeToolStripMenuItem
			});
			this->kubekToolStripMenuItem->Name = L"kubekToolStripMenuItem";
			this->kubekToolStripMenuItem->Size = System::Drawing::Size(199, 34);
			this->kubekToolStripMenuItem->Text = L"Kubek";
			// 
			// dodajKubekToolStripMenuItem
			// 
			this->dodajKubekToolStripMenuItem->Name = L"dodajKubekToolStripMenuItem";
			this->dodajKubekToolStripMenuItem->Size = System::Drawing::Size(250, 34);
			this->dodajKubekToolStripMenuItem->Text = L"Dodaj kubek";
			this->dodajKubekToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::dodajKubekToolStripMenuItem_Click);
			// 
			// usuñKubekToolStripMenuItem
			// 
			this->usuñKubekToolStripMenuItem->Name = L"usuñKubekToolStripMenuItem";
			this->usuñKubekToolStripMenuItem->Size = System::Drawing::Size(250, 34);
			this->usuñKubekToolStripMenuItem->Text = L"Usuñ kubek";
			// 
			// dodajSubstancjeToolStripMenuItem
			// 
			this->dodajSubstancjeToolStripMenuItem->Name = L"dodajSubstancjeToolStripMenuItem";
			this->dodajSubstancjeToolStripMenuItem->Size = System::Drawing::Size(250, 34);
			this->dodajSubstancjeToolStripMenuItem->Text = L"Dodaj substancje";
			// 
			// oAutorzeToolStripMenuItem
			// 
			this->oAutorzeToolStripMenuItem->Name = L"oAutorzeToolStripMenuItem";
			this->oAutorzeToolStripMenuItem->Size = System::Drawing::Size(106, 29);
			this->oAutorzeToolStripMenuItem->Text = L"O autorze";
			this->oAutorzeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWin::oAutorzeToolStripMenuItem_Click);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"cup.png");
			// 
			// MainWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1164, 588);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MainWin";
			this->Text = L"Projekt kubeczki";
			this->Load += gcnew System::EventHandler(this, &MainWin::MainWin_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Void addCup() {
		PictureBox^ pb = gcnew PictureBox();
		pb->Size = Drawing::Size(199, 319);
		pb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
		pb->Image = imageList1->Images[0];
		pb->Location = Point(12 + (10 + 199) * cups->Count , 41); //popraw - (10 + 199) * static_cast<int>(cups->Count / 8) + static_cast<int>(cups->Count/8)*(70+320)
		pb->Name = L"cup" + Convert::ToString(cups->Count);
		this->Controls->Add(pb);
		cups->Add(pb);
	}

	private: Void addLblCup() {
		Label^ lbl = (gcnew System::Windows::Forms::Label());
		lbl->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		lbl->Size = System::Drawing::Size(199, 22);
		lbl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		lbl->Location = System::Drawing::Point(12 + (10 + 199) * lbl_cups -> Count, 400);
		lbl->Name = L"lblCup" + Convert::ToString(lbl_cups->Count);
		lbl->Text = L"cup #" + Convert::ToString(lbl_cups->Count);
		lbl->Click += gcnew System::EventHandler(this, &MainWin::selectCup);
		this->Controls->Add(lbl);
		lbl_cups->Add(lbl);
	}

	private: Void cleanLblCup() {
		for each (Label ^ lbl in lbl_cups)
		{
			lbl->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			lbl->ForeColor = System::Drawing::Color::FromArgb(0, 0, 0);
		}
		//cupID = -1;
	}


	private: System::Void zamknijToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult answer;
		answer = MessageBox::Show("Czy napewno chcesz zamkn¹æ aplikacjê?",
			"Program kubeczki", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (answer == System::Windows::Forms::DialogResult::Yes)
			Application::Exit();

	}
private: System::Void oAutorzeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	OAutorze^ autor_info = gcnew OAutorze();
	autor_info->Show();
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dodajKubekToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	addCup();
	addLblCup();
}

private: System::Void selectCup(System::Object^ sender, System::EventArgs^ e)
{
	cleanLblCup();
	Label^ lbl = (Label^)sender;
	lbl->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
	lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12,
		System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(238)));
	lbl->ForeColor = System::Drawing::Color::FromArgb(255, 0, 0);
}

private: System::Void MainWin_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}

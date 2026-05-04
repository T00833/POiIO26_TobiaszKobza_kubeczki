#pragma once

namespace Wykresy {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;


	/// <summary>
	/// Podsumowanie informacji o Wykres
	/// </summary>
	public ref class Wykres : public System::Windows::Forms::Form
	{
	public:
		Wykres(void)
		{
			InitializeComponent();
			init_chart();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Wykres()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>

		Chart^ chart1;
		ChartArea^ area;
		Series^ series;

		double time = 0;
		Random^ rand = gcnew Random;
	private: System::Windows::Forms::Timer^ timer1;
		   int val = 0;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Wykres::timer1_Tick);
			// 
			// Wykres
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 568);
			this->Name = L"Wykres";
			this->Text = L"Wykres";
			this->Load += gcnew System::EventHandler(this, &Wykres::Wykres_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: Void init_chart(){
			// create chart
			chart1 = gcnew Chart();
			chart1->Anchor = AnchorStyles::None;
			chart1->Dock = DockStyle::None;
			chart1->Location = System::Drawing::Point(12, 12);
			chart1->Size = System::Drawing::Size(400, 409);
			this->Controls->Add(chart1);
			// create chart area
			area = gcnew ChartArea("MainArea");
			area->AxisX->Title = "Czas [s]";
			area->AxisY->Title = "Temperatura [oC]";
			area->AxisX->LabelStyle->Format = "0";
			area->AxisX->Interval = 1;
			chart1->ChartAreas->Add(area);
			// create data series
			series = gcnew Series("Dane");
			series->ChartType = SeriesChartType::Line;
			series->Color = Color::Red;
			series->BorderWidth = 4;
			series->ChartArea = "MainArea";
			chart1->Series->Add(series);
		}

	private: System::Void Wykres_Load(System::Object^ sender, System::EventArgs^ e) {
		chart1->Series["Dane"]->Points->Clear();
		time = 0;
		val = rand->Next(0, 300);
		series->Points->AddXY(time, val);
		chart1->Invalidate();

		timer1->Enabled = true;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		double dt = double(timer1->Interval) / 1000;
		time += dt;
		int d_val = rand->Next(-10, 10);
		val += d_val;
		series->Points->AddXY(time, val);

		if (series->Points->Count > 10 / dt) scaleX(dt);
		if (time - int(time) < dt) scaleY();
		chart1->Invalidate();
	}

	private: Void scaleX(double dt)
	{
		series->Points->RemoveAt(0);
		area->AxisX->Minimum = time - 10 - dt;
		area->AxisX->Maximum = time + dt;
	}

	private: Void scaleY()
	{
		double min_y = series->Points[0]->YValues[0];
		double max_y = min_y;
		for each (DataPoint ^ p in series->Points)
		{
			double v = p->YValues[0];
			if (v < min_y) min_y = v;
			if (v > max_y) max_y = v;
		}
		double m = (max_y - min_y) * 0.5;
		if (m == 0) m = 1;
		area->AxisY->Minimum = min_y - m;
		area->AxisY->Maximum = max_y + m;
	}
	};
}

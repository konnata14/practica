//Заголовочный файл (MyForm.h)


#pragma once
#include "Circle.h"
#include "Octagon.h"

namespace FigureDrawer {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MainForm : public Form {
    private:
        List<Figure^>^ figures;
        Point lastClickPoint;

    public:
        MainForm() {
            InitializeComponent();
            figures = gcnew List<Figure^>();
            this->DoubleBuffered = true;
        }

    private:
        // Элементы управления (добавьте в InitializeComponent)
        TextBox^ txtCenterX;
        TextBox^ txtCenterY;
        TextBox^ txtRadius;
        TextBox^ txtThickness;
        Button^ btnAddCircle;
        Button^ btnAddOctagon;
        Button^ btnClear;
        Panel^ drawingPanel;
        ColorDialog^ colorDialog;

            void InitializeComponent(void) {
    // Основная панель для рисования
    this->drawingPanel = gcnew System::Windows::Forms::Panel();
    this->drawingPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->drawingPanel->Location = System::Drawing::Point(10, 10);
    this->drawingPanel->Size = System::Drawing::Size(600, 500);
    this->drawingPanel->BackColor = System::Drawing::Color::White;
    this->drawingPanel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::drawingPanel_MouseClick);
    this->drawingPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::drawingPanel_Paint);
    
    // Группа элементов управления
    this->Controls->Add(this->drawingPanel);

    // Текстовые поля для параметров
    this->txtCenterX = gcnew System::Windows::Forms::TextBox();
    this->txtCenterX->Location = System::Drawing::Point(620, 30);
    this->txtCenterX->Text = "300";
    this->Controls->Add(this->txtCenterX);

    this->txtCenterY = gcnew System::Windows::Forms::TextBox();
    this->txtCenterY->Location = System::Drawing::Point(620, 60);
    this->txtCenterY->Text = "250";
    this->Controls->Add(this->txtCenterY);

    this->txtRadius = gcnew System::Windows::Forms::TextBox();
    this->txtRadius->Location = System::Drawing::Point(620, 90);
    this->txtRadius->Text = "100";
    this->Controls->Add(this->txtRadius);

    this->txtThickness = gcnew System::Windows::Forms::TextBox();
    this->txtThickness->Location = System::Drawing::Point(620, 120);
    this->txtThickness->Text = "3";
    this->Controls->Add(this->txtThickness);

    // Метки для текстовых полей
    this->Controls->Add(gcnew Label() {
        Text = "Центр X:", Location = System::Drawing::Point(620, 10)
    });
    this->Controls->Add(gcnew Label() {
        Text = "Центр Y:", Location = System::Drawing::Point(620, 40)
    });
    this->Controls->Add(gcnew Label() {
        Text = "Радиус:", Location = System::Drawing::Point(620, 70)
    });
    this->Controls->Add(gcnew Label() {
        Text = "Толщина:", Location = System::Drawing::Point(620, 100)
    });

    // Кнопки добавления фигур
    this->btnAddCircle = gcnew System::Windows::Forms::Button();
    this->btnAddCircle->Text = "Добавить круг";
    this->btnAddCircle->Location = System::Drawing::Point(620, 150);
    this->btnAddCircle->Click += gcnew System::EventHandler(this, &MainForm::btnAddCircle_Click);
    this->Controls->Add(this->btnAddCircle);

    this->btnAddOctagon = gcnew System::Windows::Forms::Button();
    this->btnAddOctagon->Text = "Добавить восьмиугольник";
    this->btnAddOctagon->Location = System::Drawing::Point(620, 180);
    this->btnAddOctagon->Click += gcnew System::EventHandler(this, &MainForm::btnAddOctagon_Click);
    this->Controls->Add(this->btnAddOctagon);

    this->btnAddComposite = gcnew System::Windows::Forms::Button();
    this->btnAddComposite->Text = "Добавить составную фигуру";
    this->btnAddComposite->Location = System::Drawing::Point(620, 210);
    this->btnAddComposite->Click += gcnew System::EventHandler(this, &MainForm::btnAddComposite_Click);
    this->Controls->Add(this->btnAddComposite);

    // Кнопка очистки
    this->btnClear = gcnew System::Windows::Forms::Button();
    this->btnClear->Text = "Очистить всё";
    this->btnClear->Location = System::Drawing::Point(620, 350);
    this->btnClear->Click += gcnew System::EventHandler(this, &MainForm::btnClear_Click);
    this->Controls->Add(this->btnClear);

    // Элементы для выбора цвета
    this->colorDialog = gcnew System::Windows::Forms::ColorDialog();
    
    // Цвета для составной фигуры
    this->panelCircleColor = gcnew System::Windows::Forms::Panel();
    this->panelCircleColor->BackColor = System::Drawing::Color::Red;
    this->panelCircleColor->Location = System::Drawing::Point(620, 240);
    this->panelCircleColor->Size = System::Drawing::Size(50, 20);
    this->panelCircleColor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->Controls->Add(this->panelCircleColor);

    this->panelOctagonColor = gcnew System::Windows::Forms::Panel();
    this->panelOctagonColor->BackColor = System::Drawing::Color::Blue;
    this->panelOctagonColor->Location = System::Drawing::Point(680, 240);
    this->panelOctagonColor->Size = System::Drawing::Size(50, 20);
    this->panelOctagonColor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
    this->Controls->Add(this->panelOctagonColor);

    // Кнопки выбора цвета
    Button^ btnCircleColor = gcnew Button();
    btnCircleColor->Text = "Цвет круга";
    btnCircleColor->Location = System::Drawing::Point(620, 265);
    btnCircleColor->Click += gcnew System::EventHandler(this, &MainForm::btnCircleColor_Click);
    this->Controls->Add(btnCircleColor);

    Button^ btnOctagonColor = gcnew Button();
    btnOctagonColor->Text = "Цвет восьмиугольника";
    btnOctagonColor->Location = System::Drawing::Point(620, 295);
    btnOctagonColor->Click += gcnew System::EventHandler(this, &MainForm::btnOctagonColor_Click);
    this->Controls->Add(btnOctagonColor);

    // Настройки главной формы
    this->Text = "Редактор фигур";
    this->ClientSize = System::Drawing::Size(800, 520);
    this->DoubleBuffered = true;
}
        }

        void drawingPanel_MouseClick(Object^ sender, MouseEventArgs^ e) {
            lastClickPoint = e->Location;
            txtCenterX->Text = lastClickPoint.X.ToString();
            txtCenterY->Text = lastClickPoint.Y.ToString();
        }

        void btnAddCircle_Click(Object^ sender, EventArgs^ e) {
            try {
                Point center = Point(Convert::ToInt32(txtCenterX->Text),
                    Convert::ToInt32(txtCenterY->Text));
                int radius = Convert::ToInt32(txtRadius->Text);
                int thickness = Convert::ToInt32(txtThickness->Text);

                figures->Add(gcnew Circle(center, radius, thickness,
                    Color::Red, Color::Blue));

                drawingPanel->Invalidate();
            }
            catch (Exception^ ex) {
                MessageBox::Show(ex->Message, "Error");
            }
        }

        void btnAddOctagon_Click(Object^ sender, EventArgs^ e) {
            try {
                Point center = Point(Convert::ToInt32(txtCenterX->Text),
                    Convert::ToInt32(txtCenterY->Text));
                int radius = Convert::ToInt32(txtRadius->Text);
                int thickness = Convert::ToInt32(txtThickness->Text);

                figures->Add(gcnew Octagon(center, radius, thickness,
                    Color::Green, Color::Yellow));

                drawingPanel->Invalidate();
            }
            catch (Exception^ ex) {
                MessageBox::Show(ex->Message, "Error");
            }
        }

        void btnClear_Click(Object^ sender, EventArgs^ e) {
            figures->Clear();
            drawingPanel->Invalidate();
        }

        void drawingPanel_Paint(Object^ sender, PaintEventArgs^ e) {
            e->Graphics->Clear(drawingPanel->BackColor);
            for each (Figure ^ figure in figures) {
                figure->Draw(e->Graphics);
            }
        }
    };
}


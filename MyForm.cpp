//Главная программа (MyForm.cpp)
#include "MainForm.h"

namespace WindowsFormsApp1 {

    MainForm::MainForm(void)
    {
        InitializeComponent();
        this->DoubleBuffered = true;
        this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
    }

    MainForm::~MainForm()
    {
        if (components)
        {
            delete components;
        }
    }

    void MainForm::InitializeComponent(void)
    {
        this->components = gcnew System::ComponentModel::Container();
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->Text = "Figures Editor";
        this->ClientSize = System::Drawing::Size(900, 650);

        // Панель для рисования
        this->drawPanel = gcnew Panel();
        this->drawPanel->Location = System::Drawing::Point(50, 250);
        this->drawPanel->Size = System::Drawing::Size(800, 350);
        this->drawPanel->BorderStyle = BorderStyle::FixedSingle;
        this->drawPanel->BackColor = Color::White;
        this->drawPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::DrawPanel_Paint);
        this->Controls->Add(this->drawPanel);

        // Основные координаты
        this->xCoordLabel = gcnew Label();
        this->xCoordLabel->Location = System::Drawing::Point(50, 30);
        this->xCoordLabel->Text = "X Coordinate:";
        this->Controls->Add(this->xCoordLabel);

        this->xCoordTextBox = gcnew TextBox();
        this->xCoordTextBox->Location = System::Drawing::Point(50, 50);
        this->xCoordTextBox->Size = System::Drawing::Size(100, 20);
        this->Controls->Add(this->xCoordTextBox);

        this->yCoordLabel = gcnew Label();
        this->yCoordLabel->Location = System::Drawing::Point(170, 30);
        this->yCoordLabel->Text = "Y Coordinate:";
        this->Controls->Add(this->yCoordLabel);

        this->yCoordTextBox = gcnew TextBox();
        this->yCoordTextBox->Location = System::Drawing::Point(170, 50);
        this->yCoordTextBox->Size = System::Drawing::Size(100, 20);
        this->Controls->Add(this->yCoordTextBox);

        // Радиус
        this->radiusLabel = gcnew Label();
        this->radiusLabel->Location = System::Drawing::Point(290, 30);
        this->radiusLabel->Text = "Radius:";
        this->Controls->Add(this->radiusLabel);

        this->radiusTextBox = gcnew TextBox();
        this->radiusTextBox->Location = System::Drawing::Point(290, 50);
        this->radiusTextBox->Size = System::Drawing::Size(100, 20);
        this->Controls->Add(this->radiusTextBox);

        // Цвета
        this->outlineColorLabel = gcnew Label();
        this->outlineColorLabel->Location = System::Drawing::Point(50, 80);
        this->outlineColorLabel->Text = "Outline Color:";
        this->Controls->Add(this->outlineColorLabel);

        this->outlineColorButton = gcnew Button();
        this->outlineColorButton->Location = System::Drawing::Point(50, 100);
        this->outlineColorButton->Size = System::Drawing::Size(100, 30);
        this->outlineColorButton->Text = "Choose";
        this->outlineColorButton->BackColor = Color::Black;
        this->outlineColorButton->ForeColor = Color::White;
        this->outlineColorButton->Click += gcnew System::EventHandler(this, &MainForm::OutlineColorButton_Click);
        this->Controls->Add(this->outlineColorButton);

        this->outlineColorDialog = gcnew ColorDialog();
        this->outlineColorDialog->Color = Color::Black;

        this->fillColorLabel = gcnew Label();
        this->fillColorLabel->Location = System::Drawing::Point(170, 80);
        this->fillColorLabel->Text = "Fill Color:";
        this->Controls->Add(this->fillColorLabel);

        this->fillColorButton = gcnew Button();
        this->fillColorButton->Location = System::Drawing::Point(170, 100);
        this->fillColorButton->Size = System::Drawing::Size(100, 30);
        this->fillColorButton->Text = "Choose";
        this->fillColorButton->BackColor = Color::LightBlue;
        this->fillColorButton->Click += gcnew System::EventHandler(this, &MainForm::FillColorButton_Click);
        this->Controls->Add(this->fillColorButton);

        this->fillColorDialog = gcnew ColorDialog();
        this->fillColorDialog->Color = Color::LightBlue;

        // Группа для перемещения (отдельная четкая область)
        this->moveGroupBox = gcnew GroupBox();
        this->moveGroupBox->Location = System::Drawing::Point(400, 30);
        this->moveGroupBox->Size = System::Drawing::Size(250, 120);
        this->moveGroupBox->Text = "Move Figure";
        this->Controls->Add(this->moveGroupBox);

        // Поля внутри группы перемещения
        this->moveXLabel = gcnew Label();
        this->moveXLabel->Location = System::Drawing::Point(20, 30);
        this->moveXLabel->Text = "New X:";
        this->moveGroupBox->Controls->Add(this->moveXLabel);

        this->moveXTextBox = gcnew TextBox();
        this->moveXTextBox->Location = System::Drawing::Point(20, 50);
        this->moveXTextBox->Size = System::Drawing::Size(80, 20);
        this->moveGroupBox->Controls->Add(this->moveXTextBox);

        this->moveYLabel = gcnew Label();
        this->moveYLabel->Location = System::Drawing::Point(120, 30);
        this->moveYLabel->Text = "New Y:";
        this->moveGroupBox->Controls->Add(this->moveYLabel);

        this->moveYTextBox = gcnew TextBox();
        this->moveYTextBox->Location = System::Drawing::Point(120, 50);
        this->moveYTextBox->Size = System::Drawing::Size(80, 20);
        this->moveGroupBox->Controls->Add(this->moveYTextBox);

        this->moveButton = gcnew Button();
        this->moveButton->Location = System::Drawing::Point(20, 80);
        this->moveButton->Size = System::Drawing::Size(180, 30);
        this->moveButton->Text = "Move Selected Figure";
        this->moveButton->Click += gcnew System::EventHandler(this, &MainForm::MoveButton_Click);
        this->moveGroupBox->Controls->Add(this->moveButton);

        // Кнопки создания фигур
        this->drawCircleButton = gcnew Button();
        this->drawCircleButton->Location = System::Drawing::Point(50, 180);
        this->drawCircleButton->Size = System::Drawing::Size(200, 40);
        this->drawCircleButton->Text = "Draw Circle";
        this->drawCircleButton->Click += gcnew System::EventHandler(this, &MainForm::DrawCircleButton_Click);
        this->Controls->Add(this->drawCircleButton);

        this->drawOctagonButton = gcnew Button();
        this->drawOctagonButton->Location = System::Drawing::Point(300, 180);
        this->drawOctagonButton->Size = System::Drawing::Size(200, 40);
        this->drawOctagonButton->Text = "Draw Octagon";
        this->drawOctagonButton->Click += gcnew System::EventHandler(this, &MainForm::DrawOctagonButton_Click);
        this->Controls->Add(this->drawOctagonButton);

        this->drawComFigureButton = gcnew Button();
        this->drawComFigureButton->Location = System::Drawing::Point(550, 180);
        this->drawComFigureButton->Size = System::Drawing::Size(200, 40);
        this->drawComFigureButton->Text = "Draw Composite";
        this->drawComFigureButton->Click += gcnew System::EventHandler(this, &MainForm::DrawComFigureButton_Click);
        this->Controls->Add(this->drawComFigureButton);
    }

    // ... (реализации остальных методов остаются без изменений из предыдущего примера)
    // MoveButton_Click, Draw... методы и другие обработчики событий
}

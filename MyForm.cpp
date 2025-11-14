// MainForm.cpp
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
        this->Text = "Figures";
        this->ClientSize = System::Drawing::Size(900, 650);

        // drawPanel
        this->drawPanel = gcnew Panel();
        this->drawPanel->Location = System::Drawing::Point(50, 260);
        this->drawPanel->Size = System::Drawing::Size(800, 360);
        this->drawPanel->BorderStyle = BorderStyle::FixedSingle;
        this->drawPanel->BackColor = Color::White;
        this->drawPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::DrawPanel_Paint);
        this->Controls->Add(this->drawPanel);

        // Labels and TextBoxes for coordinates and radius
        this->xCoordLabel = gcnew Label();
        this->xCoordLabel->Location = System::Drawing::Point(50, 20);
        this->xCoordLabel->Size = System::Drawing::Size(100, 20);
        this->xCoordLabel->Text = "X:";
        this->Controls->Add(this->xCoordLabel);

        this->xCoordTextBox = gcnew TextBox();
        this->xCoordTextBox->Location = System::Drawing::Point(50, 40);
        this->xCoordTextBox->Size = System::Drawing::Size(100, 20);
        this->Controls->Add(this->xCoordTextBox);

        this->yCoordLabel = gcnew Label();
        this->yCoordLabel->Location = System::Drawing::Point(170, 20);
        this->yCoordLabel->Size = System::Drawing::Size(100, 20);
        this->yCoordLabel->Text = "Y:";
        this->Controls->Add(this->yCoordLabel);

        this->yCoordTextBox = gcnew TextBox();
        this->yCoordTextBox->Location = System::Drawing::Point(170, 40);
        this->yCoordTextBox->Size = System::Drawing::Size(100, 20);
        this->Controls->Add(this->yCoordTextBox);

        this->radiusLabel = gcnew Label();
        this->radiusLabel->Location = System::Drawing::Point(290, 20);
        this->radiusLabel->Size = System::Drawing::Size(100, 20);
        this->radiusLabel->Text = "Radius:";
        this->Controls->Add(this->radiusLabel);

        this->radiusTextBox = gcnew TextBox();
        this->radiusTextBox->Location = System::Drawing::Point(290, 40);
        this->radiusTextBox->Size = System::Drawing::Size(100, 20);
        this->Controls->Add(this->radiusTextBox);

        // Move fields
        this->moveXCoordLabel = gcnew Label();
        this->moveXCoordLabel->Location = System::Drawing::Point(420, 20);
        this->moveXCoordLabel->Size = System::Drawing::Size(120, 20);
        this->moveXCoordLabel->Text = "Move X:";
        this->Controls->Add(this->moveXCoordLabel);

        this->moveXCoordTextBox = gcnew TextBox();
        this->moveXCoordTextBox->Location = System::Drawing::Point(420, 40);
        this->moveXCoordTextBox->Size = System::Drawing::Size(100, 20);
        this->Controls->Add(this->moveXCoordTextBox);

        this->moveYCoordLabel = gcnew Label();
        this->moveYCoordLabel->Location = System::Drawing::Point(550, 20);
        this->moveYCoordLabel->Size = System::Drawing::Size(120, 20);
        this->moveYCoordLabel->Text = "Move Y:";
        this->Controls->Add(this->moveYCoordLabel);

        this->moveYCoordTextBox = gcnew TextBox();
        this->moveYCoordTextBox->Location = System::Drawing::Point(550, 40);
        this->moveYCoordTextBox->Size = System::Drawing::Size(100, 20);
        this->Controls->Add(this->moveYCoordTextBox);

        // Color inputs
        this->borderColorLabel = gcnew Label();
        this->borderColorLabel->Location = System::Drawing::Point(50, 80);
        this->borderColorLabel->Size = System::Drawing::Size(170, 20);
        this->borderColorLabel->Text = "Border Color (R,G,B):";
        this->Controls->Add(this->borderColorLabel);

        this->borderColorTextBox = gcnew TextBox();
        this->borderColorTextBox->Location = System::Drawing::Point(50, 100);
        this->borderColorTextBox->Size = System::Drawing::Size(170, 20);
        this->Controls->Add(this->borderColorTextBox);

        this->fillColorLabel = gcnew Label();
        this->fillColorLabel->Location = System::Drawing::Point(250, 80);
        this->fillColorLabel->Size = System::Drawing::Size(170, 20);
        this->fillColorLabel->Text = "Fill Color (R,G,B):";
        this->Controls->Add(this->fillColorLabel);

        this->fillColorTextBox = gcnew TextBox();
        this->fillColorTextBox->Location = System::Drawing::Point(250, 100);
        this->fillColorTextBox->Size = System::Drawing::Size(170, 20);
        this->Controls->Add(this->fillColorTextBox);

        // Buttons
        this->drawCircleButton = gcnew Button();
        this->drawCircleButton->Location = System::Drawing::Point(450, 90);
        this->drawCircleButton->Size = System::Drawing::Size(120, 30);
        this->drawCircleButton->Text = "Draw Circle";
        this->drawCircleButton->Click += gcnew System::EventHandler(this, &MainForm::DrawCircleButton_Click);
        this->Controls->Add(this->drawCircleButton);

        this->drawOctagonButton = gcnew Button();
        this->drawOctagonButton->Location = System::Drawing::Point(580, 90);
        this->drawOctagonButton->Size = System::Drawing::Size(120, 30);
        this->drawOctagonButton->Text = "Draw Octagon";
        this->drawOctagonButton->Click += gcnew System::EventHandler(this, &MainForm::DrawOctagonButton_Click);
        this->Controls->Add(this->drawOctagonButton);

        this->drawComFigureButton = gcnew Button();
        this->drawComFigureButton->Location = System::Drawing::Point(710, 90);
        this->drawComFigureButton->Size = System::Drawing::Size(120, 30);
        this->drawComFigureButton->Text = "Draw Composite";
        this->drawComFigureButton->Click += gcnew System::EventHandler(this, &MainForm::DrawComFigureButton_Click);
        this->Controls->Add(this->drawComFigureButton);

        this->moveButton = gcnew Button();
        this->moveButton->Location = System::Drawing::Point(450, 130);
        this->moveButton->Size = System::Drawing::Size(120, 30);
        this->moveButton->Text = "Move Last";
        this->moveButton->Click += gcnew System::EventHandler(this, &MainForm::MoveButton_Click);
        this->Controls->Add(this->moveButton);

        this->changeBorderColorButton = gcnew Button();
        this->changeBorderColorButton->Location = gcnew System::Drawing::Point(580, 130);
        this->changeBorderColorButton->Size = System::Drawing::Size(120, 30);
        this->changeBorderColorButton->Text = "Set Border";
        this->changeBorderColorButton->Click += gcnew System::EventHandler(this, &MainForm::ChangeBorderColorButton_Click);
        this->Controls->Add(this->changeBorderColorButton);

        this->changeFillColorButton = gcnew Button();
        this->changeFillColorButton->Location = gcnew System::Drawing::Point(710, 130);
        this->changeFillColorButton->Size = System::Drawing::Size(120, 30);
        this->changeFillColorButton->Text = "Set Fill";
        this->changeFillColorButton->Click += gcnew System::EventHandler(this, &MainForm::ChangeFillColorButton_Click);
        this->Controls->Add(this->changeFillColorButton);
    }

    void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
    {
        figures = gcnew List<Figure^>();
    }

    void MainForm::DrawPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
    {
        for each(Figure ^ figure in figures)
        {
            try
            {
                figure->Draw(e->Graphics);
            }
            catch (Exception^ ex)
            {
                LogError(ex->Message);
                // don't rethrow, just skip drawing this figure
            }
        }
    }

    bool MainForm::IsValidPosition(int x, int y, int radius, bool allowZeroRadius)
    {
        if (x < 0 || y < 0) return false;
        if (!allowZeroRadius && radius <= 0) return false;
        if (radius < 0) return false;

        // We assume coordinates are relative to drawPanel (user should input coordinates within panel)
        int w = drawPanel->ClientSize.Width;
        int h = drawPanel->ClientSize.Height;

        // Check that the shape entirely fits inside panel
        if (x - radius < 0 || y - radius < 0) return false;
        if (x + radius > w || y + radius > h) return false;

        return true;
    }

    void MainForm::DrawCircleButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        try
        {
            int x = Int32::Parse(xCoordTextBox->Text);
            int y = Int32::Parse(yCoordTextBox->Text);
            int radius = Int32::Parse(radiusTextBox->Text);

            if (!IsValidPosition(x, y, radius, false))
            {
                MessageBox::Show("Invalid coordinates or radius. Coordinates and radius must be positive and figure must fit into drawing panel. Coordinates are relative to the drawing panel (top-left = 0,0).");
                return;
            }

            figures->Add(gcnew Circle(Point(x, y), radius, 0, Color::FromArgb(106, 0, 90), Color::FromArgb(10, 100, 23)));
            drawPanel->Refresh();
        }
        catch (FormatException^)
        {
            MessageBox::Show("Please enter valid integer values for coordinates and radius.");
        }
        catch (Exception^ ex)
        {
            LogError(ex->Message);
            MessageBox::Show("An error occurred: " + ex->Message);
        }
    }

    void MainForm::DrawOctagonButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        try
        {
            int x = Int32::Parse(xCoordTextBox->Text);
            int y = Int32::Parse(yCoordTextBox->Text);
            int radius = Int32::Parse(radiusTextBox->Text);

            if (!IsValidPosition(x, y, radius, false))
            {
                MessageBox::Show("Invalid coordinates or radius. Coordinates and radius must be positive and figure must fit into drawing panel. Coordinates are relative to the drawing panel (top-left = 0,0).");
                return;
            }

            figures->Add(gcnew Octagon(Point(x, y), radius, 0, Color::FromArgb(255, 0, 0), Color::FromArgb(0, 0, 255)));
            drawPanel->Refresh();
        }
        catch (FormatException^)
        {
            MessageBox::Show("Please enter valid integer values for coordinates and radius.");
        }
        catch (Exception^ ex)
        {
            LogError(ex->Message);
            MessageBox::Show("An error occurred: " + ex->Message);
        }
    }

    void MainForm::DrawComFigureButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        try
        {
            int x = Int32::Parse(xCoordTextBox->Text);
            int y = Int32::Parse(yCoordTextBox->Text);
            int radius = Int32::Parse(radiusTextBox->Text);

            if (!IsValidPosition(x, y, radius, false))
            {
                MessageBox::Show("Invalid coordinates or radius. Coordinates and radius must be positive and figure must fit into drawing panel. Coordinates are relative to the drawing panel (top-left = 0,0).");
                return;
            }

            figures->Add(gcnew ComFigure(Point(x, y), radius, 0, Color::FromArgb(255, 0, 0), Color::FromArgb(0, 0, 250), Color::FromArgb(0, 250, 0), Color::FromArgb(10, 130, 0)));
            drawPanel->Refresh();
        }
        catch (FormatException^)
        {
            MessageBox::Show("Please enter valid integer values for coordinates and radius.");
        }
        catch (Exception^ ex)
        {
            LogError(ex->Message);
            MessageBox::Show("An error occurred: " + ex->Message);
        }
    }

    void MainForm::MoveButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        try
        {
            if (figures->Count == 0)
            {
                MessageBox::Show("No figures to move.");
                return;
            }

            int x = Int32::Parse(moveXCoordTextBox->Text);
            int y = Int32::Parse(moveYCoordTextBox->Text);

            // allow zero radius for move (we're only checking that point is inside)
            if (!IsValidPosition(x, y, figures[figures->Count - 1]->Radius, true))
            {
                MessageBox::Show("Invalid coordinates for move. Coordinates must be such that the figure fits inside the drawing panel.");
                return;
            }

            figures[figures->Count - 1]->Replace(Point(x, y));
            drawPanel->Refresh();
        }
        catch (FormatException^)
        {
            MessageBox::Show("Please enter valid integer values for move coordinates.");
        }
        catch (Exception^ ex)
        {
            LogError(ex->Message);
            MessageBox::Show("An error occurred: " + ex->Message);
        }
    }

    void MainForm::ChangeBorderColorButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        try
        {
            if (figures->Count == 0)
            {
                MessageBox::Show("No figures to change color.");
                return;
            }

            array<String^>^ colorParts = borderColorTextBox->Text->Split(',');
            if (colorParts->Length != 3)
            {
                MessageBox::Show("Please enter the color in the format R,G,B.");
                return;
            }
            int r = Int32::Parse(colorParts[0]);
            int g = Int32::Parse(colorParts[1]);
            int b = Int32::Parse(colorParts[2]);

            figures[figures->Count - 1]->SetBorderColor(Color::FromArgb(r, g, b));
            drawPanel->Refresh();
        }
        catch (FormatException^)
        {
            MessageBox::Show("Please enter valid integers for color components (0-255).");
        }
        catch (Exception^ ex)
        {
            LogError(ex->Message);
            MessageBox::Show("An error occurred: " + ex->Message);
        }
    }

    void MainForm::ChangeFillColorButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        try
        {
            if (figures->Count == 0)
            {
                MessageBox::Show("No figures to change color.");
                return;
            }

            array<String^>^ colorParts = fillColorTextBox->Text->Split(',');
            if (colorParts->Length != 3)
            {
                MessageBox::Show("Please enter the color in the format R,G,B.");
                return;
            }
            int r = Int32::Parse(colorParts[0]);
            int g = Int32::Parse(colorParts[1]);
            int b = Int32::Parse(colorParts[2]);

            figures[figures->Count - 1]->SetFillColor(Color::FromArgb(r, g, b));
            drawPanel->Refresh();
        }
        catch (FormatException^)
        {
            MessageBox::Show("Please enter valid integers for color components (0-255).");
        }
        catch (Exception^ ex)
        {
            LogError(ex->Message);
            MessageBox::Show("An error occurred: " + ex->Message);
        }
    }

    void MainForm::LogError(String^ errorMessage)
    {
        try
        {
            std::ofstream logFile("error_log.txt", std::ios::app);
            if (logFile.is_open())
            {
                logFile << "Error: " << marshal_as<std::string>(errorMessage) << std::endl;
                logFile.close();
            }
        }
        catch (...)
        {
            // swallow logging errors
        }
    }
}

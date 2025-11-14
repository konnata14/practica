// MainForm.h
#pragma once

#include "Figure.h"
#include <fstream>
#include <msclr/marshal_cppstd.h>

namespace WindowsFormsApp1 {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace msclr::interop;

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void);
    protected:
        ~MainForm();

    private:
        List<Figure^>^ figures;
        System::ComponentModel::Container^ components;
        Panel^ drawPanel;

        // Controls
        Label^ xCoordLabel;
        TextBox^ xCoordTextBox;
        Label^ yCoordLabel;
        TextBox^ yCoordTextBox;
        Label^ radiusLabel;
        TextBox^ radiusTextBox;

        Label^ moveXCoordLabel;
        TextBox^ moveXCoordTextBox;
        Label^ moveYCoordLabel;
        TextBox^ moveYCoordTextBox;

        Label^ borderColorLabel;
        TextBox^ borderColorTextBox;

        Label^ fillColorLabel;
        TextBox^ fillColorTextBox;

        Button^ drawCircleButton;
        Button^ drawOctagonButton;
        Button^ drawComFigureButton;
        Button^ moveButton;
        Button^ changeBorderColorButton;
        Button^ changeFillColorButton;

        void InitializeComponent(void);
        void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
        void DrawPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
        void DrawCircleButton_Click(System::Object^ sender, System::EventArgs^ e);
        void DrawOctagonButton_Click(System::Object^ sender, System::EventArgs^ e);
        void DrawComFigureButton_Click(System::Object^ sender, System::EventArgs^ e);
        void MoveButton_Click(System::Object^ sender, System::EventArgs^ e);
        void ChangeBorderColorButton_Click(System::Object^ sender, System::EventArgs^ e);
        void ChangeFillColorButton_Click(System::Object^ sender, System::EventArgs^ e);
        void LogError(String^ errorMessage);
        bool IsValidPosition(int x, int y, int radius, bool allowZeroRadius);
    };
}

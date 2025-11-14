// Program.cpp
#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int Main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew WindowsFormsApp1::MainForm());
    return 0;
}

#include "MenuView.h"
using namespace NxHKathana6;

[STAThreadAttribute]
void ShowMenuView()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MenuView());
}
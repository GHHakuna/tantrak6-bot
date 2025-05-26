#include "NxH.Kathana6.h"

using namespace NxHKathana6;

[STAThreadAttribute]
void ShowForm()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew NxHKathana6());
}
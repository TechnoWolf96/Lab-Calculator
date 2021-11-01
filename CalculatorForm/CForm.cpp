#include "CForm.h"
#include <Windows.h>
using namespace CalculatorForm;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CForm);
	return 0;
}

#include "MyForm.h"


using namespace GUIDS;

[STAThread]
void main()
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}

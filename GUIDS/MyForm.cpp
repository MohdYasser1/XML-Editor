#include "MyForm.h"
#include "MyForm1.h"


using namespace GUIDS;

[STAThread]
void main()
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}

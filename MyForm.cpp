#include "MyForm.h"
#include "Markup.h"

#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>

using namespace std;
using namespace TextBox;




void main(array<String ^> ^args)
{
	Application::EnableVisualStyles(); Application::SetCompatibleTextRenderingDefault(false);

	MyForm ^ form = gcnew MyForm();

	//genParseTable();
	//parseAlgorithm();
	
	
	
	Application::Run(form);

	
	
	Application::Exit();


	// Create the main window and run it
	//Application::Run(gcnew Form1());


	//string s = "Your sentence is rejected";
	//TextBox::printMessage(s);

	//TextBox::getGrammerSymbol();
	




}
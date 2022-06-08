//------------------------------------------
//	For some reason it uses to many memory
//------------------------------------------

#include "Application.h"

/*TODO:
	1) Add method to find minimun;
	   Fix drawing of arrow;

	2) Add Controls;
	
	3) Add UI;
    3.1) Add Welcome Menu

	4) Add config file;
	5) Add readme file;

	Fix memory problem;
*/

int main()
{
	std::cout << "ENTER:\n\n";
	{
		Application app;
		app.Run();
	}

	std::cout << "EXIT:\n\n";

	return 0;
}
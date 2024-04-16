
#include <iostream>
using namespace std;
//#include "clsMainScreen.h"
#include"clsLoginScreen.h"

int main()
{

	while (true) {

		//clsMainScreen::ShowMainMenu();
		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}
	}
	return 0;
}



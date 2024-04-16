#pragma once
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsUser.h"
#include"Global.h"
#include<iomanip>

class clsLoginScreen :protected clsScreen
{

private:

	static bool _Login() {
		bool LoginFailed = false;
		string UserName, Password;
		short FailedLoginCount = 0;
		do {
			if (LoginFailed) {
				cout << "Invalid UserName/Password, You have " << 3 - FailedLoginCount << " Trial(s) to lock your Screen!\n"
					<< "Trial(s) to login\n";

			}
			FailedLoginCount++;
			cout << "enter UserName? ";
			cin >> UserName;
			cout << "enter Password? ";
			cin >> Password;
			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.IsEmpty();
			if (FailedLoginCount == 3) {
				cout << "\nYou're locked after 3 failed trials\n\n";
				return false;
			}

		} while (LoginFailed);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
		return true;



	}



public:

	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}

};


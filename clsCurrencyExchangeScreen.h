#pragma once
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include "clsUpdateRateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen :public clsScreen
{


private:
	enum eCurrencyExchangeOptions {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrency = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};

	static short _ReadCurrencyExchange() {
		cout << setw(38) << left << "" << "Choose what do you want to do?[1 to 5]? ";
		short Choice;
		Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Please enter a number between 1 and 5");
		return Choice;
	}
	static void _GoBackToCurrencyMainMenu() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";
		system("pause>0");
		ShowCurrencyExchangeScreen();

	}

	static void _ShowCurrenciesListScreen()
	{

		clsCurrenciesListScreen::ShowCurrenciesListScreen();

	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will Be Here.\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << "\nUpdate Currency Rate Screen Will Be Here.\n";
		clsUpdateRateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calculator Screen Will Be Here.\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}


	static void _PerformCurrencyMenuOption(eCurrencyExchangeOptions CurrencyExchangeOption) {
		switch (CurrencyExchangeOption)
		{
		case clsCurrencyExchangeScreen::eListCurrencies:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyMainMenu();
			break;
		case clsCurrencyExchangeScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMainMenu();

			break;
		case clsCurrencyExchangeScreen::eUpdateCurrency:
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyMainMenu();

			break;
		case clsCurrencyExchangeScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMainMenu();

			break;
		case clsCurrencyExchangeScreen::eMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;

		}

		}

	}


public:

	static void ShowCurrencyExchangeScreen() {
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrencyMenuOption((eCurrencyExchangeOptions)_ReadCurrencyExchange());
	}






};


#pragma once
#include<string>
#include"clsScreen.h"
#include"clsCurrency.h"
#include<iomanip>

class clsCurrenciesListScreen : public clsScreen
{

private:

	static void _PrintCurrenciesRecordLine(clsCurrency Currency) {
		cout << setw(8) << left << "";
		cout << "| " << setw(28) << left << Currency.Country();
		cout << "| " << setw(12) << left << Currency.CurrencyCode();
		cout << "| " << setw(28) << left << Currency.CurrencyName();
		cout << "| " << setw(12) << left << Currency.Rate();

	}

public:

	static void ShowCurrenciesListScreen() {
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		string Title = "\tCurrencies List Screen";
		string Subtitle = "\t (" + to_string(vCurrencies.size()) + ") Currency.";
		_DrawScreenHeader(Title, Subtitle);
		cout << setw(8) << left << "" << "\n\t_____________________________________________________";
		cout << "__________________________________________________\n\n";
		cout << setw(8) << left << "";
		cout << "| " << setw(28) << left << "Country";
		cout << "| " << setw(12) << left << "Code";
		cout << "| " << setw(28) << left << "Name";
		cout << "| " << setw(12) << left << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_____________________________________________________";
		cout << "__________________________________________________\n\n";

		if (vCurrencies.size() == 0) {
			cout << "\t\t\t\tNo Currencies Available In the System!";

		}
		else {
			for (clsCurrency Currency : vCurrencies) {
				_PrintCurrenciesRecordLine(Currency);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_____________________________________________________";
		cout << "__________________________________________________\n\n";

	}



};


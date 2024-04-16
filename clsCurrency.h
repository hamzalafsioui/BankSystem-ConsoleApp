#pragma once
#include<vector>
#include<fstream>
#include"clsString.h"
#include<iostream>
#include<string>
class clsCurrency
{


private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string CurrencyLine, string Separator = "#//#") {
		vector <string> vCurrencyLine = clsString::Split(CurrencyLine, Separator);

		return  clsCurrency(UpdateMode, vCurrencyLine[0], vCurrencyLine[1], vCurrencyLine[2], stod(vCurrencyLine[3]));

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency ObjectCurrency, string Separator = "#//#") {
		string CurrencyLine = "";
		CurrencyLine += ObjectCurrency.Country() + Separator;
		CurrencyLine += ObjectCurrency.CurrencyCode() + Separator;
		CurrencyLine += ObjectCurrency.CurrencyName() + Separator;
		CurrencyLine += to_string(ObjectCurrency.Rate()) + Separator;

		return CurrencyLine;

	}

	static vector<clsCurrency> _LoadCurrenciesDataFromFile() {
		vector<clsCurrency> vCurrencies;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrencies;
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrencies) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out); // OverWrite
		string DataLine;
		if (MyFile.is_open()) {
			for (clsCurrency C : vCurrencies) {
				DataLine = _ConvertCurrencyObjectToLine(C);
				MyFile << DataLine << endl;

			}
			MyFile.close();
		}
	}

	void _Update() {

		vector<clsCurrency> _vCurrency;
		_vCurrency = _LoadCurrenciesDataFromFile();
		for (clsCurrency& Currency : _vCurrency) {
			if (Currency.CurrencyCode() == CurrencyCode()) {
				Currency = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(_vCurrency);

	}

	static clsCurrency _GetEmptyCurrencyObject() {

		return clsCurrency(EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}
	static vector<clsCurrency> GetAllUSDRates() {
		return _LoadCurrenciesDataFromFile();
	}


	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string Country() {
		return _Country;
	}
	string CurrencyCode() {
		return _CurrencyCode;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	float Rate() {
		return _Rate;
	}

	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}

	static clsCurrency FindByCode(string CurrencyCode) {
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//Read Only
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode) {
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country) {
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();


		}
		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExist(string CurrencyCode) {
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		clsCurrency Currency = FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	static vector<clsCurrency> GetCurrenciesList() {
		vector<clsCurrency> vCurrencyList;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencyList.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrencyList;

	}

	float ConvertToUSD(float Amount) {
		return (float)(Amount / Rate());

	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2) {

		float Total = 0;
		Total += ConvertToUSD(Amount) * Currency2.Rate();
		return Total;
	}

};


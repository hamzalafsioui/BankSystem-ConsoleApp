#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"


class clsAddNewClientScreen :protected clsScreen
{
    static void _ReadClientInfo(clsBankClient& Client) {
        cout << "Enter Your First Name:\n";
        Client.FirstName = clsInputValidate::ReadString();
        cout << "Enter Your Last Name:\n";
        Client.LastName = clsInputValidate::ReadString();
        cout << "Enter Your Email\n";
        Client.Email = clsInputValidate::ReadString();
        cout << "Enter Your Phone\n";
        Client.Phone = clsInputValidate::ReadString();
        cout << "Enter Your PinCode\n";
        Client.PinCode = clsInputValidate::ReadString();
        cout << "Enter Your Account Balance\n";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

    static 	void _PrintClient(clsBankClient Client) {
        cout << "\tCart Client\n";
        cout << "============================================\n";
        cout << "FirstNumber  : " << Client.FirstName << endl;
        cout << "LastNumber   : " << Client.LastName << endl;
        cout << "Full Name    : " << Client.FullName() << endl;
        cout << "Email        : " << Client.Email << endl;
        cout << "Phone        : " << Client.Phone << endl;
        cout << "AccountNumber: " << Client.AccountNumber() << endl;
        cout << "PinCode      : " << Client.PinCode << endl;
        cout << "AccountBalance: " << Client.AccountBalance << endl;
        cout << "============================================\n";


    }


public:

    static void _ShowAddNewClientsScreen() {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\t\Add New Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount Number Is Already Used, Choose another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResults;
        SaveResults = NewClient.Save();
        switch (SaveResults)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount Added Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "\nError account was not saved because it's Empty";
            break;
        case clsBankClient::enSaveResults::svFailedAccountNumberExists:
            break; cout << "\nError account was not saved because it's exist";
        default:
            break;
        }
    }






};


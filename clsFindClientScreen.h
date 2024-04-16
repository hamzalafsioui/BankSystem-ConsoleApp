#pragma once
#include "clsBankClient.h"
#include"clsScreen.h"
#include "clsInputValidate.h"
class clsFindClientScreen :protected clsScreen
{
private:
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

    static void ShowFindClientScreen() {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tFind Client");
        string AccountNumber = "";
        cout << "\nEnter Account Number to Find it... ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nThis Account Number is not Found Choose another One...\n";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        if (!Client.IsEmpty()) {
            cout << "Client Found :-)\n";
        }
        else {
            cout << "\nClient was not Found :(-\n";
        }
        _PrintClient(Client);
    }
};


#pragma once
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsUpdateClientScreen : protected clsScreen
{

private:
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

    static void ShowUpdateClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tUpdate Client Screen");
        cout << "\nPlease Enter Account Number For Delete...\n";
        string AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nThis Account Number is Not Found,Choose another one...\n";
            string AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        cout << "\nAre You sure do you want to Update this Client...Y/N ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";
            _ReadClientInfo(Client);
            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client.Save();
            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintClient(Client);
                break;
            case clsBankClient::enSaveResults::svFaildEmptyObject:
                cout << "\nError account was not saved because it's Empty";
                break;

            }
        }
    }




};


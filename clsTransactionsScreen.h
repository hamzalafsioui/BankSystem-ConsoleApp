#pragma once
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include "clsTransferLogScreen.h"
class clsTransactionsScreen :protected clsScreen
{
private:

    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6
    };

    static short ReadTransactionsMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do [1 to 6] ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Please enter between 1 and 6 ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        //cout << "\n Balances Screen will be here.\n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen() {
        //cout << "\nTransfer Screen will Be here..\n";
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen() {
        cout << "\nTransfer Log Screen Will be here.\n";
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << "\n\nPress any key to go back to Transactions Menu...";
        system("pause>0");
        ShowTransactionsMenu();

    }


    static void _PerformTransactionsMenuOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenueOptions::eTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }




public:

    static void ShowTransactionsMenu() {
        system("cls");
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer Screen.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenueOptions)ReadTransactionsMenuOption());
    }

};


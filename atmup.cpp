#include <iostream>
#include <conio.h>
#include <iomanip>
#include <direct.h>
#include <windows.h>
#include <fstream>

using namespace std;
int check(int);
int main()
{
    system("cls");
    for (int i = 10; i >= 0; i--)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t" << i;
        Sleep(1000);
        system("cls");
    }
    int a, b, d = 0, x = 0, t, s = 0;
    int A[5], B[5] = {1, 2, 3, 4};
    int c;
    cout << "\t\t\t\t_______________________________________________________\n\n";
    cout << "\t\t\t\t                       Welcome                         \n";
    cout << "\t\t\t\t_______________________________________________________\n\n";
    Sleep(1000);
    cout << "\n\t\t\t\t\t\tInsert Your ATM  Card \n\n";
    Sleep(1000);
    cout << "\n\n\t\t\t\t\tChoose your language" << endl;
    cout << "\n\n\t\t\t1) for English" << endl;
    cout << "\n\n\t\t\t2) for Hindi" << endl;
    cout << "\n\n\t\t\t\t\tEnter your choice : ";
    cin >> a;
    if (a == 1)
    {
        Sleep(1000);
        do
        {
            system("cls");
            cout << "\n\n\t\t\t\t\tChoose any option from the below" << endl;
            cout << "\n\n\t\t\t1) for Deposite" << endl;
            cout << "\n\n\t\t\t2) for Check Balance" << endl;
            cout << "\n\n\t\t\t3) for Withdraw" << endl;
            cout << "\n\n\t\t\t4) for Exit" << endl;
            cout << "\n\n\t\t\t\t\t Enter your choice here : ";
            cin >> b;
            // if (b == 1 || b == 2 || b == 3)
            // {
            switch (b)
            {

            case 1:
            {
                while (true)
                {
                    system("cls");
                    cout << "\n\n\t\t\tEnter deposit amount: ";
                    cin >> t;

                    if (t >= 100 && t % 100 == 0)
                    {
                        system("cls");
                        cout << "\n\n\t\t\tEnter ATM PIN: ";
                        for (int i = 0; i < 4; i++)
                        {
                            cin >> A[i];
                        }

                        int match = 0;
                        for (int j = 0; j < 4; j++)
                        {
                            if (A[j] == B[j])
                                match++;
                        }

                        if (match == 4)
                        {
                            ifstream f1("info.txt");
                            if (!f1)
                            {
                                cout << "\n\t\t\tError: Could not read balance file.\n";
                                break;
                            }
                            f1 >> s;
                            f1.close();

                            s += t;

                            ofstream f2("info.txt");
                            if (!f2)
                            {
                                cout << "\n\t\t\tError: Could not update balance file.\n";
                                break;
                            }
                            f2 << s;
                            f2.close();

                            cout << "\n\t\t\tDeposit of Rs. " << t << " successful.\n";
                            cout << "\t\t\tUpdated Balance: Rs. " << s << "\n";
                            system("pause");
                            break;
                        }
                        else
                        {
                            cout << "\n\t\t\tIncorrect PIN.\n";
                        }
                    }
                    else
                    {
                        cout << "\n\t\t\tPlease enter amount in multiples of 100.\n";
                    }

                    // Ask to retry
                    char retry;
                    cout << "\n\t\t\tDo you want to try again? (y/n): ";
                    cin >> retry;
                    if (retry != 'y' && retry != 'Y')
                    {
                        break;
                    }
                }
                break;
            }

            case 3:
            {
                Sleep(1000);
                while (true)
                {
                    system("cls");
                    cout << "\n\n\t\t\tEnter Amount : ";
                    cin >> c;
                    Sleep(1000);

                    if (c >= 100 && c % 100 == 0)
                    {
                        system("cls");
                        cout << "\n\t\t\tEnter your ATM Pin No. : ";
                        for (int i = 0; i < 4; i++)
                        {
                            cin >> A[i];
                        }

                        int match = 0;
                        for (int j = 0; j < 4; j++)
                        {
                            if (A[j] == B[j])
                                match++;
                        }

                        if (match == 4)
                        {
                            if (check(c) == 1)
                            {
                                ifstream f1("info.txt");
                                if (!f1)
                                {
                                    cout << "\n\t\t\tError reading balance file.\n";
                                    break;
                                }
                                f1 >> s;
                                f1.close();

                                if (c > s)
                                {
                                    system("cls");
                                    cout << "\n\t\t\tSorry... You have Insufficient Amount in your Account\n";
                                    system("pause");
                                    break;
                                }

                                s -= c;

                                ofstream f2("info.txt");
                                if (!f2)
                                {
                                    cout << "\n\t\t\tError updating balance file.\n";
                                    break;
                                }
                                f2 << s;
                                f2.close();
                                system("cls");
                                Sleep(1000);
                                cout << "\n\t\t\tWithdrawal of Rs. " << c << " successful.\n";
                                cout << "\t\t\tRemaining Balance: " << s << "\n";
                                system("pause");
                                break;
                            }
                            else
                            {
                                cout << "\n\t\t\tInvalid withdrawal amount.\n";
                            }
                        }
                        else
                        {
                            cout << "\n\t\t\tIncorrect PIN.\n";
                        }
                    }
                    else
                    {
                        cout << "\n\t\t\tInvalid input. Amount must be in multiples of 100.\n";
                    }

                    // Ask user if they want to try again
                    char retry;
                    cout << "\n\t\t\tDo you want to try again? (y/n): ";
                    cin >> retry;
                    if (retry != 'y' && retry != 'Y')
                    {
                        break;
                    }
                }
                break;
            }

            case 2:
            {
                system("cls");
                Sleep(1000);
                cout << "\n";
                cout << "\n\t\t\tEnter your ATM Pin No. ";

                // Input PIN
                // int match = 0;
                for (int i = 0; i < 4; i++)
                {
                    cin >> A[i];
                }
                int match = 0;
                for (int j = 0; j < 4; j++)
                {
                    if (A[j] == B[j])
                    {
                        match++;
                    }
                }

                if (match == 4)
                {
                    Sleep(1000);
                    system("cls");
                    cout << "\n\t\t\t\tYour current total balance is : ";

                    ifstream f1("info.txt");
                    if (!f1)
                    {
                        cout << "\n\t\t\tError reading balance file.\n";
                        break;
                    }

                    f1 >> s;
                    cout << s << endl;
                    f1.close();
                }
                else
                {
                    cout << "\n\t\t\tIncorrect PIN.\n";
                }
                // break;
                system("pause"); // To allow user to see the output
                break;
            }
            default:
            {
                cout << "\n\n\t\t\tINVALID INPUT\n";
                // cout << "\n\n\t\t\tPlease choose from the options\n\n ";
                break;
            }
            }

        } while (b != 4);
    }
    else if (a == 2)
    {
        system("cls");
        cout << "\n";
        cout << "\n\t\t\t\tSorry our ATM not support Hindi \n\n";
        Sleep(1000);
        cout << "\t\t\t\tThanks for using our ATM \n\n";
        Sleep(1000);
        cout << "\t\t\t\tHave a Nice Day...\n";
        Sleep(1000);     // Optional: give time before pause
        system("pause"); // Or use getch() if using conio.h
    }
    else
    {
        Sleep(1000);
        cout << "\n";
        cout << "\n\t\t\tInvalid Input";
    }
    return 0;
}

int check(int c)
{
    ifstream f1("info.txt");
    int count = 0, s;
    while (f1 >> s)
    {
        if (c <= s)
        {
            count = 1;
        }
    }
    f1.close();
    return count;
}

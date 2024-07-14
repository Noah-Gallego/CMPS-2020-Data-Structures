#include <iostream>

using namespace std;

class CreditCard
{
    protected:
        string number;
        string type;
        int expmo, expyear;

        bool check_luhn()
        {
            int digits = number.length();
            int nSum = 0, isSecond = false;

            for (int i = digits - 1; i >= 0; i--) {
                int digits = number.length();

                int currentDigit = number[i] - '0';

                if (isSecond == true) {
                    currentDigit *= 2;
                }

                nSum += currentDigit / 10;
                nSum += currentDigit % 10;

                isSecond = !isSecond;
            }

            cout << (nSum % 10 == 0) << endl;
            return (nSum % 10 == 0);
        }

    public:
        CreditCard(string num, int exm, int exy)
        {
            number = num;
            expmo = exm;
            expyear = exy;
        }

        virtual bool validate(int curmo, int cury, string code) = 0;
};

class Visa : public CreditCard
{
    public:
        Visa(string num, int m, int y) : CreditCard(num, m, y)
    {
        type = "Visa";
    }

        bool validate(int cm, int cy, string code)
        {
            int stored = expyear * 100 + expmo;     // 202211
            int curr = cy * 100 + cm;               // 202202

            return (curr <= stored) && number.length() == 16 && code.length() == 3 && number[0] == '4' && check_luhn();
        }    
};

class Mastercard : public CreditCard
{
    public:
        Mastercard(string num, int m, int y) : CreditCard(num, m, y)
    {
        type = "Mastercard";
    }

        bool validate(int cm, int cy, string code)
        {
            int stored = expyear * 100 + expmo;     // 202211
            int curr = cy * 100 + cm;               // 202202

            return (curr <= stored) && number.length() == 16 && code.length() == 4 && number[0] == '5' && check_luhn();
        }    
};

class Amex : public CreditCard
{
    public:
        Amex(string num, int m, int y) : CreditCard(num, m, y)
    {
        type = "Amex";
    }

        bool validate(int cm, int cy, string code)
        {
            int stored = expyear * 100 + expmo;     // 202211
            int curr = cy * 100 + cm;               // 202202

            return (curr <= stored) && number.length() == 15 && code.length() == 4 && number[0] == '3' && check_luhn();
        }    
};

/*
 * Validation rules
 * ----------------
 *  AMEX => 15 chars long, starts with a '3', code = length 4
 *  MC   => 16 chars long, starts with a '5', code = length 3
 *
 * */

// Factory function to return child objects of CreditCard
CreditCard * create()
{
    string ccno;
    int ccmo, ccyr;

    cout << "Enter credit card number: ";
    cin >> ccno;

    cout << "Enter card exp month and year ";
    cin >> ccmo >> ccyr;

    switch(ccno[0]) {
        case '4':
            return new Visa(ccno, ccmo, ccyr);
        case '3':
            return new Amex(ccno, ccmo, ccyr);
        case '5':
            return new Mastercard(ccno, ccmo, ccyr);
        default:
            return NULL;
    }
}

int main()
{   
    int valmo = 2, valyear = 2024;  // this represents the current month and year
    string valcode;

    CreditCard * cc = create();

    if (cc != NULL)
    {
        cout << "Enter validation code: ";
        cin >> valcode;

        // Polymorphic call to validate function
        // The correct validate function is called regardless of 
        // which child CreditCard object has been created
        if (cc->validate(valmo, valyear, valcode))
        {
            cout << "Approved" << endl;
        }
        else
        {
            cout << "Declined" << endl;
        }
    }
    else
        cout << "Invalid credit card" << endl;

    delete cc;

    return 0;
}


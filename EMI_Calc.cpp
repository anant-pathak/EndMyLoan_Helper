#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void emi_calculator(float &monthly, float &interest, float &amt, float &months_repay)
{
    std::cout<< "\t" << "Monthly" << "\t" << "ACH" << "\t" <<  "\t" << "Left" << endl;
    interest = ((interest/100)/12);
    float payment_per_month = (amt * (interest) * static_cast<float>(pow( (1+interest) ,  months_repay))) / 
                            ( static_cast<float>(pow( (1+interest) ,  months_repay)) - 1);;
    int i = 1;
    float total_amt_paid = 0.0;
    bool monthly_payment_valid = monthly;
    cout << fixed << std::setprecision(2);
    while(amt > 0)
    {
        if( monthly_payment_valid )
        {
            payment_per_month = (amt * (interest) * static_cast<float>(pow( (1+interest) ,  months_repay))) / 
                            ( static_cast<float>(pow( (1+interest) ,  months_repay)) - 1);
        }
        if(amt <= monthly)
        {
            monthly = amt - payment_per_month;
        }
        total_amt_paid = total_amt_paid + payment_per_month + monthly;
        amt = amt - payment_per_month - monthly;
        months_repay--;
        cout << i++ << "\t" <<monthly << "\t" << payment_per_month << "\t" <<  "\t" << (amt >= 0 ? amt : 0) << endl;
    }
    cout <<"Total amount you paid = " << total_amt_paid << endl;
}

int main()
{
    
    float monthly;
    float interest_yearly;
    float amt;
    float months_to_repay;
    cout << "\nMonthly  =  ? "; 
    cin >> monthly;
    cout << "\nInterest/year = ? ";
    cin >> interest_yearly;
    cout << "\nCurrent amt = ? ";
    cin >> amt;
    cout << "\nTotal months to repay = ? " ; 
    cin >> months_to_repay;
    cout << endl;
    emi_calculator(monthly, interest_yearly, amt, months_to_repay);
    return 0;
}
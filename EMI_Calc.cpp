#include <iostream>
#include <math.h>

using namespace std;

void emi_calculator(float &monthly, float &interest, float &amt, float &months_repay)
{
    interest = ((interest/100)/12);
    float payment_per_month;
    while(amt > 0)
    {
        payment_per_month = (amt * (interest) * static_cast<float>(pow( (1+interest) ,  months_repay))) / 
                            ( static_cast<float>(pow( (1+interest) ,  months_repay)) - 1);
        if(amt <= monthly)
        {
            monthly = amt - payment_per_month;
        }
        amt = amt - payment_per_month - monthly;
        months_repay--;
        cout << monthly << "\t" << payment_per_month << "\t" << amt << endl;
    }
}

int main()
{
    std::cout<< "Monthly" << "\t" << "ACH" << "\t" << "Left" << endl;
    float monthly;
    float interest_yearly;
    float amt;
    float months_to_repay;
    cout << "\nMonthly  =  ? "; 
    cin >> monthly;
    cout << "\nInterest/year = ?";
    cin >> interest_yearly;
    cout << "\nCurrent amt = ?";
    cin >> amt;
    cout << "\nTotal months to repay = ?" ; 
    cin >> months_to_repay;
    cout << endl;
    emi_calculator(monthly, interest_yearly, amt, months_to_repay);
    return 0;
}
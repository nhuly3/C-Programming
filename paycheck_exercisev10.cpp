#include<iostream>
using namespace std;

int main()
{

    // these are the variables
    int regPay;
    const double otPay = 1.5;
    int total;
    double product1;
    int finalTotal;
    double otTotal;
    int hoursWorked;
    int otDifference;
    int hoursDifference;
    const int fullTimeHours = 40;
    // asking user input for hours worked
    cout << "Enter hours worked: \n"; 
    cin >> hoursWorked;
    cout << "Enter wage: \n";
    cin >> regPay;
    // got our information for computations
    if (hoursWorked < fullTimeHours) {
    total = regPay * hoursWorked;
    cout << "Pay for regular hours is: \n" << total;
    }
    
    else if (hoursWorked = 40){
    total = hoursWorked * regPay;
    cout << "\nPay for regular hours is: \n" << total;
    }
    
    else {
    otDifference = hoursWorked - fullTimeHours;
    product1 = otDifference * regPay;
    otTotal = product1 * otPay;
    total = regPay * fullTimeHours;
    finalTotal = otTotal + total;
    cout << "\nPay for overtime: \n" << finalTotal;
    }
    
    cout << "\nTotal pay: \n" << total + otTotal;
    
    return 0;
    }
    

    
     
//Leroy Harrison IV
//Feb 26, 2016
/*Develop a program C++ that will determine the gross pay and the net pay (after taxes). Employers */
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

float time(float, float);
float extra(float);
float govMoney(float, float);
float netMoney(float, float);
void ending(string, char, float, float, float, float, float, float, float, float);
void format();

int main()
{
    ifstream inputFile;

    float hours, rate, gross_pay, net_pay, taxes, bonus, dependents, years_serviced;
    string name;
    char initial;
    inputFile.open("data 6.1.dat");

    cout<<setw(10)<< "Pay Roll Output" <<endl;
    format();

    while (!inputFile.eof())
    {


    inputFile>>initial>>name>>hours>>rate>>years_serviced>>dependents;


    /*The gross pay if hours is
    greater than 40.*/

    //Overtime rate is .15

   gross_pay = time(hours, rate);
    bonus = extra(years_serviced);
    gross_pay += bonus;


    //Tax is .15% if gross_pay is over $500 and dependets is 2 or less.

    taxes = govMoney(gross_pay, dependents);
    //Calcualte net_pay(after taxes)
    net_pay = netMoney(gross_pay, taxes);

    //display(name, initials, bonus, gross_pay,taxes, net_pay);

    ending(name, initial, hours, rate, years_serviced, dependents, bonus, gross_pay, taxes, net_pay);

    }

    inputFile.close();

    return 0;
}

float time(float hours, float rate)
{
    if (hours > 40){
    return  (40 * rate) + (rate * 1.5) * (hours - 40) ;
    }

    else
    return hours * rate;
}

float extra(float years_serviced)
{
    if (years_serviced > 0 && years_serviced <= 5)
        return 100;
  else if (years_serviced > 5 && years_serviced <= 10)
        return 250;
  else if (years_serviced > 10 && years_serviced <= 20)
        return 500;
    else if (years_serviced > 20)
        return 1000;
}

float govMoney(float gross_pay, float dependents)
{

    if (gross_pay > 500 && dependents <= 3)
        return (gross_pay - 500) * .12;

    //Tax is 1.25% if the number of dependents is greater than three.
    else if (gross_pay > 500 && dependents >= 4)
        return (gross_pay - 500) * .095;

}

void ending(string name, char initial, float hours, float rate, float years_serviced, float dependents, float bonus, float gross_pay, float taxes, float net_pay)
{
    //cout<<endl << "         Pay Roll Report          "<<endl;
    //cout<<endl;

    cout<<left<<setw(7)<<name << " " <<initial<<". ";
    cout<<left<<setw(6)<<hours;
    cout<<left<<setw(7)<<rate;
    cout<<left<<setw(14)<<years_serviced;
    cout<<setw(5)<<dependents;
    cout<<"$"<<setw(6)<< bonus;
    cout<<"$"<<setw(10)<<setprecision(5)<< gross_pay;
    cout<<"$"<<setw(10)<<taxes;
    cout<<"$"<< setw(10)<<net_pay << endl;
}
float netMoney(float gross_pay, float taxes)
{
    return gross_pay - taxes;
}

void format()
{
cout<<left<<setw(11)<< "Name" <<setw(6)<<left << "Hours" <<setw(7)<<left<< "Rate" <<setw(14) <<left<< "Years Serv." <<setw(5)<<left<< "Dep"<<left<<setw(6)
<< "Bonus"<<left<<setw(12) << "Gross Pay"<<left<<setw(10) << "Taxes" <<left<<setw(10)<< "Net Pay" <<endl;
}

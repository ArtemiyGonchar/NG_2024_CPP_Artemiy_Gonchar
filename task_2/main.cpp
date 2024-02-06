#include <iostream>

using namespace std;

int main()
{
    int salary = 0;
    cout<<"Enter your salary"<<"\n";
    cin>>salary;
    if (salary < 1000){
        cout<<"Work harder!"<<"\n";
    }
    if (salary > 999){
        if(salary > 999999){
            cout<<"You are rich!\nAnd you doing great work!";
                return 0;
        }
        cout<<"Good."<<"\n";
    }
    cout<<"And you doing great work!\n";
    return 0;
}

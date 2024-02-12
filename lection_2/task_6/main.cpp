#include <iostream>

using namespace std;

int main()
{
    int bank[10]{};
    int deposit = 0;
    int card = 0;
    while (true){
        cout<<"Enter number of card to deposite some money: "<<"\n";
        cin>>card;
        cout<<"Enter amount of money to deposite: "<<"\n";
        cin>>deposit;
        bank[card] = bank[card] + deposit;
        cout<<"Bank: ";
        for(int number = 0; number < 10; number++){
            cout<<bank[number]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

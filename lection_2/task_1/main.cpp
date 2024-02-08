#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int evenSum = 0;
    int oddSum = 0;
    int arraySize = 0;
    cout<<"Enter array size: ";
    cin>>arraySize;
    int array[arraySize];
    for (int i = 0; i < arraySize;i++){
        cout<<"Enter number: ";
        cin>>array[i];
    }
    for(int number = 0; number < arraySize ;number++){
        sum += array[number];
        if (array[number] % 2 == 0){
            evenSum += array[number];
        } else {
            oddSum += array[number];
        }
    }
    cout<<"Sum of all numbers: "<<sum<<"\n";
    cout<<"Sum of even numbers: "<<evenSum<<"\n";
    cout<<"Sum of odd numbers: "<<oddSum<<"\n";

    return 0;
}

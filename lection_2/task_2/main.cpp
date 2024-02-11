#include <iostream>

using namespace std;

int main()
{
    int min = 0;
    int max = 0;
    int thirdNumber = 0;
    int arraySize = 0;
    cout<<"Enter array size: ";
    cin>>arraySize;
    int array[arraySize];
    for (int number = 0; number < arraySize;number++){
        cout<<"Enter number: ";
        cin>>array[number];
    }
    min = array[0];
    max = array[1];
    for (int number = 0; number < arraySize;number++){
        if (array[number] < min){
            min = array[number];
        }
        if (array[number] > max){
            max = array[number];
        }
    }
    cout<<"min: "<<min<<"\n";
    cout<<"max: "<<max<<"\n";
    return 0;
}

#include <iostream>

using namespace std;

int main(){
    int size = 0;
    cout<<"Enter size of the tree: ";
    cin>>size;
    for(int iteration = size; iteration > 0; iteration--){
        for(int space = iteration - 1; space > 0; space--){
            cout<<" ";
        }
        for (int star = 0; star <=(size - iteration)*2; star++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int spaceEnd = 0; spaceEnd < size - 1; spaceEnd++){
        cout<<" ";
    }
    cout<<"*"<<"\n";
    return 0;
}

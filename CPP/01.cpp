#include <iostream>
using namespace std;
int main() {
    int p,r,t;
    cin>>p>>r>>t;
    float si;
    si=(p*r*t)/100.0;
    if(si<50){
        cout<<"Invalid Input"<<endl;
    }
    else{
        cout<<"Pay Simple Interest is: "<<si<<endl;
    }    
   

    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int count=1;
    string n;
    cin >> n;
    for(int i=0;i<n.length(); i++){
        if(n[i] == 'a'|| n[i] == 'e'|| n[i] == 'i'|| n[i] == 'o'|| n[i] == 'u'|| n[i] == 'A'|| n[i] == 'E'|| n[i] == 'I'|| n[i] == 'O'|| n[i] == 'U'){
            count++;
        }
    }cout<< count;

    return 0;
}
# include<iostream>
using namespace std;

int main(){
    int n,i,j;
    cin >> n;
    for(i=0;i<n;i++){
        for (j=0;j<=i;j++){
            if(j==0||i==n-1||j==i){
                cout <<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
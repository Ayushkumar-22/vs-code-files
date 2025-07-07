// # include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         for (int j=i;j<=n;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
    
//     return 0;
// }


// another way -- 

# include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=n;i>0;i--){
        for (int j=i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}
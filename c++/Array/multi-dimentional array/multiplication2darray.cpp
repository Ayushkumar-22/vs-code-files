#include<iostream>
using namespace std;

int main(){
   int mat1[3][3], mat2[3][3], mat3[3][3], sum=0, i, j, k;

   cout << "Enter elements of first matrix: " << endl;
   for(i=0; i<3; i++){
      for(j=0; j<3; j++){
         cin >> mat1[i][j];
      }
   }

   cout << "Enter elements of second matrix: " << endl;
   for(i=0; i<3; i++){
      for(j=0; j<3; j++){
         cin >> mat2[i][j];
      }
   }

   for(i=0; i<3; i++){
      for(j=0; j<3; j++){
         sum=0;
         for(k=0; k<3; k++)
            sum = sum + mat1[i][k] * mat2[k][j];
         mat3[i][j] = sum;
      }
   }

   cout << "\nMatrix 1 ...\n";
   for(i=0; i<3; i++){
      for(j=0; j<3; j++)
         cout << mat1[i][j] << "\t";
      cout << "\n";
   }

   cout << "\nMatrix 2 ...\n";
   for(i=0; i<3; i++){
      for(j=0; j<3; j++)
         cout << mat2[i][j] << "\t";
      cout << "\n";
   }

   cout << "\nMultiplication of the two given Matrices: \n";
   for(i=0; i<3; i++){
      for(j=0; j<3; j++)
      cout << mat3[i][j] << "\t";
      cout << "\n";
   }

   return 0;
}
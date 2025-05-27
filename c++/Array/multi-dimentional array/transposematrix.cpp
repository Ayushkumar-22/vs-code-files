#include <iostream>
using namespace std;

int main() {
    

    int N, M;
    cout << "Enter the number of rows: ";
    cin >> N;
    cout << "Enter the number of columns: ";
    cin >> M;

    int matrix[N][M];
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Transpose the matrix
    int transposedMatrix[M][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    // Display the transposed matrix
    cout << "The transposed matrix is:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
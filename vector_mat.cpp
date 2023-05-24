#include <iostream>
#include <omp.h>
using namespace std ;
void matrix_mul( int mat[100][100] , int vect[100][1] , int r1 , int c1 )
{
    int ans[r1][1] ;
	#pragma omp parallel for		
	for(int i=0;i<r1;i++)
	{
		#pragma omp parallel for
		for(int j=0;j<1;j++)
		{
			ans[i][j]=0;
			for(int k=0;k<c1;k++)
			{
				ans[i][j]=ans[i][j]+mat[i][k]*vect[k][j];
			}
		}
	}
    cout << "Parallel Vector Matrix Multiplication : " << endl ;
    for(int i = 0 ; i < r1 ; i++ )
    {
        for(int j = 0 ; j < 1 ; j++ )
        {
            cout << ans[i][j] << " " ;
        }
        cout << endl ;
    } 
}
int main() 
{
    int r1,r2,c1 ;
    cout << "Enter the Row in matrix A : " ;
    cin >> r1 ;
    cout << "Enter the Column in Matrix A : " ;
    cin >> c1 ;
    int mat[100][100] ;
    for(int i = 0 ; i < r1 ; i++ )
    {
        for(int j = 0 ; j < c1 ; j++ )
        {
            cin >> mat[i][j] ;
        }
    }
    cout << endl ;
    cout << "Enter the Row in Vector Matrix : " ;
    cin >> r2 ; 
    int vect[100][1] ;
    for(int i = 0 ; i < r2 ; i++ )
    {
        for(int j = 0 ; j < 1 ; j++ )
        {
            cin >> vect[i][j] ;
        }
    }
    cout << endl ;
    if(r2 == c1)
    {
        matrix_mul( mat , vect , r1 , c1 ) ;
    }
    else 
    {
        cout << "Parallel Vector Matrix Multiplication is not Possible...........! " ;
    }
    return 0 ;
}
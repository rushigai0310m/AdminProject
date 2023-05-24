#include <iostream>
#include <omp.h>
using namespace std ;
void matrix_mul( int mat1[100][100] , int mat2[100][100] , int r1 , int c1 ,  int c2 )
{
    int ans[r1][c2] ;
	#pragma omp parallel for		
	for(int i=0;i<r1;i++)
	{
		#pragma omp parallel for
		for(int j=0;j<c2;j++)
		{
			ans[i][j]=0;
			for(int k=0;k<c1;k++)
			{
				ans[i][j]=ans[i][j]+mat1[i][k]*mat2[k][j];
			}
		}
	}
    cout << "Parallel mat1rix Multiplication : " << endl ;
    for(int i = 0 ; i < r1 ; i++ )
    {
        for(int j = 0 ; j < c2 ; j++ )
        {
            cout << ans[i][j] << " " ;
        }
        cout << endl ;
    } 
}
int main() 
{
    int r1,r2,c1,c2 ;
    cout << "Enter the Row in mat1rix A : " ;
    cin >> r1 ;
    cout << "Enter the Column in mat1rix A : " ;
    cin >> c1 ;
    int mat1[100][100] ;
    for(int i = 0 ; i < r1 ; i++ )
    {
        for(int j = 0 ; j < c1 ; j++ )
        {
            cin >> mat1[i][j] ;
        }
    }
    cout << endl ;
    cout << "Enter the Row in mat1rix B : " ;
    cin >> r2 ;
    cout << "Enter the Column in mat1rix B : " ;
    cin >> c2 ;   
    int mat2[100][100] ;
    for(int i = 0 ; i < r2 ; i++ )
    {
        for(int j = 0 ; j < c2 ; j++ )
        {
            cin >> mat2[i][j] ;
        }
    }
    cout << endl ;
    if(r2 == c1)
    {
        matrix_mul( mat1 , mat2 , r1 , c1  , c2 ) ;
    }
    else 
    {
        cout << "Parallel mat1rix Multiplication is not Possible...........! " ;
    }
    return 0 ;
}
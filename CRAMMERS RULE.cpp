
#include<iostream>
#include<conio.h>
#include <bits/stdc++.h>
using namespace std;

// This functions finds the determinant of Matrix
double determinantOfMatrix(double mat[3][3])
{

    double ans;
    ans = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])
          - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
          + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    return ans;
}

// This function finds the solution of system of
// linear equations using cramer's rule
void findSolution(double coeff[3][4])
{
     cout.precision(3);
    cout.setf(ios::fixed);
    // Matrix d using coeff as given in cramer's rule
    double d[3][3] = {
        { coeff[0][0], coeff[0][1], coeff[0][2] },
        { coeff[1][0], coeff[1][1], coeff[1][2] },
        { coeff[2][0], coeff[2][1], coeff[2][2] },
    };
    // Matrix d1 using coeff as given in cramer's rule
    double d1[3][3] = {
        { coeff[0][3], coeff[0][1], coeff[0][2] },
        { coeff[1][3], coeff[1][1], coeff[1][2] },
        { coeff[2][3], coeff[2][1], coeff[2][2] },
    };
    // Matrix d2 using coeff as given in cramer's rule
    double d2[3][3] = {
        { coeff[0][0], coeff[0][3], coeff[0][2] },
        { coeff[1][0], coeff[1][3], coeff[1][2] },
        { coeff[2][0], coeff[2][3], coeff[2][2] },
    };
    // Matrix d3 using coeff as given in cramer's rule
    double d3[3][3] = {
        { coeff[0][0], coeff[0][1], coeff[0][3] },
        { coeff[1][0], coeff[1][1], coeff[1][3] },
        { coeff[2][0], coeff[2][1], coeff[2][3] },
    };

    // Calculating Determinant of Matrices d, d1, d2, d3
    double D = determinantOfMatrix(d);
    double D1 = determinantOfMatrix(d1);
    double D2 = determinantOfMatrix(d2);
    double D3 = determinantOfMatrix(d3);
    cout<<" \n\n \t Determinant of the Equation \n\n";
     cout<<"\t general determinant = "<<D<<"\n\n";
     cout<<"\t x1 determinant = "<<D1<<"\n\n";
     cout<<"\t x2 determinant = "<<D2<<"\n\n";
     cout<<"\t x3 determinant = "<<D3<<"\n\n";
    // Case 1
    if (D != 0) {
        // Coeff have a unique solution. Apply Cramer's Rule
        double x = D1 / D;
        double y = D2 / D;
        double z = D3 / D; // calculating z using cramer's rule
        cout<<"\n\n \t Result of the simultanous Equation \n\n";
        cout<<"\t x1 = "<<x<<"\n\n";
        cout<<"\t x2 = "<<y<<"\n\n";
        cout<<"\t x3 = "<<z<<"\n\n";
    }
    // Case 2
    else {
        if (D1 == 0 && D2 == 0 && D3 == 0)
            cout<<"Infinite solutions\n";
        else if (D1 != 0 || D2 != 0 || D3 != 0)
            cout<<"No solutions\n";
    }
}

// Driver Code
int main()
{

    // storing coefficients of linear equations in coeff matrix
//    double coeff[3][4] = {
//        { 2, -1, 3, 9 },
//        { 1, 1, 1, 6 },
//        { 1, -1, 1, 2 },
//    };

double equation[3][4];
     for(int i=0; i<3; i++){
          cout<<"Enter Equation "<<i+1<<"\n\n";
          for(int j=0; j<4; j++)
            {
            //Input values of equations in rows and column ;
                cout<<"enter values for row :"<<i+1<<"  and column : "<<j+1<<"\n";
                cin>>equation[i][j];
            }
     }
     //display the equation
     cout<<"\n\n Matrix representation of the equation \n";
     for(int i=0; i<3; i++){
          for(int j=0; j<4; j++){
               cout<<"\t"<<equation[i][j]<<"  ";
          }
          cout<<"\n\n";
     }
    findSolution(equation);
    return 0;
}

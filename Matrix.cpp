#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Matrix
{
private:
    int arr[30][30];//First subscript designates row, second subscript column
    int nrows, ncols;
public:
    Matrix();//default constructor, set a one by one matrix with element zero
    void Readln(ifstream &fil);
    void PrintOut(); //Prints only the matrix
    int GetRows();
    int GetCols();
    friend Matrix operator +(Matrix A, Matrix B);
    friend Matrix operator -(Matrix A, Matrix B);
    friend Matrix operator *(Matrix A, Matrix B);
};

int main()
{
    Matrix mata, matb, matc;
    ifstream inputf, inputsec;
    inputf.open("ColtoMult1.txt");
    inputsec.open("ColtoMult2.txt");
    if (inputf.fail() || inputsec.fail())
    {
        cout << "File is missing\n";
        exit(0);
    }
    mata.Readln(inputf);
    cout << "Original first matrix has " << mata.GetRows() << " rows and " << mata.GetCols() << " columns\n";
    mata.PrintOut();
    matb.Readln(inputsec);
    cout << "Original second matrix has " << matb.GetRows() << " rows and " << matb.GetCols() << " columns\n";
    matb.PrintOut();
    if ((mata.GetRows() == matb.GetRows()) && (mata.GetCols() == matb.GetCols()))
    {
        matc = mata + matb;
        cout << "\nAdding the two gives \n";
        matc.PrintOut();
        cout << "\nSubtracting the two gives \n";
        matc = mata - matb;
        matc.PrintOut();
        cout << "\nTry Multiplying\n";
        if (mata.GetCols() == matb.GetRows())
        {
            matc = mata * matb;
            cout << "\n Multiplying the first times the second gives a matrix with " << matc.GetRows() << " rows and " << matc.GetCols() << " columns\n";
            matc.PrintOut();
        }
        else
            cout << "These two matrices are unsuitable for multiplication in that order.\n";
    }
    else if (mata.GetCols() == matb.GetRows())
    {
        matc = mata * matb;
        cout << "\n Multiplying the first times the second gives a matrix with " << matc.GetRows() << " rows and " << matc.GetCols() << " columns\n";
        matc.PrintOut();
    }
    else
    {
        cout << "These two matrices are unsuitable for addition.\n";
        cout << "These two matrices are unsuitable for subtraction\n";
        cout << "\nTry Multiplying\n";
        cout << "These two matrices are unsuitable for multiplication in that order.\n";
    }
        

    inputf.close();
    inputsec.close();

    return 0;
}
Matrix::Matrix()
{
    nrows = 0, ncols = 0;
    arr[nrows][ncols] = 0;
}
void Matrix::Readln(ifstream &fil)
{
    int tempcols(0), colval(1);
    char letr, var;
    fil >> arr[nrows][ncols];
    ncols++;
    while (!fil.eof())
    {
        var = fil.peek();
        if (var == '\n')
        {
            fil.get(letr);
            nrows++;
            ncols = ncols / (tempcols + 1);
            tempcols++;
            colval = 0;
        }
        fil >> arr[nrows][colval];
        colval++;
        ncols++;
    }
    return;//Rows is N-1 while cols is N
}
void Matrix::PrintOut()
{
    for (int x = 0; x < nrows; x++)
        for (int y = 0; y < ncols + 1; y++)
        {
            cout << setw(5) << arr[x][y];
            if (y == ncols)
            {
                cout << '\n';
            }
        }
}

int Matrix::GetRows()
{
    int rows = nrows;
    return rows;
}

int Matrix::GetCols()
{
    int cols = ncols + 1;
    return cols;
}
Matrix operator +(Matrix A, Matrix B)
{
    Matrix addanswer;
    int i, j;
    for ( i = 0; i < A.GetRows(); i++)
    {
        for ( j = 0; j <= A.GetCols()-1; j++)
        {
            addanswer.arr[i][j] = A.arr[i][j] + B.arr[i][j];
        }
        addanswer.nrows =i+1;//Setting the rows equal to the answer
        addanswer.ncols = j-1;//Setting ncols equal to the answer.
    }
    
    return addanswer;
}
Matrix operator -(Matrix A, Matrix B)
{

        Matrix subanswer;
        int c, d;
        for (c = 0; c < A.GetRows(); c++)
        {
            for (d = 0; d <= A.GetCols() - 1; d++)
            {
                subanswer.arr[c][d] = A.arr[c][d] - B.arr[c][d];
            }
            subanswer.nrows = c + 1;
            subanswer.ncols = d - 1;
        }

        return subanswer;
}
Matrix operator *(Matrix A, Matrix B)
{
    Matrix multanswer;
    int m, n, o;
    for (m = 0; m < A.GetRows(); m++)
    {
        for (n = 0; n <= B.GetCols()-1; n++)
        {
            multanswer.arr[m][n] = 0;//Setting it equal to zero to multiply again
            for(o = 0; o< B.GetRows();o++)
            multanswer.arr[m][n] += A.arr[m][o] *B.arr[o][n];// Multiply and add.
        }
        multanswer.nrows = m + 1;
        multanswer.ncols = n - 1;
    }

    return multanswer;
}














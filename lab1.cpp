#include <iostream>
using namespace std;

void sp_mid( int arr[][], const int allrows, const int allcols)

int main()
{
    int allrows = 200, allcols = 200; // размер массива
    int **arr = new int* [allrows];
     // Выделение памяти для массива
        
        for (int i = 0; i < allrows; i++)
        {
            arr[i] = new int[allcols];
        }
     /////////// заполнение ммассива   
    for (int i = 0; i < allrows; i++)
    {
        for (int j = 0; j < allcols; j++)
        {
            arr[i][j] = rand() % 20;
        }
    }
    ///////////

    /////////a)	по правым диагоналям, начиная с правого верхнего элемента
       

    /////////c)	по спирали, начиная с центрального элемента
    sp_mid(arr, allrows, allcols);
        
    
    for (int i = 0; i < allrows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr; // очистка памяти
    
    return 0;
}

void sp_mid( int arr[][], const int allrows, const int allcols)
{
    int *mas3 = new int[allrows*allcols];
    int i=1, row, col, rows=100, cols=99, cer=0, shift=1;

    mas3[0]=arr[rows][cols];
    
    while(rows!=0 && cols!=0)
    {
        row = shift; col = shift;
        if(cer==0)
        {
            while(col!=0)
            {
                cols++; col--;
                mas3[i]=arr[rows][cols];
                i++;
            }
            while(row!=0)
            {
                rows--; row--;
                mas3[i]=arr[rows][cols];
                i++;
            }
            shift++;
            cer++;
        }
        else if(cer==1)
        {
            while(col!=0)
            {
                cols--; col--;
                mas3[i]=arr[rows][cols];
                i++;
            }
            while(row!=0)
            {
                rows++; row--;
                mas3[i]=arr[rows][cols];
                i++;
            }
            shift++;
            cer--;
        }
    }
}
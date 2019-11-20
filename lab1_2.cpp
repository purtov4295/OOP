#include <iostream>

using namespace std;

int main()
{
    int rows = 4, cols = 6; // размер массива
    int **arr = new int*[rows]; // Выделение памяти для массива
        
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
        }
     /////////// заполнение ммассива   
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 20;
        }
    }
    ///////////

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    
    
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr; // очистка памяти
    return 0;
}
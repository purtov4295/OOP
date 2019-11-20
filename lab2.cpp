#include <iostream>
using namespace std;

int insert(int mas[], int n, int m, int index, int x)
{
    if (n>=m)
    {
        cout<<"list is full\n";
        exit(1);
    }
    int j = n;
    while (j >= index)
    {
        mas[j+1] = mas[j];
        j--;
    }
    mas[index] = x;
    n++;
    return n;   
}

int deleted(int mas[], int n, int index)
{
    if (index<1 || index<n)
    {
        cout<<"Invalid Index\n";
        exit(1);
    }
    
    if (index < n)
    {
        int j = index;
        while (j <= n)
        {
            mas[j] = mas[j+1];
            j++;
        }
    }   

    mas[n] = 0;
    n--;
    
    return n;   
}

int counting(int mas[], int m)
{
    int n = 0;

    while (n <= m && mas[n] != 0)
    {
        n++;
    }
    
    return n;
}

void PafterK(int mas[], int n, int m, int indexP, int indexK)
{
    if (n>=m)
    {
        cout<<"list is full\n";
        exit(1);
    }
    int j = n;
    while (j >= indexK)
    {
        mas[j+1] = mas[j];
        j--;
    }
    mas[indexK+1] = mas[indexP];
    mas[indexP] = 0; 
}

int main()
{
    int m = 99, n = 10;
    int arr[m];

    for (int i = 0; i < n; i++)
    {
        arr[i] = 1 + rand() % 7;
    }
    for (int i = 11; i < m; i++)
    {
        arr[i] = 0;
    }

    int j = 0;

    while (j <= n)
    {
        for (int i = 0; i < j; i++)
        {
            if (arr[j] == arr[i])
                n = deleted(arr, n, j);
            i++;
        }
        
    }
    
    cout<<"Новая длинна строки = "<<n<<"\n";

    return 0;
}
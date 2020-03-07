#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int mas[5], n, max_el=0, n2=0, temp, counter1;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>mas[i];
    if (n==1)
    {
        cout<<mas[0]<<endl;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        counter1=0;
        for(int r = 1; r < mas[i]/2+1; r++)
            if(mas[i]%r==0) counter1++;
        if (counter1==1)
        {
            mas[i]=-mas[i];
            n2++;
        }
    }
    for(int i = 0; i < n-1; ++i)
        for(int r = 0; r < n-i-1; ++r)
            if(mas[r+1] > mas[r])
            {
                temp = mas[r+1];
                mas[r+1] = mas[r];
                mas[r] = temp;
            }
    long long int f;
    for (f=mas[0];; f++)
    {
        int counter=0;
        for (int k=0; k<n-n2; k++)
        {
            if (f%mas[k]!=0) break;
            counter++;
        }
        if (counter==(n-n2)) break;
    }
    for (int i=n-n2; i<n; i++)
    {
        mas[i]=-mas[i];
        if (f%mas[i]!=0) f*=mas[i];
    }
    if (f<0) f=-f;
    cout<<f<<endl;
    return 0;
}


//Проверяем на простоту, потом умножаем простые на -1, потом  умножаем все числа массива

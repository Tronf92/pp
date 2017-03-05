#include<iostream>
using namespace std;

int min(int a[100],int s , int d)
{
    if ( s == d ) return a[s];
       else
       {
           int m = (s+d)/2;
           int m1 = min(a,s,m);
           int m2 = min(a,m+1,d);

           if ( m1 < m2 )  return m1;
           else return m2;

       }
}

int main()
{
    int a[100];
    int n ;
    cout<<"Numarul de elemente:";
    cin>> n;
    cout<<"\nintroduceti  elemente:";
    for (int i = 0 ; i < n ;i++)
        cin>>a[i];
    cout<<"Minimul este:";
    cout << min(a,0,n);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int a[100];int a[100];
int nr;
int min(int s , int d)
{
    printf("\nApelulul recursiv nr %d: ,min(%d,%d)",nr++,s,d);
    if ( s == d ) return a[s];

       else
       {
           int m = (s+d)/2;
           int m1 = min(s,m);
           int m2 = min(m+1,d);

           if ( m1 < m2 )  return m1;
           else return m2;

       }
}

int main()
{
    int n,i ;
    nr=0;
    printf("Numarul de elemente:");
    scanf("%d",&n);
    printf("\nintroduceti  elemente:\n");
    for (i = 0 ; i < n ;i++)
            scanf("%d",&a[i]);


    printf("\nMinimul este %d", min(0,n-1));
    return 0;
}

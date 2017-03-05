#include <stdio.h>
#include <stdlib.h>
int a[100];int nr=0;
int cmmdc( int s, int d)
{
    printf("Apel nr %d: , cmmdc(%d, %d)\n",nr++,s,d);
    if(s==d) return a[s];
  else
  { int x,y;
    x=cmmdc(s,(s+d)/2);
    y=cmmdc((s+d)/2+1,d);
    while(x!=y)
       if(x>y) x=x-y;
       else y=y-x;
    return x;
  }
}

int main()
{
    int n,i ;
     printf("Numarul de elemente:");
    scanf("%d",&n);
    printf("\nintroduceti  elemente:\n");
    for (i = 1 ; i <= n ;i++)
            scanf("%d",&a[i]);


    printf("\n cmmdc este %d", cmmdc(1,n));
    return 0;
}

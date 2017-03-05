#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[100],n,nrsol;

void scriesol ()
{ int i,j;
 nrsol++;
 printf("\nSolutia a %d este: ",nrsol);
 for(i=1;i<=n;i++) {
    printf("\n");
    for(j=1;j<=n;j++)
        if (x[j]==i) printf("X ");
        else printf("- ");
 }
}

int potcont(int k)
{ int  i;

for(i=1;i<=k-1;i++)
if (x[i]==x[k] || k-i==abs(x[k]-x[i])) return 0;
return 1;
}

void back(int k)
{
int i;
for(i=1;i<=n;i++)
{
x[k]=i;
if (potcont(k))
if (k==n) scriesol();
else back(k+1);
}
}

void main()
{
printf("Dimensiunea tablei de sah =Nr. de regine :");
scanf("%d",&n);
nrsol=0;
back(1);
printf("\nIn total avem %d solutii",nrsol);
}


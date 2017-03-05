#include <stdio.h>
#include <stdlib.h>
int x[200],n,p,nr=1;
int valid(int k) {
    int j;
 for( j=1;j<k;j++)
		 if(x[j]==x[k])
			 return 0;
	 return 1;
 }
void afiseaza(){
    int j;
    printf ("\n Solutia nr %d: ",nr++);
    for (j=1;j<=p;j++) printf ("%d ",x[j]);
}

int main() {
    int k,i;
    printf("Introduceti n un numar natural <=200:");
    scanf("%d",&n);
    printf("Introduceti p <=200:");
    scanf("%d",&p);
    k=1;
    x[k]=0;
    k=1;
    for (i=1;i<=n;i++)x[i]=0;
    while (k>0) {
            if (k==p+1) {
                k=k-1; //revenit o pozitie
                afiseaza();
            }
            else
                if (x[k]<n) {
                    x[k]=x[k]+1;
                    if (valid(k)) k=k+1;
                }
                else {
                    x[k]=0;
                    k=k-1;
             }
    }
}

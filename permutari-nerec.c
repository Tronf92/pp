#include <stdio.h>
#include <stdlib.h>
int x[200];
int verif(int k) {
int ret=1,j;
 for (j=1; (j<k)&&(ret==1);j++){
    if (x[j]==x[k]) ret=0;
 }
 return ret;
}
int main() {
    int n,i,k,nr;
    printf("Introduceti un numar natural <=200:");
    scanf("%d",&n);
    nr=0;
    k=1;
    for (i=1;i<=n;i++)x[i]=0;
    while (k>0) {
        if (k==n+1) {
            k=k-1; //revenit o pozitie
                nr=nr+1;
                printf ("\n Solutia nr %d:",nr);
                for (i=1;i<=n;i++) printf ("%d ",x[i]);
        }
        else
             if (x[k]<n) {
                x[k]=x[k]+1;
                if (verif(k)) k=k+1;
             }
             else {
                x[k]=0;
                k=k-1;
             }

    }
}

#include <stdio.h>
#include <stdlib.h>
int x[200],n,nr=1;
int verif(int k) {
int ret=1,j;
 for (j=1; (j<k)&&(ret==1);j++){
    if (x[j]==x[k]) ret=0;
 }
 return ret;
}
void tipar(){
    int j;
    printf ("\n Solutia nr %d: ",nr++);
    for (j=1;j<=n;j++) printf ("%d ",x[j]);
}
void back(int k) {
    int i;
    for(i=1;i<=n;i++){
        x[k]=i;
        if (verif(k))
                if(k==n)
                        tipar();
                else
                   back(k+1);
    }

}

int main() {
    printf("Introduceti un numar natural <=200:");
    scanf("%d",&n);
    back(1);
}

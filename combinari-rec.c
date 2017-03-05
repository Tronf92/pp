#include <stdio.h>
#include <stdlib.h>
int x[200],n,p,nr=1;
/*int valid(int k) {
    int j;
 for( j=1;j<k&&x[j-1]<k;j++)
		 if(x[j]==x[k])
			 return 0;
	 return 1;
 }*/
void afiseaza(){
    int j;
    printf ("\n Solutia nr %d: ",nr++);
    for (j=1;j<=p;j++) printf ("%d ",x[j]);
}
void comb(int k) {
int i;
	  for(i=x[k-1]+1;i<=n;i++)
		 {
		     printf("%dfor",x[k]);
			 x[k]=i;
			 if(k==p)
                    afiseaza();
             else
				 comb(k+1);
		 }
}

int main() {
    printf("Introduceti n un numar natural <=200:");
    scanf("%d",&n);
    printf("Introduceti p <=200:");
    scanf("%d",&p);
    comb(1);
}

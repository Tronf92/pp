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
void back(int k) {
int i;
	 if(k>p)
		 afiseaza();
	 else
		 for(i=1;i<=n;i++)
		 {
			 x[k]=i;
			 if(valid(k))
				 back(k+1);
		 }
}

int main() {
    printf("Introduceti n un numar natural <=200:");
    scanf("%d",&n);
    printf("Introduceti p <=200:");
    scanf("%d",&p);
    back(1);
}

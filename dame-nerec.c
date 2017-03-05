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

void main()
{
    int k,valid;
    printf("Dimensiunea tablei de sah =Nr. de regine :");
    scanf("%d",&n);
    nrsol=0;
    k=1;
    x[k]=0;
    while(k > 0) {  //cat timp am ce verifica pe nivelul curent verific
        valid = 0 ;    //initial invalid
        while(!valid && x[k] < n){  //repet cat timp nu e valid si mai am solutii posibile pe nivelul curent
            x[k] = x[k] + 1;        //incerc urmatoarea pozitie de pe nivelul curent
            valid=potcont(k);      //e oare posibila?
        }
        if(!valid) k--; //daca sau terminat posibilitatile valide pe nivelul curent atunici scad nivelul
        else if(k==n) scriesol(); //daca e solutie atunci o afisez
        else {  //nu s-au terminat posibilitatile si nu e solutie
            k++;        // deci cresc nivelul
            x[k] = 0;   // si initializez noul nivel la 0
        }
    }
    printf("\nIn total avem %d solutii",nrsol);
}

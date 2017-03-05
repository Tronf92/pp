#include <stdio.h>
#include <conio.h>
#include <string.h>

int tabla[50][50];
int n;
int startX,startY;
int solutii;

void AfiseazaTabla()
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf(" %d ",tabla[i][j]);
        }
        printf("\n");
    }

}

void SarituraCalului(int x,int y,int pas)
{
    if ((x<0)||(y<0)||(x>=n)||(y>=n))
        return;

    if (tabla[x][y]!=0)
        return;
    tabla[x][y]=pas;

    if(pas==n*n){
        solutii++;
        printf("-----Solutia:%d------\n",solutii);
        AfiseazaTabla();
    }
    else{
        SarituraCalului(x-1,y-2,pas+1);
        SarituraCalului(x-2,y-1,pas+1);
        SarituraCalului(x-2,y+1,pas+1);
        SarituraCalului(x-1,y+2,pas+1);
        SarituraCalului(x+1,y+2,pas+1);
        SarituraCalului(x+2,y+1,pas+1);
        SarituraCalului(x+2,y-1,pas+1);
        SarituraCalului(x+1,y-2,pas+1);
    }
    tabla[x][y]=0;
}

void main(void)
{
    printf("Introduceti dimensiunea tablei:");
    scanf("%d",&n);

    printf("Introduceti pozitia de start:\n");
    printf("\tX=");scanf("%d",&startX);
    printf("\tY=");scanf("%d",&startY);
    solutii=0;

    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            tabla[i][j]=0;
        }
    }

    SarituraCalului(startX,startY,1);

    if (solutii==0){
        printf("Nu exista nici o solutie!\n");
    }
    else{
        printf("S-au gasit:%d solutii!\n",solutii);
    }

    printf("\n\n-------------\nApasa o tasta...");
    getch();
}

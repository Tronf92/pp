//pozitia urmatoare se alege folosind functia nm care calculeaza in cate pozitii se poate merge din funcita curenta
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int dx[8]={-1,1,2,2,1,-1,-2,-2};
const int dy[8]={-2,-2,-1,1,2,2,1,-1};
int a[201][201],n,gata;
ifstream fin("cal.in");
ofstream fout("cal.out");

void afis()
{ int i,j;
  fout<<"n="<<n<<endl;
  for(i=1;i<=n;i++)
  { for(j=1;j<=n;j++) fout<<setw(4)<<a[i][j]<<" "; //setw din iomanip sets the field width to be used on output operations
    fout<<endl;
  }
 fout<<endl;
 gata=1;
}

int inside(int i,int j)
{
   return i>=1 && i<=n && j>=1 && j<=n;
}

int nm(int i, int j)//calculeaza in cate pozitii poate merge din i,j
{
    int inou,jnou,k,x=0;
    for(k=0;k<8;k++)
	 { inou=i+dx[k];
	   jnou=j+dy[k];
	   if(inside(inou,jnou) && a[inou][jnou]==0) x++;
	 }
    return x;
}

void calgreedy(int i, int j, int pas)
{ int k,v,min=9,inou,jnou,ii,jj;
  if(!gata)
  {
  a[i][j]=pas;
  if (pas==n*n)  afis();
  else for(k=0;k<8;k++)
	 { inou=i+dx[k];
	   jnou=j+dy[k];
	   if (inside(inou,jnou) && a[inou][jnou]==0)
	       {  //cauta pozitia cel mai greu accesibila
	           v=nm(inou,jnou);
	           if(v<min) { min=v; ii=inou; jj=jnou;}
	       }
	 }
  if(min!=9) calgreedy(ii,jj,pas+1);
  a[i][j]=0;
  }
}

int main()
{  cin>>n;
   calgreedy(1,1,1);
   fout.close();
   return 0;
}

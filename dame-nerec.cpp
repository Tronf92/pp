#include <iostream>
#include <ctime>
using namespace std;
inline int abs(int x){
    return x>=0 ? x: -x;
}
clock_t t;
int x[10000];  //tabelul de pozitii pe tabla de sah
int k;      //nivelul curent
bool valid; //este valida solutia partiala curenta?
int n;      //dimensiunile tablei de sah (n * n)
int nr;     //numarul solutiei
void citire(){
    cout<<"n = ";cin>>n;
}
void posibil(int k,bool &valid){
    valid = true;
    for(int i = 1; i <= k - 1; i++)
        //doua dame nu se pot afla pe acceasi coloana (x[k]) sau aceiasi diagonala
        if(abs(x[i] - x[k])==abs(i - k)||(x[i] == x[k])) valid = 0;
}
inline bool solutie(int k){
    return (k == n);
}
void afisare(int k){
    nr++;
    cout<<"Solutia "<<nr<<endl;
    for(int i = 1; i <= k; i++){
        for (int j = 1; j <= k; j++){
            if (x[i] == j)
                cout<<"X"<<" ";
            else cout<<"-"<<" ";
        }
        cout<<endl;
    }
}
void back(){
    k=1;
    x[k]=0;
    while(k > 0) {  //cat tim am ce verifica pe nivelul curent verific
        valid = false;    //initial invalid
        while(!valid && x[k] < n){  //repet cat timp nu e valid si mai am solutii posibile pe nivelul curent
            x[k] = x[k] + 1;        //incerc urmatoarea pozitie de pe nivelul curent
            posibil(k, valid);      //e oare posibila?
        }
        if(!valid) k--; //daca sau terminat posibilitatile valide pe nivelul curent atunici scad nivelul
        else if(solutie(k)) afisare(k); //daca e solutie atunci o afisez
        else {  //nu s-au terminat posibilitatile si nu e solutie
            k++;        // deci cresc nivelul
            x[k] = 0;   // si initializez noul nivel la 0
        }
    }
}
int main(){
    citire();
    nr=0;
    t=clock();
    back();
    t=clock() - t;
    cout.precision(6);
    cout << "Calculul a durat " << (double)t/CLOCKS_PER_SEC << " secunde." << endl;
    cout <<"am gasit "<<nr<<" solutii";
    return 0;
}

#include<iostream>
#include<fstream>

using namespace std;

unsigned int Mat[10][10], n = 0;
bool orientat;

void Citeste(unsigned n, bool orientat, unsigned Mat[10][10]){
    cout<<"Numarul de elemente: "; cin>>n; cout << n;
    for(int i = 1; i<=n; i++)
    {
        cout << "i= "<< i <<'\n';
        for(int j = 1; j<=n; j++)
        {
            cout << "i= "<< i << " j = " << j<<'\n';
            if(orientat){ //citire pentru graf orientat
                if(j != i){
                cout << "Nodul " << i <<" e conectat cu nodul " << j << "  or: ";
                cin >> Mat[i][j];  
                }else{ //diagonala principala va fi mereu 0
                Mat[i][j] = 0;
                }
            }else{
                if(j > i){ //citire pentru graf neorientat
                    cout << "i= "<< i <<'\n';
                    cout << "Nodul " << i <<" e conectat cu nodul " << j << " neor: ";
                    cin >> Mat[i][j];
                    Mat[j][i] = Mat[i][j];
                    
                } 
                if(i == j){//diagonala principala va fi mereu 0
                    Mat[i][j] = 0;
                    
                }
                cout << "i= "<< i <<'\n';
            }
             
        }   
    }
}

void Scriere(int n, unsigned Mat[10][10]){
    ofstream fisier("Fisier.txt");
    for(unsigned i = 1; i<=n; i++)
    {
        for(unsigned j = 1; j<=n; j++)
            fisier << Mat[i][j] << ' ';
        fisier << '\n';
    }
    fisier.close();
}

void AfisareMatriceTast(unsigned Mat[10][10], unsigned n){
    for(unsigned i = 1; i <=n; i++){
        for(unsigned j = 1; j <=n; j++)
            cout << Mat[i][j]<< ' ';
        cout<< '\n';
    }
}

int main(){
    unsigned int mod;
    cout << "Graf Orientat?";
    cin >> orientat;
    cout<<"Aplciatia cu grafuri: \n 1 Citeste elementele din fisier pentru grafuri \n 2 Afisare graful \n 3 Afisati gradul nodului din graf \n 4 Afisati graful partial al grafului \n 5 Afisati subgraful al unui graf \n 6 Afisati graful complet cu n noduri";
    cin >> mod;
    switch (mod)
    {
    case 1:
        Citeste(n, orientat, Mat);
        cout << '\n';
        AfisareMatriceTast(Mat, 3);
        Scriere(3, Mat);
        //cout << "test";
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    default:
        break;
    }

    return 0;
}
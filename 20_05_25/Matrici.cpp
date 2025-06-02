#include<iostream>
#include<fstream>

using namespace std;

unsigned int Mat[10][10], n = 0;


void CitesteTast(unsigned n, unsigned Mat[10][10]){
    bool orientat;
    cout << "Graf Orientat?";
    cin >> orientat;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(orientat){ //citire pentru graf orientat
                if(j != i){
                cout << "Nodul " << i <<" e conectat cu nodul " << j << ": ";
                cin >> Mat[i][j];  
                }else{ //diagonala principala va fi mereu 0
                Mat[i][j] = 0;
                }
            }else{
                if(j > i){ //citire pentru graf neorientat
                    cout << "Nodul " << i <<" e conectat cu nodul " << j << ": ";
                    cin >> Mat[i][j];
                    Mat[j][i] = Mat[i][j];   
                } 
                if(i == j)//diagonala principala va fi mereu 0
                    Mat[i][j] = 0;
            }
             
        }   
    }
}

void Scriere(int n, unsigned Mat[10][10]){
    ofstream fisier("Fisier.txt");
    for(unsigned i = 0; i<n; i++)
    {
        for(unsigned j = 0; j<n; j++)
            fisier << Mat[i][j] << " ";
        fisier << "\n";
    }
    fisier.close();
}

void CitesteFisier(unsigned Mat[10][10], unsigned n){
    ifstream fisier("Fisier.txt");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; ++j)
            fisier >> Mat[i][j];
    }
    fisier.close();
}

void AfisareMatrice(unsigned Mat[10][10], unsigned n){
    for(unsigned i = 0; i <n; i++){
        for(unsigned j = 0; j <n; j++)
            cout << Mat[i][j]<< ' ';
        cout<< '\n';
    }
}

void AfisareGrad(unsigned Mat[10][10], unsigned n){
    int i, Grad = 0;
    cout << "Introduce nodul: "; cin >> i;
    for(int j = 0; j<n; j++)
        if(Mat[i - 1][j] == 1)
            Grad++;
    cout << "Gradul nodului " << i << " este: " << Grad;
}

int main(){
    unsigned int mod;
    cout<<"Numarul de elemente: "; cin>>n; cout << n;
    cout<<"Aplciatia cu grafuri: \n 1 Citeste elementele din fisier pentru grafuri \n 2 Afisare graful \n 3 Afisati gradul nodului din graf \n 4 Afisati graful partial al grafului \n 5 Afisati subgraful al unui graf \n 6 Afisati graful complet cu n noduri";
    cin >> mod;
    switch (mod)
    {
    case 1:
        CitesteTast(n, Mat);
        Scriere(3, Mat);
        //cout << "test";
        break;
    case 2:
        CitesteFisier(Mat, n);
        AfisareMatrice(Mat, n);
        break;
    case 3:
        CitesteFisier(Mat, n);
        AfisareGrad(Mat, n);
        break;
    case 4:
        CitesteFisier(Mat, n);
        break;
    case 5:
        CitesteFisier(Mat, n);
        break;
    case 6:
        CitesteFisier(Mat, n);
        break;
    default:
        break;
    }

    return 0;
}
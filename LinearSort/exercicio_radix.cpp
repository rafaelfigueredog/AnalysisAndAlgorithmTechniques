#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define TAM 100000
#define REP 100

using namespace std;

//VETORES USADOS NO COUNTING ALOCADOS GLOBALMENTE
int *c = (int*)malloc(27*sizeof(int));
char **b = (char**)malloc(TAM*sizeof(char*));

//função de comparação usada no qsort
int compare(const void*a, const void*b) {
    char *va = (char *)a;
    char *vb = (char *)b;
    return strcmp(va,vb);
}

int countingsort(char A[TAM][4], int n, int k, int d) {
    
    memset(c,0,(k+1)*sizeof(int)); 

    // couting
    for (int i = 0; i < n; i++) {
        c[ A[i][d] - 'a' ]++; 
    }
    
    // soma cumulativa
    for (int i = 1; i < 27; i++) {
        c[i] += c[i-1];
    }
         
    for (int i = n-1; i >= 0; i-- ) {
        strcpy(b[ c[A[i][d] - 'a'] - 1], A[i]);
        c[ A[i][d] - 'a' ]--; 
    }
    
    for (int i = 0; i < n; i++ ) {
        strcpy(A[i], b[i]);
    }

}

int main() {
    char nomes[TAM][4];
    char nomescopy[TAM][4];
    srand(time(NULL));
    clock_t ticks[2];

  
    long double radix[REP]; 
    long double quick[REP];

    int it = 0; 
    while (it < REP) {

        //gera strings aleatórias
        for (int i = 0; i < TAM; i++) {
            char stral[4];
            for(int k = 0; k < 3; k++) stral[k] = (rand()%26) + 'a';
            stral[3] = '\0';
            strcpy(nomes[i],stral);
        } 
        
        //faz uma cópia do array de string para usar no qsort
        for(int i = 0; i < TAM; i++) strcpy(nomescopy[i],nomes[i]);
        
        ticks[0] = clock();
        //executa o radix sort
        for(int i = 0; i < TAM; i++) 
            b[i] = (char*)malloc(4*sizeof(char));
        for(int d = 2; d >= 0; d--) {
            countingsort(nomes,TAM,27,d);    
        }
        ticks[1] = clock();
        double tempo1 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;  

        ticks[0] = clock();
        //executa o quicksort
        qsort(nomescopy, TAM, 4*sizeof(char), compare); 
        ticks[1] = clock();
        double tempo2 = (double)(ticks[1] - ticks[0])/ CLOCKS_PER_SEC;  
        
        //verifica se os resultados das ordenações foram iguais
        for(int i = 0; i < TAM; i++) {
            cout << nomes[i] << "  " << nomescopy[i] << " - " << strcmp(nomes[i], nomescopy[i]) << endl;
        }
        radix[it] = tempo1; 
        quick[it] = tempo2; 

        //mostra o tempo de execução dos algoritmos
        printf("N: %d T1: %lf T2: %lf\n", TAM,tempo1, tempo2);

        it++; 
    }

    cout << "Radix" << TAM << ": [";  
    for (int i = 0; i < REP; i++ ) 
        cout << radix[i] << ", "; 
    cout << "]\n"; 

    cout << "Quick" << TAM << ": [";   
    for (int i = 0; i < REP; i++ ) 
        cout << quick[i] << ", "; 
    cout << "]\n"; 

    return 0;    
}


/*  
    Análise do Algoritmo. 
    1. Foi criada uma struct "Item" onde cada Item possui um valor "v" e um peso "w"
    2. Após receber os parametros da entrada os itens são inseridos numa fila de prioridade: 
        - Complexidade dessa operação: log(n)
    3. A fila de prioridade retorna o item com maior relação "valor-peso" 
    4. No método knapsackGreedy é extraído o topo da fila de prioridade até a capacidade da mochila zerar. 
        - Complexidade dessa operação: O(n)
    5. Complexidade total do algoritmo: O(n log(n)) 
*/

#include <iostream>
#include <queue>
#include <iomanip>

using namespace std; 
#define MAX 1000

struct Item {
    double v; 
    double w; 
    Item( double v, double w ) : v(v), w(w) {}; 
}; 

bool operator<( const Item& a, const Item& b ) {
    return ( (a.v/a.w) < (b.v/b.w) ); 
}

double knapsackGreedy(priority_queue<Item> &itens, int N, double W)  {
    double amount = 0.0; 
    double vi, wi, c; 
    while ( !itens.empty() ) {
        if (W == 0) break;  
        // get next item
        vi = itens.top().v;
        wi = itens.top().w;  
        itens.pop(); 
        if ( wi < W ) {
            W -= wi; 
            amount += vi; 
        } else 
            return amount + (W*(vi/wi));   
    }
    return amount; 
}

int main () { 
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int N, W; 
    double vi, wi; 
    cin >> N >> W; 
    priority_queue<Item> itens; 
    for (int i = 0; i < N; i++) {
        cin >> vi >> wi; 
        itens.push(Item(vi, wi)); 
    }   

    /* while (!itens.empty()){
        cout << itens.top().v << " " << itens.top().w << endl; 
        itens.pop(); 
    } */
        
    cout << std::fixed; 
    cout << std::setprecision(4)  << knapsackGreedy(itens, N, W) << endl; 

    return 0; 
}
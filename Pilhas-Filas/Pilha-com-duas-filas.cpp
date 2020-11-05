// -> Implementação de uma pilha com duas filas

#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

class Pilha_comFila{

    public:

        queue<int> fila1, fila2;

        int tamanho(){

            return fila1.size();
        }

        void cria_Pilha(){

            fila1 = queue<int>{};
            fila2 = queue<int>{};
        }

        int topo(){

            return fila1.front();
        }

        // função .push da pilha
        void empilha(int x){

            while(fila1.size() > 0){

                fila2.push(fila1.front()); // enfileira elemento da frente de fila1
                fila1.pop();
            }

            fila1.push(x);

            while(fila2.size() > 0){

                fila1.push(fila2.front()); // enfileira elemento da frente de fila2
                fila2.pop();
            }

        }

        // função .pop da pilha
        int desempilha(){

            if(fila1.empty()){
                cout << "Vazia...";
                exit(0);
            }

            int fila = fila1.front();
            fila1.pop();
            return fila;
        }

};

int main(){

    // -> A pilha utiliza do conceito de "Last In First Out"(LIFO), ou seja elementos que entram por último saem primeiro
    Pilha_comFila pf;
    pf.cria_Pilha();
    pf.empilha(2);
    pf.empilha(4);
    pf.empilha(6);
    pf.empilha(8);
    cout << "O tamanho da pilha eh: " << pf.tamanho() << endl;
    cout << "O topo da pilha eh: " << pf.topo() << endl;
    cout << pf.desempilha() << endl;
    cout << pf.desempilha() << endl;
    cout << pf.desempilha() << endl;
    cout << pf.desempilha() << endl;
    cout << pf.desempilha() << endl;
    return 0;

}
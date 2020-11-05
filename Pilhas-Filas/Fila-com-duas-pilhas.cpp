// Implementação de uma fila com duas pilhas

#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

// Classe com as funções para criar fila com duas pilhas

class Fila_comPilha{

    public:

    // declara duas pilhas
        stack<int> pilha1, pilha2;

        int tamanho_fila(){

            return pilha1.size();
        }

        void cria_Fila(){

            // -> pilhas vazias
            pilha1 = stack<int>{};
            pilha2 = stack<int>{};
        }

        // função .front da fila
        int frente(){

            return pilha1.top(); // -> retorna topo da fila1
        }

        // função .push da fila
        void enfileira(int x){

            while(pilha1.size() > 0){

                pilha2.push(pilha1.top()); // -> pega elemento do topo da pilha1 e coloca em pilha 2
                pilha1.pop(); // desempilha o elemento da pilha1
            }

            pilha1.push(x); // -> empilha prox. elemento se a fila estiver vazia

            while(pilha2.size() > 0){

                pilha1.push(pilha2.top()); // -> pega elemento do topo de pilha2 e empilha em pilha1
                pilha2.pop(); // -> desempilha o elemento de pilha2
            }

        }

        int desenfileira(){

            if(pilha1.empty()){

                cout << "Vazia...";
                exit(0);
            }

            int pilha = pilha1.top();
            pilha1.pop();
            return pilha;
        }

};

int main()
{
    // filas utilizam o conceito de "first in first out"(FIFO) ou seja, o primeiro a entrar eh o primeiro a sair

    Fila_comPilha fp;
    fp.cria_Fila();
    fp.enfileira(2);
    fp.enfileira(4);
    fp.enfileira(6);
    fp.enfileira(8);
    cout << "O primeiro elemento da fila eh: " << fp.frente() << endl;
    cout << "O tamanho da fila eh: " << fp.tamanho_fila() << endl;
    cout << fp.desenfileira() << endl;
    cout << fp.desenfileira() << endl;
    cout << fp.desenfileira() << endl;
    cout << fp.desenfileira() << endl;

    fp.enfileira(40);
    
    return 0;
}
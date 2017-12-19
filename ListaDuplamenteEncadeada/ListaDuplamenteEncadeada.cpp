#include <iostream>

using namespace std;

class No {
	public:
		int valor;
		
		No *prox;
		No *ant;
		
		No(int v) {
			valor = v;
			prox = NULL;
			ant = NULL;
		}
};

class Lista {
	public:
		No *inicio;
		No * fim;
		
		public:
			Lista() {
				inicio = NULL;
				fim = NULL;
			}
			
			Lista(int valor) {
				inicio = new No(valor);
				inicio = fim;
			}	
			
			void inserir(int valor) {
				No *no = new No(valor);

				// ATRIBUI VALOR A LISTA
				no -> valor = valor;
        
   	   	   	   // CRIA A LISTA
   	   	   	   if(inicio == NULL) {
      	  	  	  no -> prox = NULL;
      	  	  	  no -> ant  = NULL;
                
      	  	  	  inicio = no;
      	  	  	  fim = no;
                
      	  	  	  return ;
   	   	   	   }
   	   	   	   
   	   	   	   //INSERE NO FINAL
   	   	   	   fim -> prox = no;
   	   	   	   no -> prox = NULL;
   	   	   	   no -> ant = fim;
   	   	   	   fim = no;
   
   	   	   	   return ;
			}
					
			void inserirNoMeio(int valor, int i) {
				No *no = new No(valor);
				No *atual = inicio;
				
				int indice = 0;
				
				// PERCORRE A LISTA E INSERE VALOR EM DETERMINADA POSI��O
				while(atual != NULL) {
					if(indice == i) {
						no -> prox = atual; // PONTEIRO PR�XIMO DO N� RECEBE ATUAL 
						no -> ant = atual -> ant; // PONTEIRO ANTERIOR DO PR�XIMO N� RECEBE PONTEIRO ANTERIOR DO N� ATUAL
						atual -> ant -> prox = no; // PONTEIROS ATUAL, ANTERIOR E PR�XIMO APONTAM PARA O PR�XIMO N�
						atual -> ant = no; // ATUAL PASSA PRA PR�XIMA POSI��AO E SEU PONTEIRO ANTERIOR APONTA PARA O N�
						
						return ;
					}
					
					atual = atual->prox;
					indice++;
				}
			}
			
			void mostrar(){
				No *atual = inicio;
				
				while (atual!=NULL){
					cout<<"\nValor: "<<atual->valor<<endl;
					atual=atual->prox;
				}
   			}
};

int main() {
	Lista l;
	l.inserir(3);
	l.inserir(8);
	l.inserir(7);
	l.inserir(9);
	l.inserir(45);
	l.inserir(50);
	l.inserirNoMeio(2,5); //(VALOR, POSI��O)
	l.inserirNoMeio(99,3);
	l.mostrar();
	return 0;
}
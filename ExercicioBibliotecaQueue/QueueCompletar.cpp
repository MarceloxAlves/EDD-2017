#include <queue>
#include <iostream>
using namespace std;

template <class T>
class Queue: public queue<T> {
	protected:
		queue<T> fila;
	
	public:
	T popQueue(){
		T tmp=fila.front();
		fila.pop();
		return tmp;
	}
	
	void pushQueue(T el){
		fila.push(el);
	}
	
	void popTodos(){
		while(fila.empty() == false) {
			fila.pop();
		}
    }
    
    void simularPilha(){
    	queue<T> filaAux;
		
		cout << "FILA SIMULADA:" << endl;
		
		while(fila.empty() == false) {
			fila.push(fila.top());
			fila.pop();
				
		}
			
		while(filaAux.empty() == false) {
			cout << filaAux.top() << endl;
			filaAux.pop();
			
		}
 	}
};

int main(){
	Queue<int> q;
	
	q.pushQueue(3);
	q.pushQueue(4);
	q.pushQueue(5);
	q.pushQueue(6);
	q.pushQueue(7);
	q.pushQueue(8);
	
	p.simularPilha();
	
	
	return 0;
}
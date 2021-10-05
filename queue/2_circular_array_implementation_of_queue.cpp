// here we will apply concept of queue in a curcular array

#include<iostream>
using namespace std;

#define n 10

class Queue{
    int* arr = new int[n];
    int front = -1;
    int rear = -1;

public:

    void enqueue(int val){
        
        // case when queue is full
        if((rear+1)%n == front){
            cout << "Queue is full" << endl;
            return;
        }

        // case when there is no element in queue
        else if(front == -1){
            front = rear = 0;
            arr[rear] = val;
        }

        // we area implementing queue in a circular array
        else{
            rear = (rear+1) % n;
            arr[rear] = val;
        }
    }

    void dequeue(){
        // case when queue is empty 
        if(front == -1){
            cout << "No elements for queue" << endl;
            return;
        }

        // case when front == rear
        else if(front == rear){
            front = rear = -1;
            return;
        }
        // condition for remaining cases
        else{
            front = (front+1)%n;
        }
    }

    int top(){
        if(front == -1){
            cout << "No element in queue" << endl;
            // return -1;
        }
        else{
            return arr[front];
        }
    }

    bool empty(){
        return front == -1;
    }

    void print(){
        for(int i= front ; i<= rear ; i++){
            cout << arr[i] <<" " ;
        }cout << endl;
    }
};

int main()
{
    Queue q;
    cout << "Initially queue is empty so empty function returns : " << q.empty() << endl;
    q.enqueue(1);    
    q.enqueue(2);    
    q.enqueue(3);    
    q.enqueue(4);    
    q.enqueue(5);    
    q.print();

    q.dequeue();
    q.print();

    q.dequeue();
    q.print();

    q.dequeue();
    q.print();

    q.enqueue(69);    
    q.print();
    

    q.dequeue();
    q.print();

    q.enqueue(90);    
    q.print();

    cout << q.top() << endl;
    cout << q.empty();
    return 0;
}
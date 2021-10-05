#include<bits/stdc++.h>
using namespace std;

// n = size of array
#define n 10

class Queue{
    int front;
    int rear;
    int * arr;

public:
    Queue(){
        front = -1;
        rear = -1;
        arr = new int[n];
    }

// enqueue function
    void enqueue(int val){
        
        // case when queue is full 
        if(rear == n){
            cout << "queue is full!" << endl;
            return;
        }
        // case when queue is empty 
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = val;
    }


// Dequeue function
    void dequeue(){

        // case when our queue is empty (we cannot pop anything)
        if(front == -1 && rear == -1){
            cout << "No element in queue" << endl;
            return;
        }

        // case when front == rear {example: when front and rear are at index: 0}
        // then we have can pop them by resetting front and rear to -1
        else if(front == rear){
            front = -1;
            rear = -1;
        }

        // case when we have some elements present in queue to pop them, just do front++
        else
        front++;
    }

    bool empty(){
        return (front == -1 && rear == -1);
    }

    int top(){
        return arr[front];
    }

    void print(){
        cout << "front -> ";
        for(int i=front ; i<=rear ; i++)
            cout << arr[i] << " ";
        cout << "<- rear" << endl;
    }

};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(8);

    cout << "Our queue is : ";
    q.print();

    cout << "Top element : " << q.top() << endl;
    // front-> [5]-[6]-[4]-[3]-[8] <-rear

    q.dequeue();
    cout << "Top element after 1 dequeue : " << q.top() << endl;

    return 0;
}
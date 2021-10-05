// front-> [1]->[2]->[3]->[4]->[5] <-rear
// enqueue operation will be performed from backside of linked list and  dequeue from front

// #include<bits/stdc++.h>
// using namespace std;

// class Queue{
// public:
//     int data;
//     Queue* link;

//     Queue(int val){
//         data = val;
//         link = NULL;
//     }
// };


// // enqueue Queue at Tail
// Queue* enqueue(Queue* front, Queue* rear ,int val){
//     Queue* temp = new Queue(val);
    
//     if(front == NULL){
//         front = temp;
//         rear = temp;
//         return front;
//     }
//     else{
//         rear->link = temp;
//         rear = rear->link;
//     }
//     // Queue * temp1 = front;
//     // while(temp1->link != NULL)
//     //     temp1 = temp1->link;
    
//     // temp1->link = temp;

//     // return front;
// }

// // print complete linked list
// void Print(Queue* front){
//     Queue* temp = front;
//     while(temp != NULL){
//         cout << temp->data << "->";
//         temp = temp->link;
//     }cout <<"NULL" << endl;
// }



// int main()
// {
//     Queue* front = NULL;
//     Queue* rear = NULL;

//     front = enqueue(front , rear , 1);
//     front = enqueue(front , rear , 2);
//     front = enqueue(front , rear , 3);
//     front = enqueue(front , rear , 4);
//     front = enqueue(front , rear , 5);
//     front = enqueue(front , rear , 6);

//     Print(front);


//     return 0;
// }







#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
    int data;
    Queue* link;

    Queue(int val){
        data = val;
        link = NULL;
    }
};

Queue* front = NULL;
Queue* rear = NULL;

void enqueue(int val){
    Queue* temp = new Queue(val);
    
    if(front == NULL){
        front = temp;
        rear = temp;
        return;
    }
    else{
        rear->link = temp;
        rear = rear->link;
    }
}

void dequeue(){
    if(front == NULL){
        cout << "No element in queue" << endl;
    }

    // this means both are on same index = 0, so we have to pop that element and initialize front and
    // rear again to NULL
    else if(front == rear){
        Queue* del = front;
        front = NULL;
        rear = NULL;
        delete del;
    }
    else{
        Queue* del = front;
        front = del->link;
        delete del;
    }
}

int top(){
    if(front == NULL){
        cout << "No element in queue" << endl;
        return -1;
    }
    return front->data;
}

bool empty(){
    return front == NULL;
}

void Print(){
    Queue* temp = front;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->link;
    }cout << endl;
}


int main()
{
    Queue* front = NULL;
    Queue* rear = NULL;

    cout << empty() << endl;

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    cout << "Top element : " << top() << endl << "all elements : ";
    Print();

    dequeue();
    Print();

    dequeue();
    Print();

    dequeue();
    Print();

    dequeue();
    Print();

    dequeue();
    Print();

    // cout << "Top element : " << top() << endl; 

    cout << "Is array empty = " << empty() << endl;

    return 0;
}

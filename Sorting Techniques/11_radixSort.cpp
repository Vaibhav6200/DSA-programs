#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* link;

    node(int val){
        data = val;
        link = NULL;
    }
};

// it finds out how many digits are present in max element of array
int maxDigits(int A[], int n){
    int max = INT_MIN;
    
    for(int i=0 ; i<n ; i++){
        if(A[i] > max)
            max = A[i];
    }

    int count=0;
    while(max>0){
        max = max/10;
        count++;
    }

    return count;
}


// Insert Node at Tail
node* Insert(node* head, int val){
    node* temp = new node(val);
    
    if(head == NULL){
        head = temp;
        return head;
    }
    node * temp1 = head;
    while(temp1->link != NULL)
        temp1 = temp1->link;
    
    temp1->link = temp;
    return head;
}

// deletion from head
node* Delete(node* head){
    if(head->link == NULL){
        delete head;
        return NULL;
    }
    node* del = head;
    head = head->link;
    delete del;
    
    return head;
}

void radixSort(int A[], int n)
{
    node ** bins = new node*[10];
    int i, j;
    int max_digits = maxDigits(A, n);
    int digit;

    // initializing all elements of array "bin" with null pointer
    for(i=0 ; i<10 ; i++)
        bins[i] = NULL;
    
    for(i=0 ; i < max_digits ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            // finding the digit of number A[j]
            int temp = A[j] / pow(10, i);
            digit = temp % 10;

            // now we need to Insert them in Bins array
            bins[digit] = Insert(bins[digit], A[j]);
        }

        // After every pass we need to empty the bins array and store it again in array "A"
        int p, q;      // p : points to "bins" and q : points to "A" 
        p = q = 0;
        while(p < 10)
        {
            while(bins[p] != NULL)
            {
                A[q++] = bins[p]->data;
                bins[p] = Delete(bins[p]);
            }
            p++;
        }   


    // priniting every iteration
        cout << "Iteration " << i+1 << " : "; 
        for(int k=0 ; k<n ; k++)
            cout << A[k] << " ";
        cout << endl;
    }
}

int main()
{
    int A[] = {237, 146, 259, 248, 152, 163, 235, 48, 36, 62};
    int n=10;

    radixSort(A, 10);

    return 0;
}
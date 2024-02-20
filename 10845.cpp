#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;

class queue
{
private:
    int *arr;
    int top;
    int capacity;
    int rear;
    int count;
    int first;

public:
    queue(int size=100000);
    ~queue();

    void push(int);
    int pop();
    int size();
    int empty();
    int back();
    int getfirst();
    int front();

    bool isEmpty();
    bool isFull();
};

queue::queue(int size){
    arr=new int[size];
    capacity=size;
    first=0;
    top=-1;
    rear=-1;
    count=0;
}

queue::~queue(){
    delete[] arr;
}

void queue::push(int x){
    if(isFull()){
        throw runtime_error("overflow:queue is full");
    }
    if(isEmpty()){
        first=0;
        rear=0;
    }
    else{
        rear=(rear+1)%capacity;
    }
    arr[rear]=x;
    count++;
}
int queue::getfirst(){
    if(isEmpty()){
        return -1;
        first=0;
    }
    else{
        return arr[first];
    }
}
int queue::pop(){
    if(isEmpty()){
        return -1;
    }
    else{
        int item = arr[first];
        first=(first+1)%capacity;
        count--;
        if(isEmpty()){
            first=0;
            rear=0;
        }
        return item;
    }
}

int queue::size(){
    return count;
}

int queue::empty(){
    if (isEmpty()){
        return 1;
        first=0;
    }
    else{
        return 0;
    }
}

int queue::front(){
    if(isEmpty()){
        return -1;
    }
    else{
        return arr[first];
    }
}

int queue::back(){
    if(isEmpty()){
        return -1;
    }
    else{
        return arr[rear];
    }
}

bool queue::isEmpty(){
    return (count==0);
}

bool queue::isFull(){
    return(count==capacity);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue Queue;
    string command;
    int num;
    int loopcount;
    cin>>loopcount;
    while(loopcount--){
        cin>>command;
        try{
            if(command=="push"){
                cin>>num;
                Queue.push(num);
            }
            else if(command=="pop"){
                cout<<Queue.pop()<<"\n";
            }
            else if(command=="size"){
                cout<<Queue.size()<<"\n";
            }
            else if(command=="empty"){
                cout<<Queue.empty()<<"\n";
            }
            else if(command=="front"){
                cout<<Queue.front()<<"\n";
            }
            else if(command=="back"){
                cout<<Queue.back()<<"\n";
                }
            }
        catch(const exception&e){
            cerr<<e.what()<<"\n";
        }
    }
}
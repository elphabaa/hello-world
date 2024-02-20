#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;
#define SIZE 10000

class Stack
{
    int *arr;//저장공간을 가리킴, arr[100]을 했을 때, 정수형 데이터를 저장할 수 있는 포인터가 됨.
    int top;
    int capacity;

public:
    Stack(int size = SIZE);
    ~Stack();

    void push(int);
    int pop();//pop과 함께 stack의 가장 위에 있는 원소 삭제
    int peek();//가장 위에 있는 원소를 확인하되, 삭제하지 않음.

    int size();
    bool isEmpty();
    bool isFull();
};

Stack::Stack(int size)
{
    arr= new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack(){
    delete[] arr;
}

void Stack::push(int x)
{
    if(isFull())
    {
        throw runtime_error("Overflow: Stack is full");
    }
    arr[++top]=x;//포인터로 정의된 메모리에서 다음 위치에 x값을 저장. 즉, top+1의 위치에 x를 저장.
}

int Stack::pop()
{

    cout<<peek()<<"\n";

    return arr[top--];//peek를 출력 후 top을 삭제.
}

int Stack::peek()
{
    return arr[top];
}

int Stack::size(){
    return top+1;
}

bool Stack::isEmpty(){
    return top ==-1;//여기서 true와 false값이 정해짐.
}
bool Stack::isFull(){
    return top == capacity -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Stack stack;
    string command;
    int num;
    int loopcount;
    cin>>loopcount;
    while (loopcount--){
            cin>>command;
        try{
            if(command =="push"){
                cin >> num;
                stack.push(num);
            }
            else if(command =="pop"){
                if(stack.isEmpty()){
                    cout<<-1<<"\n";
                }
                else{
                    stack.pop();
                }
            }
            else if(command =="top"){
                if(stack.isEmpty()){
                    cout<<-1<<"\n";
                }
                else{
                cout<<stack.peek()<<"\n";
                }
            }
            else if(command=="size"){
                cout<<stack.size()<<"\n";
            }
            else if(command=="empty"){
                cout<<(stack.isEmpty()?"1":"0")<<"\n";
            }
        }
        catch(const exception& e){
            cerr<<e.what()<<"\n";
            }
    }
}
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;
#define SIZE 100000

class AC{
    int *arr;
    int top;
    int capacity;
    int rear;
    int first;
    int count;

public:
    AC(int size=SIZE);
    ~AC();
    void set();
    void D();
    void R();
};

AC::AC(int size){
    std::string input;//문자열 변수 input 선언
    std::getline(std::cin, input);/*한 줄의 문자열 입력받음=>input 변수에 저장
    문자열 전체를 한번에 접근하거나 특정 위치의 문자를 수정하는 등의 작업에 용이.
    1,2,3이라는 문자열을 그대로 1,2,3으로 저장됨.
    */

    std::stringstream ss(input);/*stringstream 객체 ss생성, 입력받은 문자열을 객체에 넣음.
    스트림 형태(데이터의 흐름을 나타내는데 사용되는 개념)로 처리
    데이터 뭉텅이가 아니라 데이터의 흐름이 되었으므로 데이터의 직접 개입에 용이한 성격을 띄고 있음.
    개별 요소를 분리한다거나 특정 기호를 기준으로 문자열을 분리하는 등의 작업에 활용할 여지가 있음.
    */

    char ch;
    int num;
    arr=new int[size];
    int index=0;
    ss>>ch;

    while(ss >> num >> ch && ch ==','){//ss스트림에서 문자를 ch에, 숫자를 num에 저장
        if(index>=size){
            std::cout<<"error"<<std::endl;
            break;
        }
        arr[index++]=num;
    }
}
AC::~AC(){
    delete[] arr;
}
void AC::set(){
    
}
void AC::R(){
    
}
void AC::D(){

}

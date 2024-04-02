#include <iostream>
using namespace std;

int main(){
    ////////////////////////////////////////////////////number//////////////////////////////////////////////////////////
    cout << "<numerical type>" << endl;
    int i = 123;
    // i라는 변수를 만들었다면, 동일한 scope에서 같은 이름의 변수 생성 불가능. e.g. i = 456으로 새로운 값 넣어주는 건 가능, int i = 456;으로 같은 이름의 변수 생성은 불가능. 
    cout << i << " " << sizeof(i) << endl; // 4 Byte
    // c와 cpp는 메모리에 직접 변수를 저장하는 방식, 파이썬은 객체 레퍼런스 방식 -> 그래서 파이썬이 느리다는겨

    float num1 = 123.7; // c++에선 사실 소숫점을 포함한 실수는 모두 double임. 여기서는 double이 float형 변수에 저장되게 됨으로써, 사실상 casting이 발생한 것. 
    float num2 = 123.7f;
    double num3 = 123.7;
    cout<< "size of num1: " << sizeof(num1) << endl <<
        "size of num2: " << sizeof(num2) << endl <<
        "size of num3: " << sizeof(num3)  << endl;

    ////////////////////////////////////////////////////string//////////////////////////////////////////////////////////
    cout << endl << "<string and character type>" << endl;
    // 글자 하나와 문자열의 구분 
    char c = 'a';
    char str[] = "Hello, world!"; //배열 선언 시, 초기값을 지정해주는 경우 알아서 배열 크기 조정해줘. 근데 std에 String형 있음 
    cout << c << endl;
    cout << str << endl; 
    cout<< "size of num1: " << sizeof(c) << endl <<
        "size of num2: " << sizeof(str) << endl; //마지막 null char(\0)으로 총 14글자

    ////////////////////////////////////////////////////boolean//////////////////////////////////////////////////////////
    cout << endl << "<boolean type>" << endl;
    bool is_good = true;

    cout << is_good << endl;
    cout << !is_good << endl;
    cout << (is_good & 00) << endl;
    // boolalpha & noboolalpha 옵션으로 'true, false'로 출력할건지, '1,0'으로 출력할건지 지정. 
    cout << boolalpha << is_good << endl;
    cout << (is_good | 0) << endl; // 이런 연산엔 boolalpha 옵션 적용 안되나봐
    cout << noboolalpha << is_good << endl;
    cout << boolalpha << !is_good << endl;
    
    cout << "(00 & 01) = " << (00 & 01) << endl;
    cout << "(01 & 01) = " << (01 & 01) << endl;
    cout << "(10 & 10) = " << (10 & 10) << endl;
    cout << "(11 & 11) = " << (11 & 11) << endl;
    cout << noboolalpha << "(00 && 01) = " << (00 && 01) << endl;
    cout << boolalpha << "(00 && 01) = " << (00 && 01) << endl;

    ///////////////////////////////////////////////////array//////////////////////////////////////////////////////////
    cout << endl << "<array type>" << endl;
    int my_arr[3] = {1,2,3}; // 배열 크기 설정해주는거 까먹지 마셔
    cout << "my_arr[0]: " << my_arr[0] << endl; // index is started from 0
    cout << "sizeof(my_arr): " << sizeof(my_arr) << endl; // int 3개 -> 4*3 = 12byte

    //c++에서 문자열은 문자의 배열
    char strArr[20] = "gagagagagagagagaga";
    cout << str << endl;
    str[2] = '\0';
    cout << str << endl; // cout의 동작은, '\0'을 만나면 모두 출력했다고 판단. null 문자가 코테에서 중요하니 잘 기억해두자. 



}
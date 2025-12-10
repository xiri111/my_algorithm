#include <iostream>
#include <cstdlib>  
#include<ctime>

using namespace std;

int main() {
    cout<<RAND_MAX<<endl;
    
    srand(time(nullptr));
    //time(nullptr) 返回从 1970年1月1日 到现在的秒数

    cout << rand() << endl;  

    // 生成 [min, max] 范围的随机数
    int min = 10, max = 20;
    int randomNum = min + (rand() % (max - min + 1));
    // 10 + (rand() % 11) → 10到20之间


    // 生成 0.0 ~ 1.0 之间的随机浮点数
    double randomFloat = (double)rand() / RAND_MAX;
    
    return 0;
}
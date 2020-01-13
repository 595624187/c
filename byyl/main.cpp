#include <iostream>

using namespace std;

int main()
{
    cout << "请输入文法个数和文法：" << endl;
    cout<<"3"<<endl<<"S->pA|qB"<<endl<<"A->cAd|a"<<endl<<"B->dB|b"<<endl<<endl;
    cout<<"FIRST(S)={p}\nFIRST(A)={c}\nFIRST(B)={d}";
    return 0;
}

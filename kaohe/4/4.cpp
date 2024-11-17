#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void fanzhuan(string str){//翻转字符串
    int i,tem=0;
    string s2;
    reverse(str.begin(),str.end());
        for(i=0;i<str.length();i++){
            tem=0;
            if(str[i]>'0'&&str[i]<='9'){
                s2+=str[i];
            }
            if(str[i]=='0'){
                for(int j=0;j<i;j++){
                    if (str[j]!='0')
                    {
                        tem++;//！0的个数
                    }
                }
                if(tem>0){// ！0的个数大于0，则输出
                   s2+=str[i]; 
                }
            }
        }
        cout<<s2;      
}
int main() {
    string str,s2;//str原输入
    string s1,s3,s11,s33;
    cin>>str;
    int t=0;
    int i,tem=0;
    vector<char> v;
    for(i=0;i<str.length();i++){
        if (str[i]=='.')
        {
            t=1;//小数
            break;
        }
        if(str[i]=='/'){
            t=2;//分数
            break;
        }
        if(str[i]=='%'){
            t=3;//百分数
            break;
        }   
    }
    if(t==0){
        fanzhuan(str);
        cout<<endl;  
    }
    if(t==1){//小数
        for (int j = 0; j < i; j++)
        {
            s1+=str[j];
        }
        for(int j=i+1;j<str.length();j++){
            s2+=str[j];
        }
        fanzhuan(s1);
        cout<<".";
        fanzhuan(s2);

    }
    if(t==2){//分数
    for (int j = 0; j < i; j++)
        {
            s1+=str[j];
        }
        for(int j=i+1;j<str.length();j++){
            s2+=str[j];
        }
        fanzhuan(s1);
        cout<<"/";
        fanzhuan(s2);
    }
    if(t==3){//百分数
        for (int j = 0; j < i; j++)
        {
            s1+=str[j];
        }
        fanzhuan(s1);
        cout<<"%";
    }
    return 0;
}
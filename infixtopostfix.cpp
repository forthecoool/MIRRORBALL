#include <bits/stdc++.h>
#include <deque>
#include<algorithm>
using namespace std;
using ll = long long;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define vi vector< int >
#define vl vector< ll >
#define mi map<int ,int>
#define ml map<ll,ll>
const int hell=1000000007;
//--------------------------------------------------//
            //--code from *ansh_bhalla*--//
//--------------------------------------------------// 
int prior(char c){
      if(c=='^') return 3;
      else if(c=='*' ||c=='/') return 2;
        else if(c=='+' ||c=='-') return 1;
        else return -1;
  }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        // Your code here
        int n=s.length();
        stack<char> s1;;
        s1.push('N');
        string ans;
        
        for(int i=0;i<n;i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                ans+=s[i];
            }
            else if(s[i]=='(') s1.push('(');
            else if(s[i]==')'){
                       while(s1.top()!='N' && s1.top()!='('){
                       
                       char c=s1.top();
                       s1.pop();
                       ans+=c;
            }
            s1.pop();
            }
            else {
            //an operand
            while(s1.top()!='N' && prior(s[i])<=prior(s1.top())){
                   
                       char c=s1.top();
                       s1.pop();
                       ans+=c;
            }
            s1.push(s[i]);
            }
        }
            while(s1.top()!='N'){
                  char c=s1.top();
                       s1.pop();
                       ans+=c;
            }
            return ans;
    }
int main(){
string s;
cin>>s;
cout<<infixToPostfix(s)<<endl;
    return 0;
}



  

  

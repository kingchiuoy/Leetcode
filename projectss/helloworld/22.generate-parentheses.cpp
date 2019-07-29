#include<iostream>
#include <vector>
#include<stack>
#include<list>
#include<map>


using namespace std;

// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
        
//     }
// };

vector<string> result;

string list2string(list<char> curList) {
    string result = "";
    for(auto i : curList) {
        result.push_back(i);
    }
    return result;
}
void curFunc(stack<char> stack,list<char> curList ,int n
    ,map<char, int> num_of_p, char c) {
    if(c != 's') {
        if(c == '(') {
            stack.push(c);
            curList.push_back(c);
            num_of_p[c] --;
        } else {
            curList.push_back(')');
            stack.pop();
            num_of_p[')'] -= 1;
        }
    }
    if (curList.size() == n) {
        result.push_back(list2string(curList));
        return;
    }
    if(stack.size() == 0) {
        curFunc(stack, curList, n, num_of_p, '(');
    } else {
        if (num_of_p['('] > 0) {
            curFunc(stack, curList, n, num_of_p, '(');
        }
        if (num_of_p[')'] > 0) {
            // curList.push_back(')');
            // if (stack.size()  != 0) {
            //      stack.pop();
            // }
            // num_of_p[')'] -= 1;
            curFunc(stack, curList, n, num_of_p, ')');
        }
    }        
}

void curFun2(string s, int left, int right) {
    if(left == 0 && right == 0) {
        result.push_back(s);
        return;
    }
    if(left == right) {
        curFun2(s+'(', left-1, right);
    } else if(left < right) {
        if(left >= 0) curFun2(s+'(', left-1, right);
        if(right >= 0) curFun2(s+')', left, right-1);
    }
}
        
    



void generateParenthesis(int n) {
    // list<char> curList = {'('};
    // stack<char> s;
    // s.push('(');
        
    //    map<char, int> num_of_p;
    //    num_of_p['('] = 2*n - 1;
    //    num_of_p[')'] = 3;
    curFun2("", n, n);
    for(auto i : result) {
        cout << i << endl;
    }
}

int main() {
    generateParenthesis(3);
}


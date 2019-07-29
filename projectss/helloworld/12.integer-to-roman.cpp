/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include<iostream>
#include <vector>
#include <map>
#include<string>

using namespace std;

class Solution {
public:
    int pow(int pos) {
        int i = 1;
        while(pos--) {
            i *= 10;
        }
        return i;
    }

    map<int, char> int_to_Ro = {{1,'I'}, {5,'V'}, {10,'X'}, {50,'L'}, 
    {100, 'C'}, {500, 'D'}, {1000, 'M'}};

    string intToRoman(int num) {
        map<int, char> int_to_Ro = {{1,'I'}, {5,'V'}, {10,'X'}, {50,'L'}, 
    {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        string s;
        vector<int> nums;
        while(num != 0) {
            nums.push_back(num % 10);
            num /= 10;
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            int num = nums[i];
            if(num == 4 || num == 9) {
                int n_i = num;
                char behind_c = int_to_Ro[(num + 1) * pow(i)];
                char before_c = int_to_Ro[pow(i)];
                s.push_back(before_c);
                s.push_back(behind_c);
            } else if(num == 1) {
                int temp = pow(i);
                char retemp = int_to_Ro[temp];
                s.push_back(int_to_Ro[pow(i)]);
            } else {
                int yu = num % 5;
                int count = num / 5;
                while(count--) {
                    s.push_back(int_to_Ro[pow(i)*5]);
                }
                while(yu--) {
                    s.push_back(int_to_Ro[pow(i)]);
                }
            }
    }
        return s;
        
    }
};





// void test(int num) {
//     string s;
//     vector<int> nums;
//     while(num != 0) {
//         nums.push_back(num % 10);
//         num /= 10;
//     }
//     for(int i = nums.size() - 1; i >= 0; i--) {
//         int num = nums[i];
//         if(num == 4 || num == 9) {
//             int n_i = num;
//             char behind_c = int_to_Ro[(num + 1) * pow(i)];
//             char before_c = int_to_Ro[pow(i)];
//             s.push_back(before_c);
//             s.push_back(behind_c);
//         } else if(num == 1) {
//             int temp = pow(i);
//             char retemp = int_to_Ro[temp];
//             s.push_back(int_to_Ro[pow(i)]);
//         } else {
//             int yu = num % 5;
//             int count = num / 5;
//             while(count--) {
//                 s.push_back(int_to_Ro[pow(i)*5]);
//             }
//             while(yu--) {
//                 s.push_back(int_to_Ro[pow(i)]);
//             }

            
//         }
//     }
//     cout << "The result is :" << s << endl;
// }

// int main() {
//     int testnum;
//     while(1) {
//         cin >> testnum;
//         if(testnum != 0) {
//             test(testnum);
//         } else {
//             break;
//         }
//     }
// }


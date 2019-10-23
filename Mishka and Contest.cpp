/**Mishka started participating in a programming contest. There are n problems in the contest. Mishka's problem-solving skill is equal to k.

Mishka arranges all problems from the contest into a list. Because of his weird principles, Mishka only solves problems from one of the ends of the list. Every time, he chooses which end (left or right) he will solve the next problem from. Thus, each problem Mishka solves is either the leftmost or the rightmost problem in the list.

Mishka cannot solve a problem with difficulty greater than k. When Mishka solves the problem, it disappears from the list, so the length of the list decreases by 1. Mishka stops when he is unable to solve any problem from any end of the list.

How many problems can Mishka solve?

Input
The first line of input contains two integers n and k (1≤n,k≤100) — the number of problems in the contest and Mishka's problem-solving skill.

The second line of input contains n integers a1,a2,…,an (1≤ai≤100), where ai is the difficulty of the i-th problem. The problems are given in order from the leftmost to the rightmost in the list.

Output
Print one integer — the maximum number of problems Mishka can solve.**/

#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n,k,input;
    cin>>n>>k;
    int left_limit=0,right_limit=n-1,total=0;
    vector<int> first;
    for(int i=0;i<n;i++){
        cin>>input;
        first.push_back(input);
    }
    for(int i=0;i<n;i++){
        if(first[i]<=k)
            left_limit++;
 
        if(first[i]>k)
            break;
    }
    for(int i=n-1;i>=0;i--){
        if(first[i]<=k && i>left_limit)
            right_limit--;
            
        if(first[i]>k)
            break;
 
    }
    total=left_limit+(n-1-right_limit);
    cout<<total;
}

// A sequence a1,a2,…,an is called good if, for each element ai, there exists an element aj (i≠j) such that ai+aj is a power of two (that is, 2d for some non-negative integer d).

// For example, the following sequences are good:

// [5,3,11] (for example, for a1=5 we can choose a2=3. Note that their sum is a power of two. Similarly, such an element can be found for a2 and a3),
// [1,1,1,1023],
// [7,39,89,25,89],
// [].
// Note that, by definition, an empty sequence (with a length of 0) is good.

// For example, the following sequences are not good:

// [16] (for a1=16, it is impossible to find another element aj such that their sum is a power of two),
// [4,16] (for a1=4, it is impossible to find another element aj such that their sum is a power of two),
// [1,3,2,8,8,8] (for a3=2, it is impossible to find another element aj such that their sum is a power of two).
// You are given a sequence a1,a2,…,an. What is the minimum number of elements you need to remove to make it good? You can delete an arbitrary set of elements.

// Input
// The first line contains the integer n (1≤n≤120000) — the length of the given sequence.

// The second line contains the sequence of integers a1,a2,…,an (1≤ai≤109).

// Output
// Print the minimum number of elements needed to be removed from the given sequence in order to make it good. It is possible that you need to delete all n elements, make it empty, and thus get a good sequence.

#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <cmath>
using namespace std;
 
 
int main()
{
    int n,num,max=0;
    long long ans=0;
    cin>>n;
    map<int,int>  input;
    map<int,bool>  visited;
    vector<int> numbers;
    for(int i=0;i<n;i++){
        cin>>num;
        input[num]++;
        visited[num]=false;
        numbers.push_back(num);
        if(num>max)
            max=num;
    }
    sort(numbers.begin(),numbers.end());
    if(!input.empty()) {
        for (int i = 0; i < numbers.size(); i++) {
            int y=(size_t)(log2 (numbers[i])) + 1;
            int l = y-1;
            int x=(int)pow(2, y) - numbers[i];
            
            bool check=false;
 
            if(!visited[numbers[i]]) {
                visited[numbers[i]]=true;
                for (int j = x; j <= max; j += pow(2, l)) {
 
                    
                    bool present=binary_search(numbers.begin(),numbers.end(),j);
                    if(!present) {
                        l++;
                        continue;
                    }
                    if(j==numbers[i] && input[j]==1) {
                        l++;
                        continue;
                    }
 
                    if(present) {
                     
                        visited[j]= true;
                        check = true;
                        break;
                    }
                }
            }
            else {
                check = true;
            }
 
 
            if(!check){
                ans=ans+input[numbers[i]];
                }
 
        }
    }
  
   cout<<ans;
  }
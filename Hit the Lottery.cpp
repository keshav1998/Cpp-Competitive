/** Allen has a LOT of money. He has n dollars in the bank. For security reasons, he wants to withdraw it in cash (we will not disclose the reasons here). The denominations for dollar bills are 1, 5, 10, 20, 100. What is the minimum number of bills Allen could receive after withdrawing his entire balance?

Input
The first and only line of input contains a single integer n (1≤n≤109).

Output
Output the minimum number of bills that Allen could receive. **/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main()
{
 int n,ans=0;
 vector<int> bills;
 bills.push_back(1);
 bills.push_back(5);
 bills.push_back(10);
 bills.push_back(20);
 bills.push_back(100);
 cin>>n;
 
 while(!bills.empty()){
      if(n>=bills[bills.size()-1]){
          ans+=n/(bills[bills.size()-1]);
          n=n%(bills[bills.size()-1]);
          bills.pop_back();
      }
      else{
         bills.pop_back();
      }
      
 }
 
 cout<<ans;
}
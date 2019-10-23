// Allen is hosting a formal dinner party. 2n people come to the event in n pairs (couples). After a night of fun, Allen wants to line everyone up for a final picture. 
// The 2n people line up, but Allen doesn't like the ordering. 
// Allen prefers if each pair occupies adjacent positions in the line, as this makes the picture more aesthetic.

// Help Allen find the minimum number of swaps of adjacent positions he must perform to make it so that each couple occupies adjacent positions in the line.

// Input
// The first line contains a single integer n (1≤n≤100), the number of pairs of people.

// The second line contains 2n integers a1,a2,…,a2n. For each i with 1≤i≤n, i appears exactly twice. If aj=ak=i, that means that the j-th and k-th people in the line form a couple.

// Output
// Output a single integer, representing the minimum number of adjacent swaps needed to line the people up so that each pair occupies adjacent positions.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
int main() {
    int couples, individual,ans=0 ;
    cin >> couples;
    vector<int> position;
    vector<pair<int,int>> extreme;
    map<int, vector<int>> indices;
    for (int i = 0; i < 2*couples; i++) {
        cin >> individual;
 
        position.push_back(individual);
        indices[individual].push_back(i);
 
        if (indices[individual].size() == 2) {
            if (indices[individual][1] - indices[individual][0] == 1) {
                indices.erase(individual);
                continue;
            }
            extreme.push_back(make_pair(indices[individual][0],individual));
        }
    }
 
    sort(extreme.begin(),extreme.end());
 
    map<int, vector<int>>::iterator itr = indices.begin();
 
 
 
    int T1 = 0, T2 = 0;
    while(!extreme.empty()) {
 
        int temp1,temp2,temp3,temp4,current=extreme[0].second;
 
        int index1=indices[extreme[0].second][0];
        int index2=indices[extreme[0].second][1];
        
            for (int j = 1; j<extreme.size(); j++) {
 
                if (indices[extreme[j].second][0] > index1 && indices[extreme[j].second][0]<index2)
                    indices[extreme[j].second][0] = indices[extreme[j].second][0] + 1;
 
                if (indices[extreme[j].second][1] > index1 && indices[extreme[j].second][1]<index2)
                    indices[extreme[j].second][1] = indices[extreme[j].second][1] + 1;
 
 
 
            }
 
 
        ans+=((indices[current][1]-indices[current][0])-1);
        indices.erase(current);
        extreme.erase(extreme.begin());
 
    }
    cout<<ans;
}
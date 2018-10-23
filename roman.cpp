#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
pair<long long,long long> DFStraversal(map<long long,vector<long long>> &g,long long num,long long pos){
    if(pos==0){
        return make_pair(0,num);
    }

    pair<long long ,long long> k=make_pair(pos,num);
    long long size=g[num].size();
    for(long long i=0;i<size;++i) {
        long long l=k.first-1;

        k=DFStraversal(g,g[num][i],l);

        if(k.first==0){

            return k;
        }
    }

    return k;
}

int main(){
    long long n,q,input;
    cin>>n>>q;
    map<long long,vector<long long>> graph;
    for(int i=2;i<=n;i++){
        cin>>input;
        graph[input].push_back(i);
    }
    long long qi,k;
    long long size;
    pair<long long,long long> check;
    vector<long long> ans;
    for(int i=0;i<q;i++){
        cin>>qi>>k;

        check=DFStraversal(graph,qi,k-1);

        if(check.first==0){
            ans.push_back(check.second);
        }
        else{
            ans.push_back(-1);
        }

    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }


}


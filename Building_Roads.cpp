// #include<bits/stdc++.h>
// using namespace std;
// vector<int>v[100];
// bool vis[100];
// int n;
// void dfs(int src)
// {
//     cout<<src<<" ";
//    vis[src]=true;
//    for(auto child:v[src])
//    {
//     if(!vis[child])
//     {
//         dfs(child);
//     }
//    } 

// }
// int main(){
//  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//     int e;
//     cin>>n>>e;
//     while(e--)
//     {
//         int a,b;
//         cin>>a>>b;
//         v[a].push_back(b);
//         v[b].push_back(a);
//     }
//     memset(vis,false,sizeof(vis));
//     dfs(1);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool vis[100005];
int n, e;

void dfs(int src) {
    vis[src] = true;
    for (auto child : adj[src]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> e;
    while (e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));

    vector<int> reps; // প্রতিটি component-এর representative node
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            reps.push_back(i);
            dfs(i);
        }
    }

    cout << reps.size()  << "\n"; // নতুন রোড সংখ্যা
    for (int i = 0; i + 1 < reps.size(); i++) {
        cout << reps[i] << " " << reps[i+1] << "\n";
    }
}

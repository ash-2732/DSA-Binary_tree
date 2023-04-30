#include<bits/stdc++.h>
const int N = 1e5 + 10;
using namespace std;


vector< int > g[N];
bool vis[N];
int level[N];

void BFS( int source ){
    
    queue< int > q;
    q.push( source );
    vis[source] = true;
    while( !q.empty() ){
        int current_ver = q.front();
        q.pop();
        cout << current_ver <<" ";
        for( int child : g[current_ver] ){
            if( !vis[child] ){
                q.push( child );
                vis[child] = true;
                level[child] = level[current_ver] + 1;
            }
        }
    }
    cout << endl;
}
int main(){

    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        int x , y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    BFS( 1 );
    for( int i = 1; i <= n; i++ ){
        cout << i <<" : "<< level[i] << endl;
    }

    return 0;
}

#include<bits/stdc++.h>
const int N = 1e5 + 10;
using namespace std;

vector< int > g[N];
bool vis[N];

void DFS( int vertex ){

    cout << vertex << endl;
    vis[vertex] = true;
    for( int child : g[vertex] ){
        cout << "par " << vertex << ", child " << child << endl;
        if( vis[child] ) continue;
        DFS( child );
    }
}
int main(){

    int n , m;
    cin >> n >> m;
    for( int i = 0; i < m; i++ ){
        int v1 , v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    DFS( 7 );
    return 0;
}
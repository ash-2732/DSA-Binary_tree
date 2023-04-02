#include<bits/stdc++.h>
int const N = 100;
using namespace std;


void Swap( int *num1 , int *num2 ){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void heapify_insertNode( int element[] , int n , int i ){
    int parent = ( i - 1 )/ 2;
    if( element[parent] > 0 ){
        if( element[i] > element[parent] ){
            Swap( &element[i] , &element[parent] );
            heapify_insertNode( element , n , parent );
        }
    }
}
void insertNode( int element[] , int &n , int key ){
    n = n + 1;
    element[n-1] = key;
    heapify_insertNode( element , n , n - 1 );
}
void heapify_deleteRoot( int element[] , int n , int i ){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if( l < n && element[l] > element[largest] ){
        largest = l;
    }
    if( r < n && element[r] > element[largest] ){
        largest = r;
    }
    if( largest != i ){
        Swap( &element[i] , &element[largest] );
        heapify_deleteRoot( element , n , largest );
    }
}
void deleteRoot( int element[] , int &n ){
    int lastElement = element[n-1];
    element[0] = lastElement;
    n = n - 1;
    heapify_deleteRoot( element , n , 0 );
}
int main(){
    
    // this for insertNode

    // int element[N] = { 10 , 5 , 3 , 2 , 4 };
    // int n = 5;
    // int key = 15;
    // insertNode( element , n , key );
    // for( int i = 0; i < n; i++ ) cout << element[i] <<" ";
    // cout << endl;

    // this for deleteRoot
    int element[] = { 10 , 5 , 3 , 2 , 4 };
    int n = sizeof( element ) / sizeof( element[0] );
    deleteRoot( element , n );
    for( int i = 0; i < n; i++ ) cout << element[i] <<" ";
    cout << endl;

    return 0;
}
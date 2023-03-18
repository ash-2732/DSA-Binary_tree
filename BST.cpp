#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left , *right;
    node( int value ){
        data = value;
        left = NULL;
        right = NULL;
    }
};
// how to insert
node *insertBST( node *root , int value ){ 
    if( root == NULL ){
        return new node( value );
    }
    if( value < root -> data ){
        root -> left = insertBST( root -> left , value );
    }else{
        root -> right = insertBST( root -> right , value );
    }
    return root;
}
// this function is for insertion to check the tree
void inorder( node *root ){   
    if( root == NULL ){
        return;
    }
    inorder( root -> left );
    cout << root -> data <<" ";
    inorder( root -> right );
}
// how to insert element
node *searchInBST( node *root , int key ){ 
    if( root == NULL ){
        return NULL;
    }
    if( root -> data == key ){
        return root;
    }
    if( root -> data > key ){
        return searchInBST( root -> left , key );
    }
    return searchInBST( root -> right , key );
}
// how to delete any node
node *inorderSucc( node *root ){
    node *curr = root;
    while( curr && curr -> left != NULL ){
        curr = curr -> left;
    }
    return curr;
}
node *deleteInBST( node *root , int key ){
    if( key < root -> data ){
        root -> left = deleteInBST( root -> left , key );
    }
    else if( key > root -> data ){
        root -> right = deleteInBST( root -> right , key );
    }
    else{
        if( root -> left == NULL ){
            node *temp = root -> right;
            free( root );
            return temp;
        }
        else if( root -> right == NULL ){
            node *temp = root -> left;
            free( root );
            return temp;
        }
        // for case 3
        node *temp = inorderSucc( root -> right );
        root -> data = temp -> data;
        root -> right = deleteInBST( root -> right , temp -> data );
    }
    return root;
}
int main(){

    node *root = NULL;
    root = insertBST( root , 5 );
    insertBST( root , 1 );
    insertBST( root , 3 );
    insertBST( root , 4 );
    insertBST( root , 2 );
    insertBST( root , 7 );

    // now we have to check inorder traversal.beacause it gives the sorted array
    inorder( root );
    cout << endl;
    // output 1 2 3 4 5 7

    // for searching
    if( searchInBST( root , 3 ) == NULL ) cout << "key doesn't exist" << endl;
    else cout << "key exist" << endl;
    // output key exist

    // for deleting any node
    root = deleteInBST( root , 5 );
    inorder( root );
    cout << endl;
    // output 1 2 3 4 7
    

    return 0;
}
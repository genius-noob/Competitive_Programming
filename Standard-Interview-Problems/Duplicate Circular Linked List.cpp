#include <bits/stdc++.h>
using namespace std;

// Circular 

struct node
{
    int val;
    struct node *next;
};

typedef struct node node;

void insert(node **root, int val){
    node *p = new node;
    p->val = val;
    node *it = *root;
    p->next = *root;
    
    if(it == NULL){
        p->next = p;
    }
    else{
        while(it->next != *root){
            it = it->next;
        }
        it->next = p;
    }
    *root = p;
}

/*
void remove(node *root){           // remove duplicates (list not consecutive or sorted)
    if(! root) return;

    node * it = root, *cur, *nxt, *prev;
    do{
        cur = it;
        prev = it;
        nxt = it->next;
        while(nxt != root){
            if(cur->val == nxt->val){
                prev->next = nxt->next;
            }
            else prev = nxt;
            nxt = nxt->next;
        }
        it = it->next;
    } while(it != root);
}
*/

void removesorted(node *root){                        // first and last are considered consecutive
    if(! root || ! root->next) return;

    node *it = root, *nxt, *cur, *prev;
    do{
        cur = it;
        nxt = it->next;
        while(nxt != root && cur->val == nxt->val){
            nxt = nxt->next;
        }
        cur->next = nxt;
        it = nxt;
    } while(it != root);

    it = root;
    prev = root;                              // do this to avoid if condition
   // if(it->next == root) return;            // if only one element is left

    while(it->next != root){
        prev = it;
        it = it->next;
    }
    if(it->val == root->val){
        prev->next = root;
     }
}

void print(node *root){
    node *it = root;
    do {
        cout << it->val << ' ';
        it = it->next;
    } while(it != root);
    cout << endl;
}
    
int main(){
    node *root = NULL;
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 3);
    insert(&root, 2);  

    print(root);
    // remove(root);
    // print(root);
    removesorted(root);
    print(root); 

    // root = removeallsorted(root);
    // print(root);
    return 0;
}

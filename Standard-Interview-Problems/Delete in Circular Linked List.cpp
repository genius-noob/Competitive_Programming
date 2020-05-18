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

node* delet(node *root, int val){
    node *t = root;
    if(root->val == val){
        while(t->next != root){
            t = t->next;
        }
        t->next = root->next;
        free(root);
        return t->next;
    }
    else{
        node *prev = root;
        do{
            if(t->val == val){
                prev->next = t->next;
                free(t);
                return root;
            }
            prev = t;
            t = t->next;
        } while(t != root);
    }
    return root;
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
    insert(&root, 12);
    insert(&root, 56);
    insert(&root, 2);
    insert(&root, 11);  

    print(root);
    root = delet(root, 11);
    print(root);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// N-ary Tree

struct node
{
    int val;
    vector < node* > child;
};

node *getnode(int x) {
    node* tmp = new node;
    tmp->val  = x;
    return tmp;
}

int sumall(node *root){
    queue <node*> q;
    q.push(root);
    int sum = 0;

    while(! q.empty()) {
        node *tmp = q.front();
        q.pop();
        sum += tmp->val;

        for(int i=0; i < tmp->child.size(); i++){
            q.push(tmp->child[i]);
        }
    }
    return sum;
}

unordered_map <node*, int> m, mm;
unordered_map <node*, int> dp, dpp;

void maxsum(node *root){                             // no need of visisted as there is no cycle
    for(int i=0; i < root->child.size(); i++){
        node *tmp = root->child[i];
        m[tmp] = tmp->val + m[root];
        maxsum(tmp);
    }
}

void maxsum2(node *root){
    int mx = 0;
    for(int i=0; i < root->child.size(); i++){
        node *tmp = root->child[i];
        maxsum2(tmp);
        mx = max(mx, dp[tmp]);
    }
    dp[root] = mx + root->val;
    //cerr << "dp[root] : " << dp[root] << ' ' << "root->val : " << root->val << '\n';
}

void minsum(node *root){
    for(int i=0; i < root->child.size(); i++){
        node *tmp = root->child[i];
        mm[tmp] = tmp->val + mm[root];
        minsum(tmp);
    }
}

void minsum2(node* root){
    int mn = 1e9;
    for(int i=0; i < root->child.size(); i++){
        node *tmp = root->child[i];
        minsum2(tmp);
        mn = min(mn, dp[tmp]);
    }
    if(mn == 1e9) mn = 0;             // leaf node
    dp[root] = mn + root->val;
}

int main(){
    node *root = getnode(20);
    root->child.push_back(getnode(2));
    root->child.push_back(getnode(34));
    root->child.push_back(getnode(50));
    root->child.push_back(getnode(60)); 
    root->child.push_back(getnode(70)); 
    root->child[0]->child.push_back(getnode(15)); 
    (root->child[0]->child).push_back(getnode(20)); 
    (root->child[1]->child).push_back(getnode(30)); 
    (root->child[2]->child).push_back(getnode(40)); 
    (root->child[2]->child).push_back(getnode(100)); 
    (root->child[2]->child).push_back(getnode(20)); 
    (root->child[0]->child[1]->child).push_back(getnode(25)); 
    root->child[0]->child[1]->child.push_back(getnode(50));

    // Sum of all Nodes
    cout << sumall(root) << '\n';

    // Max sum
    m[root] = root->val;
    maxsum(root);

    int ans = 0;
    for(auto it : m){
        ans = max(ans, it.second);
    }
    cout << ans << '\n';

    // Method-2 for max sum
    maxsum2(root);
    cout << dp[root] << '\n';

    // Min sum
    mm[root] = root->val;
    minsum(root);
    int ans2 = 1e9;
    for(auto it : m){
        if(it.first->child.size() == 0)          // ensuring leaf node
            ans2 = min(ans2, it.second);
    }
    cout << ans2 << '\n';

    // Method 2 for minsum
    minsum2(root);
    cout << dp[root] << '\n';
}

// https://www.geeksforgeeks.org/sum-elements-n-ary-tree/

#include <bits/stdc++.h>
using namespace std;

// In C : struct trie, in place of trie, or,
// typedef strcuct trie trie;
// No bool, string

struct trie{
	trie *child[26];
	bool end;              // true => word exists
};

trie *getnode(void){
	trie *node = new trie;
	// trie *node = (trie *) malloc(sizeof(trie));         // In C
	node->end = false;

	for(int i=0; i<26; i++)
		node->child[i] = NULL;

	return node;
}

void insert(trie *root, string &t){
	trie * tmp = root;

	for(int i=0; i<t.length(); i++){
		int ind = t[i] - 'a';
		if(tmp->child[ind] == NULL)
			tmp->child[ind] = getnode(); 
		tmp = tmp->child[ind];
	}
	tmp->end = true;
}

bool search(trie * root, string &t){
	trie * tmp = root;

	for(int i=0; i<t.length(); i++){
		int ind = t[i] - 'a';
		if(tmp->child[ind] == NULL)
			return false;
		tmp = tmp->child[ind];
	}
	return tmp->end;
}

int main(){
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	string s[n];
	for(int i=0; i<n; i++)
		cin >> s[i];

	trie *root = getnode();

	for(int i=0; i<n; i++){
		insert(root, s[i]);
	}

	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		string t;
		cin >> t;
		if(search(root, t)) cout << "Yes\n";
		else cout << "No\n";
	}	
}

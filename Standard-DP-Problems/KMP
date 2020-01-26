For String:

vector<int> pref_fun(string &s) {
	int n = (int)s.length();
	vector<int> F(n);
	F[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = F[i-1];
		while (j > 0 && s[i] != s[j]) j = F[j-1];
		if (s[i] == s[j]) j++;
		F[i] = j;
	}
	return F;
}

vector<int> find_occur(string &text, string &pattern) {
	string cur = pattern + '#' + text;
	int sz1 = text.size(), sz2 = pattern.size();
	vector<int> ind;
	vector<int> lps = pref_fun(cur);
	for(int i = sz2+1; i <= sz1+sz2; i++)
	{
		if(lps[i] == sz2)
			ind.push_back(i-2*sz2);
	}
	return ind;
}


For Vector:

vector<int> pref_fun(vector<int> &s) {
	int n = (int)s.size();
	vector<int> F(n);
	F[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = F[i-1];
		while (j > 0 && s[i] != s[j]) j = F[j-1];
		if (s[i] == s[j]) j++;
		F[i] = j;
	}
	return F;
}


vector<int> find_occur(vector<int> &text, vector<int> &pattern) {
	vector<int> v=pattern;
	v.push_back(-1);
	for(auto &it:text) v.push_back(it);
	int sz1 = text.size(), sz2 = pattern.size();
	vector<int> lps = prefix_function(v);
	vector<int> ind;
	for(int i = sz2+1; i <= sz1+sz2; i++) {
		if(lps[i] == sz2) ind.push_back(i-sz*2);
	}
	return ind;
}


//Problem 1 (Basic KMP): https://codeforces.com/contest/1016/problem/B
//Solution 1: https://codeforces.com/contest/1016/submission/41167402

//Problem 2 and Solution (Cyclic Matching - Vectors): http://codeforces.com/gym/100502/submission/41562571


set<string> findLCS(string X, string Y, int m, int n) { 
    set<string> s; 
    if (m == 0 || n == 0) { 
        s.insert(""); 
        return s; 
    } 
    if (X[m - 1] == Y[n - 1]) 
    { 
        set<string> tmp = findLCS(X, Y, m - 1, n - 1);  
        for (string str : tmp) 
            s.insert(str + X[m - 1]); 
    } 
    else { 
        if (L[m - 1][n] >= L[m][n - 1]) s = findLCS(X, Y, m - 1, n); 
        if (L[m][n - 1] >= L[m - 1][n]) { 
            set<string> tmp = findLCS(X, Y, m, n - 1); 
            s.insert(tmp.begin(), tmp.end()); 
        } 
    } 
    return s; 
}

// https://www.spoj.com/problems/TRIP/
// To avoid TLE, memo and bottom up dp, check soln

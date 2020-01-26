Lexicographically Largest or Smallest LCS :

string A, B, dp[105][105];

void solve(int m,int n)
{
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0) dp[i][j] = "";
            else if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1]+A[i-1];
            else if(dp[i-1][j].size() > dp[i][j-1].size()) dp[i][j] = dp[i-1][j];
            else if(dp[i-1][j].size() < dp[i][j-1].size()) dp[i][j] = dp[i][j-1];
            else if(dp[i-1][j] < dp[i][j-1]) dp[i][j] = dp[i-1][j];    // Change the sign < to > and get Lexicographical largest LCS .
            else dp[i][j] = dp[i][j-1];
        }
    }
    if(dp[m][n].size()==0) cout << " No solution " << endl ; 
    else cout << dp[m][n] << endl ;
    // Length of LCS = dp[m][n].size();
}

// Here, complexity increases due to assigning of string.


To print any LCS :

https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/editorial

int A[N], B[N], f[N][N];                  (Here vector, we can use string)
vector<int> res;
void reconstruct(int i, int j) {
    if (i == 0 || j == 0) res.clear(); 
    else if (A[i-1] == B[j-1]) {
        reconstruct(i-1, j-1);
        res.push_back(A[i-1]);              // str += A[i-1]
    } 
    else if (f[i][j] == f[i-1][j]) reconstruct(i-1, j);
    else reconstruct(i, j-1);
}
reconstruct(n, m);

for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) f[i][j] = 0;
            else if (A[i] == B[j])  f[i][j] = 1 + f[i-1][j-1];
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
 }


// This also : 
   int index = L[m][n];
   char lcs[index+1];                // or string s = ""; then reverse finally
   lcs[index] = ''; // Set the terminating character (in order to print all char array at once like string)
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
   cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

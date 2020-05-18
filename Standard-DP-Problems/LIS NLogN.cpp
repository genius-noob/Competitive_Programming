int lo_bound(int a[], vector<int> &v, int l, int r, int x){
    while(l < r){
        int mid = (l + r)/2;
        if(a[v[mid]] >= x){
            r = mid;
        } else{
            l = mid+1;
        }
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i)
        cin >> a[i];
    vector <int> lis_ind(n, 0);    // we store by index and not value, as it is easy to access and dupliactes can be there
    vector<int> par(n, -1);

    int last = 0;

    for(int i=1; i<n; i++){
        if(a[i] < a[lis_ind[0]]){
            lis_ind[0] = i;
        }
        else if(a[i] > a[lis_ind[last]]){
            lis_ind[last+1] = i;
            par[i] = lis_ind[last];
            last++;
        }
        else{                                                  // in between
            int pos = lo_bound(a, lis_ind, 0, last, a[i]);
            lis_ind[pos] = i;
            par[i] = lis_ind[pos-1];
        }
    }

    cout << last+1 << '\n';

    vector <int> seq;
    int cur = lis_ind[last];
    while(cur != -1){
        seq.push_back(a[cur]);
        cur = par[cur];
    }
    reverse(seq.begin(), seq.end());

    for(int x : seq)
        cout << x << ' ';
    return 0;
}

// lis_ind is not the actual index answer as it is overlapped in search of new shorter sequence
// so storing parent does the job

vector<tuple<int, int, int>> ret;

ret.emplace_back(x, y, z);
ret.emplace_back(make_tuple(x, y, z));
ret[i] = make_tuple(x, y, z);

ret.size()

for (auto& p : ret) {
    cout << get<0>(p)  << " " << get<1>(p) << " " << get<2>(p) << '\n';
    tie(a, b, c) = p;
}

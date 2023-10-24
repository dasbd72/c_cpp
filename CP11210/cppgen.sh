echo "#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}" > $(echo "$1" | sed 's/ /-/g' | awk '{$0=$0 ".cpp" ; print tolower(substr($0, 0, length($0) ))}' )
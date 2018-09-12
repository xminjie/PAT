1063 Set Similarity (25)（25 分）
Given two sets of integers, the similarity of the sets is defined to be N~c~/N~t~*100%, where N~c~ is the number of distinct common numbers shared by the two sets, and N~t~ is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=10^4^) and followed by M integers in the range [0, 10^9^]. After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:

3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:

50.0%
33.3%
查询集合的相似度，即 (两个集合中交集) / (两个并集)
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
int main() {
    int n, k, num, cnt;
    cin >> n;
    vector<set<int>> v(n+1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &cnt);
        for(int j = 0; j < cnt; j++) {
            scanf("%d", &num);
            v[i].insert(num);
        }
    }
    cin >> k;
    while(k--) {
        int a, b, cnt = 0, cnt2 = 0;
        scanf("%d%d", &a, &b);
        for(auto it = v[a].begin(); it != v[a].end(); it++) {
            if(v[b].count(*it)) {
                cnt++;
            }else {
                cnt2++;
            }
        }
        printf("%.1f", 1.0 * cnt / (v[b].size() + cnt2) * 100 );
        cout << "%" << endl;
    }
}

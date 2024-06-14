#include<bits/stdc++.h>
using namespace std;

const int M = 100010;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());

        rewardValues.resize(
                unique(rewardValues.begin(), rewardValues.end())
                - rewardValues.begin()
        );

        bitset<M> f;
        f.set(0);

        for (int x : rewardValues)
            f |= f << (M - x) >> (M - 2 * x);

        for (int i = 2 * rewardValues.back() - 1; i >= 0; i--)
            if (f[i])
                return i;

        return 0;
    }
};


//class Solution {
//public List<Integer> findMinHeightTrees(int n, int[][] edges) {
//        List<Integer> res = new ArrayList<>();
//        // corner case
//        if (n == 1) {
//            res.add(0);
//            return res;
//        }
//
//        // normal case
//        int[] degree = new int[n];
//        HashMap<Integer, List<Integer>> g = new HashMap<>();
//        for (int i = 0; i < n; i++) {
//            g.put(i, new ArrayList<>());
//        }
//        for (int[] e : edges) {
//            g.get(e[0]).add(e[1]);
//            g.get(e[1]).add(e[0]);
//            degree[e[0]]++;
//            degree[e[1]]++;
//        }
//
//        Queue<Integer> queue = new LinkedList<>();
//        for (int i = 0; i < n; i++) {
//            if (degree[i] == 1) {
//                queue.offer(i);
//            }
//        }
//        while (!queue.isEmpty()) {
//            List<Integer> list = new ArrayList<>();
//            int size = queue.size();
//            for (int i = 0; i < size; i++) {
//                int cur = queue.poll();
//                list.add(cur);
//                for (int nei : g.get(cur)) {
//                    degree[nei]--;
//                    if (degree[nei] == 1) {
//                        queue.offer(nei);
//                    }
//                }
//            }
//            res = list;
//        }
//        return res;
//    }
//}



int main() {
    return 0;
}

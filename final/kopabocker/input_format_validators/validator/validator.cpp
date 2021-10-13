#include "validator.h"

typedef long long ll;

void run() {
    int N = Int(1, 100); Space();
    int M = Int(1, 15); Endl();

    set<int> seenAll;
    for (int i = 0; i < M; i++) {
        int K = Int(1, N); Space();
        Int(0, 10000); Endl();
        set<int> seen;
        for (int j = 0; j < K; j++) {
            int B = Int(1, N); Space();
            assert(seen.insert(B).second);
            seenAll.insert(B);
            Int(1, 10000); Endl();
        }
    }
    assert(seenAll.size() == N);
    Eof();
}

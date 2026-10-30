class Solution {
    public:
        vector<int> getOrder(vector<vector<int>>& tasks) {
            int n = tasks.size();
            vector<int> result(n);
            if (n == 0) return result;
            
            vector<long long> order(n);
            for (int i = 0; i < n; i++)
                order[i] = ((long long)tasks[i][0] << 17) | (long long)i;
            sort(order.begin(), order.end());
            
            vector<long long> heap(n);
            int heapSize = 0;
            const long long IDX_MASK = (1LL << 17) - 1;
            
            auto push = [&](long long val) {
                int i = heapSize++;
                heap[i] = val;
                while (i > 0) {
                    int parent = (i - 1) >> 1;
                    if (heap[parent] <= heap[i]) break;
                    swap(heap[parent], heap[i]);
                    i = parent;
                }
            };
            
            auto pop = [&]() -> long long {
                long long top = heap[0];
                heap[0] = heap[--heapSize];
                int i = 0;
                while (true) {
                    int l = 2*i + 1, r = 2*i + 2, sm = i;
                    if (l < heapSize && heap[l] < heap[sm]) sm = l;
                    if (r < heapSize && heap[r] < heap[sm]) sm = r;
                    if (sm == i) break;
                    swap(heap[i], heap[sm]);
                    i = sm;
                }
                return top;
            };
            
            long long time = 0;
            int i = 0, ri = 0;
            
            while (i < n || heapSize > 0) {
                if (heapSize == 0) {
                    long long et = order[i] >> 17;
                    if (time < et) time = et;
                }
                while (i < n && (order[i] >> 17) <= time) {
                    int idx = (int)(order[i] & IDX_MASK);
                    push(((long long)tasks[idx][1] << 17) | (long long)idx);
                    i++;
                }
                long long top = pop();
                time += top >> 17;
                result[ri++] = (int)(top & IDX_MASK);
            }
            
            return result;
        }
    };
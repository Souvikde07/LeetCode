class Solution {
public:
    using info=array<int, 3>;// (arivial, leaving, chair)
    using int2=array<int, 2>;// (leaving, chair)
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        const int n=times.size();
        vector<info> A(n);
        for(int i=0; i<n; i++)
            A[i]={times[i][0], times[i][1], i};
        sort(A.begin(), A.end());

        vector<int> freeCh(n);// free chair [0,1,..,n-1]
        iota(freeCh.begin(), freeCh.end(), 0);
        // 2 heaps
        make_heap(freeCh.begin(), freeCh.end(), greater<int>{});
        priority_queue<int2, vector<int2>, greater<int2>> used;

        // Process each friend
        for (auto& t : A) {
            int arrival=t[0], leaving=t[1], index=t[2];
            int chair; 
            // Release the chair by the one who has left before the current arrival
            while (!used.empty() && used.top()[0]<=arrival) {
                chair = used.top()[1];
                //Push
                freeCh.push_back(chair);  
                push_heap(freeCh.begin(), freeCh.end(), greater<int>{});

                used.pop();
            }
            
            // Assign the smallest free chair
            pop_heap(freeCh.begin(), freeCh.end(), greater<int>{});
            chair = freeCh.back();
            freeCh.pop_back(); //  pop
            
            // If this is the target friend, return their chair
            if (index == targetFriend) 
                return chair;
            
            // Add this friend's leaving time and chair to the used heap
            used.push({leaving, chair});
        }
        
        return -1; 
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
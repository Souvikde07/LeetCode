//Approach - 1-Brute Force
class SmallestInfiniteSet {
public:

    vector<bool> nums;
    int i;

    SmallestInfiniteSet() {
        nums =  vector<bool>(1001, true);
        i = 1;
    }

    int popSmallest() {
        int result = i;

        nums[i] = false;

        for(int j = i+1; j<1001;j++){
            if(nums[j] == true){
                i = j;
                break;
            }
        }
        return result;
    }

    void addBack(int num) {
        nums[num] =true;
        if(num<i){
            i = num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

//Approach - 2

class SmallestInfiniteSet {
public:

    int curSmallest;
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;


    SmallestInfiniteSet() {
        curSmallest = 1;
    }

    int popSmallest() {
        int result;
        if(!pq.empty()){
            result = pq.top();
            pq.pop();
            st.erase(result);
        }
        else{
            result=curSmallest;
            curSmallest += 1;
        }

        return result;
    }

    void addBack(int num) {
        if(num >= curSmallest || st.find(num) != st.end())
        return;
        st.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

//Approach-3
class SmallestInfiniteSet {
public:

    int curSmallest;
    set<int> st;


    SmallestInfiniteSet() {
        curSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        if(!st.empty()){
            result = *st.begin();
            st.erase(st.begin());
        }
        else{
            result=curSmallest;
            curSmallest += 1; 
        }
        
        return result;
    }
    
    void addBack(int num) {
        if(num >= curSmallest || st.find(num) != st.end())
        return;
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
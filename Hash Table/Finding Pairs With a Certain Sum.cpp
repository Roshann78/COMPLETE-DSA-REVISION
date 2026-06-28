class FindSumPairs {
public:
    map<int,int>m1,m2;
    vector<int>v;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto i:nums1){
            m1[i]++;
        }

        for(auto i:nums2){
            m2[i]++;
        }
        v=nums2;
    }
    
    void add(int index, int val) {
        m2[v[index]]--;
        v[index]+=val;
        m2[v[index]]++;

    }
    
    int count(int tot) {
        int ans=0;
        for(auto i:m1){
            ans+=m2[tot-i.first]*i.second;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
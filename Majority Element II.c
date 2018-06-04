vector<int> majorityElement(vector<int>& nums) {
        map<int,int>element;
        vector<int>output;
        int temp = nums.size()/3;
        for(auto val:nums)
            element[val]++;
        for(auto it = element.begin();it!=element.end();it++)
            if(it->second>temp)
                output.push_back(it->first);
        return output;
    }
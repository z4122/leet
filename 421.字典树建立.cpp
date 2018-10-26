给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。

找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。

你能在O(n)的时间解决这个问题吗？

示例:

输入: [3, 10, 5, 25, 2, 8]

输出: 28

解释: 最大的结果是 5 ^ 25 = 28.


class Solution {
public:
    struct Trie{
        Trie* Node[2];
        Trie():Node{NULL}{}
    };
    
    void buildTrie(Trie* Head,int input){
        for(int i = 31;i>=0;i--){
            int temp = ((1<<i)&input)?1:0;
            if(Head->Node[temp]==NULL) {
                Head->Node[temp] = new Trie();
            }
            Head = Head->Node[temp];
        }    
    }
    
    int findMax(Trie *head,int input){
        int result = 0;
        for(int i = 31;i>=0;i--){
            int temp = ((1<<i)&input)?1:0;
            if(head->Node[1-temp]!=NULL){
                head = head->Node[1-temp];
                result = result|((1-temp)<<i);
            }
            else{
                head = head->Node[temp];
                result = result|(temp<<i);
            }
        }
        return result;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        Trie *Node = new Trie();
        int result = 0;
        for(auto val:nums){
            buildTrie(Node,val);
        }
        
        for(auto val:nums){
            result = max(result,val^findMax(Node,val));
        }
        
        return result;
    }
};
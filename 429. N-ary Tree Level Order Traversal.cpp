429. N-ary Tree Level Order Traversal



/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        queue<Node*>last,now;
        vector<int> layer;
        vector<vector<int>> ret;
        Node* temp;
        if(root==NULL)
            return ret;
        last.push(root);
        
        while(!last.empty())
        {

            while(!last.empty())
            {
                temp = last.front();
                last.pop();
                layer.push_back(temp->val);
                
                if(temp->children.size()!=0)
                {
                    for(auto iter=temp->children.begin();iter!=temp->children.end();iter++)
                    {
                        now.push(*iter);
                    }
                }
            }
            last = now;
            queue<Node*>().swap(now);
            
            ret.push_back(layer);
            layer.clear();
        }
        return ret;
    }
};
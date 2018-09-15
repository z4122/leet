class Solution {
public:
    
    void dfs(vector<vector<int>>& image,int sr,int sc,int oldcolor,int newcolor)
    {
        if(image[sr][sc]==oldcolor)
            image[sr][sc] = newcolor;
        
        if(sr-1>=0&&image[sr-1][sc]==oldcolor) dfs(image,sr-1,sc,oldcolor,newcolor);
        if(sr+1<=image.size()-1&&image[sr+1][sc]==oldcolor) dfs(image,sr+1,sc,oldcolor,newcolor);
        if(sc-1>=0&&image[sr][sc-1]==oldcolor) dfs(image,sr,sc-1,oldcolor,newcolor);
        if(sc+1<=image[0].size()-1&&image[sr][sc+1]==oldcolor) dfs(image,sr,sc+1,oldcolor,newcolor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldcolor = image[sr][sc];
        if(oldcolor==newColor)
            return image;
        dfs(image,sr,sc,oldcolor,newColor);
            
        return image;
    }
};
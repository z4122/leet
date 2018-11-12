
滴滴笔试题
o（n^2)的方法也可以做的

给出n个数字 a_1,...,a_n，问最多有多少不重叠的非空区间，使得每个区间内数字的xor都等于0。 
输入描述:
第一行一个整数ｎ； 第二行ｎ个整数　a_1,...,a_n； 对于30%的数据，n<=20； 对于100%的数据，n<=100000, a_i<=100000；


输出描述:
一个整数表示最多的区间个数；

输入例子1:
4
3 0 2 2

输出例子1:
2


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> num(n);
    for(int i = 0;i<n;i++) {
        cin>>num[i];
    }
    int sum = 0,start = 0;
    int xxor = 0;

    //关键是算每个数字及之前的数字是否能异或为0，这样复杂度就变低了
    for(int i = 0;i<n;i++){
        //如果有发现一个零，就以这个数字重新计数。
        if(num[i]==0){
            sum++;
            start=i+1;
            continue;
        }
        xxor=0;
        for(int j = i;j>=start;j--){
            xxor=xxor^num[j];
            if(xxor==0){
                sum++;
                start = i+1;
                break;
            }
        }
        
    }
    cout<<sum;
    return 0;
}


八皇后问题
class Solution {
public:
    //判断是否不冲突
    bool available(vector<int> &index,int rowa,int rowb){
        if(index[rowa]==index[rowb])
            return false;
        if(rowa-rowb==index[rowa]-index[rowb])
            return false;
        if(rowb-rowa==index[rowa]-index[rowb])
            return false;
        return true;
    }
    
    //循环与已经填充的数组是否冲突
    void recur(vector<int> &index,int n,int row,int &ret){
        if(row==n){
            ret++;
            return;
        }
        for(int i = 0;i<n;i++){
            index[row] = i;
            for(int j = 0;j<row;j++){
                if(available(index,j,row)==false)
                    break;      
                if(j==row-1)
                    recur(index,n,row+1,ret);
            }
            index[row]=0;
        }

    }
    
    int totalNQueens(int n) {
        vector<int> index(n,0);
        int ret = 0;
        for(int i = 0;i<n;i++){
            index[0] = i;
            recur(index,n,1,ret);
        }
        return ret;
    }
};
#include"stdio.h"
#include"heap"


vector<int> max,min;

template<typename T>class DynamicArray
{
    public:
    void insert(T num)
        {
            if((max.size()+min.size())&1==0)//总数是奇数时插入最大堆
            {
                if(min.size()>0&&num>min[0])
                {
                    min.push_back(num);
                    push_heap(min.begin(),min.end(),greater<T>());

                    num = min[0];
                    pop_heap(min.begin,min.end(),greater<T>());

                    min.pop_back();
                }
                max.push_back(num);
                push_head(max.begin(),max.end(),less<T>());
            }
            else//偶数时插入最小堆
            {
                if(max.size()>0&&num<max[0])
                {
                    max.push_back(num);
                    push_heap(max.begin(),max.end(),greater<int>());

                    num = max[0];
                    pop_head(max.begin(),max.end(),greater<int>());

                    max.pop_back(num);
                }   
                min.push_back(num);
                push_heap(min.begin(),min.end(),less<int>());
            }
        }
}
#include<stdio.h>


template <typename T> class StackWithMin
{



    public:
        StackwithMin(){};
        ~StackwithMin(){};
        

    private:
    std::stack<T> stack1;
    std::stack<T> stack2;

}

template <typename T>void StackWithMin<T>::push(const T&value)
{
    m_data.push(value);
    if()
}


template<typename T>void StackWithMin<T>::push()
{

}

template<typename T>const T&StackWithMin<<T>::min() const
{
    assert(m_data.size()>0&&m_min.size()>0)

    return m_min.top();

}
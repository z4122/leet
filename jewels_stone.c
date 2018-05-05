#include "stdio.h"



int numJewelsInStones(char* J, char* S) {
    int i,j,k;
    while(*(J+i)!='\0')
    {
        i++;
    }
    while(*(S+j)!='\0')
    {
        j++;
    }
    for(;i>=0;i--)
    {
        for(;j>=0;j--)
        {
            if(J[i]==S[j])
                k++;
        }
    }
    printf("%d",k);
    return k;
    
}


void main()
{
    int test = 0;
    test = (numJewelsInStones("aA","AAabbB"));
    printf("%d\n",test);
}
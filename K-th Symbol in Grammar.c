int kthGrammar(int N, int K) {
        int order = 1;
        int count = 0;
        while(order<K)
            order *= 2;
        while(K>2)
        {
            order = order/2;
            if (K > order)
		{
			K = K - order;
			count++;
		}      
        }   
        if(count%2)
            K = 2-K;
        else
            K = K - 1;
        return K;
    }
	
	
	//用递归也可以
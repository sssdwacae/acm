/*

差分  原数组  前缀和

前缀和，差分，递归，函数


    前缀和
        对于q次查询a[l]->a[r]的和
        b[i]=b[i-1]+a[i]
    
    
    差分
        给定一个原数组a不全为0
        对于q次操作a[l]到a[r]全部加k
        输出这个数组改变之后的结果

        原数组的a[i]+差分数组求前缀和的c[i]
        b[l]+=k;b[r+1]-=k;

    void/int fun(int a,vector<int> b...){
        if(递归出口){
            return ;
        }

        if(){
            fun(A,B...)
        }
        if(){
            fun(A,B...)
        }
        return ;
    }
*/
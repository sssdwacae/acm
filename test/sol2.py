import sys

def solve():
    k,x,y=map(int,input().split())
    res=0

    if k==1:
        print(x+y)
        return

    if k%2==0:
        res=(x+2*y)//k
        print(res)
        return
    
    res=min(x,2*y//(k-1))
    x-=res
    y-=res*(k-1)//2

    if x==0:
        res+=y//((k-1)//2+1)
    else:
        cnt=2*y
        if cnt+x>=k:
            res+=1
            x-=k-cnt
            res+=x//k
    
    print(res)

sys.stdout = open('E:\\acmer\\test\\sol2out.txt', 'w')
sys.stdin = open('E:\\acmer\\test\\in.txt', 'r')

T=int(input())
for i in range(T):
    solve()
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct Node{
    int x,y;
    int l;
    int h;
    Node(){}
    Node(int _x,int _y,int _l,int _h){
        x=_x;y=_y;l=_l;h=_h;
    }
};
bool cmp(Node a,Node b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    else 
        return a.y<b.y;
}
int main()
{
    int n,l,h;
    cin>>n>>l>>h;
    vector<Node> a;
    a.push_back(Node(0,0,l,h));
    for(int i=1,_l,_h;i<=n;i++){
        cin>>_l>>_h;
        bool flag=false;
        for(int j=0;j<a.size()&&!flag;j++){
            if(_l<=a[j].l&&_h<=a[j].h){
                if(_l<a[j].l){
                    a.push_back(Node(a[j].x+_l,a[j].y,a[j].l-_l,_h));
                }
                if(_h<a[j].h){
                    a.push_back(Node(a[j].x,a[j].y+_h,a[j].l,a[j].h-_h));
                }
                cout<<a[j].x<<' '<<a[j].y<<endl;
                a.erase(a.begin()+j);
                flag=true;
            }
        }
        if(!flag)
            cout<<"-1\n";
        sort(a.begin(),a.end(),cmp);
    }
    return 0;
}
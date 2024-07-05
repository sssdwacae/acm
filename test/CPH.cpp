//二分查找
// >=x 
sort;
while(l<r){
    int mid=(l+r)/2;
    if(a[mid]>=x){   //a[mid]->f(mid)
        r=mid;
    }
    else{
        l=mid+1;
    }
}

// <=x
sort;
while(l<r){
    int mid=(l+1+r)/2;
    if(a[mid]>x){  ////a[mid]->f(mid)
        r=mid-1;
    }
    else{
        l=mid;
    }
}
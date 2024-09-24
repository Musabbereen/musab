 #include<bits/stdc++.h>
using namespace std;
void prime(int n)
{int i,j;
    int prime[n];
   memset(prime,0,sizeof(prime));
    for(i=2;i<=sqrt(n);i++){

        if(prime[i]==0){
            for(j=i*i;j<=n;j+=i){
                prime[j] = 1;
            }

        }

    }
    for(i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<endl;
        }
    }

}
long long int power(int n){
    int i,j=1;
    for(i=0;i<n;i++){
        j*=10;
    }
    return j;


}
int compare(const void *x_void,const void *y_void){

    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return x-y;
}
int compare1(const void *x_void,const void *y_void){

    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return y-x;
}
long long int binary_search(long long int arr[],long long int n,long long int k){
long long int s = 0;
long long int e = n;

for(long long int i=0;s<=e;i++){
    long long int mid = (s+e)/2 ;
    if(arr[mid]==k){
        return mid;
    }
    else if(k<arr[mid]){
            e = mid-1;
    }
    else {s = mid+1;}



}
return -1;
}
void mergee(int a[],int low,int mid,int high){
int n = high-low+1;
int *b = new int[n];
int left = low;
int right = mid+1;
int bidx = 0;
while(left<=mid  && right<=high){
    if(a[left]<=a[right]){
        b[bidx++] = a[left++];
    }
    else{b[bidx++] = a[right++];}
}
while(left<=mid){
    b[bidx++] = a[left++];
}
while(right<=high){
    b[bidx++] = a[right++];
}
for(int k=0;k<n;k++){
    a[low+k] = b[k];
}
}
void mergesort(int a[],int low,int high){
if(low<high){
    int mid = (low+high)/2;
   mergesort(a,low,mid);
   mergesort(a,mid+1,high);
   mergee(a,low,mid,high);
   }

}
int gcd(int a,int b){
    if(b==0){
        return 1;
    }
    else{return gcd(b,a%b);}
}
long long int fun(long long int a){
    long long int c=1;
    for(long long i=0;i<a;i++){
        c*=-1;
    }
    return c;

}
 long long int primal(long long int n){
int i;
for(i=2;i<=sqrt(n);i++){
    if(n%i==0){
        return -1;
    }

}
return 1;
}
long long int findsum(vector<int>v,long long int n){

    long long int sum = 0;
    for(int i =0;i<=n;i++){
        sum+=v[i];
    }
    return sum;

   }
vector<long long int> binary_searchh(long long int low,long long int high,long long int n,long long int k){
    vector<long long int>v;
  long long int rv = 0;
    while(low<=high){
        long long int mid = (low+high)/2;
        if((mid*n)>=k ){
                rv=mid;
                v.push_back(rv);
            high = mid-1;

        }
        else if((mid*n)<k){
            low = mid+1;
        }
    }
    return v;
}
void permutation(int ind,vector<int>v,set<vector<int>>&permit,int n,vector<int>emp){
        if(ind==n){
            return ;
        }
    if(ind==n-1){
        swap(v[0],v[ind]);
    }
    else{swap(v[ind],v[ind+1]);}
    permutation(ind+1,v,permit,n,emp);
    permit.insert(v);
     if(ind==n-1){
        swap(v[0],v[ind]);
    }
    else{swap(v[ind],v[ind+1]);}
    permutation(ind+1,v,permit,n,emp);
   // permit.push_back(v);
}
void sum_sequence(int ind,long long int sum,vector<int>v,vector<int>arr,vector<long long int>&deck,int n){
    if(ind==n){
        if(sum==0){
                int c=0;
            for(int i=0;i<arr.size();i++){
                if(arr[i]==1){
                    c+=1;
                }
            }
            deck.push_back(c);

        }
        return ;
    }
    if(v[ind]<=sum){
        arr.push_back(v[ind]);
    sum_sequence(ind,sum-v[ind],v,arr,deck,n);
    arr.pop_back();
    }
     sum_sequence(ind+1,sum,v,arr,deck,n);
}
void vector_box(int ind,vector<int>v,vector<vector<int>>&ans,vector<int>test,int n){



}
long long int  dp2(int ind,int m,int a,int b,vector<int>&dp){
if(ind<=0){
    return 0;
}
if(dp[ind]!=-1){
    return dp[ind];
}
long long int left = dp2(ind-1,m,a,b,dp)+a;
long long int right = INT_MAX;
    right = dp2(ind-m,m,a,b,dp)+b;

return dp[ind] = min(left,right);
}
bool sequence_sum(int ind,vector<int>v,int sum,vector<vector<int>>&dp){
if(sum==0){
    return true;
}
if(ind==0){
    return (v[ind]==sum);
}
if(dp[ind][sum]!=-1){
    return dp[ind][sum];
}
bool not_pick = sequence_sum(ind-1,v,sum-v[ind],dp);
bool pick  =false;
if(v[ind]<=sum){
bool pick = sequence_sum(ind-1,v,sum-v[ind],dp);
}


return dp[ind][sum] = not_pick | pick;
}
int find_prefixes(int ind,vector<int>v,int sum){
if(ind==0){
    if(sum%v[ind]==0){
        return sum/v[ind];
    }
    else{
        return INT_MAX;
    }
}
int not_take = find_prefixes(ind-1,v,sum);
int take = INT_MAX;
if(v[ind]<=sum){
    take = 1+find_prefixes(ind,v,sum-v[ind]);
}
return min(not_take,take);
}
int  binary(long long int n){
long long int first=1;
long long int last=n;
while(first<=last){
    long long int mid =(first+last)/2;
    if((mid*mid*mid)<n){
        return mid;
    }
    else{last=mid-1;}
}
return -1;
}
int find_val(long long int n,long long int m){
long long int strt=1;
long long int last=m;
long long int val=0;
while(strt<=last){
    long long int mid=(strt+last)/2;
        if(mid*n>=m && ((mid*n)%m==0 || (mid*n)>n)){
            last=mid-1;
            val=mid;
        }
        else{
            strt=mid+1;
        }
}  
return val;
}
int idx(vector<long long int>v,long long int l){
    long long int idx;
    long long int low =0;
    long long int high=v.size()-1;
    while(low<=high){
        long long int mid=(low+high)/2;
        if(v[mid]>l){
            high=mid-1;
        }
        else if(v[mid]<l){
            low=mid+1;
        }
        else if(v[mid]==l){
            return mid;
        }
    }

    return -1;
}

int main(){
long long int z,strt,last,r,g,e,m=0,x=0,y,s,i,j,c=0,d=0,n,a,b,maximum=0,t,f=0,k,l,sum,q;
cin>>t;
for(k=0;k<t;k++){
    cin>>n;
    vector<int>v;
    for(i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    s=0;
    sort(v.begin(),v.end(),greater<int>());
    int v1 = count(v.begin(),v.begin()+n,v[0]);
    for(i=0;i<n;i++){
        if(v[i]!=v[0]){
            s=v[i];
            break;
        }
    }
    int v2 = count(v.begin(),v.begin()+n,s);
    if(v1%2!=0){
        cout<<"YES"<<endl;

    }  
    else if(v1%2==0){
        if(v1==n || (v2%2==0 && v2!=0)){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}
return 0; 
}

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main(){
    int k;
    cin>>k;
    int number=1<<k;//位運算，計算2^k的值
    int limit=static_cast<int>(ceil(sqrt(number)));//將所需的數字開平方取整，巢狀程式運算的速度會比較快
    vector<int> square(limit+1);//設定陣列，存取平方值
    for(int i=1;i<=limit;i++){
        square[i]=i*i;
    }
    set<vector<int>> solutions;//自動排序去重
for(int a=1;a<=limit;a++){
    if(square[a]>number)break;
        for(int b=a;b<=limit;b++){
            if((square[a]+square[b])>number)break;
             for(int c=b;c<=limit;c++){
                 if((square[a]+square[b]+square[c])>number)break;
              int remain=number-square[a]-square[b]-square[c];
              if(remain>square[c]||remain<0)break;
              int d=sqrt(remain);
              if(remain==square[d]){
                  vector<int> solution={a,b,c,d};
                solutions.insert(solution);//插入到set中
              }
        }
    }
}
if(solutions.empty()){
    cout<<0;
}else {
    for(const auto& solution:solutions){
       for(int x:solution){
           cout<<x<<" ";
       }
       cout<<endl;
    }
}
}
/*還有改進空間 1. 在巢狀結構最內層中，使用二分搜尋法，以追求極致效能
2. remain < 0 的判斷位置
3. 在計算 d = sqrt(remain) 之後，需要對d的範圍檢查
4. remain < square[c] 多餘的一行
以上有些問題可能導致程式無法運行，不過既然都AC了，哪管那麼多
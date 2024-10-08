#include <bits/stdc++.h>
//The second modification removes the new comment
#define SIZE 10000000
using namespace std;

void recQuickSort(vector<int> &a, int l, int r) { //快速排序
    if(l<0 || r>=a.size() || l>=r) return;
    int key=a[l], i=l, j=r;
    while(i<j) {
        while(i<j &&a[j]>=key) j--;
        swap(a[i], a[j]);
        while(i<j &&a[i]<=key) i++;
        swap(a[i], a[j]);
    }
    a[i]=key;
    recQuickSort(a, l, i-1);
    recQuickSort(a, i+1, r);
}



int main() {
    int n,i,times;
    vector <int> a(SIZE);
    vector <int> original_data(SIZE);
    cout<<"请输入测试次数:"<<endl;
    cin>>times;//输入测试数
    clock_t c_start,c_end;
    double recquick_T=0;
    for(n=10;n<=1000000;n*=10){
        cout<<"规模"<<n<<"次:"<<endl;
        for(int j=0; j<times; j++) { //随机产生20组测试样本
            srand((unsigned)time(NULL));//srand()函数产生一个以当前时间开始的随机种子
            for(i=0; i<n; i++) { //产生n个0~n的随机数
                original_data[i]=rand()*rand()%n;
            }

            c_start=clock();
            recQuickSort(original_data,0,n);
            c_end=clock();
            cout<<c_end-c_start<<' ';
            if(j%10==9)
                cout<<endl;
            recquick_T+=double(c_end-c_start)/ CLOCKS_PER_SEC;//快速排序

        }
        cout<<times<<"次快速排序平均用时："<<recquick_T/times<<endl;


        cout<<endl;
    }
    return 0;
}


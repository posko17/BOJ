#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> stock_price;
    int jh_cash=0,sm_cash=0;
    int jh_stock=0,sm_stock=0;
    int n;
    cin>>n;
    jh_cash=n;
    sm_cash=n;
    int count=0;
    int decrease=0;
    stock_price.push_back(0);
    int a;
    for(int i=0;i<14;i++)
    {
        cin>>a;
        stock_price.push_back(a);

        //junhyun
        while(jh_cash>=stock_price[i+1])
        {
            jh_cash-=stock_price[i+1];
            jh_stock++;
        }
        //sungmin
        if(stock_price[i]<stock_price[i+1])
        {//increase
            count++;
            decrease=0;
        }
        if(stock_price[i]>stock_price[i+1])
        {//increase
            count=0;
            decrease++;
        }
        if(count==3)
        {//sell all
            sm_cash+=sm_stock*stock_price[i+1];
            sm_stock=0;
            count=0;
        }
        if(decrease==3)
        {
            while(sm_cash>=stock_price[i+1])
            {
                sm_cash-=stock_price[i+1];
                sm_stock++;
            }
        }
    }
    int smoney=sm_stock*stock_price[14]+sm_cash;
    int jmoney=jh_stock*stock_price[14]+jh_cash;
   // cout<<smoney<<'\n'<<jmoney<<'\n';
    if(jmoney>smoney)
    {
        cout<<"BNP";
    }
    else if(jmoney<smoney)
    {
        cout<<"TIMING";
    }
    else
    {
        cout<<"SAMESAME";
    }

}
/*
代码功能:
	1、素性测试
	参考资料-->密码编码学与网络安全（第四版）Stallings
2017/5/25 yeqinlao
 */
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
	using namespace std;

typedef long long int ll;


ll exponent (ll a,ll n,ll mod)	//返回a 的 n次幂。
{
	ll i,sum = 1;
	for(i = 1; i <= n; i++)
		sum = (sum * a) % mod;
	return sum;
}

int PrimeTest(ll n,ll q,ll k)	//素性检验
{
	ll N = n - 1;
	ll a;		//随机数的地址
	ll j,y;	//中间变量
	ll t,counter;	//计数器

	//生成随机数

	a = int (2 + rand()%(N - 2));	// 1 < a < n - 1  <--> 2 <= a <= n - 2

	y = exponent (a,q,n) % n;

	if( y == 1 || y == N ) return 0;	// y == 1 || y == n - 1返回

	for(j = 1; j <= k -1 && y != N; j++)
		{
			y  = exponent (y,2,n) % n;
			if(y == 1)
			{
				cout << "合数"  << endl;
				exit(0);
			}	//返回合数
		}
	if(y != N) 
	{
		cout << "合数"  << endl;
		exit(0);
	}	//返回合数

	return 0;	//返回0
}

void JudgePrime (ll n,ll t)
{
	ll sum = 0,temp;
	ll i,counter;
	ll k,q;		//找出整数 k,q使得（n - 1 = 2^k * q）
	srand(time(0));	//生成随机数种子

	//计算k,q
	counter = 0;
	i = n -1;
	while(i % 2 == 0 )
	{
		i /= 2;
		counter++;
	}

	k = counter;
	q = i;

	cout << "k = " << k << " q = " << q << endl;
	
	for(i = 0; i < t; i++)	//生成t个随机数进行判断
	{
		temp = PrimeTest(n,q,k);
		sum += PrimeTest(n,q,k);
	} 
	if(i >= t)
	cout << "素数" << endl;
	
}
int main()
{
    ll n;
	ll  t;
	cout << "输入一个大于3的奇整数: ";
	cin >> n;

	cout << "随机数的个数: ";
	cin >> t;

	JudgePrime(n,t);

	return 0;
}


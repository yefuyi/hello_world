#include<iostream> 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	using namespace std;
#define MAX 100
#define KG "    "
#define XX "------------------"
#define XH "*********"
int flag = 0;
void Caesar();	//移位密码 
void Virginia(); //维吉尼亚密码 
void FangShe();	//仿射密码 
void Hill();    //希尔密码
void menu()			//菜单栏 
{
	cout <<"\n" << XH << "加密（1）" << XH << endl;
	cout << XH << "解密（2）" << XH << endl;
	cout << XH << "设置（3）" << XH << endl;
	cout << XH << "帮助（4）" << XH << endl;
	cout << XH << "退出（5）" << XH << endl;
}

void encryption()
{
	int i;
	cout <<"-----------------------------------" << endl; 
	cout << " （1）移位密码" << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （2）维吉尼亚密码"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （3）仿射密码" << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （4）Hill密码"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << "选择加密方法（1~4）: " ;
	
	cin >> i;
	switch(i) 
		{
			case 1: Caesar();break;	//	仿射密码 
			case 2: Virginia();break; 
			case 3: FangShe();break; 
            case 4: Hill();break;
			default:cout << "*****退出*****" << endl; break; 
		}
	
}
void Caesar()		//移位密码 
{
	char plaintext[MAX],ciphertext[MAX],c;
	int key,i,len;
	cout << "请输入明文(a ~ z) : " ;
	cin >> plaintext;
	len = strlen(plaintext);
	for(i = 0; i < len ; i++)
	{
		if(plaintext[i] < 97 || plaintext[i] > 122)
		{
			flag = 1;
		}

	}
	if (flag == 1) 
	{
		cout << "明文中含有不合法的输入值！！" << endl;
		return;
	}
	if (flag == 1) return;
	cout << "输入秘钥(0 ~ 25): ";
	cin >> key;
	for(i = 0; i < len ; i++ )
	{
		c = (plaintext[i] + key);
		if(c > 'z') c= 'a' + (c - 'z' - 1);
		ciphertext[i] = c - 32;
	}
	
	cout << "明文为: " <<plaintext << endl;
	cout << "秘钥为: " << key << endl;
	cout << "密文为: ";
	for(i = 0; i < len; i++)
 	cout << ciphertext[i];
 	cout << endl;
	
	
}
void DecipCaesar()	//解密移位密码 
{
	char plaintext[MAX],ciphertext[MAX],c;
	int key,i,len;
	cout << "请输入密文(A ~ Z) : " ;
	cin >> plaintext;
	len = strlen(plaintext);
	for(i = 0; i < len ; i++)
	{
		if(plaintext[i] < 65 || plaintext[i] > 90)
		{
			flag = 1;
		}

	}
	if (flag == 1) return;	if (flag == 1) 
	{
		cout << "明文中含有不合法的输入值！！" << endl;
		return;
	}	cout << "输入秘钥(0 ~ 25): ";
	cin >> key;
	for(i = 0; i < len ; i++ )
	{
		c = (plaintext[i] - key);
		if(c < 'A') c= 'Z' - ('A' - c - 1);
		ciphertext[i] = c + 32;
	}
	
	cout << "密文为: " <<plaintext << endl;
	cout << "秘钥为: " << key << endl;
	cout << "明文为: ";
	for(i = 0; i < len; i++)
 	cout << ciphertext[i];
 	cout << endl;

}
void Virginia()		//维吉尼亚密码 
{
	char plaintext[MAX],ciphertext[MAX],c;
	int i,j,t,len_p,len_k;
	char key[MAX];
	cout << "请输入明文(a ~ z) : " ;
	cin >> plaintext;
	len_p = strlen(plaintext);
	for(i = 0; i < len_p ; i++)	//合法性检验 
	{
		if(plaintext[i] < 'a' || plaintext[i] > 'z')
		{
			flag = 1;
		}

	}
	if (flag == 1) 
	{
		cout << "明文中含有不合法的输入值！！" << endl;
		return;
	}
	cout << "输入秘钥(a~z组成的字符串) : " ;
	cin >>key;
	len_k = strlen(key);
	
	for(i = 0; i < len_p ; i++ )	//加密 
	{
		j = i % len_k;
		t = key[j] - 'a';
		c = (plaintext[i] + t);
		if(c > 'z') c= 'a' + (c - 'z' - 1);
		ciphertext[i] = c - 32;
	}

	cout << "明文为: " <<plaintext << endl;
	cout << "秘钥为: " << key << endl;
	cout << "密文为: ";
	for(i = 0; i < len_p; i++)
 	cout << ciphertext[i];
 	cout << endl;
	
} 

void DecipVirginia()   //解密维吉尼亚密码 
{
	char plaintext[MAX],ciphertext[MAX],c;
	int i,j,t,len_p,len_k;
	char key[MAX];
	cout << "请输入密文(A ~ Z) : " ;
	cin >> plaintext;
	len_p = strlen(plaintext);
	for(i = 0; i < len_p ; i++)	//合法性检验 
	{
		if(plaintext[i] < 'A' || plaintext[i] > 'Z')
		{
			flag = 1;
		}

	}
	if (flag == 1) 
	{
		cout << "明文中含有不合法的输入值！！" << endl;
		return;
	}
	cout << "输入秘钥(a~z组成的字符串) : " ;
	cin >>key;
	len_k = strlen(key);
	
	for(i = 0; i < len_p ; i++ )	//加密 
	{
		j = i % len_k;
		t = key[j] - 'a';
		c = (plaintext[i] - t);
		if(c < 'A') c= 'Z' - ( 'A' - c - 1);
		ciphertext[i] = c + 32;
	}

	cout << "密文为: " <<plaintext << endl;
	cout << "秘钥为: " << key << endl;
	cout << "明文为: ";
	for(i = 0; i < len_p; i++)
 	cout << ciphertext[i];
 	cout << endl;
	
}
void FangShe()	//仿射密码
{
	char plaintext[MAX],ciphertext[MAX],c;
	int i,j,key,len,a,b,t;
	cout << "请输入明文(a ~ z) : " ;
	cin >> plaintext;
	len = strlen(plaintext);
	for(i = 0; i < len ; i++)
	{
		if(plaintext[i] < 'a' || plaintext[i] > 'z')
		{
			flag = 1;
		}

	}
	if (flag == 1) 
	{
		cout << "明文中含有不合法的输入值！！" << endl;
		return;
	}
	cout << "输入秘钥(0 ~ 25): \n";
	cout << "秘钥 a = ";
	cin >> a;
	cout << "秘钥 b = ";
	cin >> b;
        i = a;
        key = a;
        j = 26;
        while(i % j != 0)
        {
            t = i % j;
            i = j;
            j = t;
        }
        if(j != 1)
        {
            cout << "秘钥输入不符合规则！\n";
            return;
        }
	for(i = 0; i < len ; i++ )
	{
		t = (plaintext[i] - 'a');
		t = (a * t + b) % 26;
		c = 'a' + t;
		ciphertext[i] = c - 32;
	}
	
	cout << "明文为: " <<plaintext << endl;
	cout << "秘钥为: a = "  << key << "  b = "  << b << endl;
	cout << "密文为: ";
	for(i = 0; i < len; i++)
 	cout << ciphertext[i];
 	cout << endl;	
	
} 

void DecipherFangShe() 
{
	char plaintext[MAX],ciphertext[MAX],c;
	int key,i,j,len,a,b,t;
	cout << "请输入密文(A ～ Z) : " ;
	cin >> plaintext;
	len = strlen(plaintext);
	for(i = 0; i < len ; i++)
	{
		if(plaintext[i] < 'A' || plaintext[i] > 'Z')
		{
			flag = 1;
		}

	}
	if (flag == 1) 
	{
		cout << "密文中含有不合法的输入值！！" << endl;
		return;
	}
	cout << "输入秘钥(0 ~ 25): \n";
	cout << "秘钥 a = ";
	cin >> a;
	cout << "秘钥 b = ";
	cin >> b;
        i = a;
        key = a;
        j = 26;
        while(i % j != 0)
        {
            t = i % j;
            i = j;
            j = t;
        }
        if(j != 1)
        {
            cout << "秘钥输入不符合规则！\n";
            return;
        }
        for(i = 0; i < 1000; i++)
        {
            if( ((a * i) % 26 ==1))break;
        }
        a = i;
	for(i = 0; i < len ; i++ )
	{
		t = (plaintext[i] - 'A');
		t = a * (t - b) % 26;
		c = 'A' + t;
		ciphertext[i] = c + 32;
	}
	
	cout << "密文为: " <<plaintext << endl;
	cout << "秘钥为: a = " << key << "  b = "  << b << endl;
	cout << "明文为: ";
	for(i = 0; i < len; i++)
 	cout << ciphertext[i];
 	cout << endl;		
}
/*以下为计算行列式值的递归函数*/
int Fun( int n, int a[MAX][MAX] )
{
    int b[MAX][MAX] = {{0}};            /*定义数组b并初始化*/
    int i = 0, j = 0, sum = 0;          /*i，j为行与列，sum为行列式的值*/
    int x = 0,c = 0,p=0;                /*用x判断加与减，c,p为中间变量*/

    if(n == 1)
    return a[0][0];

    for(i = 0;i < n; i++)               /*此处大循环实现将余子式存入数组b中*/
    {
        for(c = 0;c < n-1; c++)
        {
            for(j = 0;j < n-1;j++)
            {
                if (c < i){             /*借助c判断每行的移动方法*/
                    p = 0;              /*当p=0时，行列式只向左移，即消去对应的第一列的数*/
                }
                else{                   /*否则行列式左移后再上移*/
                    p = 1;
                }
            b[c][j] = a[c+p][j+1];
            }
        }

        if(i % 2 == 0){                  /*i+j（此时j=0，故只考虑i）为偶数，加法预算*/
            x = 1;
        }
        else{                           /*i+j为奇数，减法运算*/
            x = (-1);
        }
     sum += a[i][0] * Fun(n - 1, b ) * x;         /*计算行列式的值*/
    }

    return sum;                                   /*将值返回*/
}
void Hill()     //希尔密码加密
{
    char plaintext[MAX],ciptertext[MAX];
    int key[MAX][MAX] = {{0}};
    int i,j,k,m,n,t,len_p,len_c;
    int char2num[MAX];
    cout << "请输入明文(a ～ｚ)： ";
    cin >> plaintext;
        len_p = strlen(plaintext);；
	for(i = 0; i < len ; i++)
	{
		if(plaintext[i] < 'a' || plaintext[i] > 'z')
		{
			flag = 1;
		}

	}
	if (flag == 1) 
	{
		cout << "密文中含有不合法的输入值！！" << endl;
		return;
	}
    cout << "请输入希尔加密矩阵:" << endl;
    cout << "矩阵阶数m = ";
    cin >> m;
    n = m;
    for( i = 0; i < m ; i++)
    {
        cout << "输入矩阵第" << i + 1<< "行元素: ";
        for(j = 0; j < n; j++)
        cin >> key[i][j];
    }
    t = Fun( n, key );
    if(t == 0)
    {
		cout << "输入加密矩阵必须是非奇异矩阵！！\n";
		return;
	}
    len_c = 0;
    for(i = 0; i< len_p; i++)
    {
        char2num[i] =  plaintext[i] - 'a';
    }
    
    j = len_p / n;
    int l;
    for(i = 0; i < j; i++)
    {
        for(k = 0; k < m; k++)
        {
			t = 0;
            for( l = 0; l < m; l++){
            t += char2num[m * i + l] * key[k][l];
            }
        ciptertext[m*i+k] = t % 26 + 'A';
        len_c++;
        }
    }
    
    cout << "明文为: \n" << plaintext << endl;
    cout << "秘钥为; \n";
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%3d",key[i][j]);
        printf("\n");
    }
    cout << "密文为: \n";
    for(j = 0; j < len_c; j++)
    cout << ciptertext[j];
    cout << "\n";
}

/* void DecipherHill() //破译希尔密码
{
     char plaintext[MAX],ciptertext[MAX];
    int key[MAX][MAX] = {{0}};
    int i,j,k,m,n,t,len_p,len_c;
    int char2num[MAX];
    cout << "请输入密文(A ～Z)： ";
    cin >> plaintext;
            len_p = strlen(plaintext);；
	for(i = 0; i < len ; i++)
	{
		if(plaintext[i] < 'A' || plaintext[i] > 'Z')
		{
			flag = 1;
		}

	}
	if (flag == 1) 
	{
		cout << "密文中含有不合法的输入值！！" << endl;
		return;
	}
    cout << "请输入希尔加密矩阵:" << endl;
    cout << "矩阵阶数m = ";
    cin >> m;
    n = m;
    for( i = 0; i < m ; i++)
    {
        cout << "输入矩阵第" << i + 1<< "行元素: ";
        for(j = 0; j < n; j++)
        cin >> key[i][j];
    }
    t = Fun( n, key );
    if(t == 0)
        {
		cout << "输入加密矩阵必须是非奇异矩阵！！\n";
		return;
	}
	
	for(i = 0; i <= 1000; i++)         //我TM用暴力穷举法
            for(j = 0; j <= 1000;j++)
                for(k = 0; k <= 1000;k++)
                {
                    if(a[p][q])
                }
	
    len_c = 0;
    for(i = 0; i< len_p; i++)
    {
        char2num[i] =  plaintext[i] - 'a';
    }
    
    j = len_p / n;
    int l;
    for(i = 0; i < j; i++)
    {
        for(k = 0; k < m; k++)
        {
			t = 0;
            for( l = 0; l < m; l++){
            t += char2num[m * i + l] * key[k][l];
            }
        ciptertext[m*i+k] = t % 26 + 'A';
        len_c++;
        }
    }
    
    cout << "明文为: \n" << plaintext << endl;
    cout << "秘钥为; \n";
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%3d",key[i][j]);
        printf("\n");
    }
    cout << "密文为: \n";
    for(j = 0; j < len_c; j++)
    cout << ciptertext[j];
    cout << "\n";   
}
*/
void decipher() 
{
	int i;
	cout <<"-----------------------------------" << endl; 
	cout << " （1）破译移位密码" << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （2）破译维吉尼亚密码"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （3）破译仿射密码" << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （4）破译Hill密码"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （5）退出" << endl;
	cout <<"-----------------------------------" << endl;
	cout << "选择操作方法（1~5）: " ; 
	
	cin >> i;
	switch(i) 
		{
			case 1: DecipCaesar();break;	//	移位密码 
			case 2: DecipVirginia() ;break;
            case 3: DecipherFangShe();break;
			/*
			case 3:Del(head);break;
			case 4:Disp(head) ;break;
			*/
			default:cout << "退出" << endl; break; 
		}
	
}
int main()
{
	menu();
	int i;
	cout << "输入要进行的操作（1~5）: " ;
	cin >> i;
	while(i != 5)
	{
		switch(i) 
		{
			case 1:encryption();break;
			case 2:decipher();break;
			case 3:
			cout << "×××××××修复软件软件××××××××" << endl;
			break;
			case 4:
			cout << "----------------------------" <<endl;
			cout << " 请联系开发人员 yeqinlao    \n" ;
			cout << "----------------------------" <<endl;
			cout << " 18856021939@163.com    \n" ;
			cout << "----------------------------" <<endl;
			cout << " 使用手册及源码下载：        \n" ;
			cout << "----------------------------" <<endl;
			cout << " www.github/yeqinlao/   \n" ;
			cout << "----------------------------" <<endl;
			break;
			/*case 2:Add(head);break;
			case 3:Del(head);break;
			case 4:Disp(head) ;break;
			*/
			default:cout << "退出" << endl; break; 
		}
		menu();
		cout << "\n 输入要进行的操作（1~5）: " ;
		cin >> i;
	}
	return 0;
};	

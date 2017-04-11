#include<iostream> 
#include<stdio.h>
#include<stdlib.h>
/*
代码功能 :
	1、移位密码加密解密
	2、维吉尼亚密码加密解密
	3、仿射密码加密解密
	4、希尔密码加密解密 (注意加密K矩阵左乘P)
2017/3/20 编辑--yeqinlao
2017/4/9  修改--yeqinlao
2017/4/11 修改--yeiqnlao
				 
*/ 
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
	cout << " （5）返回主界面"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << "选择加密方法或者回到主界面（1~5）: " ;
	
	cin >> i;
	switch(i) 
		{
			case 1: Caesar();break;	//	仿射密码 
			case 2: Virginia();break; 
			case 3: FangShe();break; 
            case 4: Hill();break;
			default:break; 
		}
	
}
void Caesar()		//移位密码 
{
	char plaintext[MAX],ciphertext[MAX];	//明文密文定义 
	int temp;	//存储字符转化为数字的中间值 
	int key,i,len;//明文长度、密钥、中间变量定义 
	cout << "请输入明文(a ~ z) : " ;
	cin >> plaintext;
	len = strlen(plaintext);
	for(i = 0; i < len ; i++)	//明文合法性判断 
	{
		if(plaintext[i] < 97 || plaintext[i] > 122)
		{
			flag = 1;
		}

	}
	if (flag == 1) //明文不合法 
	{
		cout << "明文中含有不合法的输入值！！" << endl;
		return;
	}
	if (flag == 1) return;
	cout << "输入秘钥(0 ~ 25): ";
	cin >> key;
	if(key < 0 || key > 25) //密钥不合法 
	{
		cout << "密钥中含有不合法的输入值！！" << endl;
		return;
	}
	for(i = 0; i < len ; i++ )	//加密函数实现 
	{
		temp = plaintext[i] - 'a' + key;//明文字符转化为数字存储到temp数组 
		temp = temp%26;
		ciphertext[i] = temp + 'A';
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
	char plaintext[MAX],ciphertext[MAX];//明文密文定义，注意这里直接使用加密部分代码,明文单词意味着密文 ,反之亦然 
	int key,i,len,temp;//明文密文长度及相关中间量的定义
	 
	cout << "请输入密文(A ~ Z) : " ;
	cin >> plaintext;
	len = strlen(plaintext);
	for(i = 0; i < len ; i++)//密文合法性判断 
	{
		if(plaintext[i] < 65 || plaintext[i] > 90)
		{
			flag = 1;
		}

	}
		
	if (flag == 1) //密文不合法给出提示并且退出 
	{
		cout << "密文中含有不合法的输入值！！" << endl;
		return;
	}	cout << "输入秘钥(0 ~ 25): ";
	cin >> key;
	
		if(key < 0 || key > 25) //密钥不合法 
	{
		cout << "密钥中含有不合法的输入值！！" << endl;
		return;
	}
	
	for(i = 0; i < len ; i++ )//解密函数实现 
	{
		temp = (plaintext[i] - 'A' - key)%26;	//密文转化为数值并进行加密运算 
		if(temp < 0) temp = temp + 26;	//小于0的处理 
		ciphertext[i] = temp + 'a';
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
	char plaintext[MAX],ciphertext[MAX];//明文密文定义
	int i,j,t,len_p,len_k,temp;//明文长度、密钥长度及中间变量定义 
	char key[MAX];
	cout << "请输入明文(a ~ z) : " ;
	cin >> plaintext;
	len_p = strlen(plaintext);
	for(i = 0; i < len_p ; i++)	//明文合法性检验 
	{
		if(plaintext[i] < 'a' || plaintext[i] > 'z')
		{
			flag = 1;
		}

	}
	if (flag == 1) //不合法退出到主界面并给出提示 
	{
		cout << "明文中含有不合法的输入值！！" << endl;
		return;
	}
	cout << "输入秘钥(a~z组成的字符串) : " ;
	cin >>key;
	 
	len_k = strlen(key);
	for(i = 0; i < len_k ; i++)	//密钥合法性检验 
	{
		if(key[i] < 'a' || key[i] > 'z')
		{
			flag = 1;
		}
	}
	
	if (flag == 1) //不合法退出到主界面并给出提示 
	{
		cout << "密钥中含有不合法的输入值！！" << endl;
		return;
	}
	
	for(i = 0; i < len_p ; i++ )	//加密 
	{
		j = i % len_k;//通过模运算循环选择密钥,也可以使用循环链表 
		t = key[j] - 'a';//密钥变数值 
		temp = (plaintext[i] + t)%26; 
		ciphertext[i] = temp + 'A';
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
	char plaintext[MAX],ciphertext[MAX];//明文密文定义,注意这里直接使用加密部分代码,明文单词意味着密文 ,反之亦然 
	int i,j,t,len_p,len_k,temp;		//中间变量及密文明文长度 
	char key[MAX];
	cout << "请输入密文(A ~ Z) : " ;
	cin >> plaintext;
	len_p = strlen(plaintext);	//读取密文长度 
	for(i = 0; i < len_p ; i++)	//合法性检验 
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
	cout << "输入秘钥(a~z组成的字符串) : " ;
	cin >>key;
	len_k = strlen(key);
	
	for(i = 0; i < len_k ; i++)	//密钥合法性检验 
	{
		if(key[i] < 'a' || key[i] > 'z')
		{
			flag = 1;
		}
	}
	
	if (flag == 1) //不合法退出到主界面并给出提示 
	{
		cout << "密钥中含有不合法的输入值！！" << endl;
		return;
	}
	for(i = 0; i < len_p ; i++ )	//解密函数实现 
	{
		j = i % len_k;
		t = key[j] - 'A';
		temp = (plaintext[i] - t)%26;
		if(temp < 0) temp += 26;
		ciphertext[i] = temp + 'a';
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
	char plaintext[MAX],ciphertext[MAX];	//仿射密码明文密文定义 
	int i,j,key,len,a,b,t;	//密钥及明文长度及中间变量定义 
	cout << "请输入明文(a ~ z) : " ;//明文输入 
	cin >> plaintext;
	len = strlen(plaintext);//明文长度 
	for(i = 0; i < len ; i++)//合法性检验 
	{
		if(plaintext[i] < 'a' || plaintext[i] > 'z')
		{
			flag = 1;
		}

	}
	if (flag == 1) //不合法明文退出函数 
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
    while(i % j != 0)		//辗转相除发判断a与26互素 
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
	for(i = 0; i < len ; i++ )	//加密过程函数实现 
	{
		t = (plaintext[i] - 'a');//明文字符数值化处理 
		t = (a * t + b) % 26;
		ciphertext[i] = t + 'A';
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
	char plaintext[MAX],ciphertext[MAX];//密文明文定义,注意此处直接复制加密部分代码,密文即位上面的明文,反之亦然 
	int key,i,j,len,a,b,t;	//密钥及中间变量定义 
	cout << "请输入密文(A ～ Z) : " ;
	cin >> plaintext;	//密文输入 
	len = strlen(plaintext);//密文长度
	 
	for(i = 0; i < len ; i++)	//密文合法性检验 
	{
		if(plaintext[i] < 'A' || plaintext[i] > 'Z')
		{
			flag = 1;
		}

	}
	if (flag == 1) //不合法输入值给出提示并返回 
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
        while(i % j != 0)	//判断a 是否和26互素 
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
        for(i = 0; i < 1000; i++)	//a 的逆 
        {
            if( ((a * i) % 26 ==1))break;
        }
        a = i;
	for(i = 0; i < len ; i++ )	//解密过程函数实现 
	{
		t = (plaintext[i] - 'A');
		t = a * (t - b) % 26;
		while(t < 0) t = t + 26; 
		ciphertext[i] = t + 'a';
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
    char plaintext[MAX],ciptertext[MAX];//明文密文定义
    int key[MAX][MAX] = {{0}};//密钥矩阵 
    int i,j,k,m,n,t,len_p,len_c;//明文长度、密钥长度及中间变量定义 
    int char2num[MAX];
    cout << "请输入明文(a ～ｚ)： ";
    cin >> plaintext;
    len_p = strlen(plaintext);
	for(i = 0; i < len_p ; i++)
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
    t = Fun( n, key )%26;	//计算矩阵行列式
    //while(t < 0) t += 26;
    cout << "矩阵的行列式: " << t << endl;
    if(t == 0)
    {
		cout << "输入加密矩阵必须是非奇异矩阵！！\n";
		return;
	}
    len_c = 0;
    for(i = 0; i< len_p; i++)
    {
        char2num[i] =  plaintext[i] - 'a';	//字符转换为数字
    }
    
    j = len_p / n;
    int l;
    //temp = 0;
    for(i = 0; i < j; i++)	//(k * P ) mod 26;
    {
        for(k = 0; k < m; k++)
        {
			t = 0;
            for( l = 0; l < m; l++){
            t += char2num[m * i + l] * key[k][l];//k[i,j] * p[j,i]
            //cout << "测试" << t << endl;
            }
       // cout << "测试--->" << t << endl;
        while(t < 0) t += 26;//模运算
        ciptertext[m*i+k] = t%26 + 'A';//储存密文
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
void BanSui(int a[MAX][MAX], int bansui[MAX][MAX], int n)		//计算伴随矩阵
{
	int i,j,k,p,q;
	int b[MAX],c[MAX][MAX];
	for(i = 0; i < n; i++)	
		for(j = 0; j < n; j++)
		{
			k = 0;
			for(p  = 0; p < n; p++)
				for(q = 0; q < n; q++)	//余子式存储到一维数组
				{
					if(i == p) continue;
					if(j == q) continue;
					else b[k] = a[p][q];
					k++;
				}
			for(p = 0,k = 0; p < n - 1; p++)	//余子式储存到矩阵
				for(q = 0; q < n - 1; q++)
				{
					c[p][q] = b[k];
					k++;
				}
				if( (i + j) % 2 == 1 )
			bansui[j][i] = 0-Fun(n - 1,c);//余子式储存到伴随矩阵每个位置
                        else bansui[j][i] = Fun(n - 1,c);
		}
}

void DecipherHill() //破译希尔密码
{
     char plaintext[MAX],ciptertext[MAX];
    int key[MAX][MAX] = {{0}},key1[MAX][MAX];
    int i,j,k,m,n,t,len_p,len_c,p;
    int char2num[MAX];
    cout << "请输入密文(A ～Z)： ";
    cin >> plaintext;
            len_p = strlen(plaintext);
	for(i = 0; i < len_p ; i++)
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
    for( i = 0; i < m ; i++)		//秘钥矩阵的录入
    {
        cout << "输入矩阵第" << i + 1<< "行元素: ";
        for(j = 0; j < n; j++)
        cin >> key[i][j];
    }
/*    t = Fun( n, key )%26;
 	while(t < 0)
	t += 26;
*/
	t = Fun( n, key );
	p = t % 26;
	while(p < 0)
	p += 26;
    if(t == 0)
        {
		cout << "输入加密矩阵必须是非奇异矩阵！！\n";
		return;
	}		 
     for(i = 0; i < 1000; i++)	//求加密矩阵行列式的逆
        {
            if( ((p * i) % 26 ==1))break;
        }
	k = i; 
	BanSui(key,key1,n);
     for(i = 0; i < m; i++)		//求加密矩阵逆矩阵
		 for(j = 0; j < m;j++)
			 key1[i][j] = ( k * key1[i][j]) % 26;
     for(i = 0; i < m; i++)		//求模运算逆矩阵
		 for(j = 0; j < m;j++)
		 while(key1[i][j] < 0)
		 key1[i][j] += 26;
			 
	cout << "加密矩阵逆矩阵" << endl;
	for(i = 0; i < m; i++)
	{
		for(j = 0;j < m; j++)
		printf("%3d",key1[i][j]);
		printf("\n");
	}
	
	
    len_c = 0;
    for(i = 0; i< len_p; i++)
    {
        char2num[i] =  plaintext[i] - 'A';
    }
    
    j = len_p / n;
    int l;
    for(i = 0; i < j; i++)
    {
        for(k = 0; k < m; k++)
        {
			t = 0;
            for( l = 0; l < m; l++){
            t += char2num[m * i + l] * key1[k][l];
            }
        ciptertext[m*i+k] = t % 26 + 'a';
        len_c++;
        }
    }
    
    cout << "密文为: \n" << plaintext << endl;
    cout << "秘钥为; \n";
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%3d",key[i][j]);
        printf("\n");
    }
    cout << "明文为: \n";
    for(j = 0; j < len_c; j++)
    cout << ciptertext[j];
    cout << "\n";   
}
void decipher() 
{
	int i;
	cout <<"-----------------------------------" << endl; 
	cout << " （1）解密移位密码" << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （2）解密维吉尼亚密码"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （3）解密仿射密码" << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （4）解密Hill密码"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " （5）返回主界面" << endl;
	cout <<"-----------------------------------" << endl;
	cout << "选择操作方法（1~5）: " ; 
	
	cin >> i;
	switch(i) 
		{
			case 1: DecipCaesar();break;	//	移位密码 
			case 2: DecipVirginia() ;break;
            case 3: DecipherFangShe();break;
			case 4: DecipherHill();break;
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
			cout << "×××××××version 1.1××××××" << endl;
			cout << "×××××××更新检测××××××××" << endl;
			cout << "×××××××失败了,开心吧！××××" << endl;
			break;
			case 4:
			cout << "----------------------------" <<endl;
			cout << " 请联系开发人员 yeqinlao    \n" ;
			cout << "----------------------------" <<endl;
			cout << " 18856021939@163.com    \n" ;
			cout << "----------------------------" <<endl;
			cout << " 使用手册及源码下载：        \n" ;
			cout << "----------------------------" <<endl;
			cout << " https://github.com/yefuyi/hello_world/tree/C \n" ;
			cout << "----------------------------" <<endl;
			break;
			default:cout << "退出" << endl; break; 
		}
		menu();
		cout << "\n 输入要进行的操作（1~5）: " ;
		cin >> i;
	}
	return 0;
};	


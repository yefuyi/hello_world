#include<iostream> 
#include<stdio.h>
#include<stdlib.h>
/*
���빦�� :
	1����λ������ܽ���
	2��ά������������ܽ���
	3������������ܽ���
	4��ϣ��������ܽ��� (ע�����K�������P)
2017/3/20 �༭--yeqinlao
2017/4/9  �޸�--yeqinlao
2017/4/11 �޸�--yeiqnlao
				 
*/ 
#include<string.h>
	using namespace std;
#define MAX 100
#define KG "    "
#define XX "------------------"
#define XH "*********"
int flag = 0;
void Caesar();	//��λ���� 
void Virginia(); //ά���������� 
void FangShe();	//�������� 
void Hill();    //ϣ������
void menu()			//�˵��� 
{
	cout <<"\n" << XH << "���ܣ�1��" << XH << endl;
	cout << XH << "���ܣ�2��" << XH << endl;
	cout << XH << "���ã�3��" << XH << endl;
	cout << XH << "������4��" << XH << endl;
	cout << XH << "�˳���5��" << XH << endl;
}

void encryption()
{
	int i;
	cout <<"-----------------------------------" << endl; 
	cout << " ��1����λ����" << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " ��2��ά����������"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " ��3����������" << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " ��4��Hill����"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " ��5������������"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << "ѡ����ܷ������߻ص������棨1~5��: " ;
	
	cin >> i;
	switch(i) 
		{
			case 1: Caesar();break;	//	�������� 
			case 2: Virginia();break; 
			case 3: FangShe();break; 
            case 4: Hill();break;
			default:break; 
		}
	
}
void Caesar()		//��λ���� 
{
	char plaintext[MAX],ciphertext[MAX];	//�������Ķ��� 
	int temp;	//�洢�ַ�ת��Ϊ���ֵ��м�ֵ 
	int key,i,len;//���ĳ��ȡ���Կ���м�������� 
	cout << "����������(a ~ z) : " ;
	cin >> plaintext;
	len = strlen(plaintext);
	for(i = 0; i < len ; i++)	//���ĺϷ����ж� 
	{
		if(plaintext[i] < 97 || plaintext[i] > 122)
		{
			flag = 1;
		}

	}
	if (flag == 1) //���Ĳ��Ϸ� 
	{
		cout << "�����к��в��Ϸ�������ֵ����" << endl;
		return;
	}
	if (flag == 1) return;
	cout << "������Կ(0 ~ 25): ";
	cin >> key;
	if(key < 0 || key > 25) //��Կ���Ϸ� 
	{
		cout << "��Կ�к��в��Ϸ�������ֵ����" << endl;
		return;
	}
	for(i = 0; i < len ; i++ )	//���ܺ���ʵ�� 
	{
		temp = plaintext[i] - 'a' + key;//�����ַ�ת��Ϊ���ִ洢��temp���� 
		temp = temp%26;
		ciphertext[i] = temp + 'A';
	}
	
	cout << "����Ϊ: " <<plaintext << endl;
	cout << "��ԿΪ: " << key << endl;
	cout << "����Ϊ: ";
	for(i = 0; i < len; i++)
 	cout << ciphertext[i];
 	cout << endl;	
	
}
void DecipCaesar()	//������λ���� 
{
	char plaintext[MAX],ciphertext[MAX];//�������Ķ��壬ע������ֱ��ʹ�ü��ܲ��ִ���,���ĵ�����ζ������ ,��֮��Ȼ 
	int key,i,len,temp;//�������ĳ��ȼ�����м����Ķ���
	 
	cout << "����������(A ~ Z) : " ;
	cin >> plaintext;
	len = strlen(plaintext);
	for(i = 0; i < len ; i++)//���ĺϷ����ж� 
	{
		if(plaintext[i] < 65 || plaintext[i] > 90)
		{
			flag = 1;
		}

	}
		
	if (flag == 1) //���Ĳ��Ϸ�������ʾ�����˳� 
	{
		cout << "�����к��в��Ϸ�������ֵ����" << endl;
		return;
	}	cout << "������Կ(0 ~ 25): ";
	cin >> key;
	
		if(key < 0 || key > 25) //��Կ���Ϸ� 
	{
		cout << "��Կ�к��в��Ϸ�������ֵ����" << endl;
		return;
	}
	
	for(i = 0; i < len ; i++ )//���ܺ���ʵ�� 
	{
		temp = (plaintext[i] - 'A' - key)%26;	//����ת��Ϊ��ֵ�����м������� 
		if(temp < 0) temp = temp + 26;	//С��0�Ĵ��� 
		ciphertext[i] = temp + 'a';
	}
	
	cout << "����Ϊ: " <<plaintext << endl;
	cout << "��ԿΪ: " << key << endl;
	cout << "����Ϊ: ";
	for(i = 0; i < len; i++)
 	cout << ciphertext[i];
 	cout << endl;

}
void Virginia()		//ά���������� 
{
	char plaintext[MAX],ciphertext[MAX];//�������Ķ���
	int i,j,t,len_p,len_k,temp;//���ĳ��ȡ���Կ���ȼ��м�������� 
	char key[MAX];
	cout << "����������(a ~ z) : " ;
	cin >> plaintext;
	len_p = strlen(plaintext);
	for(i = 0; i < len_p ; i++)	//���ĺϷ��Լ��� 
	{
		if(plaintext[i] < 'a' || plaintext[i] > 'z')
		{
			flag = 1;
		}

	}
	if (flag == 1) //���Ϸ��˳��������沢������ʾ 
	{
		cout << "�����к��в��Ϸ�������ֵ����" << endl;
		return;
	}
	cout << "������Կ(a~z��ɵ��ַ���) : " ;
	cin >>key;
	 
	len_k = strlen(key);
	for(i = 0; i < len_k ; i++)	//��Կ�Ϸ��Լ��� 
	{
		if(key[i] < 'a' || key[i] > 'z')
		{
			flag = 1;
		}
	}
	
	if (flag == 1) //���Ϸ��˳��������沢������ʾ 
	{
		cout << "��Կ�к��в��Ϸ�������ֵ����" << endl;
		return;
	}
	
	for(i = 0; i < len_p ; i++ )	//���� 
	{
		j = i % len_k;//ͨ��ģ����ѭ��ѡ����Կ,Ҳ����ʹ��ѭ������ 
		t = key[j] - 'a';//��Կ����ֵ 
		temp = (plaintext[i] + t)%26; 
		ciphertext[i] = temp + 'A';
	}

	cout << "����Ϊ: " <<plaintext << endl;
	cout << "��ԿΪ: " << key << endl;
	cout << "����Ϊ: ";
	for(i = 0; i < len_p; i++)
 	cout << ciphertext[i];
 	cout << endl;
	
} 

void DecipVirginia()   //����ά���������� 
{
	char plaintext[MAX],ciphertext[MAX];//�������Ķ���,ע������ֱ��ʹ�ü��ܲ��ִ���,���ĵ�����ζ������ ,��֮��Ȼ 
	int i,j,t,len_p,len_k,temp;		//�м�������������ĳ��� 
	char key[MAX];
	cout << "����������(A ~ Z) : " ;
	cin >> plaintext;
	len_p = strlen(plaintext);	//��ȡ���ĳ��� 
	for(i = 0; i < len_p ; i++)	//�Ϸ��Լ��� 
	{
		if(plaintext[i] < 'A' || plaintext[i] > 'Z')
		{
			flag = 1;
		}

	}
	if (flag == 1) 
	{
		cout << "�����к��в��Ϸ�������ֵ����" << endl;
		return;
	}
	cout << "������Կ(a~z��ɵ��ַ���) : " ;
	cin >>key;
	len_k = strlen(key);
	
	for(i = 0; i < len_k ; i++)	//��Կ�Ϸ��Լ��� 
	{
		if(key[i] < 'a' || key[i] > 'z')
		{
			flag = 1;
		}
	}
	
	if (flag == 1) //���Ϸ��˳��������沢������ʾ 
	{
		cout << "��Կ�к��в��Ϸ�������ֵ����" << endl;
		return;
	}
	for(i = 0; i < len_p ; i++ )	//���ܺ���ʵ�� 
	{
		j = i % len_k;
		t = key[j] - 'A';
		temp = (plaintext[i] - t)%26;
		if(temp < 0) temp += 26;
		ciphertext[i] = temp + 'a';
	}

	cout << "����Ϊ: " <<plaintext << endl;
	cout << "��ԿΪ: " << key << endl;
	cout << "����Ϊ: ";
	for(i = 0; i < len_p; i++)
 	cout << ciphertext[i];
 	cout << endl;
	
}
void FangShe()	//��������
{
	char plaintext[MAX],ciphertext[MAX];	//���������������Ķ��� 
	int i,j,key,len,a,b,t;	//��Կ�����ĳ��ȼ��м�������� 
	cout << "����������(a ~ z) : " ;//�������� 
	cin >> plaintext;
	len = strlen(plaintext);//���ĳ��� 
	for(i = 0; i < len ; i++)//�Ϸ��Լ��� 
	{
		if(plaintext[i] < 'a' || plaintext[i] > 'z')
		{
			flag = 1;
		}

	}
	if (flag == 1) //���Ϸ������˳����� 
	{
		cout << "�����к��в��Ϸ�������ֵ����" << endl;
		return;
	}
	cout << "������Կ(0 ~ 25): \n";
	cout << "��Կ a = ";
	cin >> a;
	cout << "��Կ b = ";
	cin >> b;
    i = a;
    key = a;
    j = 26;
    while(i % j != 0)		//շת������ж�a��26���� 
        {
            t = i % j;
            i = j;
            j = t;
        }
    if(j != 1)
        {
            cout << "��Կ���벻���Ϲ���\n";
            return;
        }
	for(i = 0; i < len ; i++ )	//���ܹ��̺���ʵ�� 
	{
		t = (plaintext[i] - 'a');//�����ַ���ֵ������ 
		t = (a * t + b) % 26;
		ciphertext[i] = t + 'A';
	}
	
	cout << "����Ϊ: " <<plaintext << endl;
	cout << "��ԿΪ: a = "  << key << "  b = "  << b << endl;
	cout << "����Ϊ: ";
	for(i = 0; i < len; i++)
 	cout << ciphertext[i];
 	cout << endl;	
	
} 

void DecipherFangShe() 
{
	char plaintext[MAX],ciphertext[MAX];//�������Ķ���,ע��˴�ֱ�Ӹ��Ƽ��ܲ��ִ���,���ļ�λ���������,��֮��Ȼ 
	int key,i,j,len,a,b,t;	//��Կ���м�������� 
	cout << "����������(A �� Z) : " ;
	cin >> plaintext;	//�������� 
	len = strlen(plaintext);//���ĳ���
	 
	for(i = 0; i < len ; i++)	//���ĺϷ��Լ��� 
	{
		if(plaintext[i] < 'A' || plaintext[i] > 'Z')
		{
			flag = 1;
		}

	}
	if (flag == 1) //���Ϸ�����ֵ������ʾ������ 
	{
		cout << "�����к��в��Ϸ�������ֵ����" << endl;
		return;
	}
	cout << "������Կ(0 ~ 25): \n";
	cout << "��Կ a = ";
	cin >> a;
	cout << "��Կ b = ";
	cin >> b;
        i = a;
        key = a;
        j = 26;
        while(i % j != 0)	//�ж�a �Ƿ��26���� 
        {
            t = i % j;
            i = j;
            j = t;
        }
        if(j != 1)
        {
            cout << "��Կ���벻���Ϲ���\n";
            return;
        }
        for(i = 0; i < 1000; i++)	//a ���� 
        {
            if( ((a * i) % 26 ==1))break;
        }
        a = i;
	for(i = 0; i < len ; i++ )	//���ܹ��̺���ʵ�� 
	{
		t = (plaintext[i] - 'A');
		t = a * (t - b) % 26;
		while(t < 0) t = t + 26; 
		ciphertext[i] = t + 'a';
	}
	
	cout << "����Ϊ: " <<plaintext << endl;
	cout << "��ԿΪ: a = " << key << "  b = "  << b << endl;
	cout << "����Ϊ: ";
	for(i = 0; i < len; i++)
 	cout << ciphertext[i];
 	cout << endl;		
}
/*����Ϊ��������ʽֵ�ĵݹ麯��*/
int Fun( int n, int a[MAX][MAX] )
{
    int b[MAX][MAX] = {{0}};            /*��������b����ʼ��*/
    int i = 0, j = 0, sum = 0;          /*i��jΪ�����У�sumΪ����ʽ��ֵ*/
    int x = 0,c = 0,p=0;                /*��x�жϼ������c,pΪ�м����*/

    if(n == 1)
    return a[0][0];

    for(i = 0;i < n; i++)               /*�˴���ѭ��ʵ�ֽ�����ʽ��������b��*/
    {
        for(c = 0;c < n-1; c++)
        {
            for(j = 0;j < n-1;j++)
            {
                if (c < i){             /*����c�ж�ÿ�е��ƶ�����*/
                    p = 0;              /*��p=0ʱ������ʽֻ�����ƣ�����ȥ��Ӧ�ĵ�һ�е���*/
                }
                else{                   /*��������ʽ���ƺ�������*/
                    p = 1;
                }
            b[c][j] = a[c+p][j+1];
            }
        }

        if(i % 2 == 0){                  /*i+j����ʱj=0����ֻ����i��Ϊż�����ӷ�Ԥ��*/
            x = 1;
        }
        else{                           /*i+jΪ��������������*/
            x = (-1);
        }
     sum += a[i][0] * Fun(n - 1, b ) * x;         /*��������ʽ��ֵ*/
    }

    return sum;                                   /*��ֵ����*/
}
void Hill()     //ϣ���������
{
    char plaintext[MAX],ciptertext[MAX];//�������Ķ���
    int key[MAX][MAX] = {{0}};//��Կ���� 
    int i,j,k,m,n,t,len_p,len_c;//���ĳ��ȡ���Կ���ȼ��м�������� 
    int char2num[MAX];
    cout << "����������(a ����)�� ";
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
		cout << "�����к��в��Ϸ�������ֵ����" << endl;
		return;
	}
    cout << "������ϣ�����ܾ���:" << endl;
    cout << "�������m = ";
    cin >> m;
    n = m;
    for( i = 0; i < m ; i++)
    {
        cout << "��������" << i + 1<< "��Ԫ��: ";
        for(j = 0; j < n; j++)
        cin >> key[i][j];
    }
    t = Fun( n, key )%26;	//�����������ʽ
    //while(t < 0) t += 26;
    cout << "���������ʽ: " << t << endl;
    if(t == 0)
    {
		cout << "������ܾ�������Ƿ�������󣡣�\n";
		return;
	}
    len_c = 0;
    for(i = 0; i< len_p; i++)
    {
        char2num[i] =  plaintext[i] - 'a';	//�ַ�ת��Ϊ����
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
            //cout << "����" << t << endl;
            }
       // cout << "����--->" << t << endl;
        while(t < 0) t += 26;//ģ����
        ciptertext[m*i+k] = t%26 + 'A';//��������
        len_c++;
        }
    }
    
    cout << "����Ϊ: \n" << plaintext << endl;
    cout << "��ԿΪ; \n";
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%3d",key[i][j]);
        printf("\n");
    }
    cout << "����Ϊ: \n";
    for(j = 0; j < len_c; j++)
    cout << ciptertext[j];
    cout << "\n";
}
void BanSui(int a[MAX][MAX], int bansui[MAX][MAX], int n)		//����������
{
	int i,j,k,p,q;
	int b[MAX],c[MAX][MAX];
	for(i = 0; i < n; i++)	
		for(j = 0; j < n; j++)
		{
			k = 0;
			for(p  = 0; p < n; p++)
				for(q = 0; q < n; q++)	//����ʽ�洢��һά����
				{
					if(i == p) continue;
					if(j == q) continue;
					else b[k] = a[p][q];
					k++;
				}
			for(p = 0,k = 0; p < n - 1; p++)	//����ʽ���浽����
				for(q = 0; q < n - 1; q++)
				{
					c[p][q] = b[k];
					k++;
				}
				if( (i + j) % 2 == 1 )
			bansui[j][i] = 0-Fun(n - 1,c);//����ʽ���浽�������ÿ��λ��
                        else bansui[j][i] = Fun(n - 1,c);
		}
}

void DecipherHill() //����ϣ������
{
     char plaintext[MAX],ciptertext[MAX];
    int key[MAX][MAX] = {{0}},key1[MAX][MAX];
    int i,j,k,m,n,t,len_p,len_c,p;
    int char2num[MAX];
    cout << "����������(A ��Z)�� ";
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
		cout << "�����к��в��Ϸ�������ֵ����" << endl;
		return;
	}
    cout << "������ϣ�����ܾ���:" << endl;
    cout << "�������m = ";
    cin >> m;
    n = m;
    for( i = 0; i < m ; i++)		//��Կ�����¼��
    {
        cout << "��������" << i + 1<< "��Ԫ��: ";
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
		cout << "������ܾ�������Ƿ�������󣡣�\n";
		return;
	}		 
     for(i = 0; i < 1000; i++)	//����ܾ�������ʽ����
        {
            if( ((p * i) % 26 ==1))break;
        }
	k = i; 
	BanSui(key,key1,n);
     for(i = 0; i < m; i++)		//����ܾ��������
		 for(j = 0; j < m;j++)
			 key1[i][j] = ( k * key1[i][j]) % 26;
     for(i = 0; i < m; i++)		//��ģ���������
		 for(j = 0; j < m;j++)
		 while(key1[i][j] < 0)
		 key1[i][j] += 26;
			 
	cout << "���ܾ��������" << endl;
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
    
    cout << "����Ϊ: \n" << plaintext << endl;
    cout << "��ԿΪ; \n";
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%3d",key[i][j]);
        printf("\n");
    }
    cout << "����Ϊ: \n";
    for(j = 0; j < len_c; j++)
    cout << ciptertext[j];
    cout << "\n";   
}
void decipher() 
{
	int i;
	cout <<"-----------------------------------" << endl; 
	cout << " ��1��������λ����" << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " ��2������ά����������"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " ��3�����ܷ�������" << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " ��4������Hill����"  << endl;
	cout <<"-----------------------------------" << endl; 
	cout << " ��5������������" << endl;
	cout <<"-----------------------------------" << endl;
	cout << "ѡ�����������1~5��: " ; 
	
	cin >> i;
	switch(i) 
		{
			case 1: DecipCaesar();break;	//	��λ���� 
			case 2: DecipVirginia() ;break;
            case 3: DecipherFangShe();break;
			case 4: DecipherHill();break;
			default:cout << "�˳�" << endl; break; 
		}
	
}
int main()
{
	menu();
	int i;
	cout << "����Ҫ���еĲ�����1~5��: " ;
	cin >> i;
	while(i != 5)
	{
		switch(i) 
		{
			case 1:encryption();break;
			case 2:decipher();break;
			case 3:
			cout << "��������������version 1.1������������" << endl;
			cout << "�����������������¼�����������������" << endl;
			cout << "��������������ʧ����,���İɣ���������" << endl;
			break;
			case 4:
			cout << "----------------------------" <<endl;
			cout << " ����ϵ������Ա yeqinlao    \n" ;
			cout << "----------------------------" <<endl;
			cout << " 18856021939@163.com    \n" ;
			cout << "----------------------------" <<endl;
			cout << " ʹ���ֲἰԴ�����أ�        \n" ;
			cout << "----------------------------" <<endl;
			cout << " https://github.com/yefuyi/hello_world/tree/C \n" ;
			cout << "----------------------------" <<endl;
			break;
			default:cout << "�˳�" << endl; break; 
		}
		menu();
		cout << "\n ����Ҫ���еĲ�����1~5��: " ;
		cin >> i;
	}
	return 0;
};	


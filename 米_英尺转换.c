/* 米转化为英尺 */
#include<stdio.h>
float tran(float x);

int main()
{
	float x,y;			//定义两个实型变量
	printf("\nintput meter: ");  //输入提示
	scanf("%f",&x);
	y = tran(x);
	printf("\n%f trans into inch %f.\n",x,y);
	return 0;
}

float tran(float x){
	return x*3.2808;		//返回转化结果
}

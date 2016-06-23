# !/bin/sh
# output greeting
# 根据系统时间输出问候语 if-elif语句的使用
hour=$(date +%H)
if [ "$hour" -ge 0 -a "$hour" -le 11 ]
then
	echo "Good Morning!"
	elif [ "$hour" -ge 12 -a "$hour" -le 17 ]
	then
		echo "Good Afternoon"
	else
		echo "Good Evening"
fi

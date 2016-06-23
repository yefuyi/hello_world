# !/bin/sh
# Translate the number to English
if [ "$#" -ne 1 ]
then 
	echo "命令行输入参数不对， 使用方法： ./translate.sh 数字" # 输入参数个数不为1时提示出错信息并退出
	exit 1
fi
case "$1" in
	0) echo zero;;
	1) echo one;;
	2) echo two;;
	3) echo three;;
	4) echo four;;
	5) echo five;;
	6) echo six;;
	7) echo seven;;
	8) echo eight;;
	9) echo nine;;
	*) echo "输入参数错误， 请输入一位数字";;
esac

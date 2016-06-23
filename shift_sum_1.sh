# !/bin/sh
# 求命令行上所有整数之和
sum=0
until [ $# -eq 0 ]   #将条件判断的不等于“ -ne ”修改为等于 “ -eq ”
do
    let sum=sum+$1
    shift
done
echo "sum = $sum"
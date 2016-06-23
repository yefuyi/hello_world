# !/bin/sh
# 求命令行上的所有整数之和
sum=0
while [ $# -ne 0 ]
do
    let sum=sum+$1
    shift
done
echo "sum = $sum"
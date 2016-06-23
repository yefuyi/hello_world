# !/bin/sh
# 创建，删除文件，退出循环
cd /home/yeqinlao/文档/临时
while true
do
        echo -e "Select the operate: \n1         :Create one file;\n2           :Remove one file;\nother:Exit. "
        read select
        if [ $select=1 ]
        then 
                echo "Enter a filename to create: "
                read file
                if [ -e $file ]
                then 
                        echo "This is already existed."
                        continue
                else
                        touch $file
                        echo "Create file $file successful!"
                fi
        elif [ $select=2 ]
        then 
                echo "Enter a filename to remove: "
                read file
                if [ -e $file -a -f $file ]
                then 
                        rm $file
                        echo "removing file $file successful!"
                else
                echo "This file is not existed, or not a regular file. "
                continue
                fi
        else
                echo "progress will be existed, Yes or No?"
                read answer
                if [ answer= "Yes" ]
                then 
                        break
                else
                        continue
                fi
        fi
done
exit

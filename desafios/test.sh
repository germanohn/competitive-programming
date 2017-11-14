x=19
list = []

for a in range(19, 31):
    list.append(a)

for a in list:
do
    cd Aula$x
    let "x=$x+1"
    for i in a b c d;
    do
        if [ -f $i.cpp ]; then 
            if [ $i == 'a' ]; then
                mkdir ../9298340-batch3/9298340-A$a-PA
                cp $i.cpp ../9298340-batch3/9298340-A$a-PA
            elif [ $i == 'b' ]; then 
                mkdir ../9298340-batch3/9298340-A$a-PB
                cp $i.cpp ../9298340-batch3/9298340-A$a-PB
            elif [ $i == 'c' ]; then 
                mkdir ../9298340-batch3/9298340-A$a-PC
                cp $i.cpp ../9298340-batch3/9298340-A$a-PC
            elif [ $i == 'd' ]; then 
                mkdir ../9298340-batch3/9298340-A$a-PD
                cp $i.cpp ../9298340-batch3/9298340-A$a-PD
            fi
        fi
    done 
    cd ../
done 



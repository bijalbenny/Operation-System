//Student Details
echo "Enter your name:"
read name
echo "Enter your Semester"
read semester
echo "Enter your Batch:"
read batch
echo "Enter your RollNo:"
read rollNo
echo "Enter your RegNo:"
read regNo
echo -e "Name is $name\nSemester is $semester\n Batch is $batch\nRollNo is $rollNo\n RegNo is $regNo\n"

*******************************************************************

//Sum of 2 numbers

echo "Enter two numbers "
read num1
read num2
echo "Sum of $num1 and $num2 is $(($num1+$num2))"

******************************************************************

//Biggest among 2 numbers

echo "Enter two numbers "
read num1
read num2
if(($num1==$num2))
then
echo " Numbers are equal"
elif(($num1>$num2))
then 
echo "$num1 is greater"
else 
echo "$num2 is greater"
fi

********************************************************************

//first 10 natural  numbers

for((i=1;i<=10;i++))
do 
echo "$i"
done

*********************************************************************

//Factorial

echo "Enter Number"
read num
fact=1
for((i=1;i<=num;i++))
do 
fact=$(( $fact*$i ))
done
echo "factorial is $fact"

********************************************************************

//Fibonacci series

echo "Enter limit"
read limit
num1=0
num2=1
echo "Series is:"
echo "$num1"
echo "$num2"
num3=0
for((i=0;i<limit-2;i++))
do
num3=$(($num1+$num2))
echo "$num3"
num1=$num2
num2=$num3
done

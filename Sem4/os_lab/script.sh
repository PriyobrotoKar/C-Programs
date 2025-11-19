echo "Enter n:"
read n

if [ $((n%2))==0 ]
then
echo "Even"
else
echo "Odd"
fi

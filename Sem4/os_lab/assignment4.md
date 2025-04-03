## Assignment 4
`Submission Date: 3rd April 2025`

**Aim**: Write a Shell script to perform addition, subtraction, multiplication, division and modulus of two numbers.

**Commands**:
```bash
$ ls
Desktop Documents Downloads Music Pictures Videos priyobroto
```
```bash
$ cd priyobroto
```
```bash
$ touch add.sh
```
```bash
$ nano add.sh

a=20
b=10
sum=$((a+b))
sub=$((a-b))
mul=$((a*b))
div=$((a/b))
mod=$((a%b))
echo "Sum is: $sum"
echo "Subtraction is: $sub"
echo "Multiplication is: $mul"
echo "Division is: $div"
echo "Modulus is: $mod"
```
```bash
$ chmod +x add.sh
```
```bash
$ ./add.sh
Sum is: 30
Subtraction is: 10
Multiplication is: 200
Division is: 2
Modulus is: 0
```

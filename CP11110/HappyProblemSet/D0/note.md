## Compile

`g++ -std=c++17 -Wall -Wextra -fsanitize=address -g -O2 A.cpp -o A`

## IO

`./A <in.txt >out.txt`

## Timing

`time ./A.out <in.txt >out.txt`

## Compare Answer

`diff ans.txt out.txt`
`diff -Z ans.txt out.txt` (ignore OS difference \n \r)

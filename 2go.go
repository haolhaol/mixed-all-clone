// 判断 101-200 之间有多少个素数,并输出所有素数。
package main

import (
	"fmt"
	"math"
)

func main() {
	count := 0 //合数个数
	for m := 101; m <= 200; m++ {
		mid := int(math.Sqrt(float64(m)))
		for n := 2; n <= mid; n++ {
			if m%n == 0 {
				//fmt.Println(m)//符合条件的即为合数
				count = count + 1
				break
			}
		}
	}
	fmt.Println(100 - count)
}

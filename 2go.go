// �ж� 101-200 ֮���ж��ٸ�����,���������������
package main

import (
	"fmt"
	"math"
)

func main() {
	count := 0 //��������
	for m := 101; m <= 200; m++ {
		mid := int(math.Sqrt(float64(m)))
		for n := 2; n <= mid; n++ {
			if m%n == 0 {
				//fmt.Println(m)//���������ļ�Ϊ����
				count = count + 1
				break
			}
		}
	}
	fmt.Println(100 - count)
}

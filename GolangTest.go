package main

/* import package, u can use another type like import "fmt" */
import (
	"errors"
	"fmt"
)

/* A struct */
type person struct {
	name   string
	height uint32
}

/* Method of type person*/
func (p *person) printAll() {
	fmt.Println(p.name, p.height)
}
func (p *person) setAll() {
	p.name = "john"
	p.height = 321
}

/* A function return two values */
func makeDivision(a int32, b int32) (int32, error) {
	for i := 0; i < 5; i++ {
		defer fmt.Print(i, " ") /* defer意为不管如何，只要跳出函数就会执行。可以定义多个defer，后进先出(LIFO),即此例中先打印4 */
	}
	defer func(x string) { /* 匿名函数 */
		fmt.Print(x)
	}("Defer test:") /* 参数 */

	if b == 0 {
		return 0, errors.New("Division number zero!")
	}
	return a / b, nil
}

/* Test array and slice */
func testSlice() {
	var arr [10]int
	for i := 0; i < 10; i++ {
		arr[i] = i
	}

	sl := make([]int, 10) /* 创建一个拥有10个元素的切片 */
	sla := arr[3:5]       /* 对数组引用的切片 */
	fmt.Print("Test slice:")
	fmt.Println(arr)
}

/* The main */
func main() {
	//! test Method
	var pep person
	pep.setAll()
	pep.printAll()

	//! test function and multi return values
	var (
		a int32
		b error
	)
	a, b = makeDivision(101, 2)
	fmt.Println(a, b)

	//! test slice
	testSlice()
}

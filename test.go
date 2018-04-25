package main

import "fmt"
import "math"
import "errors"

func season(month int) string {
	switch month {
	case 12, 1, 2:
		return "winter"
	case 3, 4, 5:
		return "spring"
	case 6, 7, 8:
		return "summer"
	case 9, 10, 11:
		return "autumn"
	}
	return "unkown"
}

func for_loop(count int) {
	for ix := 0; ix < count; ix++ {
		fmt.Println(ix + 1)
	}
}

func goto_loop(count int) {
	ix := 0
retry:
	fmt.Println(ix + 1)
	ix++
	if ix < count {
		goto retry
	}
}

func bitwise_complement() {
	for ix := 0; ix < 11; ix++ {
		fmt.Printf("bitwise of %b is %b\n", ix, ^ix)
	}
}

func fizzbuzz() {
	for ix := 1; ix <= 100; ix++ {
		if ix%15 == 0 {
			fmt.Println("FizzBuzz")
		} else if ix%3 == 0 {
			fmt.Println("Fizz")
		} else if ix%5 == 0 {
			fmt.Println("Buzz")
		} else {
			fmt.Println(ix)
		}
	}
}

func test() {
	for i := 0; i < 5; i++ {
		var v int
		fmt.Printf("%d ", v)
	}
	/*for i := 0; ; i++ {
		fmt.Println(i)
	}*/
	s := ""
	for s != "aaaa" {
		fmt.Println(s)
		s = s + "a"
	}
	for i, j, s := 0, 5, "a"; i < 3 && j < 100 && s != "aaaaa"; i, j, s = i+1, j+1, s+"a" {
		fmt.Println(i, j, s)
	}
}

func continue_label() {
LABEL1:
	for i := 0; i <= 5; i++ {
		for j := 0; j <= 5; j++ {
			if j == 4 {
				continue LABEL1
			}
			fmt.Printf("i is: %d, and j is: %d\n", i, j)
		}
	}
}

func for_break() {
	i := 0
	for { //since there are no checks, this is an infinite loop
		if i >= 3 {
			break
		}
		//break out of this for loop when this condition is met
		fmt.Println("Value of i is:", i)
		i++
	}
	fmt.Println("A statement just after for loop.")
}

func for_confinue() {
	for i := 0; i < 7; i++ {
		if i%2 == 0 {
			continue
		}
		fmt.Println("Odd:", i)
	}
}

func Pop(st []int) int {
	v := 0
	for ix := len(st) - 1; ix >= 0; ix-- {
		if v = st[ix]; v != 0 {
			st[ix] = 0
			return v
		}
	}
	return -100
}

func mult_returnval1(a int, b int) (int, int, int) {
	return a + b, a - b, a * b
}

func mult_returnval2(a int, b int) (ret1, ret2, ret3 int) {
	ret1 = a + b
	ret2 = a - b
	ret3 = a * b
	return
}

func Mysqrt1(f float64) (float64, error) {
	if f < 0 {
		return float64(math.NaN()), errors.New("I won't be able to do a sqrt to negtive number!")
	}
	return math.Sqrt(f), nil
}

func Mysqrt2(f float64) (sqrt float64, e error) {
	if f < 0 {
		sqrt, e = float64(math.NaN()), errors.New("I won't be able to do a sqrt to negtive number!")
	} else {
		sqrt, e = math.Sqrt(f), nil
	}
	return
}

func varargs(values ...interface{}) {
	for _, value := range values {
		switch v := value.(type) {
		case int:
			fmt.Printf("type %T with value %v\n", v, v)
		case float64:
			fmt.Printf("type %T with value %v\n", v, v)
		case string:
			fmt.Printf("type %T with value %v\n", v, v)
		case bool:
			fmt.Printf("type %T with value %v\n", v, v)
		default:
			fmt.Printf("type %T with value %v\n", v, v)
		}
	}
}

func fib(n int) (ret, index int) {
	var ret1, ret2 int
	if n <= 1 {
		ret = 1
	} else {
		ret1, _ = fib(n - 1)
		ret2, _ = fib(n - 2)
		ret = ret1 + ret2
	}
	index = n
	return
}

func fact(n int) (ret int) {
	if n <= 1 {
		ret = 1
	} else {
		ret = n * fact(n-1)
	}
	return
}

func closure() func(s1 string) {
	g := func(s1 string) {
		fmt.Println(s1)
	}
	return g
}

func fib1(n int) (fibN, index int) {
	fibN_1, fibN_2 := 1, 1
	index = n
	if n <= 1 {
		fibN = 1
	} else {
		for ; n > 1; n-- {
			fibN = fibN_1 + fibN_2
			fibN_2 = fibN_1
			fibN_1 = fibN
		}
	}
	return
}
func main() {
	//var month int
	//fmt.Scanf("%d", &month)
	//fmt.Println(season(month))
	//for_loop(15)
	//goto_loop(15)
	//bitwise_complement()
	//fizzbuzz()
	//test()
	//continue_label()
	//for_break()
	//for_confinue()
	//fmt.Println(mult_returnval1(4, 2))
	//fmt.Println(mult_returnval2(4, 2))
	//a := [...]int{1, 2, 3}
	//varargs(a[:], 1, 2, "hi")
	//fmt.Println(Mysqrt2(-1))
	//fmt.Println(Mysqrt2(100))
	//fmt.Println(fib(5))
	//fmt.Println(fib(10))
	//fmt.Println(fact(5))
	//f := closure()
	//f("hello")
	//fmt.Println(fib1(5))
	//fmt.Println(fib1(10))

}

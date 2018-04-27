package main

import "fmt"
import "math"
import "errors"
import "container/list"
import "unsafe"
import "regexp"
import "strconv"
import "math/big"
import "reflect"

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

func item_change() {
	items := [...]int{10, 20, 30, 40, 50}
	for index, item := range items {
		//item *= 2
		items[index] = item * 2
	}
	fmt.Println(items)
}

func sum_arr(arr [5]int) (sum int, average float32) {
	length := len(arr)
	for ix := 0; ix < length; ix++ {
		sum += arr[ix]
	}
	average = ((float32)(sum)) / ((float32)(length))
	return
}

func get_max_min(arr []int) (max int, min int) {
	max = arr[0]
	min = arr[0]
	length := len(arr)
	for ix := 1; ix < length; ix++ {
		if arr[ix] > max {
			max = arr[ix]
		}
		if arr[ix] < min {
			min = arr[ix]
		}
	}
	return
}

func split_str(str string, i int) (str1, str2 string) {
	if len(str) < i {
		fmt.Printf("Error index %d\n", i)
	} else {
		str1 = str[:i]
		str2 = str[i:]
	}
	return
}

func reverse_slice(slice1 []byte) (slice2 []byte) {
	length := len(slice1)
	var tmp byte
	//for ix := 0; ix < length/2; ix++ {
	for ix := 0; ix < length/2; ix++ {
		//fmt.Println(slice1[length-ix])
		tmp = slice1[ix]
		slice1[ix] = slice1[length-1-ix]
		slice1[length-1-ix] = tmp
	}
	slice2 = slice1
	return
}

func reverse_slice2(slice1 *[]byte) {
	length := len(*slice1)
	var tmp byte
	//for ix := 0; ix < length/2; ix++ {
	for ix := 0; ix < length/2; ix++ {
		//fmt.Println(slice1[length-ix])
		tmp = (*slice1)[ix]
		(*slice1)[ix] = (*slice1)[length-1-ix]
		(*slice1)[length-1-ix] = tmp
	}
}

func mapFunc(slice1 []int, g func(int) int) (slice2 []int) {
	length := len(slice1)
	for ix := 0; ix < length; ix++ {
		slice2 = append(slice2, g(slice1[ix]))
	}
	return
}

func g(a int) int {
	return a * 10
}

func test_map() {
	var value int
	var isPresent bool

	map1 := make(map[string]int)
	map1["New Delhi"] = 55
	map1["Beijing"] = 20
	map1["Washingtong"] = 25
	value, isPresent = map1["Beijing"]

	if isPresent {
		fmt.Printf("The value of \"Beijing\" in map1 is: %d\n", value)
	} else {
		fmt.Println("map1 does not contain Beijing")
	}
	value, isPresent = map1["Paris"]
	fmt.Printf("Is \"Paris\" in map1 ?: %t\n", isPresent)
	fmt.Printf("Value is: %d\n", value)

	delete(map1, "Washingtong")
	value, isPresent = map1["Washingtong"]
	if isPresent {
		fmt.Printf("The value of \"Washingtong\" in map1 is %d\n", value)
	} else {
		fmt.Println("map1 does not contain Washingtong")
	}
}

func test_map2() {
	//map1 := make(map[string]int)
	map1 := map[string]int{"Monday": 1, "Tuesday": 2, "Wednesday": 3, "Thursday": 4, "Friday": 5, "Saturday": 6, "Sunday": 7}
	var value int
	var isPresent bool

	value, isPresent = map1["Tuesday"]
	if isPresent {
		fmt.Printf("The value of \"Tuesday\" in map1 is: %d\n", value)
	} else {
		fmt.Println("map1 does not contain Tuesday")
	}
	value, isPresent = map1["Holiday"]
	if isPresent {
		fmt.Printf("The value of \"Holiday\" in map1 is: %d\n", value)
	} else {
		fmt.Println("map1 does not contain Holiday")
	}
}

func slice_map() {
	items := make([]map[int]int, 5)
	for i := range items {
		items[i] = make(map[int]int, 1)
		items[i][1] = 2
	}
	fmt.Printf("Version A: Value of items: %v\n", items)

	items2 := make([]map[int]int, 5)
	for _, item := range items2 {
		item = make(map[int]int, 1)
		item[1] = 2
	}
	fmt.Printf("Version B: Value of items: %v\n", items2)
}

func revert_slice() {
	barVal := map[string]int{"alpha": 34, "bravo": 56, "charlie": 23,
		"delta": 87, "echo": 56, "foxtrot": 12,
		"golf": 34, "hotel": 16, "indio": 87,
		"juliet": 65, "kili": 43, "lima": 98}
	invMap := make(map[int]string, len(barVal))
	for k, v := range barVal {
		invMap[v] = k
	}
	fmt.Println("inverted:")
	for k, v := range invMap {
		fmt.Printf("Key: %v, Value: %v / ", k, v)
	}
}

func test_list() {
	l := list.New()
	for i := 0; i < 5; i++ {
		l.PushBack(i)
	}
	for e := l.Front(); e != nil; e = e.Next() {
		fmt.Printf("%d\t", e.Value)
	}
	fmt.Println("")
	fmt.Println(l.Front().Value)
	fmt.Println(l.Back().Value)
	l.InsertAfter(6, l.Front())
	for e := l.Front(); e != nil; e = e.Next() {
		fmt.Printf("%d\t", e.Value)
	}

	fmt.Println("")
	l.MoveBefore(l.Front().Next(), l.Front())
	for e := l.Front(); e != nil; e = e.Next() {
		fmt.Printf("%d\t", e.Value)
	}
	fmt.Println("")
	l.MoveToFront(l.Back())
	for e := l.Front(); e != nil; e = e.Next() {
		fmt.Printf("%d\t", e.Value)
	}
	fmt.Println("")
}

type Person struct {
	name string
	age  int32
}

func test_unsafe() {
	i := 1
	size := unsafe.Sizeof(i)
	fmt.Println(i, size)

	pi := &i
	size = unsafe.Sizeof(*pi)
	fmt.Println(*pi, size)

	p := &Person{name: "abcdsjdksm.sm", age: 20}
	size = unsafe.Sizeof(*p)
	fmt.Printf("%p %v %d\n", p, p, size)

	by := (*[1024]byte)(unsafe.Pointer(p))
	fmt.Printf("unsafe取址：%p\n", unsafe.Pointer(p))
	fmt.Printf("结构体取址:%p\n", p)
	p1 := (*Person)(unsafe.Pointer(p))
	p2 := (*Person)(unsafe.Pointer(by))
	fmt.Println(p1.age)
	fmt.Println(p2.age)
	//偏移量取值
	fmt.Println("nameSize：", unsafe.Sizeof(p.name))
	fmt.Println("ageSize：", unsafe.Sizeof(p.age))
	fmt.Println("nameAlignof：", unsafe.Alignof(p.name))
	fmt.Println("ageAlignof：", unsafe.Alignof(p.age))
	fmt.Println("name偏移量：", unsafe.Offsetof(p.name))
	fmt.Println("age偏移量：", unsafe.Offsetof(p.age))
	fmt.Println("name:", *(*string)(unsafe.Pointer(p)))
	fmt.Println("age:", *(*uint32)(unsafe.Pointer(uintptr(unsafe.Pointer(p)) + unsafe.Offsetof(p.age))))
}

func patterns_test() {
	searchIn := "John: 2578.34 William: 4567.23 Steve: 5632.18"
	pat := "[0-9]+.[0-9]+"

	f := func(s string) string {
		v, _ := strconv.ParseFloat(s, 32)
		return strconv.FormatFloat(v*2, 'f', 2, 32)
	}

	if ok, _ := regexp.Match(pat, []byte(searchIn)); ok {
		fmt.Println("Match found")
	}

	re, _ := regexp.Compile(pat)
	str := re.ReplaceAllString(searchIn, "##.#")
	fmt.Println(str)

	str2 := re.ReplaceAllStringFunc(searchIn, f)
	fmt.Println(str2)
}

func test_big() {
	im := big.NewInt(math.MaxInt64)
	in := im
	io := big.NewInt(1956)
	ip := big.NewInt(1)
	ip.Mul(im, in).Add(ip, im).Div(ip, io)

	fmt.Printf("Big Int:%v\n", ip)

	rm := big.NewRat(math.MaxInt64, 1956)
	rn := big.NewRat(-1956, math.MaxInt64)
	ro := big.NewRat(19, 56)
	rp := big.NewRat(1111, 2222)
	rq := big.NewRat(1, 1)
	rq.Mul(rm, rn).Add(rq, ro).Mul(rq, rp)
	fmt.Printf("Big Rat: %v\n", rq)
}

type TagType struct {
	field1 bool   "an important answer"
	field2 string "The name of the thing"
	field3 int    "How much there are"
}

func refTag(tt TagType, ix int) {
	ttType := reflect.TypeOf(tt)
	ixField := ttType.Field(ix)
	fmt.Printf("%v\n", ixField.Tag)
}

func test_reflect() {
	tt := TagType{true, "Barak Obama", 1}
	for i := 0; i < 3; i++ {
		refTag(tt, i)
	}
}

type inners struct {
	in1 int
	in2 int
}

type outers struct {
	b int
	c float32
	int
	inners
}

func anonymous_fields() {
	outer := new(outers)
	outer.b = 6
	outer.c = 7.5
	outer.int = 60
	outer.in1 = 5
	outer.in2 = 10

	fmt.Printf("outer.b is %d\n", outer.b)
	fmt.Printf("outer.c is %f\n", outer.c)
	fmt.Printf("outer.int is %d\n", outer.int)
	fmt.Printf("outer.in1 id %d\n", outer.in1)
	fmt.Printf("outer.in2 is %d\n", outer.in2)

	outer2 := outers{6, 7.5, 60, inners{5, 10}}
	fmt.Println("outer2 is:", outer2)
}

type A struct {
	ax, ay int
}

type B struct {
	A
	bx, by float32
}

func embeded_struct() {
	b := B{A{1, 2}, 3.0, 4.0}
	fmt.Println(b.ax, b.ay, b.bx, b.by)
	fmt.Println(b.A)
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
	//item_change()
	//arr := [5]int{1, 2, 3, 4, 6}
	//fmt.Println(sum_arr(arr))
	//fmt.Println(get_max_min(arr[:]))
	//fmt.Println(arr[4:4])
	//fmt.Println(arr[4:5])
	//str := "Hello, world."
	//str := "Google"
	//data := []byte(str)
	//fmt.Println(split_str(str, 5))
	//fmt.Println(split_str(str, 50))
	//fmt.Println(str[len(str)/2:] + str[:len(str)/2])
	//fmt.Println(string(reverse_slice(data[:])))
	//reverse_slice2(&data)
	//fmt.Println(string(data))
	//fmt.Println(str)
	//a := [...]int{1, 2, 3, 4, 5}
	//fmt.Println(mapFunc(a[:], g))
	//test_map()
	//test_map2()
	//slice_map()
	//test_list()
	//test_unsafe()
	//patterns_test()
	//test_big()
	//test_reflect()
	anonymous_fields()
	embeded_struct()
}

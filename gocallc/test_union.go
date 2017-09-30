package main

import (
	"fmt"
)

// #include <stdio.h>
// union bar {
//        char   c;
//        int    i;
//        double d;
// };
import "C"

func main() {
	var b *C.union_bar = new(C.union_bar)
	//b.c undefined (type *[8]byte has no field or method c
	//从报错的信息来看，Go对待union与其他类型不同，似乎将union当成[N]byte来对待，其中N为union中最大字段的size(圆整后的)，因此我们可以按如下方式处理C.union_bar：
	//b.c = 4
	b[0] = 13
	b[1] = 17
	fmt.Println(b)
}

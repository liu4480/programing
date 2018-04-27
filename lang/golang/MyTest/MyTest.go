package MyTest

import "fmt"

func isOdd() {
	for ix := 1; ix <= 100; ix++ {
		if ix&1 == 1 {
			fmt.Printf("%d is odd\n", ix)
		} else {
			fmt.Printf("%d is even\n", ix)
		}
	}
}

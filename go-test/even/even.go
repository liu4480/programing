package even

func Even(i int) bool {
	return ((i & 1) == 0)
}

func Odd(i int) bool {
	return ((i & 1) == 1)
}

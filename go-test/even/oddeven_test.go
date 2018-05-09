package even

import "testing"
import "even"

func TestEven(t *testing.T) {
	if !even.Even(10) {
		t.Log(" 10 must be even!")
		t.Fail()
	}
	if even.Even(7) {
		t.Log(" 7 must not be even!")
		t.Fail()
	}
}

func TestOdd(t *testing.T) {
	if !even.Odd(11) {
		t.Log(" 11 must be odd!")
		t.Fail()
	}
	if even.Odd(10) {
		t.Log(" 10 must not be odd!")
		t.Fail()
	}
}

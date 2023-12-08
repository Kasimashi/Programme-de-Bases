package main

import (
	"errors"
	"fmt"
)

func main() {
	result, err := divide(10.0, 0)

	if err != nil {
		panic(err)
	}

	fmt.Println(result)
}

func divide(a, b float32) (float32, error) {
	if b == 0 {
		return 0, errors.New("Impossible de diviser par zero")
	}

	return a / b, nil
}

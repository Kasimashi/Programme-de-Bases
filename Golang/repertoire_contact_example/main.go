package main

import (
	"fmt"
)

func main() {
	myContact := newContact("Alex", 30,
		map[string]string{
			"Fixe":     "+33929319381",
			"Portable": "+33629319381",
		})
	fmt.Println(myContact)
	fmt.Println(myContact.displayContact())
}

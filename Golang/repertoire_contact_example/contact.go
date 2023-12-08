package main

import (
	"fmt"
)

type Contact struct {
	name  string
	age   int
	phone map[string]string
}

func newContact(name string, age int, number map[string]string) Contact {
	c := Contact{
		name:  name,
		age:   age,
		phone: number,
	}

	return c
}

// On associe la fonction au type Contact (Programmation orientée objet)
// fmt.Println(myContact.displayContact())
func (c Contact) displayContact() string {
	display := fmt.Sprintf("Contact :%v (%v ans)\n", c.name, c.age)
	for key, value := range c.phone {
		display += fmt.Sprintf("%v %v\n", key+":"+value)
	}
	display += "-------------\n"

	return display
}

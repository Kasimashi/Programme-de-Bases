package main

import (
	"encoding/json"
	"fmt"
)

type User struct {
	Name  string `json:"name"`
	Age   int    `json:"age"`
	Email string `json:"email"`
	Phone string `json:"phone"`
}

func main() {
	jsonFromApi := `
[
    {
        "age": 30,
        "email": "foogmail@gmail.com",
        "name": "Alex",
        "phone": "+33000230223"
    },
    {
        "age": 31,
        "email": "georgegmail@gmail.com",
        "name": "George",
        "phone": "+33100230223"
    }
]`

	var users []User

	err := json.Unmarshal([]byte(jsonFromApi), &users)
	if err != nil {
		fmt.Println("Error unmarshal json :", err)
	}
	fmt.Println(users)

	var MyStruct []User
	var new_user User
	new_user.Name = "Pierre"
	new_user.Email = "pierre@gmail.com"
	new_user.Age = 31
	new_user.Phone = "+333333333333"

	MyStruct = append(MyStruct, new_user)
	// Add two time the user
	MyStruct = append(MyStruct, new_user)

	// We can use Marshal but MarshalIndent is used for indent data in output.
	// jsonFromSlice, err := json.Marshal(MyStruct)
	jsonFromSlice, err := json.MarshalIndent(MyStruct, "", " ")
	if err != nil {
		fmt.Println("Error marshal json :", err)
	}

	// It return a array of bytes need to convert to string to be human readable
	fmt.Println(string(jsonFromSlice))

	/*
	 {
	  "name": "Pierre",
	  "age": 31,
	  "email": "pierre@gmail.com",
	  "phone": "+333333333333"
	 },
	 {
	  "name": "Pierre",
	  "age": 31,
	  "email": "pierre@gmail.com",
	  "phone": "+333333333333"
	 }

	*/

}

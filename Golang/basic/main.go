package main

import (
	"fmt"
	"math/rand"
) // Bibliothéque standard d'entrée sortie Golang

var global_var int

// Example structure
type Example struct {
	a string
	b int
	c bool
}

func main() {
	var x int // Déclaration de la variable x en tant qu'entier
	x = 15

	fmt.Printf("Mon nombre x est %v\n", x)
	y := 16 // Déclaration automatique de la variable y en tant qu'entier et affectation

	fmt.Printf("Mon nombre y est %v\n", y)

	z := true

	fmt.Printf("Mon booléen est %v\n", z)

	a := "Helllllllllllllloooooooooo" // Déclaration automatique de la variable z en tant que string et affectation

	fmt.Printf("Ma chaine de character est %v\n", a)

	// Multiple déclaration de b,c,d de différent types
	var (
		b bool
		c uint8
		d string
	)

	b = true
	c = 21
	d = "Coucou"

	fmt.Printf("%v,%v,%v\n", b, c, d)

	// Ici on déclarage e en tant d'entier et on vérifie si ce dernier est pair
	if e := rand.Int(); e%2 == 0 {
		fmt.Println("e est un nombre pair")
	} else {
		fmt.Println("e est un nombre impair")
	}

	f := rand.Int() % 2
	if f == 0 {
		fmt.Println("f est un nombre pair")
	} else {
		fmt.Println("f est un nombre impair")
	}

	for i := 0; i < 5; i++ {
		fmt.Println(i)
	}

	g := 0
	for g < 5 {
		fmt.Println(g)
		g++
	}

	h := 0
	for {
		if h > 5 {
			break
		}
		fmt.Println(h)
		h++
	}

	// Afficher seulement les chiffres pair
	j := 0
	for ; j <= 10; j++ {
		if j%2 == 0 {
			continue
		}
		fmt.Println(j)
	}

	// Déclaration d'une liste de taille 2 : tableau d'entier
	var list [2]int
	list[0] = 10
	list[1] = 20

	newList := [...]int{40, 50}
	fmt.Println(newList)
	fmt.Println(newList[0])

	bigList := [...]int{40, 50, 50, 50, 50, 50, 50, 20, 50, 50, 50}

	for k, v := range bigList {
		fmt.Printf("Position %d est égal à %d.\n", k, v)
	}

	global_var = 1
	fmt.Println(global_var)
	sayHello("Didier")
	fmt.Println(global_var)

	// Map : similaire aux dictionnaires en python/javascript
	supermarketPrice := map[string]int{
		"petitPrince": 8, // Clée / Valeur
		"eau":         2,
		"meat":        6,
	}

	fmt.Println(supermarketPrice["petitPrince"])

	for key, value := range supermarketPrice {
		fmt.Println(key, value)
	}

	// Fonction anonyme : analogue à void en C
	w := func() {
		println("Je suis une fonction anonyme sans return.")
	}

	w()

	// n est du type string , elle est affecté au niveau du return.
	n := func() string {
		println("Je suis une fonction anonyme")
		return "Alex"
	}()

	println(n)

	// Fonction qui retourne plusieurs valeurs
	q, s := func() (int, int) {
		println("Aucun paramètre, Deux returns")
		return 5, 7
	}()

	println(q)
	println(s)

	func(a, b int) {
		println("Q*Q + S*S = ", q*q+s*s)
	}(q, s)

	//Println
	mon_nombre, mon_nombre_2 := 1, 4
	fmt.Printf("Salut à tous\n")
	fmt.Printf("Mon nombre (default) est %v\n", mon_nombre)
	fmt.Printf("Mon nombre (base 2) est %v\n", mon_nombre)
	fmt.Printf("Mon nombre (base 8) est %v\n", mon_nombre)
	fmt.Printf("Mon nombre (base 10) est %v\n", mon_nombre)
	fmt.Printf("Mon nombre (base 16) est %v\n", mon_nombre)
	fmt.Printf("(Bool)La valeur de mon nombre est égale à a valeur de mon nombre 2 -> %t\n", mon_nombre > mon_nombre_2)
	fmt.Printf("L'écriture scientifique de mon nombre est %E\n", 3.1492882381388181)

	A := 5
	updateA(A)
	println(A) // 5

	A = updateA_ref(A)
	println(A) // 10

	groceryList := map[string]int{
		"prince": 6,
		"viande": 10,
	}

	updateB(groceryList)
	fmt.Println(groceryList) // map[bonbon:5 prince:6 viande:10]

	// Pointeur
	mon_nombre_3 := 99
	fmt.Println(mon_nombre_3)
	// 10
	fmt.Println("Addresse mémoire de mon_nombre_3", &mon_nombre_3) // Addresse mémoire de mon_nombre_3 0xc00000a1a8

	My_pointer := &mon_nombre_3
	fmt.Println("Addresse mémoire de ma variable %v et sa valeur est %v", My_pointer, *My_pointer)

	MyExample := Example{
		a: "Alex",
		b: 30,
		c: true,
	}

	fmt.Println(MyExample)

	fooExample := Example{"Alexs", 30, true}
	fmt.Println(fooExample)

}

func sayHello(name string) {
	fmt.Println("Bonjour à toi", name)
	global_var = 0
}

func updateA(number int) {
	number = 10
}

func updateA_ref(number int) int {
	number = 10
	return number
}

func updateB(item map[string]int) {
	item["bonbon"] = 5
}

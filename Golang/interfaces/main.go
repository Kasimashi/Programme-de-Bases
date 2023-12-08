/*
Le bruit de cet animal est :  Miaou
Il a tant de jambes :  4
Le bruit de cet animal est :  SSSSSSSS
Il a tant de jambes :  8
*/

package main

import "fmt"

// Une interface est une suite de fonction que ce type doit avoir
// Exemple
type Animal interface {
	Noise() string     // Which noise this animal produce
	NumberOfLegs() int //Now many leg he have
}

type Cat struct {
	Name   string
	Espece string
}

type Spider struct {
	Name      string
	Espece    string
	Venimeuse bool
}

func main() {
	cat := Cat{
		Name:   "Kitty",
		Espece: "Siamois",
	}

	PrintAnimalInfo(&cat)

	spider := Spider{
		Name:      "Spiddy",
		Espece:    "Veuve noire",
		Venimeuse: true,
	}

	PrintAnimalInfo(&spider)
}

func PrintAnimalInfo(a Animal) {
	fmt.Println("Le bruit de cet animal est : ", a.Noise())
	fmt.Println("Il a tant de jambes : ", a.NumberOfLegs())
}

// Création de l'interface : TOUT LES CHATS FONT MIAOU et on QUATRE PATTES (normalement)
func (c *Cat) Noise() string {
	return "Miaou"
}

func (c *Cat) NumberOfLegs() int {
	return 4
}

// Création de l'interface : TOUT LES SPIDER FONT SSSSS et on QUATRE PATTES (normalement)
func (c *Spider) Noise() string {
	return "SSSSSSSS"
}

func (c *Spider) NumberOfLegs() int {
	return 8
}

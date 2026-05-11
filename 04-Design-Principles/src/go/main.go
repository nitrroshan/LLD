// Chapter 04 — Design Principles in Go
// Go has no inheritance at all — composition is the only way
// Run: go run .

package main

import "fmt"

func main() {
	fmt.Println("=== Composition over Inheritance ===\n")

	knight := NewGameCharacter("Arthur", SwordWeapon{}, WalkMovement{})
	knight.Attack()
	knight.DoMove()

	fmt.Println()
	mage := NewGameCharacter("Gandalf", MagicWeapon{}, TeleportMovement{})
	mage.Attack()
	mage.DoMove()

	fmt.Println("\n--- Runtime Swap ---")
	fmt.Printf("%s picks up a bow and learns to fly!\n\n", knight.Name)
	knight.Weapon = BowWeapon{}
	knight.Movement = FlyMovement{}
	knight.Attack()
	knight.DoMove()
}

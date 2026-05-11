package main

import "fmt"

// Go naturally favors composition — interfaces are implicit, embedding is composition

type WeaponBehavior interface {
	Attack(name string)
}

type SwordWeapon struct{}
func (SwordWeapon) Attack(name string) { fmt.Printf("%s swings a sword!\n", name) }

type BowWeapon struct{}
func (BowWeapon) Attack(name string) { fmt.Printf("%s shoots an arrow!\n", name) }

type MagicWeapon struct{}
func (MagicWeapon) Attack(name string) { fmt.Printf("%s casts a fireball!\n", name) }

package main

import "fmt"

type MovementBehavior interface {
	Move(name string)
}

type WalkMovement struct{}
func (WalkMovement) Move(name string) { fmt.Printf("%s walks.\n", name) }

type FlyMovement struct{}
func (FlyMovement) Move(name string) { fmt.Printf("%s flies!\n", name) }

type TeleportMovement struct{}
func (TeleportMovement) Move(name string) { fmt.Printf("%s teleports!\n", name) }

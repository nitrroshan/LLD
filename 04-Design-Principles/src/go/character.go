package main

type GameCharacter struct {
	Name     string
	Weapon   WeaponBehavior
	Movement MovementBehavior
}

func NewGameCharacter(name string, weapon WeaponBehavior, movement MovementBehavior) *GameCharacter {
	return &GameCharacter{Name: name, Weapon: weapon, Movement: movement}
}

func (c *GameCharacter) Attack()   { c.Weapon.Attack(c.Name) }
func (c *GameCharacter) DoMove()   { c.Movement.Move(c.Name) }

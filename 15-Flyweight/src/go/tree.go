package main

// Tree is the Context — stores extrinsic (unique) state (x, y) plus a
// pointer to a shared TreeType flyweight.
type Tree struct {
	x    int
	y    int
	kind *TreeType
}

func (t *Tree) Draw() {
	t.kind.Draw(t.x, t.y)
}

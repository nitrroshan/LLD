package main

// Forest is the Client — plants many trees. Each Tree holds only its
// position; the heavy shared data lives once per TreeType in the factory.
type Forest struct {
	trees   []*Tree
	factory *TreeFactory
}

func NewForest() *Forest {
	return &Forest{factory: NewTreeFactory()}
}

func (f *Forest) PlantTree(x, y int, name, color, texture string) {
	kind := f.factory.GetTreeType(name, color, texture)
	f.trees = append(f.trees, &Tree{x: x, y: y, kind: kind})
}

func (f *Forest) Draw() {
	for _, tree := range f.trees {
		tree.Draw()
	}
}

func (f *Forest) TreeCount() int         { return len(f.trees) }
func (f *Forest) DistinctTypeCount() int { return f.factory.DistinctTypeCount() }

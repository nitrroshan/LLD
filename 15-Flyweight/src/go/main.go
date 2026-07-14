package main

import "fmt"

func main() {
	fmt.Println("=== Flyweight Pattern Demo (Go) ===")
	fmt.Println()

	forest := NewForest()

	// Plant 1,000,000 trees, but only 3 distinct types
	fmt.Println("Planting 1,000,000 trees...")
	species := [][3]string{
		{"Oak", "Green", "oak.png"},
		{"Pine", "DarkGreen", "pine.png"},
		{"Cherry", "Pink", "cherry.png"},
	}

	for i := 0; i < 1000000; i++ {
		s := species[i%len(species)]
		forest.PlantTree(i%800, i%600, s[0], s[1], s[2])
	}

	fmt.Println()
	fmt.Println("Result:")
	fmt.Printf("  Trees planted:        %d\n", forest.TreeCount())
	fmt.Printf("  Distinct TreeTypes:   %d\n", forest.DistinctTypeCount())
	fmt.Printf("  Memory saved: 1,000,000 contexts share only %d heavy flyweight objects.\n",
		forest.DistinctTypeCount())

	// Draw a few sample trees to show extrinsic state passed in
	fmt.Println()
	fmt.Println("--- Sample draws ---")
	sample := NewForest()
	sample.PlantTree(10, 20, "Oak", "Green", "oak.png")
	sample.PlantTree(35, 40, "Pine", "DarkGreen", "pine.png")
	sample.PlantTree(50, 12, "Oak", "Green", "oak.png") // reuses the Oak flyweight
	sample.Draw()
}

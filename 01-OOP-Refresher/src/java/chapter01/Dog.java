package chapter01;

public class Dog extends Animal {
    private String breed;

    public Dog(String name, String breed) {
        super(name);
        this.breed = breed;
    }

    public String getBreed() {
        return breed;
    }

    @Override
    public void makeSound() {
        System.out.println(getName() + " says Woof! [" + breed + "]");
    }

    public void fetch() {
        System.out.println(getName() + " fetches the ball!");
    }
}

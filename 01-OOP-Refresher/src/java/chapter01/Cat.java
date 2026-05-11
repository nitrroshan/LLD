package chapter01;

public class Cat extends Animal {

    public Cat(String name) {
        super(name);
    }

    @Override
    public void makeSound() {
        System.out.println(getName() + " says Meow!");
    }

    public void purr() {
        System.out.println(getName() + " is purring...");
    }
}

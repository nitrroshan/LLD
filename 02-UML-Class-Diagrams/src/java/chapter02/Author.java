package chapter02;

/**
 * UML: Association target.
 * Book --> Author (Book knows its Author, Author exists independently)
 */
public class Author {
    private String name;
    private String email;

    public Author(String name, String email) {
        this.name = name;
        this.email = email;
    }

    public String getName() { return name; }
    public String getEmail() { return email; }

    @Override
    public String toString() {
        return name;
    }
}

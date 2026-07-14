package chapter12;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Composite Pattern Demo ===\n");

        // Build a file system tree
        Directory root = new Directory("project");

        // Top-level files
        root.add(new File("README.md", 150));
        root.add(new File(".gitignore", 30));

        // src/ directory with files
        Directory src = new Directory("src");
        src.add(new File("Main.java", 500));
        src.add(new File("Utils.java", 300));
        src.add(new File("Config.java", 200));

        // src/test/ nested directory
        Directory test = new Directory("test");
        test.add(new File("MainTest.java", 400));
        test.add(new File("UtilsTest.java", 250));
        src.add(test);

        root.add(src);

        // docs/ directory
        Directory docs = new Directory("docs");
        docs.add(new File("guide.md", 800));
        docs.add(new File("api.md", 600));
        root.add(docs);

        // 1. Print the entire tree
        System.out.println("--- File System Tree ---");
        root.print("");
        System.out.println();

        // 2. Uniform treatment — getSize() works on both files and directories
        System.out.println("--- Sizes (uniform interface) ---");
        System.out.println("root total:   " + root.getSize() + " bytes");
        System.out.println("src/ total:   " + src.getSize() + " bytes");
        System.out.println("test/ total:  " + test.getSize() + " bytes");
        System.out.println("docs/ total:  " + docs.getSize() + " bytes");
        System.out.println();

        // 3. Polymorphism — iterate children without instanceof
        System.out.println("--- Direct children of root (no instanceof!) ---");
        for (FileSystemNode child : root.getChildren()) {
            System.out.println("  " + child.getName() + " → " + child.getSize() + " bytes");
            // Works for File AND Directory — same interface
        }
    }
}

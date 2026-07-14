package chapter12;

import java.util.ArrayList;
import java.util.List;

/**
 * Composite — a directory that contains files and/or other directories.
 * getSize() recursively sums all children.
 */
public class Directory implements FileSystemNode {
    private final String name;
    private final List<FileSystemNode> children = new ArrayList<>();

    public Directory(String name) {
        this.name = name;
    }

    public void add(FileSystemNode node) {
        children.add(node);
    }

    public void remove(FileSystemNode node) {
        children.remove(node);
    }

    public List<FileSystemNode> getChildren() {
        return children;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public int getSize() {
        int total = 0;
        for (FileSystemNode child : children) {
            total += child.getSize();  // polymorphic — works for File AND Directory
        }
        return total;
    }

    @Override
    public void print(String indent) {
        System.out.println(indent + "📁 " + name + "/ (" + getSize() + " bytes)");
        for (FileSystemNode child : children) {
            child.print(indent + "  ");  // recursive — children print themselves
        }
    }
}

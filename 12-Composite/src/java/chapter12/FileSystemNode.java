package chapter12;

/**
 * Component interface — common operations for both files and directories.
 */
public interface FileSystemNode {
    String getName();
    int getSize();
    void print(String indent);
}

mod file_system;

use file_system::FileSystemNode;

fn main() {
    println!("=== Composite Pattern Demo (Rust) ===\n");

    // Build the tree
    let mut root = FileSystemNode::new_directory("project");
    root.add(FileSystemNode::new_file("README.md", 150));
    root.add(FileSystemNode::new_file(".gitignore", 30));

    let mut src = FileSystemNode::new_directory("src");
    src.add(FileSystemNode::new_file("Main.java", 500));
    src.add(FileSystemNode::new_file("Utils.java", 300));
    src.add(FileSystemNode::new_file("Config.java", 200));

    let mut test = FileSystemNode::new_directory("test");
    test.add(FileSystemNode::new_file("MainTest.java", 400));
    test.add(FileSystemNode::new_file("UtilsTest.java", 250));
    src.add(test);

    root.add(src);

    let mut docs = FileSystemNode::new_directory("docs");
    docs.add(FileSystemNode::new_file("guide.md", 800));
    docs.add(FileSystemNode::new_file("api.md", 600));
    root.add(docs);

    // 1. Print the tree
    println!("--- File System Tree ---");
    root.print("");
    println!();

    // 2. Uniform treatment
    println!("--- Sizes ---");
    println!("root total: {} bytes", root.get_size());
    println!();

    // 3. Iterate direct children
    println!("--- Direct children of root ---");
    if let FileSystemNode::Directory { children, .. } = &root {
        for child in children {
            println!("  {} -> {} bytes", child.get_name(), child.get_size());
        }
    }
}

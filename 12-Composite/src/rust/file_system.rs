/// Component — common operations for both files and directories.
/// Using an enum instead of trait objects — more idiomatic in Rust
/// for closed hierarchies (we know all node types at compile time).
pub enum FileSystemNode {
    File {
        name: String,
        size: u64,
    },
    Directory {
        name: String,
        children: Vec<FileSystemNode>,
    },
}

impl FileSystemNode {
    pub fn new_file(name: &str, size: u64) -> Self {
        FileSystemNode::File {
            name: name.to_string(),
            size,
        }
    }

    pub fn new_directory(name: &str) -> Self {
        FileSystemNode::Directory {
            name: name.to_string(),
            children: Vec::new(),
        }
    }

    pub fn add(&mut self, node: FileSystemNode) {
        if let FileSystemNode::Directory { children, .. } = self {
            children.push(node);
        } else {
            panic!("Cannot add children to a file");
        }
    }

    pub fn get_name(&self) -> &str {
        match self {
            FileSystemNode::File { name, .. } => name,
            FileSystemNode::Directory { name, .. } => name,
        }
    }

    pub fn get_size(&self) -> u64 {
        match self {
            FileSystemNode::File { size, .. } => *size,
            FileSystemNode::Directory { children, .. } => {
                children.iter().map(|c| c.get_size()).sum()
            }
        }
    }

    pub fn print(&self, indent: &str) {
        match self {
            FileSystemNode::File { name, size } => {
                println!("{}F {} ({} bytes)", indent, name, size);
            }
            FileSystemNode::Directory { name, children } => {
                println!("{}D {}/ ({} bytes)", indent, name, self.get_size());
                let child_indent = format!("{}  ", indent);
                for child in children {
                    child.print(&child_indent);
                }
            }
        }
    }
}

use std::fmt;

pub trait Prototype: fmt::Display {
    fn clone_shape(&self) -> Box<dyn Prototype>;
    fn move_to(&mut self, x: i32, y: i32);
    fn add_tag(&mut self, tag: &str);
}

pub struct Circle {
    x: i32,
    y: i32,
    color: String,
    tags: Vec<String>,
    radius: i32,
}

impl Circle {
    pub fn new(x: i32, y: i32, color: &str, radius: i32) -> Self {
        Circle { x, y, color: color.to_string(), tags: Vec::new(), radius }
    }
}

impl Prototype for Circle {
    fn clone_shape(&self) -> Box<dyn Prototype> {
        Box::new(Circle {
            x: self.x,
            y: self.y,
            color: self.color.clone(),
            tags: self.tags.clone(),     // deep copy — Vec::clone clones each element
            radius: self.radius,
        })
    }

    fn move_to(&mut self, x: i32, y: i32) {
        self.x = x;
        self.y = y;
    }

    fn add_tag(&mut self, tag: &str) {
        self.tags.push(tag.to_string());
    }
}

impl fmt::Display for Circle {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "Circle [radius={} ({},{}) color={} tags={:?}]",
               self.radius, self.x, self.y, self.color, self.tags)
    }
}

pub struct Rectangle {
    x: i32,
    y: i32,
    color: String,
    tags: Vec<String>,
    width: i32,
    height: i32,
}

impl Rectangle {
    pub fn new(x: i32, y: i32, color: &str, width: i32, height: i32) -> Self {
        Rectangle { x, y, color: color.to_string(), tags: Vec::new(), width, height }
    }
}

impl Prototype for Rectangle {
    fn clone_shape(&self) -> Box<dyn Prototype> {
        Box::new(Rectangle {
            x: self.x,
            y: self.y,
            color: self.color.clone(),
            tags: self.tags.clone(),
            width: self.width,
            height: self.height,
        })
    }

    fn move_to(&mut self, x: i32, y: i32) {
        self.x = x;
        self.y = y;
    }

    fn add_tag(&mut self, tag: &str) {
        self.tags.push(tag.to_string());
    }
}

impl fmt::Display for Rectangle {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "Rectangle [{}x{} ({},{}) color={} tags={:?}]",
               self.width, self.height, self.x, self.y, self.color, self.tags)
    }
}

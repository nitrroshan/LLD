use crate::approver::Approver;

pub struct Manager {
    next: Option<Box<dyn Approver>>,
}

impl Manager {
    pub fn new() -> Self {
        Manager { next: None }
    }

    pub fn set_next(mut self, next: Box<dyn Approver>) -> Self {
        self.next = Some(next);
        self
    }
}

impl Approver for Manager {
    fn limit(&self) -> f64 { 5000.0 }
    fn name(&self) -> &str { "Manager" }
    fn next(&self) -> Option<&dyn Approver> { self.next.as_deref() }
}

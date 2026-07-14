use crate::approver::Approver;

pub struct Director {
    next: Option<Box<dyn Approver>>,
}

impl Director {
    pub fn new() -> Self {
        Director { next: None }
    }

    pub fn set_next(mut self, next: Box<dyn Approver>) -> Self {
        self.next = Some(next);
        self
    }
}

impl Approver for Director {
    fn limit(&self) -> f64 { 20000.0 }
    fn name(&self) -> &str { "Director" }
    fn next(&self) -> Option<&dyn Approver> { self.next.as_deref() }
}

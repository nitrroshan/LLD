use crate::approver::Approver;

pub struct TeamLead {
    next: Option<Box<dyn Approver>>,
}

impl TeamLead {
    pub fn new() -> Self {
        TeamLead { next: None }
    }

    pub fn set_next(mut self, next: Box<dyn Approver>) -> Self {
        self.next = Some(next);
        self
    }
}

impl Approver for TeamLead {
    fn limit(&self) -> f64 { 1000.0 }
    fn name(&self) -> &str { "Team Lead" }
    fn next(&self) -> Option<&dyn Approver> { self.next.as_deref() }
}

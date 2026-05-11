pub struct BankAccount {
    owner: String,
    balance: f64,
}

impl BankAccount {
    pub fn new(owner: &str, initial_balance: f64) -> Self {
        BankAccount {
            owner: owner.to_string(),
            balance: initial_balance,
        }
    }

    pub fn get_balance(&self) -> f64 {
        self.balance
    }

    pub fn deposit(&mut self, amount: f64) {
        if amount <= 0.0 {
            println!("Deposit amount must be positive.");
            return;
        }
        self.balance += amount;
        println!("{} deposited {}. New balance: {}", self.owner, amount, self.balance);
    }

    pub fn withdraw(&mut self, amount: f64) {
        if amount <= 0.0 {
            println!("Withdrawal amount must be positive.");
            return;
        }
        if amount > self.balance {
            println!(
                "Insufficient funds! {} tried to withdraw {} but balance is {}",
                self.owner, amount, self.balance
            );
            return;
        }
        self.balance -= amount;
        println!("{} withdrew {}. New balance: {}", self.owner, amount, self.balance);
    }
}

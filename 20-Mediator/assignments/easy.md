# Assignment: Auction System (Easy)

## Objective

Apply the Mediator pattern to an auction where **bidders** never talk to each other — the **auctioneer** (mediator) coordinates all bidding.

## Background

In an auction, when someone places a bid, every *other* bidder must be notified of the new highest bid, and the auctioneer enforces the rules (a bid must beat the current highest). Bidders don't know about each other; they only interact with the auctioneer. This is a textbook many-to-many interaction funneled through one mediator.

## Requirements

**Mediator — `Auctioneer`:**

| Method | Behavior |
|--------|----------|
| `register(Bidder bidder)` | add a bidder |
| `placeBid(Bidder bidder, double amount)` | if `amount > currentHighest`, accept it, update the highest, and notify **all other** bidders; otherwise reject and print `Bid of $<amount> rejected (highest is $<highest>)` |

Track `currentHighest` and the `highestBidder`'s name.

**Colleague — `Bidder`:**

| Method | Behavior |
|--------|----------|
| `bid(double amount)` | calls `auctioneer.placeBid(this, amount)` |
| `notify(String bidderName, double amount)` | prints `<name> notified: <bidderName> now leads at $<amount>` |
| `getName()` | bidder's name |

### What to implement

1. `Auctioneer` (interface + concrete, or a single mediator class), `Bidder` — one file per type in all 4 languages
2. `Main`:
   - Register 3 bidders (Alice, Bob, Carol)
   - Alice bids $100 → accepted, Bob & Carol notified
   - Bob bids $150 → accepted, Alice & Carol notified
   - Carol bids $120 → **rejected** (below $150)
   - Print the final winner and price

### Expected Output (shape)

```
Alice bids $100
    Bob notified: Alice now leads at $100
    Carol notified: Alice now leads at $100
Bob bids $150
    Alice notified: Bob now leads at $150
    Carol notified: Bob now leads at $150
Carol bids $120
  Bid of $120 rejected (highest is $150)
Winner: Bob at $150
```

## Constraints

- One file per class/type
- Bidders hold **no** reference to other bidders — only to the auctioneer
- All bid rules and notifications live in the `Auctioneer` (the mediator)
- A bidder is never notified of its own winning bid

## Submission

Put your solution in `20-Mediator/assignments/easy/src/{java,cpp,rust,go}/`.

# Assignment: Menu System (Easy)

## Objective

Apply the Composite pattern to build a restaurant menu where menu items (leaves) and sub-menus (composites) are treated uniformly.

## Requirements

**Component — `MenuComponent`:**

| Method | Description |
|--------|-------------|
| `getName()` | Name of the item or sub-menu |
| `getPrice()` | Price for items; total price for sub-menus |
| `print(indent)` | Display the item or sub-menu tree |

**Leaf — `MenuItem`:**
- Has `name`, `price`, `description`
- `getPrice()` returns its own price
- `print()` shows: `name — $price (description)`

**Composite — `SubMenu`:**
- Has `name` and a list of `MenuComponent` children
- `getPrice()` sums all children's prices
- `print()` shows its name, then prints all children indented

### What to implement

1. `MenuComponent` — interface/trait
2. `MenuItem` — leaf (name, price, description)
3. `SubMenu` — composite (name, children)
4. `Main` — build this menu tree:

```
Restaurant Menu ($40.47)
  Appetizers ($12.48)
    Spring Rolls — $5.99 (Crispy vegetable rolls)
    Soup — $3.99 (Tomato basil)
    Bruschetta — $2.50 (Toasted bread with tomatoes)
  Main Course ($19.99)
    Steak — $15.99 (Grilled ribeye)
    Pasta — $4.00 (Penne arrabbiata)
  Desserts ($7.00)
    Ice Cream — $3.50 (Vanilla bean)
    Cake — $3.50 (Chocolate lava)
  Beverages ($1.00)
    Water — $1.00 (Sparkling)
```

### Expected behavior

- `menu.getPrice()` returns 40.47 (sum of all items recursively)
- `menu.print("")` prints the entire tree above
- `appetizers.getPrice()` returns 12.48

## Constraints

- One file per class/type
- No `instanceof` or type checking in client code
- `getPrice()` must work identically on items and sub-menus

## Submission

Put your solution in `12-Composite/assignments/easy/src/{java,cpp,rust,go}/`.

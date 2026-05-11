# Assignment: Medium — Reverse-Engineer UML from Code

## Objective
Practice **reading code and extracting the UML class diagram** — the reverse of what you usually do.

## Requirements

Study the Java code in `02-UML-Class-Diagrams/src/java/chapter02/` (or any language you prefer) and:

1. **Draw the complete UML class diagram** showing ALL relationships:
   - Library ↔ Book
   - Library ↔ Member
   - Book ↔ Author
   - Book ↔ DigitalBook
   - Library ↔ Searchable
   - Member ↔ Book

2. For each relationship, state:
   - The **type** (Association, Aggregation, Composition, Inheritance, Realization, Dependency)
   - The **multiplicity** (1, *, 0..1, etc.)
   - **Why** it's that type (one sentence)

3. **Compare how relationships are expressed across languages:**

| Relationship | Java | C++ | Rust | Go |
|-------------|------|-----|------|----|
| Composition | ? | ? | ? | ? |
| Association | ? | ? | ? | ? |
| Inheritance | ? | ? | ? | ? |
| Realization | ? | ? | ? | ? |
| Dependency | ? | ? | ? | ? |
| Aggregation | ? | ? | ? | ? |

Fill in what language construct is used for each (e.g., "extends", "embedding", "trait", "unique_ptr", etc.)

## Deliverable

Create a file `02-UML-Class-Diagrams/assignments/medium/library_uml.md` with:
1. The full Mermaid class diagram
2. A table explaining each relationship
3. The cross-language comparison table (filled in)

## Checklist
- [ ] All 6 relationships identified correctly
- [ ] Multiplicity on every relationship
- [ ] Mermaid diagram is valid
- [ ] Cross-language table is complete
- [ ] Explanations show understanding of WHY each type was chosen

## Hint
The key distinction in the code:
- Look at **what's stored as a field** vs **what's passed as a parameter**
- Look at **who creates the object** vs **who just uses it**
- In C++: `unique_ptr` = ownership (composition), raw pointer = reference (association/aggregation)
- In Rust: `Vec<Book>` = ownership, `&Book` = borrowing

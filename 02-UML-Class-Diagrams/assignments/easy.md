# Assignment: Easy — Draw UML for a School System

## Objective
Practice **reading requirements and drawing a class diagram** with correct relationships and multiplicity.

## Requirements

Given the following description, draw a UML class diagram (in Mermaid syntax):

> A **School** has many **Classrooms**. Each Classroom has exactly one **Teacher** assigned.
> A Classroom has many **Students**. A Student can be in exactly one Classroom.
> A Teacher can teach multiple Classrooms.
> Each Student has a **Backpack** that contains multiple **TextBooks**.
> If a Student leaves the school, their Backpack goes with them — but the TextBooks remain
> (they're on loan from the school).

### You need to identify:

1. **Classes**: What are the entities? (at least 5)
2. **Attributes**: At least 2-3 per class (name, id, capacity, subject, etc.)
3. **Methods**: At least 1-2 per class
4. **Relationships**: For each pair, decide:
   - Association, Aggregation, or Composition?
   - What's the multiplicity on each side?
5. **Write it in Mermaid syntax** in a `.md` file

### Hints

| Pair | Question to ask |
|------|----------------|
| School ↔ Classroom | Does the classroom exist without the school? |
| Classroom ↔ Teacher | Does the teacher die if the classroom is deleted? |
| Classroom ↔ Student | Does the student die if the classroom is deleted? |
| Student ↔ Backpack | Can the backpack exist without the student? |
| Backpack ↔ TextBook | Are the textbooks owned by the backpack? |

## Deliverable

Create a file `02-UML-Class-Diagrams/assignments/easy/school.md` with:
1. The Mermaid class diagram
2. A brief explanation of each relationship (1 sentence per pair)

## Checklist
- [ ] At least 5 classes with attributes and methods
- [ ] All 6 relationships identified with correct type
- [ ] Multiplicity annotated on every relationship
- [ ] Mermaid syntax is valid
- [ ] Justification for each relationship type

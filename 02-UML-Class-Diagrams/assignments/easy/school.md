# School System — UML Class Diagram

> Fill in the Mermaid diagram and relationship explanations below.
> Refer to `02-UML-Class-Diagrams/notes.md` for syntax and relationship types.

## Class Diagram

```mermaid
classDiagram

    class School {
        %% TODO: Add attributes (name, address, etc.)
        %% TODO: Add methods
    }

    class Classroom {
        %% TODO: Add attributes (roomNumber, capacity, etc.)
        %% TODO: Add methods
    }

    class Teacher {
        %% TODO: Add attributes (name, subject, etc.)
        %% TODO: Add methods
    }

    class Student {
        %% TODO: Add attributes (name, studentId, etc.)
        %% TODO: Add methods
    }

    class Backpack {
        %% TODO: Add attributes (color, etc.)
        %% TODO: Add methods
    }

    class TextBook {
        %% TODO: Add attributes (title, subject, etc.)
        %% TODO: Add methods
    }

    %% TODO: Define relationships below
    %% Use the correct arrow type and multiplicity for each:
    %%   Composition:  A *-- B
    %%   Aggregation:  A o-- B
    %%   Association:  A --> B
    %%
    %% Example: School "1" *-- "1..*" Classroom : contains

```

## Relationship Explanations

| # | Relationship | Type | Multiplicity | Why? |
|---|-------------|------|-------------|------|
| 1 | School ↔ Classroom | TODO | TODO | TODO |
| 2 | Classroom ↔ Teacher | TODO | TODO | TODO |
| 3 | Classroom ↔ Student | TODO | TODO | TODO |
| 4 | Student ↔ Backpack | TODO | TODO | TODO |
| 5 | Backpack ↔ TextBook | TODO | TODO | TODO |

## Verification Checklist
- [ ] At least 5 classes with 2+ attributes each
- [ ] All relationships have the correct UML type
- [ ] Multiplicity is on every relationship
- [ ] Mermaid syntax renders correctly (preview in VS Code with Mermaid extension)
- [ ] Each explanation answers: "Why this type and not another?"

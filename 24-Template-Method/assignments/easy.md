# Assignment: Data Processing Pipeline (Easy)

## Objective

Apply the Template Method pattern to a data-import pipeline whose steps (read → parse → transform → save) are fixed in order, but where **parsing** and **transforming** vary by file format.

## Background

Importing data always follows the same phases: read the file, parse it, transform the records, save them. The *sequence* never changes, but *how* you parse (CSV vs JSON) and *how* you transform differ. That's a textbook template method: fix the skeleton, vary the format-specific steps.

## Requirements

**Abstract class — `DataImporter`:**

Template method `run(String source)` executes, in order:
1. `read(source)` — concrete, shared: prints `Reading from <source>`
2. `parse()` — **abstract** (format-specific)
3. `transform()` — **abstract** (format-specific)
4. `save()` — concrete, shared: prints `Saving <n> records` (use a small fixed count or a value the steps set)
5. Optional hook `validate()` — default does nothing; a subclass may override to add a validation step **before** save

Make `run` non-overridable (final / non-virtual / default trait method).

**Concrete importers (one file each):**

| Importer | parse() | transform() |
|----------|---------|-------------|
| `CsvImporter` | `Parsing CSV rows` | `Trimming whitespace` |
| `JsonImporter` | `Parsing JSON objects` | `Flattening nested fields` |

Add one importer that **overrides the `validate()` hook**, e.g. `StrictCsvImporter` that prints `Validating schema` before saving.

### What to implement

1. `DataImporter` (abstract/base/trait), `CsvImporter`, `JsonImporter`, `StrictCsvImporter`
2. `Main`: run each importer on a sample source and show identical structure with varying steps; the strict one shows the extra validation step

### Expected Output (shape)

```
CSV import:
  Reading from data.csv
  Parsing CSV rows
  Trimming whitespace
  Saving records
JSON import:
  Reading from data.json
  Parsing JSON objects
  Flattening nested fields
  Saving records
Strict CSV import:
  Reading from data.csv
  Parsing CSV rows
  Trimming whitespace
  Validating schema
  Saving records
```

## Constraints

- One file per class/type in all 4 languages
- The step order lives **only** in the template method — subclasses can't reorder it
- The template method must be non-overridable (final/non-virtual/default trait method)
- Use a **hook** for the optional validation step, not a required abstract method
- Reflect each language's idiom: Java/C++ inheritance, Rust default trait method, Go function-over-interface

## Submission

Put your solution in `24-Template-Method/assignments/easy/src/{java,cpp,rust,go}/`.

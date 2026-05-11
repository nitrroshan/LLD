# Assignment: Medium — Document Generator with Factory Method + OOP

## Objective
Build a document generation system using Factory Method. Combines Factory Method with OOP (Ch01) and SOLID (Ch03).

## Requirements

A system that generates different document formats:
- **PDF** — header, body with bold text, page numbers
- **HTML** — wraps content in `<html><body>...</body></html>` tags
- **Markdown** — uses `#` headers and `**bold**` formatting

### Structure

1. **Product interface: `Document`**
   - `void addHeader(String text)`
   - `void addBody(String text)`
   - `String render()` — returns the formatted document as a String

2. **Concrete Products:** `PdfDocument`, `HtmlDocument`, `MarkdownDocument`

3. **Creator (abstract): `DocumentFactory`**
   - Factory method: `Document createDocument()`
   - Business method: `String generateReport(String title, String content)`
     → Creates a document, adds header with title, adds body with content, returns render()

4. **Concrete Creators:** `PdfDocumentFactory`, `HtmlDocumentFactory`, `MarkdownDocumentFactory`

## Expected Output
```
=== PDF Report ===
[PDF HEADER] Quarterly Report
[PDF BODY] Revenue increased by 20% this quarter.
[PDF PAGE 1]

=== HTML Report ===
<html><body>
<h1>Quarterly Report</h1>
<p>Revenue increased by 20% this quarter.</p>
</body></html>

=== Markdown Report ===
# Quarterly Report

Revenue increased by 20% this quarter.
```

## Compile & Run
```
cd 05-Factory-Method/assignments/medium/src
javac chapter05/medium/*.java
java chapter05.medium.Main
```

## Checklist
- [ ] `Document` is an interface with `addHeader()`, `addBody()`, `render()`
- [ ] Each document type formats output differently
- [ ] `DocumentFactory` uses factory method — `generateReport()` never calls `new` directly
- [ ] Adding Latex format = 2 new files, 0 changes to existing code (OCP)
- [ ] No `if/else` or `switch` on document type anywhere

# Assignment: Easy — Theme Factory

## Objective
Apply the Abstract Factory pattern to create a themed UI component set. The system supports **Light** and **Dark** themes, each producing matching buttons and text fields.

## Requirements

1. **Product interfaces:**
   - `ThemedButton` — methods: `display()`, `click()`
   - `ThemedTextField` — methods: `display()`, `type(text String)`

2. **Concrete Products (Light family):**
   - `LightButton` — displays white button with dark text
   - `LightTextField` — displays white input field

3. **Concrete Products (Dark family):**
   - `DarkButton` — displays black button with light text
   - `DarkTextField` — displays dark input field

4. **Abstract Factory: `ThemeFactory`**
   - `createButton()` → returns `ThemedButton`
   - `createTextField()` → returns `ThemedTextField`

5. **Concrete Factories:**
   - `LightThemeFactory` — creates `LightButton` + `LightTextField`
   - `DarkThemeFactory` — creates `DarkButton` + `DarkTextField`

6. **Client function/method:** `renderForm(ThemeFactory factory)` — creates both components, displays and interacts with them

## Expected Output
```
=== Light Theme ===
--- Rendering Form ---
[Light Button] White button with dark text.
[Light TextField] White input field with border.
--- Interacting ---
[Light Button] Clicked — light ripple effect.
[Light TextField] Typing: "Hello World" — dark text on white.

=== Dark Theme ===
--- Rendering Form ---
[Dark Button] Black button with glowing text.
[Dark TextField] Dark input field with subtle border.
--- Interacting ---
[Dark Button] Clicked — neon glow effect.
[Dark TextField] Typing: "Hello World" — light text on dark.
```

## Compile & Run (Java)
```
cd 06-Abstract-Factory/assignments/easy/src/java
javac chapter06/easy/*.java
java chapter06.easy.Main
```

## Checklist
- [ ] Two product interfaces: `ThemedButton` and `ThemedTextField`
- [ ] Each theme family has matching products (Light-Light, Dark-Dark)
- [ ] `ThemeFactory` is an interface with one factory method per product type
- [ ] Client code (`renderForm`) works entirely through interfaces — never mentions Light/Dark classes
- [ ] No mixing possible — `LightThemeFactory` can't produce a `DarkButton`
- [ ] Adding a new theme (e.g., "High Contrast") = 1 factory + 2 products, 0 edits to existing code

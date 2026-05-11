# LLD Chapter Plan — Detailed Breakdown

> This is the detailed plan for every chapter. Copilot also keeps this in memory for cross-session context.

---

## Phase 1: Foundations (Chapters 01–04)

### Chapter 01 — OOP Refresher
**Goal:** Solidify core OOP concepts with Java examples.
- Topics: Classes, Objects, Constructors, `this` keyword
- Inheritance: `extends`, method overriding, `super`
- Polymorphism: Compile-time (overloading) vs Runtime (overriding)
- Abstraction: Abstract classes vs Interfaces
- Encapsulation: Access modifiers, getters/setters
- Code examples: Animal hierarchy, Shape calculator
- Assignments: Model a Vehicle system (easy), Bank Account with polymorphism (medium)

### Chapter 02 — UML & Class Diagrams
**Goal:** Read and draw UML diagrams for any system.
- Class diagrams: attributes, methods, visibility
- Relationships: Association, Aggregation, Composition, Inheritance, Dependency
- Multiplicity notation (1..*, 0..1, etc.)
- Sequence diagrams basics
- Mermaid syntax for diagrams
- Code examples: Translate UML ↔ Java code
- Assignments: Draw UML for a Library (easy), Reverse-engineer UML from code (medium)

### Chapter 03 — SOLID Principles
**Goal:** Understand and apply all 5 SOLID principles.
- **S** – Single Responsibility: One reason to change per class
- **O** – Open/Closed: Open for extension, closed for modification
- **L** – Liskov Substitution: Subtypes must be substitutable
- **I** – Interface Segregation: No fat interfaces
- **D** – Dependency Inversion: Depend on abstractions, not concretions
- Each principle: Bad code → Refactored code comparison
- Assignments: Refactor a violating codebase (easy), Design a notification system using SOLID (medium), Identify & fix all violations in a mini-project (hard)

### Chapter 04 — Design Principles Beyond SOLID
**Goal:** Learn complementary principles for clean design.
- DRY (Don't Repeat Yourself)
- KISS (Keep It Simple, Stupid)
- YAGNI (You Aren't Gonna Need It)
- Composition over Inheritance — when and why
- Law of Demeter (Principle of Least Knowledge)
- Tell, Don't Ask principle
- Code examples: Inheritance abuse → Composition refactor
- Assignments: Refactor tightly-coupled code (easy), Redesign a class hierarchy using composition (medium)

---

## Phase 2: Creational Patterns (Chapters 05–09)

### Chapter 05 — Factory Method Pattern
**Goal:** Delegate object creation to subclasses.
- Problem: `new` keyword coupling, switch/if chains for creation
- Solution: Define interface for creating objects; let subclasses decide
- UML: Creator → ConcreteCreator, Product → ConcreteProduct
- Code example: NotificationFactory (Email, SMS, Push)
- When to use: Object type determined at runtime, many product variants
- When NOT: Only one product type, simple construction
- Assignments: Shape factory (easy), Document generator combining with OOP (medium)

### Chapter 06 — Abstract Factory Pattern
**Goal:** Create families of related objects without specifying concrete classes.
- Problem: Platform/theme-dependent UI components
- Solution: Factory of factories — one factory per family
- UML: AbstractFactory → ConcreteFactory1/2, AbstractProduct → ConcreteProduct
- Code example: UI Toolkit (Windows vs Mac buttons, checkboxes, menus)
- Difference from Factory Method
- Assignments: Furniture factory (easy), Cross-platform UI kit (medium)

### Chapter 07 — Builder Pattern
**Goal:** Construct complex objects step by step.
- Problem: Telescoping constructor, too many constructor params
- Solution: Separate construction from representation
- Fluent interface / method chaining
- Director class (optional orchestrator)
- Code example: MealBuilder, HouseBuilder
- When to use: Many optional params, immutable objects
- Assignments: QueryBuilder for SQL (easy), Pizza ordering system (medium), Report generator with Director (hard)

### Chapter 08 — Singleton Pattern
**Goal:** Ensure a class has exactly one instance.
- Problem: Shared resources (DB connection, config, logger)
- Implementations: Eager, Lazy, Thread-safe (double-checked locking), Enum singleton
- Bill Pugh Singleton (inner static helper)
- Breaking singleton: Reflection, Serialization, Cloning — and prevention
- When NOT to use: Testing difficulties, hidden dependencies
- Code example: DatabaseConnection, ConfigManager
- Assignments: Logger singleton (easy), Thread-safe registry (medium)

### Chapter 09 — Prototype Pattern
**Goal:** Clone existing objects instead of creating from scratch.
- Problem: Expensive object creation, complex initialization
- Solution: `Cloneable` interface, `clone()` method
- Shallow copy vs Deep copy — critical distinction
- Prototype Registry / Manager pattern
- Code example: Shape cloning, Game character templates
- Assignments: Document cloner (easy), Game unit spawner using prototype + factory (medium)

---

## Phase 3: Structural Patterns (Chapters 10–16)

### Chapter 10 — Adapter Pattern
**Goal:** Make incompatible interfaces work together.
- Problem: Third-party library with different interface
- Class Adapter (inheritance) vs Object Adapter (composition)
- Code example: MediaPlayer adapting VLC/MP4 players
- Real-world: `Arrays.asList()`, XML-to-JSON adapter
- Assignments: Payment gateway adapter (easy), Legacy system integration (medium)

### Chapter 11 — Bridge Pattern
**Goal:** Separate abstraction from implementation so both can vary.
- Problem: Cartesian product explosion (Shape × Color, Remote × Device)
- Solution: Two independent hierarchies connected by composition
- Code example: Remote control (Basic/Advanced) × Device (TV/Radio)
- Bridge vs Adapter — key differences
- Assignments: Messaging system (easy), Drawing shapes with renderers (medium)

### Chapter 12 — Composite Pattern
**Goal:** Treat individual objects and compositions uniformly.
- Problem: Tree structures (file systems, menus, org charts)
- Component, Leaf, Composite roles
- Code example: FileSystem (File + Directory), Organization hierarchy
- Transparency vs Safety approach
- Assignments: Menu system (easy), Expression tree calculator (medium)

### Chapter 13 — Decorator Pattern
**Goal:** Add behavior dynamically without modifying existing classes.
- Problem: Subclass explosion for feature combinations
- Solution: Wrapping objects in decorator layers
- Code example: Coffee shop (Espresso + Milk + Whip), I/O streams
- Decorator vs Inheritance — when to use which
- Assignments: Pizza topping system (easy), Text formatting with stacked decorators (medium), Notification decorator chain (hard)

### Chapter 14 — Facade Pattern
**Goal:** Provide a simplified interface to a complex subsystem.
- Problem: Client interacts with too many subsystem classes
- Solution: Single entry-point class that delegates
- Code example: HomeTheaterFacade (Projector, Amplifier, DVDPlayer, Lights)
- Facade vs Adapter vs Proxy
- Assignments: Order processing facade (easy), Computer startup facade (medium)

### Chapter 15 — Flyweight Pattern
**Goal:** Share common state to support large numbers of objects efficiently.
- Problem: Thousands of similar objects consuming memory
- Intrinsic state (shared) vs Extrinsic state (unique)
- Flyweight Factory
- Code example: Text editor characters, Game forest (tree types)
- Assignments: Bullet system in a game (easy), Character rendering engine (medium)

### Chapter 16 — Proxy Pattern
**Goal:** Control access to an object through a surrogate.
- Types: Virtual proxy (lazy loading), Protection proxy (access control), Remote proxy, Caching proxy
- Code example: Image lazy-loading proxy, Internet access proxy
- Proxy vs Decorator — key differences
- Assignments: Document access proxy (easy), Cached database proxy (medium)

---

## Phase 4: Behavioral Patterns (Chapters 17–27)

### Chapter 17 — Chain of Responsibility
**Goal:** Pass requests along a chain of handlers.
- Problem: Multiple handlers, sender shouldn't know which handles it
- Handler interface, chaining via `next` reference
- Code example: Logging levels, Purchase approval chain
- Assignments: Authentication middleware (easy), Support ticket escalation (medium)

### Chapter 18 — Command Pattern
**Goal:** Encapsulate a request as an object.
- Problem: Parameterize actions, support undo/redo, queue requests
- Command, Receiver, Invoker, Client roles
- Code example: Remote control, Text editor with undo
- Macro commands (composite commands)
- Assignments: Light/fan remote (easy), Transaction system with undo (medium), Task scheduler (hard)

### Chapter 19 — Iterator Pattern
**Goal:** Traverse a collection without exposing its structure.
- Problem: Different traversal strategies for same collection
- Iterator interface, Iterable contract
- Code example: Custom linked list iterator, Tree traversal (BFS/DFS)
- Java's `Iterator` and `Iterable` interfaces
- Assignments: Playlist iterator (easy), Filtered iterator (medium)

### Chapter 20 — Mediator Pattern
**Goal:** Centralize complex communication between objects.
- Problem: Many-to-many relationships, tight coupling
- Mediator object coordinates colleagues
- Code example: Chat room, Air traffic control
- Mediator vs Observer
- Assignments: Auction system (easy), Smart home controller (medium)

### Chapter 21 — Memento Pattern
**Goal:** Capture and restore object state without violating encapsulation.
- Originator, Memento, Caretaker roles
- Code example: Text editor save/restore, Game checkpoints
- Assignments: Calculator with undo (easy), Document version history (medium)

### Chapter 22 — Observer Pattern
**Goal:** Define a one-to-many dependency for event notification.
- Problem: Polling vs Push notification
- Subject, Observer, ConcreteSubject, ConcreteObserver
- Push vs Pull model
- Code example: Weather station, Stock price alerts
- Java's built-in Observer (deprecated) — why build your own
- Assignments: Newsletter subscription (easy), Event bus system (medium), Real-time dashboard (hard)

### Chapter 23 — State Pattern
**Goal:** Allow an object to alter its behavior when its internal state changes.
- Problem: Giant switch/if-else for state-dependent behavior
- State interface, ConcreteState classes, Context
- Code example: Vending machine states, Order lifecycle
- State vs Strategy — key differences
- Assignments: Traffic light controller (easy), Document workflow (Draft→Review→Published) (medium)

### Chapter 24 — Strategy Pattern
**Goal:** Define a family of algorithms, make them interchangeable.
- Problem: Multiple ways to do the same task, hardcoded selection
- Strategy interface, ConcreteStrategies, Context
- Code example: Payment methods, Sorting strategies, Route navigation
- Assignments: Discount calculator (easy), Compression tool with multiple algorithms (medium)

### Chapter 25 — Template Method Pattern
**Goal:** Define the skeleton of an algorithm, defer some steps to subclasses.
- Problem: Same algorithm structure, different details
- Abstract class with `final` template method + abstract hook methods
- Code example: Game initialization flow, Data parser (CSV/XML/JSON)
- Template Method vs Strategy
- Assignments: Beverage maker (easy), Report generator (medium)

### Chapter 26 — Visitor Pattern
**Goal:** Add operations to object structures without modifying them.
- Problem: New operations on a fixed class hierarchy
- Double dispatch mechanism
- Element, Visitor, ConcreteVisitor, `accept()` method
- Code example: Shape area/perimeter calculator, Tax computation
- Assignments: File system operations (easy), Shopping cart pricing (medium)

### Chapter 27 — Null Object Pattern
**Goal:** Provide a default do-nothing behavior instead of null checks.
- Problem: `NullPointerException`, scattered null checks
- Code example: Logger (RealLogger vs NullLogger), Customer lookup
- Assignments: Default animal behavior (easy), Optional service with fallback (medium)

---

## Phase 5: Real-World Case Studies (Chapters 28–42)

### Chapter 28 — Parking Lot System
- Entities: ParkingLot, Floor, Spot, Vehicle, Ticket, Payment
- Patterns: Strategy (pricing), Factory (vehicle/spot), State (spot status), Singleton (ParkingLot)
- Features: Multi-floor, different vehicle types, pricing strategies

### Chapter 29 — Elevator System
- Entities: Elevator, Floor, Request, Controller, Door
- Patterns: State (elevator states), Observer (floor displays), Strategy (scheduling), Command (requests)
- Features: Multiple elevators, scheduling algorithms, direction optimization

### Chapter 30 — Library Management System
- Entities: Book, Member, Librarian, Loan, Reservation, Fine
- Patterns: Factory (member types), Observer (due-date alerts), Strategy (fine calculation)
- Features: Search, borrow, return, reservations, fine management

### Chapter 31 — Tic-Tac-Toe
- Entities: Board, Player, Piece, Game
- Patterns: Strategy (player move — human vs AI), Factory (players), State (game status)
- Features: Extensible board size, pluggable player strategies

### Chapter 32 — Snake & Ladder Game
- Entities: Board, Player, Dice, Snake, Ladder, Cell
- Patterns: State (player turn), Factory (board elements), Observer (game events)
- Features: Configurable board, multiple players

### Chapter 33 — BookMyShow (Movie Ticket Booking)
- Entities: Movie, Show, Theater, Screen, Seat, Booking, Payment
- Patterns: Observer (seat availability), Strategy (pricing), Factory (seat types), Singleton (BookingSystem)
- Features: Seat selection, concurrent booking, pricing tiers

### Chapter 34 — Splitwise (Expense Sharing)
- Entities: User, Group, Expense, Split, Balance
- Patterns: Strategy (split types — equal/exact/percentage), Observer (balance updates), Mediator (group management)
- Features: Multiple split strategies, balance simplification

### Chapter 35 — Vending Machine
- Entities: VendingMachine, Product, Coin, State, Inventory
- Patterns: State (idle/selecting/dispensing/refunding), Strategy (payment), Chain of Responsibility (coin handling)
- Features: State machine, coin management, inventory tracking

### Chapter 36 — ATM System
- Entities: ATM, Account, Card, Transaction, CashDispenser
- Patterns: State (ATM states), Chain of Responsibility (cash denomination), Command (transactions)
- Features: Authentication, withdrawal with denomination handling, balance inquiry

### Chapter 37 — Hotel Management System
- Entities: Hotel, Room, Guest, Reservation, Payment, HouseKeeping
- Patterns: Factory (room types), Observer (reservation alerts), State (room status), Strategy (pricing/seasonal)
- Features: Room booking, check-in/check-out, housekeeping scheduling

### Chapter 38 — Chess Game
- Entities: Board, Piece (King/Queen/Rook/Bishop/Knight/Pawn), Player, Move, Game
- Patterns: State (game state), Strategy (piece movement rules), Command (moves with undo), Observer (check detection)
- Features: Full move validation, check/checkmate detection, move history

### Chapter 39 — Ride-Sharing System (Uber/Ola)
- Entities: Rider, Driver, Trip, Location, Payment, Rating
- Patterns: Strategy (matching/pricing), Observer (trip status), Factory (vehicle types), State (trip lifecycle), Proxy (location service)
- Features: Driver matching, dynamic pricing, trip tracking

### Chapter 40 — Food Delivery System (Zomato/Swiggy)
- Entities: Restaurant, Menu, Order, DeliveryAgent, Customer, Payment
- Patterns: Observer (order tracking), Strategy (delivery assignment/pricing), State (order lifecycle), Factory (payment methods)
- Features: Order placement, real-time tracking, delivery assignment

### Chapter 41 — Logging Framework
- Entities: Logger, LogLevel, Handler, Formatter, Appender
- Patterns: Singleton (Logger), Chain of Responsibility (log levels), Observer (log listeners)
- Features: Multiple log levels, multiple output targets, formatting

### Chapter 42 — Cache Design (LRU Cache)
- Entities: Cache, CacheEntry, EvictionPolicy
- Patterns: Strategy (eviction policy — LRU/LFU/FIFO), Proxy (cache as proxy to data source), Singleton (cache instance)
- Features: Thread-safe, pluggable eviction, capacity management

---

## Phase 6: Advanced Topics (Chapters 43–46)

### Chapter 43 — Concurrency in LLD
- Thread safety in Singleton and shared resources
- synchronized, volatile, Locks, ReadWriteLock
- Producer-Consumer pattern
- Thread-safe collections
- Code example: Thread-safe Singleton, Concurrent cache

### Chapter 44 — Refactoring & Code Smells
- Common smells: God class, Feature envy, Long method, Shotgun surgery
- Refactoring techniques: Extract method, Move method, Replace conditional with polymorphism
- Before/After examples for each smell
- Assignments: Refactor a messy codebase applying learned patterns

### Chapter 45 — Testing & Testable Design
- Unit testing with JUnit 5
- Dependency Injection for testability
- Mocking with Mockito
- Testing patterns (Builder for test data, Test doubles)
- Code example: Testing a Strategy pattern, Testing Observer interactions

### Chapter 46 — LLD Interview Strategies
- Step-by-step approach: Requirements → Entities → Relationships → Patterns → Code
- Time management in 45-min interviews
- Communication framework
- Common interview questions mapped to chapters
- Practice: Timed design exercises

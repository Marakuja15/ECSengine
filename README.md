# ECS Engine

A 2D game engine built from scratch in C++17 using an Entity Component System architecture and raylib for rendering.

## Overview

This project is a custom game engine centered around a clean ECS (Entity Component System) design. The goal is to build a lightweight, modular engine where gameplay logic is driven entirely by composable components and stateless systems operating on them.

The rendering layer uses raylib 5.5, fetched automatically via CMake's FetchContent.

## Architecture

The engine is split into two layers: the core ECS framework (`Engine/`) and game-specific code (`Game/`).

### Entity

An entity is a lightweight identifier consisting of a numeric ID and a generation counter. The generation field is used to distinguish recycled entity slots from their previous occupants, preventing stale references from accidentally accessing data that belongs to a new entity.

### EntityManager

Responsible for creating and destroying entities. Internally it maintains a contiguous vector of all entity slots alongside a free list of recycled slots. When a new entity is requested, the manager first checks the free list. If a recycled slot is available, its generation is incremented and the slot is reused. Otherwise a new slot is appended to the vector.

### ComponentArray

A type-erased, per-component-type storage container. Each `ComponentArray<T>` holds an `unordered_map` mapping entity IDs to component instances of that type. It supports adding, removing, querying, and checking existence of components for a given entity. All concrete arrays implement a common `IComponentArray` interface so that the ComponentManager can store and iterate them polymorphically.

### ComponentManager

Owns all component arrays and provides a typed API for adding, getting, checking, and removing components on entities. Internally it uses `std::type_index` as a key to look up or lazily create the appropriate `ComponentArray<T>`. It also exposes a `RemoveAllComponents` method that iterates every registered array and strips all data associated with a given entity, which is used during entity destruction.

### System and SystemManager

A system is any class implementing `ISystem` with a single `Update(World&)` method. The SystemManager holds two separate pipelines of systems: update systems (game logic) and render systems (drawing). Each frame, the manager runs all update systems first, then all render systems, both receiving a reference to the World so they can query and modify entities and components freely.

### World

The central facade that ties everything together. World owns an EntityManager and a ComponentManager and exposes a unified API for creating and destroying entities, attaching and detaching components, and querying entities. Its `View<Components...>()` method uses a variadic template fold expression to iterate all living entities and return only those possessing every requested component type. World also tracks delta time for frame-independent logic.

## Building

The project uses CMake and automatically downloads raylib 5.5 via FetchContent.

```
cmake -S . -B build
cmake --build build
```

On Windows the build additionally links `winmm` for multimedia timer support required by raylib.

## Current status

The core ECS loop is functional. Entities can be created and destroyed with generational recycling, components can be freely attached and queried, systems run each frame in the correct phase order, and a basic raylib window renders entities with a Position component as circles.

### What remains to be done

The `IsAlive` method in EntityManager is declared but has no implementation yet, which means the alive-check used by `GetEntities` does not actually filter anything. This needs to be completed so that destroyed entities are properly excluded from queries and Views.

The component storage currently uses `std::unordered_map` keyed by entity ID. The next planned step is to replace these maps with sparse sets. Sparse sets provide O(1) insertion, removal, and lookup like a hash map, but they also store components in a dense, contiguous array. This means iterating over all components of a given type becomes a simple linear scan through tightly packed memory, which is significantly more cache-friendly and faster in practice than chasing pointers through hash table buckets. This change is the single most impactful architectural improvement on the roadmap.

Beyond that, the engine still needs input handling, a proper asset and resource management layer, collision detection, audio support, scene management, and a sprite rendering system to replace the current placeholder circle drawing.

## License

MIT

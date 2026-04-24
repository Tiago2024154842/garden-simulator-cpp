<div align="center">

# Garden Simulator | Simulador de Jardim

**Object-Oriented Programming — ISEC 2025/2026**

![C++](https://img.shields.io/badge/C%2B%2B-20-blue?logo=cplusplus&logoColor=white)
![Build](https://img.shields.io/badge/Build-CMake-064F8C?logo=cmake&logoColor=white)
![IDE](https://img.shields.io/badge/IDE-CLion-000000?logo=jetbrains&logoColor=white)
![Grade](https://img.shields.io/badge/Grade-19%2F20-brightgreen)
![License](https://img.shields.io/badge/License-Academic-yellow)

A console-based garden simulation engine built in modern C++20, featuring polymorphic plant species, tool management, turn-based time progression, and a command-driven interface — developed as a coursework project for the Object-Oriented Programming course at Instituto Superior de Engenharia de Coimbra (ISEC).

</div>

---

<details open>
<summary><strong>🇬🇧 English</strong></summary>

## Overview

This project implements a fully interactive **garden simulator** where the user takes the role of a gardener managing a rectangular grid-based garden. Plants grow, multiply, and die according to species-specific rules. Tools degrade with use. Time advances in discrete turns, and all interaction happens through a text-based command interface.

The simulator was designed with a strong emphasis on **OOP principles**: inheritance hierarchies, polymorphism, encapsulation, dynamic memory management, and the **Factory design pattern** for command dispatching.

## Architecture

```
Trabalho_POO/
├── main.cpp                  # Entry point — REPL command loop
├── ComandoFactory.h/.cpp     # Factory Pattern — command creation & dispatching
├── Settings.h                # Centralized configuration constants
├── Comandos/
│   └── Comando.h/.cpp        # Abstract command base class + all command subclasses
├── Jardim/
│   ├── Jardim.h/.cpp         # Garden grid management & display
│   ├── Celula.h/.cpp         # Individual soil cell (water, nutrients)
│   ├── Planta.h/.cpp         # Plant hierarchy (Cacto, Roseira, ErvaDaninha, Bananeira)
│   ├── Ferramenta.h/.cpp     # Tool hierarchy (Regador, Adubo, Tesoura, Enxada)
│   └── Jardineiro.h/.cpp     # Gardener entity (movement, inventory, actions)
└── Random/
    └── Random.h/.cpp         # Random number generation utility
```

## Key Design Decisions

### Factory Pattern

The `ComandoFactory` class is the central command dispatcher. It maps command strings to concrete `Comando` subclass instances, decoupling parsing logic from execution. This makes the system easily extensible — adding a new command requires only a new subclass and a single line in the factory method.

### Class Hierarchy

**Plants** inherit from an abstract `Planta` base class, each species implementing its own behavior for absorption, death conditions, and multiplication: Cacto (cactus), Roseira (rose bush), ErvaDaninha (weed), and Bananeira (banana tree — the custom exotic plant).

**Tools** follow a similar polymorphic structure: Regador (watering can), Pacote de Adubo (fertilizer), Tesoura de Poda (pruning shears), and Enxada (hoe — the custom tool that enriches soil nutrients at the cost of water).

### Memory Management

The garden grid is implemented as a **raw 2D dynamic array** (no STL containers for the grid, as required by the assignment). Deep copy semantics are implemented for the save/restore functionality (`grava`/`recupera` commands), ensuring correct snapshot and rollback behavior.

## Features

- **Turn-based simulation** — time advances on user command; plants react each turn
- **4 plant species** with unique growth, death, and reproduction mechanics
- **4 tool types** with durability and specialized effects
- **Gardener movement** with per-turn action limits (moves, plantings, harvests)
- **Save & restore** — snapshot the garden state and recover it later
- **Script execution** — batch commands from file (`executa` command)
- **Full input validation** — syntax checking and meaningful error messages
- **Console grid display** with labeled coordinate rulers

## Commands Reference

| Command | Description |
|---|---|
| `jardim <rows> <cols>` | Create the garden (must be first command) |
| `avanca [n]` | Advance n time instants (default: 1) |
| `planta <pos> <type>` | Plant a new plant (c/r/e/x) |
| `colhe <pos>` | Harvest a plant |
| `entra <pos>` | Gardener enters the garden |
| `sai` | Gardener exits the garden |
| `e / d / c / b` | Move gardener (left/right/up/down) |
| `compra <type>` | Buy a tool (g/a/t/z) |
| `pega <id>` | Pick up tool by serial number |
| `larga` | Put down current tool |
| `lplantas / lplanta <pos>` | List plants info |
| `larea / lsolo <pos> [n]` | List area/soil info |
| `lferr` | List gardener's tools |
| `grava <name>` | Save garden snapshot |
| `recupera <name>` | Restore garden snapshot |
| `apaga <name>` | Delete a snapshot |
| `executa <file>` | Run commands from file |
| `fim` | Exit the program |

Developed for the Object-Oriented Programming course (2025/2026) at DEIS — Instituto Superior de Engenharia de Coimbra.

</details>

---

<details>
<summary><strong>🇵🇹 Português</strong></summary>

## Visão Geral

Este projeto implementa um **simulador de jardim** totalmente interativo, onde o utilizador assume o papel de jardineiro a gerir um jardim baseado numa grelha retangular. As plantas crescem, multiplicam-se e morrem de acordo com regras específicas de cada espécie. As ferramentas desgastam-se com o uso. O tempo avança em turnos discretos e toda a interação é feita através de uma interface de comandos por texto.

O simulador foi desenhado com forte ênfase nos **princípios de POO**: hierarquias de herança, polimorfismo, encapsulamento, gestão dinâmica de memória e o **padrão de design Factory** para despacho de comandos.

## Arquitetura

```
Trabalho_POO/
├── main.cpp                  # Ponto de entrada — ciclo REPL de comandos
├── ComandoFactory.h/.cpp     # Factory Pattern — criação e despacho de comandos
├── Settings.h                # Constantes de configuração centralizadas
├── Comandos/
│   └── Comando.h/.cpp        # Classe base abstrata + todas as subclasses de comando
├── Jardim/
│   ├── Jardim.h/.cpp         # Gestão da grelha do jardim e visualização
│   ├── Celula.h/.cpp         # Célula individual de solo (água, nutrientes)
│   ├── Planta.h/.cpp         # Hierarquia de plantas (Cacto, Roseira, ErvaDaninha, Bananeira)
│   ├── Ferramenta.h/.cpp     # Hierarquia de ferramentas (Regador, Adubo, Tesoura, Enxada)
│   └── Jardineiro.h/.cpp     # Entidade jardineiro (movimento, inventário, ações)
└── Random/
    └── Random.h/.cpp         # Utilitário de geração de números aleatórios
```

## Decisões de Design

### Padrão Factory

A classe `ComandoFactory` é o dispatcher central de comandos. Mapeia strings de comando para instâncias concretas de subclasses de `Comando`, desacoplando a lógica de parsing da execução. Isto torna o sistema facilmente extensível — adicionar um novo comando requer apenas uma nova subclasse e uma única linha no método factory.

### Hierarquia de Classes

As **plantas** herdam de uma classe base abstrata `Planta`, cada espécie implementando o seu próprio comportamento de absorção, condições de morte e multiplicação: Cacto, Roseira, Erva-Daninha e Bananeira (a planta exótica personalizada).

As **ferramentas** seguem uma estrutura polimórfica semelhante: Regador, Pacote de Adubo, Tesoura de Poda e Enxada (a ferramenta personalizada que enriquece os nutrientes do solo à custa de água).

### Gestão de Memória

A grelha do jardim é implementada como um **array dinâmico 2D raw** (sem containers STL para a grelha, conforme exigido pelo enunciado). A semântica de cópia profunda é implementada para a funcionalidade de guardar/restaurar (comandos `grava`/`recupera`), garantindo comportamento correto de snapshot e rollback.

## Funcionalidades

- **Simulação por turnos** — o tempo avança por comando do utilizador; as plantas reagem a cada turno
- **4 espécies de plantas** com mecânicas únicas de crescimento, morte e reprodução
- **4 tipos de ferramentas** com durabilidade e efeitos especializados
- **Movimento do jardineiro** com limites de ações por turno (movimentos, plantações, colheitas)
- **Guardar e restaurar** — snapshot do estado do jardim com recuperação posterior
- **Execução de scripts** — comandos em lote a partir de ficheiro (comando `executa`)
- **Validação completa de input** — verificação sintática e mensagens de erro significativas
- **Visualização da grelha na consola** com réguas de coordenadas

## Referência de Comandos

| Comando | Descrição |
|---|---|
| `jardim <linhas> <colunas>` | Criar o jardim (deve ser o primeiro comando) |
| `avanca [n]` | Avançar n instantes de tempo (padrão: 1) |
| `planta <pos> <tipo>` | Plantar uma nova planta (c/r/e/x) |
| `colhe <pos>` | Colher uma planta |
| `entra <pos>` | Jardineiro entra no jardim |
| `sai` | Jardineiro sai do jardim |
| `e / d / c / b` | Mover jardineiro (esquerda/direita/cima/baixo) |
| `compra <tipo>` | Comprar uma ferramenta (g/a/t/z) |
| `pega <id>` | Pegar ferramenta pelo número de série |
| `larga` | Largar ferramenta atual |
| `lplantas / lplanta <pos>` | Listar informação de plantas |
| `larea / lsolo <pos> [n]` | Listar informação da área/solo |
| `lferr` | Listar ferramentas do jardineiro |
| `grava <nome>` | Guardar snapshot do jardim |
| `recupera <nome>` | Restaurar snapshot do jardim |
| `apaga <nome>` | Apagar um snapshot |
| `executa <ficheiro>` | Executar comandos de ficheiro |
| `fim` | Encerrar o programa |

Desenvolvido para a cadeira de Programação Orientada a Objetos (2025/2026) no DEIS — Instituto Superior de Engenharia de Coimbra.

</details>

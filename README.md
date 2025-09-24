# 🍭 COS110 Day 2: The Great Yorozuya Memory Management Crisis!

**A Swift Tuition C++ Practical Experience**

---

## 🎌 Welcome to Kabuki District's Programming Dojo!

Gintoki and the Yorozuya gang need your help to create a memory management system that won't crash worse than Gintoki's attempts at being productive. This practical combines serious C++ concepts with the chaotic humor you'd expect from everyone's favorite silver-haired samurai.

### 📖 The Story
Read the full ridiculous scenario in [`docs/STORY.md`](docs/STORY.md) - trust us, it's worth it!

### 🎯 Learning Objectives
By the end of this practical, you'll master:
- **Dynamic Memory Allocation** using `new` and `delete`
- **Pointer Management** and pointer arithmetic
- **Dynamic Arrays** (1D and 2D)
- **Memory Leak Prevention**
- **Deep vs Shallow Copy** concepts
- **Proper Resource Management**

---

## 🚀 Quick Start

### Option 1: GitHub Codespaces (Recommended)
1. Click the big green "Code" button above
2. Select "Codespaces" tab
3. Click "Create codespace on main"
4. Wait for the magic to happen ✨
5. Start coding in your browser!

### Option 2: Local Development
```bash
git clone [repository-url]
cd COS110_Day2_Project
make run
```

---

## 🛠️ Available Commands

| Command | Description | Points |
|---------|-------------|---------|
| `make run` | Compile and run your program | - |
| `make check-basic` | Test basic functionality | 40% |
| `make check-edge` | Test edge cases and error handling | 30% |
| `make check-memory` | Valgrind memory leak detection | 20% |
| `make check-full` | Complete test suite | 100% |

---

## 📋 Project Requirements

### Core Features to Implement

#### 1. 📝 Client Management System
- Store client names dynamically
- Add/remove clients without memory waste
- Handle resizing when capacity is exceeded

#### 2. 💼 Job Tracker
- Use pointer arrays for job descriptions
- Dynamic allocation for variable-length strings
- Link jobs to specific clients

#### 3. 🍖 Sadaharu's Food Inventory
- 2D dynamic arrays for food management
- Track different food types and quantities
- Daily consumption updates

#### 4. 👓 Shinpachi's Glasses Collection
- Multi-dimensional array organization
- Backup glasses storage system
- Efficient access patterns

#### 5. 🧹 Memory Cleanup Protocol
- No memory leaks allowed!
- Proper destructor implementation
- Deep copy when needed

---

## 📊 Grading Breakdown

- **Basic Functionality (40%)**: Core features work correctly
- **Edge Cases (30%)**: Handles invalid input and boundary conditions
- **Memory Management (20%)**: No leaks, proper cleanup
- **Code Quality (10%)**: Following specifications, good practices

---

## 🤖 AI Assistant Setup

Need help debugging? We've got you covered!

```bash
# Set up AI assistance
./scripts/setup_gemini.sh

# Get help with your code
cat scripts/gemini_prompt_template.txt
```

The AI assistant is configured to guide you toward solutions rather than give you answers directly - perfect for learning!

---

## 📁 Project Structure

```
COS110_Day2_Project/
├── docs/                    # Project documentation
│   ├── STORY.md            # The ridiculous Gintama scenario
│   └── INSTRUCTIONS.md     # Detailed requirements
├── src/                     # Your code goes here
│   ├── main.cpp            # Main program file
│   ├── yorozuya.h          # Header file
│   └── yorozuya.cpp        # Implementation file
├── tests/                   # Automated testing
├── scripts/                 # Helper scripts
└── Makefile                # Build and test commands
```

---

## ⚠️ Important Notes

- **C++98 Standard**: Use `NULL` instead of `nullptr`
- **Memory Management**: Every `new` needs a corresponding `delete`
- **No STL Containers**: Implement everything from scratch
- **30-minute target**: Aim to complete within this timeframe

---

## 🆘 Getting Help

### Immediate Assistance
- Use the integrated AI assistant (setup instructions above)
- Check [`docs/INSTRUCTIONS.md`](docs/INSTRUCTIONS.md) for detailed specs
- Run `make check-basic` to see what's missing

### Swift Tuition Support
- **Email**: admin@swifttuition.co.za
- **WhatsApp**: +27 73 499 6948
- **Support Page**: [Swift Tuition COS110 Support](link-to-be-added)

---

## 🎯 Success Tips

1. **Read the story first** - it's actually helpful and hilarious
2. **Start with basic structures** before adding complexity
3. **Test frequently** using the provided commands
4. **Use the AI assistant** when stuck - it's like having Shinpachi explain things!
5. **Don't forget cleanup** - memory leaks make Gintoki sad

---

**Good luck, and remember**: In the words of Gintoki, "Life is basically about how much you can get away with" - but in C++, you can't get away with memory leaks! 🎌

---

*© 2025 Swift Tuition - Making C++ education as entertaining as possible (which honestly isn't saying much, but we try)*
# 🎌 COS110 Day 2 Project Support Hub

**The Great Yorozuya Memory Management Crisis - Student Support Center**

---

## 🎬 Getting Started Video Tutorial

<!-- YouTube Video Placeholder - Day 2 Introduction -->
<div style="text-align: center; margin: 2rem 0;">
    <iframe width="560" height="315" src="https://www.youtube.com/embed/PLACEHOLDER_VIDEO_ID_INTRO"
            title="COS110 Day 2 - Introduction to Memory Management Project"
            frameborder="0"
            allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
            allowfullscreen>
    </iframe>
    <p><em>Day 2 Project Introduction & Overview</em></p>
</div>

---

## 🚀 Quick Start Guide

### Step 1: Launch Your Development Environment
**One-Click Setup with GitHub Codespaces:**

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](PLACEHOLDER_CODESPACES_LINK)

*Click the button above to launch a fully configured C++ development environment in your browser!*

### Step 2: Understand the Project
1. Read the hilarious [`docs/STORY.md`](STORY.md) - Yes, it's actually helpful!
2. Review the technical specs in [`docs/INSTRUCTIONS.md`](INSTRUCTIONS.md)
3. Examine the starter code in `src/` directory

### Step 3: Start Coding
```bash
# Test your setup
make run

# Run basic tests
make check-basic

# Check for memory leaks
make check-memory

# Complete test suite
make check-full
```

---

## 💬 Join the Community

**Need help from fellow students or want to collaborate?**

[![Join WhatsApp Group](https://img.shields.io/badge/WhatsApp-25D366?style=for-the-badge&logo=whatsapp&logoColor=white)](https://chat.whatsapp.com/HH45aFDchGRByVpdIwHtsj)

*Click above to join the COS110 10-Day Programme WhatsApp group for peer support, announcements, and study coordination!*

---

## ❓ Common Issues & Solutions

### 🔧 Compilation Issues

**Q: "My code won't compile - undefined reference errors"**
- **A:** You haven't implemented all the required methods yet. Check your `yorozuya.cpp` file and look for `TODO` comments.

**Q: "Memory leak errors with Valgrind"**
- **A:** Every `new` needs a corresponding `delete`. Check your destructor and make sure you're cleaning up all dynamic memory.

**Q: "Segmentation fault when running"**
- **A:** You're likely accessing uninitialized pointers. Make sure to initialize all pointers to `NULL` in your constructor.

### 💾 Memory Management Issues

**Q: "My copy constructor isn't working"**
- **A:** Are you doing a deep copy? You need to allocate new memory and copy the data, not just copy pointers.

**Q: "Program crashes when adding many clients"**
- **A:** Implement the `resizeClientArrays()` method to handle capacity expansion.

**Q: "Tests are failing"**
- **A:** Run `make check-basic` first, then `make check-edge`, then `make check-memory`. Fix issues in that order.

### 🎯 Project-Specific Help

**Q: "I don't understand the Gintama references"**
- **A:** Don't worry! The humor is just for fun. Focus on the technical requirements in `INSTRUCTIONS.md`.

**Q: "What's the difference between shallow and deep copy?"**
- **A:** Shallow copy copies pointers, deep copy copies the actual data. You need deep copy for this project.

**Q: "How do I handle string allocation?"**
- **A:** Use `strlen()` to get length, allocate `length + 1` bytes, then `strcpy()` to copy.

---

## 🤖 AI Assistant Setup (For Dummies Guide)

### Quick Setup (The Really Easy Way)

1. **Run the setup script:**
   ```bash
   ./scripts/setup_gemini.sh
   ```

2. **Get your free API key:**
   - Go to: https://makersuite.google.com/app/apikey
   - Sign in with your Google account (the one you use for Gmail/YouTube)
   - Click "Create API Key"
   - Copy the long string of letters and numbers

3. **Set your API key:**
   ```bash
   export GEMINI_API_KEY=your_api_key_here
   ```
   *(Replace "your_api_key_here" with what you copied)*

4. **Ask for help:**
   ```bash
   gemini-cli "My code is crashing when I create a YorozuyaManager object"
   ```

### What the AI Assistant Does:
- **Guides you** toward solutions (doesn't give direct answers)
- **Explains concepts** you don't understand
- **Helps debug** your specific errors
- **Teaches you** proper C++ practices

### Important Notes:
- 🎓 The AI helps you **learn**, not cheat
- 📚 It explains **why** things work, not just **how**
- 🤝 Use it when you're **stuck**, not as a shortcut
- 🔍 **We'll do a deeper dive into AI-assisted programming on Day 10!**

---

## 📝 Testing Commands Reference

| Command | Purpose | Points |
|---------|---------|---------|
| `make run` | Compile and run your program | - |
| `make check-basic` | Test core functionality | 40% |
| `make check-edge` | Test edge cases & error handling | 30% |
| `make check-memory` | Valgrind memory leak detection | 20% |
| `make check-full` | Complete test suite | 100% |
| `make clean` | Clean up build files | - |
| `make help` | Show all available commands | - |

### Pro Testing Tips:
- ✅ Start with `make check-basic` and get that passing first
- ⚠️ Fix compilation errors before worrying about test failures
- 🧠 Use `make check-memory` frequently - memory leaks are sneaky
- 🎯 Aim for 100% on `make check-full` before submission

---

## 📺 Complete Video Tutorial

<!-- YouTube Video Placeholder - Day 2 Complete Tutorial -->
<div style="text-align: center; margin: 2rem 0;">
    <iframe width="560" height="315" src="https://www.youtube.com/embed/PLACEHOLDER_VIDEO_ID_COMPLETE"
            title="COS110 Day 2 - Complete Memory Management Project Tutorial"
            frameborder="0"
            allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture"
            allowfullscreen>
    </iframe>
    <p><em>Complete Day 2 Project Walkthrough & Implementation Guide</em></p>
</div>

---

## 📞 Get Additional Help

### 🐛 Technical Issues
**Found a bug or have suggestions for improvement?**

📧 **Email:** [christian@swifttuition.co.za](mailto:christian@swifttuition.co.za?subject=COS110%20Day%202%20Bug%20Report&body=Please%20describe%20the%20issue%20you%20encountered:)

*Please include error messages, screenshots, and steps to reproduce the issue.*

### 📚 Tuition & Course Questions
**Need help with course content or have questions about Swift Tuition?**

📧 **Course Admin:** [admin@swifttuition.co.za](mailto:admin@swifttuition.co.za?subject=COS110%20Course%20Question)

📱 **WhatsApp Business:** [+27 73 499 6948](https://wa.me/27734996948?text=Hi,%20I%20have%20a%20question%20about%20the%20COS110%20course)

---

## 🎌 Final Reminders

### The Yorozuya Way:
- **Gintoki's Wisdom:** "Even if it's difficult, you still gotta do the work yourself!"
- **Shinpachi's Advice:** "Understanding beats memorization every time!"
- **Kagura's Motivation:** "Code with the intensity of protecting your last sukonbu!"

### Success Checklist:
- [ ] Read the story (it's actually educational)
- [ ] Understand the memory management concepts
- [ ] Implement one feature at a time
- [ ] Test frequently with `make` commands
- [ ] Use the AI assistant when stuck
- [ ] Ask for help in the WhatsApp group
- [ ] Don't give up - memory management is tough but learnable!

---

**Good luck, and remember:** In the world of C++, proper memory management is the difference between being a hero and causing a segfault disaster! 🚀

*© 2025 Swift Tuition - Making C++ Education Less Painful Than Gintoki's Work Ethic*
# Who Wants To Be A Millionaire- C Project

This is a C language project that replicates the popular quiz show **"Who Wants To Be A Millionaire**.  
The player must answer multiple-choice questions correctly to win increasing prize amounts. The game includes a timeout feature for each question and terminal control for better gameplay experience.

---

## 📜 Features

- Read questions, options, answers, timeout, and prize money from a file (`questions.txt`).
- 15-second timeout per question (customizable).
- Instant single-key input without needing to press Enter.
- Automatic uppercase conversion of answers (accepts 'a', 'A', etc.).
- Clean terminal input handling (no extra characters displayed).
- Proper resource management (memory allocation and deallocation).
- Game ends if:
  - Wrong answer is given.
  - Timeout occurs.
  - Player answers all questions correctly.

---

## 🛠️ Technologies Used

- **C Language**
- **GCC Compiler** (or any standard C compiler)
- **Linux/Unix System** (for `alarm`, `signal`, and `termios` features)

---

---

## 🚀 How to Run

1. **Clone the repository** or download the source code.

2. **Prepare your questions file** (`questions.txt`) following this format:

   ```
   Question 1 text
   Option A
   Option B
   Option C
   Option D
   Correct Answer (A/B/C/D)
   Timeout in seconds
   Prize amount
   (Repeat for next question)
   ```

3. **Compile the program** using `gcc`:

   ```bash
   gcc quiz.c -o game
   ```

4. **Run the program**:
   ```bash
   ./game
   ```

---

## ⚙️ Functions Overview

| Function      | Purpose                                                       |
| :------------ | :------------------------------------------------------------ |
| `exit()`      | Exit the program cleanly.                                     |
| `toupper()`   | Convert character input to uppercase.                         |
| `signal()`    | Set custom handlers for signals like timeout.                 |
| `alarm()`     | Set a countdown timer per question.                           |
| `getchar()`   | Read player input (answer choices).                           |
| `fflush()`    | Instantly flush output buffer.                                |
| `fopen()`     | Open the questions file for reading.                          |
| `fgets()`     | Read each line from the file.                                 |
| `rewind()`    | Rewind the file pointer to the start after counting lines.    |
| `malloc()`    | Allocate memory dynamically for storing questions.            |
| `tcgetattr()` | Get current terminal attributes.                              |
| `tcsetattr()` | Set terminal attributes for instant character input.          |
| `atexit()`    | Ensure terminal settings are restored when the program exits. |

---

## ⚡ Important Notes

- This project uses **Linux system-specific** functions like `alarm()`, `signal()`, `termios`, so it may **not run correctly on Windows** unless you use a Linux environment or tools like **WSL (Windows Subsystem for Linux)**.
- **Proper formatting** of `questions.txt` is critical. No extra spaces or missing lines!

---

## 📜 License

This project is open source and free to use for educational purposes.  
Feel free to modify and improve it!

---

## 🙏 Acknowledgements

Inspired by the classic TV show **"Who Wants To Be A Millionaire"** and designed for practicing C programming concepts like:

- File handling
- Dynamic memory allocation
- Signal handling
- Terminal control

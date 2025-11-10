# Simple Shell

## Description
This project is a simple UNIX command interpreter (shell) built as part of the Holberton School Low-Level Programming curriculum.  
It mimics basic functionalities of `/bin/sh` including executing commands, managing environment variables, and handling interactive and non-interactive modes.

---

## Features
- Display a prompt and wait for the user to type a command.
- Handle commands with arguments.
- Handle the PATH to find executables.
- Implement built-in commands: `exit`, `env`.
- Works in both **interactive** and **non-interactive** mode.
- Proper error handling and exit status.
- No memory leaks (checked with Valgrind).

---

## Compilation
The shell is compiled using:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Usage

### Interactive Mode
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($) ls -l
total 28
-rw-rw-r-- 1 user user  131 Nov 10 12:00 AUTHORS
-rw-rw-r-- 1 user user 1024 Nov 10 12:00 README.md
($) exit
$
```

### Non-Interactive Mode
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c
$ echo "ls" | ./hsh
AUTHORS  README.md  execute.c  main.c  shell.c  shell.h  utils.c
```

---

## Built-in Commands

| Command | Description |
|---------|-------------|
| `exit`  | Exit the shell |
| `env`   | Print the current environment variables |

---

## Files

| File | Description |
|------|-------------|
| `main.c` | Entry point for the shell |
| `shell.c` | Main shell loop and input handling |
| `shell.h` | Header file with function prototypes |
| `execute.c` | Command execution logic |
| `utils.c` | Utility functions (PATH resolution, memory management) |
| `AUTHORS` | List of contributors |
| `README.md` | This file |
| `man_1_simple_shell` | Manual page for the shell |

---

## Authors
- **Almansour Khaled Shaden** - [GitHub](https://github.com/illo888)
- **Tariq Almutairi** - [GitHub](https://github.com/tariqRash)

---

## License
This project is part of the Holberton School curriculum.

---

## Testing

### Run All Tests
```bash
./run_tests.sh
```

### Manual Testing

**Interactive mode:**
```bash
$ ./hsh
($) ls
($) /bin/pwd
($) env
($) exit
```

**Non-interactive mode:**
```bash
$ echo "ls" | ./hsh
$ echo "env" | ./hsh
```

### Check for Memory Leaks
```bash
echo "exit" | valgrind --leak-check=full ./hsh
```

### Betty Style Check
```bash
betty *.c *.h
```

---

## Project Structure
```
holbertonschool-simple_shell/
├── AUTHORS                 # Contributors list
├── README.md              # This file
├── CHECKLIST.md          # Project completion checklist
├── main.c                # Entry point
├── shell.c               # Main shell loop
├── shell.h               # Header file
├── execute.c             # Command execution
├── builtins.c            # Built-in commands
├── utils.c               # Utility functions
├── error_handler.c       # Error handling
├── man_1_simple_shell    # Manual page
├── run_tests.sh          # Test suite
└── .gitignore            # Git ignore rules
```

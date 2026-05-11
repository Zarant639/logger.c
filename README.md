```markdown
# Age Logger

A simple terminal utility written in C.  
It asks for your age, validates the input, and logs the age with a timestamp to a file.

## Features
- Only numeric input allowed (range 0–127)
- Dynamic memory allocation with error handling (`malloc` / `perror`)
- Age classification: prints `Baby` for age < 14
- Timestamp logging
- Configurable max attempts (default 3)
- Logs saved to `age.log` in the current directory

## Build and Run

```bash
gcc age_logger.c -o age_logger
./age_logger
```

Example

```
=== Age Logger ===
Enter the age: 25
Successful
2025-05-11 14:30:15 - 25
=== Log saved successfully ===
```

Log file example (age.log)

```
2025-05-11 14:30:15 - 25
```

Purpose

This project was created for learning:

· C language basics
· Memory management (malloc, free)
· Standard library functions (stdio.h, time.h, stdlib.h, errno.h)
· Input validation and error handling

License

GNU General Public License v2.0 — see LICENSE file for details.

Author

Zarant639

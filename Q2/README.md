VRATI SAGAR SURANA
01384

# Question 2 – Process Management Using fork(), wait(), and Signals

## Objective

Develop a C program that:

- Creates child processes using `fork()`.
- Monitors child execution.
- Prevents zombie processes using `wait()`.
- Terminates unresponsive child processes using signals.

---

## Compilation

```bash
gcc Question2.c -o Question2
```

## Execution

```bash
./Question2
```

---

## Linux System Calls Used

| Function | Purpose |
|----------|---------|
| `fork()` | Creates child processes. |
| `wait()` | Waits for child processes to finish and prevents zombie processes. |
| `kill()` | Sends signals to terminate unresponsive child processes. |
| `sleep()` | Simulates execution delays. |
| `exit()` | Terminates a child process normally. |

---

## Working

1. The parent process creates three child processes.
2. Two child processes complete normally.
3. One child process is intentionally made unresponsive.
4. The parent detects the situation and terminates it using `SIGKILL`.
5. `wait()` collects the exit status of all children, preventing zombie processes.

---

## Conclusion

This program demonstrates Linux process management by creating child processes, monitoring their execution, terminating unresponsive processes using signals, and preventing zombie processes through proper use of `wait()`.

VRATI SAGAR SURANA
01384

# Question 3 – File Processing Using Linux System Calls

## Objective

Develop a C program using Linux system calls to:

- Create an employee data file.
- Write employee records.
- Update specific records without rewriting the entire file.
- Retrieve records efficiently using random access.

---

## Compilation

```bash
gcc Question3.c -o Question3
```

## Execution

```bash
./Question3
```

---

## Linux System Calls Used

| System Call | Purpose |
|-------------|---------|
| `open()` | Creates and opens the employee file. |
| `write()` | Writes employee records into the file. |
| `lseek()` | Moves the file pointer to a specific record for direct access. |
| `read()` | Reads employee records from the file. |
| `close()` | Closes the file and releases resources. |

---

## Working

1. Creates `employee.dat`.
2. Writes three employee records.
3. Uses `lseek()` to move to the second record.
4. Updates only the second record.
5. Reads the updated record using `read()`.
6. Closes the file using `close()`.

---

## Conclusion

The program demonstrates efficient file handling using Linux system calls. By combining `open()`, `read()`, `write()`, `lseek()`, and `close()`, it allows secure creation, direct updating, and retrieval of employee records without rewriting the entire file.

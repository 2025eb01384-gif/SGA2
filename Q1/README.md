VRATI SAGAR SURANA
01384

# Question 1 – Duplicate Submission Detection and Backup

## Objective
Design a shell script that:

- Identifies duplicate student submissions.
- Creates a backup of unique submissions.
- Generates a report showing:
  - Number of files processed
  - Number of duplicate files
  - Number of files backed up
- Stores all error messages in a separate log file.

---

## Files Included

- `duplicate_backup.sh` – Shell script to identify duplicates and back up unique files.
- `student1.txt` – Sample student submission.
- `student2.txt` – Duplicate of `student1.txt`.
- `student3.txt` – Unique student submission.
- `backup/` – Contains only the unique submissions.
- `Backup_Report.txt` – Displays the number of processed, duplicate, and backed-up files.
- `Error_Log.txt` – Stores any errors encountered during execution.

---

## Commands Used

### Create Sample Files

```bash
mkdir -p ~/Q1
cd ~/Q1

echo "Student A Assignment" > student1.txt
cp student1.txt student2.txt
echo "Student B Assignment" > student3.txt
```

### Make the Script Executable

```bash
chmod +x duplicate_backup.sh
```

### Run the Script

```bash
./duplicate_backup.sh .
```

---

## Linux Commands Used

| Command | Purpose |
|---------|---------|
| `cp` | Copies only unique files to the backup folder. |
| `shasum -a 256` | Generates a SHA-256 hash for each file to detect duplicates (macOS equivalent of `sha256sum`). |
| `grep` | Checks if a file hash already exists. |
| `awk` | Extracts the hash value from the `shasum` output. |
| `mktemp` | Creates a temporary file to store hashes. |
| `rm` | Deletes the temporary hash file after execution. |

---

## Redirection Operators

| Operator | Purpose |
|----------|---------|
| `>` | Creates or overwrites a file. |
| `>>` | Appends output to a file. |
| `2>>` | Redirects error messages (stderr) to `Error_Log.txt`. |

---

## Output

After execution, the script creates:

- `backup/` containing only unique files.
- `Backup_Report.txt` summarizing the results.
- `Error_Log.txt` containing any errors generated during execution.

---

## Conclusion

This shell script efficiently identifies duplicate student submissions using SHA-256 hashing, backs up only unique files, generates a processing report, and stores all error messages separately. The solution demonstrates the use of Linux shell scripting, file handling, hashing, loops, conditional statements, and input/output redirection.

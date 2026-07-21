VRATI SAGAR SURANA
01384

# Question 4 – Linux Log Monitoring Pipeline

## Objective

Design a Linux command pipeline that:

- Continuously monitors a log file.
- Displays newly added log entries in real time.
- Extracts only ERROR messages.
- Stores ERROR messages in a separate report file.
- Suppresses unnecessary error output.

---

## Command

```bash
tail -f system.log 2>/dev/null | grep "ERROR" >> Error_Report.txt
```

---

## Commands Used

| Command | Purpose |
|---------|---------|
| `tail -f` | Continuously monitors the log file for new entries. |
| `grep "ERROR"` | Filters and extracts only ERROR messages. |
| `|` (Pipe) | Passes the output of one command directly to another. |
| `>>` | Appends filtered messages to `Error_Report.txt`. |
| `2>/dev/null` | Redirects standard error to `/dev/null`, suppressing unnecessary output. |

---

## Conclusion

This command pipeline provides an efficient real-time log monitoring solution. It continuously watches the log file, filters only ERROR messages, saves them to a separate report file, and suppresses unnecessary error output, making system monitoring simpler and more efficient.

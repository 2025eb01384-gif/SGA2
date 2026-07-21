VRATI SURANA
01384

# Question 5 – vi Recovery Mechanisms

## Objective

Evaluate the recovery mechanisms available in the **vi** editor after a system crash and determine the most reliable recovery strategy.

## Scenario

A software developer is editing a critical configuration file using **vi**. Before saving the file, the system crashes unexpectedly. The goal is to recover the unsaved work using the recovery features provided by **vi**.

## Recovery Mechanisms

### 1. Swap Files

* `vi` automatically creates a swap (`.swp`) file while editing.
* It stores unsaved changes and allows recovery after a crash.
* Recovery can be performed using:

  ```bash
  vi -r config.txt
  ```

### 2. Undo History

* Undo (`u`) helps reverse changes during the current editing session.
* It is not useful after a crash because the undo history is usually lost.

### 3. Registers

* Registers temporarily store copied or deleted text.
* They are helpful during an active editing session but are generally unavailable after a crash.

### 4. Backup Files

* Backup files preserve the last saved version of the file if backups are enabled.
* They do not contain the latest unsaved changes.

### 5. Auto-Recovery

* When a swap file is detected, `vi` automatically offers to recover the file.
* This makes restoring unsaved work simple and effective.

## Most Reliable Recovery Strategy

The most reliable recovery strategy is to use **swap files together with vi's auto-recovery feature**.

### Justification

* Swap files continuously save editing progress.
* Auto-recovery detects the swap file after a crash and restores the latest recoverable version.
* This method preserves most unsaved work, unlike undo history, registers, or backup files.

## Commands Executed

### Open the file

```bash
vi config.txt
```

### Recover the file

```bash
vi -r config.txt
```

### Verify the swap file

```bash
ls -la
```

## Conclusion

Among all recovery mechanisms, **swap files and auto-recovery** provide the safest and most effective solution for recovering unsaved work after an unexpected system crash.


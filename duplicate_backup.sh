#!/bin/bash

SOURCE_DIR="$1"
BACKUP_DIR="backup"
REPORT_FILE="Backup_Report.txt"
ERROR_LOG="Error_Log.txt"

mkdir -p "$BACKUP_DIR" 2>>"$ERROR_LOG"

processed=0
duplicates=0
backedup=0

HASH_FILE=$(mktemp)

for file in "$SOURCE_DIR"/*
do
    [ -f "$file" ] || continue

    processed=$((processed+1))

    hash=$(shasum -a 256 "$file" 2>>"$ERROR_LOG" | awk '{print $1}')

    if grep -q "^$hash" "$HASH_FILE"
    then
        duplicates=$((duplicates+1))
    else
        echo "$hash" >> "$HASH_FILE"

        cp "$file" "$BACKUP_DIR"/ 2>>"$ERROR_LOG"

        backedup=$((backedup+1))
    fi
done

echo "===== Backup Report =====" > "$REPORT_FILE"
echo "Files Processed : $processed" >> "$REPORT_FILE"
echo "Duplicate Files : $duplicates" >> "$REPORT_FILE"
echo "Files Backed Up : $backedup" >> "$REPORT_FILE"

rm "$HASH_FILE"

echo "Done!"


#!/bin/bash
# 2023-03-19T1738+0100
cp Compose.yml Compose-backup.yml
echo "    Compose.yml is now backed up."
perl generate-multikey.pl

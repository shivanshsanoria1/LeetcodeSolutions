#!/usr/bin/env bash

START_MS=$(date +%s%3N) 

START_TIME=$(date -u +"%Y-%m-%d %H:%M:%S")
echo "[$START_TIME] Started stat-generator script..."

echo "--------------------"
echo "Running node commands..."
node ./stats/generator/stats-generator.js

echo "--------------------"
echo "Running python commands..."
source ./stats/generator/.venv/bin/activate
python3 ./stats/generator/chart-generator.py
deactivate
echo "--------------------"

END_TIME=$(date -u +"%Y-%m-%d %H:%M:%S")
echo "[$END_TIME] Stopped stat-generator script..."

END_MS=$(date +%s%3N) 
DURATION=$((END_MS - START_MS))
echo "Time taken to run script = $DURATION ms"

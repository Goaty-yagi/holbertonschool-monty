#!/bin/bash

# Fetch the latest changes from the remote repository
git fetch origin main

# Get a list of all local branches except for main
branches=$(git branch --list | grep -v "main")

# Loop through each branch (excluding main)
for branch in $branches
do
    # Rebase each branch onto origin/main
    git checkout $branch
    git rebase origin/main
done

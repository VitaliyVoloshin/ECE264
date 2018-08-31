#!/usr/bin/env bash

set -o errexit
set -o errtrace
set -o nounset
set -o pipefail
printf 'gitScript beginning...\n'
cd ~/ECE264
git remote rm origin
git remote add origin git@github.com:astpierre/ECE264.git
printf 'Removed, re-added remote origin.\n'
ssh-keygen -t rsa -b 4096 -C "web@github.com"
mv new264key ../.ssh
mv new264key.pub ../.ssh
printf 'Generated new key.\n'
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/new264key
printf 'Add the key below to your SSH deploy keys on GitHub.com\n'
cat ~/.ssh/new264key.pub

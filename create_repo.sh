#!/usr/bin/env bash
set -e
REPO_NAME="flamapp-ai-assignment"
echo "Creating local git repo in current directory..."
# configure git user for local commits
git init
git config user.email "you@example.com"
git config user.name "Pooja Kiragi"

# initial commit
git add .
git commit -m "chore: initial scaffold for Flamapp.AI assignment"

# simulate progressive commits
git commit --allow-empty -m "feat(android): add JNI native-lib example"
git commit --allow-empty -m "feat(web): add TypeScript webcam worker scaffold"
git commit --allow-empty -m "docs: add README and architecture docs"
git commit --allow-empty -m "chore: add create_repo script and gitignore"

echo "Created sample commit history locally."
echo ""
echo "Next steps to push to GitHub:"
echo "1) Create an empty repository on your GitHub account named 'flamapp-ai-assignment'"
echo "2) Run these commands:"
echo "   git remote add origin https://github.com/poojakiragi/flamapp-ai-assignment.git"
echo "   git branch -M main"
echo "   git push -u origin main"
echo ""
echo "If you prefer SSH push, use the SSH repo URL instead of HTTPS."

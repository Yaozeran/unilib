Git Cheat Sheet
===============

Basic
-----

Initiate
```
git init
```
Checkout 
```
git clone path\to\local
git clone username@host:/path/to/repository
```
Add new, modified file to stage
```
git add . (all)
git add file\path
```
Commit changes
```
git commit -m "msg"
```
Cancel staging
```
git reset . (all)
git add file\path
```
View status
```
git log --graph --all 
```

Remote
------

Add remote repository
```
git remote add remote-name url
```

Upload a branch of your git version history to your
remote repository
```
git push remote-name local-branch
```
Update the local branch with any updates from
the remote repository (on GitHub)
```
git pull remote-name local-branch
```
Config remote repos with ssh key, replace https with ssh
```
git remote set-url origin git@github.com:user-name/repo-name.git
```
Verify
```
git remote -v
```
Set global identity for remote
```
git config --global user.name "Your Name"
git config --global user.email "your_email@example.com"
```


Branching
---------
Create new branch
```
git branch new-feature-name
git checkout -b new-feature-name
```
Switch
```
git checkout branch-name
```
Delete branch
```
git branch -d feature-name
```
Merge another branch into your active branch
```
git merge another-branch-name
```

Feature Branch Workflow
-----------------------
1. Create a new branch
```
git checkout -b new-feature
...
git add .
git commit -m "msg"
```
2. Upload the feature branch to GitHub
```
git push origin new-feature
```
3. Create a pull request on GitHub (a pull request lets teammates do code reviews and add comments)
4. Merge the feature branch into the main branch (by opening the pull request in the browser and clicking "Merge pull request")
5. After merging, update the local repository
```
git checkout main
git pull origin main
```

Merge Conflicts in the Feature Branch Workflow
----------------------------------------------
1. Resolve the merge conflict on GitHub.
2. On computer
   1. Get the latest updates from main, get the latest updates from the feature branch
  ```
  git checkout main
  git pull origin main`
  ```
   2. Merge main into the feature branch
  ```
  git checkout feature
  git pull origin feature
  ```
   3. Merge main into the feature branch
  ```
  git checkout feature
  git merge main
  ```
   4. Push the resolved feature branch to GitHub
  ```
  git push origin feature4
  ```
   5. Now the pull request should be ready to merge again.

Remove file on git track
------------------------

```
git rm --cached -r $(git ls-files | grep .DS_Store)
git commit -m "Remove all DS_Store files from repo"
```

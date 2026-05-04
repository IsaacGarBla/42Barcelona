# 🔁 Git Workflow Guide

> A structured pull request workflow to ensure all changes are reviewed and the commit history stays clean.

---

## 📋 Table of Contents

- [Daily Workflow](#-daily-workflow)
- [Key Rules](#-key-rules)
- [Best Practices](#-best-practices)
- [Example Workflow](#-example-workflow)
- [Repository Rules](#-repository-rules)

---

## 🚀 Daily Workflow

### 1. Start from `main`

Always begin with the latest version of the repository:

```bash
git checkout main
git pull origin main
```

---

### 2. Create a New Branch

Create a branch for your feature or fix:

```bash
git checkout -b feature/login-form
```

Use consistent naming conventions:

| Prefix     | Use Case                             |
| ---------- | ------------------------------------ |
| `feature/` | New features                         |
| `fix/`     | Bug fixes                            |
| `chore/`   | Maintenance, dependencies, refactors |
| `docs/`    | Documentation updates                |

---

### 3. Make Changes and Commit

Work normally and commit your changes:

```bash
git add .
git commit -m "Add login form UI"
```

> 💡 You can make multiple commits on your branch — they will all be squashed into one clean commit when merged.

---

### 4. Push Your Branch

```bash
git push origin feature/login-form
```

---

### 5. Open a Pull Request (PR)

On GitHub:

1. Go to your repository
2. Click **"Compare & pull request"**
3. Set:
   - **Base** → `main`
   - **Compare** → your branch
4. Add:
   - A clear, descriptive **title**
   - A short **description** of what changed and why

---

### 6. Review Process

Your collaborator will:

- Review your code
- Leave inline comments if needed
- Approve the PR ✅

> ⚠️ **Important:** If you push new commits after approval, the approval is automatically removed and a new review is required.

---

### 7. Merge Using "Squash and Merge"

Once approved:

1. Click **"Squash and merge"**
2. Edit the final commit message if needed

**Example of a good squash commit message:**

```
Add login form with validation

- Input fields for email and password
- Client-side validation on submit
- Error messages for empty/invalid inputs
```

This keeps `main` clean: **1 PR = 1 commit**.

---

### 8. Delete the Branch

After merging, click **"Delete branch"** on GitHub to keep the repository tidy.

---

### 9. Sync Locally

```bash
git checkout main
git pull origin main
git branch -d feature/login-form
```

---

## 🔄 Repeat for Every Change

```
New branch → Commit → Push → PR → Review → Squash & Merge → Delete branch → Sync
```

---

## 🧠 Key Rules

### ✅ Always

- Branch from `main`
- Use pull requests — no direct pushes to `main`
- Wait for approval before merging
- Delete branches after merging

### ❌ Never

- Commit directly to `main`
- Merge your own PR (when strict review is required)
- Reuse old branches
- Force-push to shared branches

---

## 💡 Best Practices

### Keep Branches Small

Pull requests should be:

- Easy to review at a glance
- Focused on **a single change or feature**
- Ideally under **~300 lines of diff**

Smaller PRs get reviewed faster and are less likely to introduce bugs.

---

### Write Clear PR Titles

| ❌ Bad      | ✅ Good                                     |
| ----------- | ------------------------------------------- |
| `fix stuff` | `Fix login validation error on empty input` |
| `updates`   | `Update user avatar upload to support WebP` |
| `wip`       | `Add skeleton loading state to dashboard`   |

---

### Always Update Before Starting Work

```bash
git checkout main
git pull
```

This reduces the chance of merge conflicts before you even start.

---

### Write Meaningful Commit Messages

Follow the pattern: **`<verb> <what> <context>`**

```bash
# ✅ Good
git commit -m "Fix null pointer error in auth middleware"
git commit -m "Add pagination to user list endpoint"

# ❌ Bad
git commit -m "fix"
git commit -m "stuff"
```

---

## 🧪 Example Workflow

```bash
# 1. Start fresh from main
git checkout main
git pull

# 2. Create a new branch
git checkout -b fix/button-color

# 3. Make your changes, then stage and commit
git add .
git commit -m "Fix primary button color on homepage CTA"

# 4. Push to remote
git push origin fix/button-color
```

Then on GitHub:

1. Open a Pull Request
2. Get it reviewed and approved
3. Squash and merge
4. Delete the branch

---

## 🔐 Repository Rules

Branch protection is enabled on `main`:

| Rule                                 | Enforced |
| ------------------------------------ | -------- |
| Require pull request before merging  | ✅       |
| Require approval before merging      | ✅       |
| Dismiss stale reviews on new commits | ✅       |
| Block direct pushes to `main`        | ✅       |

All changes must go through a reviewed pull request — no exceptions.

---

## ✅ Summary

| Step | Action                                                                |
| ---- | --------------------------------------------------------------------- |
| 1    | `git checkout main && git pull`                                       |
| 2    | `git checkout -b feature/your-feature`                                |
| 3    | Make changes → `git add .` → `git commit -m "..."`                    |
| 4    | `git push origin feature/your-feature`                                |
| 5    | Open Pull Request on GitHub                                           |
| 6    | Wait for code review & approval                                       |
| 7    | Squash and merge                                                      |
| 8    | Delete branch on GitHub                                               |
| 9    | `git checkout main && git pull && git branch -d feature/your-feature` |

---

_Follow this workflow consistently to keep the project history clean, collaboration safe, and code quality high._

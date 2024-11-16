# How to Use GitHub

## Preparation
1. Create a GitHub account and verify your Gmail to enable collaboration.
2. Install WSL (Windows Subsystem for Linux) as the runtime environment in Windows.
3. Ensure your VSCode can connect to WSL.

## Getting Started

### Ensure Git is installed in your WSL
Check if Git is installed using the following command:
```
git --version
```

If you get an error, it means Git is not installed in your WSL. Download Git using the following commands:
```
sudo apt update
sudo apt install git
```

### Configure Your Git
Set up your Git with the email and name you used for your GitHub account. \
Don't forget to include the quotation marks:
```
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```


### Clone a Project Locally
Choose a desired location and use this command to pull the project locally:
```
git clone https://github.com/nakiridaisuki/linear_algebra_final_project.git
```

### Create Your Branch
To avoid conflicts with others' changes, create your own branch and complete your tasks within it. \
Create a new branch and switch to it with:
```
git checkout -b [branch name]
```
Remember to name your branch appropriately (no need for the brackets).

## After You Have Written Your Code

### Record Your Changes
Log the changes you made in the CHANGELOG to help identify issues if bugs arise later.\
Refer to the [CHANGELOG template](./changelogtemplate.md) for guidance.

### Commit Your Changes
After writing your code, use these commands to commit your changes to your branch and push them to GitHub. \
Remember to briefly describe your changes in the commit message and mention your branch name.
```
git add -A
git commit -m "what change did you make"
git push origin [your branch name]
```
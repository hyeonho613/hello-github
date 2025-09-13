## ✨ GitHub Workflow Summary

This document summarizes the basic GitHub workflows.

### 👤 Solo Workflow

The basic steps for working on a project by yourself.

1.  **New Repository**
    > Create a new remote repository on GitHub. It's a good practice to add a `README.md` file.

2.  **Clone**
    > Clone the remote repository to your local machine.
    ```bash
    # Replace 'hyeonho613' and 'hello-github' with your actual info.
    git clone https://github.com/hyeonho613/hello-github.git
    ```

3.  **Edit & Commit**
    > Modify files, stage the changes (add), and then record them to the local repository with a message (commit).
    ```bash
    # Stage the modified file.
    git add README.md

    # Commit the changes with a message.
    git commit -m "Add modifications"
    ```

4.  **Push**
    > Upload the changes from your local repository to the remote repository.
    ```bash
    git push
    ```

### 🤝 Collaboration Workflow

The standard steps for contributing to someone else's project.

1.  **Fork**
    > `other github -> my github`
    > Copy someone else's remote repository to your own GitHub account.

2.  **Clone**
    > `my github -> local PC`
    > Clone **the forked repository from your account** to your local machine.

3.  **Branch & Edit**
    > `create new branch`
    > Create a new branch to avoid affecting the original, then modify and commit your code within that branch.
    ```bash
    git checkout -b update-readme
    ```

4.  **Push**
    > `local PC -> my github`
    > Upload the changes from **your local branch** to **your remote repository (the fork)**.
    ```bash
    # Push the 'update-readme' branch to the remote repository (origin).
    git push origin update-readme
    ```

5.  **Pull Request (PR)**
    > `my github -> other github`
    > Send a request from your remote repository to the original repository, asking to merge your changes.

6.  **Merge**
    > `update-readme branch -> main branch`
    > The owner of the original repository reviews the code and, if there are no issues, merges the changes into the `main` branch.
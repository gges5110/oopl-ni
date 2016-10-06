# oopl-ni
This is a fork repo for Prof. Downing's cpp course.

# Setup Environment
In a linux environment, just run the setup.sh bash file at the top level.  
<br>You may want to run it with permission: `sudo ./setup.sh`

If the compiler does not work, it might be an issue with the g++ version. Change the CXX flag in the makefile and see what works for you.

# How to merge?
As a reminder of the method of merging between forks, here is a list of git commands:

| N   | Command                           | Description                                                                                                            |
| --- |:--------------------------------- | :----------------------------------------------------------------------------------------------------------------------|
| 1   | `git checkout master`             | Checkout the branch you want to merge into.                                                                            |
| 2   | `git pull REPO BRANCH_NAME`       | Pull the desired branch from the upstream repository. <br>This method will retain the commit history without modification. |
| 3   | `git commit -am "commit msg"`     | Commit the merge.                                                                                                      |
| 4   | `git push origin master`          | Push the merge to your GitHub repository.                                                                              |

Source: https://help.github.com/articles/merging-an-upstream-repository-into-your-fork/

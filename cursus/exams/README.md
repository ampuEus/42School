# 42 Exams guide
***Thanks to @pasqualerossi / Versión en [español](LEEME.md)***
## Table of content
[Exam Rank 02](rank02/README.md) - 4 Piscine Questions

## Exam details
### Norminette
There is no Norminette on exams.

### To practice exam login
  1. Login on a 42 PC with an exam account
     - *login*: exam
     - 	*password*: exam
  2. Execute `examshell` command in terminal
     - *login*: your 42 intra login username
     - *pasword*: your password
  3. Allow photo check
>In the *examshell*, you can only the following 3 commands:
>  - `status`. Check the time and other things
>  - `grademe`. Checking pushed exercise (moulinet)
>  - `finish`. Closing *examshell* and finish exam
  4. Open new terminal
     - You can find your exam subject in the directory *subject*
     - Then you can see directory *Rendu*. It is your repository for the exam.
     - Also you must create the directory named by the project and create files that it says (for example .c and/or .h) and start working.
     - When you are ready go in *Rendu* and push the directory by doing the following:
```bash
      git add .
      git commit -m "<insert a comment>"
      git push
      grademe
```

### For practice the exam itself
To practice the exam as you would in the real exam here -> https://github.com/JCluzet/42_EXAM

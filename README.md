# computer-architectures-exercises

This are some of the excercises that are proposed from tutor and professor for the fall exams session at University of Rome, TorVergata.

>The course is named "Calcolatori elettronici" (Computer Architectures)

## Read befor continue.
Care about the Assembly part. You know, there are so many computer architectures, with so many
processor, and based on them, Assembly can have some different way to
same things.\
So the **Assembly** part of this course, is completely **based on MIPS processor**, and I'm using QtSpim
to run MIPS cose on my pc.

For the **C** part, you can use the **C11** (ISO/IEC 9899:2011) version.

## Info
Now, some infos about the project structure: each part (C, Assembly), is divided in two macro categories
called **course** and **pre-course** (there is also the directory called **exercise-files** where I get the exercises).\
The first one are filled by exercises made after some concepts
got from the course, the second one, are filled by exercises made 
before the course start and there can be some typos.

## ./pre-course/
In this folder you can find some exercises that I tried to do before start the class.

- in [tested-standalone](), for the C programming part you can find some files related to the exercises in [excercises_files]() folder.
Files inside this folder, are NOT developed in CLion, so with _Microsoft Visual Studio compiler_; I created them in Vim, they need to be compiled with _gcc compiler_
    #### Command Prompt
    ```sh
    gcc <path-to-file>/<file-name>.c -o <path-to-exe>/<exe-name>
    <path-to-exe>/<exe-name>.exe
    ```
    #### Vim (Normal mode)
    ```sh
    !gcc "%" -o <path-to-exe>/<exe-name>
    <path-to-exe>/<exe-name>.exe
    ```
    For the Assembly part, there is just one file.
- in [not-tested]() folder you can find same exercises, but without testing. They are developer with Microsoft Visual Studio Compiler. Just press "run" in CLion
  

## ./course/
In this folder you can find some exercises assigned by professor to the class.


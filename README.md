# linear_algebra_final_project

## Task list:
 - [ ] write this f**king document today (11/16)

### Code
 - vector (11/24)
    - [ ] vector_init
    - [ ] dot
    - [ ] multiply 
 - plot.h (11/24)
    - [ ] plot_init
    - [ ] plot_add
    - [ ] plot_show
 - [ ] main.c : Nakiri (12/1)
 - [ ] makefile : Nakiri (12/1)

### Video
 - [ ] animation : Toby (12/1)
 - [ ] voice (12/1)

### Others
 - [ ] report : Banana (12/15)

## What should each part in our code do

### vector:
- `vector *vector_init(int x, int y)` : \
Receive two arguments x and y, return a pointer which point to a x*y matrix.

- `double dot(const vector *a, const vector *b)` : \
Calcute the dot product of two vectors and return the value. \
You may need to check if this operator is legel.

- `void multiply(const vector *a, vector b)` : \
Calcute the matrix multiplication of two vectors and store the result into `b` (follow the direction of matrix multiplication). \
You may need to check if this operator is legel.

### plot:
- `plot *plot_init(int x, int y)` : \
Initialize a canva with height x and width y full of whitespace charater. Return this canva's pointer.

- `void plot_add(int x, int y, char c)` : \
Update the pixel at `(x, y)` into character `c`.

- `void plot_show(const plot *p)` : \
Print the canve, who want to implement this function should know how to clean the cmd window, or read the output part in the old code in the reference region below.

### main:
1. Generate a donut model and store it into a vector. 
2. Rotate it by multiplying it with a rotation matrix. 
3. Determinate the luminence by calculate the dot product of ligh vector and surface normal vector of each point. 
4. Use different charater present different luminence and draw it on the canva.
5. Show the canva on the cmd window.


Feel free to change our code as long as it has the function we need.

## What should everyone do:
1. Choose at least one part you want to do in the task list.
2. Report your choice in line group, and I will add our name behind the task.
3. Creat your branch and work in it.
3. Compelet your job before the deadline (the date in brackets behind task).
4. Learn something cool during this project~

## Documents
[如何使用 GitHub](./documents/use_zh.md) / 
[How to use GitHub](./documents/us_en.md)\
[專案介紹](./documents/intro_zh.md) /
[Project introduction](./documents/intro_en.md)

## Reference
[My old code](https://github.com/nakiridaisuki/rotate_anything) \
[YT video](https://youtu.be/DEqXNfs_HhY?si=PJ-tHbdZCaWX7drx)
hwout() {
script -c "echo \"sh-4.2$ cat -n $1\" && cat -n $1 && echo \"sh-4.2$ gcc -lm $1\" && gcc -lm $1 && echo \"sh-4.2$ a.out\" && a.out && echo \"sh-4.2$ exit\" && exit" $1.txt
}

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>

int main(int argc, char** argv) {
    char *dirpath = argc > 1 ? argv[1] : ".";
    DIR *d = opendir(dirpath);
    if(!d) {
        perror("opendir");
        return 1;
    }
    struct dirent *de;
    int i = 0;

    while((de = readdir(d)) != NULL) {
        printf("%03d: %s\n", i++, de->d_name);
    }

    closedir(d);
}

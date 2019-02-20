#include<stdio.h>
#include<string.h>

char *copy(char *s1 /*source*/ , char *s2 /*destination*/){
    int i;
    
    for(i = 0; s1[i] != '\0'; ++i)
    {
        s2[i] = s1[i];
    }
    
    s2[i] = '\0';
    return s2;
}

char *c_strncpy(char *s, char *source, int n) {
    char *temp = s; //Pointer 'temp' points to contents of s which will overwrite it.
    
    while(n--) // start from value 'int n' work down to zero.
        *temp++ = *source++; //the contents of 'temp' will equal to the source.
    
    *temp = '\0'; // After the loop stops, the '\0' is copied in *saver and a pointer to the result is returned.
    
    
    
    return s; //the 'source' is untouched. (returns tangible object).
    
}

char *c_strncat(char *dest, char *source, int n)
{
    
    unsigned long l = strlen(dest); //length of the destination string.
    
    char *temp = dest + l; // index at end of destination string.
    
    while (n--) {
        *temp++ = *source++;
    }
    
    *temp = '\0';
    
    return dest;

    
    
}

int c_strncmp(const char* s, const char* t, int n)

{
    while (--n && *s == *t) {
        s++;
        t++;
    }
    
    if (n)
        return *s - *t;   // first entry - second entry
    
    
    return 0;
}

// This doesn't accept new line feed '\n'
char *fgets_c(char *input, int buflen, FILE *fp)
{
    if (fgets(input, buflen, fp) != 0)
    {
//len finds the length of the input which the (n-1) entry is '\n'. The goal is to replace it to '\0'
        int len = strlen(input);
        if (len > 0 && input[len-1] == '\n')
            input[len-1] = '\0';
        return input;
    }
    return 0;
}

int main(){
    
    char arg1[500];// (s)
    char arg2[500];// (t)
    char x[500];
    char x1[500];
    char y[500];
    int n;
    
    printf("Enter a string 1 : ");
        fgets_c(arg1,500,stdin); //*** modified input of fgets where it doesn't input '\n' value.
    
    printf("Enter a string 2 : ");
        fgets_c(arg2,500,stdin);
    printf("Enter number : ");
    scanf("%d",&n); // Read integer number.
    
    copy(arg1,x); // x = copy of arg 1.
    copy(arg1,x1); // x1 = copy of arg 1.
    copy(arg2,y); // y = copy of arg 2.
    
    c_strncpy(arg1,arg2,n); //arg 2 is unaffected. arg1 is now changed.
    c_strncat(x,arg2,n); // use x (x = arg1_copy) because arg 1 is now changed from strncpy.
    
    int value = c_strncmp(x1,y,n);
    
    printf("\nstrncpy is \"%s\"\n", arg1);
    printf("strncat is \"%s\"\n", x);
    
    //    printf("%d\n", value);
    
    if (value == 0){
        printf("strncmp is \"%s\" = \"%s\" \n",x1,y); // str1 = str2
    }
    else if (value > 0){
        printf("strncmp is \"%s\" > \"%s\" \n",x1,y); //str1 (>)after str2
    }
    else
        printf("strncmp is \"%s\" <  \"%s\" \n",x1,y); //str1 (<)before str2
    
    return 0;
    
}



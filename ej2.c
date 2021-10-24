/*#include <stdio.h>
#include <stdlib.h>

int len(char* s){
    int c = 0;
    while (s[c] != 0){
        c++;
    }
    return c;
}

int dupStr(char* src, char** dst){
    int l = len(src);
    char *new = (char*)malloc(l * sizeof(char));
    for (int i = 0; i < l; i++){
        new[i] = src[i];
    }
    *dst = new;
    printf("%s\n", new);
    return l;
}

int cmpStr(char* s1, char* s2){
  
    int l1 = len(s1);
    int l2 = len(s2);
    
    int small = l1;
    if (l2 < l1)
        small = l2;
 
    for(int i = 0; i < l1; i++){
        if(s1[i] > s2[i])
            return -1;
        else if(s1[i] < s2[i])
            return 1;
    }

    if (l1 > l2)
        return -1;
    else if (l1 < l2)
        return 1;
    
    return 0;
}

void split(char* source, int count, char** s1, char** s2){

  int ls = len(source);
    char *p1 = (char*)malloc(count * sizeof(char));
    char *p2 = (char*)malloc((len(source)-count)*sizeof(char));

    for (int i = 0; i < ls; i++){
        
        if (i < count){
            p1[i] = source[i];
        }
        else{
            p2[i-count] = source[i];
        }
    }

    if (count > ls)
        p2 = "";
    
    *s1 = p1;
    *s2 = p2;
}
int main(){
    char* dup;
    char og[5] = "hola";
    og[4] = '\0';
    int size = dupStr(og, &dup);
    printf("dupStr(\"hola\", &dup) -> size = %i, dup = \"%s\"\n", size, dup);
    og[1] = 'a';
    printf("%s\n", og);
    printf("%s\n", dup);
    free(dup);

		printf("\n");

    printf("%i\n", cmpStr("zorro","abecedario"));
    printf("%i\n", cmpStr("casa","cal"));
    printf("%i\n", cmpStr("topo","top"));
    printf("%i\n", cmpStr("pato","pato"));
		
		printf("\n");


    char* first;
    char* last;
    split("mostacho",3, &first, &last);
    printf("s1 = %s\n", first);
    printf("s2 = %s\n", last);

		printf("\n");

    split("elefante",0, &first, &last);
    printf("s1 = %s\n", first);
    printf("s2 = %s\n", last);

		printf("\n");
    
    split("tucan",10, &first, &last);
    printf("s1 = %s\n", first);
    printf("s2 = %s\n", last);

    return 0;
}*/
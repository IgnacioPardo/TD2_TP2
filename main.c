#include <stdio.h>
#include <stdlib.h>

struct node {
    char* data;
    struct node* next;
};

struct container {
    struct node* data[4];
    int count;
};
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
    return l;
}

int equalStr(char* s1, char* s2){
	int l1 = len(s1);
  int l2 = len(s2);
	if (l1 != l2)
		return 0;
	for(int i = 0; i < l1; i++){
		if(s1[i] != s2[i])
			return 0;
	}
	return 1;
}

int cmpStr(char* s1, char* s2){
	int l1 = len(s1);
	int l2 = len(s2);
	for (int i = 0; i < l1; i++){
		int j = i;
		if (i == l1 && j < l2)
			return 1;
		else if (j == l2 && i < l1)
			return -1;
		else{
			if (s1[i] > s2[j])
				return -1;
			else if (s1[i] < s2[j])
				return 1;
		}
	}
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

int getIndex(char * s){
	return (int)s[0] & 0x03;
}

int contains(struct container* c, char* value) {

    // COMPLETAR
		int count = 0;
		for(int i=0; i<4; i++) {
        struct node* n = c->data[i];
        while(n != 0) {
            if (equalStr(n->data, value))
							count++;
            n = n->next;
        }
    }

    return count;
}

void sortedAdd(struct container* c, char* value) {

	if (!contains(c, value))
		c->count++;
	
	int i = getIndex(value);

	struct node* newNode = (struct node*)malloc(sizeof(struct node*));
	dupStr(value, &newNode->data);
	newNode->next = 0;

	if (!c->data[i]){
		c->data[i] = newNode;
		return;
	}
	struct node* n = c->data[i];
	
	if (!n->next){
		if (cmpStr(value, n->data) + 1){
			c->data[i] = newNode;
			newNode->next = n;
			return;
		}
		n->next = newNode;
		return;
	}

	while(n->next){
		if (cmpStr(value, n->next->data) + 1){
			newNode->next = n->next;
			n->next = newNode;
			return;
		}
		n = n->next;
	}

	n->next = newNode;
}

int inverseDelete(struct container* c, char* value) {

    // COMPLETAR
		int count = 0;
		int i = getIndex(value);

    struct node* n = c->data[i];

		while(n->next != 0) {
			if (!equalStr(n->next->data, value)){
				struct node* tmp = n->next;
				n->next = n->next->next;
				free(tmp);
				count++;
			}
			else{
				n = n->next;
			}
		}

		if (!equalStr(c->data[i]->data, value)){
			struct node* tmp = c->data[i];
			c->data[i] = c->data[i]->next;
			free(tmp);
			count++;
		}
		
		c->count -= count;
    return count;
}

struct container* newContainer() {
    struct container* c = (struct container*)malloc(sizeof(struct container));
    c->data[0] = 0;
    c->data[1] = 0;
    c->data[2] = 0;
    c->data[3] = 0;
    c->count = 0;
    return c;
}

void deleteContainer(struct container* c) {
    for(int i=0; i<4; i++) {
        struct node* n = c->data[i];
        while(n != 0) {
            struct node* t = n;
            n = n->next;
            free(t->data);
            free(t);
        }
    }
    free(c);
}

void printContainer(struct container* c) {
		printf("Cointeiner count: %i\n", c->count);
    for(int i=0; i<4; i++) {
        fprintf(stdout,"%i -> ",i);
        struct node* n = c->data[i];
        while(n != 0) {
            fprintf(stdout,"[%s]->",n->data);
            n = n->next;
        }
        fprintf(stdout," %i\n", 0);
    }
}

int main(){
	struct container* cont = newContainer();
	/*
	sortedAdd(cont, "aristocracia");

	sortedAdd(cont, "abecedario");

	sortedAdd(cont, "zimbabwe");
	sortedAdd(cont, "alfarero");

	sortedAdd(cont, "adenosintrifosfato");

	sortedAdd(cont, "aguila");

	sortedAdd(cont, "zorro");

	//sortedAdd(cont, "scaloneta");

	//sortedAdd(cont, "esteroides");*/
	
	sortedAdd(cont, "dado");
	sortedAdd(cont, "lado");
	sortedAdd(cont, "pato");
	sortedAdd(cont, "ala");
	sortedAdd(cont, "arco");
	sortedAdd(cont, "mate");
	sortedAdd(cont, "mesa");
	sortedAdd(cont, "queso");
	sortedAdd(cont, "barco");
	sortedAdd(cont, "flor");
	sortedAdd(cont, "nariz");
	sortedAdd(cont, "rojo");
	sortedAdd(cont, "casa");
	sortedAdd(cont, "casa");
	printContainer(cont);
	
	printf("\n");
	
	printf("pero -> %i\n", contains(cont, "pero")); 
	printf("arco -> %i\n", contains(cont, "arco")); 
	printf("casa -> %i\n", contains(cont, "casa"));
	
	printf("\n");
	
	printf("mate %i\n\n", inverseDelete(cont,"mate"));
	
	printContainer(cont);
	/*
	char *toCMP[5];
	toCMP[0] = "ala";
	toCMP[1] = "arco";
	toCMP[2] = "mate";
	toCMP[3] = "mesa";
	toCMP[4] = "queso";
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			printf("%s %s %i\n",toCMP[i], toCMP[j], cmpStr(toCMP[i], toCMP[j]));
		}
	}*/
	return 0;
}
#include "container.h"

int len(char* s){
	//Longitud del string s
	int c = 0;
	while (s[c] != 0){
			c++;
	}
	return c;
}

int dupStr(char* src, char** dst){
	//Copia el contenido del string src al puntero dst
	int l = len(src);
	char *new = (char*)malloc(l * sizeof(char));
	for (int i = 0; i < l; i++){
			new[i] = src[i];
	}
	*dst = new;
	return l;
}

char normalizeChar(char c){
	//Convierte el char c de minuscula a mayuscula
	if (c > 96)
		return c - 32;
	return c;
}

int equalStr(char* s1, char* s2){
	//Evalua igualdad entre los strings s1 y s2 caracter por caracter
	int l1 = len(s1);
  int l2 = len(s2);
	if (l1 != l2)
		return 0;
	for(int i = 0; i < l1; i++){
		if(normalizeChar(s1[i]) != normalizeChar(s2[i]))
			return 0;
	}
	return 1;
}

int cmpStr(char* s1, char* s2){
	//Devuelve si s1 y s2 estan en orden lexicografico
	int l1 = len(s1);
	int l2 = len(s2);
	for (int i = 0; i < l1; i++){
		int j = i;
		if (i == l1 && j < l2)
			return 1;
		else if (j == l2 && i < l1)
			return -1;
		else{
			char a = normalizeChar(s1[i]);
			char b = normalizeChar(s2[j]);
			
			if (a > b)
				return -1;
			else if (a < b)
				return 1;
		}
	}
	if (equalStr(s1, s2))
		return 0;
		
	return 1;
}

void split(char* source, int count, char** s1, char** s2){
	//Divide un string source en la posicion count y ubica las divisiones en s1 y s2
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
//Borra todos los datos del slot al que pertenece el string value, menos todas las copias que existan del string value. Debe retonar la cantidad de datos que fueron borrados.
		
		//Retorna 0 y no modifica c si no contiene value. 
		if (!contains(c, value))
			return 0;

		int count = 0;
		int i = getIndex(value);

    struct node* n = c->data[i];

		while(n->next != 0) {
			if (!equalStr(n->next->data, value)){
				struct node* tmp = n->next;
				n->next = n->next->next;
				free(tmp->data);
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
			free(tmp->data);
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
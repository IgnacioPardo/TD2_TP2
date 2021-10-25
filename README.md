# TD2_TP1

### 💾 [Trabajo Practico 2](https://github.com/IgnacioPardo/TD2_TP2/blob/main/Enunciado_TP2.pdf) - [Tecnologia Digital II UTDT](https://www.utdt.edu/ver_contenido.php?id_contenido=19866&id_item_menu=31534)

### 🧠 **Integrantes**: Luca Mazzarello - Camila Migdal - Ignacio Pardo

### 👨🏻‍🏫 **Profesor**: David Alejandro Gonzalez Marquez

### 🗃 **Estructura del repositorio**:
  

```C	
📄container.c	
//Definicion de las funciones de contenedores
	
	int len(char* s;
	//Longitud del string s

	int dupStr(char* src, char** dst;
	//Duplica un string. Debe contar la cantidad de caracteres totales de src y solicitar la memoria equivalente. Luego, debe copiar todos los caracteres a esta nueva area de memoria. El puntero al nuevo string se almacenara en el doble puntero dst. Ademas, como valor de retorno se debe retornar el tamaño del string.

	char normalizeChar(char c;
	//Retorna el char c en mayuscula

	int equalStr(char* s1, char* s2;
	//Evalua la igualdad entre los strings s1 y s2 caracter por caracter

	int cmpStr(char* s1, char* s2;
	//Compara dos strings en orden lexicograafico. Retorna (0 si son iguales, 1 si s1<s2, −1 si s2<s1)

	void split(char* source, int count, char** s1, char** s2;
	//A partir del string en source, genera dos nuevos strings s1 y s2. s1 debe contener los primeros count caracteres del string source, mientas que s2 debe contener los caracteres restantes. La memoria del string source pasado por parametro debe ser liberada. En caso que count supere la cantidad de caracteres totales de source, se debe retornar en s2 un string vacio. El parametro count es siempre un numero positivo.

	int getIndex(char * s;
	//Retorna el indice del contenedor a donde corresponde el string s

	int contains(struct container* c, char* value);
	//Determina la cantidad de veces que value est ́a definido dentro de container. Debe retonar la cantidad de apariciones del dato.

	void sortedAdd(struct container* c, char* value);
	//Agregar el string value pasado por par ́ametro dentro del container, respetando los invariantes de la estructura indicados anteriormente.

	int inverseDelete(struct container* c, char* value);
	//Borra todos los datos del slot al que pertenece el string value, menos todas las copias que existan del string value. Debe retonar la cantidad de datos que fueron borrados.	

	struct container* newContainer();
	//Solicita memoria e inicializa una estructura container vacia.

	void deleteContainer(struct container* c);
	//Borra toda la memoria solicitada dentro de un container.

	void printContainer(struct container* c);
	//Imprime en pantalla el container pasado por parametro.


📄main.c
//tests

	int test_dup1()
	//String vacio.
	int test_dup2()
	//string de un caracter
	int test_dup3()
	//String que incluya todos los caracteres validos distintos de cero
	int test_cmpStr1()
	//Dos string vacios
	int test_cmpStr2a()
	//Dos strings de 1 caracter iguales
	int test_cmpStr2b()
	//Dos strings de 1 caracter 'a' < 'b'
	int test_cmpStr2c()
	//Dos strings de 1 caracter 'b' > 'a'
	int test_cmpStr3a()
	//Strings iguales hasta un caracter
	int test_cmpStr3b()
	//Strings iguales hasta un caracter
	int test_cmpStr4a()
	//Dos strings diferentes s1 < s2
	int test_cmpStr4b()
	//Dos strings diferentes s1 > s2
	int test_cmpStr4c()
	//Dos strings diferentes s1 < s2 (s2 caps)
	int test_split1a()
	//Un string vacio, count = 1
	int test_split1b()
	//Un string vacio, count = 2
	int test_split1c()
	//Un string vacio, count = 3
	int test_split2a()
	//Un string de un caracter, count = 1
	int test_split2b()
	//Un string de un caracter, count = 2
	int test_split2c()
	//Un string de un caracter, count = 3
	int test_split3a()
	// Un string de multiples caracteres, count = 1
	int test_split3b()
	// Un string de multiples caracteres, count = 2
	int test_split3c()
	// Un string de multiples caracteres, count = 3
	int test_sortedAdd1()
	//Agregar un dato por lista
	int test_sortedAdd2()
	//Sobre el primer caso, agregar un dato mayor a todos por lista
	int test_sortedAdd3()
	//Sobre el primer caso, agregar un dato menor a todos por lista
	int test_sortedAdd4()
	//Sobre el primer caso, agregar un dato que ordenado termine entre dos elementos
	int test_contains1()
	//Dada una estructura, consultar si existe un dato que se ubique como ultimo dato de alguna de las listas
	int test_contains2()
	//Dada una estructura, consultar si existe un dato que se ubique como primer dato de algunade las listas
	int test_contains3()
	//Dada una estructura, consultar si existe un dato que se ubique en el medio de una lista
	int test_contains4()
	//Dada una estructura, consultar si existe un dato que no este en la lista
	int test_inverseDelete1()
	//Para un dato que se ubique al comienzo de una lista
	int test_inverseDelete2()
	//Para un dato que se ubique al final de una lista
	int test_inverseDelete3()
	//Para un dato que se ubique entre dos nodos de una lista

```		

        
📅 **Fecha**: Octubre 2021

<br/><br/><br/><br/>

<img width="100" alt="micro_DiTella" src="https://user-images.githubusercontent.com/65306107/132214134-ac5df2b8-353e-46b2-9c6e-ab9f0429a767.png"> 

### 🎓 Tecnologia Digital II UTDT
### 📦 [GitHub](https://github.com/IgnacioPardo/TD2_TP2)

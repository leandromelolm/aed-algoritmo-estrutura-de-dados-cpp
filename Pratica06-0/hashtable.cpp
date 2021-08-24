#include <iostream>
#include <string>

using namespace std;

/* Tabela de Espalhamento como array de listas encadeadas.
 * As listas lidam com colisões (hashs que dão o mesmo índice).
 * T_key: tipo da chave
 * T_value: tipo do valor
 *
 */
template <class T_key, class T_value>
class Hashtable {
private:
	struct Node {
		T_key key;
		T_value value;
		Node * next;
		Node(T_key key, T_value value) : key(key), value(value), next(NULL) {}
	};

	Node ** data;			// Array de pontos para as cabeças das listas
	int cap, size;
	T_value notFound;		// Item default retornado caso a chave não seja encontrada

public:
	Hashtable(int cap, T_value notFound) {
		this->cap = cap;
		this->size = 0;
		this->notFound = notFound;
		data = new Node*[cap];
		for (int i = 0; i < cap; i++) {
			data[i] = NULL;
		}
	}

	~Hashtable() {
		for (int i = 0; i < cap; i++) {
			while (data[i] != NULL)
		 		__remove(data[i], data[i]->key);
		}
		delete [] data;
	}

	/* Insere item (chave, valor) na tabela */
	void insert(T_key key, T_value value) {
		// Calcular o hash da chave e o índice na tabela
		// Pegar o ponteiro de início da lista correspondente na tabela
		// Inserir na lista (usando o ponteiro)
	}

	/* Remove item da tabela usando a chave */
	T_value remove(T_key key) {
		// Calcular o hash da chave e o índice na tabela
		// Pegar o ponteiro de início da lista correspondente na tabela
		// Remover da lista (usando o ponteiro)
	}

	/* Busca e retorna o valor na tabela usando a chave */
	T_value search(T_key key) {
		// Calcular o hash da chave e o índice na tabela
		// Pegar o ponteiro de início da lista correspondente na tabela
		// Buscar na lista (usando o ponteiro)
	}

	/* Exibe todos os itens na tabela */
	void show() {
		for (int i = 0; i < cap; i++) {
			cout << i << ":";
			__show(data[i]);
			cout << endl;
		}
	}

private:
	// FUNCOES DE ESPALHAMENTO
	// Serão necessária funções diferentes para tipos de chaves diferentes.

	int hash(int x) {
		// Calcula o hash para chaves do tipo inteiro
	}

	int hash(string key) {
		// Calcula o hash para chaves do tipo string
	}

	// FUNÇOES DE MANIPULAÇÃO DA LISTA DE ITENS

	/* Exibe os items de uma posição da tabela (lista) */
	void __show(Node * node) {
		while (node != NULL) {
			cout << "(" << node->key << ", " << node->value << ") ";
			node = node->next;
		}
	}

	/* Insere o item no início da lista indicada por node */
	void __insert(Node * &node, T_key key, T_value value) {
		Node * tmp = new Node(key, value);
		tmp->next = node;
		node = tmp;
	}

	/* Remove o item no início da lista indicada por node */
	T_value __remove(Node * &node, T_key key) {
		if (node == NULL) return notFound;
		if (node->key == key) {
			Node * old = node;
			T_value tmp = node->value;
			node = node->next;
			delete old;
			return tmp;
		} else {
			return __remove(node->next, key);
		}
	}

	/* Busca e retorna o item indicado pela chave */
	T_value __search(Node * node, T_key key) {
		while (node != NULL) {
			if (node->key == key) {
				return node->value;
			}
			node = node->next;
		}
		return notFound;
	}

};


int main() {
	/* Tabela de alunos por matricula: mat = aluno */
	Hashtable<int, string> alunos(10, "NAO ENCONTRADO");

	alunos.insert(12312, "Marcos");
	alunos.insert(23523, "Flavia");
	alunos.insert(9878,  "Victor");
	alunos.insert(72365, "Pedro");
	alunos.insert(51535, "Esmeralda");

	cout << "TABELA de Alunos: " << endl;
	alunos.show();
	cout << endl;

	cout << "ALUNOS: "  << endl;
	cout << "12312: "  << alunos.search(12312) << endl;
	cout << "23523: "  << alunos.search(23523) << endl;
	cout << "98784: "  << alunos.search(98784) << endl;
	cout << "22353: "  << alunos.search(22353) << endl;
	cout << "72365: "  << alunos.search(72365) << endl;

	cout << endl;

	// ----------------------

	/* Tabela de notas por aluno: nome = nota */
	Hashtable<string, float> notas(10, -1);

	notas.insert(string("Joao"), 5);
	notas.insert(string("Pedro"), 7);
	notas.insert(string("Larissa"), 10);
	notas.insert(string("Tereza"), 7.5);
	notas.insert(string("Victor"), 8);
	notas.insert(string("Mario"), 4);

	cout << "TABELA de Notas: " << endl;
	notas.show();
	cout << endl;

	cout << "NOTAS: "  << endl;
	cout << "Joao: "   << notas.search(string("Joao")) << endl;
	cout << "Carlos: " << notas.search(string("Carlos")) << endl;
	cout << "Pedro: "  << notas.search(string("Pedro")) << endl;
	cout << "Maria: "  << notas.search(string("Maria")) << endl;
	cout << "Mario: "  << notas.search(string("Mario")) << endl;
}




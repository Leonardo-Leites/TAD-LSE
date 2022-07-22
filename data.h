typedef struct TipoNo ptLSE;

struct TipoNo{
       int numero;
       ptLSE *prox;
};

ptLSE* cria_lista(void);
ptLSE* insere(ptLSE *ptLista, int num);
ptLSE* preenche(ptLSE *ptLista, int num);
void imprime(ptLSE* lista);
ptLSE* destroi(ptLSE* lista);

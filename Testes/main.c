#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <assert.h>

#define MAX_ASSENTOS 200   // Define o numero maximo de assentos
#define MAX_VOOS 50        // Define o numero maximo de voos
#define CADASTROS_TRIPULANTES 100
#define NOMES 50
#define CARGOS 20
#define NUM_PASSAGEIROS 100
typedef struct {
    char codigoVoo[20];      // Código do voo
    int numeroAssento;       // Número do assento
    int codigoPassageiro;    // Código do passageiro
} Reserva;
// Estrutura para armazenar informacoes de um assento
Reserva reservas[NUM_PASSAGEIROS]; // Vetor para armazenar as reservas
int totalReservas = 0;

typedef struct {
    int numero;          // Número do assento
    char codigoVoo[20];  // Código do voo ao qual o assento pertence
    int ocupado;         // Status do assento: 0 = Livre, 1 = Ocupado
    int codigoPassageiro; // Código do passageiro associado (0 se livre)
} Assento;

// Estrutura para armazenar informacoes de um voo
typedef struct {
    char codigo[20];      // Codigo do voo (suporta letras e numeros)
    char origem[50];      // Origem do voo
    char destino[50];     // Destino do voo
    char data[20];        // Data do voo (Formato: DD/MM/AAAA)
    char hora[10];        // Hora do voo (Formato: HH:MM)
    char codigoAviacao[20];  // Codigo do aviao
    char codigoPiloto[20];   // Codigo do piloto
    char codigoCopiloto[20]; // Codigo do copiloto
    char codigoComissario[20]; // Codigo do comissario
    float tarifa;          // Tarifa do voo
    int ativo;            // Status do voo: 1 = Ativo, 0 = Inativo
} Voo;

// Arrays globais para armazenar os voos e assentos
Voo voos[MAX_VOOS];
int totalVoos = 0;        // Contador de voos cadastrados
Assento assentos[MAX_ASSENTOS];
int totalAssentos = 0;    // Contador de assentos cadastrados

// Funcao para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao para capturar uma string valida, removendo espacos extras
void capturarTexto(const char *mensagem, char *saida, int tamanho) {
    char entrada[100];   // Buffer temporario para a entrada do usuario
    while (1) {
        printf("%s", mensagem);
        fgets(entrada, sizeof(entrada), stdin);   // Captura a entrada do usuario
        entrada[strcspn(entrada, "\n")] = '\0';   // Remove o '\n' da string

        // Remove espacos antes e depois da string
        int inicio = 0;
        int fim = strlen(entrada) - 1;
        while (inicio <= fim && isspace(entrada[inicio])) inicio++;  // Ignora espacos no inicio
        while (fim >= inicio && isspace(entrada[fim])) fim--;        // Ignora espacos no final

        // Verifica se a entrada nao esta vazia (apenas espacos)
        if (inicio > fim) {
            printf("Erro: Entrada invalida (apenas espacos). Tente novamente.\n");
            continue;
        }

        // Copia a string valida para a variavel de saida
        strncpy(saida, &entrada[inicio], fim - inicio + 1);
        saida[fim - inicio + 1] = '\0';  // Garante que a string esta terminada corretamente
        return; // Sai da funcao
    }
}

// Funcao para validar a data no formato DD/MM/AAAA
int validarData(const char *data) {
    if (strlen(data) != 10) return 0; // O formato deve ser exatamente 10 caracteres
    if (data[2] != '/' || data[5] != '/') return 0; // Verifica as barras no formato

    int dia, mes, ano;
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) return 0;

    // Valida o intervalo de dia, mes e ano
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900) return 0;

    // Valida os dias do mes (simplificado, nao leva em conta anos bissextos)
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return 0;
    if (mes == 2 && dia > 28) return 0; // Considera fevereiro com 28 dias

    return 1;
}

// Funcao para validar a hora no formato HH:MM
int validarHora(const char *hora) {
    if (strlen(hora) != 5) return 0; // O formato deve ser exatamente 5 caracteres
    if (hora[2] != ':') return 0; // Verifica o separador de hora e minuto

    int h, m;
    if (sscanf(hora, "%d:%d", &h, &m) != 2) return 0;

    // Valida o intervalo de hora e minuto
    if (h < 0 || h > 23 || m < 0 || m > 59) return 0;

    return 1;
}

// Funcao para buscar um voo pelo codigo
int buscarVoo(const char *codigoVoo) {
    // Percorre todos os voos cadastrados e busca pelo codigo
    for (int i = 0; i < totalVoos; i++) {
        if (strcmp(voos[i].codigo, codigoVoo) == 0) {
            return i; // Retorna o indice do voo se encontrado
        }
    }
    return -1; // Retorna -1 se nao encontrar o voo
}

// Funcao para cadastrar um novo voo
void cadastrarVoo() {
    if (totalVoos >= MAX_VOOS) {
        printf("Erro: Limite maximo de voos atingido.\n");
        return; // Impede o cadastro de mais voos se o limite foi alcançado
    }

    // Solicita o codigo do voo ao usuario e verifica se ja existe
    char codigo[20];
    capturarTexto("Digite o codigo do voo: ", codigo, sizeof(codigo));
    if (buscarVoo(codigo) != -1) {
        printf("Erro: Ja existe um voo com este codigo.\n");
        return; // Se o codigo ja existe, o voo nao e cadastrado
    }

    // Solicita a origem e destino do voo
    char origem[50], destino[50];
    capturarTexto("Digite a origem do voo: ", origem, sizeof(origem));
    capturarTexto("Digite o destino do voo: ", destino, sizeof(destino));

    // Solicita a data do voo (verifica se esta no formato correto)
    char data[20];
    while (1) {
        capturarTexto("Digite a data do voo (DD/MM/AAAA): ", data, sizeof(data));
        if (validarData(data)) {
            break;
        } else {
            printf("Erro: Data invalida. Utilize o formato DD/MM/AAAA.\n");
        }
    }

    // Solicita a hora do voo (verifica se esta no formato correto)
    char hora[10];
    while (1) {
        capturarTexto("Digite a hora do voo (HH:MM): ", hora, sizeof(hora));
        if (validarHora(hora)) {
            break;
        } else {
            printf("Erro: Hora invalida. Utilize o formato HH:MM.\n");
        }
    }

    // Solicita o codigo do aviao, piloto, copiloto e comissario
    char codigoAviacao[20], codigoPiloto[20], codigoCopiloto[20], codigoComissario[20];
    capturarTexto("Digite o codigo do aviao: ", codigoAviacao, sizeof(codigoAviacao));
    capturarTexto("Digite o codigo do piloto: ", codigoPiloto, sizeof(codigoPiloto));
    capturarTexto("Digite o codigo do copiloto: ", codigoCopiloto, sizeof(codigoCopiloto));
    capturarTexto("Digite o codigo do comissario: ", codigoComissario, sizeof(codigoComissario));

    // Solicita a tarifa do voo
    float tarifa;
    do {
        printf("Digite a tarifa do voo: ");
        scanf("%f", &tarifa);
        limparBuffer();
        if (tarifa < 0) {
            printf("Erro: Tarifa invalida. Deve ser maior que 0.\n");
        }
    } while (tarifa < 0);

    // Cadastra o novo voo
    strcpy(voos[totalVoos].codigo, codigo);
    strcpy(voos[totalVoos].origem, origem);
    strcpy(voos[totalVoos].destino, destino);
    strcpy(voos[totalVoos].data, data);
    strcpy(voos[totalVoos].hora, hora);
    strcpy(voos[totalVoos].codigoAviacao, codigoAviacao);
    strcpy(voos[totalVoos].codigoPiloto, codigoPiloto);
    strcpy(voos[totalVoos].codigoCopiloto, codigoCopiloto);
    strcpy(voos[totalVoos].codigoComissario, codigoComissario);
    voos[totalVoos].tarifa = tarifa;
    voos[totalVoos].ativo = 1; // Marca o voo como ativo
    totalVoos++; // Atualiza o contador de voos cadastrados

    printf("Voo cadastrado com sucesso!\n");
}

// Funcao para listar todos os voos cadastrados
void listarVoos() {
    if (totalVoos == 0) {
        printf("Nenhum voo cadastrado.\n");
        return; // Se nao houver voos cadastrados, retorna sem fazer nada
    }

    printf("Lista de voos cadastrados:\n");
    for (int i = 0; i < totalVoos; i++) {
        printf("Codigo do Voo: %s, Origem: %s, Destino: %s, Data: %s, Hora: %s, Tarifa: $%.2f\n",
               voos[i].codigo, voos[i].origem, voos[i].destino,
               voos[i].data, voos[i].hora, voos[i].tarifa);
    }
}

// Funcao para cadastrar um novo assento
void cadastrarAssento() {
    if (totalAssentos >= MAX_ASSENTOS) {
        printf("Erro: Limite maximo de assentos atingido.\n");
        return; // Impede o cadastro de mais assentos se o limite foi atingido
    }

    // Solicita o codigo do voo ao usuario
    char codigoVoo[20];
    capturarTexto("Digite o codigo do voo para cadastrar o assento: ", codigoVoo, sizeof(codigoVoo));

    // Verifica se o voo existe
    int indiceVoo = buscarVoo(codigoVoo);
    if (indiceVoo == -1) {
        printf("Erro: Voo nao encontrado.\n");
        return; // Se o voo nao existir, nao cadastra o assento
    }

    // Solicita o numero do assento
    int numeroAssento;
    do {
        printf("Digite o numero do assento (1 a 200): ");
        scanf("%d", &numeroAssento);
        limparBuffer();
        if (numeroAssento < 1 || numeroAssento > 200) {
            printf("Erro: Numero de assento invalido.\n");
        }
    } while (numeroAssento < 1 || numeroAssento > 200);

    // Verifica se o assento ja esta ocupado
    for (int i = 0; i < totalAssentos; i++) {
        if (assentos[i].numero == numeroAssento && strcmp(assentos[i].codigoVoo, codigoVoo) == 0) {
            printf("Erro: Assento ja cadastrado neste voo.\n");
            return; // Se o assento ja estiver cadastrado, nao permite o cadastro
        }
    }

    // Cadastra o novo assento
    assentos[totalAssentos].numero = numeroAssento;
    strcpy(assentos[totalAssentos].codigoVoo, codigoVoo);
    assentos[totalAssentos].ocupado = 0; // Marca o assento como livre inicialmente
    totalAssentos++; // Atualiza o contador de assentos cadastrados

    printf("Assento cadastrado com sucesso!\n");
}

// Funcao para listar todos os assentos cadastrados
void listarAssentos() {
    if (totalAssentos == 0) {
        printf("Nenhum assento cadastrado.\n");
        return; // Se nao houver assentos cadastrados, retorna sem fazer nada
    }

    printf("Lista de assentos cadastrados:\n");
    for (int i = 0; i < totalAssentos; i++) {
        printf("Assento: %d, Codigo do Voo: %s, Status: %s\n",
               assentos[i].numero, assentos[i].codigoVoo,
               assentos[i].ocupado ? "Ocupado" : "Livre");
    }
}

// Estrutura para cadastrar os tripulantes
typedef struct
{
    int codigo;          // Código único do tripulante
    char nome[NOMES];    // Nome do tripulante
    char cargo[CARGOS];  // Cargo do tripulante (ex: piloto, copiloto, comissário)
    char telefone[15];   // Telefone de contato do tripulante
} Tripulante;

// Estrutura que representa um passageiro com seus dados
typedef struct {
    int codigo;              // Código único do passageiro
    char nome[100];          // Nome do passageiro
    char rua[100];           // Endereço do passageiro
    char cidade[50];         // Cidade onde o passageiro reside
    char bairro[50];         // Bairro onde o passageiro reside
    char pais[50];           // País onde o passageiro reside
    int numeroCasa;          // Número da casa do passageiro
    char telefone[15];       // Telefone do passageiro
    char fidelidade;         // Indica se o passageiro é fiel (S/N)
    int pontosFidelidade;    // Pontos de fidelidade do passageiro, caso tenha
} Passageiro;

// Arrays para armazenar os dados dos tripulantes e passageiros
Tripulante tripulantes[CADASTROS_TRIPULANTES]; // Limite de cadastros de tripulantes
Passageiro passageiros[NUM_PASSAGEIROS];       // Limite de cadastros de passageiros
int todos_tripulante = 0;                      // Contador de tripulantes cadastrados
int todos_passageiros = 0;                     // Contador de passageiros cadastrados
int Codigo = 1;                                // Código único para cada novo passageiro

// Função para validar se o cargo é válido e informar os cargos disponíveis
int VerificarOcargos(char cargo[])
{
    // Verifica se o cargo é um dos válidos
    if (strcmp(cargo, "piloto") == 0 || strcmp(cargo, "copiloto") == 0 || strcmp(cargo, "comissario") == 0) {
        return 1;  // Cargo válido
    }

    // Se o cargo não for válido, imprime os cargos válidos
    printf("\nCargos validos sao: \n");
    printf("- piloto\n");
    printf("- copiloto\n");
    printf("- comissario\n");

    return 0;  // Cargo inválido
}

// Função para validar o nome (apenas letras e espaços são permitidos)
int validar_nome(char nome[])
{
    if (strlen(nome) > 49)  // Verifica se o nome é maior que 49 caracteres
    {
        return 0;  // Nome inválido
    }
    for (int i = 0; i < strlen(nome); i++)
    {
        if (!isalpha(nome[i]) && nome[i] != ' ')  // Verifica se o nome contém caracteres não alfabéticos
        {
            return 0;  // Nome inválido
        }
    }
    return 1;  // Nome válido
}

// Função para validar se o telefone contém apenas números e está no formato correto
int validar_telefone(char telefone[])
{
    if (strlen(telefone) < 8 || strlen(telefone) > 14)  // Verifica o comprimento do telefone
    {
        return 0;  // Telefone inválido
    }

    for (int i = 0; i < strlen(telefone); i++)  // Verifica se todos os caracteres são números
    {
        if (!isdigit(telefone[i]))
        {
            return 0;  // Telefone inválido
        }
    }
    return 1;  // Telefone válido
}

// Função para cadastrar um novo tripulante
int cadastrar_tripulante(char nome[], char cargo[], char telefone[])
{
    if (todos_tripulante >= CADASTROS_TRIPULANTES)  // Verifica se atingiu o limite de cadastros
    {
        printf("Limite maximo de tripulantes cadastrados.\n");
        return 0;
    }

    // Verificação do cargo
    if (!VerificarOcargos(cargo))
    {
        printf("\nO cargo que voce inseriu nao e valido.\n");
        return 0;
    }

    // Validação do nome
    if (!validar_nome(nome))
    {
        printf("\nNome INVALIDO!! O nome deve conter apenas letras e espaços e ter no máximo 49 caracteres.\n");
        return 0;
    }

    // Validação do telefone
    if (!validar_telefone(telefone))
    {
        printf("\nTelefone invalido. O telefone deve conter entre 8 e 14 digitos.\n");
        return 0;
    }

    // Cadastra o tripulante
    tripulantes[todos_tripulante].codigo = todos_tripulante + 1;
    strncpy(tripulantes[todos_tripulante].nome, nome, NOMES - 1);
    strncpy(tripulantes[todos_tripulante].cargo, cargo, CARGOS - 1);
    strncpy(tripulantes[todos_tripulante].telefone, telefone, 14);

    todos_tripulante++;  // Incrementa o número de tripulantes cadastrados
    printf("Tripulante cadastrado com sucesso! Codigo: %d\n", tripulantes[todos_tripulante - 1].codigo);
    return 1;
}

// Função para listar todos os tripulantes cadastrados
void list_trip()
{
    if (todos_tripulante == 0)  // Verifica se não há tripulantes cadastrados
    {
        printf("Nenhum tripulante cadastrado.\n");
        return;
    }

    for (int i = 0; i < todos_tripulante; i++)  // Exibe todos os tripulantes cadastrados
    {
        printf("Codigo: %d, Nome: %s, Cargo: %s, Telefone: %s\n",
               tripulantes[i].codigo,
               tripulantes[i].nome,
               tripulantes[i].cargo,
               tripulantes[i].telefone);
    }
}

// Função para validar se o campo contém apenas espaços em branco
int validarEspacosEmBranco(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            return 0;  // Se houver algum caractere diferente de espaço
        }
    }
    return 1;  // Se a string for composta apenas por espaços
}

// Função para validar o nome do passageiro
int validarNome(char nome[]) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && !isspace(nome[i])) {
            return 0;  // Se o nome contiver caracteres não permitidos
        }
    }
    return 1;  // Nome válido
}

// Função para validar o telefone do passageiro
int validarTelefone(char telefone[]) {
    for (int i = 0; telefone[i] != '\0'; i++) {
        if (!isdigit(telefone[i])) {
            return 0;  // Se o telefone contiver caracteres não numéricos
        }
    }
    return 1;  // Telefone válido
}
// Função para verificar se o texto contém números
int validarTextoSemNumeros(const char *texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isdigit(texto[i])) {
            return 0; // Contém números
        }
    }
    return 1; // Não contém números
}
// Função para ler os dados do passageiro
// Função para ler os dados do passageiro
Passageiro lerPassageiro() {
    Passageiro p;
    p.codigo = Codigo++;  // Atribui um código único ao passageiro
    char fidelidade_str[10];

    // Validações para o nome
    do {
        printf("Digite o nome do passageiro: ");
        fgets(p.nome, sizeof(p.nome), stdin);
        p.nome[strcspn(p.nome, "\n")] = '\0';

        if (validarEspacosEmBranco(p.nome)) {
            printf("O nome nao pode conter apenas espacos.\n");
        } else if (!validarNome(p.nome)) {
            printf("Nome invalido! Apenas letras e espacos sao permitidos.\n");
        }
    } while (validarEspacosEmBranco(p.nome) || !validarNome(p.nome));

    // Validações para o telefone
    do {
        printf("Digite o telefone do passageiro: ");
        fgets(p.telefone, sizeof(p.telefone), stdin);
        p.telefone[strcspn(p.telefone, "\n")] = '\0';
        if (!validarTelefone(p.telefone)) {
            printf("Telefone invalido! Apenas digitos sao permitidos.\n");
        }
    } while (!validarTelefone(p.telefone));

    // Validações para endereço: rua, cidade, bairro e país
    do {
        printf("Digite a rua do passageiro: ");
        fgets(p.rua, sizeof(p.rua), stdin);
        p.rua[strcspn(p.rua, "\n")] = '\0';
        if (validarEspacosEmBranco(p.rua)) {
            printf("A rua nao pode conter apenas espacos.\n");
        } else if (!validarTextoSemNumeros(p.rua)) {
            printf("A rua nao pode conter numeros.\n");
        }
    } while (validarEspacosEmBranco(p.rua) || !validarTextoSemNumeros(p.rua));

    do {
        printf("Digite a cidade do passageiro: ");
        fgets(p.cidade, sizeof(p.cidade), stdin);
        p.cidade[strcspn(p.cidade, "\n")] = '\0';
        if (validarEspacosEmBranco(p.cidade)) {
            printf("A cidade nao pode conter apenas espacos.\n");
        } else if (!validarTextoSemNumeros(p.cidade)) {
            printf("A cidade nao pode conter numeros.\n");
        }
    } while (validarEspacosEmBranco(p.cidade) || !validarTextoSemNumeros(p.cidade));

    do {
        printf("Digite o bairro do passageiro: ");
        fgets(p.bairro, sizeof(p.bairro), stdin);
        p.bairro[strcspn(p.bairro, "\n")] = '\0';
        if (validarEspacosEmBranco(p.bairro)) {
            printf("O bairro nao pode conter apenas espacos.\n");
        } else if (!validarTextoSemNumeros(p.bairro)) {
            printf("O bairro nao pode conter numeros.\n");
        }
    } while (validarEspacosEmBranco(p.bairro) || !validarTextoSemNumeros(p.bairro));

    do {
        printf("Digite o pais do passageiro: ");
        fgets(p.pais, sizeof(p.pais), stdin);
        p.pais[strcspn(p.pais, "\n")] = '\0';
        if (validarEspacosEmBranco(p.pais)) {
            printf("O pais nao pode conter apenas espacos.\n");
        } else if (!validarTextoSemNumeros(p.pais)) {
            printf("O pais nao pode conter numeros.\n");
        }
    } while (validarEspacosEmBranco(p.pais) || !validarTextoSemNumeros(p.pais));

    // Validação para número da casa
    do {
        printf("Digite o numero da casa do passageiro: ");
        if (scanf("%d", &p.numeroCasa) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida. Digite um numero.\n");
            p.numeroCasa = 0;
        }
    } while (p.numeroCasa <= 0);
    while (getchar() != '\n');

    // Fidelidade
    do {
        printf("O passageiro tem fidelidade? (S/N): ");
        fgets(fidelidade_str, sizeof(fidelidade_str), stdin);
        fidelidade_str[strcspn(fidelidade_str, "\n")] = '\0';

        if (strlen(fidelidade_str) != 1 ||
            (fidelidade_str[0] != 'S' && fidelidade_str[0] != 's' &&
             fidelidade_str[0] != 'N' && fidelidade_str[0] != 'n')) {
            printf("Entrada invalida! Digite apenas 'S' ou 'N'.\n");
            continue;
        }

        p.fidelidade = fidelidade_str[0];
        break;
    } while (1);

    if (p.fidelidade == 'S' || p.fidelidade == 's') {
        do {
            printf("Digite os pontos de fidelidade (valor positivo): ");
            if (scanf("%d", &p.pontosFidelidade) != 1) {
                while (getchar() != '\n');
                printf("Entrada invalida. Digite um numero.\n");
                p.pontosFidelidade = -1;
            }
        } while (p.pontosFidelidade < 0);
        while (getchar() != '\n');
    } else {
        p.pontosFidelidade = 0;
    }

    return p;
}

// Função para cadastrar um passageiro
int cadastrar_passageiro(Passageiro p) {
    if (todos_passageiros < NUM_PASSAGEIROS) {
        passageiros[todos_passageiros++] = p;  // Adiciona o passageiro no array
        printf("Passageiro cadastrado com sucesso! Codigo: %d\n", p.codigo);
        return 1;
    } else {
        printf("Nao e possivel cadastrar mais passageiros.\n");
        return 0;
    }
}

// Função para listar passageiros cadastrados
void listar_passageiros() {
    if (todos_passageiros == 0) {
        printf("Nenhum passageiro cadastrado.\n");
        return;
    }

    for (int i = 0; i < todos_passageiros; i++) {
        printf("Codigo: %d, Nome: %s, Telefone: %s, Fidelidade: %c, Pontos de Fidelidade: %d\n",
               passageiros[i].codigo, passageiros[i].nome, passageiros[i].telefone,
               passageiros[i].fidelidade, passageiros[i].pontosFidelidade);
    }
}




int reservar_assento() {
    int codigo_passageiro;
    char codigo_voo[20];

    // Pergunta o código do passageiro
    printf("Digite o código do passageiro: ");
    scanf("%d", &codigo_passageiro);

    // Verifica se o passageiro existe
    Passageiro *passageiro_encontrado = NULL;
    for (int i = 0; i < todos_passageiros; i++) {
        if (passageiros[i].codigo == codigo_passageiro) {
            passageiro_encontrado = &passageiros[i];
            break;
        }
    }
    if (!passageiro_encontrado) {
        printf("Erro: Passageiro com código %d não encontrado!\n", codigo_passageiro);
        return 0;
    }

    // Pergunta o código do voo
    printf("Digite o código do voo: ");
    scanf("%s", codigo_voo);

    // Verifica se o voo existe
    Voo *voo_encontrado = NULL;
    for (int i = 0; i < totalVoos; i++) {
        if (strcmp(voos[i].codigo, codigo_voo) == 0 && voos[i].ativo == 1) {
            voo_encontrado = &voos[i];
            break;
        }
    }
    if (!voo_encontrado) {
        printf("Erro: Voo com código %s não encontrado ou está inativo!\n", codigo_voo);
        return 0;
    }

    // Verifica se há assento disponível
    Assento *assento_disponivel = NULL;
    for (int i = 0; i < totalAssentos; i++) {
        if (strcmp(assentos[i].codigoVoo, codigo_voo) == 0 && assentos[i].ocupado == 0) {
            assento_disponivel = &assentos[i];
            break;
        }
    }
    if (!assento_disponivel) {
        printf("Erro: Não há assentos disponíveis para o voo %s!\n", codigo_voo);
        return 0;
    }

    // Marca o assento como ocupado
    assento_disponivel->ocupado = 1;

    // Salva a reserva no vetor `reservas[]`
    reservas[totalReservas].codigoPassageiro = codigo_passageiro;
    reservas[totalReservas].numeroAssento = assento_disponivel->numero;
    strcpy(reservas[totalReservas].codigoVoo, codigo_voo);
    totalReservas++;

    // Após confirmar a reserva
    printf("Reserva realizada com sucesso para o passageiro %s no voo %s, assento %d.\n",
       passageiro_encontrado->nome, codigo_voo, assento_disponivel->numero);

    // Acumular pontos de fidelidade
    acumularPontosFidelidade(codigo_passageiro, 10);


    return 1;
}


void exibir_reservas() {
    if (totalReservas == 0) {
        printf("Nenhuma reserva encontrada.\n");
        return;
    }

    printf("\n--- Lista de Reservas ---\n");

    for (int i = 0; i < totalReservas; i++) {
        // Encontrar o passageiro correspondente
        Passageiro *passageiro_encontrado = NULL;
        for (int j = 0; j < todos_passageiros; j++) {
            if (passageiros[j].codigo == reservas[i].codigoPassageiro) {
                passageiro_encontrado = &passageiros[j];
                break;
            }
        }

        // Exibir os detalhes da reserva
        if (passageiro_encontrado != NULL) {
            printf("Voo: %s, Assento: %d, Passageiro: %s (Código: %d)\n",
                   reservas[i].codigoVoo,
                   reservas[i].numeroAssento,
                   passageiro_encontrado->nome,
                   passageiro_encontrado->codigo);
        }
    }

    printf("-------------------------\n");
}

// Função para executar o menu
void executar_menu() {
    char comando[100];
    do {
        // Apresenta o menu para o usuário
        printf("\nEscolha uma opcao:\n");
        printf("1 - Cadastrar Passageiro\n");
        printf("2 - Cadastrar Tripulante\n");
        printf("3 - Listar Passageiros\n");
        printf("4 - Listar Tripulantes\n");


        printf("Digite 'sair' para finalizar o programa.\n");
        fgets(comando, sizeof(comando), stdin);
        comando[strcspn(comando, "\n")] = 0;

        // Processa a escolha do usuário
        if (strcmp(comando, "1") == 0) {
            Passageiro p = lerPassageiro();
            cadastrar_passageiro(p);
        } else if (strcmp(comando, "2") == 0) {
            char nome[50], cargo[20], telefone[15];
            printf("Digite o nome do tripulante: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0;

            printf("Digite o cargo do tripulante:\n-comissario\n-piloto\n-copiloto\n  ");
            fgets(cargo, sizeof(cargo), stdin);
            cargo[strcspn(cargo, "\n")] = 0;

            printf("Digite o telefone do tripulante: ");
            fgets(telefone, sizeof(telefone), stdin);
            telefone[strcspn(telefone, "\n")] = 0;

            cadastrar_tripulante(nome, cargo, telefone);
        } else if (strcmp(comando, "3") == 0) {
            listar_passageiros();
        } else if (strcmp(comando, "4") == 0) {
            list_trip();
        } else if (strcmp(comando, "5") == 0) {


            // Realizar a reserva

        } else if (strcmp(comando, "sair") == 0) {
            printf("Saindo...\n");
        } else {
            printf("Comando desconhecido!\n");
        }
    } while (strcmp(comando, "sair") != 0);  // Repete até o comando "sair"
}

int baixar_reserva() {
    int numero_assento;
    char codigo_voo[20];

    // Solicita ao usuário o código do voo e o número do assento
    printf("Digite o código do voo: ");
    scanf("%s", codigo_voo);

    printf("Digite o número do assento: ");
    scanf("%d", &numero_assento);

    // Verifica se o voo existe
    Voo *voo_encontrado = NULL;
    for (int i = 0; i < totalVoos; i++) {
        if (strcmp(voos[i].codigo, codigo_voo) == 0 && voos[i].ativo == 1) {
            voo_encontrado = &voos[i];
            break;
        }
    }
    if (!voo_encontrado) {
        printf("Erro: Voo com código %s não encontrado ou está inativo!\n", codigo_voo);
        return 0;
    }

    // Verifica se o assento existe e está ocupado
    Assento *assento_encontrado = NULL;
    for (int i = 0; i < totalAssentos; i++) {
        if (strcmp(assentos[i].codigoVoo, codigo_voo) == 0 &&
            assentos[i].numero == numero_assento &&
            assentos[i].ocupado == 1) {
            assento_encontrado = &assentos[i];
            break;
        }
    }
    if (!assento_encontrado) {
        printf("Erro: Assento %d no voo %s não está ocupado!\n", numero_assento, codigo_voo);
        return 0;
    }

    // Libera o assento
    assento_encontrado->ocupado = 0;

    // Calcula o valor total a ser pago
    float valor_total = voo_encontrado->tarifa;
    printf("Assento %d no voo %s liberado com sucesso.\n", numero_assento, codigo_voo);
    printf("Valor total a ser pago: R$%.2f\n", valor_total);

    return 1;
}

void pesquisar_pessoa() {
    char termo[50];
    int escolha;

    // Verificar se há dados cadastrados
    if (todos_passageiros == 0 && todos_tripulante == 0) {
        printf("Erro: Não há passageiros ou tripulantes cadastrados.\n");
        return;
    }

    // Solicita ao usuário o tipo de pesquisa
    printf("Digite 1 para pesquisar Passageiro, 2 para pesquisar Tripulante: ");
    scanf("%d", &escolha);

    if (escolha != 1 && escolha != 2) {
        printf("Erro: Opção inválida.\n");
        return;
    }

    printf("Digite o nome ou código a ser pesquisado: ");
    scanf("%s", termo);

    // Pesquisa Passageiro
    if (escolha == 1) {
        if (todos_passageiros == 0) {
            printf("Erro: Nenhum passageiro cadastrado.\n");
            return;
        }

        Passageiro *encontrado = NULL;
        int codigo_int = atoi(termo); // Converte o termo para inteiro, caso seja um código

        for (int i = 0; i < todos_passageiros; i++) {
            if (strcmp(passageiros[i].nome, termo) == 0 || passageiros[i].codigo == codigo_int) {
                encontrado = &passageiros[i];
                printf("\nPassageiro encontrado:\n");
                printf("Código: %d, Nome: %s, Telefone: %s\n", encontrado->codigo, encontrado->nome, encontrado->telefone);
                printf("Endereço: Rua %s, Nº %d, Bairro %s, Cidade %s, País %s\n",
                       encontrado->rua, encontrado->numeroCasa, encontrado->bairro,
                       encontrado->cidade, encontrado->pais);
                printf("Fidelidade: %c, Pontos: %d\n", encontrado->fidelidade, encontrado->pontosFidelidade);
                return;
            }
        }

        printf("Passageiro não encontrado.\n");
    }
    // Pesquisa Tripulante
    else if (escolha == 2) {
        if (todos_tripulante == 0) {
            printf("Erro: Nenhum tripulante cadastrado.\n");
            return;
        }

        Tripulante *encontrado = NULL;
        int codigo_int = atoi(termo); // Converte o termo para inteiro, caso seja um código

        for (int i = 0; i < todos_tripulante; i++) {
            if (strcmp(tripulantes[i].nome, termo) == 0 || tripulantes[i].codigo == codigo_int) {
                encontrado = &tripulantes[i];
                printf("\nTripulante encontrado:\n");
                printf("Código: %d, Nome: %s, Cargo: %s, Telefone: %s\n",
                       encontrado->codigo, encontrado->nome, encontrado->cargo, encontrado->telefone);
                return;
            }
        }

        printf("Tripulante não encontrado.\n");
    }
}

// Função para acumular pontos de fidelidade caso o passageiro seja fiel
void acumularPontosFidelidade(int codigo_passageiro, int pontos) {
    // Localiza o passageiro no array
    for (int i = 0; i < todos_passageiros; i++) {
        if (passageiros[i].codigo == codigo_passageiro) {
            // Verifica se o passageiro é fidelizado
            if (passageiros[i].fidelidade == 'S' || passageiros[i].fidelidade == 's') {
                passageiros[i].pontosFidelidade += pontos;
                printf("Passageiro %s ganhou %d pontos de fidelidade! Total: %d pontos.\n",
                       passageiros[i].nome, pontos, passageiros[i].pontosFidelidade);
            } else {
                // Caso não seja fiel, não acumula pontos
                printf("Passageiro %s nao e fidelizado, portanto nao acumula pontos.\n", passageiros[i].nome);
            }
            return; // Sai da função após encontrar o passageiro
        }
    }
    // Se não encontrar o passageiro
    printf("Nao foi encontrado passageiro com codigo %d para acumular pontos.\n", codigo_passageiro);
}

void exibirPontosFidelidade() {
    if (todos_passageiros == 0) {
        printf("Nenhum passageiro cadastrado.\n");
        return;
    }

    // Limpa o buffer antes de ler a próxima entrada
    limparBuffer();

    char entrada[100];
    printf("Digite o nome ou codigo do passageiro: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // remove o '\n' do final

    // Tenta converter a entrada para inteiro
    int codigo_procurado = atoi(entrada);
    Passageiro *passageiro_encontrado = NULL;

    if (codigo_procurado > 0) {
        // Busca por código
        for (int i = 0; i < todos_passageiros; i++) {
            if (passageiros[i].codigo == codigo_procurado) {
                passageiro_encontrado = &passageiros[i];
                break;
            }
        }
    } else {
        // Busca por nome
        for (int i = 0; i < todos_passageiros; i++) {
            if (strcmp(passageiros[i].nome, entrada) == 0) {
                passageiro_encontrado = &passageiros[i];
                break;
            }
        }
    }

    if (passageiro_encontrado) {
        printf("\nPassageiro encontrado:\n");
        printf("Codigo: %d\n", passageiro_encontrado->codigo);
        printf("Nome: %s\n", passageiro_encontrado->nome);
        printf("Fidelidade: %c\n", passageiro_encontrado->fidelidade);
        printf("Pontos de Fidelidade: %d\n", passageiro_encontrado->pontosFidelidade);
    } else {
        printf("Nenhum passageiro encontrado com o nome ou codigo fornecido.\n");
    }

    // Opcional: Pausar a tela para o usuário ver a informação antes de voltar ao menu
    // printf("Pressione ENTER para voltar ao menu...");
    // getchar();
}

void testarCadastroVoo() {
    totalVoos = 0;

    // Configura os dados do voo para teste
    strcpy(voos[totalVoos].codigo, "VOO123");
    strcpy(voos[totalVoos].origem, "São Paulo");
    strcpy(voos[totalVoos].destino, "Rio de Janeiro");
    strcpy(voos[totalVoos].data, "12/12/2024");
    strcpy(voos[totalVoos].hora, "14:30");
    voos[totalVoos].tarifa = 500.0;
    voos[totalVoos].ativo = 1;
    totalVoos++;

    // Verifica se o total de voos foi incrementado corretamente
    if (totalVoos == 1) {
        printf("Teste de total de voos: PASSOU\n");
    } else {
        printf("Teste de total de voos: FALHOU (esperado 1, obtido %d)\n", totalVoos);
    }

    // Verifica se o código do voo foi armazenado corretamente
    if (strcmp(voos[0].codigo, "VOO123") == 0) {
        printf("Teste de código do voo: PASSOU\n");
    } else {
        printf("Teste de código do voo: FALHOU (esperado 'VOO123', obtido '%s')\n", voos[0].codigo);
    }

    printf("Teste de cadastro de voo concluído.\n");
}

void testarValidarData() {
    // Verifica uma data válida
    if (validarData("12/12/2024") == 1) {
        printf("Teste de data valida ('12/12/2024'): PASSOU\n");
    } else {
        printf("Teste de data valida ('12/12/2024'): FALHOU\n");
    }

    // Verifica uma data invalida
    if (validarData("32/12/2024") == 0) {
        printf("Teste de data invalida ('32/12/2024'): PASSOU\n");
    } else {
        printf("Teste de data invalida ('32/12/2024'): ERROU\n");
    }

    printf("Teste de validacao de data concluído.\n");
}

// Teste para buscar um voo pelo codigo
void testarBuscarVoo() {
    // Cadastro inicial de voos para o teste
    strcpy(voos[totalVoos].codigo, "TEST123");
    totalVoos++;
    strcpy(voos[totalVoos].codigo, "FLY456");
    totalVoos++;

    // Teste de busca bem-sucedida
    int indice = buscarVoo("TEST123");
    if (indice != -1) {
        printf("Teste de busca de voo ('TEST123'): PASSOU\n");
    } else {
        printf("Teste de busca de voo ('TEST123'): FALHOU\n");
    }

    // Teste de busca falha
    indice = buscarVoo("NOTFOUND");
    if (indice == -1) {
        printf("Teste de busca de voo inexistente ('NOTFOUND'): PASSOU\n");
    } else {
        printf("Teste de busca de voo inexistente ('NOTFOUND'): FALHOU\n");
    }
}

// Teste para validar a hora no formato HH:MM
void testarValidarHora() {
    // Teste de horas válidas
    if (validarHora("12:30")) {
        printf("Teste de hora valida ('12:30'): PASSOU\n");
    } else {
        printf("Teste de hora valida ('12:30'): FALHOU\n");
    }

    // Teste de horas inválidas
    if (!validarHora("25:00")) {
        printf("Teste de hora invalida ('25:00'): PASSOU\n");
    } else {
        printf("Teste de hora invalida ('25:00'): FALHOU\n");
    }

    if (!validarHora("12:60")) {
        printf("Teste de hora inválida ('12:60'): PASSOU\n");
    } else {
        printf("Teste de hora inválida ('12:60'): FALHOU\n");
    }
}

// Teste para cadastrar assentos e verificar disponibilidade
void testarCadastroAssento() {
    // Cadastro inicial de um voo para associar assentos
    strcpy(voos[totalVoos].codigo, "ASSENTO123");
    totalVoos++;

    // Cadastro de um assento no voo
    strcpy(assentos[totalAssentos].codigoVoo, "ASSENTO123");
    assentos[totalAssentos].numero = 1;
    assentos[totalAssentos].ocupado = 0; // Livre inicialmente
    assentos[totalAssentos].codigoPassageiro = 0;
    totalAssentos++;

    // Verificar se o assento foi registrado corretamente
    if (strcmp(assentos[0].codigoVoo, "ASSENTO123") == 0 &&
        assentos[0].numero == 1 &&
        assentos[0].ocupado == 0) {
        printf("Teste de cadastro de assento: PASSOU\n");
    } else {
        printf("Teste de cadastro de assento: FALHOU\n");
    }
}

// Testes
void testarCadastrarTripulante() {
    // Teste de cadastro válido
    char nome[] = "Joao Silva";
    char cargo[] = "piloto";
    char telefone[] = "123456789";
    int resultado = cadastrar_tripulante(nome, cargo, telefone);
    assert(resultado == 1);  // Espera-se sucesso no cadastro

    // Teste de nome inválido
    char nomeInvalido[] = "Joao123";
    resultado = cadastrar_tripulante(nomeInvalido, cargo, telefone);
    assert(resultado == 0);  // Espera-se falha no cadastro devido ao nome inválido
}

void testarVerificarOcargos() {
    // Teste com cargo válido
    assert(VerificarOcargos("piloto") == 1);
    assert(VerificarOcargos("copiloto") == 1);
    assert(VerificarOcargos("comissario") == 1);

    // Teste com cargo inválido
    assert(VerificarOcargos("atendente") == 0);
}

void testarValidarNome() {
    // Teste com nome válido
    assert(validar_nome("Joao Silva") == 1);

    // Teste com nome inválido
    assert(validar_nome("Joao123") == 0);
    assert(validar_nome("") == 0);  // Nome vazio é inválido
}

void testarValidarTelefone() {
    // Teste com telefone válido
    assert(validar_telefone("123456789") == 1);

    // Teste com telefone inválido
    assert(validar_telefone("1234") == 0);  // Número de telefone curto
    assert(validar_telefone("abcdefgh") == 0);  // Letras no telefone
}

void test_validarTelefone() {
    assert(validarTelefone("1234567890") == 1);
    assert(validarTelefone("123-456-7890") == 0);
    assert(validarTelefone("12345678a0") == 0);
    assert(validarTelefone("987654321") == 1);
}

void test_validarTextoSemNumeros() {
    assert(validarTextoSemNumeros("Cidade de São Paulo") == 1);
    assert(validarTextoSemNumeros("Rua 123") == 0);
    assert(validarTextoSemNumeros("Bairro") == 1);
    assert(validarTextoSemNumeros("Bairro1") == 0);
}

void test_list_trip() {
    // Teste com nenhum tripulante cadastrado
    todos_tripulante = 0;
    list_trip();  // Espera: Nenhum tripulante cadastrado.

    // Teste com um tripulante cadastrado
    todos_tripulante = 1;
    tripulantes[0].codigo = 1;
    strcpy(tripulantes[0].nome, "João");
    strcpy(tripulantes[0].cargo, "Piloto");
    strcpy(tripulantes[0].telefone, "123456789");
    list_trip();  // Espera: Detalhes do tripulante João
}

void testar_cadastro_passageiro() {
    Passageiro p;
    // Simula o cadastro de um passageiro
    strcpy(p.nome, "Lucas");
    p.codigo = 1;
    strcpy(p.telefone, "123456789");
    strcpy(p.rua, "Rua Exemplo");
    p.numeroCasa = 123;
    strcpy(p.bairro, "Bairro Exemplo");
    strcpy(p.cidade, "Cidade Exemplo");
    strcpy(p.pais, "Brasil");
    p.fidelidade = 'S';
    p.pontosFidelidade = 100;

    // Cadastra o passageiro
    cadastrar_passageiro(p);

    // Verifica se o passageiro foi cadastrado corretamente
    Passageiro *passageiro_cadastrado = &passageiros[0];

    // Verificação manual com if
    if (passageiro_cadastrado != NULL &&
        strcmp(passageiro_cadastrado->nome, "Lucas") == 0 &&
        passageiro_cadastrado->codigo == 1 &&
        strcmp(passageiro_cadastrado->telefone, "123456789") == 0) {
        printf("Teste de cadastro do passageiro passou com sucesso!\n");
    } else {
        printf("Teste de cadastro do passageiro falhou.\n");
    }
}

void testar_baixar_reserva() {
    // Suponha que temos um voo e assento já cadastrados
    Voo voo_exemplo = {"Voo123", 1, 500.0};
    Assento assento_exemplo = {"Voo123", 10, 1};  // 1 significa que o assento está ocupado
    voos[0] = voo_exemplo;
    assentos[0] = assento_exemplo;

    // Verifica o estado inicial do assento
    if (assentos[0].ocupado == 1) {
        // Realiza a liberação do assento
        int resultado = baixar_reserva();

        // Verifica se a operação foi bem-sucedida
        if (resultado == 1 && assentos[0].ocupado == 0) {
            printf("Teste de liberação de reserva passou com sucesso!\n");
        } else {
            printf("Teste de liberação de reserva falhou.\n");
        }
    } else {
        printf("Assento ja estava livre, passou no teste.\n");
    }
}

int main() {
 setlocale(LC_ALL, "Portuguese");


    printf("========================================\n");
    printf("           TESTES DA TOP FLY          \n");
    printf("========================================\n");
    printf("                 __|__                  \n");
    printf("         --@--@--(_)--@--@--            \n");
    printf("                /     \\                 \n");
    printf("               /       \\                \n");
    printf("             _|_________|_              \n");
    printf("            |___________|               \n");
    printf("        Suas asas para o mundo.         \n");
    printf("----------------------------------------\n");
    printf("| Explore o mundo com as melhores rotas |\n");
    printf("| Preços acessiveis e serviço premium.  |\n");
    printf("| Visite: www.topflytravel.com          |\n");
    printf("----------------------------------------\n");
    printf("    Obrigado por escolher a TOP FLY!    \n");
    printf("========================================\n");


    testarValidarData();
    testarCadastroVoo();
    testarCadastroAssento();
    testarValidarHora();
    testarBuscarVoo();
    test_validarTelefone();
    test_validarTextoSemNumeros();
    test_list_trip();
    testar_cadastro_passageiro();
    testar_baixar_reserva();

    return 0;
}


# Trabalho Interdisciplinar - Companhia Aérea Voo Seguro | TOPFLY
### Pontifícia Universidade Católica de Minas Gerais 
### Unidade - Coração Eucarístico
### Desenvolvedores: Pedro Henrique Roldão, Joao Vitor Russo, Bryan Breder, Davi Nunes

<div align="center">
<img src = "https://github.com/user-attachments/assets/58467434-67b1-4cfc-8cbf-e8b4f565a894" width="500px" height="600px">
</div>

## Vídeo de apresentação: **(A ser colocado)**

## 1. Introdução 

A Voo Seguro precisa de um sistema que transforme seu caos administrativo em organização digital. Então para resolver isso desenvolvemos um software (TOP FLY) para eliminar problemas como reservas duplicadas, falta de controle sobre disponibilidade de voos e assentos, e desorganização no registro de informações. Ao centralizar dados de passageiros (incluindo informações pessoais e de fidelidade), tripulação (com detalhes profissionais), voos (com características completas) e reservas, o sistema promoverá maior eficiência operacional.


## Backlog do produto
Backlog do produto: 

 

### SPRINT 1: (1 DIAS)  Ínicio: 02/12/2024 Fim: 03/12/2024
<div align="center">
 <img src = "https://github.com/user-attachments/assets/de9cc130-bbd3-4db1-8c1d-56b4b5a700ec" >
</div>

 

### SPRINT 2: (2 DIAS) ÍNICIO: 03/12/2024 FIM 05/12/2024  

 <div align="center">
 <img src = "https://github.com/user-attachments/assets/0b2a0c07-d4a9-408a-aa82-95182f9ece50">
 </div>

### SPRINT 3: (A ser Definido) 

 <div align="center">
<img src = "https://github.com/user-attachments/assets/ee0754e6-0850-4d5d-abb9-83915487cf7e" >
 </div>

### SPRINT 4: (A ser Definido) 

 <div align="center">
 <img src = "https://github.com/user-attachments/assets/55eb7bea-4a9e-4bc7-b2b2-050d9137f337" >
 </div>
 

# Documentação das Funções

## Lista de assinaturas das funções e paramêtros

## Estruturas de Dados Principais

- **Reserva**: Representa uma reserva de assento vinculada a um voo e passageiro.
- **Assento**: Define os assentos de um voo, indicando se estão ocupados.
- **Voo**: Armazena informações como código, origem, destino, data, hora e tarifa do voo.
- **Tripulante**: Representa a equipe de bordo, incluindo pilotos, copilotos e comissários.
- **Passageiro**: Detalha informações pessoais e status de fidelidade dos passageiros.

---

## Lista de Funções

### Funções Gerais

#### `void limparBuffer()`
- **Descrição**: Limpa o buffer de entrada para evitar problemas ao ler dados do usuário.
- **Parâmetros**: Nenhum.
- **Retorno**: Nenhum.

#### `void capturarTexto(const char *mensagem, char *saida, int tamanho)`
- **Descrição**: Lê uma string do usuário, remove espaços extras e valida a entrada.
- **Parâmetros**:
  - `mensagem`: Mensagem exibida ao usuário.
  - `saida`: Buffer onde a entrada será armazenada.
  - `tamanho`: Tamanho máximo permitido para a entrada.
- **Retorno**: Nenhum.

#### `int validarData(const char *data)`
- **Descrição**: Valida uma data no formato `DD/MM/AAAA`.
- **Parâmetros**:
  - `data`: String representando a data a ser validada.
- **Retorno**: 1 se a data for válida, 0 caso contrário.

#### `int validarHora(const char *hora)`
- **Descrição**: Valida uma hora no formato `HH:MM`.
- **Parâmetros**:
  - `hora`: String representando a hora a ser validada.
- **Retorno**: 1 se a hora for válida, 0 caso contrário.

---

### Gerenciamento de Voos

#### `int buscarVoo(const char *codigoVoo)`
- **Descrição**: Busca um voo pelo código fornecido.
- **Parâmetros**:
  - `codigoVoo`: Código do voo a ser buscado.
- **Retorno**: Índice do voo encontrado ou -1 se não existir.

#### `void cadastrarVoo()`
- **Descrição**: Cadastra um novo voo solicitando as informações necessárias ao usuário.
- **Parâmetros**: Nenhum.
- **Retorno**: Nenhum.

#### `void listarVoos()`
- **Descrição**: Exibe todos os voos cadastrados com seus detalhes.
- **Parâmetros**: Nenhum.
- **Retorno**: Nenhum.

---

### Gerenciamento de Assentos

#### `void cadastrarAssento()`
- **Descrição**: Cadastra assentos para um voo existente.
- **Parâmetros**: Nenhum.
- **Retorno**: Nenhum.

#### `void listarAssentos()`
- **Descrição**: Lista todos os assentos cadastrados, indicando se estão ocupados ou livres.
- **Parâmetros**: Nenhum.
- **Retorno**: Nenhum.

---

### Gerenciamento de Passageiros

#### `Passageiro lerPassageiro()`
- **Descrição**: Lê e valida as informações fornecidas pelo usuário para criar um novo passageiro.
- **Parâmetros**: Nenhum.
- **Retorno**: Estrutura `Passageiro` preenchida.

#### `int cadastrar_passageiro(Passageiro p)`
- **Descrição**: Cadastra um passageiro no sistema.
- **Parâmetros**:
  - `p`: Estrutura contendo os dados do passageiro.
- **Retorno**: 1 em caso de sucesso, 0 se houver falha (por exemplo, limite atingido).

#### `void listar_passageiros()`
- **Descrição**: Exibe todos os passageiros cadastrados com suas informações.
- **Parâmetros**: Nenhum.
- **Retorno**: Nenhum.

---

### Gerenciamento de Tripulantes

#### `int cadastrar_tripulante(char nome[], char cargo[], char telefone[])`
- **Descrição**: Valida e cadastra um novo tripulante.
- **Parâmetros**:
  - `nome`: Nome do tripulante.
  - `cargo`: Cargo (piloto, copiloto, comissário).
  - `telefone`: Telefone de contato.
- **Retorno**: 1 em caso de sucesso, 0 se os dados forem inválidos.

#### `void list_trip()`
- **Descrição**: Lista todos os tripulantes cadastrados.
- **Parâmetros**: Nenhum.
- **Retorno**: Nenhum.

---

### Reservas

#### `int reservar_assento()`
- **Descrição**: Realiza uma reserva vinculando passageiro, voo e assento disponível.
- **Parâmetros**: Nenhum.
- **Retorno**: 1 se a reserva for bem-sucedida, 0 caso contrário.

#### `void exibir_reservas()`
- **Descrição**: Lista todas as reservas realizadas, incluindo detalhes do passageiro e assento.
- **Parâmetros**: Nenhum.
- **Retorno**: Nenhum.

#### `int baixar_reserva()`
- **Descrição**: Libera um assento previamente reservado.
- **Parâmetros**: Nenhum.
- **Retorno**: 1 em caso de sucesso, 0 caso contrário.

---

### Fidelidade

#### `void acumularPontosFidelidade(int codigo_passageiro, int pontos)`
- **Descrição**: Adiciona pontos ao programa de fidelidade de um passageiro fidelizado.
- **Parâmetros**:
  - `codigo_passageiro`: Código do passageiro.
  - `pontos`: Pontuação a ser adicionada.
- **Retorno**: Nenhum.

#### `void exibirPontosFidelidade()`
- **Descrição**: Mostra o status de fidelidade e os pontos acumulados de um passageiro.
- **Parâmetros**: Nenhum.
- **Retorno**: Nenhum.

---

### Pesquisa

#### `void pesquisar_pessoa()`
- **Descrição**: Permite buscar passageiros ou tripulantes pelo nome ou código.
- **Parâmetros**: Nenhum.
- **Retorno**: Nenhum.

---

## Como Usar
1. Compile o programa utilizando um compilador C.
2. Execute o programa e siga as instruções do menu interativo.

# Casos de Teste

# Considerações Adicionais

O desenvolvimento do sistema de gerenciamento para a companhia aérea **Voo Seguro** aborda um problema real que a empresa enfrenta atualmente. A gestão de voos, reservas e tripulação feita manualmente em planilhas e cadernos tem gerado uma série de complicações, como reservas duplicadas, falta de controle sobre a disponibilidade de voos e assentos, além de dificuldades na comunicação entre os membros da tripulação. Esses problemas não apenas afetam a eficiência operacional da companhia, mas também impactam negativamente a experiência do passageiro.

## 1. Problemas Identificados

Ao longo do trabalho, ficou claro que a falta de um sistema integrado para gerenciar as operações da companhia aérea resultava em:

- **Reservas Duplicadas**: Sem um controle adequado, é fácil que dois passageiros tentem reservar o mesmo assento no mesmo voo, levando a conflitos e insatisfação.
- **Falta de Controle sobre Voos e Assentos**: Gerenciar informações em planilhas pode ser confuso e propenso a erros, resultando em informações desatualizadas ou incorretas.
- **Dificuldades na Comunicação**: A falta de um sistema centralizado dificulta a comunicação entre os membros da tripulação, o que é crucial para garantir que todos estejam cientes das informações do voo.

Esses problemas não apenas afetam a operação diária da Voo Seguro, mas também podem prejudicar a imagem da companhia e sua capacidade de fidelizar passageiros.

## 2. Solução Proposta

O sistema que estamos desenvolvendo tem como objetivo resolver esses desafios ao centralizar todas as informações sobre voos, assentos, passageiros e tripulação em uma plataforma única e de fácil acesso, implementando validações rigorosas para garantir que não haja reservas duplicadas e que todos os dados sejam precisos e válidos, além de aprimorar a comunicação entre os membros da tripulação, permitindo que cada um tenha acesso rápido e claro às informações essenciais para a operação de cada voo, tudo isso para garantir uma operação mais eficiente, sem erros e com maior integração.

## 3. Aprendizados Durante o Trabalho

Durante o desenvolvimento deste projeto, tivemos várias oportunidades de aprendizado que foram fundamentais para nosso crescimento como estudantes do 1 período da PUC-MINAS:

- **Aplicação Prática de Teoria**: O projeto nos permitiu aplicar conceitos teóricos aprendidos nas aulas, como organizar e documentar um software, arquitetura de um software, algoritmos, backlog, github, e muitos mais..
- **Desenvolvimento de Habilidades Técnicas**: Aprendemos a programar em C com mais profundidade, incluindo como estruturar código, criar funções reutilizáveis e implementar validações eficazes. Essas habilidades serão valiosas não apenas neste projeto, mas em nossa futura carreira na área de tecnologia.
- **Colaboração e Trabalho em Equipe**: O trabalho em grupo nos ensinou sobre a importância da comunicação clara e da divisão eficiente das tarefas. Cada membro teve a oportunidade de se especializar em diferentes partes do sistema, mas também precisávamos garantir que tudo funcionasse bem junto. O que as vezes nos trouxe bastante dificuldade, mas tenho certeza que vai nós agregar muito no futuro.
- **Importância dos Testes**: Compreendemos melhor como os testes são essenciais para garantir que o software funcione conforme esperado. Criar casos de teste nos ajudou a pensar criticamente sobre como cada parte do sistema deve se comportar.
- **Reflexão sobre Impacto Social**: Ao lidar com um projeto que tem implicações diretas na experiência dos passageiros, começamos a entender melhor como o software pode impactar positivamente as operações empresariais e a satisfação do cliente.

## Conclusão

O desenvolvimento do sistema para a **Voo Seguro** não apenas nos proporcionou uma experiência prática valiosa no campo da programação e engenharia de software, mas também nos fez refletir sobre os desafios reais enfrentados por empresas no dia a dia. Através desse trabalho, aprendemos sobre colaboração, validações rigorosas e a importância de um sistema bem estruturado. Estamos confiantes de que este projeto também nos preparará melhor para futuros desafios na nossa jornada acadêmica e profissional.


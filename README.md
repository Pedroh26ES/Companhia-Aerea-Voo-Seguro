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

### **`void limparBuffer()`**
- **Assinatura:** `void limparBuffer()`
- **Parâmetros:** Nenhum.
- **Descrição:**  
  Limpa o buffer de entrada para evitar que entradas anteriores interfiram nas próximas leituras.  
  Utiliza um loop para ler caracteres até encontrar uma nova linha ou o final do arquivo.

---

### **`void capturarTexto(const char *mensagem, char *saida, int tamanho)`**
- **Assinatura:** `void capturarTexto(const char *mensagem, char *saida, int tamanho)`
- **Parâmetros:**
  - `const char *mensagem`: Mensagem exibida ao usuário.
  - `char *saida`: Ponteiro onde a entrada válida será armazenada.
  - `int tamanho`: Tamanho máximo da string a ser capturada.
- **Descrição:**  
  Captura uma string do usuário removendo espaços em branco extras. Utiliza um buffer temporário para armazenar a entrada antes de processá-la.

---

### **`int validarData(const char *data)`**
- **Assinatura:** `int validarData(const char *data)`
- **Parâmetros:**
  - `const char *data`: String representando a data a ser validada.
- **Descrição:**  
  Valida se uma data está no formato `DD/MM/AAAA`.  
  Verifica o comprimento da string e a validade dos valores de dia, mês e ano.

---

### **`int validarHora(const char *hora)`**
- **Assinatura:** `int validarHora(const char *hora)`
- **Parâmetros:**
  - `const char *hora`: String representando a hora a ser validada.
- **Descrição:**  
  Valida se uma hora está no formato `HH:MM`.  
  Verifica o comprimento da string e os limites válidos para horas e minutos.

---

### **`int buscarVoo(const char *codigoVoo)`**
- **Assinatura:** `int buscarVoo(const char *codigoVoo)`
- **Parâmetros:**
  - `const char *codigoVoo`: Código do voo que se deseja buscar.
- **Descrição:**  
  Percorre todos os voos cadastrados em busca do código fornecido.  
  Retorna o índice do voo se encontrado ou `-1` se não encontrado.

---

## Funções de Cadastro

### **`void cadastrarVoo()`**
- **Assinatura:** `void cadastrarVoo()`
- **Parâmetros:** Nenhum.
- **Descrição:**  
  Cadastra um novo voo no sistema após verificar se o número máximo de voos foi atingido.  
  Solicita informações como código do voo, origem, destino, data, hora, códigos dos tripulantes e tarifa.  
  Realiza validações para garantir que os dados são válidos antes de armazená-los.

---

### **`void listarVoos()`**
- **Assinatura:** `void listarVoos()`
- **Parâmetros:** Nenhum.
- **Descrição:**  
  Lista todos os voos cadastrados no sistema.  
  Se não houver voos cadastrados, informa ao usuário; caso contrário, imprime as informações relevantes de cada voo.

---

### **`void cadastrarAssento()`**
- **Assinatura:** `void cadastrarAssento()`
- **Parâmetros:** Nenhum.
- **Descrição:**  
  Cadastra um novo assento para um voo existente.  
  Solicita o código do voo e verifica se ele existe antes de solicitar o número do assento.  
  Realiza validações para garantir que o assento não esteja ocupado ou fora dos limites válidos.

---

### **`void listarAssentos()`**
- **Assinatura:** `void listarAssentos()`
- **Parâmetros:** Nenhum.
- **Descrição:**  
  Lista todos os assentos cadastrados no sistema.  
  Se não houver assentos cadastrados, informa ao usuário; caso contrário, imprime as informações dos assentos junto com seu status (livre ou ocupado).

---

## Funções Relacionadas a Tripulantes

### **`int VerificarOcargos(char cargo[])`**
- **Assinatura:** `int VerificarOcargos(char cargo[])`
- **Parâmetros:**
  - `char cargo[]`: String representando o cargo a ser verificado.
- **Descrição:**  
  Verifica se o cargo informado é válido (`piloto`, `copiloto` ou `comissário`).  
  Retorna `1` se for válido; caso contrário, imprime os cargos válidos e retorna `0`.

---

### **`int validar_nome(char nome[])`**
- **Assinatura:** `int validar_nome(char nome[])`
- **Parâmetros:**
  - `char nome[]`: String representando o nome a ser validado.
- **Descrição:**  
  Valida se o nome contém apenas letras e espaços sem exceder 49 caracteres.  
  Retorna `1` se válido; caso contrário, retorna `0`.

---

### **`int validar_telefone(char telefone[])`**
- **Assinatura:** `int validar_telefone(char telefone[])`
- **Parâmetros:**
  - `char telefone[]`: String representando o telefone a ser validado.
- **Descrição:**  
  Valida se o telefone contém apenas números e está dentro dos limites de comprimento definidos (8 a 14 caracteres).  
  Retorna `1` se válido; caso contrário, retorna `0`.

---

### **`int cadastrar_tripulante(char nome[], char cargo[], char telefone[])`**
- **Assinatura:** `int cadastrar_tripulante(char nome[], char cargo[], char telefone[])`
- **Parâmetros:**
  - `char nome[]`: Nome do tripulante.
  - `char cargo[]`: Cargo do tripulante.
  - `char telefone[]`: Telefone de contato do tripulante.
- **Descrição:**  
  Cadastra um novo tripulante no sistema após verificar se o limite máximo foi atingido.  
  Realiza validações para garantir que as informações estão corretas antes de armazená-las.

---

### **`void list_trip()`**
- **Assinatura:** `void list_trip()`
- **Parâmetros:** Nenhum.
- **Descrição:**  
  Lista todos os tripulantes cadastrados no sistema.  
  Se não houver tripulantes cadastrados, informa ao usuário; caso contrário, imprime as informações relevantes de cada tripulante.

---

## Funções Relacionadas a Passageiros

### **`Passageiro lerPassageiro()`**
- **Assinatura:** `Passageiro lerPassageiro()`
- **Parâmetros:** Nenhum.
- **Descrição:**  
  Lê os dados de um passageiro e retorna uma estrutura preenchida com essas informações.  
  Solicita informações como nome, telefone e endereço com validações em cada etapa.

---

### **`int validarEspacosEmBranco(char str[])`**
- **Assinatura:** `int validarEspacosEmBranco(char str[])`
- **Parâmetros:**
  - `char str[]`: String a ser verificada.
- **Descrição:**  
  Verifica se uma string contém apenas espaços em branco.  
  Retorna `1` se for composta apenas por espaços; caso contrário, retorna `0`.

---

### **`int validarNome(char nome[])`**
- **Assinatura:** `int validarNome(char nome[])`
- **Parâmetros:**
  - `char nome[]`: Nome do passageiro a ser validado.
- **Descrição:**  
  Valida se o nome contém apenas caracteres permitidos (letras e espaços).  
  Retorna `1` se válido; caso contrário, retorna `0`.

---

### **`int validarTelefone(char telefone[])`**
- **Assinatura:** `int validarTelefone(char telefone[])`
- **Parâmetros:**
  - `char telefone[]`: Telefone do passageiro a ser validado.
- **Descrição:**  
  Valida se o telefone contém apenas números.  
  Retorna `1` se válido; caso contrário, retorna `0`.


  **Futuramente será implementando mais funcionalidades e será documentado a lista de assinatura e paramêtros tudo aqui.

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


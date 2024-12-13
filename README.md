# Trabalho Interdisciplinar - Companhia Aérea Voo Seguro | TOPFLY
### Pontifícia Universidade Católica de Minas Gerais 
### Unidade - Coração Eucarístico
### Desenvolvedores: Pedro Henrique Roldão, Joao Vitor Russo, Brian Breder, Davi Nunes
### Nome do Nosso Projeto: TOPFLY

<br>

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

### SPRINT 3: (2 DIAS) ÍNICIO: 07/12/2024 FIM 09/12/2024

 <div align="center">
<img src = "https://github.com/user-attachments/assets/ee0754e6-0850-4d5d-abb9-83915487cf7e" >
 </div>

### SPRINT 4: (1 DIA) ÍNICIO: 12//12/2024 FIM 12/12/2024 

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

## Caso de Teste: Cadastro de Passageiro

| ID do Caso de Teste | Descrição                                | Pré-condições        | Passos para Execução                                  | Resultado Esperado                        |
|---------------------|------------------------------------------|----------------------|-------------------------------------------------------|-------------------------------------------|
| TC01                | Cadastro de um novo passageiro           | Nenhuma              | 1. Digite o número 5 para acessar o módulo de cadastro de passageiros e depois digite 1 para começar o cadastro. <br> 2. Preencha todos os dados corretamente, nome do passageiro, endereço, telefone, pontos de fideldade e etc.. <br> 3. Após isso clique enter para cadastrar o passageiro. | Passageiro cadastrado com sucesso.         |

## Caso de Teste: Listagem de Passageiros

| ID do Caso de Teste | Descrição                                | Pré-condições        | Passos para Execução                                  | Resultado Esperado                        |
|---------------------|------------------------------------------|----------------------|-------------------------------------------------------|-------------------------------------------|
| TC02                | Listagem de todos os passageiros         | Passageiros cadastrados | 1. Digite o número 5 para acessar o módulo de passageiro e depois digite o número 3 para listar todos os passageiros que já foram cadastrados. <br> 2. Verificar a lista exibida. | A lista de passageiros é exibida corretamente. |

## Caso de Teste: Cadastro de Tripulante

| ID do Caso de Teste | Descrição                                | Pré-condições        | Passos para Execução                                  | Resultado Esperado                        |
|---------------------|------------------------------------------|----------------------|-------------------------------------------------------|-------------------------------------------|
| TC03                | Cadastro de um novo tripulante           | Nenhuma              | 1. Digite 5 para acessar o módulo de cadastro de tripulantes. <br> 2. Preencher dados como nome, cargo (piloto, comissario ou copiloto) e digitar o número de telefone. <br> 3. Digite enter para completar o cadastro. | Tripulante cadastrado com sucesso.        |

## Caso de Teste: Listagem de Tripulantes

| ID do Caso de Teste | Descrição                                | Pré-condições        | Passos para Execução                                  | Resultado Esperado                        |
|---------------------|------------------------------------------|----------------------|-------------------------------------------------------|-------------------------------------------|
| TC04                | Listagem de todos os tripulantes         | Tripulantes cadastrados | 1. Digite o número 5 para acessar a tela de listagem de tripulantes. Depois, digite o número 4 para listar os tripulantes que já foram cadastrados. <br> 2. Verificar a lista exibida. | A lista de tripulantes é exibida corretamente. |

## Caso de Teste: Cadastro de Voo

| ID do Caso de Teste | Descrição                                | Pré-condições        | Passos para Execução                                  | Resultado Esperado                        |
|---------------------|------------------------------------------|----------------------|-------------------------------------------------------|-------------------------------------------|
| TC05                | Cadastro de um novo voo                  | Nenhuma              | 1. Digite 1 para acessar o módulo de cadastro de voos. <br> 2. Preencha os dados do voo, como código do voo, origem do voo, destino do voo, data do voo, hora do voo, e etc... <br> 3. Enviar e verificar o cadastro. | Voo cadastrado com sucesso.               |

## Caso de Teste: Listagem de Voos

| ID do Caso de Teste | Descrição                                | Pré-condições        | Passos para Execução                                  | Resultado Esperado                        |
|---------------------|------------------------------------------|----------------------|-------------------------------------------------------|-------------------------------------------|
| TC06                | Listagem de todos os voos                | Voos cadastrados     | 1. Digite 4 para acessar a tela de listagem de voos. <br> 2. Verificar a lista de voos exibida. | A lista de voos será exibida corretamente.   |


## Caso de Teste: Cadastro de Assentos

| ID do Caso de Teste | Descrição                                | Pré-condições        | Passos para Execução                                  | Resultado Esperado                        |
|---------------------|------------------------------------------|----------------------|-------------------------------------------------------|-------------------------------------------|
| TC07                | Cadastro de assentos para voo            | Voo cadastrado       | 1. Digite o número 2 para acessar a tela de cadastro de assentos. <br> 2. Preencha o dado do voo. (Observação: O Voo já tem que ter sido cadastro anteriormente.) <br> 3. Submeta e Verifique os dados do formulário. | Assento cadastrado com sucesso.           |

## Caso de Teste: Cadastro de Reserva de Passageiro

| ID do Caso de Teste | Descrição                                | Pré-condições        | Passos para Execução                                  | Resultado Esperado                        |
|---------------------|------------------------------------------|----------------------|-------------------------------------------------------|-------------------------------------------|
| TC08                | Realizar reserva de passageiro para voo  | Passageiro e voo cadastrados | 1. Digite o número 6 para acessar o módulo de reservas. <br> 2. Preencha com o código do passageiro. (Observação: O Passageiro já tem que ter sido cadastrado) <br> 3. Confirmar a sua reserva. | Reserva realizada com sucesso.            |

# Casos de Teste - Validação de Entrada

## Caso de Teste 8: Testar Nome com Números

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC09                | Validar se o nome contém apenas letras e espaços | "João123"  | O programa deve retornar um erro dizendo "Nome inválido! Apenas letras e espaços são permitidos." e pedir para inserir novamente. | 1. Inserir "João123" como nome. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 9: Testar País com Números

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC10                | Validar se o país contém apenas letras e espaços | "Brasil123" | O programa deve retornar um erro dizendo "País inválido! Apenas letras e espaços são permitidos." e pedir para inserir novamente. | 1. Inserir "Brasil123" como país. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 10: Testar País com Caracteres Especiais

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC11                | Validar se o país contém apenas letras e espaços | "Br@sil"    | O programa deve retornar um erro dizendo "País inválido! Apenas letras e espaços são permitidos." e pedir para inserir novamente. | 1. Inserir "Br@sil" como país. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 11: Testar Cidade com Números

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC12                | Validar se a cidade contém apenas letras e espaços | "São Paulo 123" | O programa deve retornar um erro dizendo "Cidade inválida! Apenas letras e espaços são permitidos." e pedir para inserir novamente. | 1. Inserir "São Paulo 123" como cidade. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 12: Testar Rua com Apenas Letras

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC13                | Validar se a rua contém letras e números | "Rua A"     | O programa deve retornar um erro dizendo "Rua inválida! A rua deve conter números e letras." e pedir para inserir novamente. | 1. Inserir "Rua A" como rua. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 13: Testar Número de Casa Negativo

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC14                | Validar se o número da casa é positivo | "-10"      | O programa deve retornar um erro dizendo "Número da casa inválido! O número deve ser positivo." e pedir para inserir novamente. | 1. Inserir "-10" como número da casa. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 14: Testar Número de Casa com Letras

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC15                | Validar se o número da casa contém apenas números | "10A"      | O programa deve retornar um erro dizendo "Número da casa inválido! O número deve ser positivo." e pedir para inserir novamente. | 1. Inserir "10A" como número da casa. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 15: Testar Telefone com Letras

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC16                | Validar se o telefone contém apenas números | "123AB45678" | O programa deve retornar um erro dizendo "Telefone inválido! Apenas números são permitidos." e pedir para inserir novamente. | 1. Inserir "123AB45678" como telefone. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 16: Testar Telefone com Número Negativo

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC17                | Validar se o telefone contém apenas números positivos | "-123456789" | O programa deve retornar um erro dizendo "Telefone inválido! Apenas números são permitidos." e pedir para inserir novamente. | 1. Inserir "-123456789" como telefone. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 17: Testar Fidelidade com Resposta Errada

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC18                | Validar se a resposta de fidelidade é "S" ou "N" | "X"        | O programa deve retornar um erro dizendo "Entrada inválida! Digite apenas 'S' ou 'N'." e pedir para inserir novamente. | 1. Inserir "X" como resposta de fidelidade. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 18: Testar Pontos de Fidelidade Negativos

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC19                | Validar se os pontos de fidelidade são números não negativos | "-10"      | O programa deve retornar um erro dizendo "Pontos inválidos! Apenas números não negativos são permitidos." e pedir para inserir novamente. | 1. Inserir "-10" como pontos de fidelidade. <br> 2. Verificar a mensagem de erro exibida. |

## Caso de Teste 19: Testar Pontos de Fidelidade com Letras

| ID do Caso de Teste | Descrição                       | Entrada    | Resultado Esperado | Passos para Execução | 
|---------------------|---------------------------------|------------|--------------------|----------------------|
| TC20                | Validar se os pontos de fidelidade são números | "dez"       | O programa deve retornar um erro dizendo "Pontos inválidos! Apenas números não negativos são permitidos." e pedir para inserir novamente. | 1. Inserir "dez" como pontos de fidelidade. <br> 2. Verificar a mensagem de erro exibida. |




<div align="center">
  <img src="https://github.com/user-attachments/assets/aa8bc702-7200-4c29-921c-1c7c9ddd0d12">
</div>

<br>

<div align="center">
  <img src="https://github.com/user-attachments/assets/32ebaa97-0c9b-4e02-abd6-d0b143fa1b62">
</div>

<br>

<div align="center">
  <img src="https://github.com/user-attachments/assets/5d804f8e-742d-479e-92b2-ecf808287ac0">
</div>

<br>

<div align="center">
  <img src="https://github.com/user-attachments/assets/4007c055-c43b-4e0d-9ff9-a27ffc4de7b5">
</div>





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
- **Colaboração e Trabalho em Equipe**: O trabalho em grupo nos ensinou sobre como todas as atividades que aprendemos na matéria de fundamentos de engenharia de software fizeram sentido. Cada membro teve a oportunidade de se especializar em diferentes partes do sistema, mas também precisávamos garantir que tudo funcionasse bem junto. O que as vezes nos trouxe bastante dificuldade, mas tenho certeza que vai nós agregar muito no futuro. A comunicação foi a parte essencial do nosso projeto, se não não teria dado certo.
- **Importância dos Testes**: Compreendemos melhor como os testes são essenciais para garantir que o software funcione conforme esperado. Criar casos de teste nos ajudou a pensar criticamente sobre como cada parte do sistema deve se comportar.
- 
## Conclusão

O desenvolvimento do sistema para a **Voo Seguro** não apenas nos proporcionou uma experiência prática valiosa no campo da programação e engenharia de software, mas também nos fez refletir sobre os desafios reais enfrentados por empresas no dia a dia. Através desse trabalho, aprendemos sobre como se comunicar e a valorizar mais oque aprendemos. Estamos confiantes de que este projeto também nos preparará melhor para futuros desafios na nossa jornada acadêmica e profissional.


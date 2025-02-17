> # Introdução

> ## Pra que aprender Programar em C/C++

> ## Configurações

> ## Dúvidas

Uma lista de perguntas e resposta que tive no ínico e ao decorrer do meu aprendizado em C++

<details>
<summary>
<strong>
1. Sobre compiladores, existem vários compiladores para a linguagem C++, qual a diferença entre eles? E se a função do compilador é transformar o código-fonte em C para código de máquina ou Assembly, como posso visualizar meu código?
</strong>
</summary>
<br />
<i>

Existem vários compiladores para C, vai depender do seu sistema operacional, exemplo para macOS e Linux (GCC ou Clang), para windows (winGW) etc, no meu caso o macOs utilizei o clang, por conta de algumas vantagens (é o padrão do macOS, mais rápido e melhor otimização para o macOS, OBS: no macOS tem um alias para "cc"). O passo de compilação de um código envolve vários processos: pré-processamento, compilação (para assembly), montagem (para código de máquina) e linkedição.

O produto final é um arquivo executável (binário) onde o sistema operacional possa executar. Caso você queria visualizar o código Assembly gerado, basta compilar seu projeto com <kbd>cc -S meu_programa.c</kbd>

</i>
</details>

---

<details>
<summary>
<strong>
2. Sobre o CMake e Makefile o que são? Para que servem? E como usarem inicialmente?
</strong>
</summary>
<br />
<i>

Quando se trabalha com projetos em C/C++, duas abordagens populares para gerenciar a compilação são o CMake e o Make. Vamos entender a fundo como cada um funciona e suas principais diferenças.

O Make é uma ferramenta de automação de compilação que usa um arquivo chamado Makefile para definir como os arquivos-fonte devem ser compilados e vinculados para gerar o executável. O Makefile contém regras que descrevem dependências e os comandos necessários para gerar os arquivos alvo (targets). O Make verifica as modificações nos arquivos e compila apenas os que foram alterados. Exemplo

Makefile
```make
# Nome do executável
TARGET = programa

# Compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -Wextra -std=c++17

# Arquivos fonte
SRCS = main.cpp utils.cpp
OBJS = $(SRCS:.cpp=.o)

# Regra padrão para compilar o programa
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpa os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)
```

O CMake é uma ferramenta de gerenciamento de build que gera arquivos de compilação para diferentes sistemas, como Makefiles, Visual Studio projects, Ninja, entre outros.

Em vez de criar um Makefile manualmente, o CMake permite que você defina a estrutura do projeto em um arquivo chamado CMakeLists.txt, e ele gera automaticamente os arquivos apropriados para o sistema alvo.

O CMakeLists.txt descreve o projeto e suas dependências, e o CMake gera os arquivos de build apropriados.

CMakeLists.txt
```cmake
# Versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto e linguagem
project(MeuProjeto LANGUAGES CXX)

# Define os arquivos fonte
set(SOURCES main.cpp utils.cpp)

# Adiciona o executável
add_executable(meu_programa ${SOURCES})

# Configura flags de compilação
target_compile_features(meu_programa PRIVATE cxx_std_17)
target_compile_options(meu_programa PRIVATE -Wall -Wextra)
```

</i>
</details>

---

<details>
<summary>
<strong>
3. Sobre os arquivos de cabeçalho em projetos que utilizam o C/C++ (arquivos .h e .hpp) o que seria isso e para que servem?
</strong>
</summary>
<br />
<i>

Um arquivo de cabeçalho é simplesmente um arquivo de texto que contém declarações, mas não implementações. Ou seja, ele declara a interface do que o arquivo de código C vai fazer, mas não diz exatamente como ele vai fazer isso. O código em C (com extensão .c) é onde as implementações de funções, variáveis e outras lógicas ocorrem.

</i>
</details>

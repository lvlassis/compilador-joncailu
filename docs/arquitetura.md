# Arquitetura

## Historinha 

Pode-se pensar um compilador como sendo uma pequena 
fábrica que transforma matéria prima (strings do 
código fonte) em produto (código executável).

O primeiro funcionário (Léxico) fica na esteira 
por onde a matéria prima chega, esperando outro 
funcionário (Sintático) pedir um pacote de matéria
prima (token). Ele não sabe o que acontece do outro 
lado da esteira, ele só empacota a matéria prima e 
passa o pacote.

O Sintático já é o cara mais importante, pois está no
centro da operação. Ele pede um token para o Léxico e 
junta na sua árvore. Se aconteceu algo de relevante 
(uma variável foi declarada, uma função foi utilizada)
ele avisa para o 3o funcionário (Semântico) para ver 
se tudo faz sentido, o qual anota tudo em sua prancheta
(Tabela Hash de Símbolos). Se tudo está correto, ele 
continua para o próximo token.

Quando o Sintático terminou de montar um pedaço de Árvore
Sintática Abstrata, ele envia para o 4o e último 
funcionário (Gerador), que vai pegar esse pedaço de código
confiável e transformar em executável.

O Léxico não sabe que os outros existem. O Sintático conhece
a todos, mas não sabe como usar a planilha do Semântico, nem 
como gerar código como o Gerador, ele só sabe montar a sua
árvore e comunicar com o Semântico e com o Gerador. O 
Semântico só responde as perguntas do Sintático. E o Gerador
só recebe a Árvore do Sintático e gera código.

## Componentes

- CompilerContext:
  - Struct que guarda variáveis globais que serão compartilhadas entre os
    módulos

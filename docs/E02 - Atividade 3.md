# E02 - Atividade 3
Data Limite: **01/12/2026**
Atribuido para:
- #Caio 
- #Jonathas 
- #Lucas 
## Descrição
### História
**Como** professor
**Quero** que seja implementado a etapa de Análise Sintática e Tradução no projeto de compilador pré-existente. 
**Para** que meus alunos aprendam análise sintática :D

É necessário que seja utilizado como base a [[Definição da Linguagem do Professor]], com possibilidade de acrescentar itens em [[Definição da Nossa Linguagem]].
### Descrição do Professor
Os grupos deverão:
1. Implementar o analisador sintático usando o modelo Shift-Reduce com análise sintática 
ascendente LR(1), ou seja, implementando o lookahead com valor de k=1. Considere as 
seguintes etapas na implementação: 
	1. Definição da gramática estendida/aumentada 
	2. Enumerar as produções 
	3. Construção do autômato LR 
	4. Construção da tabela de análise 
	5. Realização da análise 
2. Validar programas escritos na linguagem;
3. Apresentar mensagens de erro (léxico e sintático);
4. Traduzir o programa em comandos simples da linguagem Python. 
### Produtos a serem entregues
Implementação do analisador sintático da linguagem simplificada para um robô, o qual 
deverá ser apresentado ao professor. 
### Valor
Conforme definido no programa da disciplina, será atribuído a nota de 0,0 a 10,0, com peso 
de 45% (0,45) na nota total do trabalho de implementação (TI). 
## Critérios de Aceitação
- [ ] Analisador sintático usando modelo Shift-Reduce com análise sintática ascendente LR(1)
      Implementando lookahead com k=1
- Documentar:
	- [ ] Definição da gramática estendida/aumentada 
	- [ ] Enumerar as produções 
	- [ ] Construção do autômato LR 
	- [ ] Construção da tabela de análise 
	- [ ] Realização da análise 
- [ ] Validação de Programas escritos na linguagem ^2e8114
- [ ] Apresentar mensagens de erro (léxico e sintático)
- [ ] Traduzir o programa para python
## Tarefas relacionadas
- [ ] 